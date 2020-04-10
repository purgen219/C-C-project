#include "Asm.h"

int EMPTY = -666;
int EMPTY_POP = -777;

int ASCII = 48;

int SUCCESS = 0;
int CANNOT_OPEN_FILE = -1;
int NULL_CHAR = -2;
int ERROR_SEEK = -3;
int SIGNAL_LABEL = -111;
int SIGNAL_NEW_FUNC = -222;

////WORK_WITH_FILE////
int Asm::r_file_w_array (){
    FILE* file=fopen(data_file, "r");
    if (!file){
        printf("Cannot open %s\n" , data_file);
        return CANNOT_OPEN_FILE;
    }
    fseek(file,0,SEEK_END);
    chr = ftell(file);
    if (chr == 0){
        printf("null char");
        return NULL_CHAR;
    }
    fseek( file , 0 , SEEK_SET );
    int seek  = ftell(file);
    if (seek != 0){
        printf("Bad SEEK_SET");
        return ERROR_SEEK;
    }
    text.resize(chr);
    fread (text.data() , sizeof(char) , chr , file);
    fclose(file);
    return SUCCESS ;
}
int Asm::create_array_data(){
    int k = 0;
    buf.resize(chr,'0');
    for(int i = 0 ; i < chr ; i++ ){
        if (text[i] == '\n'  ){
            buf[k] = ' ';
            k++;
            if (i >= chr){
                break;
            }
        }
        if (text[i]==';'){
            buf[k] = ' ';
            k++;
            while ( text[i] != '\n'){
                i++;
                if (i >= chr){
                    break;
                }
            }
        }
        if (i >= chr){
            break;
        }
        while ( text[i] == '\n'){
            i++;
            if (i >= chr){
                break;
            }
        }
        buf[k] = text[i];
        k++;
    }
    buf.resize(k);
    //text.clear();
    //printf("\n/количество символов %d\n/количество строк %d \n",chr, nstr);
    return SUCCESS;
}
int Asm::create_executable_file(){
    try {
        int size = array_code.size();//
        my_class_error error;
        FILE *file = fopen(executable_file, "wb");
        if (!file) {
            TEST(error,"Нифига не открылось.",0);
            throw error;
        }
        fwrite(&size, sizeof(int),1,file);
        fwrite(array_code.data(), sizeof(int),size,file);
        //for (int i = 0 ; i < func_arg.size() ; i++){
            //fwrite( &(func_arg[i].code_func), sizeof(int), 1 , file);
            //fwrite( &(func_arg[i].code_arg), sizeof(int), 1 , file);
        //}
        fclose(file);
    }
    catch (my_class_error error){
        throw error;
    }
}
/////////////////////
////TOKEN////////////
int Asm::Tokenization(){
    int i = 0;
    auto begin = buf.begin();
    auto end = buf.end();
    while(true){
        auto result = find(begin, end, ' ');
        string help_str(begin, result);
        if(help_str != "") {
            tokens.push_back(help_str);
        }
        begin = result + 1;
        if (result == end) {
            //tokens.pop_back();
            break;
        }
    }
}
////////////////////////

int Asm::get_number (const string & str_number ){
    int size = str_number.size();
    int number = 0;
    double help_number = 0;
    for (int i = 0 ; i <size ; i++){
        help_number = pow(10,i);
        number = ((int) str_number[size- i - 1] - ASCII) * help_number + number ;
    }
    return number;
}
int Asm::it_is_number(string number){ // ошибку тут увидеть . Типо если 5t5
    for (int i = 0 ; i < number.size() ; i++) {
        int ascii_cod = (int) number[i];
        if (ascii_cod < 58 && ascii_cod > 47) {
            i++;
        } else {
            return false;
        }
    }
    return true;
}
int Asm::create_semantic_peace() { // сделать на виртуалках
    try {
        my_class_error error;
        semantic_piece help;
        for (int i = 0; i < tokens.size(); i++) {
            help.code_func = EMPTY;
            help.code_arg = EMPTY;
            if (!it_is_number(tokens[i])) { // если это не число , то либо функция ,либо регистр ,либо метка
                if (tokens[i] == "push") {//если попали на push,то смотрим сл элемент
                    if (i + 1 == tokens.size()) {// ОБРАБОТАТЬ ПУШ В КОНЦЕ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                        TEST(error,"Ошибка компиляции .Функция push без аругмента на этом токене: " ,i );
                        throw error;
                    } else if (it_is_number(tokens[i + 1])) {
                        help.code_func = code_push;
                        help.code_arg = get_number(tokens[i + 1]);
                        func_arg.push_back(help);
                    } else if ((!it_is_number(tokens[i + 1])) &&(constant.register_(tokens[i + 1]) != not_reg)) {
                        help.code_func = code_pushr;
                        help.code_arg = constant.register_(tokens[i + 1]);
                        func_arg.push_back(help);
                    } else {
                        TEST(error,"Ошибка компиляции .Функция push без аругмента на этом токене:" , i);
                        throw error;
                    }
                }
                else if (tokens[i] == "pop") { //Обработать пустой pop в конце!!!!!!!!!!!!!!!!!!!!!!!
                    if (it_is_number(tokens[i + 1])) {
                        TEST(error,"Ошибка компиляции .Функция pop с некорректным аргументом на этом токене :" , i);
                        throw error;
                    } else if ((!it_is_number(tokens[i + 1])) &&(constant.register_(tokens[i + 1]) != not_reg)) {
                        help.code_func = code_popr;
                        help.code_arg = constant.register_(tokens[i + 1]);
                        func_arg.push_back(help);
                    } else {
                        help.code_func = code_pop;
                        help.code_arg = EMPTY_POP;/////////////////////////////////////////////////////////////////////
                        func_arg.push_back(help);
                    }
                }
                //f (tokens[i] == "jump" || tokens[i] == "jne" || tokens[i] == "je" || tokens[i] == "ja" || tokens[i] == "jb" ){
                else if (constant.jump(tokens[i]) != not_jmp){
                    if (i+1 == tokens.size() ){ // если jump стоит в конце без метки
                        TEST(error,"После jump нет метки ! Он стоит на токене" ,i);
                        throw error;
                    }
                    else {
                        for (int j = 0; j < vector_label.size(); j++) {
                            if ((":"+tokens[i + 1]) == vector_label[j].label) {
                                help.code_func = constant.jump(tokens[i]); // код jump
                                help.code_arg = vector_label[j].ptr;// то куда надо прыгнуть после jump . адрес в токенах
                                /*while( tokens[vector_label[j].ptr].data()[0] != ':' ) {
                                    vector_label[j].ptr ++;
                                }*/
                                func_arg.push_back(help);
                                break;
                            }
                        }
                        if ( help.code_func == EMPTY ) {// если не нашли метку
                            TEST(error,"После jump несуществующая метка:" +tokens[i+1] + " Она стоит на этом токене " , i );
                            throw error;
                        }

                    }
                }
                else if (tokens[i] == "call"){
                    if (i+1 == tokens.size() ){ // если call стоит в конце без названия функции
                        TEST(error,"После call нет названия функции! Он стоит на токене" ,i);
                        throw error;
                    }

                    else {
                        for (int j = 0; j < vector_func.size(); j++) {
                            if (("@"+tokens[i + 1]) == vector_func[j].func) {
                                help.code_func = constant.call(tokens[i]); // код call
                                help.code_arg = vector_func[j].ptr;// то куда надо прыгнуть после call
                                func_arg.push_back(help);
                                break;
                            }
                        }
                        if (help.code_func == EMPTY){// если не нашли метку
                            TEST(error,"После call несуществующая метка:" +tokens[i+1] + " Она стоит на этом токене " , i );
                            throw error;
                        }

                    }
                }
                else if (tokens[i] == "ret"){
                    help.code_func = constant.ret(tokens[i]);
                    func_arg.push_back(help);
                }
                else if (tokens[i] == "in"){ // пушит в стек то ,что ввели;
                    cin >> help.code_arg;
                    help.code_func = constant.function(tokens[i]);
                    func_arg.push_back(help);
                } // для меток тоже отдельную штуку запилить
                else if (tokens[i].data()[0] == ':') {
                    for (int k = 0 ; k < vector_label.size() ; k++){
                        if (tokens[i] == vector_label[k].label){
                            help.code_func = SIGNAL_LABEL;
                            help.code_arg = SIGNAL_LABEL;
                            func_arg.push_back(help);
                        }
                    }
                }
                else if (tokens[i].data()[0] == '@') {
                    for (int k = 0 ; k < vector_func.size() ; k++){
                        if (tokens[i] == vector_func[k].func){
                            help.code_func = SIGNAL_NEW_FUNC;
                            help.code_arg = SIGNAL_NEW_FUNC;
                            func_arg.push_back(help);
                        }
                    }
                }
            }

        }
        for (int i = 0 ; i < vector_label.size() ; i++){
            cout << vector_label[i].label <<endl;
            cout << vector_label[i].ptr <<endl;
        }
        for (int i = 0 ; i<tokens.size() ; i++){
            cout << "||" << tokens[i] << "||" << endl;
        }
        for (int i = 0; i < func_arg.size(); i++) {
            cout << "Это номер функции  = " << func_arg[i].code_func << endl;
            cout << "Это номер аргумента = " << func_arg[i].code_arg << endl;
        }
    }
    catch (my_class_error error){
        throw error;
    }
}
int Asm :: create_array_for_exe_file(){
    for (int i = 0 ; i < func_arg.size() ; i++){
        if (func_arg[i].code_func == SIGNAL_LABEL || func_arg[i].code_func == SIGNAL_NEW_FUNC || func_arg[i].code_func == code_pop || func_arg[i].code_func == code_ret || func_arg[i].code_arg == code_in){
            array_code.push_back(func_arg[i].code_func);
        }
        else{
            array_code.push_back(func_arg[i].code_func);
            array_code.push_back(func_arg[i].code_arg);
        }
    }
    for (int i = 0 ; i < array_code.size() ; i++){
        cout << array_code[i] << endl;
    }
}
int Asm::create_array_label_and_function(){
    try {
        label_ptr help_label;
        func_ptr help_func;
        my_class_error error;
        for (int i = 0; i < tokens.size(); i++) {

            if (tokens[i].data()[0] == ':') { //сделать виртуальные функции
                help_label.label = tokens[i];
                help_label.ptr = i;
                for(int j = 0 ; j < vector_label.size() ; j++){
                    if (help_label.label == vector_label[j].label){
                        TEST(error,"\nДве одинаковые метки.Я в замешательстве! Вот эта метка : " + help_label.label+"Номер токена " , i );
                        throw error;
                    }
                }
                vector_label.push_back(help_label);
            }
            else if (tokens[i].data()[0] == '@') {
                help_func.func = tokens[i];
                help_func.ptr = i;
                for(int j = 0 ; j < vector_func.size() ; j++){
                    if (help_func.func== vector_label[j].label){
                        TEST(error,"\nДве вызова функции.Я в замешательстве! Вот название функции : " + help_func.func+" Номер токена " , i );
                        throw error;
                    }
                }
                vector_func.push_back(help_func);
            }
        }
        for (int i = 0 ; i < vector_label.size() ; i++  ){
            cout << vector_label[i].label<<endl;
            cout << vector_label[i].ptr<<endl;
        }
        for (int i = 0 ; i < vector_func.size() ; i++  ){
            cout << vector_func[i].func<<endl;
            cout << vector_func[i].ptr<<endl;
        }
    }
    catch (my_class_error error){
        throw error;
    }
}
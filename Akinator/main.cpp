#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include "Head_Steck.h"

using namespace std;

#define BAD_FILE -1
#define SUCCESS 0
#define COMPARE 1
#define DESCRIPTION 2




class Node {
public:
    Node * parent;
    string str;
    Node * left;
    Node * right;
    Node() :
            parent(nullptr),
            str ({}),
            left(nullptr),
            right(nullptr)
    {}
    ~Node(){};

};
class GameManager {
public:
    Node *root;

    GameManager() :
            root(new Node) {}

    explicit GameManager(Node *node) :
            root(node) {}

    ~GameManager() { delete root; }

    int Introduction(char *dot_file) {
        int answer = 0;
        cout
                << "[1]Начать игру заново. \n[2] Продолжить прошлую игру. \n[3]Помощь? \n||Ожидаемые ответы : [1] , [2] , [3]||\n";
        cin >> answer;
        if (answer == 1) {
            New_game(dot_file);
        }
        if (answer == 2) {
            //Continue_the_game();
        }
        if (answer == 3) {
            // Help();
        }
        return 0;
    }

////////////////////////////GAME_PLAY/////////////////////////////////////////////
    int New_game(char *dot_file) {
        int ch = 0;
        int answer = 666;
        cout << "Твоё дерево пустует. Скорей добавь нового игрока " << endl;
        cout << "Назови героя смежного с твоим ?" << endl;
        while ((ch = cin.get()) != '\n' && ch != EOF) {}
        //cin.ignore('\n');
        getline(cin, root->str);
        Insert_Hero(root);
        Ask();
        For_Dot(dot_file);
    }

    int Insert_Hero(Node *finish_node) {// если ответ нет и оба указателя равны нулю
        Node *new_node_r = new Node();
        Node *new_node_l = new Node();
        int ch = 0;
        cout << "Как зовут твоего героя?" << endl;// Решить вопрос!
        //while ((ch = cin.get()) != '\n' && ch != EOF){}
        //cin.ignore('\n');
        getline(cin, new_node_r->str);
        cout << "Чем " << new_node_r->str << " отличается от " << finish_node->str << endl;
        cout << "Оно(a/о)..." << endl;
        new_node_l->str = finish_node->str;
        //while ((ch = cin.get()) != '\n' && ch != EOF){}
        getline(cin, finish_node->str);
        ///////SOFT///////////////////
        finish_node->left = new_node_l;
        finish_node->right = new_node_r;
        new_node_l->parent = finish_node;
        new_node_r->parent = finish_node;
    }


    int Insert_Hero_Recurs() {
        int answer = 888;
        Node *kayf = new Node();
        auto node_found = new Node();
        int ch = 0;

        cout << "Назовите имя героя (находящегося в листе) с которого вы хотите начать добавлять " << endl;
        while ((ch = cin.get()) != '\n' && ch != EOF) {}
        getline(cin, kayf->str);
        int res = Search_Node(kayf, root, &node_found);
        Insert_Hero(node_found);
        cout << "Продолжить добавление ?" << endl;
        cout << "|| Ожидаемые ответы : [1](да) или [0](нет)|| ";
        cin >> answer;
        if (answer == 1) {
            Insert_Hero_Recurs();
        }
        if (answer == 0) {
            return 0;
        }
    }

    int Ask() {
        Node *node = root;
        int answer = 888;
        int answer1 = 666;
        int answer2 = 777;
        while (node->left != nullptr) {
            cout << "Он(а/о)" << node->str << "?" << endl << "||Ожидаемые ответы : [1](да) , [0](нет) ||" << endl;
            cin >> answer;
            if (answer == 1) {
                node = node->right;
            }
            if (answer == 0) {
                node = node->left;
            }
        }
        answer = 2;
        cout << "Это " << node->str << "?" << endl;
        cin >> answer;
        if (answer == 1) {
            cout << "Ура ,мы справились )))" << endl;
        }
        if (answer == 0) {
            int ch = 0;
            while ((ch = cin.get()) != '\n' && ch != EOF) {}
            Insert_Hero(node);
        }
        cout << "Мы неплохо потрудились." << endl;
        cout << "Ты хочешь продолжить игру?" << endl;
        cout << "|| Ожидаемые ответы : [1](да),[0](нет) или [3](сохранить и выйти) ||" << endl;
        cin >> answer;
        if (answer == 1) {
            cout << "Вы хотите добавлять элементы или начать играть с корня дерева?" << endl;
            cout << "|| Ожидаемые ответы : [1](добавлять с листа ) или [2](начать с корня дерева.)||" << endl;
            cin >> answer1;
            if (answer1 == 1) {
                Insert_Hero_Recurs();
            }
            if (answer1 == 2) {
                Ask();
            }
        }
        if (answer == 0) {
            return 0;
        }
        if (answer == 3) {
            //Save_Tree();
        }
    }
///////////////////////////////////////GAME_PLAY/////////////////////////////////////////////

//////////////////////////////////////FOR DOT//////////////////////////
    int For_Dot(const char *dot_file) {
        FILE *file = fopen(dot_file, "w");
        if (!file) {
            printf("Файл не открылся");
            return BAD_FILE;
        }
        fprintf(file, "Digraph G{\n\t");
        For_Dot_recurs(file, root);
        fprintf(file, "}");
        fclose(file);
    }

    int For_Dot_recurs(FILE *file, Node *node) {
        if (node->left != nullptr) {
            fprintf(file, "\"%s\"->\"%s\"\n", node->str.data(), node->left->str.data());
            For_Dot_recurs(file, node->left);

        }
        if (node->left == nullptr) {
            fprintf(file, ";\n\t");
            return 0;
        }
        if (node->right != nullptr) {
            fprintf(file, "\"%s\"->\"%s\"\n", node->str.data(), node->right->str.data());
            For_Dot_recurs(file, node->right);
        }
    }
///////////////////////////////////////FOR DOT//////////////////////////

//////////////////////////////////////TREE_FILE/////////////////////////////////
    void Save_Tree(FILE *file, Node *node) {
        string chr_start = "[";
        string chr_space = " ";
        string chr_end = "]";
        string chr_N = "N";
        Node *start_node = node;
        unsigned long nmb = 0;
        nmb = start_node->str.size();
        cout <<"размер :" <<nmb <<endl;
        fwrite(chr_start.data(), sizeof(char), 1, file); // "["
        fwrite(&nmb, sizeof(unsigned long), 1, file); // "количество символов"
        fwrite(start_node->str.data(), sizeof(char), start_node->str.size(), file); // "сама строчка"
        if (start_node->right != nullptr) {
            fwrite(chr_space.data(), sizeof(char), 1, file);// " "
            Save_Tree(file, start_node->right);
        }
        if (start_node->left != nullptr) {
            fwrite(chr_space.data(), sizeof(char), 1, file);// " "
            Save_Tree(file, start_node->left);
        }
        else {
            fwrite(chr_N.data(), sizeof(char), 1, file);// "N"
        }
        fwrite(chr_end.data(), sizeof(char), 1, file); // "]"
    }
    int Create_Tree (FILE *file, Node ** node){
        char chr_start = '0' ; // "["
        char chr_end = '0' ; // "]"
        char chr_space_or_N = '0' ;
        *node = new Node(); //
        Node *node_left = new Node(); //
        Node *node_right = new Node(); //
        unsigned long len = 0;
        while (chr_start != '[') {
            fread(&chr_start, sizeof(char), 1, file);
        }
        if (chr_start == '['){
            fread(&len, sizeof(unsigned long), 1, file);
            char *string1 = new char[len];
            fread(string1, 1, len, file);
            (*node)->str = string1;
            fread(&chr_space_or_N, sizeof(char), 1, file);
            if (chr_space_or_N == ' '){
                Create_Tree(file, &node_right);
                (*node)->right = node_right;
                node_right->parent = *node;

                Create_Tree(file, &node_left);
                (*node)->left = node_left;
                node_left->parent = *node;
            }
            else if (chr_space_or_N == 'N'){
                fread(&chr_end , sizeof(char),1,file);
                (*node)->right = nullptr;
                (*node)->left = nullptr;
                return 0;
            }
        }
    }
//////////////////////////////////////TREE_FILE/////////////////////////////////

////////////////////////////DESC____COMP/////////////////////////////////////////////////////
    int Description() {
        MyStack *stk = Help_for_desc_or_cmp(DESCRIPTION);
        while (stk->size_() != 0){
            cout<< stk->top() << endl;
            stk->pop();
        }
    }
    int Compare() {
        MyStack *stack_hero1 = Help_for_desc_or_cmp(COMPARE );
        MyStack *stack_hero2 = Help_for_desc_or_cmp(COMPARE );
        while (stack_hero1->size_() != 0 || stack_hero2->size_() != 0){
            if (stack_hero1->top() == stack_hero2->top()){
                cout << "Сходства: "<< endl;
                cout<< "|| Они оба " << stack_hero2->top() << "||" << endl;
                stack_hero1->pop();
                stack_hero2->pop();
            } else{
                cout << "Различия" << endl;
                cout << " || первый " << stack_hero1->top() << " , а второй " << stack_hero2->top()  << "||" << endl;
                stack_hero1->pop();
                stack_hero2->pop();
            }
        }
    }
    MyStack * Help_for_desc_or_cmp(int indicator){ // indicator - от неё зависит работа функции.
        MyStack *stk = new MyStack(1);
        Node *node = new Node();
        Node *found_node = new Node();
        if (indicator == DESCRIPTION ){
            cout << "Описание какого объекта вы хотите получить? " << endl;
        }
        if (indicator == COMPARE ){
            cout << "Назовите элемент для сравнения : " << endl;
        }
        getline(cin, node->str);
        Search_Node(node, root, &found_node);
        while (found_node->parent != nullptr ){
            if (found_node == found_node->parent->right ) {
                stk->push(&(found_node->parent->str));
            }
            else if (found_node == found_node->parent->left){
                string str = "не " + found_node->parent->str;
                stk->push(&(str));
            }
            found_node = found_node->parent;
        }
        return stk;
    }

    int Search_Node(Node *kayf, Node *start_node, Node **found_node) {
        if (start_node->right == nullptr && start_node->str == kayf->str) {
            *found_node = start_node;
            return 0;
        }
        else if (start_node->right != nullptr) {
            Search_Node(kayf, start_node->right, found_node);
            Search_Node(kayf, start_node->left, found_node);
        }
        return -6;
    }
////////////////////////////DESC____COMP/////////////////////////////////////////////////////

};
int main (){
    //GameManager gay1 ;
    /*MyStack stack1(0);
    string str1 = "первый пуш";
    string str2 = "второй пуш";
    string str3 = "третий пуш";
    stack1.push(&str1);
    stack1.push(&str2);
    stack1.push(&str3);
    cout << stack1.top() << endl;

    stack1.pop();
    cout << stack1.top()<<endl;

    stack1.pop();
    cout << stack1.top()<<endl;

    stack1.pop();
    cout << stack1.top()<<endl;*/

    /*gay1.Introduction("/home/sergey/CLionProjects/Akinator/tree");
    FILE * file1 = fopen("/home/sergey/CLionProjects/Akinator/Tree_Save.txt","wb+");
    gay1.Save_Tree(file1,gay1.root);
    //gay1.For_Dot("/home/sergey/CLionProjects/Akinator/tree");
    fclose(file1);*/

    /*FILE * file2 = fopen("/home/sergey/CLionProjects/Akinator/Tree_Save.txt","rb");
    gay1.Create_Tree(file2,&gay1.root);
    gay1.Compare();
    fclose(file2);
    */
    /*FILE * file3 = fopen("/home/sergey/CLionProjects/Akinator/Tree_Save_TEST.txt","rb+");
    gay1.Save_Tree(file3,gay1.root);
    //gay1.For_Dot("/home/sergey/CLionProjects/Akinator/tree");
    fclose(file3);*/
    return 0;
}

#ifndef MYCPU_CONST
#define MYCPU_CONST

enum function_code{
    code_push = 50,
    code_pushr,
    code_pop,
    code_popr,
    code_in,
    not_func
};
enum jump_code{
    code_jump=not_func+1,
    code_jne,
    code_ja,
    code_jb,
    code_call,
    code_ret,
    not_jmp
};
enum register_code{
    code_ax=not_jmp+1,
    code_bx,
    code_cx,
    code_dx,
    code_sp,
    code_bp,
    not_reg
};
/////////////////////////////////////////////////     __PRETTY_FUNCTION__
/////////////////////////////////////////////////     __LINE__
/////////////////////////////////////////////////     __FILE__

class Const {
public:
    int function (string str_func ){
        if (str_func == "in") return code_in;
        else return not_func;
    }
    int register_(string str_reg){
        if (str_reg == "ax") return code_ax;
        if (str_reg == "bx") return code_bx;
        if (str_reg == "cx") return code_cx;
        if (str_reg == "dx") return code_dx;
        if (str_reg == "sp") return code_sp;
        if (str_reg == "bp") return code_bp;
        else return not_reg;
    }
    int jump(string str_jmp){
        if (str_jmp == "jump") return code_jump;
        if (str_jmp == "jne") return code_jne;
        if (str_jmp == "ja") return code_ja;
        if (str_jmp == "jb") return code_jb;
        else return not_jmp;
    }
    int call (string str_call){
        if (str_call == "call") return code_call;

    }
    int ret (string str_ret){
        if (str_ret == "ret") return code_ret;
    }
};


#endif

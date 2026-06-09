//
// Created by  on 2024/10/12.
//

#include "parser.h"
#include "error/errorList.h"

parser::parser(std::vector<Token> tokens) {
    this->tokens = std::move(tokens);
    this->now = 0;
    this->depth = 0;
    this->root = nullptr;
}

std::shared_ptr<Node> parser::parse() {
    this->root = this->handle_CompUnit(0);
    return this->root;
}

//编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef // 1.是否存在Decl 2.是否存在FuncDef
std::shared_ptr<Node> parser::handle_CompUnit(int d) {
    Grammar compUnit = {CompUnit, "CompUnit"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, compUnit);
    std::shared_ptr<Node> child = nullptr;
    //Decl
    while (this->tokens[this->now + 2].type != LPARENT) {
        child = this->handle_Decl(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    //FuncDef
    while (this->tokens[this->now + 1].type != MAINTK) {
        child = this->handle_FuncDef(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    //MainFuncDef
    child = this->handle_MainFuncDef(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    return parent;
}

//声明 Decl → ConstDecl | VarDecl // 覆盖两种声明
std::shared_ptr<Node> parser::handle_Decl(int d) {
    Grammar decl = {Decl, "Decl"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, decl);
    std::shared_ptr<Node> child = nullptr;
    //ConstDecl
    if (this->tokens[this->now].type == CONSTTK) {
        child = this->handle_ConstDecl(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
        //VarDecl
    else {
        child = this->handle_VarDecl(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // 1.花括号内重复0次
//2.花括号内重复多次
std::shared_ptr<Node> parser::handle_ConstDecl(int d) {
    Grammar constDecl = {ConstDecl, "ConstDecl"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, constDecl);
    std::shared_ptr<Node> child = nullptr;
    //const
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //BType
    child = this->handle_BType(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //ConstDef
    child = this->handle_ConstDef(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //{ ',' ConstDef }
    while (this->tokens[this->now].type == COMMA) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        child = this->handle_ConstDef(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    //;
    if (this->tokens[this->now].type != SEMICN) {
        errorList::getInstance().addError({i, this->tokens[this->now-1].line});
        Token semicn = {SEMICN, ";"};
        child = std::make_shared<Node>(parent, d + 1, semicn);
        parent->addChildren(child);
        return parent;

    }
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    return parent;
}

//基本类型 BType → 'int' | 'char' // 覆盖两种数据类型的定义
std::shared_ptr<Node> parser::handle_BType(int d) {
    Grammar bType = {BType, "BType"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, bType);
    std::shared_ptr<Node> child = nullptr;
    //int
    if (this->tokens[this->now].type == INTTK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
        //char
    else {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
    return parent;
}

//常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // 包含普通变量、一维
//数组两种情况
std::shared_ptr<Node> parser::handle_ConstDef(int d) {
    Grammar constDef = {ConstDef, "ConstDef"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, constDef);
    std::shared_ptr<Node> child = nullptr;
    //Ident
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //[
    if (this->tokens[this->now].type == LBRACK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //ConstExp
        child = this->handle_ConstExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        //]
        if (this->tokens[this->now].type != RBRACK) {
            errorList::getInstance().addError({k, this->tokens[this->now-1].line});
            Token rbrack = {RBRACK, "]"};
            child = std::make_shared<Node>(parent, d + 1, rbrack);
        } else {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }

    }
    //=
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //ConstInitVal
    child = this->handle_ConstInitVal(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    return parent;
}

//常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst // 1.常表达式初值 2.一维数组初值
std::shared_ptr<Node> parser::handle_ConstInitVal(int d) {
    Grammar constInitVal = {ConstInitVal, "ConstInitVal"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, constInitVal);
    std::shared_ptr<Node> child = nullptr;
    //ConstExp
    if (tokens[this->now].type != LBRACE && tokens[this->now].type != STRCON) {
        child = this->handle_ConstExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
        //{
    else if (tokens[this->now].type == LBRACE) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //ConstExp
        if (tokens[this->now].type != RBRACE) {
            child = this->handle_ConstExp(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
            //{ ',' ConstExp }
            while (tokens[this->now].type == COMMA) {
                child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
                parent->addChildren(child);
                now++;
                child = this->handle_ConstExp(d + 1);
                parent->addChildren(child);
                child->addParent(parent);
            }
        }
        //}
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
        //string
    else {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
    return parent;
}

//变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
std::shared_ptr<Node> parser::handle_VarDecl(int d) {
    Grammar varDecl = {VarDecl, "VarDecl"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, varDecl);
    std::shared_ptr<Node> child = nullptr;
    //BType
    child = this->handle_BType(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //VarDef
    child = this->handle_VarDef(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //{ ',' VarDef }
    while (this->tokens[this->now].type == COMMA) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        child = this->handle_VarDef(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    //;
    if (this->tokens[this->now].type != SEMICN) {
        errorList::getInstance().addError({i, this->tokens[this->now-1].line});
        Token semi = {SEMICN, ";"};
        child = std::make_shared<Node>(parent, d + 1, semi);
        parent->addChildren(child);
    } else {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }

    return parent;
}

//变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
std::shared_ptr<Node> parser::handle_VarDef(int d) {
    Grammar varDef = {VarDef, "VarDef"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, varDef);
    std::shared_ptr<Node> child = nullptr;
    //Ident
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //[ '[' ConstExp ']' ]
    if (this->tokens[this->now].type == LBRACK) {
        //[
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //ConstExp
        child = this->handle_ConstExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        //]
        if (this->tokens[this->now].type != RBRACK) {
            errorList::getInstance().addError({k, this->tokens[this->now-1].line});
            Token rbrack = {RBRACK, "]"};
            child = std::make_shared<Node>(parent, d + 1, rbrack);
            parent->addChildren(child);
        } else {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }

    }
    //'=' InitVal
    if (this->tokens[this->now].type == ASSIGN) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //InitVal
        child = this->handle_InitVal(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
std::shared_ptr<Node> parser::handle_InitVal(int d) {
    Grammar initVal = {InitVal, "InitVal"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, initVal);
    std::shared_ptr<Node> child = nullptr;
    //Exp
    if (this->tokens[this->now].type != LBRACE && this->tokens[this->now].type != STRCON) {
        child = this->handle_Exp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        return parent;
    } else if (this->tokens[this->now].type == LBRACE) {
        //{
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //Exp
        child = this->handle_Exp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        //{ ',' Exp }
        while (this->tokens[this->now].type == COMMA) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
            child = this->handle_Exp(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
        }
        //}
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    } else if (this->tokens[this->now].type == STRCON) {
        //StringConst
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
    return parent;
}

//函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
std::shared_ptr<Node> parser::handle_FuncDef(int d) {
    Grammar funcDef = {FuncDef, "FuncDef"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, funcDef);
    std::shared_ptr<Node> child = nullptr;
    //FuncType
    child = this->handle_FuncType(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //Ident
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //(
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //FuncFParams
    if (this->tokens[this->now].type == INTTK || this->tokens[this->now].type == CHARTK) {
        child = this->handle_FuncFParams(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }

    //)
    if (this->tokens[this->now].type != RPARENT) {
        errorList::getInstance().addError({j, this->tokens[this->now-1].line});
        Token rparen = {RPARENT, ")"};
        child = std::make_shared<Node>(parent, d + 1, rparen);
        parent->addChildren(child);
    } else {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }

    //Block
    child = this->handle_Block(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    return parent;
}

//主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block
std::shared_ptr<Node> parser::handle_MainFuncDef(int d) {
    Grammar mainFuncDef = {MainFuncDef, "MainFuncDef"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, mainFuncDef);
    std::shared_ptr<Node> child = nullptr;
    //int
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //main
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //(
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //)
    if (this->tokens[this->now].type != RPARENT) {
        errorList::getInstance().addError({j, this->tokens[this->now-1].line});
        Token rparen = {RPARENT, ")"};
        child = std::make_shared<Node>(parent, d + 1, rparen);
        parent->addChildren(child);
    } else {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
    //Block
    child = this->handle_Block(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    return parent;
}

//函数类型 FuncType → 'void' | 'int' | 'char'
std::shared_ptr<Node> parser::handle_FuncType(int d) {
    Grammar funcType = {FuncType, "FuncType"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, funcType);
    std::shared_ptr<Node> child = nullptr;
    //int
    if (this->tokens[this->now].type == INTTK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
        //void
    else if (this->tokens[this->now].type == VOIDTK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
        //char
    else if (this->tokens[this->now].type == CHARTK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
    return parent;
}

//函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
std::shared_ptr<Node> parser::handle_FuncFParams(int d) {
    Grammar funcFParams = {FuncFParams, "FuncFParams"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, funcFParams);
    std::shared_ptr<Node> child = nullptr;
    //FuncFParam

    child = this->handle_FuncFParam(d + 1);
    parent->addChildren(child);
    child->addParent(parent);

    //{ ',' FuncFParam }
    while (this->tokens[this->now].type == COMMA) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        child = this->handle_FuncFParam(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//函数形参 FuncFParam → BType Ident ['[' ']']
std::shared_ptr<Node> parser::handle_FuncFParam(int d) {
    Grammar funcFParam = {FuncFParam, "FuncFParam"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, funcFParam);
    std::shared_ptr<Node> child = nullptr;
    //BType
    child = this->handle_BType(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //Ident
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //'[' ']'
    if (this->tokens[this->now].type == LBRACK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //]
        if (this->tokens[this->now].type != RBRACK) {
            errorList::getInstance().addError({k, this->tokens[this->now-1].line});
            Token rbrack = {RBRACK, ")"};
            child = std::make_shared<Node>(parent, d + 1, rbrack);
            parent->addChildren(child);
        } else {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
    }
    return parent;
}

//语句块 Block → '{' { BlockItem } '}'
std::shared_ptr<Node> parser::handle_Block(int d) {
    Grammar block = {Block, "Block"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, block);
    std::shared_ptr<Node> child = nullptr;
    //{

    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);

    now++;

    //BlockItem
    while (tokens[this->now].type != RBRACE) {
        child = this->handle_BlockItem(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    //}
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    return parent;
}

//语句块项 BlockItem → Decl | Stmt
std::shared_ptr<Node> parser::handle_BlockItem(int d) {
    Grammar blockItem = {BlockItem, "BlockItem"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, blockItem);
    std::shared_ptr<Node> child = nullptr;
    //Decl
    if (tokens[this->now].type == CONSTTK || tokens[this->now].type == INTTK || tokens[this->now].type == CHARTK) {
        child = this->handle_Decl(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
        //Stmt
    else {
        child = this->handle_Stmt(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//语句 ForStmt → LVal '=' Exp
std::shared_ptr<Node> parser::handle_ForStmt(int d) {
    Grammar forStmt = {ForStmt, "ForStmt"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, forStmt);
    std::shared_ptr<Node> child = nullptr;
    //LVal
    child = this->handle_LVal(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //=
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //Exp
    child = this->handle_Exp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    return parent;
}

//表达式 Exp → AddExp
std::shared_ptr<Node> parser::handle_Exp(int d) {
    Grammar exp = {Exp, "Exp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, exp);
    std::shared_ptr<Node> child = nullptr;
    //AddExp
    child = this->handle_AddExp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    return parent;
}

//条件表达式 Cond → LOrExp
std::shared_ptr<Node> parser::handle_Cond(int d) {
    Grammar cond = {Cond, "Cond"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, cond);
    std::shared_ptr<Node> child = nullptr;
    //LOrExp
    child = this->handle_LOrExp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    return parent;
}

//左值表达式 LVal → Ident ['[' Exp ']']
std::shared_ptr<Node> parser::handle_LVal(int d) {
    Grammar lval = {LVal, "LVal"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, lval);
    std::shared_ptr<Node> child = nullptr;
    //Ident
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    //[ Exp ]
    if (this->tokens[this->now].type == LBRACK) {
        //[
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //Exp
        child = this->handle_Exp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        //]
        if (this->tokens[this->now].type != RBRACK) {
            errorList::getInstance().addError({k, this->tokens[this->now-1].line});
            Token rbrack = {RBRACK, "]"};
            child = std::make_shared<Node>(parent, d + 1, rbrack);
            parent->addChildren(child);
        } else {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
    }
    return parent;
}

//基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character
std::shared_ptr<Node> parser::handle_PrimaryExp(int d) {
    Grammar primaryExp = {PrimaryExp, "PrimaryExp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, primaryExp);
    std::shared_ptr<Node> child = nullptr;
    //'(' Exp ')'
    if (this->tokens[this->now].type == LPARENT) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //Exp
        child = this->handle_Exp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        //)
        if (this->tokens[this->now].type != RPARENT) {
            errorList::getInstance().addError({j, this->tokens[this->now-1].line});
            Token rparent = {RPARENT, ")"};
            child = std::make_shared<Node>(parent, d + 1, rparent);
            parent->addChildren(child);
        } else {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
    }
        //LVal
    else if (this->tokens[this->now].type == IDENFR) {
        child = this->handle_LVal(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
        //Number
    else if (this->tokens[this->now].type == INTCON) {
        child = handle_Number(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
        //Character
    else if (this->tokens[this->now].type == CHRCON) {
        child = handle_Character(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;

}

//数值 Number → IntConst
std::shared_ptr<Node> parser::handle_Number(int d) {
    Grammar number = {Number, "Number"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, number);
    std::shared_ptr<Node> child = nullptr;
    //IntConst
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    return parent;
}

//字符 Character → CharConst
std::shared_ptr<Node> parser::handle_Character(int d) {
    Grammar character = {Character, "Character"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, character);
    std::shared_ptr<Node> child = nullptr;
    //CharConst
    child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
    parent->addChildren(child);
    now++;
    return parent;
}

//一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
std::shared_ptr<Node> parser::handle_UnaryExp(int d) {
    Grammar unaryExp = {UnaryExp, "UnaryExp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, unaryExp);
    std::shared_ptr<Node> child = nullptr;
    //UnaryOp UnaryExp
    if (this->tokens[this->now].type == PLUS || this->tokens[this->now].type == MINU ||
        this->tokens[this->now].type == NOT) {
        child = this->handle_UnaryOp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        child = this->handle_UnaryExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
        //Ident '(' [FuncRParams] ')'
    else if (this->tokens[this->now].type == IDENFR && this->tokens[this->now + 1].type == LPARENT) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //(
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //FuncRParams
        if (this->tokens[this->now].type == IDENFR || this->tokens[this->now].type == INTCON ||
            this->tokens[this->now].type == CHRCON ||
            this->tokens[this->now].type == LPARENT || this->tokens[this->now].type == PLUS ||
            this->tokens[this->now].type == MINU || this->tokens[this->now].type == NOT) {
            child = this->handle_FuncRParams(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
        }
        if (this->tokens[this->now].type != RPARENT) {
            errorList::getInstance().addError({j, this->tokens[this->now-1].line});
            Token rparent = {RPARENT, ")"};
            child = std::make_shared<Node>(parent, d + 1, rparent);
            parent->addChildren(child);
        }
            //)
        else {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }

    }
        //PrimaryExp
    else {
        child = this->handle_PrimaryExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//UnaryOp → '+' | '−' | '!'
std::shared_ptr<Node> parser::handle_UnaryOp(int d) {
    Grammar unaryOp = {UnaryOp, "UnaryOp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, unaryOp);
    std::shared_ptr<Node> child = nullptr;
    //+
    if (this->tokens[this->now].type == PLUS) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
        //-
    else if (this->tokens[this->now].type == MINU) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
        //!
    else if (this->tokens[this->now].type == NOT) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
    }
    return parent;
}

//函数实参表 FuncRParams → Exp { ',' Exp }
std::shared_ptr<Node> parser::handle_FuncRParams(int d) {
    Grammar funcRParams = {FuncRParams, "FuncRParams"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, funcRParams);
    std::shared_ptr<Node> child = nullptr;
    //Exp
    child = this->handle_Exp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //{ ',' Exp }
    while (this->tokens[this->now].type == COMMA) {
        //,
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //Exp
        child = this->handle_Exp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
//MulExp -> UnaryExp {('*' | '/' | '%') UnaryExp}
std::shared_ptr<Node> parser::handle_MulExp(int d) {
    Grammar mulExp = {MulExp, "MulExp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, mulExp);
    std::shared_ptr<Node> child = nullptr;
    //UnaryExp
    child = this->handle_UnaryExp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //{('*' | '/' | '%') UnaryExp}
    while (this->tokens[this->now].type == MULT || this->tokens[this->now].type == DIV ||
           this->tokens[this->now].type == MOD) {
        std::shared_ptr<Node> temp = std::make_shared<Node>(nullptr, d + 1, mulExp);
        parent->deleteChildren();
        temp->addChildren(child);
        parent->addChildren(temp);
        child->addParent(temp);
        temp->addParent(parent);
        //*
        if (this->tokens[this->now].type == MULT) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
            ///
        else if (this->tokens[this->now].type == DIV) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
            //%
        else if (this->tokens[this->now].type == MOD) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
        //UnaryExp
        child = this->handle_UnaryExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
//AddExp -> MulExp {('+' | '−') MulExp}
std::shared_ptr<Node> parser::handle_AddExp(int d) {
    Grammar addExp = {AddExp, "AddExp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, addExp);
    std::shared_ptr<Node> child = nullptr;
    //MulExp
    child = this->handle_MulExp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //{('+' | '−') MulExp}
    while (this->tokens[this->now].type == PLUS || this->tokens[this->now].type == MINU) {
        //+
        std::shared_ptr<Node> temp = std::make_shared<Node>(nullptr, d + 1, addExp);
        parent->deleteChildren();
        temp->addChildren(child);
        parent->addChildren(temp);
        child->addParent(temp);
        temp->addParent(parent);
        if (this->tokens[this->now].type == PLUS) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
            //-
        else if (this->tokens[this->now].type == MINU) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
        //MulExp
        child = this->handle_MulExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
//RelExp -> AddExp {('<' | '>' | '<=' | '>=') AddExp}
std::shared_ptr<Node> parser::handle_RelExp(int d) {
    Grammar relExp = {RelExp, "RelExp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, relExp);
    std::shared_ptr<Node> child = nullptr;
    //AddExp
    child = this->handle_AddExp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //{('<' | '>' | '<=' | '>=') AddExp}
    while (this->tokens[this->now].type == LSS || this->tokens[this->now].type == GRE ||
           this->tokens[this->now].type == LEQ || this->tokens[this->now].type == GEQ) {
        //<
        std::shared_ptr<Node> temp = std::make_shared<Node>(nullptr, d + 1, relExp);
        parent->deleteChildren();
        temp->addChildren(child);
        parent->addChildren(temp);
        child->addParent(temp);
        temp->addParent(parent);
        if (this->tokens[this->now].type == LSS) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
            //>
        else if (this->tokens[this->now].type == GRE) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
            //<=
        else if (this->tokens[this->now].type == LEQ) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
            //>=
        else if (this->tokens[this->now].type == GEQ) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
        //AddExp
        child = this->handle_AddExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
//EqExp -> RelExp {('==' | '!=') RelExp}
std::shared_ptr<Node> parser::handle_EqExp(int d) {
    Grammar eqExp = {EqExp, "EqExp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, eqExp);
    std::shared_ptr<Node> child = nullptr;
    //RelExp
    child = this->handle_RelExp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //{('==' | '!=') RelExp}
    while (this->tokens[this->now].type == EQL || this->tokens[this->now].type == NEQ) {
        //==
        std::shared_ptr<Node> temp = std::make_shared<Node>(nullptr, d + 1, eqExp);
        parent->deleteChildren();
        temp->addChildren(child);
        parent->addChildren(temp);
        child->addParent(temp);
        temp->addParent(parent);
        if (this->tokens[this->now].type == EQL) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
            //!=
        else if (this->tokens[this->now].type == NEQ) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
        //RelExp
        child = this->handle_RelExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
//LAndExp -> EqExp {'&&' EqExp}
std::shared_ptr<Node> parser::handle_LAndExp(int d) {
    Grammar lAndExp = {LAndExp, "LAndExp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, lAndExp);
    std::shared_ptr<Node> child = nullptr;
    //EqExp
    child = this->handle_EqExp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //{'&&' EqExp}
    while (this->tokens[this->now].type == AND) {
        std::shared_ptr<Node> temp = std::make_shared<Node>(nullptr, d + 1, lAndExp);
        parent->deleteChildren();
        temp->addChildren(child);
        parent->addChildren(temp);
        child->addParent(temp);
        temp->addParent(parent);
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //EqExp
        child = this->handle_EqExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
//LOrExp -> LAndExp {'||' LAndExp}
std::shared_ptr<Node> parser::handle_LOrExp(int d) {
    Grammar lOrExp = {LOrExp, "LOrExp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, lOrExp);
    std::shared_ptr<Node> child = nullptr;
    //LAndExp
    child = this->handle_LAndExp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    //{'||' LAndExp}
    while (this->tokens[this->now].type == OR) {
        std::shared_ptr<Node> temp = std::make_shared<Node>(nullptr, d + 1, lOrExp);
        parent->deleteChildren();
        temp->addChildren(child);
        parent->addChildren(temp);
        child->addParent(temp);
        temp->addParent(parent);
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //LAndExp
        child = this->handle_LAndExp(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
    return parent;
}

//常量表达式 ConstExp → AddExp
std::shared_ptr<Node> parser::handle_ConstExp(int d) {
    Grammar constExp = {ConstExp, "ConstExp"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, constExp);
    std::shared_ptr<Node> child = nullptr;
    //AddExp
    child = this->handle_AddExp(d + 1);
    parent->addChildren(child);
    child->addParent(parent);
    return parent;
}

/*语句
Stmt →
| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
| 'break' ';'
| 'continue' ';'
| 'return' [Exp] ';'
| 'printf''('StringConst {','Exp}')'';'
| Block
| LVal '=' Exp ';'
| LVal '=' 'getint''('')'';'
| LVal '=' 'getchar''('')'';'
| [Exp] ';'
*/
std::shared_ptr<Node> parser::handle_Stmt(int d) {
    Grammar stmt = {Stmt, "Stmt"};
    std::shared_ptr<Node> parent = std::make_shared<Node>(nullptr, d, stmt);
    std::shared_ptr<Node> child = nullptr;
    //if
    if (this->tokens[this->now].type == IFTK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //(
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //Cond
        child = this->handle_Cond(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        //)
        if (this->tokens[this->now].type != RPARENT) {
            errorList::getInstance().addError({j, this->tokens[this->now-1].line});
            Token rparent = {RPARENT, ")"};
            child = std::make_shared<Node>(parent, d + 1, rparent);
            parent->addChildren(child);
        } else {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }

        //Stmt
        child = this->handle_Stmt(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        //else
        if (this->tokens[this->now].type == ELSETK) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
            //Stmt
            child = this->handle_Stmt(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
        }
    }
        //for
    else if (this->tokens[this->now].type == FORTK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //(
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //ForStmt
        if (this->tokens[this->now].type != SEMICN) {
            child = this->handle_ForStmt(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
        }
        //;
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //Cond
        if (this->tokens[this->now].type != SEMICN) {
            child = this->handle_Cond(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
        }
        //;
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //ForStmt
        if (this->tokens[this->now].type != RPARENT) {
            child = this->handle_ForStmt(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
        }
        //)
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //Stmt
        child = this->handle_Stmt(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
        //break
    else if (this->tokens[this->now].type == BREAKTK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //;
        if(this->tokens[this->now].type != SEMICN){
            errorList::getInstance().addError({i, this->tokens[this->now-1].line});
            Token semicn = {SEMICN, ";"};
            child = std::make_shared<Node>(parent, d + 1, semicn);
            parent->addChildren(child);
        }
        else
        {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }

    }
        //continue
    else if (this->tokens[this->now].type == CONTINUETK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //;
        if(this->tokens[this->now].type != SEMICN){
            errorList::getInstance().addError({i, this->tokens[this->now-1].line});
            Token semicn = {SEMICN, ";"};
            child = std::make_shared<Node>(parent, d + 1, semicn);
            parent->addChildren(child);
        }
        else
        {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
    }
        //return
    else if (this->tokens[this->now].type == RETURNTK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //Exp
        if (this->tokens[this->now].type == IDENFR || this->tokens[this->now].type == INTCON ||
            this->tokens[this->now].type == CHRCON ||
            this->tokens[this->now].type == LPARENT || this->tokens[this->now].type == PLUS ||
            this->tokens[this->now].type == MINU || this->tokens[this->now].type == NOT) {
            child = this->handle_Exp(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
        }
        //;
        if(this->tokens[this->now].type != SEMICN){
            errorList::getInstance().addError({i, this->tokens[this->now-1].line});
            Token semicn = {SEMICN, ";"};
            child = std::make_shared<Node>(parent, d + 1, semicn);
            parent->addChildren(child);
        }
        else
        {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
    }
        //'printf''('StringConst {','Exp}')'';'
    else if (this->tokens[this->now].type == PRINTFTK) {
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //(
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //StringConst
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //{','Exp}
        while (this->tokens[this->now].type == COMMA) {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
            //Exp
            child = this->handle_Exp(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
        }
        //)
        if(this->tokens[this->now].type != RPARENT){
            errorList::getInstance().addError({j, this->tokens[this->now-1].line});
            Token rparent = {RPARENT, ")"};
            child = std::make_shared<Node>(parent, d + 1, rparent);
            parent->addChildren(child);
        }
        else
        {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
        //;
        if(this->tokens[this->now].type != SEMICN){
            errorList::getInstance().addError({i, this->tokens[this->now-1].line});
            Token semicn = {SEMICN, ";"};
            child = std::make_shared<Node>(parent, d + 1, semicn);
            parent->addChildren(child);
        }
        else
        {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
    }
        //Block
    else if (this->tokens[this->now].type == LBRACE) {
        child = this->handle_Block(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
    }
        //Exp
    else if (!isAssign(this->now)) {
        if (this->tokens[this->now].type == IDENFR || this->tokens[this->now].type == INTCON ||
            this->tokens[this->now].type == CHRCON ||
            this->tokens[this->now].type == LPARENT || this->tokens[this->now].type == PLUS ||
            this->tokens[this->now].type == MINU || this->tokens[this->now].type == NOT) {
            child = this->handle_Exp(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
        }
        //;
        if(this->tokens[this->now].type != SEMICN){
            errorList::getInstance().addError({i, this->tokens[this->now-1].line});
            Token semicn = {SEMICN, ";"};
            child = std::make_shared<Node>(parent, d + 1, semicn);
            parent->addChildren(child);
        }
        else
        {
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
        }
    } else if (isAssign(this->now)) {
        /*| LVal '=' Exp ';'
 | LVal '=' 'getint''('')'';'
 | LVal '=' 'getchar''('')'';'*/
        //LVal
        child = this->handle_LVal(d + 1);
        parent->addChildren(child);
        child->addParent(parent);
        //=
        child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
        parent->addChildren(child);
        now++;
        //Exp
        if (this->tokens[this->now].type != GETINTTK && this->tokens[this->now].type != GETCHARTK) {
            child = this->handle_Exp(d + 1);
            parent->addChildren(child);
            child->addParent(parent);
            //;
            if(this->tokens[this->now].type != SEMICN){
                errorList::getInstance().addError({i, this->tokens[this->now-1].line});
                Token semicn = {SEMICN, ";"};
                child = std::make_shared<Node>(parent, d + 1, semicn);
            }
            else
            {
                child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
                parent->addChildren(child);
                now++;
            }
        } else if (this->tokens[this->now].type == GETINTTK) {
            //getint
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
            //(
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
            //)
            if(this->tokens[this->now].type != RPARENT){
                errorList::getInstance().addError({j, this->tokens[this->now-1].line});
                Token rparent = {RPARENT, ")"};
                child = std::make_shared<Node>(parent, d + 1, rparent);
                parent->addChildren(child);
            }
            else
            {
                child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
                parent->addChildren(child);
                now++;
            }
            //;
            if(this->tokens[this->now].type != SEMICN){
                errorList::getInstance().addError({i, this->tokens[this->now-1].line});
                Token semicn = {SEMICN, ";"};
                child = std::make_shared<Node>(parent, d + 1, semicn);
                parent->addChildren(child);
            }
            else
            {
                child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
                parent->addChildren(child);
                now++;
            }
        } else if (this->tokens[this->now].type == GETCHARTK) {
            //getchar
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
            //(
            child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
            parent->addChildren(child);
            now++;
            //)
            if(this->tokens[this->now].type != RPARENT){
                errorList::getInstance().addError({j, this->tokens[this->now-1].line});
                Token rparent = {RPARENT, ")"};
                child = std::make_shared<Node>(parent, d + 1, rparent);
                parent->addChildren(child);
            }
            else
            {
                child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
                parent->addChildren(child);
                now++;
            }
            //;
            if(this->tokens[this->now].type != SEMICN){
                errorList::getInstance().addError({i, this->tokens[this->now-1].line});
                Token semicn = {SEMICN, ";"};
                child = std::make_shared<Node>(parent, d + 1, semicn);
                parent->addChildren(child);
            }
            else
            {
                child = std::make_shared<Node>(parent, d + 1, this->tokens[this->now]);
                parent->addChildren(child);
                now++;
            }
        }

    }
    return parent;
}

bool parser::isAssign(int pt) {
    while (this->tokens[pt].type != ASSIGN && this->tokens[pt].type != SEMICN&&pt<this->tokens.size()) {
        pt++;
    }
    if (this->tokens[pt].type == ASSIGN) {
        return true;
    } else {
        return false;
    }
}
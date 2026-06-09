cmake_minimum_required(VERSION 3.25)
project(Compiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Compiler main.cpp
        error/Error.h error/Error.cpp
        lexer/Lexer.h lexer/Lexer.cpp
        util/Constants.h util/Constants.cpp
        token/Token.h token/Token.cpp
        util/Util.h util/Util.cpp

        parser/Parser.h parser/Parser.cpp

        parser/compUnit/CompUnit.h parser/compUnit/CompUnit.cpp

        parser/declaration/const/ConstDecl.h parser/declaration/const/ConstDecl.cpp
        parser/declaration/variable/VarDecl.h parser/declaration/variable/VarDecl.cpp
        parser/declaration/variable/VarDef.h parser/declaration/variable/VarDef.cpp
        parser/declaration/variable/InitVal.h parser/declaration/variable/InitVal.cpp
        parser/declaration/Decl.h parser/declaration/Decl.cpp

        parser/def/ConstDef.h parser/def/ConstDef.cpp
        parser/def/ConstInitVal.h parser/def/ConstInitVal.cpp

        parser/expression/multiexp/AddExp.h parser/expression/multiexp/AddExp.cpp
        parser/expression/multiexp/EqExp.h parser/expression/multiexp/EqExp.cpp
        parser/expression/multiexp/LAndExp.h parser/expression/multiexp/LAndExp.cpp
        parser/expression/multiexp/LOrExp.h parser/expression/multiexp/LOrExp.cpp
        parser/expression/multiexp/MulExp.h parser/expression/multiexp/MulExp.cpp
        parser/expression/multiexp/PrimaryExp.h parser/expression/multiexp/PrimaryExp.cpp
        parser/expression/multiexp/RelExp.h parser/expression/multiexp/RelExp.cpp

        parser/expression/unaryexp/Character.h parser/expression/unaryexp/Character.cpp
        parser/expression/unaryexp/Cond.h parser/expression/unaryexp/Cond.cpp
        parser/expression/unaryexp/ConstExp.h parser/expression/unaryexp/ConstExp.cpp
        parser/expression/unaryexp/Exp.h parser/expression/unaryexp/Exp.cpp
        parser/expression/unaryexp/Lval.h parser/expression/unaryexp/Lval.cpp
        parser/expression/unaryexp/Number.h parser/expression/unaryexp/Number.cpp
        parser/expression/unaryexp/UnaryExp.h parser/expression/unaryexp/UnaryExp.cpp

        parser/function/FuncDef.h parser/function/FuncDef.cpp
        parser/function/FuncFParam.h parser/function/FuncFParam.cpp
        parser/function/FuncFParams.h parser/function/FuncFParams.cpp
        parser/function/FuncRParams.h parser/function/FuncRParams.cpp
        parser/function/MainFuncDef.h parser/function/MainFuncDef.cpp

        parser/statement/Block.h parser/statement/Block.cpp
        parser/statement/BlockItem.h parser/statement/BlockItem.cpp
        parser/statement/ForStmt.h parser/statement/ForStmt.cpp
        parser/statement/Stmt.h parser/statement/Stmt.cpp

#        symbolTable/symbolTable.h symbolTable/symbolType.h semantic/semantic.h semantic/semantic.cpp symbolTable/blockTree/blockTree.h symbolTable/blockTree/blockTreeNode.h symbolTable/blockTree/blockTreeNode.cpp
)
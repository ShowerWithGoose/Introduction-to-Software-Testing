//
// Created by  on 2ParserTreeNode()24/tmpNodeParserTreeNode()/9.
//
#include "GA.h"
#include <iostream>
#include "ParserTree.h"
using namespace std;
ParserTreeNode parserTreeRoot;
// 获取并返回下一个token
// 当调用的时候说明当前token已经被处理，所以打印当前token
Token getNext() {
    // fileout << Lexer::tokens[nowIndex].toString() << endl;
    nowIndex++;
    if (nowIndex < Lexer::tokens.size()) {
        now = Lexer::tokens[nowIndex];
    }
    else {
        now = Token();
    }
    return now;
}
Token PreRead() {
    if (nowIndex + 1 < Lexer::tokens.size()) {
        preRead = Lexer::tokens[nowIndex + 1];
    }
    else {
        preRead = Token();
    }
    return preRead;
}
Token PrePreRead() {
    if (nowIndex + 2 < Lexer::tokens.size()) {
        prePreRead = Lexer::tokens[nowIndex + 2];
    }
    else {
        prePreRead = Token();
    }
    return prePreRead;
}
ParserTreeNode CompUnit_Analysis() {
    //    while(now == 'int'){
    //        if(preRead == 'main'){
    //            MainFuncDef(); //now == int
    //        }
    //        if(isIdent(preRead)){ //now == int
    //            if(prePreRead == '='){
    //                Decl(); //now == int
    //            }
    //            else if(prePreRead == '('){
    //                FuncDef(); //now == int
    //            }
    //            else{/*错误*/}
    //        }
    //        else{/*错误*/}
    //        }
    ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::CompUnit);
	now = Lexer::tokens[nowIndex];
    while (now.word == "int" || now.word == "char" || now.word == "void" || now.word == "const") {
        // MainFuncDef
        if (now.word == "int" && PreRead().word == "main") {
            tmpNode.AddChild(MainFuncDef_Analysis());
        }
        // {Decl} {FuncDef}
        else if (now.word == "const") {
            tmpNode.AddChild(Decl_Analysis());
        }
        else if (isIdent(PreRead())) {
            if (PrePreRead().word == "(") {
                tmpNode.AddChild(FuncDef_Analysis());
            }
            else {
                tmpNode.AddChild(Decl_Analysis());
            }
        }
        else { PrintError("Unexpected error when analyse CompUnit!"); return ParserTreeNode(); }
    }
	//getNext();
    // fileout << GraItem_Str.find(CompUnit)->second << endl;
    return tmpNode;
}
ParserTreeNode Decl_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::Decl);
    // ConstDecl
    if (now.word == "const") {
        tmpNode.AddChild(ConstDecl_Analysis());
    }
    // VarDecl
    else if (now.word == "int" || now.word == "char") {
        tmpNode.AddChild(VarDecl_Analysis());
    }

    else {
        PrintError("Unexpected error when analyse Decl!");
        return ParserTreeNode();
    }
    return tmpNode;
}

ParserTreeNode ConstDecl_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::ConstDecl);
    // 'const'
    if (now.word == "const") {
		tmpNode.AddChild(ParserTreeNode(true, CONSTTK, "const", Unknown));
        // BType
        getNext();
        tmpNode.AddChild(BType_Analysis());
        // ConstDef
        tmpNode.AddChild(ConstDef_Analysis());
        // { ',' ConstDef }
        while (now.word == ",") {
            tmpNode.AddChild(ParserTreeNode(true, COMMA, ",", Unknown));
            getNext();
            tmpNode.AddChild(ConstDef_Analysis());
        }
        // ';'
        if (now.word != ";") {
            RecordError(LastTokenLine(), LastTokenCharacterCount(),  "i");
        }
        else {
            tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
            getNext();
        }

        // fileout << GraItem_Str.find(ConstDecl)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse ConstDecl!");
        return ParserTreeNode();
    }
}

ParserTreeNode BType_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::BType);
    if (now.word == "int" || now.word == "char") {
        tmpNode.AddChild(ParserTreeNode(true, now.type, now.word, Unknown));
		getNext();
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse BType!");
        return ParserTreeNode();
    }
}
ParserTreeNode ConstDef_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::ConstDef);
    // Ident
    if (isIdent(now)) {
		tmpNode.AddChild(ParserTreeNode(true, IDENFR, now.word, Unknown));
        getNext();
        // [ '[' ConstExp ']' ]
        if (now.word == "[") {
			tmpNode.AddChild(ParserTreeNode(true, LBRACK, "[", Unknown));
            // ConstExp
            getNext();
            tmpNode.AddChild(ConstExp_Analysis());

            if (now.word != "]") {
                RecordError(now.line, now.characterCount,  "k");
            }
            else {
				tmpNode.AddChild(ParserTreeNode(true, RBRACK, "]", Unknown));
                getNext();
            }
        }

        // '=' ConstInitVal
        if (now.word == "=") {
			tmpNode.AddChild(ParserTreeNode(true, ASSIGN, "=", Unknown));
            getNext();
            tmpNode.AddChild(ConstInitVal_Analysis());
        }
        else {
            PrintError("Unexpected error when analyse ConstDef!");
        }
        // fileout << GraItem_Str.find(ConstDef)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse ConstDef!");
        return ParserTreeNode();
    }
}

ParserTreeNode ConstInitVal_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::ConstInitVal);
    // ConstExp
    if (isTheFirstOfExp(now)) {
        tmpNode.AddChild(ConstExp_Analysis());
    }
    // StringConst
    else if (isSTRCON(now)) {
		tmpNode.AddChild(ParserTreeNode(true, STRCON, now.word, Unknown));
		getNext();
	}
    // '{' [ ConstInitVal { ',' ConstInitVal } ] '}'
    else if (now.word == "{") {
		tmpNode.AddChild(ParserTreeNode(true, LBRACE, "{", Unknown));
        getNext();
        if (now.word != "}") {
            tmpNode.AddChild(ConstExp_Analysis());
            while (now.word == ",") {
				tmpNode.AddChild(ParserTreeNode(true, COMMA, ",", Unknown));
                getNext();
                tmpNode.AddChild(ConstExp_Analysis());
            }
        }
        if (now.word != "}") {
            PrintError("Unexpected error when analyse ConstInitVal!");
            return ParserTreeNode();
        }
        else {
			tmpNode.AddChild(ParserTreeNode(true, RBRACE, "}", Unknown));
            getNext();
        }
    }
    else {
        PrintError("Unexpected error when analyse ConstInitVal!");
        return ParserTreeNode();
    }
    // fileout << GraItem_Str.find(ConstInitVal)->second << endl;
    return tmpNode;
}

ParserTreeNode VarDecl_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::VarDecl);
    // BType
    tmpNode.AddChild(BType_Analysis());
    // VarDef
    tmpNode.AddChild(VarDef_Analysis());
    // { ',' VarDef }
    while (now.word == ",") {
		tmpNode.AddChild(ParserTreeNode(true, COMMA, ",", Unknown));
        getNext();
        tmpNode.AddChild(VarDef_Analysis());
    }
    // ';'
    if (now.word != ";") {
        RecordError(LastTokenLine(), LastTokenCharacterCount(),  "i");
    }
    else {
		tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
        getNext();
    }
    // fileout << GraItem_Str.find(VarDecl)->second << endl;
    return tmpNode;
}

// 注意这个对推导公式进行了合并
ParserTreeNode VarDef_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::VarDef);
    // Ident
    if (isIdent(now)) {
		tmpNode.AddChild(ParserTreeNode(true, IDENFR, now.word, Unknown));
        getNext();
        // [ '[' ConstExp ']' ]
        if (now.word == "[") {
			tmpNode.AddChild(ParserTreeNode(true, LBRACK, "[", Unknown));
            // ConstExp
            getNext();
            tmpNode.AddChild(ConstExp_Analysis());

            if (now.word != "]") {
                RecordError(LastTokenLine(), LastTokenCharacterCount(),  "k");
            }
            else {
				tmpNode.AddChild(ParserTreeNode(true, RBRACK, "]", Unknown));
                getNext();
            }
        }
        // [ '=' InitVal ]
        if (now.word == "=") {
			tmpNode.AddChild(ParserTreeNode(true, ASSIGN, "=", Unknown));
            getNext();
            tmpNode.AddChild(InitVal_Analysis());
        }
        // fileout << GraItem_Str.find(VarDef)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse VarDef!");
        return ParserTreeNode();
    }
}

ParserTreeNode InitVal_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::InitVal);
    if (now.word == "{") {
        // '{' [ Exp { ',' Exp } ] '}'
		tmpNode.AddChild(ParserTreeNode(true, LBRACE, "{", Unknown));
        getNext();
        if (now.word != "}") {
            tmpNode.AddChild(Exp_Analysis());
            while (now.word == ",") {
				tmpNode.AddChild(ParserTreeNode(true, COMMA, ",", Unknown));
                getNext();
                tmpNode.AddChild(Exp_Analysis());
            }
            if (now.word != "}") {
                PrintError("Unexpected error when analyse InitVal!");
                return ParserTreeNode();
            }
            else {
				tmpNode.AddChild(ParserTreeNode(true, RBRACE, "}", Unknown));
            }
        }
		else {
			getNext();
		}
		getNext();
    }
    else {
        // StringConst
        if (isSTRCON(now)) { 
			tmpNode.AddChild(ParserTreeNode(true, STRCON, now.word, Unknown));
            getNext(); 
        }
        // Exp
        else {
            tmpNode.AddChild(Exp_Analysis());
        }
    }
    // fileout << GraItem_Str.find(InitVal)->second << endl;
    return tmpNode;
}

ParserTreeNode FuncDef_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::FuncDef);
    // FuncType
    if (now.word == "int" || now.word == "char" || now.word == "void") {
        tmpNode.AddChild(FuncType_Analysis());
        // Ident
        if (isIdent(now)) {
			tmpNode.AddChild(ParserTreeNode(true, IDENFR, now.word, Unknown));
            // '('
            getNext();
            if (now.word != "(") {
                PrintError("Unexpected error when analyse FuncDef!");
                return ParserTreeNode();
            }
			tmpNode.AddChild(ParserTreeNode(true, LPARENT, "(", Unknown));
            // [ FuncFParams ]
            getNext();
            if (isBType(now.word)) {
                tmpNode.AddChild(FuncFParams_Analysis());
            }
            // ')'
            if (now.word != ")") {
                RecordError(LastTokenLine(), LastTokenCharacterCount(),  "j");
            }
            else {
				tmpNode.AddChild(ParserTreeNode(true, RPARENT, ")", Unknown));
				getNext();
            }
            // Block
            Block_Analysis();
            // fileout << GraItem_Str.find(FuncDef)->second << endl;
            return tmpNode;
        }
        else {
            PrintError("Unexpected error when analyse FuncDef!");
            return ParserTreeNode();
        }
    }
    else {
        PrintError("Unexpected error when analyse FuncDef!");
        return ParserTreeNode();
    }
}

ParserTreeNode MainFuncDef_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::MainFuncDef);
    // 'int'
    if (now.word == "int") {
		tmpNode.AddChild(ParserTreeNode(true, INTTK, "int", Unknown));
        // 'main'
        getNext();
        if (now.word == "main") {
			tmpNode.AddChild(ParserTreeNode(true, MAINTK, "main", Unknown));
            // '('
            getNext();
            if (now.word != "(") {
                PrintError("Unexpected error when analyse MainFuncDef!");
                return ParserTreeNode();
            }
			tmpNode.AddChild(ParserTreeNode(true, LPARENT, "(", Unknown));
            // ')'
            getNext();
            if (now.word != ")") {
                RecordError(LastTokenLine(), LastTokenCharacterCount(),  "j");
            }
            else {
				tmpNode.AddChild(ParserTreeNode(true, RPARENT, ")", Unknown));
				getNext();
            }
            // Block
            tmpNode.AddChild(Block_Analysis());
            // fileout << GraItem_Str.find(MainFuncDef)->second << endl;
            return tmpNode;
        }
        else {
            PrintError("Unexpected error when analyse MainFuncDef!");
            return ParserTreeNode();
        }
    }
    else {
        PrintError("Unexpected error when analyse MainFuncDef!");
        return ParserTreeNode();
    }
}

ParserTreeNode FuncType_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::FuncType);
    if (now.word == "int" || now.word == "char" || now.word == "void") {
		tmpNode.AddChild(ParserTreeNode(true, now.type, now.word, Unknown));
		getNext();
        // fileout << GraItem_Str.find(FuncType)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse FuncType!");
        return ParserTreeNode();
    }
}

ParserTreeNode FuncFParams_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::FuncFParams);
    // FuncFParam
    tmpNode.AddChild(FuncFParam_Analysis());
    // { ',' FuncFParam }
    while (now.word == ",") {
		tmpNode.AddChild(ParserTreeNode(true, COMMA, ",", Unknown));
        getNext();
        tmpNode.AddChild(FuncFParam_Analysis());
    }
    // fileout << GraItem_Str.find(FuncFParams)->second << endl;
    return tmpNode;
}

ParserTreeNode FuncFParam_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::FuncFParam);
    // BType
    tmpNode.AddChild(BType_Analysis());
    // Ident
    if (isIdent(now)) {
		tmpNode.AddChild(ParserTreeNode(true, IDENFR, now.word, Unknown));
        // [ '[' ']' ]
        if (PreRead().word == "[") {
            getNext();
			tmpNode.AddChild(ParserTreeNode(true, LBRACK, "[", Unknown));
            if (PreRead().word != "]") {
                RecordError(now.line, now.characterCount,  "k");
            }
            else {
				getNext();
				tmpNode.AddChild(ParserTreeNode(true, RBRACK, "]", Unknown));
            }
        }
		getNext();
        // fileout << GraItem_Str.find(FuncFParam)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse FuncFParam!");
        return ParserTreeNode();
    }
}

ParserTreeNode Block_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::Block);
    // '{'
    if (now.word == "{") {
		tmpNode.AddChild(ParserTreeNode(true, LBRACE, "{", Unknown));
        getNext();
        // { BlockItem }
        // F(BlockItem) = {'const', 'int', 'char', Ident, IntConst, 
        // CharConst, '(', '+', '-', '!', '{', ';', 'if', 'for', 'break', 'continue', 'return', 'printf'}
        while (now.type == CONSTTK || now.type == INTTK || now.type == CHARTK || isIdent(now) || isINTCON(now)
        || isCHRCON(now) || now.word == "(" || now.word == "+" || now.word == "-" || now.word == "!" || now.word == "{"
            || now.word == ";" || isIFTK(now) || isFORTK(now) || isBREAKTK(now) || isCONTINUETK(now) || isRETURNTK(now) || isPRINTFTK(now)) {
            tmpNode.AddChild(BlockItem_Analysis());
        }
        // '}'
        if (now.word != "}") {
            PrintError("Unexpected error when analyse Block!");
        }
        else {
			tmpNode.AddChild(ParserTreeNode(true, RBRACE, "}", Unknown));
            getNext();
        }
        // fileout << GraItem_Str.find(Block)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse Block!");
        return ParserTreeNode();
    }
}

ParserTreeNode BlockItem_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::BlockItem);
    // Decl
    if (now.word == "const" || now.word == "int" || now.word == "char") {
        tmpNode.AddChild(Decl_Analysis());
    }
    // Stmt
    else {
        tmpNode.AddChild(Stmt_Analysis());
    }
    return tmpNode;
}

ParserTreeNode Stmt_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::Stmt);
    if (isIdent(now)) {// LVal '=' Exp ';' OR LVal '=' 'getint''('')'';' OR LVal '=' 'getchar''('')'';'
        //(上面三种情况视为LVal Stmt2)OR [Exp] ';'(部分)
        // [Exp] ';'包含LVal 和 Ident '(' [FuncRParams] ')' 两种情况
        if (PreRead().word == "(") {
            // Ident '(' [FuncRParams] ')' => Exp ';'
            tmpNode.AddChild(Exp_Analysis());
            if (now.word != ";") {
                RecordError(LastTokenLine(), LastTokenCharacterCount(),  "i");
			}
            else {
				tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
				getNext();
            }
        }
        else {
            // 仍然区分不了LVal Stmt2和LVal ;([Exp] ';')
            // 似乎必须先预处理一个LVal再判断
            string temp = PreHandleLVal();
            if (temp == "=") {
                // LVal Stmt2
                tmpNode.AddChild(LVal_Analysis());

                // '='
                if (now.word != "=") {
                    PrintError("Unexpected error when analyse Stmt!");
                    return ParserTreeNode();
                }
				tmpNode.AddChild(ParserTreeNode(true, ASSIGN, "=", Unknown));
                // 'getint' OR 'getchar'
                getNext();
                if (now.word == "getint" || now.word == "getchar") {
					tmpNode.AddChild(ParserTreeNode(true, now.type, now.word, Unknown));
                    getNext();
                    if (now.word != "(") {
                        PrintError("Unexpected error when analyse Stmt!");
                        return ParserTreeNode();
                    }
					tmpNode.AddChild(ParserTreeNode(true, LPARENT, "(", Unknown));
                    if (PreRead().word != ")") {
                        RecordError(now.line, now.characterCount,  "j");
                    }
                    else {
						tmpNode.AddChild(ParserTreeNode(true, RPARENT, ")", Unknown));
						getNext();
                    }
                    if (PreRead().word != ";") {
                        RecordError(now.line, now.characterCount,  "i");
                    }
                    else {
                        tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
                        getNext();
                    }
					getNext();
                }
                else {
                    // Exp
                    tmpNode.AddChild(Exp_Analysis());
                    if (now.word != ";") {
                        RecordError(LastTokenLine(), LastTokenCharacterCount(),  "i");
                    }
                    else {
						tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
                        getNext();
                    }
                }
            }
            else {
                // Exp
                tmpNode.AddChild(Exp_Analysis());
                if (now.word != ";") {
                    RecordError(LastTokenLine(), LastTokenCharacterCount(),  "i");
                }
                else {
					tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
					getNext();
                }
            }
        }
    }
    // ; => [Exp] ';'
    else if (now.word == ";") {
		tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
        getNext();
    }
    // Block
    else if (now.word == "{") {
        tmpNode.AddChild(Block_Analysis());
    }
    // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    else if (now.word == "if") {
		tmpNode.AddChild(ParserTreeNode(true, IFTK, "if", Unknown));
        getNext();
        if (now.word != "(") {
            PrintError("Unexpected error when analyse Stmt!");
            return ParserTreeNode();
        }
		tmpNode.AddChild(ParserTreeNode(true, LPARENT, "(", Unknown));
        getNext();
        tmpNode.AddChild(Cond_Analysis());
        if (now.word != ")") {
            RecordError(LastTokenLine(), LastTokenCharacterCount(),  "j");
        }
        else {
			tmpNode.AddChild(ParserTreeNode(true, RPARENT, ")", Unknown));
            getNext();
        }
        tmpNode.AddChild(Stmt_Analysis());
        if(now.word == "else") {
			tmpNode.AddChild(ParserTreeNode(true, ELSETK, "else", Unknown));
            getNext();
            tmpNode.AddChild(Stmt_Analysis());
        }
    }
    // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    else if (now.word == "for") {
		tmpNode.AddChild(ParserTreeNode(true, FORTK, "for", Unknown));
        getNext();

        if (now.word != "(") {
            PrintError("Unexpected error when analyse Stmt!");
            return ParserTreeNode();
        }
        else {
			tmpNode.AddChild(ParserTreeNode(true, LPARENT, "(", Unknown));
			getNext();
        }

        if (now.word != ";") {
            ForStmt_Analysis();
        }
		tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
		getNext();

        if (now.word != ";") {
            Cond_Analysis();
        }
		tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
        getNext();

        if (now.word != ")") {
            tmpNode.AddChild(ForStmt_Analysis());
        }
		tmpNode.AddChild(ParserTreeNode(true, RPARENT, ")", Unknown));
        getNext();

        tmpNode.AddChild(Stmt_Analysis());
    }
    // 'break' ';' | 'continue' ';'
    else if (now.word == "break" || now.word == "continue") {
		tmpNode.AddChild(ParserTreeNode(true, now.type, now.word, Unknown));
        if (PreRead().word != ";") {
            RecordError(now.line, now.characterCount,  "i");
        }
        else getNext();
		tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
		getNext();
    }
    // 'return' [Exp] ';'
    else if (now.word == "return") {
		tmpNode.AddChild(ParserTreeNode(true, RETURNTK, "return", Unknown));
        if (PreRead().word != ";") {
            if (isTheFirstOfExp(preRead)) {
                getNext();
                tmpNode.AddChild(Exp_Analysis());
                if (now.word != ";") {
                    RecordError(LastTokenLine(), LastTokenCharacterCount(),  "i");
                }
                else {
					tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
                    getNext();
                }
            }
            else {
                RecordError(now.line, now.characterCount,  "i");
            }
        }
        else {
            getNext();
			tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
            getNext();
        }
    }
    // 'printf''('StringConst {','Exp}')'';'
    else if (now.word == "printf") {
		tmpNode.AddChild(ParserTreeNode(true, PRINTFTK, "printf", Unknown));
        getNext();

        if (now.word != "(") {
            PrintError("Unexpected error when analyse Stmt!");
            return ParserTreeNode();
        }
		tmpNode.AddChild(ParserTreeNode(true, LPARENT, "(", Unknown));
        getNext();

        if (!isSTRCON(now)) {
            PrintError("Unexpected error when analyse Stmt!");
            return ParserTreeNode();
        }
		tmpNode.AddChild(ParserTreeNode(true, STRCON, now.word, Unknown));
		getNext();
        while (now.word == ",") {
			tmpNode.AddChild(ParserTreeNode(true, COMMA, ",", Unknown));
            getNext();
            tmpNode.AddChild(Exp_Analysis());
        }

        if (now.word != ")") {
            RecordError(LastTokenLine(), LastTokenCharacterCount(),  "j");
        }
        else {
			tmpNode.AddChild(ParserTreeNode(true, RPARENT, ")", Unknown));
			getNext();
        }
        if (now.word != ";") {
            RecordError(LastTokenLine(), LastTokenCharacterCount(),  "i");
        }
        else {
			tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
			getNext();
        }
    }
    else {
        // 其他Exp ；的情况
        tmpNode.AddChild(Exp_Analysis());
		if (now.word != ";") {
			RecordError(LastTokenLine(), LastTokenCharacterCount(),  "i");
		}
        else {
			tmpNode.AddChild(ParserTreeNode(true, SEMICN, ";", Unknown));
			getNext();
        }
    }
    // fileout << GraItem_Str.find(Stmt)->second << endl;
    return tmpNode;
}
ParserTreeNode ForStmt_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::ForStmt);
    // LVal
    if (isIdent(now)) {
        tmpNode.AddChild(LVal_Analysis());
        // '='
        if (now.word != "=") {
            PrintError("Unexpected error when analyse ForStmt!");
            return ParserTreeNode();
        }
		tmpNode.AddChild(ParserTreeNode(true, ASSIGN, "=", Unknown));
        // Exp
        getNext();
        tmpNode.AddChild(Exp_Analysis());
    }
    else {
        PrintError("Unexpected error when analyse ForStmt!");
    }
    // fileout << GraItem_Str.find(ForStmt)->second << endl;
    return tmpNode;
}
ParserTreeNode Exp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::Exp);
    // AddExp
    tmpNode.AddChild(AddExp_Analysis());
    // fileout << GraItem_Str.find(Exp)->second << endl;
    return tmpNode;
}
ParserTreeNode Cond_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::Cond);
    // LOrExp
    tmpNode.AddChild(LOrExp_Analysis());
    // fileout << GraItem_Str.find(Cond)->second << endl;
    return tmpNode;
}
ParserTreeNode LVal_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::LVal);
    // Ident
    if (isIdent(now)) {
		tmpNode.AddChild(ParserTreeNode(true, IDENFR, now.word, Unknown));
        getNext();
        // [ '[' Exp ']' ]
        if (now.word == "[") {
            getNext();
            tmpNode.AddChild(Exp_Analysis());
            if (now.word != "]") {
                RecordError(LastTokenLine(), LastTokenCharacterCount(),  "k");
            }
            else {
				tmpNode.AddChild(ParserTreeNode(true, RBRACK, "]", Unknown));
				getNext();
            }
        }
		
        // fileout << GraItem_Str.find(LVal)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse LVal!");
        return ParserTreeNode();
    }
}
ParserTreeNode PrimaryExp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::PrimaryExp);
    //  '(' Exp ')' | LVal | Number | Character
    if (isIdent(now)) {
        // LVal
        tmpNode.AddChild(LVal_Analysis());
    }
    // '(' Exp ')'
    else if (now.word == "(") {
        getNext();
        tmpNode.AddChild(ParserTreeNode(true, LPARENT, "(", Unknown));
        tmpNode.AddChild(Exp_Analysis());
        if (now.word != ")") {
            RecordError(LastTokenLine(), LastTokenCharacterCount(),  "j");
        }
        else {
			tmpNode.AddChild(ParserTreeNode(true, RPARENT, ")", Unknown));
			getNext();
        }
    }
    // Number
    else if (isINTCON(now)) {
        tmpNode.AddChild(Number_Analysis());
    }
    // Character
    else if (isCHRCON(now)) {
        tmpNode.AddChild(Character_Analysis());
    }
    else {
        PrintError("Unexpected error when analyse PrimaryExp!");
        return ParserTreeNode();
    }
    // fileout << GraItem_Str.find(PrimaryExp)->second << endl;
    return tmpNode;
}
ParserTreeNode Number_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::Number);
    if (isINTCON(now)) {
		tmpNode.AddChild(ParserTreeNode(true, INTCON, now.word, Unknown));
		getNext();
        // fileout << GraItem_Str.find(Number)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse Number!");
        return ParserTreeNode();
    }
}
ParserTreeNode Character_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::Character);
    if (isCHRCON(now)) {
		getNext();
		tmpNode.AddChild(ParserTreeNode(true, CHRCON, now.word, Unknown));
        // fileout << GraItem_Str.find(Character)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse Character!");
        return ParserTreeNode();
    }
}
ParserTreeNode UnaryExp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::UnaryExp);
    if (isIdent(now)) {
        if (PreRead().word == "(") {
            // Ident '(' [FuncRParams] ')'
            tmpNode.AddChild(ParserTreeNode(true, IDENFR, now.word, Unknown));
            getNext();
			tmpNode.AddChild(ParserTreeNode(true, LPARENT, "(", Unknown));
			getNext();
            if (now.word != ")") {
				// FuncRParams
				if (isTheFirstOfExp(now)) {
                    tmpNode.AddChild(FuncRParams_Analysis());
					if (now.word != ")") {
						RecordError(LastTokenLine(), LastTokenCharacterCount(),  "j");
					}
                    else {
						tmpNode.AddChild(ParserTreeNode(true, RPARENT, ")", Unknown));
						getNext();
                    }
                }
                else {
					RecordError(LastTokenLine(), LastTokenCharacterCount(),  "j");
                }
            }
            else {
				tmpNode.AddChild(ParserTreeNode(true, RPARENT, ")", Unknown));
				getNext();
            }
        }
        else {
			// LVal => PrimaryExp
            tmpNode.AddChild(PrimaryExp_Analysis());
        }
    }
    // UnaryOp UnaryExp
    else if (isTheFirstOfUnaryOp(now)) {
        tmpNode.AddChild(UnaryOp_Analysis());
        tmpNode.AddChild(UnaryExp_Analysis());
    }
    // PrimaryExp 
    else {
        tmpNode.AddChild(PrimaryExp_Analysis());
    }
    // fileout << GraItem_Str.find(UnaryExp)->second << endl;
    return tmpNode;
}
ParserTreeNode UnaryOp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::UnaryOp);
    if (now.word == "!" || now.word == "-" || now.word == "+") {
		tmpNode.AddChild(ParserTreeNode(true, now.type, now.word, Unknown));
		getNext();
        // fileout << GraItem_Str.find(UnaryOp)->second << endl;
        return tmpNode;
    }
    else {
        PrintError("Unexpected error when analyse UnaryOp!");
        return ParserTreeNode();
    }
}
ParserTreeNode FuncRParams_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::FuncRParams);
    // Exp
    tmpNode.AddChild(Exp_Analysis());
    // { ',' Exp }
    while (now.word == ",") {
		tmpNode.AddChild(ParserTreeNode(true, COMMA, ",", Unknown));
        getNext();
        tmpNode.AddChild(Exp_Analysis());
    }
    // fileout << GraItem_Str.find(FuncRParams)->second << endl;
    return tmpNode;
}
ParserTreeNode MulExp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::MulExp);
    // UnaryExp
    tmpNode.AddChild(UnaryExp_Analysis());
    // {('*' | '/' | '%') UnaryExp}
    while (now.word == "*" || now.word == "/" || now.word == "%") {
        // fileout << GraItem_Str.find(MulExp)->second << endl;
		tmpNode.AddChild(ParserTreeNode(true, now.type, now.word, Unknown));
        getNext();
        tmpNode.AddChild(UnaryExp_Analysis());
    }
    // fileout << GraItem_Str.find(MulExp)->second << endl;
    return tmpNode;
}
ParserTreeNode AddExp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::AddExp);
    // MulExp
    tmpNode.AddChild(MulExp_Analysis());
    // {('+' | '-') MulExp}
    while (now.word == "+" || now.word == "-") {
        // fileout << GraItem_Str.find(AddExp)->second << endl;
		tmpNode.AddChild(ParserTreeNode(true, now.type, now.word, Unknown));
        getNext();
        tmpNode.AddChild(MulExp_Analysis());
    }
    // fileout << GraItem_Str.find(AddExp)->second << endl;
    return tmpNode;
}
ParserTreeNode RelExp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::RelExp);
    // AddExp
    tmpNode.AddChild(AddExp_Analysis());
    // {('<' | '>' | '<=' | '>=') AddExp}
    while (now.word == "<" || now.word == ">" || now.word == "<=" || now.word == ">=") {
        // fileout << GraItem_Str.find(RelExp)->second << endl;
		tmpNode.AddChild(ParserTreeNode(true, now.type, now.word, Unknown));
        getNext();
        AddExp_Analysis();
    }
    // fileout << GraItem_Str.find(RelExp)->second << endl;
    return tmpNode;
}
ParserTreeNode EqExp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::EqExp);
    // RelExp
    tmpNode.AddChild(RelExp_Analysis());
    // ('==' | '!=') RelExp
    if (now.word == "==" || now.word == "!=") {
        // fileout << GraItem_Str.find(EqExp)->second << endl;
		tmpNode.AddChild(ParserTreeNode(true, now.type, now.word, Unknown));
        getNext();
        tmpNode.AddChild(RelExp_Analysis());
    }
    // fileout << GraItem_Str.find(EqExp)->second << endl;
    return tmpNode;
}
ParserTreeNode LAndExp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::LAndExp);
    // EqExp
    tmpNode.AddChild(EqExp_Analysis());
    // {'&&' EqExp}
    while (now.word == "&&" || now.word == "&") {
        // fileout << GraItem_Str.find(LAndExp)->second << endl;
		tmpNode.AddChild(ParserTreeNode(true, AND, now.word, Unknown));
        getNext();
        tmpNode.AddChild(EqExp_Analysis());
    }
    // fileout << GraItem_Str.find(LAndExp)->second << endl;
    return tmpNode;
}
ParserTreeNode LOrExp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::LOrExp);
    // LAndExp
    tmpNode.AddChild(LAndExp_Analysis());
    // {'||' LAndExp}
    while (now.word == "||" || now.word == "|") {
        // fileout << GraItem_Str.find(LOrExp)->second << endl;
		tmpNode.AddChild(ParserTreeNode(true, OR, now.word, Unknown));
        getNext();
        tmpNode.AddChild(LAndExp_Analysis());
    }
    // fileout << GraItem_Str.find(LOrExp)->second << endl;
    return tmpNode;
}
ParserTreeNode ConstExp_Analysis() {
	ParserTreeNode tmpNode(false, TokenType::None, "", GraItem::ConstExp);
    // AddExp
    tmpNode.AddChild(AddExp_Analysis());
    // fileout << GraItem_Str.find(ConstExp)->second << endl;
    return tmpNode;
}
string PreHandleLVal() {
    int index = nowIndex;
    // Ident
    if (isIdent(now)) {
        // [ '[' Exp ']' ]
        if (PreRead().word == "[") {
            index++;
            while (index < Lexer::tokens.size() && Lexer::tokens[index].word != "]" && Lexer::tokens[index + 1].word != "=" && Lexer::tokens[index + 1].word != ";") {
                index++;
            }
        }
        if (index < Lexer::tokens.size() - 1) {
            return Lexer::tokens[index + 1].word;
        }
        else {
            return "";
        }
    }
    else {
        PrintError("Unexpected error when analyse LVal!");
        return "";
    }
}
bool isTheFirstOfExp(Token token) {
    return token.word == "(" || isIdent(token) || isINTCON(token) || isCHRCON(token) || token.word == "!" || token.word == "-" || token.word == "+";
}
bool isTheFirstOfUnaryOp(Token token) {
    return token.word == "!" || token.word == "-" || token.word == "+";
}
bool isBType(string str) {
	return str == "int" || str == "char";
}


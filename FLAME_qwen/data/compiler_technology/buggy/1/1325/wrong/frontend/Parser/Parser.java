package frontend.Parser;

import frontend.ErrorHandler.Error;
import frontend.ErrorHandler.ErrorHandler;
import frontend.Lexer;
import frontend.LexerTool.Token;
import frontend.LexerTool.TypeCode;

import java.io.IOException;
import java.util.LinkedList;

import static frontend.LexerTool.TypeCode.*;

public class Parser {

    private int index = -1;

    private Lexer lexer;

    private Token curToken;

    private LinkedList<Token> tokenList = new LinkedList<>();

    public Parser(Lexer lexer) {
        this.lexer = lexer;
    }

    public void recover() {
        index--;
        if (index != -1) {
            curToken = tokenList.get(index);
        }
    }

    public void recover(int pos) {
        index = pos;
        if (index != -1) {
            curToken = tokenList.get(index);
        }
    }

    public void getToken() throws IOException {
        index++;
        if (index == tokenList.size()) {
            tokenList.add(lexer.getToken());
        }
        curToken =  tokenList.get(index);
    }

    public boolean peekToken(TypeCode... typeCodes) throws IOException {
        getToken();
        for (TypeCode typeCode : typeCodes) {
            if (curToken.isType(typeCode)) {
                return true;
            }
        }
        recover();
        return false;
    }

    public void peekAndAdd(LinkedList<ParsedTree> subTree, TypeCode... typeCodes) throws IOException {
        getToken();
        subTree.add(curToken);
    }

    public void replace(String typeCode, LinkedList<ParsedTree> subTree1) {
        LinkedList<ParsedTree> prefix = new LinkedList<>(subTree1);
        ParsedTree preTree = new ParsedTree(typeCode, prefix);
        subTree1.clear();
        subTree1.add(preTree);
        subTree1.add(curToken);
    }

    public void addError(String errorCode) {
        ErrorHandler.ERROR.addError(new Error(errorCode, curToken.getLinePos()));
    }

    public ParsedTree parseCompUnit() throws IOException {
        //编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        int oldPos = -1;
        //parse {Decl}
        //声明 Decl → ConstDecl | VarDecl
        while (peekToken(CONSTTK, INTTK, CHARTK)) {
            oldPos = index - 1;
            if (curToken.isType(CONSTTK)) {
                recover(oldPos);
                subTree.add(parseConstDecl());
            } else if (!peekToken(IDENFR)) { //main
                recover(oldPos);
                break;
            } else if (peekToken(LPARENT)) {
                recover(oldPos);
                break;
            } else {
                recover(oldPos);
                subTree.add(parseVarDecl());
            }
        }
        //parse {FuncDef}
        //函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        while (peekToken(INTTK, VOIDTK, CHARTK)){
            oldPos = index - 1;
            if (!curToken.isType(INTTK)) {
                recover(oldPos);
                subTree.add(parseFuncDef());
            } else if (peekToken(MAINTK)){
                recover(oldPos);
                break;
            } else {
                recover(oldPos);
                subTree.add(parseFuncDef());
            }
        }
        //parse {MainFuncDef}
        subTree.add(parseMainFuncDef());
        return new ParsedTree("CompUnit", subTree);
    }

    private ParsedTree parseConstDecl() throws IOException {
        //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'  // i
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, CONSTTK);
        //BType → 'int' | 'char'
        peekAndAdd(subTree, INTTK, CHARTK);
        subTree.add(parseConstDef());
        while (peekToken(COMMA)) {
            subTree.add(curToken);
            subTree.add(parseConstDef());
        }
        if (peekToken(SEMICN)){
            subTree.add(curToken);
        } else {
            addError("i");
        }
        return new ParsedTree("ConstDecl", subTree);
    }

    private ParsedTree parseConstDef() throws IOException {
        //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // b k
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, IDENFR);
        if (peekToken(LBRACK)) {
            subTree.add(curToken);
            subTree.add(parseConstExp());
            if (peekToken(RBRACK)) {
                subTree.add(curToken);
            } else {
                addError("k");
            }
        }
        peekAndAdd(subTree, ASSIGN);
        subTree.add(parseConstInitVal());
        return new ParsedTree("ConstDef", subTree);
    }

    private ParsedTree parseConstInitVal() throws IOException {
        //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' || StringConst
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        if (peekToken(STRCON)) {
            subTree.add(curToken);
        } else if (peekToken(LBRACE)) {
            subTree.add(curToken);
            if (!peekToken(RBRACE)) {
                subTree.add(parseConstExp());
                while (peekToken(COMMA)) {
                    subTree.add(curToken);
                    subTree.add(parseConstExp());
                }
                peekAndAdd(subTree, RBRACE);
            } else {
                subTree.add(curToken);
            }
        } else {
            subTree.add(parseConstExp());
        }
        return new ParsedTree("ConstInitVal", subTree);
    }

    private ParsedTree parseVarDecl() throws IOException {
        //VarDecl → BType VarDef { ',' VarDef } ';' // i
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, INTTK, CONSTTK);
        subTree.add(parseVarDef());
        while (peekToken(COMMA)) {
            subTree.add(curToken);
            subTree.add(parseVarDef());
        }
        if (peekToken(SEMICN)){
            subTree.add(curToken);
        } else {
            addError("i");
        }
        return new ParsedTree("VarDecl", subTree);
    }

    private ParsedTree parseVarDef() throws IOException {
        //VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // b k
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, IDENFR);
        if (peekToken(LBRACK)) {
            subTree.add(curToken);
            subTree.add(parseConstExp());
            if (peekToken(RBRACK)) {
                subTree.add(curToken);
            } else {
                addError("k");
            }
        }
        if (peekToken(ASSIGN)) {
            subTree.add(curToken);
            subTree.add(parseInitVal());
        }
        return new ParsedTree("VarDef", subTree);
    }

    private ParsedTree parseInitVal() throws IOException {
        //InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        if (peekToken(STRCON)) {
            subTree.add(curToken);
        } else if (peekToken(LBRACE)) {
            subTree.add(curToken);
            if (!peekToken(RBRACE)) {
                subTree.add(parseExp());
                while (peekToken(COMMA)) {
                    subTree.add(curToken);
                    subTree.add(parseExp());
                }
                peekAndAdd(subTree, RBRACE);
            } else {
                subTree.add(curToken);
            }
        } else {
            subTree.add(parseExp());
        }
        return new ParsedTree("InitVal", subTree);
    }

    private ParsedTree parseFuncDef() throws IOException {
        //FuncDef → FuncType Ident '(' [FuncFParams] ')' Block  // b g j
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseFuncType());
        peekAndAdd(subTree, IDENFR);
        peekAndAdd(subTree, LPARENT);
        if (peekToken(LBRACE)) {
            recover();
            addError("j");
        } else if (!peekToken(RPARENT)) {
            subTree.add(parseFuncFParams());
            if (peekToken(RPARENT)) {
                subTree.add(curToken);
            } else {
                addError("j");
            }
        } else {
            subTree.add(curToken);
        }
        subTree.add(parseBlock());
        return new ParsedTree("FuncDef", subTree);
    }


    private ParsedTree parseMainFuncDef() throws IOException {
        //MainFuncDef → 'int' 'main' '(' ')' Block // g j
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, INTTK);
        peekAndAdd(subTree, MAINTK);
        peekAndAdd(subTree, LPARENT);
        if (peekToken(RPARENT)) {
            subTree.add(curToken);
        } else {
            addError("j");
        }
        subTree.add(parseBlock());
        return new ParsedTree("MainFuncDef", subTree);
    }

    private ParsedTree parseFuncType() throws IOException {
        //FuncType → 'void' | 'int' | 'char'
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, VOIDTK, INTTK, CHARTK);
        return new ParsedTree("FuncType", subTree);
    }

    private ParsedTree parseFuncFParams() throws IOException {
        //FuncFParams → FuncFParam { ',' FuncFParam }
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseFuncFParam());
        while (peekToken(COMMA)) {
            subTree.add(curToken);
            subTree.add(parseFuncFParam());
        }
        return new ParsedTree("FuncFParams", subTree);
    }

    private ParsedTree parseFuncFParam() throws IOException {
        //FuncFParam → BType Ident ['[' ']'] // b k
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, CHARTK, INTTK);
        peekAndAdd(subTree, IDENFR);
        if (peekToken(LBRACK)) {
            subTree.add(curToken);
            if (peekToken(RBRACK)) {
                subTree.add(curToken);
            } else {
                addError("k");
            }
        }
        return new ParsedTree("FuncFParam", subTree);
    }

    private ParsedTree parseBlock() throws IOException {
        //Block → '{' { BlockItem } '}'
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, LBRACE);
        while (!peekToken(RBRACE)) {
            subTree.add(parseBlockItem());
        }
        subTree.add(curToken);
        return new ParsedTree("Block", subTree);
    }

    private ParsedTree parseBlockItem() throws IOException {
        //BlockItem → Decl | Stmt
        if (peekToken(CONSTTK, INTTK, CHARTK)) {
            if (curToken.isType(CONSTTK)) {
                recover();
                return parseConstDecl();
            }
            recover();
            return parseVarDecl();
        }
        return parseStmt();
    }

    private ParsedTree parseStmt() throws IOException {
        /*Stmt → LVal '=' Exp ';' // h i
        | [Exp] ';' // i
        | Block
        | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
        | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // h
        | 'break' ';' | 'continue' ';' // i m
        | 'return' [Exp] ';' // f i
        | LVal '=' 'getint''('')'';' // h i j
        | LVal '=' 'getchar''('')'';' // h i j
        | 'printf''('StringConst {','Exp}')'';' // i j l
         */

        LinkedList<ParsedTree> subTree = new LinkedList<>();
        getToken();
        switch (curToken.getTypeCode()) {
            //Block
            case LBRACE:
                recover();
                subTree.add(parseBlock());
                break;
            case SEMICN:
                subTree.add(curToken);
                break;
            //LVal '=' Exp ';' // h i
            //LVal '=' 'getint''('')'';' // h i j
            //LVal '=' 'getchar''('')'';' // h i j
            //[Exp] ';' // i
            case IDENFR:
                if (peekToken(ASSIGN, LBRACK)) {
                    recover();
                    recover();
                    subTree.add(parseLVal());
                    peekAndAdd(subTree, ASSIGN);
                    if (peekToken(GETINTTK, GETCHARTK)) {
                        subTree.add(curToken);
                        peekAndAdd(subTree, LPARENT);
                        if (peekToken(RPARENT)) {
                            subTree.add(curToken);
                        } else {
                            addError("j");
                        }
                    } else {
                        subTree.add(parseExp());
                    }
                } else {
                    recover();
                    subTree.add(parseExp());
                }
                if (peekToken(SEMICN)) {
                    subTree.add(curToken);
                } else {
                    addError("i");
                }
                break;
            //'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
            case IFTK:
                subTree.add(curToken);
                peekAndAdd(subTree, LPARENT);
                subTree.add(parseCond());
                if (peekToken(RPARENT)) {
                    subTree.add(curToken);
                } else {
                    addError("j");
                }
                subTree.add(parseStmt());
                if (peekToken(ELSETK)) {
                    subTree.add(curToken);
                    subTree.add(parseStmt());
                }
                break;
            //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // h
            case FORTK:
                subTree.add(curToken);
                peekAndAdd(subTree, LPARENT);
                if (peekToken(SEMICN)) {
                    subTree.add(curToken);
                } else {
                    subTree.add(parseForStmt());
                    peekAndAdd(subTree, SEMICN);
                }
                if (peekToken(SEMICN)) {
                    subTree.add(curToken);
                } else {
                    subTree.add(parseCond());
                    peekAndAdd(subTree, SEMICN);
                }
                if (peekToken(RPARENT)) {
                    subTree.add(curToken);
                } else {
                    subTree.add(parseForStmt());
                    peekAndAdd(subTree, RPARENT);
                }
                subTree.add(parseStmt());
                break;
            //'break' ';' | 'continue' ';'  // i m
            case BREAKTK:
            case CONTINUETK:
                subTree.add(curToken);
                if (peekToken(SEMICN)){
                    subTree.add(curToken);
                } else {
                    addError("i");
                }
                break;
            //'return' [Exp] ';' // f i
            case RETURNTK:
                subTree.add(curToken);
                int oldPos = index;
                if (peekToken(INTCON, CHRCON, IDENFR, PLUS, MINU, NOT, LPARENT)) {//First(exp)
                    recover();
                    subTree.add(parseExp());
                }
                if (peekToken(SEMICN)){
                    subTree.add(curToken);
                } else {
                    recover();
                    subTree.add(parseExp());
                    if (peekToken(SEMICN)){
                        subTree.add(curToken);
                    } else {
                        addError("i");
                    }
                }
                break;
            //'printf''('StringConst {','Exp}')'';' // i j l
            case PRINTFTK:
                subTree.add(curToken);
                peekAndAdd(subTree, LPARENT);
                peekAndAdd(subTree, STRCON);
                while (peekToken(COMMA)) {
                    subTree.add(curToken);
                    subTree.add(parseExp());
                }
                if (peekToken(RPARENT)) {
                    subTree.add(curToken);
                } else {
                    addError("j");
                }
                if (peekToken(SEMICN)){
                    subTree.add(curToken);
                } else {
                    addError("i");
                }
                break;
            //[Exp] ';' // i
            default:
                recover();
                subTree.add(parseExp());
                if (peekToken(SEMICN)) {
                    subTree.add(curToken);
                } else {
                    addError("i");
                }
                break;
        }

        return new ParsedTree("Stmt", subTree);
    }

    private ParsedTree parseForStmt() throws IOException {
        //ForStmt → LVal '=' Exp // h
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseLVal());
        peekAndAdd(subTree, ASSIGN);
        subTree.add(parseExp());
        return new ParsedTree("ForStmt", subTree);
    }

    private ParsedTree parseExp() throws IOException {
        //Exp → AddExp
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseAddExp());
        return new ParsedTree("Exp", subTree);
    }

    private ParsedTree parseCond() throws IOException {
        //Cond → LOrExp
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseLOrExp());
        return new ParsedTree("Cond", subTree);
    }

    private ParsedTree parseLVal() throws IOException {
        //LVal → Ident ['[' Exp ']'] // c k
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, IDENFR);
        if (peekToken(LBRACK)) {
            subTree.add(curToken);
            subTree.add(parseExp());
            if (peekToken(RBRACK)) {
                subTree.add(curToken);
            } else {
                addError("k");
            }
        }
        return new ParsedTree("LVal", subTree);
    }

    private ParsedTree parsePrimaryExp() throws IOException {
        //PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        getToken();
        switch (curToken.getTypeCode()) {
            case LPARENT:
                subTree.add(curToken);
                subTree.add(parseExp());
                if (peekToken(RPARENT)) {
                    subTree.add(curToken);
                } else {
                    addError("j");
                }
                break;
            case INTCON:
                recover();
                subTree.add(parseNumber());
                break;
            case CHRCON:
                recover();
                subTree.add(parseCharacter());
                break;
            default:
                recover();
                subTree.add(parseLVal());
        }
        return new ParsedTree("PrimaryExp", subTree);
    }

    private ParsedTree parseNumber() throws IOException {
        //Number → IntConst
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, INTCON);
        return new ParsedTree("Number", subTree);
    }

    private ParsedTree parseCharacter() throws IOException {
        //Character → CharConst
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, CHRCON);
        return new ParsedTree("Character", subTree);
    }

    private ParsedTree parseUnaryExp() throws IOException {
        //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp //c d e j
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        if (peekToken(PLUS, MINU, NOT)) {
            recover();
            subTree.add(parseUnaryOp());
            subTree.add(parseUnaryExp());
        } else if (peekToken(IDENFR)) {
            if (peekToken(LPARENT)) {
                recover();
                subTree.add(curToken);
                peekAndAdd(subTree, LPARENT);
                if (peekToken(INTCON, CHRCON, IDENFR, PLUS, MINU, NOT, LPARENT)) {
                    recover();
                    subTree.add(parseFuncRParams());
                }
                if (peekToken(RPARENT)) {
                    subTree.add(curToken);
                } else {
                    addError("j");
                }
            } else {
                recover();
                subTree.add(parsePrimaryExp());
            }
        } else {
            subTree.add(parsePrimaryExp());
        }
        return new ParsedTree("UnaryExp", subTree);
    }

    private ParsedTree parseUnaryOp() throws IOException {
        //UnaryOp → '+' | '−' | '!'
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        peekAndAdd(subTree, PLUS, MINU, NOT);
        return new ParsedTree("UnaryOp", subTree);
    }

    private ParsedTree parseFuncRParams() throws IOException {
        //FuncRParams → Exp { ',' Exp }
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseExp());
        while (peekToken(COMMA)) {
            subTree.add(curToken);
            subTree.add(parseExp());
        }
        return new ParsedTree("FuncRParams", subTree);
    }

    private ParsedTree parseMulExp() throws IOException {
        // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        // MulExp → UnaryExp { ('*' | '/' | '%') UnaryExp }
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseUnaryExp());
        while (peekToken(MULT, DIV, MOD)) {
            replace("MulExp", subTree);
            subTree.add(parseUnaryExp());
        }
        return new ParsedTree("MulExp", subTree);
    }

    private ParsedTree parseAddExp() throws IOException {
        // AddExp → MulExp | AddExp ('+' | '−') MulExp
        // AddExp → MulExp { ('+' | '−') MulExp }
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseMulExp());
        while (peekToken(PLUS, MINU)) {
            replace("AddExp", subTree);
            subTree.add(parseMulExp());
        }
        return new ParsedTree("AddExp", subTree);
    }

    private ParsedTree parseRelExp() throws IOException {
        // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        // RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp }
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseAddExp());
        while (peekToken(LSS, GRE, LEQ, GEQ)) {
            replace("RelExp", subTree);
            subTree.add(parseAddExp());
        }
        return new ParsedTree("RelExp", subTree);
    }

    private ParsedTree parseEqExp() throws IOException {
        // EqExp → RelExp | EqExp ('==' | '!=') RelExp
        // EqExp → RelExp { ('==' | '!=') RelExp }
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseRelExp());
        while (peekToken(EQL, NEQ)){
            replace("EqExp", subTree);
            subTree.add(parseRelExp());
        }
        return new ParsedTree("EqExp", subTree);
    }

    private ParsedTree parseLAndExp() throws IOException {
        // LAndExp → EqExp | LAndExp '&&' EqExp // a
        // LAndExp → EqExp { '&&' EqExp  }
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseEqExp());
        while (peekToken(AND)) {
            replace("LAndExp", subTree);
            subTree.add(parseEqExp());
        }
        return new ParsedTree("LAndExp", subTree);
    }

    private ParsedTree parseLOrExp() throws IOException {
        // LOrExp → LAndExp | LOrExp '||' LAndExp // a
        // LOrExp → LAndExp { '||' LAndExp } // a
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseLAndExp());
        while (peekToken(OR)) {
            replace("LOrExp", subTree);
            subTree.add(parseLAndExp());
        }
        return new ParsedTree("LOrExp", subTree);
    }

    private ParsedTree parseConstExp() throws IOException {
        // ConstExp → AddExp
        LinkedList<ParsedTree> subTree = new LinkedList<>();
        subTree.add(parseAddExp());
        return new ParsedTree("ConstExp", subTree);
    }
}
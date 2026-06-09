package frontend;

import java.io.PrintStream;

public class Parser {
    private static Parser parser = new Parser();
    private static PrintStream fileOut1;
    private static PrintStream fileOut2;
    private static Token token;
    private static Token root;

    public Parser() {

    }

    public static void start() {
        getToken();
        root = CompUnit();
    }

    private static Token CompUnit() {
        Token t = new Token(Type.CompUnit);
        while (type() == Type.CONSTTK ||
                ((type() == Type.CHARTK || type() == Type.INTTK) && pre(false, 2) != Type.LPARENT)) {
            t.setTree(Decl());
        }
        while ((type() == Type.CHARTK || type() == Type.VOIDTK) ||
                (type() == Type.INTTK && pre(false, 1) == Type.IDENFR)) {
            t.setTree(FuncDef());
        }
        t.setTree(MainFuncDef());
        Lexer.print();
		fileOut1.printf("<%s>\n", "CompUnit");
        return t;
    }

    private static Token Decl() {
        Token t = new Token(Type.Decl);
        if (type() == Type.CONSTTK) {
            t.setTree(ConstDecl());
        } else {
            t.setTree(VarDecl());
        }
        return t;
    }

    private static Token FuncDef() {
        Token t = new Token(Type.FuncDef);
        t.setTree(FuncType());
        t.setTree(getToken());
        t.setTree(getToken());
        if (type() == Type.INTTK || type() == Type.CHARTK) {
            t.setTree(FuncFParams());
        }
        if (type() != Type.RPARENT) {
            t.setTree(error('j'));
        } else {
            t.setTree(getToken());
        }
        t.setTree(Block());
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncDef");
        return t;
    }

    private static Token MainFuncDef() {
        Token t = new Token(Type.MainFuncDef);
        t.setTree(getToken());
        t.setTree(getToken());
        t.setTree(getToken());
        if (type() != Type.RPARENT) {
            t.setTree(error('j'));
        } else {
            t.setTree(getToken());
        }
        t.setTree(Block());
        Lexer.print();
		fileOut1.printf("<%s>\n", "MainFuncDef");
        return t;
    }

    private static Token ConstDecl() {
        Token t = new Token(Type.ConstDecl);
        t.setTree(getToken());  //const
        t.setTree(BType());
        t.setTree(ConstDef());
        while (type() == Type.COMMA) {
            t.setTree(getToken());
            t.setTree(ConstDef());
        }
        if (type() != Type.SEMICN) {
            t.setTree(error('i'));
        } else {
            t.setTree(getToken());
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "ConstDecl");
        return t;
    }

    private static Token VarDecl() {
        Token t = new Token(Type.VarDecl);
        t.setTree(BType());
        t.setTree(VarDef());
        while (type() == Type.COMMA) {
            t.setTree(getToken());
            t.setTree(VarDef());
        }
        if (type() != Type.SEMICN) {
            t.setTree(error('i'));
        } else {
            t.setTree(getToken());
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "VarDecl");
        return t;
    }

    private static Token BType() {
        Token t = new Token(Type.BType);
        t.setTree(getToken());
        return t;
    }

    private static Token ConstDef() {
        Token t = new Token(Type.ConstDef);
        t.setTree(getToken());
        if (type() == Type.LBRACK) {
            t.setTree(getToken());
            t.setTree(ConstExp());
            if (type() != Type.RBRACK) {
                t.setTree(error('k'));
            } else {
                t.setTree(getToken());
            }
        }
        t.setTree(getToken());
        t.setTree(ConstInitVal());
        Lexer.print();
		fileOut1.printf("<%s>\n", "ConstDef");
        return t;
    }

    private static Token ConstExp() {
        Token t = new Token(Type.ConstExp);
        t.setTree(AddExp());
        Lexer.print();
		fileOut1.printf("<%s>\n", "ConstExp");
        return t;
    }

    private static Token ConstInitVal() {
        Token t = new Token(Type.ConstInitVal);
        if (type() == Type.LBRACE) {
            t.setTree(getToken());
            if (type() != Type.RBRACE) {
                t.setTree(ConstExp());
                while (type() == Type.COMMA) {
                    t.setTree(getToken());
                    t.setTree(ConstExp());
                }
            }
            t.setTree(getToken());
        } else if (type() == Type.STRCON) {
            t.setTree(getToken());
        } else {
            t.setTree(ConstExp());
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "ConstInitVal");
        return t;
    }

    private static Token AddExp() {
        Token tmp = new Token(Type.AddExp);
        Token t0;
        tmp.setTree(MulExp());
        Lexer.print();
        fileOut1.printf("<%s>\n", "AddExp");
        while (type() == Type.PLUS || type() == Type.MINU) {
            t0 = new Token(Type.AddExp);
            t0.setTree(tmp);
            t0.setTree(getToken());
            t0.setTree(MulExp());
            tmp = t0;
            Lexer.print();
            fileOut1.printf("<%s>\n", "AddExp");
        }
        return tmp;
    }

    private static Token MulExp() {
        Token tmp = new Token(Type.MulExp);
        Token t0;
        tmp.setTree(UnaryExp());
        Lexer.print();
        fileOut1.printf("<%s>\n", "MulExp");
        while (type() == Type.MULT || type() == Type.DIV || type() == Type.MOD) {
            t0 = new Token(Type.MulExp);
            t0.setTree(tmp);
            t0.setTree(getToken());
            t0.setTree(UnaryExp());
            tmp = t0;
            Lexer.print();
            fileOut1.printf("<%s>\n", "MulExp");
        }
        return tmp;
    }

    private static Token UnaryExp(){
        Token t = new Token(Type.UnaryExp);
        if(type() == Type.PLUS || type() == Type.MINU || type() == Type.NOT){
            t.setTree(UnaryOp());
            t.setTree(UnaryExp());
        }else{
            if (type() == Type.IDENFR && pre(false, 1) == Type.LPARENT) {
                t.setTree(getToken());
                t.setTree(getToken());
                if (type() == Type.PLUS || type() == Type.MINU || type() == Type.NOT ||
                        type() == Type.IDENFR || type() == Type.LPARENT || type() == Type.INTCON || type() == Type.CHRCON) {
                    t.setTree(FuncRParams());
                }
                if (type() != Type.RPARENT) {
                    t.setTree(error('j'));
                } else {
                    t.setTree(getToken());
                }
            }else{
                t.setTree(PrimaryExp());
            }
        }
        Lexer.print();
        fileOut1.printf("<%s>\n", "UnaryExp");
        return t;
    }
    /*private static Token UnaryExp() {
        int count = 0;
        while (type() == Type.PLUS || type() == Type.MINU || type() == Type.NOT) {
            UnaryOp();
            count++;
        }
        if (type() == Type.IDENFR && pre(false, 1) == Type.LPARENT) {
            getToken();
            getToken();
            if (type() == Type.PLUS || type() == Type.MINU || type() == Type.NOT ||
                    type() == Type.IDENFR || type() == Type.LPARENT || type() == Type.INTCON || type() == Type.CHRCON) {
                FuncRParams();
            }
            if (type() != Type.RPARENT) {
                error('j');
            } else {
                getToken();
            }
        } else {
            PrimaryExp();
        }
        while(count-->=0){
            Lexer.print();
            fileOut1.printf("<%s>\n", "UnaryExp");
        }
    }*/

    private static Token UnaryOp() {
        Token t = new Token(Type.UnaryOp);
        t.setTree(getToken());
        Lexer.print();
		fileOut1.printf("<%s>\n", "UnaryOp");
        return t;
    }

    private static Token FuncRParams() {
        Token t = new Token(Type.FuncRParams);
        t.setTree(Exp());
        while (type() == Type.COMMA) {
            t.setTree(getToken());
            t.setTree(Exp());
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncRParams");
        return t;
    }

    private static Token PrimaryExp() {
        Token t = new Token(Type.PrimaryExp);
        if (type() == Type.LPARENT) {
            t.setTree(getToken());
            t.setTree(Exp());
            if (type() != Type.RPARENT) {
                t.setTree(error('j'));
            } else {
                t.setTree(getToken());
            }
        } else if (type() == Type.IDENFR) {
            t.setTree(LVal());
        } else if (type() == Type.INTCON) {
            t.setTree(Number());
        } else {
            t.setTree(Character());
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "PrimaryExp");
        return t;
    }

    private static Token Exp() {
        Token t = new Token(Type.Exp);
        t.setTree(AddExp());
        Lexer.print();
		fileOut1.printf("<%s>\n", "Exp");
        return t;
    }

    private static Token LVal() {
        Token t= new Token(Type.LVal);
        t.setTree(getToken());
        if (type() == Type.LBRACK) {
            t.setTree(getToken());
            t.setTree(Exp());
            if (type() != Type.RBRACK) {
                t.setTree(error('k'));
            } else {
                t.setTree(getToken());
            }
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "LVal");
        return t;
    }

    private static Token Number() {
        Token t = new Token(Type.Number);
        t.setTree(getToken());
        Lexer.print();
		fileOut1.printf("<%s>\n", "Number");
        return t;
    }

    private static Token Character() {
        Token t = new Token(Type.Character);
        t.setTree(getToken());
        Lexer.print();
		fileOut1.printf("<%s>\n", "Character");
        return t;
    }

    private static Token VarDef() {
        Token t = new Token(Type.VarDef);
        t.setTree(getToken());
        if (type() == Type.LBRACK) {
            t.setTree(getToken());
            t.setTree(ConstExp());
            if (type() != Type.RBRACK) {
                t.setTree(error('k'));
            } else {
                t.setTree(getToken());
            }
        }
        if (type() == Type.ASSIGN) {
            t.setTree(getToken());
            t.setTree(InitVal());
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "VarDef");
        return t;
    }

    private static Token InitVal() {
        Token t =new Token(Type.InitVal);
        if (type() == Type.LBRACE) {
            t.setTree(getToken());
            if (type() != Type.RBRACE) {
                t.setTree(Exp());
                while (type() == Type.COMMA) {
                    t.setTree(getToken());
                    t.setTree(Exp());
                }
            }
            t.setTree(getToken());
        } else if (type() == Type.STRCON) {
            t.setTree(getToken());
        } else {
            t.setTree(Exp());
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "InitVal");
        return t;
    }

    private static Token FuncType() {
        Token t = new Token(Type.FuncType);
        t.setTree(getToken());
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncType");
        return t;
    }

    private static Token FuncFParams() {
        Token t = new Token(Type.FuncFParams);
        t.setTree(FuncFParam());
        while (type() == Type.COMMA) {
            t.setTree(getToken());
            t.setTree(FuncFParam());
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncFParams");
        return t;
    }

    private static Token FuncFParam() {
        Token t = new Token(Type.FuncFParam);
        t.setTree(BType());
        t.setTree(getToken());
        if (type() == Type.LBRACK) {
            t.setTree(getToken());
            if (type() != Type.RBRACK) {
                t.setTree(error('k'));
            } else {
                t.setTree(getToken());
            }
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncFParam");
        return t;
    }

    private static Token Block() {
        Token t = new Token(Type.Block);
        t.setTree(getToken());
        while (type() != Type.RBRACE) {
            t.setTree(BlockItem());
        }
        t.setTree(getToken());
        Lexer.print();
		fileOut1.printf("<%s>\n", "Block");
        return t;
    }

    private static Token BlockItem() {
        Token t = new Token(Type.BlockItem);
        if (type() == Type.CONSTTK || type() == Type.INTTK || type() == Type.CHARTK) {
            t.setTree(Decl());
        } else {
            t.setTree(Stmt());
        }
        return t;
    }

    private static Token Stmt() {
        Token t = new Token(Type.Stmt);
        if (type() == Type.LBRACE) {
            t.setTree(Block());
        } else if (type() == Type.IFTK) {
            t.setTree(getToken());
            t.setTree(getToken());
            t.setTree(Cond());
            if (type() != Type.RPARENT) {
                t.setTree(error('j'));
            } else {
                t.setTree(getToken());
            }
            t.setTree(Stmt());
            if (type() == Type.ELSETK) {
                t.setTree(getToken());
                t.setTree(Stmt());
            }
        } else if (type() == Type.FORTK) {
            t.setTree(getToken());
            t.setTree(getToken());
            if (type() != Type.SEMICN) {
                t.setTree(ForStmt());
            }
            t.setTree(getToken());
            if (type() != Type.SEMICN) {
                t.setTree(Cond());
            }
            t.setTree(getToken());
            if (type() != Type.RPARENT) {
                t.setTree(ForStmt());
            }
            t.setTree(getToken());
            t.setTree(Stmt());
        } else if (type() == Type.BREAKTK) {
            t.setTree(getToken());
            if (type() != Type.SEMICN) {
                t.setTree(error('i'));
            } else {
                t.setTree(getToken());
            }
        } else if (type() == Type.CONTINUETK) {
            t.setTree(getToken());
            if (type() != Type.SEMICN) {
                t.setTree(error('i'));
            } else {
                t.setTree(getToken());
            }
        } else if (type() == Type.RETURNTK) {
            t.setTree(getToken());
            if (type() == Type.PLUS || type() == Type.MINU || type() == Type.NOT ||
                    type() == Type.IDENFR || type() == Type.LPARENT || type() == Type.INTCON || type() == Type.CHRCON) {
                t.setTree(Exp());
            }
            if (type() != Type.SEMICN) {
                t.setTree(error('i'));
            } else {
                t.setTree(getToken());
            }
        } else if (type() == Type.PRINTFTK) {
            t.setTree(getToken());
            t.setTree(getToken());
            t.setTree(getToken());
            while (type() == Type.COMMA) {
                t.setTree(getToken());
                t.setTree(Exp());
            }
            if (type() != Type.RPARENT) {
                t.setTree(error('j'));
            } else {
                t.setTree(getToken());
            }
            if (type() != Type.SEMICN) {
                t.setTree(error('i'));
            } else {
                t.setTree(getToken());
            }
        } else if (type() == Type.PLUS || type() == Type.MINU || type() == Type.NOT ||
                (type() == Type.IDENFR && pre(false, 1) == Type.LPARENT) || type() == Type.LPARENT || type() == Type.INTCON || type() == Type.CHRCON) {
            //一部分[Exp]; 除去LVal开头的
            t.setTree(Exp());
            if (type() != Type.SEMICN) {
                t.setTree(error('i'));
            } else {
                t.setTree(getToken());
            }
        } else if (type() == Type.SEMICN) {
            t.setTree(getToken());
        } else {//LVal开头的
            if (PreParser.start().getType() != Type.ASSIGN) {
                t.setTree(Exp());
                if (type() != Type.SEMICN) {
                    t.setTree(error('i'));
                } else {
                    t.setTree(getToken());
                }
            } else {
                t.setTree(LVal());
                t.setTree(getToken());
                if (type() == Type.GETINTTK || type() == Type.GETCHARTK) {
                    t.setTree(getToken());
                    t.setTree(getToken());
                    if (type() != Type.RPARENT) {
                        t.setTree(error('j'));
                    } else {
                        t.setTree(getToken());
                    }
                    if (type() != Type.SEMICN) {
                        t.setTree(error('i'));
                    } else {
                        t.setTree(getToken());
                    }
                } else {
                    t.setTree(Exp());
                    if (type() != Type.SEMICN) {
                        t.setTree(error('i'));
                    } else {
                        t.setTree(getToken());
                    }
                }
            }
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "Stmt");
        return t;
    }

    private static Token Cond() {
        Token t = new Token(Type.Cond);
        t.setTree(LOrExp());
        Lexer.print();
		fileOut1.printf("<%s>\n", "Cond");
        return t;
    }

    private static Token ForStmt() {
        Token t = new Token(Type.ForStmt);
        t.setTree(LVal());
        t.setTree(getToken());
        t.setTree(Exp());
        Lexer.print();
		fileOut1.printf("<%s>\n", "ForStmt");
        return t;
    }

    private static Token LOrExp() {
        Token tmp = new Token(Type.LOrExp);
        Token t0;
        tmp.setTree(LAndExp());
        Lexer.print();
        fileOut1.printf("<%s>\n", "LOrExp");
        while (type() == Type.OR) {
            t0 = new Token(Type.LOrExp);
            t0.setTree(tmp);
            t0.setTree(getToken());
            t0.setTree(LAndExp());
            tmp = t0;
            Lexer.print();
            fileOut1.printf("<%s>\n", "LOrExp");
        }
        return tmp;
    }

    private static Token LAndExp() {
        Token tmp = new Token(Type.LAndExp);
        Token t0;
        tmp.setTree(EqExp());
        Lexer.print();
        fileOut1.printf("<%s>\n", "LAndExp");
        while (type() == Type.AND) {
            t0 = new Token(Type.LAndExp);
            t0.setTree(tmp);
            t0.setTree(getToken());
            t0.setTree(EqExp());
            tmp = t0;
            Lexer.print();
            fileOut1.printf("<%s>\n", "LAndExp");
        }
        return tmp;
    }

    private static Token EqExp() {
        Token tmp = new Token(Type.EqExp);
        Token t0;
        tmp.setTree(RelExp());
        Lexer.print();
        fileOut1.printf("<%s>\n", "EqExp");
        while (type() == Type.EQL || type() == Type.NEQ) {
            t0 = new Token(Type.EqExp);
            t0.setTree(tmp);
            t0.setTree(getToken());
            t0.setTree(RelExp());
            tmp = t0;
            Lexer.print();
            fileOut1.printf("<%s>\n", "EqExp");
        }
        return tmp;
    }

    private static Token RelExp() {
        Token tmp = new Token(Type.RelExp);
        Token t0;
        tmp.setTree(AddExp());
        Lexer.print();
        fileOut1.printf("<%s>\n", "RelExp");
        while (type() == Type.LSS || type() == Type.GRE || type() == Type.LEQ || type() == Type.GEQ) {
            t0 = new Token(Type.RelExp);
            t0.setTree(tmp);
            t0.setTree(getToken());
            t0.setTree(AddExp());
            tmp = t0;
            Lexer.print();
            fileOut1.printf("<%s>\n", "RelExp");
        }
        return tmp;
    }

    private static Token error(char c) {
        Token tmp = new Token();
        switch (c){
            case 'i':
                fileOut2.printf("%d %c\n", Lexer.getLine0(), 'i');
                tmp.append(';');
                tmp.enType(Type.SEMICN);
                break;
            case 'j':
                fileOut2.printf("%d %c\n", Lexer.getLine0(), 'j');
                tmp.append(')');
                tmp.enType(Type.RPARENT);
                break;
            case 'k':
                fileOut2.printf("%d %c\n", Lexer.getLine0(), 'k');
                tmp.append(']');
                tmp.enType(Type.RBRACK);
                break;
            default:
                break;
        }
        return tmp;
    }

    public static Parser getInstance() {
        return parser;
    }

    public static void setFile(PrintStream fileOut1, PrintStream fileOut2) {
        Parser.fileOut1 = fileOut1;
        Parser.fileOut2 = fileOut2;
    }

    private static Token getToken() {
        Token tmp = token;
        token = Lexer.getSym();
        return tmp;
    }

    private static Type pre(boolean isContinuous, int count) {
        Token t = new Token();
        if (!isContinuous) {
            t = PreLexer.getSym(false);
            while ((--count) > 0) {
                t = PreLexer.getSym(true);
            }
        } else {
            while ((--count) >= 0) {
                t = PreLexer.getSym(true);
            }
        }
        return t.getType();
    }

    private static Type type() {
        return token.getType();
    }
}

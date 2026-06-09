package frontend;

import java.io.PrintStream;

public class Parser {
    private static Parser parser = new Parser();
    private static PrintStream fileOut1;
    private static PrintStream fileOut2;
    private static Token token;

    public Parser() {

    }

    public static void start() {
        getToken();
        CompUnit();
    }

    private static void CompUnit() {
        while (type() == Type.CONSTTK ||
                ((type() == Type.CHARTK || type() == Type.INTTK) && pre(false, 2) != Type.LPARENT)) {
            Decl();
        }
        while ((type() == Type.CHARTK || type() == Type.VOIDTK) ||
                (type() == Type.INTTK && pre(false, 1) == Type.IDENFR)) {
            FuncDef();
        }
        MainFuncDef();
        Lexer.print();
		fileOut1.printf("<%s>\n", "CompUnit");
    }

    private static void Decl() {
        if (type() == Type.CONSTTK) {
            ConstDecl();
        } else {
            VarDecl();
        }
    }

    private static void FuncDef() {
        FuncType();
        getToken();
        getToken();
        if (type() == Type.INTTK || type() == Type.CHARTK) {
            FuncFParams();
        }
        if (type() != Type.RPARENT) {
            error('j');
        } else {
            getToken();
        }
        Block();
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncDef");
    }

    private static void MainFuncDef() {
        getToken();
        getToken();
        getToken();
        if (type() != Type.RPARENT) {
            error('j');
        } else {
            getToken();
        }
        Block();
        Lexer.print();
		fileOut1.printf("<%s>\n", "MainFuncDef");
    }

    private static void ConstDecl() {
        getToken(); //const
        BType();
        ConstDef();
        while (type() == Type.COMMA) {
            getToken();
            ConstDef();
        }
        if (type() != Type.SEMICN) {
            error('i');
        } else {
            getToken();
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "ConstDecl");
    }

    private static void VarDecl() {
        BType();
        VarDef();
        while (type() == Type.COMMA) {
            getToken();
            VarDef();
        }
        if (type() != Type.SEMICN) {
            error('i');
        } else {
            getToken();
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "VarDecl");
    }

    private static void BType() {
        getToken();
    }

    private static void ConstDef() {
        getToken();
        if (type() == Type.LBRACK) {
            getToken();
            ConstExp();
            if (type() != Type.RBRACK) {
                error('k');
            } else {
                getToken();
            }
        }
        getToken();
        ConstInitVal();
        Lexer.print();
		fileOut1.printf("<%s>\n", "ConstDef");
    }

    private static void ConstExp() {
        AddExp();
        Lexer.print();
		fileOut1.printf("<%s>\n", "ConstExp");
    }

    private static void ConstInitVal() {
        if (type() == Type.LBRACE) {
            getToken();
            if (type() != Type.RBRACE) {
                ConstExp();
                while (type() == Type.COMMA) {
                    getToken();
                    ConstExp();
                }
            }
            getToken();
        } else if (type() == Type.STRCON) {
            getToken();
        } else {
            ConstExp();
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "ConstInitVal");
    }

    private static void AddExp() {
        MulExp();
        Lexer.print();
        fileOut1.printf("<%s>\n", "AddExp");
        while (type() == Type.PLUS || type() == Type.MINU) {
            getToken();
            MulExp();
            Lexer.print();
            fileOut1.printf("<%s>\n", "AddExp");
        }
    }

    private static void MulExp() {
        UnaryExp();
        Lexer.print();
        fileOut1.printf("<%s>\n", "MulExp");
        while (type() == Type.MULT || type() == Type.DIV || type() == Type.MOD) {
            getToken();
            UnaryExp();
            Lexer.print();
            fileOut1.printf("<%s>\n", "MulExp");
        }
    }

    private static void UnaryExp() {
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
    }

    private static void UnaryOp() {
        getToken();
        Lexer.print();
		fileOut1.printf("<%s>\n", "UnaryOp");
    }

    private static void FuncRParams() {
        Exp();
        while (type() == Type.COMMA) {
            getToken();
            Exp();
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncRParams");
    }

    private static void PrimaryExp() {
        if (type() == Type.LPARENT) {
            getToken();
            Exp();
            if (type() != Type.RPARENT) {
                error('j');
            } else {
                getToken();
            }
        } else if (type() == Type.IDENFR) {
            LVal();
        } else if (type() == Type.INTCON) {
            Number();
        } else {
            Character();
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "PrimaryExp");
    }

    private static void Exp() {
        AddExp();
        Lexer.print();
		fileOut1.printf("<%s>\n", "Exp");
    }

    private static void LVal() {
        getToken();
        if (type() == Type.LBRACK) {
            getToken();
            Exp();
            if (type() != Type.RBRACK) {
                error('k');
            } else {
                getToken();
            }
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "LVal");
    }

    private static void Number() {
        getToken();
        Lexer.print();
		fileOut1.printf("<%s>\n", "Number");
    }

    private static void Character() {
        getToken();
        Lexer.print();
		fileOut1.printf("<%s>\n", "Character");
    }

    private static void VarDef() {
        getToken();
        if (type() == Type.LBRACK) {
            getToken();
            ConstExp();
            if (type() != Type.RBRACK) {
                error('k');
            } else {
                getToken();
            }
        }
        if (type() == Type.ASSIGN) {
            getToken();
            InitVal();
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "VarDef");
    }

    private static void InitVal() {
        if (type() == Type.LBRACE) {
            getToken();
            if (type() != Type.RBRACE) {
                Exp();
                while (type() == Type.COMMA) {
                    getToken();
                    Exp();
                }
            }
            getToken();
        } else if (type() == Type.STRCON) {
            getToken();
        } else {
            Exp();
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "InitVal");
    }

    private static void FuncType() {
        getToken();
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncType");
    }

    private static void FuncFParams() {
        FuncFParam();
        while (type() == Type.COMMA) {
            getToken();
            FuncFParam();
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncFParams");
    }

    private static void FuncFParam() {
        BType();
        getToken();
        if (type() == Type.LBRACK) {
            getToken();
            if (type() != Type.RBRACK) {
                error('k');
            } else {
                getToken();
            }
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "FuncFParam");
    }

    private static void Block() {
        getToken();
        while (type() != Type.RBRACE) {
            BlockItem();
        }
        getToken();
        Lexer.print();
		fileOut1.printf("<%s>\n", "Block");
    }

    private static void BlockItem() {
        if (type() == Type.CONSTTK || type() == Type.INTTK || type() == Type.CHARTK) {
            Decl();
        } else {
            Stmt();
        }
    }

    private static void Stmt() {
        if (type() == Type.LBRACE) {
            Block();
        } else if (type() == Type.IFTK) {
            getToken();
            getToken();
            Cond();
            if (type() != Type.RPARENT) {
                error('j');
            } else {
                getToken();
            }
            Stmt();
            if (type() == Type.ELSETK) {
                getToken();
                Stmt();
            }
        } else if (type() == Type.FORTK) {
            getToken();
            getToken();
            if (type() != Type.SEMICN) {
                ForStmt();
            }
            getToken();
            if (type() != Type.SEMICN) {
                Cond();
            }
            getToken();
            if (type() != Type.RPARENT) {
                ForStmt();
            }
            getToken();
            Stmt();
        } else if (type() == Type.BREAKTK) {
            getToken();
            if (type() != Type.SEMICN) {
                error('i');
            } else {
                getToken();
            }
        } else if (type() == Type.CONTINUETK) {
            getToken();
            if (type() != Type.SEMICN) {
                error('i');
            } else {
                getToken();
            }
        } else if (type() == Type.RETURNTK) {
            getToken();
            if (type() == Type.PLUS || type() == Type.MINU || type() == Type.NOT ||
                    type() == Type.IDENFR || type() == Type.LPARENT || type() == Type.INTCON || type() == Type.CHRCON) {
                Exp();
            }
            if (type() != Type.SEMICN) {
                error('i');
            } else {
                getToken();
            }
        } else if (type() == Type.PRINTFTK) {
            getToken();
            getToken();
            getToken();
            while (type() == Type.COMMA) {
                getToken();
                Exp();
            }
            if (type() != Type.RPARENT) {
                error('j');
            } else {
                getToken();
            }
            if (type() != Type.SEMICN) {
                error('i');
            } else {
                getToken();
            }
        } else if (type() == Type.PLUS || type() == Type.MINU || type() == Type.NOT ||
                (type() == Type.IDENFR && pre(false, 1) == Type.LPARENT) || type() == Type.LPARENT || type() == Type.INTCON || type() == Type.CHRCON) {
            //一部分[Exp]; 除去LVal开头的
            Exp();
            if (type() != Type.SEMICN) {
                error('i');
            } else {
                getToken();
            }
        } else if (type() == Type.SEMICN) {
            getToken();
        } else {//LVal开头的
            if (PreParser.start().getType() != Type.ASSIGN) {
                Exp();
                if (type() != Type.SEMICN) {
                    error('i');
                } else {
                    getToken();
                }
            } else {
                LVal();
                getToken();
                if (type() == Type.GETINTTK || type() == Type.GETCHARTK) {
                    getToken();
                    getToken();
                    if (type() != Type.RPARENT) {
                        error('j');
                    } else {
                        getToken();
                    }
                    if (type() != Type.SEMICN) {
                        error('i');
                    } else {
                        getToken();
                    }
                } else {
                    Exp();
                    if (type() != Type.SEMICN) {
                        error('i');
                    } else {
                        getToken();
                    }
                }
            }
        }
        Lexer.print();
		fileOut1.printf("<%s>\n", "Stmt");
    }

    private static void Cond() {
        LOrExp();
        Lexer.print();
		fileOut1.printf("<%s>\n", "Cond");
    }

    private static void ForStmt() {
        LVal();
        getToken();
        Exp();
        Lexer.print();
		fileOut1.printf("<%s>\n", "ForStmt");
    }

    private static void LOrExp() {
        LAndExp();
        Lexer.print();
        fileOut1.printf("<%s>\n", "LOrExp");
        while (type() == Type.OR) {
            getToken();
            LAndExp();
            Lexer.print();
            fileOut1.printf("<%s>\n", "LOrExp");
        }
    }

    private static void LAndExp() {
        EqExp();
        Lexer.print();
        fileOut1.printf("<%s>\n", "LAndExp");
        while (type() == Type.AND) {
            getToken();
            EqExp();
            Lexer.print();
            fileOut1.printf("<%s>\n", "LAndExp");
        }
    }

    private static void EqExp() {
        RelExp();
        Lexer.print();
        fileOut1.printf("<%s>\n", "EqExp");
        while (type() == Type.EQL || type() == Type.NEQ) {
            getToken();
            RelExp();
            Lexer.print();
            fileOut1.printf("<%s>\n", "EqExp");
        }
    }

    private static void RelExp() {
        AddExp();
        Lexer.print();
        fileOut1.printf("<%s>\n", "RelExp");
        while (type() == Type.LSS || type() == Type.GRE || type() == Type.LEQ || type() == Type.GEQ) {
            getToken();
            AddExp();
            Lexer.print();
            fileOut1.printf("<%s>\n", "RelExp");
        }
    }

    private static void error(char c) {
        switch (c){
            case 'i':
                fileOut2.printf("%d %c\n", Lexer.getLine(), 'i');
                break;
            case 'j':
                fileOut2.printf("%d %c\n", Lexer.getLine(), 'j');
                break;
            case 'k':
                fileOut2.printf("%d %c\n", Lexer.getLine(), 'k');
                break;
            default:
                break;
        }
    }

    public static Parser getInstance() {
        return parser;
    }

    public static void setFile(PrintStream fileOut1, PrintStream fileOut2) {
        Parser.fileOut1 = fileOut1;
        Parser.fileOut2 = fileOut2;
    }

    private static void getToken() {
        token = Lexer.getSym();
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

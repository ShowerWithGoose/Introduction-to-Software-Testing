package frontend;

import AST.*;
import AST.Cha;

import java.util.ArrayList;
import java.util.TreeMap;

public class Parser {
    private Lexer lexer;
    private StringBuilder out = new StringBuilder();
    private boolean Err = false;
    private TreeMap<Integer, ArrayList<MyError>> errors;
    private CompUnit compUnit = null;

    private int arg = 0;    //语法分析输出打开

    public Parser(Lexer lexer, int arg, TreeMap<Integer, ArrayList<MyError>> errors) {
        this.lexer = lexer;
        this.arg = arg;
        this.errors = errors;
        compUnit = parseCompUnit();
    }

    public void printTk(Token token) {
        if (arg == 0) {
            out.append(token.getType()).append(" ").append(token.getName()).append("\n");
        } else {
            return;
        }
    }

    public void print(String str) {
        if (arg == 0) {
            out.append(str);
        } else {
            return;
        }
    }

    public CompUnit parseCompUnit() {
        ArrayList<Decl> decls = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        MainFuncDef mainfuncDef = null;
        while (lexer.notEnd()) {
            Token token = lexer.now();

            if (token.getName().equals("const")) {
                decls.add(parseDecl());
            } else if (token.getName().equals("int") || token.getName().equals("char")) {
                if (lexer.getToken(1).getName().equals("main")) {
                    mainfuncDef = parseMainFuncDef();
                } else if (lexer.getToken(2).getName().equals("(")) {
                    funcDefs.add(parseFuncDef());
                } else {
                    decls.add(parseDecl());
                }
            } else {
                funcDefs.add(parseFuncDef());
            }
        }

        print("<CompUnit>\n");
        return new CompUnit(decls, funcDefs, mainfuncDef);
    }

    public Decl parseDecl() {
        Token token = lexer.now();

        ConstDecl constDecl = null;
        VarDecl varDecl = null;
        if (token.getName().equals("const")) {
            constDecl = parseConstDecl();
        } else if (token.getName().equals("int") || token.getName().equals("char")) {
            varDecl = parseVarDecl();
        } else {
            //ERR;
        }

//        print("<Decl>\n");

        return new Decl(constDecl, varDecl);
    }

    public boolean isBType(BType bType) {
        return bType.getType().equals("int") || bType.getType().equals("char");
    }

    public ConstDecl parseConstDecl() {
        Token token = lexer.now();
        printTk(token);

        lexer.next();
        token = lexer.now();

        BType bType = parseBType();

        ArrayList<ConstDef> constDefs = new ArrayList<>();

        if (lexer.notEnd()) {
            constDefs.add(parseConstDef());
        } else {
            //    Err;
        }

        while (lexer.notEnd() && lexer.now().getName().equals(",")) {
            token = lexer.now();
            printTk(token);

            lexer.next();
            if (lexer.notEnd()) {
                constDefs.add(parseConstDef());
            }
        }
        if (lexer.now().getName().equals(";")) {
            token = lexer.now();
            printTk(token);
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        print("<ConstDecl>\n");

        return new ConstDecl(bType, constDefs);
    }

    public BType parseBType() {
        Token token = lexer.now();
        printTk(token);

        BType bType = new BType(lexer.now().getName());
        if (isBType(bType)) {
            lexer.next();
        } else {
            //ERR;
        }


        return bType;
    }

    private ConstDef parseConstDef() {
        Ident ident = null;
        ConstExp constExp = null;
        ConstInitVal constInitVal = null;

        Token token = lexer.now();
        if (lexer.notEnd()) {
            printTk(token);
            ident = new Ident(lexer.now().getName());
            lexer.next();
        }

        if (lexer.notEnd() && lexer.now().getName().equals("[")) {
            token = lexer.now();
            printTk(token);

            lexer.next();
            constExp = parseConstExp();
            if (lexer.now().getName().equals("]")) {
                token = lexer.now();
                printTk(token);
                lexer.next();
            } else {
                Err = true;
                if (errors.containsKey(lexer.getToken(-1).getLine())) {
                    //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("k", lexer.getToken(-1).getLine()));
                } else {
                    ArrayList<MyError> list = new ArrayList<>();
                    list.add(new MyError("k", lexer.getToken(-1).getLine()));
                    errors.put(lexer.getToken(-1).getLine(), list);
                }
            }

        }

        if (lexer.notEnd() && lexer.now().getName().equals("=")) {
            token = lexer.now();
            printTk(token);

            lexer.next();
            constInitVal = parseConstInitVal();
        } else {
            //Err;
        }

        print("<ConstDef>\n");
        return new ConstDef(ident, constExp, constInitVal);
    }

    public StringConst parseStringConst() {
        Token token = lexer.now();
        printTk(token);

        StringConst stringConst = new StringConst(lexer.now().getName());
        lexer.next();

        return stringConst;
    }

    private ConstInitVal parseConstInitVal() {
        ConstExp constExp = null;
        ArrayList<ConstExp> constExps = new ArrayList<>();
        StringConst stringConst = null;

        if (lexer.notEnd() && lexer.now().getName().equals("{")) {
            printTk(lexer.now());

            lexer.next();

            while (lexer.notEnd() && !lexer.now().getName().equals("}")) {
                constExps.add(parseConstExp());

                if (lexer.notEnd() && lexer.now().getName().equals(",")) {
                    printTk(lexer.now());
                    lexer.next();
                }
            }
            printTk(lexer.now());
            lexer.next();

        } else if (lexer.notEnd() && lexer.now().getType().equals(Type.STRCON)) {
            stringConst = parseStringConst();
        } else {
            constExp = parseConstExp();
        }

        print("<ConstInitVal>\n");

        return new ConstInitVal(constExps, constExp, stringConst);
    }

    private VarDecl parseVarDecl() {
        BType bType;
        ArrayList<VarDef> varDefs = new ArrayList<>();

        bType = parseBType();

        //lexer.next();


        if (lexer.notEnd()) {
            varDefs.add(parseVarDef());
        }

        while (lexer.notEnd() && lexer.now().getName().equals(",")) {
            printTk(lexer.now());

            lexer.next();
            if (lexer.notEnd()) {
                varDefs.add(parseVarDef());
            }
        }
        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }


        print("<VarDecl>\n");
        return new VarDecl(bType, varDefs);
    }

    private VarDef parseVarDef() {
        Ident ident = null;
        ConstExp constExp = null;
        InitVal initVal = null;

        if (lexer.notEnd()) {
            ident = new Ident(lexer.now().getName());
            printTk(lexer.now());

            lexer.next();
        }
        if (lexer.notEnd() && lexer.now().getName().equals("[")) {
            printTk(lexer.now());

            lexer.next();
            constExp = parseConstExp();

            if (lexer.now().getName().equals("]")) {
                printTk(lexer.now());

                lexer.next();
            } else {
                Err = true;
                if (errors.containsKey(lexer.getToken(-1).getLine())) {
                    //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("k", lexer.getToken(-1).getLine()));
                } else {
                    ArrayList<MyError> list = new ArrayList<>();
                    list.add(new MyError("k", lexer.getToken(-1).getLine()));
                    errors.put(lexer.getToken(-1).getLine(), list);
                }
            }
        }

        if (lexer.notEnd() && lexer.now().getName().equals("=")) {
            printTk(lexer.now());

            lexer.next();
            initVal = parseInitVal();
        }
        print("<VarDef>\n");

        return new VarDef(ident, constExp, initVal);
    }

    private InitVal parseInitVal() {
        ArrayList<Exp> exps = new ArrayList<>();
        Exp exp = null;
        StringConst stringConst = null;

        if (lexer.notEnd() && lexer.now().getName().equals("{")) {
            printTk(lexer.now());

            lexer.next();
            while (lexer.notEnd() && !lexer.now().getName().equals("}")) {
                exps.add(parseExp());
                if (lexer.notEnd() && lexer.now().getName().equals(",")) {
                    printTk(lexer.now());
                    lexer.next();
                }
            }
            printTk(lexer.now());
            lexer.next();
        } else if (lexer.notEnd() && lexer.now().getType().equals(Type.STRCON)) {
            stringConst = parseStringConst();
        } else {
            exp = parseExp();
        }

        print("<InitVal>\n");

        return new InitVal(exp, exps, stringConst);
    }

    public FuncDef parseFuncDef() {
        FuncType funcType = null;
        Ident ident = null;
        FuncFParams funcFParams = null;
        Block block = null;

        if (lexer.notEnd()) {
            funcType = parseFuncType();
        }

        if (lexer.notEnd()) {
            ident = new Ident(lexer.now().getName());
            printTk(lexer.now());

            lexer.next();
        }

        if (lexer.notEnd() && lexer.now().getName().equals("(")) {
            printTk(lexer.now());

            lexer.next();
            if (lexer.notEnd() && lexer.now().getName().equals(")")) {
                printTk(lexer.now());
                lexer.next();
            } else if (lexer.notEnd() &&
                    (lexer.now().getName().equals("int")
                            || lexer.now().getName().equals("char"))) {
                funcFParams = parseFuncFParams();
                if (lexer.notEnd() && lexer.now().getName().equals(")")) {
                    printTk(lexer.now());
                    lexer.next();
                } else {
                    Err = true;
                    if (errors.containsKey(lexer.getToken(-1).getLine())) {
                        //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
                    } else {
                        ArrayList<MyError> list = new ArrayList<>();
                        list.add(new MyError("j", lexer.getToken(-1).getLine()));
                        errors.put(lexer.getToken(-1).getLine(), list);
                    }
                }
            } else {
                Err = true;
                if (errors.containsKey(lexer.getToken(-1).getLine())) {
                    //   errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
                } else {
                    ArrayList<MyError> list = new ArrayList<>();
                    list.add(new MyError("j", lexer.getToken(-1).getLine()));
                    errors.put(lexer.getToken(-1).getLine(), list);
                }
            }
        }

        if (lexer.notEnd()) {
            block = parseBlock();
        }

        print("<FuncDef>\n");
        return new FuncDef(funcType, ident, funcFParams, block);
    }


    private MainFuncDef parseMainFuncDef() {
        Block block = null;

        if (lexer.notEnd() && lexer.now().getName().equals("int")) {
            printTk(lexer.now());
            lexer.next();
        }
        if (lexer.notEnd() && lexer.now().getName().equals("main")) {
            printTk(lexer.now());
            lexer.next();
        }
        if (lexer.notEnd() && lexer.now().getName().equals("(")) {
            printTk(lexer.now());
            lexer.next();
        }
        if (lexer.notEnd() && lexer.now().getName().equals(")")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("j", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }
        if (lexer.notEnd()) {
            block = parseBlock();
        }
        print("<MainFuncDef>\n");
        return new MainFuncDef(block);
    }

    public boolean isFuncType(FuncType funcType) {
        return funcType.getType().equals("int") || funcType.getType().equals("char") || funcType.getType().equals("void");
    }

    public FuncType parseFuncType() {

        Token token = lexer.now();
        printTk(token);

        FuncType funcType = new FuncType(lexer.now().getName());
        if (isFuncType(funcType)) {
            lexer.next();
        } else {
            //ERR;
        }
        print("<FuncType>\n");
        return funcType;
    }

    private FuncFParams parseFuncFParams() {
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        FuncFParam funcFParam = null;

        if (lexer.notEnd()) {
            funcFParam = parseFuncFParam();
            funcFParams.add(funcFParam);
        }

        while (lexer.notEnd() && lexer.now().getName().equals(",")) {
            printTk(lexer.now());

            lexer.next();
            if (lexer.notEnd()) {
                funcFParam = parseFuncFParam();
                funcFParams.add(funcFParam);
            }
        }

        print("<FuncFParams>\n");

        return new FuncFParams(funcFParams);
    }

    private FuncFParam parseFuncFParam() {
        BType bType = null;
        Ident ident = null;
        boolean isArray = false;

        if (lexer.notEnd()) {
            bType = parseBType();
        }

        if (lexer.notEnd()) {
            ident = new Ident(lexer.now().getName());
            printTk(lexer.now());

            lexer.next();
        }

        if (lexer.notEnd() && lexer.now().getName().equals("[")) {
            printTk(lexer.now());

            isArray = true;
            lexer.next();
            if (lexer.notEnd() && lexer.now().getName().equals("]")) {
                printTk(lexer.now());

                lexer.next();
            } else {
                Err = true;
                if (errors.containsKey(lexer.getToken(-1).getLine())) {
                    //   errors.get(lexer.getToken(-1).getLine()).add(new MyError("k", lexer.getToken(-1).getLine()));
                } else {
                    ArrayList<MyError> list = new ArrayList<>();
                    list.add(new MyError("k", lexer.getToken(-1).getLine()));
                    errors.put(lexer.getToken(-1).getLine(), list);
                }
            }
        }

        print("<FuncFParam>\n");

        return new FuncFParam(bType, ident, isArray);
    }

    private Block parseBlock() {
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        if (lexer.notEnd() && lexer.now().getName().equals("{")) {
            printTk(lexer.now());

            lexer.next();
        } else {
            //ERR;
        }

        if (lexer.notEnd() && lexer.now().getName().equals("}")) {
            printTk(lexer.now());

            lexer.next();
        } else {
            while (lexer.notEnd() && !lexer.now().getName().equals("}")) {
                blockItems.add(parseBlockItem());
            }
            if (lexer.notEnd() && lexer.now().getName().equals("}")) {
                printTk(lexer.now());

                lexer.next();
            } else {
                //ERR;
            }

        }

        print("<Block>\n");

        return new Block(blockItems);
    }

    private BlockItem parseBlockItem() {
        Decl decl = null;
        Stmt stmt = null;
        if (lexer.notEnd() && (lexer.now().getName().equals("const") || lexer.now().getName().equals("int") || lexer.now().getName().equals("char"))) {
            decl = parseDecl();
        } else {
            stmt = parseStmt();
        }

//        print("<BlockItem>\n");
        return new BlockItem(decl, stmt);
    }

    private Stmt parseStmt() {
        int type;

        if (lexer.notEnd() && lexer.now().getName().equals("if")) {
            type = 4;
            Stmt stmt = parseIfStmt(type);
            print("<Stmt>\n");
            return stmt;
        } else if (lexer.notEnd() && lexer.now().getName().equals("for")) {
            type = 5;
            Stmt stmt = parseFor(type);
            print("<Stmt>\n");
            return stmt;
        } else if (lexer.notEnd() && lexer.now().getName().equals("break")) {
            type = 6;
            Stmt stmt = parseBreakStmt(type);
            print("<Stmt>\n");
            return stmt;
        } else if (lexer.notEnd() && lexer.now().getName().equals("continue")) {
            type = 7;
            Stmt stmt = parseContinueStmt(type);
            print("<Stmt>\n");
            return stmt;
        } else if (lexer.notEnd() && lexer.now().getName().equals("return")) {
            type = 8;
            Stmt stmt = parseReturnStmt(type);
            print("<Stmt>\n");
            return stmt;
        } else if (lexer.notEnd() && lexer.now().getName().equals("printf")) {
            type = 11;
            Stmt stmt = parsePrintfStmt(type);
            print("<Stmt>\n");
            return stmt;
        } else if (lexer.notEnd() && lexer.now().getName().equals("{")) {
            type = 3;
            Block block = parseBlock();
            print("<Stmt>\n");
            return new Stmt(type, block);
        } else {
            int idx = 0;
            if (!lexer.now().getType().equals(Type.IDENFR)) {
                type = 2;
                Stmt stmt = parseExpStmt(type);
                print("<Stmt>\n");
                return stmt;
            }
            while (!lexer.getToken(idx).getName().equals(";")) {
                if (lexer.getToken(idx).getName().equals("=")) {
                    if (lexer.getToken(idx + 1).getName().equals("getint")) {
                        type = 9;
                        Stmt stmt = parseGetint(type);
                        print("<Stmt>\n");
                        return stmt;
                    } else if (lexer.getToken(idx + 1).getName().equals("getchar")) {
                        type = 10;
                        Stmt stmt = parseGetchar(type);
                        print("<Stmt>\n");
                        return stmt;
                    } else {
                        type = 1;
                        Stmt stmt = parseLValExpStmt(type);
                        print("<Stmt>\n");
                        return stmt;
                    }
                }
                if (lexer.getToken(idx).getLine() != lexer.getToken(idx + 1).getLine()) {
                    type = 2;
                    Stmt stmt = parseExpStmt(type);
                    print("<Stmt>\n");
                    return stmt;
                }
                idx++;
            }
            type = 2;
            Stmt stmt = parseExpStmt(type);
            print("<Stmt>\n");
            return stmt;
        }


    }

    public Stmt parseExpStmt(int type) {
        Exp exp = null;
        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else if (lexer.notEnd() && ("+-!".contains(lexer.now().getName()) || lexer.now().getName().equals("(")
                || lexer.now().getType().equals(Type.INTCON) || lexer.now().getType().equals(Type.CHRCON) || lexer.now().getType().equals(Type.IDENFR))) {
            exp = parseExp();
            if (lexer.notEnd() && lexer.now().getName().equals(";")) {
                printTk(lexer.now());
                lexer.next();
            } else {
                Err = true;
                if (errors.containsKey(lexer.getToken(-1).getLine())) {
                    //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
                } else {
                    ArrayList<MyError> list = new ArrayList<>();
                    list.add(new MyError("i", lexer.getToken(-1).getLine()));
                    errors.put(lexer.getToken(-1).getLine(), list);
                }
            }
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        return new Stmt(type, exp);
    }

    public Stmt parseLValExpStmt(int type) {
        LVal lVal = null;
        Exp exp = null;
        lVal = parseLVal();
        if (lexer.notEnd() && lexer.now().getName().equals("=")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        exp = parseExp();
        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        return new Stmt(type, lVal, exp);
    }

    public Stmt parseGetint(int type) {
        LVal lVal = null;
        if (lexer.notEnd()) {
            lVal = parseLVal();
        }
        if (lexer.notEnd() && lexer.now().getName().equals("=")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        if (lexer.notEnd() && lexer.now().getName().equals("getint")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        if (lexer.notEnd() && lexer.now().getName().equals("(")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        if (lexer.notEnd() && lexer.now().getName().equals(")")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("j", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        return new Stmt(type, lVal);
    }

    public Stmt parseGetchar(int type) {
        LVal lVal = null;
        if (lexer.notEnd()) {
            lVal = parseLVal();
        }
        if (lexer.notEnd() && lexer.now().getName().equals("=")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            ////Err;
        }

        if (lexer.notEnd() && lexer.now().getName().equals("getchar")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        if (lexer.notEnd() && lexer.now().getName().equals("(")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        if (lexer.notEnd() && lexer.now().getName().equals(")")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //   errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("j", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        return new Stmt(type, lVal);
    }


    private Stmt parsePrintfStmt(int type) {
        if (lexer.notEnd() && lexer.now().getName().equals("printf")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        if (lexer.notEnd() && lexer.now().getName().equals("(")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }
        StringConst stringConst = null;

        stringConst = parseStringConst();


        ArrayList<Exp> exps = new ArrayList<>();

        while (lexer.notEnd() && lexer.now().getName().equals(",")) {
            printTk(lexer.now());
            lexer.next();
            exps.add(parseExp());
        }

        if (lexer.notEnd() && lexer.now().getName().equals(")")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("j", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }
        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        return new Stmt(type, stringConst, exps);
    }


    private Stmt parseReturnStmt(int type) {
        if (lexer.notEnd() && lexer.now().getName().equals("return")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        Exp exp = null;
        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else if (lexer.notEnd() && ("+-!".contains(lexer.now().getName()) || lexer.now().getName().equals("(")
                || lexer.now().getType().equals(Type.INTCON) || lexer.now().getType().equals(Type.CHRCON) || lexer.now().getType().equals(Type.IDENFR))) {
            exp = parseExp();
            if (lexer.notEnd() && lexer.now().getName().equals(";")) {
                printTk(lexer.now());
                lexer.next();
            } else {
                Err = true;
                if (errors.containsKey(lexer.getToken(-1).getLine())) {
                    //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
                } else {
                    ArrayList<MyError> list = new ArrayList<>();
                    list.add(new MyError("i", lexer.getToken(-1).getLine()));
                    errors.put(lexer.getToken(-1).getLine(), list);
                }
            }
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        return new Stmt(type, exp);
    }

    private Stmt parseContinueStmt(int type) {
        if (lexer.notEnd() && lexer.now().getName().equals("continue")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }
        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }
        return new Stmt(type);
    }

    private Stmt parseBreakStmt(int type) {
        if (lexer.notEnd() && lexer.now().getName().equals("break")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }
        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("i", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("i", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }
        return new Stmt(type);
    }

    private Stmt parseFor(int type) {
        ForStmt forStmt1 = null;
        Cond cond = null;
        ForStmt forStmt2 = null;
        Stmt stmt = null;

        if (lexer.notEnd() && lexer.now().getName().equals("for")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }
        if (lexer.notEnd() && lexer.now().getName().equals("(")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }
        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            forStmt1 = parseForStmt();
            printTk(lexer.now());
            lexer.next();
        }
        if (lexer.notEnd() && lexer.now().getName().equals(";")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            cond = parseCond();
            printTk(lexer.now());
            lexer.next();
        }
        if (lexer.notEnd() && lexer.now().getName().equals(")")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            forStmt2 = parseForStmt();
            printTk(lexer.now());
            lexer.next();
        }
        stmt = parseStmt();
        return new Stmt(type, forStmt1, cond, forStmt2, stmt);
    }

    private ForStmt parseForStmt() {
        LVal lVal = null;
        Exp exp = null;
        lVal = parseLVal();
        if (lexer.notEnd() && lexer.now().getName().equals("=")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }
        exp = parseExp();

        print("<ForStmt>\n");
        return new ForStmt(lVal, exp);
    }

    private Stmt parseIfStmt(int type) {
        Cond cond = null;
        Stmt thenStmt = null;
        Stmt elseStmt = null;

        if (lexer.notEnd() && lexer.now().getName().equals("if")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        if (lexer.notEnd() && lexer.now().getName().equals("(")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            //Err;
        }

        cond = parseCond();

        if (lexer.notEnd() && lexer.now().getName().equals(")")) {
            printTk(lexer.now());
            lexer.next();
        } else {
            Err = true;
            if (errors.containsKey(lexer.getToken(-1).getLine())) {
                //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
            } else {
                ArrayList<MyError> list = new ArrayList<>();
                list.add(new MyError("j", lexer.getToken(-1).getLine()));
                errors.put(lexer.getToken(-1).getLine(), list);
            }
        }

        thenStmt = parseStmt();
        if (lexer.notEnd() && lexer.now().getName().equals("else")) {
            printTk(lexer.now());
            lexer.next();
            elseStmt = parseStmt();
            //lexer.next();
        }

        return new Stmt(type, cond, thenStmt, elseStmt);

    }

    public Exp parseExp() {
        AddExp addExp = parseAddExp();

        print("<Exp>\n");
        return new Exp(addExp);
    }

    private Cond parseCond() {
        LOrExp lOrExp = parseLOrExp();

        print("<Cond>\n");
        return new Cond(lOrExp);
    }

    public LVal parseLVal() {
        Token token = lexer.now();
        printTk(token);

        Ident ident = new Ident(lexer.now().getName());
        lexer.next();

        Exp exp = null;
        if (lexer.notEnd() && lexer.now().getName().equals("[")) {
            token = lexer.now();
            printTk(token);

            lexer.next();
            exp = parseExp();
            if (lexer.now().getName().equals("]")) {
                token = lexer.now();
                printTk(token);
                lexer.next();
            } else {
                Err = true;
                if (errors.containsKey(lexer.getToken(-1).getLine())) {
                    //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("k", lexer.getToken(-1).getLine()));
                } else {
                    ArrayList<MyError> list = new ArrayList<>();
                    list.add(new MyError("k", lexer.getToken(-1).getLine()));
                    errors.put(lexer.getToken(-1).getLine(), list);
                }
            }
        }


        print("<LVal>\n");

        return new LVal(ident, exp);
    }

    public PrimaryExp parsePrimaryExp() {
        if (lexer.notEnd() && lexer.now().getName().equals("(")) {
            printTk(lexer.now());
            lexer.next();
            Exp exp = parseExp();
            if (lexer.now().getName().equals(")")) {
                printTk(lexer.now());
                lexer.next();
            } else {
                Err = true;
                if (errors.containsKey(lexer.getToken(-1).getLine())) {
                    //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
                } else {
                    ArrayList<MyError> list = new ArrayList<>();
                    list.add(new MyError("j", lexer.getToken(-1).getLine()));
                    errors.put(lexer.getToken(-1).getLine(), list);
                }
            }
            print("<PrimaryExp>\n");
            return new PrimaryExp(exp);
        }
        if (lexer.notEnd() && lexer.now().getType().toString().equals("INTCON")) {
            Num num = parseNumber();
            print("<PrimaryExp>\n");
            return new PrimaryExp(num);
        }
        if (lexer.notEnd() && lexer.now().getType().toString().equals("CHRCON")) {
            Cha character = parseCharacter();
            print("<PrimaryExp>\n");
            return new PrimaryExp(character);
        }
        LVal lVal = parseLVal();
        print("<PrimaryExp>\n");
        return new PrimaryExp(lVal);

    }

    public Num parseNumber() {
        Token token = lexer.now();
        printTk(token);
        Num num = new Num(Long.getLong(token.getName()));
        lexer.next();
        print("<Number>\n");
        return num;
    }

    public Cha parseCharacter() {
        Token token = lexer.now();
        printTk(token);
        Cha character = new Cha(token.getName());
        lexer.next();
        print("<Character>\n");
        return character;
    }

    public UnaryExp parseUnaryExp() {
        if (lexer.notEnd() && "+-!".contains(lexer.now().getName())) {
            UnaryOp unaryOp = parseUnaryOp();
            UnaryExp unaryExp = parseUnaryExp();
            print("<UnaryExp>\n");
            return new UnaryExp(unaryOp, unaryExp);
        }
        if (lexer.notEnd() && (lexer.now().getName().equals("(")
                || lexer.now().getType().toString().equals("INTCON")
                || lexer.now().getType().toString().equals("CHRCON"))) {
            PrimaryExp primaryExp = parsePrimaryExp();
            print("<UnaryExp>\n");
            return new UnaryExp(primaryExp);
        }
        if (lexer.notEnd() && lexer.now().getType().equals(Type.IDENFR) && lexer.getToken(1).getName().equals("(")) {
            Ident ident = new Ident(lexer.now().getName());
            printTk(lexer.now());
            lexer.next();
            if (lexer.now().getName().equals("(")) {
                printTk(lexer.now());
                lexer.next();
            } else {
                //Err;
            }
            FuncRParams funcRParams = null;
            if (lexer.now().getName().equals(")")) {
                printTk(lexer.now());
                lexer.next();
            } else if (lexer.notEnd() && ("+-!".contains(lexer.now().getName())
                    || lexer.now().getName().equals("(")
                    || lexer.now().getType().equals(Type.IDENFR)
                    || lexer.now().getType().equals(Type.INTCON)
                    || lexer.now().getType().equals(Type.CHRCON)
            )) {
                funcRParams = parseFuncRParams();
                if (lexer.notEnd() && lexer.now().getName().equals(")")) {
                    printTk(lexer.now());
                    lexer.next();
                } else {
                    Err = true;
                    if (errors.containsKey(lexer.getToken(-1).getLine())) {
                        //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
                    } else {
                        ArrayList<MyError> list = new ArrayList<>();
                        list.add(new MyError("j", lexer.getToken(-1).getLine()));
                        errors.put(lexer.getToken(-1).getLine(), list);
                    }
                }
            } else {
                Err = true;
                if (errors.containsKey(lexer.getToken(-1).getLine())) {
                    //    errors.get(lexer.getToken(-1).getLine()).add(new MyError("j", lexer.getToken(-1).getLine()));
                } else {
                    ArrayList<MyError> list = new ArrayList<>();
                    list.add(new MyError("j", lexer.getToken(-1).getLine()));
                    errors.put(lexer.getToken(-1).getLine(), list);
                }
            }
            print("<UnaryExp>\n");
            return new UnaryExp(ident, funcRParams);
        }

        PrimaryExp primaryExp = parsePrimaryExp();

        print("<UnaryExp>\n");
        return new UnaryExp(primaryExp);

    }

    public UnaryOp parseUnaryOp() {
        Token token = lexer.now();
        printTk(token);
        lexer.next();
        print("<UnaryOp>\n");
        return new UnaryOp(token.getName());
    }

    public FuncRParams parseFuncRParams() {
        ArrayList<Exp> exps = new ArrayList<>();
        Exp exp = null;
        exp = parseExp();
        exps.add(exp);
        while (lexer.notEnd() && lexer.now().getName().equals(",")) {
            printTk(lexer.now());
            lexer.next();
            exp = parseExp();
            exps.add(exp);
        }
        print("<FuncRParams>\n");
        return new FuncRParams(exps);
    }

    public MulExp parseMulExp() {
        ArrayList<UnaryExp> unaryExps = new ArrayList<>();
        ArrayList<String> mulOps = new ArrayList<>();

        UnaryExp unaryExp = parseUnaryExp();
        unaryExps.add(unaryExp);
        while (lexer.notEnd() && "*/%".contains(lexer.now().getName())) {
            print("<MulExp>\n");
            printTk(lexer.now());
            mulOps.add(lexer.now().getName());
            lexer.next();
            unaryExp = parseUnaryExp();
            unaryExps.add(unaryExp);
        }
        print("<MulExp>\n");
        return new MulExp(unaryExps, mulOps);
    }

    public AddExp parseAddExp() {
        ArrayList<MulExp> mulExps = new ArrayList<>();
        ArrayList<String> addOps = new ArrayList<>();

        MulExp mulExp = parseMulExp();
        mulExps.add(mulExp);
        while (lexer.notEnd() && "+-".contains(lexer.now().getName())) {
            print("<AddExp>\n");
            printTk(lexer.now());
            addOps.add(lexer.now().getName());
            lexer.next();
            mulExp = parseMulExp();
            mulExps.add(mulExp);
        }
        print("<AddExp>\n");
        return new AddExp(mulExps, addOps);
    }

    public RelExp parseRelExp() {
        ArrayList<AddExp> addExps = new ArrayList<>();
        ArrayList<String> relOps = new ArrayList<>();

        AddExp addExp = parseAddExp();
        addExps.add(addExp);
        while (lexer.notEnd() && "<=>=".contains(lexer.now().getName())) {
            print("<RelExp>\n");
            printTk(lexer.now());
            relOps.add(lexer.now().getName());
            lexer.next();
            addExp = parseAddExp();
            addExps.add(addExp);
        }
        print("<RelExp>\n");
        return new RelExp(addExps, relOps);
    }

    public EqExp parseEqExp() {
        ArrayList<RelExp> relExps = new ArrayList<>();
        ArrayList<String> eqOps = new ArrayList<>();

        RelExp relExp = parseRelExp();
        relExps.add(relExp);
        while (lexer.notEnd() && "!==".contains(lexer.now().getName())) {
            print("<EqExp>\n");
            printTk(lexer.now());
            eqOps.add(lexer.now().getName());
            lexer.next();
            relExp = parseRelExp();
            relExps.add(relExp);
        }
        print("<EqExp>\n");
        return new EqExp(relExps, eqOps);
    }

    public LAndExp parseLAndExp() {
        ArrayList<EqExp> eqExps = new ArrayList<>();
        ArrayList<String> lAndOps = new ArrayList<>();

        EqExp eqExp = parseEqExp();
        eqExps.add(eqExp);
        while (lexer.notEnd() && "&&".contains(lexer.now().getName())) {
            print("<LAndExp>\n");
            printTk(lexer.now());
            lAndOps.add(lexer.now().getName());
            lexer.next();
            eqExp = parseEqExp();
            eqExps.add(eqExp);
        }
        print("<LAndExp>\n");
        return new LAndExp(eqExps, lAndOps);
    }

    public LOrExp parseLOrExp() {
        ArrayList<LAndExp> lAndExps = new ArrayList<>();
        ArrayList<String> lOrOps = new ArrayList<>();

        LAndExp lAndExp = parseLAndExp();
        lAndExps.add(lAndExp);
        while (lexer.notEnd() && "||".contains(lexer.now().getName())) {
            print("<LOrExp>\n");
            printTk(lexer.now());
            lOrOps.add(lexer.now().getName());
            lexer.next();
            lAndExp = parseLAndExp();
            lAndExps.add(lAndExp);
        }
        print("<LOrExp>\n");
        return new LOrExp(lAndExps, lOrOps);
    }

    public ConstExp parseConstExp() {
        AddExp addExp = parseAddExp();
        print("<ConstExp>\n");
        return new ConstExp(addExp);
    }

    public boolean isErr() {
        return Err;
    }

    public TreeMap<Integer, ArrayList<MyError>> getErrors() {
        return errors;
    }

    public StringBuilder getOut() {
        return out;
    }

}


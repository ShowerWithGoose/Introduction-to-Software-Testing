import java.util.*;
import Node.*;
import Tools.Token;
import Tools.myError;

public class Parser {
    private final List<Token> tokens;
    private int current = 0;
    private CompUnit compUnit;

    public Parser(List<Token> tokens) {
        this.tokens = tokens;
        this.compUnit = compUnit();
    }

    private CompUnit compUnit() {
        ArrayList<Decl> decls = new ArrayList<>();
        while (current < tokens.size() && isDecl()) {
            decls.add(decl());
        }
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        while (current < tokens.size() && isFuncDef()) {
            funcDefs.add(funcDef());
        }
        MainFuncDef mainFuncDef = mainFuncDef();
        //TODO
        return new CompUnit(100, decls, funcDefs, mainFuncDef);
    }

    private boolean isDecl() {
        int i = current;
        if (tokens.get(i).getType() == Token.TokenType.CONSTTK) {
            return true;
        } else if (tokens.get(i).getType() != Token.TokenType.INTTK && tokens.get(i).getType() != Token.TokenType.CHARTK) {
            return false;
        }
        //跳过 BType Ident
        i += 2;
        return tokens.get(i).getType() != Token.TokenType.LPARENT;
    }

    private boolean isFuncDef() {
        int i = current;
        if (tokens.get(i).getType() == Token.TokenType.VOIDTK || tokens.get(i).getType() == Token.TokenType.CHARTK) {
            return true;
        }
        //跳过 FuncType
        i += 1;
        return tokens.get(i).getType() != Token.TokenType.MAINTK;
    }

    private Decl decl() {
        Node node;
        if (tokens.get(current).getType() == Token.TokenType.CONSTTK) {
            node = constDecl();
        } else {
            node = varDecl();
        }
        return new Decl(100, node);
    }

    private ConstDecl constDecl() {
        ArrayList<Token> addTokens = new ArrayList<>();
        addTokens.add(tokens.get(current));

        match(Token.TokenType.CONSTTK);
        BType bType = bType();
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        constDefs.add(constDef());
        while (match(Token.TokenType.COMMA)) {
            addTokens.add(tokens.get(current - 1));
            constDefs.add(constDef());
        }

        if (!match(Token.TokenType.SEMICN)) {
            myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
            addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
        } else {
            addTokens.add(tokens.get(current - 1));
        }
        //TODO("<ConstDecl>" + "\n");
        ConstDecl constDecl = new ConstDecl(100, bType, constDefs);
        constDecl.addTokens(addTokens);
        return constDecl;
    }

    private BType bType() {
        if (match(Token.TokenType.INTTK) || match(Token.TokenType.CHARTK)) {
            return new BType(100, tokens.get(current - 1));
        }
        System.out.println("BType ERROR");
        return null;
    }

    private ConstDef constDef() {
        Token l_token = null;
        Token r_token = null;
        Token assign_token = null;
        Ident ident = new Ident(100, tokens.get(current));
        match(Token.TokenType.IDENFR);
        ConstExp constExp = null;
        if (match(Token.TokenType.LBRACK)) {
            l_token = (tokens.get(current - 1));
            constExp = constExp();
            if (!match(Token.TokenType.RBRACK)) {
                myError.newError(myError.ErrorType.ERROR_K, tokens.get(current - 1).getLineno());
                r_token = (new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                r_token = (tokens.get(current - 1));
            }
        }
        match(Token.TokenType.ASSIGN);
        assign_token = (tokens.get(current - 1));
        ConstInitVal constInitVal = constInitVal();
        //TODO("<ConstDef>" + "\n");
        return new ConstDef(100, ident, l_token, constExp, r_token, assign_token, constInitVal);
    }

    private ConstInitVal constInitVal() {
        ArrayList<Token> addTokens = new ArrayList<>();
        int num = 0;
        ArrayList<ConstExp> constExps = new ArrayList<>();
        StringConst stringConst = null;
        if (match(Token.TokenType.LBRACE)) {
            addTokens.add(tokens.get(current - 1));
            num = 2;
            if (!match(Token.TokenType.RBRACE)) {
                constExps.add(constExp());
                while (match(Token.TokenType.COMMA)) {
                    addTokens.add(tokens.get(current - 1));
                    constExps.add(constExp());
                }
                match(Token.TokenType.RBRACE);
                addTokens.add(tokens.get(current - 1));
            } else {
                addTokens.add(tokens.get(current - 1));
            }

        } else if (match(Token.TokenType.STRCON)) {
            stringConst = new StringConst(100, tokens.get(current - 1));
            num = 3;
        } else {
            num = 1;
            constExps.add(constExp());
        }
        //TODO("<ConstInitVal>" + "\n");
        ConstInitVal constInitVal = new ConstInitVal(100, constExps, stringConst, num);
        constInitVal.addTokens(addTokens);
        return constInitVal;
    }

    private VarDecl varDecl() {
        ArrayList<Token> addTokens = new ArrayList<>();
        BType bType = bType();
        ArrayList<VarDef> varDefs = new ArrayList<>();
        varDefs.add(varDef());
        while (match(Token.TokenType.COMMA)) {
            addTokens.add(tokens.get(current - 1));
            varDefs.add(varDef());
        }
        if (!match(Token.TokenType.SEMICN)) {
            myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
            addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
        } else {
            addTokens.add(tokens.get(current - 1));
        }
        //TODO("<VarDecl>" + "\n");
        VarDecl varDecl = new VarDecl(100, bType, varDefs);
        varDecl.addTokens(addTokens);
        return varDecl;
    }

    private VarDef varDef() {
        Token l_token = null;
        Token r_token = null;
        Token assign_token = null;
        int num = 1;
        Ident ident = new Ident(100, tokens.get(current));
        match(Token.TokenType.IDENFR);
        ConstExp constExp = null;
        if (match(Token.TokenType.LBRACK)) {
            l_token = (tokens.get(current - 1));
            constExp = constExp();
            if (!match(Token.TokenType.RBRACK)) {
                myError.newError(myError.ErrorType.ERROR_K, tokens.get(current - 1).getLineno());
                r_token = (new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                r_token = (tokens.get(current - 1));
            }
        }
        InitVal initVal = null;
        if (match(Token.TokenType.ASSIGN)) {
            assign_token = (tokens.get(current - 1));
            num = 2;
            initVal = initVal();
        }
        //TODO("<VarDef>" + "\n");
        return new VarDef(100, ident, l_token, constExp, r_token, assign_token, initVal, num);

    }

    private InitVal initVal() {
        ArrayList<Token> addTokens = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        int num = 0;
        StringConst stringConst = null;
        if (match(Token.TokenType.LBRACE)) {
            addTokens.add(tokens.get(current - 1));
            num = 2;
            if (!match(Token.TokenType.RBRACE)) {
                exps.add(exp());
                while (match(Token.TokenType.COMMA)) {
                    addTokens.add(tokens.get(current - 1));
                    exps.add(exp());
                }
                match(Token.TokenType.RBRACE);
                addTokens.add(tokens.get(current - 1));
            } else {
                addTokens.add(tokens.get(current - 1));
            }
        } else if (match(Token.TokenType.STRCON)) {
            stringConst = new StringConst(100, tokens.get(current - 1));
            num = 3;
        } else {
            num = 1;
            exps.add(exp());
        }
        //TODO("<InitVal>" + "\n");
        InitVal initVal = new InitVal(100, exps, stringConst, num);
        initVal.addTokens(addTokens);
        return initVal;
    }

    private FuncDef funcDef() {
        Token l_token = null;
        Token r_token = null;
        FuncType funcType = funcType();
        Ident ident = new Ident(100, tokens.get(current));
        match(Token.TokenType.IDENFR);
        match(Token.TokenType.LPARENT);
        l_token = (tokens.get(current - 1));
        FuncFParams funcFParams = null;
        if (tokens.get(current).getType() == Token.TokenType.INTTK || tokens.get(current).getType() == Token.TokenType.CHARTK) {
            funcFParams = funcFParams();
        }

        if (!match(Token.TokenType.RPARENT)) {
            myError.newError(myError.ErrorType.ERROR_J, tokens.get(current-1).getLineno());
            r_token = (new Token(Token.TokenType.UNKNOW, "ERROR", -1));
        } else {
            r_token = (tokens.get(current - 1));
        }
        Block block = block();

        //TODO("<FuncDef>" + "\n");
        return new FuncDef(100, funcType, ident, l_token, funcFParams, r_token,  block);
    }

    private MainFuncDef mainFuncDef() {
        Token int_token = null;
        Token main_token = null;
        Token l_token = null;
        Token r_token = null;
        int_token = (tokens.get(current));
        match(Token.TokenType.INTTK);
        main_token = (tokens.get(current));
        match(Token.TokenType.MAINTK);
        l_token = (tokens.get(current));
        match(Token.TokenType.LPARENT);

        if (!match(Token.TokenType.RPARENT)) {
            myError.newError(myError.ErrorType.ERROR_J, tokens.get(current-1).getLineno());
            r_token = (new Token(Token.TokenType.UNKNOW, "ERROR", -1));
        } else {
            r_token = (tokens.get(current - 1));
        }
        Block block = block();
        //TODO("<MainFuncDef>" + "\n");

        return new MainFuncDef(100 ,int_token, main_token, l_token, r_token, block);
    }

    private FuncType funcType() {
        Token token = null;
        if (match(Token.TokenType.INTTK) || match(Token.TokenType.CHARTK) || match(Token.TokenType.VOIDTK)) {
            token = tokens.get(current - 1);
        }
        //TODO("<FuncType>" + "\n");
        return new FuncType(100, token);
    }

    private FuncFParams funcFParams() {
        ArrayList<Token> addTokens = new ArrayList<>();
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        funcFParams.add(funcFParam());
        while (match(Token.TokenType.COMMA)) {
            addTokens.add(tokens.get(current - 1));
            funcFParams.add(funcFParam());
        }
        //TODO("<FuncFParams>" + "\n");
        FuncFParams temp =  new FuncFParams(100, funcFParams);
        temp.addTokens(addTokens);
        return temp;
    }

    private FuncFParam funcFParam() {
        Token l_token = null;
        Token r_token = null;
        BType bType = bType();
        Ident ident = new Ident(100, tokens.get(current));
        match(Token.TokenType.IDENFR);
        if (match(Token.TokenType.LBRACK)) {
            l_token = (tokens.get(current - 1));
            if(!match(Token.TokenType.RBRACK)) {
                myError.newError(myError.ErrorType.ERROR_K, tokens.get(current-1).getLineno());
                r_token = (new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                r_token = (tokens.get(current - 1));
            }
        }
        //TODO("<FuncFParam>" + "\n");

        return new FuncFParam(100, bType, ident, l_token, r_token);
    }

    private Block block() {
        Token l_token = null;
        Token r_token = null;
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        match(Token.TokenType.LBRACE);
        l_token = (tokens.get(current - 1));
        while (current < tokens.size() && !match(Token.TokenType.RBRACE)) {
            blockItems.add(blockItem());
        }
        r_token = (tokens.get(current - 1));
        //TODO("<Block>" + "\n");
        return new Block(100, l_token, blockItems, r_token);
    }

    private BlockItem blockItem() {
        Node node;
        if (isDecl()) {
            node = decl();
        } else {
            node = stmt();
        }
        return new BlockItem(100, node);
    }

    private Stmt stmt() {
        ArrayList<Token> addTokens = new ArrayList<>();
        LVal lVal = null;
        ArrayList<Exp> exps = new ArrayList<>();
        Block block = null;
        Cond cond = null;
        Stmt stmt1 = null;
        Stmt stmt2 = null;
        ForStmt forStmt1 = null;
        ForStmt forStmt2 = null;
        StringConst str = null;
        int num = 0;

        if (tokens.get(current).getType() == Token.TokenType.IDENFR && checkAssignAfterLVal()) {
            // LVal
            lVal = lVal();
            match(Token.TokenType.ASSIGN);
            addTokens.add(tokens.get(current - 1));
            if (match(Token.TokenType.GETINTTK)) {
                addTokens.add(tokens.get(current - 1));
                num = 9;
                match(Token.TokenType.LPARENT);
                addTokens.add(tokens.get(current - 1));
                if (!match(Token.TokenType.RPARENT)) {
                    myError.newError(myError.ErrorType.ERROR_J, tokens.get(current-1).getLineno());
                    addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
                } else {
                    addTokens.add(tokens.get(current - 1));
                }
                if (!match(Token.TokenType.SEMICN)) {
                    myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
                    addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
                } else {
                    addTokens.add(tokens.get(current - 1));
                }
            } else if (match(Token.TokenType.GETCHARTK)) {
                addTokens.add(tokens.get(current - 1));
                num = 10;
                match(Token.TokenType.LPARENT);
                addTokens.add(tokens.get(current - 1));
                if (!match(Token.TokenType.RPARENT)) {
                    myError.newError(myError.ErrorType.ERROR_J, tokens.get(current-1).getLineno());
                    addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
                } else {
                    addTokens.add(tokens.get(current - 1));
                }
                if (!match(Token.TokenType.SEMICN)) {
                    myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
                    addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
                } else {
                    addTokens.add(tokens.get(current - 1));
                }
            } else {
                num = 1;
                exps.add(exp());
                if (!match(Token.TokenType.SEMICN)) {
                    myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
                    addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
                } else {
                    addTokens.add(tokens.get(current - 1));
                }
            }
        } else if (tokens.get(current).getType() == Token.TokenType.IFTK) {
            // if
            num = 4;
            match(Token.TokenType.IFTK);
            addTokens.add(tokens.get(current - 1));
            match(Token.TokenType.LPARENT);
            addTokens.add(tokens.get(current - 1));
            cond = cond();
            if (!match(Token.TokenType.RPARENT)) {
                myError.newError(myError.ErrorType.ERROR_J, tokens.get(current-1).getLineno());
                addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                addTokens.add(tokens.get(current - 1));
            }
            stmt1 = stmt();
            if (tokens.get(current).getType() == Token.TokenType.ELSETK) {
                match(Token.TokenType.ELSETK);
                addTokens.add(tokens.get(current - 1));
                stmt2 = stmt();
            }
        } else if (tokens.get(current).getType() == Token.TokenType.FORTK) {
            // for
            num = 5;
            match(Token.TokenType.FORTK);
            addTokens.add(tokens.get(current - 1));
            match(Token.TokenType.LPARENT);
            addTokens.add(tokens.get(current - 1));
            if (tokens.get(current).getType() != Token.TokenType.SEMICN) {
                forStmt1 = forStmt();
            }
            if (match(Token.TokenType.SEMICN)) {
                addTokens.add(tokens.get(current - 1));
            }
            if (tokens.get(current).getType() != Token.TokenType.SEMICN) {
                cond = cond();
            }
            if (match(Token.TokenType.SEMICN)) {
                addTokens.add(tokens.get(current - 1));
            }
            if (tokens.get(current).getType() != Token.TokenType.RPARENT) {
                forStmt2 = forStmt();
            }
            if (match(Token.TokenType.RPARENT)) {
                addTokens.add(tokens.get(current - 1));
            }
            stmt1 = stmt();
        } else if (match(Token.TokenType.BREAKTK)) {
            // break; continue;
            addTokens.add(tokens.get(current - 1));
            num = 6;
            if (!match(Token.TokenType.SEMICN)) {
                myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
                addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                addTokens.add(tokens.get(current - 1));
            }
        } else if (match(Token.TokenType.CONTINUETK)) {
            // break; continue;
            addTokens.add(tokens.get(current - 1));
            num = 7;
            if (!match(Token.TokenType.SEMICN)) {
                myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
                addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                addTokens.add(tokens.get(current - 1));
            }
        } else if (match(Token.TokenType.RETURNTK)) {
            //return
            addTokens.add(tokens.get(current - 1));
            num = 8;
            int c = current;
            Exp expFlag = exp();
            if (expFlag != null) {
                exps.add(expFlag);
            } else {
                current = c;
            }
            if (!match(Token.TokenType.SEMICN)) {
                myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
                addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                addTokens.add(tokens.get(current - 1));
            }
        } else if (match(Token.TokenType.PRINTFTK)) {
            //print
            num = 11;
            addTokens.add(tokens.get(current - 1));
            match(Token.TokenType.LPARENT);
            addTokens.add(tokens.get(current - 1));
            match(Token.TokenType.STRCON);
            str = new StringConst(100, tokens.get(current - 1));
            while (match(Token.TokenType.COMMA)) {
                addTokens.add(tokens.get(current - 1));
                exps.add(exp());
            }
            if (!match(Token.TokenType.RPARENT)) {
                myError.newError(myError.ErrorType.ERROR_J, tokens.get(current-1).getLineno());
                addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                addTokens.add(tokens.get(current - 1));
            }
            if (!match(Token.TokenType.SEMICN)) {
                myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
                addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                addTokens.add(tokens.get(current - 1));
            }
        } else if (tokens.get(current).getType() == Token.TokenType.LBRACE){
            num = 3;
            block = block();
        } else {
            num = 2;
            if (tokens.get(current).getType() == Token.TokenType.SEMICN) {
                match(Token.TokenType.SEMICN);
                addTokens.add(tokens.get(current - 1));
            } else {
                exps.add(exp());
                if (!match(Token.TokenType.SEMICN)) {
                    myError.newError(myError.ErrorType.ERROR_I, tokens.get(current-1).getLineno());
                    addTokens.add(new Token(Token.TokenType.UNKNOW, "ERROR", -1));
                } else {
                    addTokens.add(tokens.get(current - 1));
                }
            }
        }
        //TODO("<Stmt>" + "\n");
        Stmt stmt = new Stmt(100, lVal, exps, block, cond,
                stmt1, stmt2, forStmt1, forStmt2, str, num);
        stmt.addTokens(addTokens);
        return stmt;
    }

    private ForStmt forStmt() {

        LVal lVal = lVal();
        match(Token.TokenType.ASSIGN);
        Token token = tokens.get(current - 1);
        Exp exp = exp();
        //TODO("<ForStmt>" + "\n");
        return new ForStmt(100, lVal, token, exp);
    }

    private Exp exp() {
        AddExp addExp = addExp();
        //TODO("<Exp>" + "\n");
        if (addExp == null) {
            return null;
        } else {
            return new Exp(100, addExp);
        }

    }

    private Cond cond() {

        LOrExp lOrExp = lOrExp();
        //TODO("<Cond>" + "\n");
        return new Cond(100, lOrExp);
    }

    private LVal lVal() {
        Token l_token = null;
        Token r_token = null;
        Exp exp = null;
        Ident ident = new Ident(100, tokens.get(current));
        if (!match(Token.TokenType.IDENFR)) {
            return null;
        }
        if (match(Token.TokenType.LBRACK)) {
            l_token = tokens.get(current - 1);
            exp = exp();
            if (exp == null) {
                return null;
            }
            if(!match(Token.TokenType.RBRACK)) {
                myError.newError(myError.ErrorType.ERROR_K, tokens.get(current-1).getLineno());
                r_token = (new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                 r_token = tokens.get(current - 1);
            }
        }
        //TODO("<LVal>" + "\n");
        return new LVal(100, ident, l_token, exp, r_token);
    }

    private PrimaryExp primaryExp() {
        Token l_token = null;
        Token r_token = null;
        Exp exp = null;
        LVal lVal = null;
        Num number = null ;
        character cha = null;
        int num = 0;
        if (match(Token.TokenType.INTCON)) {
            num = 3;
            //TODO("<Number>" + "\n");
            number = new Num(100, (tokens.get(current-1)));

        } else if (match(Token.TokenType.CHRCON)) {
            num = 4;
            //TODO("<Character>" + "\n");
            cha = new character(100, (tokens.get(current-1)));
        } else if (match(Token.TokenType.LPARENT)) {
            l_token = tokens.get(current - 1);
            num = 1;
            exp = exp();
            if (exp == null) {
                return null;
            }
            if (!match(Token.TokenType.RPARENT)) {
                myError.newError(myError.ErrorType.ERROR_J, tokens.get(current-1).getLineno());
                r_token = (new Token(Token.TokenType.UNKNOW, "ERROR", -1));
            } else {
                r_token = tokens.get(current - 1);
            }
        } else {
            num = 2;
            lVal = lVal();
            if (lVal == null) {
                return null;
            }
        }
        //TODO("<PrimaryExp>" + "\n");
        return new PrimaryExp(100, l_token, exp, r_token, lVal, number, cha, num);
    }

    private UnaryExp unaryExp() {
        Token l_token = null;
        Token r_token = null;
        PrimaryExp primaryExp = null;
        Ident ident = null;
        FuncRParams funcRParams = null;
        UnaryOp unaryOp = null;
        UnaryExp unaryExp = null;
        int num = 0;
        if (tokens.get(current).getType() == (Token.TokenType.PLUS) ||
                tokens.get(current).getType() == (Token.TokenType.MINU) ||
                tokens.get(current).getType() == (Token.TokenType.NOT)) {
            num = 3;
            unaryOp = unaryOp();
            unaryExp = unaryExp();
            if (unaryOp == null || unaryExp == null) {
                return null;
            }
        } else if (tokens.get(current).getType() == Token.TokenType.IDENFR  &&
                tokens.get(current + 1).getType() == Token.TokenType.LPARENT) {
            num = 2;
            ident = new Ident(100, tokens.get(current));
            match(Token.TokenType.IDENFR);
            if(!match(Token.TokenType.LPARENT)) {
                return null;
            }
            l_token = tokens.get(current - 1);
            if (match(Token.TokenType.RPARENT)) {
                r_token = tokens.get(current - 1);
            } else {
                funcRParams = funcRParams();
                if (!match(Token.TokenType.RPARENT)) {
                    myError.newError(myError.ErrorType.ERROR_J, tokens.get(current-1).getLineno());
                    r_token = (new Token(Token.TokenType.UNKNOW, "ERROR", -1));
                } else {
                    r_token = tokens.get(current - 1);
                }
            }
        } else {
            num = 1;
            primaryExp = primaryExp();
            if (primaryExp == null) {
                return null;
            }
        }
        //TODO("<UnaryExp>" + "\n");
        return new UnaryExp(100, primaryExp, ident, l_token, funcRParams, r_token, unaryOp, unaryExp, num);
    }

    private UnaryOp unaryOp() {
        Token token = null;
        if (match(Token.TokenType.PLUS) || match(Token.TokenType.MINU) || match(Token.TokenType.NOT)) {
            token = tokens.get(current - 1);
            return new UnaryOp(100, token);
        }
        //TODO("<UnaryOp>" + "\n");
        return null;
    }

    private FuncRParams funcRParams() {
        ArrayList<Token> addTokens = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        Exp exp = exp();
        if (exp == null) {
            return null;
        }
        exps.add(exp);
        while (match(Token.TokenType.COMMA)) {
            addTokens.add(tokens.get(current - 1));
            exp = exp();
            if (exp == null) {
                return null;
            }
            exps.add(exp);
        }
        //TODO("<FuncRParams>" + "\n");
        FuncRParams funcRParams = new FuncRParams(100, exps);
        funcRParams.addTokens(addTokens);
        return funcRParams;
    }

    private MulExp mulExp() {
        Token token = null;
        UnaryExp unaryExp;
        MulExp mulExp = null;
        int num = 1;
        unaryExp = unaryExp();
        if (unaryExp == null) {
            return null;
        }
        //TODO("<MulExp>" + "\n");
        if (match(Token.TokenType.MULT) || match(Token.TokenType.DIV) || match(Token.TokenType.MOD)) {
            num = 2;
            token = tokens.get(current - 1);
            mulExp = mulExp();
        }
        return new MulExp(100, unaryExp, token , mulExp, num);
    }

    private AddExp addExp() {
        Token token = null;
        MulExp mulExp = mulExp();
        if (mulExp == null) {
            return null;
        }
        int num = 1;
        AddExp addExp = null;
        //TODO("<AddExp>" + "\n");
        if (match(Token.TokenType.PLUS) || match(Token.TokenType.MINU)) {
            num = 2;
            token = tokens.get(current - 1);
            addExp = addExp();
        }
        return new AddExp(100, mulExp, token, addExp, num);
    }

    private RelExp relExp() {
        AddExp addExp = addExp();
        Token token = null;
        int num = 1;
        //TODO("<RelExp>" + "\n");
        RelExp relExp = null;
        if (match(Token.TokenType.LSS) || match(Token.TokenType.GRE) ||
                match(Token.TokenType.LEQ) || match(Token.TokenType.GEQ)) {
            num = 2;
            token = tokens.get(current - 1);
            relExp = relExp();
        }
        return new RelExp(100, addExp, token, relExp, num);
    }

    private EqExp eqExp() {
        Token token = null;
        int num = 1;
        RelExp relExp = relExp();
        //TODO("<EqExp>" + "\n");
        EqExp eqExp = null;
        if (match(Token.TokenType.EQL) || match(Token.TokenType.NEQ)) {
            num = 2;
            token = tokens.get(current - 1);
            eqExp = eqExp();

        }
        return new EqExp(100, relExp, token, eqExp, num);
    }

    private LAndExp lAndExp() {
        Token token = null;
        EqExp eqExp = eqExp();
        LAndExp lAndExp = null;
        int num = 1;
        //TODO("<LAndExp>" + "\n");
        if (match(Token.TokenType.AND)) {
            token = tokens.get(current - 1);
            num = 2;
            lAndExp = lAndExp();
        }
        return new LAndExp(100, eqExp, token, lAndExp, num);
    }

    private LOrExp lOrExp() {
        Token token = null;
        LAndExp lAndExp = lAndExp();
        LOrExp lOrExp = null;
        int num = 1;
        //TODO("<LOrExp>" + "\n");
        if (match(Token.TokenType.OR)) {
            token = tokens.get(current - 1);
            num = 2;
            lOrExp = lOrExp();
        }
        return new LOrExp(100, lAndExp, token, lOrExp, num);
    }

    private ConstExp constExp() {
        AddExp addExp = addExp();
        //TODO("<ConstExp>" + "\n");
        return new ConstExp(100, addExp);
    }

    private boolean match(Token.TokenType expectedType) {
        if (current < tokens.size() && tokens.get(current).getType() == expectedType) {
            nextToken();
            return true;
        }
        return false;
    }

    private void nextToken() {
        //TODO(tokens.get(current) + "\n");
        current++;
    }

    public boolean checkAssignAfterLVal() {
        int i = current;
        exp();
        if (tokens.get(current).getType() == Token.TokenType.ASSIGN) {
            current = i;
            return true;
        } else {
            current = i;
            return false;
        }
    }

    public CompUnit getCompUnit() {
        return compUnit;
    }
}

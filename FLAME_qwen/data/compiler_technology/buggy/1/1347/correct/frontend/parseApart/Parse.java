package frontend.parseApart;

import frontend.ErrorType;
import frontend.Errors;
import frontend.LexType;
import frontend.Lexer;
import frontend.MyError;
import frontend.Token;
import frontend.parseApart.NodeDef.Block;
import frontend.parseApart.NodeDef.Exps.AddExp;
import frontend.parseApart.NodeDef.Exps.Cond;
import frontend.parseApart.NodeDef.Exps.ConstExp;
import frontend.parseApart.NodeDef.Exps.EqExp;
import frontend.parseApart.NodeDef.Exps.Exp;
import frontend.parseApart.NodeDef.Exps.FuncRParams;
import frontend.parseApart.NodeDef.Exps.FuncUExp;
import frontend.parseApart.NodeDef.Exps.LAndExp;
import frontend.parseApart.NodeDef.Exps.LOrExp;
import frontend.parseApart.NodeDef.Exps.LVal;
import frontend.parseApart.NodeDef.Exps.MulExp;
import frontend.parseApart.NodeDef.Exps.MyCharacter;
import frontend.parseApart.NodeDef.Exps.MyNumber;
import frontend.parseApart.NodeDef.Exps.OpUnaryExp;
import frontend.parseApart.NodeDef.Exps.PrimaryExp;
import frontend.parseApart.NodeDef.Exps.PrimaryExpExp;
import frontend.parseApart.NodeDef.Exps.PrimaryLVal;
import frontend.parseApart.NodeDef.Exps.RelExp;
import frontend.parseApart.NodeDef.Exps.UnaryExp;
import frontend.parseApart.NodeDef.Exps.UnaryPrimaryExp;
import frontend.parseApart.NodeDef.Normal.CompUnit;
import frontend.parseApart.NodeDef.Normal.ConstDecl;
import frontend.parseApart.NodeDef.Normal.ConstDef;
import frontend.parseApart.NodeDef.Normal.ConstInitVal;
import frontend.parseApart.NodeDef.Normal.Decl;
import frontend.parseApart.NodeDef.Normal.FuncDef;
import frontend.parseApart.NodeDef.Normal.FuncFParam;
import frontend.parseApart.NodeDef.Normal.InitVal;
import frontend.parseApart.NodeDef.Normal.MainFuncDef;
import frontend.parseApart.NodeDef.Normal.Stmt;
import frontend.parseApart.NodeDef.Normal.VarDecl;
import frontend.parseApart.NodeDef.Normal.VarDef;
import frontend.parseApart.NodeDef.Stmts.BlockItem;
import frontend.parseApart.NodeDef.Stmts.BlockStmt;
import frontend.parseApart.NodeDef.Stmts.BreakStmt;
import frontend.parseApart.NodeDef.Stmts.ContinueStmt;
import frontend.parseApart.NodeDef.Stmts.ExpStmt;
import frontend.parseApart.NodeDef.Stmts.FirstForStmt;
import frontend.parseApart.NodeDef.Stmts.ForStmt;
import frontend.parseApart.NodeDef.Stmts.IfStmt;
import frontend.parseApart.NodeDef.Stmts.LEStmt;
import frontend.parseApart.NodeDef.Stmts.LGetchar;
import frontend.parseApart.NodeDef.Stmts.LGetint;
import frontend.parseApart.NodeDef.Stmts.PrintfStmt;
import frontend.parseApart.NodeDef.Stmts.ReturnStmt;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Parse {
    private Lexer lexer;
    private Token curToken = null;
    private Token oldToken = null;
    private Errors errors;
    private Queue<Token> buffer = new LinkedList<>();
    private ArrayList<String> parseOut = new ArrayList<>();

    private LVal lVal;

    public Parse(Lexer lexer, Errors errors) {
        this.lexer = lexer;
        this.errors = errors;
    }

    public void parseBegin() {
        getOneToken();
        CompUnit compUnit = paresCompUnit();
    }

    private void getOneToken() {
        lexer.next();
        this.curToken = lexer.getNewToken();
    }

    private CompUnit paresCompUnit() {
        Token tempToken;
        CompUnit compUnit = new CompUnit();
        while (true) {
            // forwardToken();
            if (curToken.getLexType() == LexType.INTTK) {
                tempToken = forwardToken();
                if (tempToken.getLexType() == LexType.MAINTK) {
                    compUnit.setMainFuncDef(parseMainFuncDef());
                    break;
                } else {
                    tempToken = forwardToken();
                    if (tempToken.getLexType() == LexType.LPARENT) {
                        compUnit.setFuncDef(parseFuncDef(LexType.INTTK));
                    } else {
                        Decl decl = parseDecl(false);
                        compUnit.setDecl(decl);
                    }
                }
            } else if (curToken.getLexType() == LexType.CHARTK) {
                forwardToken();
                tempToken = forwardToken();
                if (tempToken.getLexType() == LexType.LPARENT) {
                    FuncDef funcDef = parseFuncDef(LexType.CHARTK);
                    compUnit.setFuncDef(funcDef);
                } else {
                    Decl decl = parseDecl(false);
                    compUnit.setDecl(decl);
                }
            } else if (curToken.getLexType() == LexType.VOIDTK) {
                FuncDef funcDef = parseFuncDef(LexType.VOIDTK);
                compUnit.setFuncDef(funcDef);
            } else if (curToken.getLexType() == LexType.CONSTTK) {
                Decl decl = parseDecl(true);
                compUnit.setDecl(decl);
            }
        }
        this.parseOut.add(compUnit.returnSymbolType());
        return compUnit;
    }

    private MainFuncDef parseMainFuncDef() {
        MainFuncDef mainFuncDef = new MainFuncDef();
        match(curToken, LexType.INTTK);
        match(curToken, LexType.MAINTK);
        match(curToken, LexType.LPARENT);
        if (curToken.getLexType() == LexType.RPARENT) {
            match(curToken, LexType.RPARENT);
        } else {
            MyError error = new MyError(oldToken.getLine(), ErrorType.j);
            this.errors.setErrors(error);
        }
        Block block = parseBlock();
        mainFuncDef.setBlock(block);
        this.parseOut.add(mainFuncDef.returnSymbolType());
        return mainFuncDef;
    }

    private Decl parseDecl(boolean type) {
        Decl decl = new Decl();
        if (type) {
            ConstDecl constDecl = parseConstDecl();
            decl.setConstDecl(constDecl);
        } else {
            VarDecl varDecl = parseVarDecl();
            decl.setVarDecl(varDecl);
        }

        //this.parseOut.add(decl.returnSymbolType());
        return decl;
    }

    private VarDecl parseVarDecl() {
        VarDecl varDecl = new VarDecl();
        if (curToken.getLexType() == LexType.INTTK) {
            match(curToken, LexType.INTTK);
            varDecl.setBType(LexType.INTTK);
            //this.parseOut.add("<BType>");
        } else if (curToken.getLexType() == LexType.CHARTK) {
            match(curToken, LexType.CHARTK);
            varDecl.setBType(LexType.CHARTK);
            //this.parseOut.add("<BType>");
        }
        VarDef varDef = parseVarDef();
        varDecl.setVarDefs(varDef);
        while (curToken.getLexType() == LexType.COMMA) {
            getNextToken(); // TODO match
            varDef = parseVarDef();
            varDecl.setVarDefs(varDef);
        }
        if (curToken.getLexType() == LexType.SEMICN) {
            getNextToken();
        } else {
            MyError error = new MyError(oldToken.getLine(), ErrorType.i);
            this.errors.setErrors(error);
        }

        this.parseOut.add(varDecl.returnSymbolType());

        return varDecl;
    }

    private VarDef parseVarDef() {
        VarDef varDef = new VarDef();
        varDef.setNameAndLine(curToken);
        match(curToken, LexType.IDENFR);
        if (curToken.getLexType() == LexType.LBRACK) {
            match(curToken, LexType.LBRACK);
            ConstExp constExp = parseConstExp();
            varDef.setConstExp(constExp);
            if (curToken.getLexType() == LexType.RBRACK) {
                match(curToken, LexType.RBRACK);
            } else {                //maybe error
                MyError error = new MyError(oldToken.getLine(), ErrorType.k);
                this.errors.setErrors(error);
            }
            if (curToken.getLexType() == LexType.ASSIGN) {
                match(curToken, LexType.ASSIGN);
                InitVal initVal = parseInitVal();
                varDef.setInitVal(initVal);
            }
        } else if (curToken.getLexType() == LexType.ASSIGN) {
            match(curToken, LexType.ASSIGN);
            InitVal initVal = parseInitVal();
            varDef.setInitVal(initVal);
        }

        parseOut.add(varDef.returnSymbolType());

        return varDef;
    }

    private ConstDecl parseConstDecl() {
        ConstDecl constDecl = new ConstDecl();
        match(curToken, LexType.CONSTTK);
        if (curToken.getLexType() == LexType.INTTK) {
            match(curToken, LexType.INTTK);
            constDecl.setBType(LexType.INTTK);
        } else if (curToken.getLexType() == LexType.CHARTK) {
            match(curToken, LexType.CHARTK);
            constDecl.setBType(LexType.CHARTK);
        } else {
            System.out.println("parseConstDecl Error");
        }

        //this.parseOut.add("<BType>");

        ConstDef constDef = parseConstDef();
        constDecl.setConstDefs(constDef);
        while (curToken.getLexType() == LexType.COMMA) {
            getNextToken();
            constDef = parseConstDef();
            constDecl.setConstDefs(constDef);
        }
        if (curToken.getLexType() == LexType.SEMICN) {
            getNextToken();
        } else {
            MyError error = new MyError(oldToken.getLine(), ErrorType.i);
            this.errors.setErrors(error);
        }

        this.parseOut.add(constDecl.returnSymbolType());

        return constDecl;

    }

    private ConstDef parseConstDef() {
        ConstDef constDef = new ConstDef();
        constDef.setNameAndLine(curToken);
        match(curToken, LexType.IDENFR);
        if (curToken.getLexType() == LexType.LBRACK) {
            match(curToken, LexType.LBRACK);
            ConstExp constExp = parseConstExp();
            constDef.setConstExp(constExp);
            if (curToken.getLexType() == LexType.RBRACK) {
                match(curToken, LexType.RBRACK);
            } else {                //maybe error
                MyError error = new MyError(oldToken.getLine(), ErrorType.k);
                this.errors.setErrors(error);
            }
            match(curToken, LexType.ASSIGN);
        } else if (curToken.getLexType() == LexType.ASSIGN) {
            match(curToken, LexType.ASSIGN);
        }
        ConstInitVal constInitVal = parseConstInitval();
        constDef.setConstInitVal(constInitVal);

        this.parseOut.add(constDef.returnSymbolType());

        return constDef;
    }

    private InitVal parseInitVal() {
        InitVal initVal = new InitVal();

        if (curToken.getLexType() == LexType.STRCON) {
            initVal.setStringAndLine(curToken);
            match(curToken, LexType.STRCON);
            initVal.setType(3);
        } else if (curToken.getLexType() == LexType.LBRACE) {
            initVal.setType(2);
            match(curToken, LexType.LBRACE);
            if (curToken.getLexType() == LexType.RBRACE) {
                match(curToken, LexType.RBRACE);
            } else {
                Exp exp = parseExp(false);
                initVal.setExps(exp);
                while (curToken.getLexType() == LexType.COMMA) {
                    match(curToken, LexType.COMMA);
                    Exp exp1 = parseExp(false);
                    initVal.setExps(exp1);
                }
                match(curToken, LexType.RBRACE);
            }
        } else {
            initVal.setType(1);
            Exp exp = parseExp(false);
            initVal.setExps(exp);
        }

        this.parseOut.add(initVal.returnSymbolType());
        return initVal;
    }

    private ConstInitVal parseConstInitval() {
        ConstInitVal constInitVal = new ConstInitVal();
        if (curToken.getLexType() == LexType.STRCON) {
            constInitVal.setStringAndLine(curToken);
            constInitVal.setType(3);
            match(curToken, LexType.STRCON);

        } else if (curToken.getLexType() == LexType.LBRACE) {
            constInitVal.setType(2);
            match(curToken, LexType.LBRACE);
            if (curToken.getLexType() == LexType.RBRACE) {
                match(curToken, LexType.RBRACE);
            } else {
                ConstExp constExp = parseConstExp();
                constInitVal.setConstExps(constExp);
                while (curToken.getLexType() == LexType.COMMA) {
                    match(curToken, LexType.COMMA);
                    constExp = parseConstExp();
                    constInitVal.setConstExps(constExp);
                }
                match(curToken, LexType.RBRACE);
            }
        } else {
            ConstExp constExp = parseConstExp();
            constInitVal.setConstExps(constExp);
            constInitVal.setType(1);
        }
        this.parseOut.add(constInitVal.returnSymbolType());
        return constInitVal;
    }

    private FuncDef parseFuncDef(LexType lexType) {
        FuncDef funcDef = new FuncDef();
        funcDef.setLexType(lexType);
        match(curToken, lexType);

        this.parseOut.add("<FuncType>");

        funcDef.setNameAndLine(curToken);
        match(curToken, LexType.IDENFR);
        match(curToken, LexType.LPARENT);
        if (curToken.getLexType() == LexType.RPARENT) {
            match(curToken, LexType.RPARENT);
        } else if (curToken.getLexType() == LexType.LBRACE) {
            MyError error = new MyError(oldToken.getLine(), ErrorType.j);
            this.errors.setErrors(error);
        } else {
            FuncFParam funcFParam = parseFuncFParam();
            funcDef.setFuncFParams(funcFParam);
            while (curToken.getLexType() == LexType.COMMA) {
                match(curToken, LexType.COMMA);
                funcFParam = parseFuncFParam();
                funcDef.setFuncFParams(funcFParam);
            }

            this.parseOut.add("<FuncFParams>");

            if (curToken.getLexType() == LexType.RPARENT) {
                match(curToken, LexType.RPARENT);
            } else {
                MyError error = new MyError(oldToken.getLine(), ErrorType.j);
                this.errors.setErrors(error);
            }
        }
        Block block = parseBlock();
        funcDef.setBlock(block);
        parseOut.add(funcDef.returnSymbolType());

        return funcDef;
    }

    private FuncFParam parseFuncFParam() {
        FuncFParam funcFParam = new FuncFParam();

        if (curToken.getLexType() == LexType.INTTK) {
            funcFParam.setLexType(curToken);
            match(curToken, LexType.INTTK);
        } else if (curToken.getLexType() == LexType.CHARTK) {
            funcFParam.setLexType(curToken);
            match(curToken, LexType.CHARTK);
        } else {
            System.out.println("parseFuncFParam error");
        }

        //this.parseOut.add("<BType>");

        funcFParam.setNameAndLine(curToken);
        match(curToken, LexType.IDENFR);
        if (curToken.getLexType() == LexType.LBRACK) {
            match(curToken, LexType.LBRACK);
            funcFParam.setType();
            if (curToken.getLexType() == LexType.RBRACK) {
                match(curToken, LexType.RBRACK);
            } else {
                MyError error = new MyError(oldToken.getLine(), ErrorType.k);
                this.errors.setErrors(error);
            }

        }
        this.parseOut.add(funcFParam.returnSymbolType());

        return funcFParam;
    }

    private Block parseBlock() {
        Block block = new Block();

        match(curToken, LexType.LBRACE);
        while (curToken.getLexType() != LexType.RBRACE) {
            BlockItem blockItem = parseBlockItem();
            block.setBlockItems(blockItem);
        }
        match(curToken, LexType.RBRACE);

        this.parseOut.add(block.returnSymbolType());
        return block;
    }

    private BlockItem parseBlockItem() {
        BlockItem blockItem = new BlockItem();
        if (curToken.getLexType() == LexType.INTTK
                || curToken.getLexType() == LexType.CHARTK) {
            Decl decl = parseDecl(false);
            blockItem.setDecl(decl);
        } else if (curToken.getLexType() == LexType.CONSTTK) {
            Decl decl = parseDecl(true);
            blockItem.setDecl(decl);
        } else {
            Stmt stmt = parseStmt();
            blockItem.setStmt(stmt);
        }

        //this.parseOut.add(blockItem.returnSymbolType());

        return blockItem;
    }

    private Stmt parseStmt() {

        if (curToken.getLexType() == LexType.IFTK) {
            IfStmt ifStmt = parseIfStmt();

            this.parseOut.add(ifStmt.returnSymbolType());
            return ifStmt;
        } else if (curToken.getLexType() == LexType.FORTK) {
            ForStmt forStmt = parseForStmt();

            this.parseOut.add(forStmt.returnSymbolType());
            return forStmt;
        } else if (curToken.getLexType() == LexType.BREAKTK) {
            BreakStmt breakStmt = parseBreakStmt();

            this.parseOut.add(breakStmt.returnSymbolType());

            return breakStmt;
        } else if (curToken.getLexType() == LexType.CONTINUETK) {
            ContinueStmt continueStmt = parseContinueStmt();

            this.parseOut.add(continueStmt.returnSymbolType());

            return continueStmt;
        } else if (curToken.getLexType() == LexType.RETURNTK) {
            ReturnStmt returnStmt = parseReturnStmt();

            this.parseOut.add(returnStmt.returnSymbolType());

            return returnStmt;
        } else if (curToken.getLexType() == LexType.PRINTFTK) {
            PrintfStmt printfStmt = parsePrintfStmt();

            this.parseOut.add(printfStmt.returnSymbolType());

            return printfStmt;
        } else if (curToken.getLexType() == LexType.LBRACE) {
            BlockStmt blockStmt = parseBlockStmt();

            this.parseOut.add(blockStmt.returnSymbolType());

            return blockStmt;
        } else if (curToken.getLexType() == LexType.SEMICN) { // only one SEMICN
            ExpStmt expStmt = new ExpStmt();
            match(curToken, LexType.SEMICN);

            this.parseOut.add("<Stmt>");

            return expStmt;
        } else if (firstExpPart(curToken)) {
            ExpStmt expStmt = parseExpStmt(false);

            this.parseOut.add(expStmt.returnSymbolType());

            return expStmt;
        } else if (curToken.getLexType() == LexType.IDENFR) {
            Token tempToken = forwardToken();
            if (tempToken.getLexType() == LexType.LPARENT) { // TODO unsure
                ExpStmt expStmt = parseExpStmt(false);

                this.parseOut.add(expStmt.returnSymbolType());

                return expStmt;
            } else {
                this.lVal = parseLVal(); // special condition TODO change it
                if (curToken.getLexType() == LexType.ASSIGN) {
                    tempToken = forwardToken();
                    if (tempToken.getLexType() == LexType.GETINTTK) {
                        return parseLGetint();
                    } else if (tempToken.getLexType() == LexType.GETCHARTK) {
                        return parseLGetchar();
                    } else {
                        return parseLEStmt();
                    }
                } else {
                    ExpStmt expStmt = parseExpStmt(true);
                    this.parseOut.add(expStmt.returnSymbolType());
                    return expStmt;
                }
            }
        }
        return null;
    }

    private LEStmt parseLEStmt() {
        LEStmt stmt = new LEStmt();
        stmt.setlVal(this.lVal);
        match(curToken, LexType.ASSIGN);
        Exp exp = parseExp(false);
        stmt.setExp(exp);
        if (curToken.getLexType() == LexType.SEMICN) {
            match(curToken, LexType.SEMICN);
        } else {
            MyError error = new MyError(oldToken.getLine(), ErrorType.i);
            errors.setErrors(error);
        }

        this.parseOut.add(stmt.returnSymbolType());

        return stmt;
    }

    private ExpStmt parseExpStmt(boolean isLval) { // TODO LVal is the first apartment
        ExpStmt expStmt = new ExpStmt();
        Exp exp = parseExp(isLval);

        expStmt.setExp(exp);
        if (curToken.getLexType() == LexType.SEMICN) {
            match(curToken, LexType.SEMICN);
        } else {
            MyError error = new MyError(oldToken.getLine(), ErrorType.i);
            this.errors.setErrors(error);
        }

        return expStmt;
    }


    private BlockStmt parseBlockStmt() {
        BlockStmt blockStmt = new BlockStmt();

        Block block = parseBlock();

        blockStmt.setBlock(block);

        return blockStmt;
    }

    private IfStmt parseIfStmt() {
        IfStmt ifStmt = new IfStmt();

        match(curToken, LexType.IFTK);
        match(curToken, LexType.LPARENT);
        Cond cond = parseCond();

        ifStmt.setCond(cond);
        if (curToken.getLexType() == LexType.RPARENT) {
            match(curToken, LexType.RPARENT);
        } else {
            MyError error = new MyError(oldToken.getLine(), ErrorType.j);
            errors.setErrors(error);
        }
        Stmt stmt1 = parseStmt();
        ifStmt.setStmt1(stmt1);
        if (curToken.getLexType() == LexType.ELSETK) {
            match(curToken, LexType.ELSETK);
            Stmt stmt2 = parseStmt();
            ifStmt.setStmt2(stmt2);
        }


        return ifStmt;
    }

    private ForStmt parseForStmt() {
        ForStmt forStmt = new ForStmt();

        match(curToken, LexType.FORTK);
        match(curToken, LexType.LPARENT);
        if (curToken.getLexType() != LexType.SEMICN) {
            FirstForStmt firstForStmt = parseFirstForStmt();
            forStmt.setFirstForStmt(firstForStmt);
        }
        match(curToken, LexType.SEMICN);
        if (curToken.getLexType() != LexType.SEMICN) {
            Cond cond = parseCond();
            forStmt.setCond(cond);
        }
        match(curToken, LexType.SEMICN);
        if (curToken.getLexType() != LexType.RPARENT) {
            FirstForStmt forStmt2 = parseFirstForStmt();
            forStmt.setForStmt2(forStmt2);
        }
        match(curToken, LexType.RPARENT);
        Stmt stmt = parseStmt();
        forStmt.setStmt(stmt);


        return forStmt;

    }

    private FirstForStmt parseFirstForStmt() {
        FirstForStmt firstForStmt = new FirstForStmt();
        LVal lVal1 = parseLVal();
        firstForStmt.setlVal(lVal1);
        match(curToken, LexType.ASSIGN);
        Exp exp = parseExp(false);
        firstForStmt.setExp(exp);

        this.parseOut.add(firstForStmt.returnSymbolType());
        return firstForStmt;
    }

    private BreakStmt parseBreakStmt() {
        BreakStmt breakStmt = new BreakStmt();

        match(curToken, LexType.BREAKTK);
        if (curToken.getLexType() == LexType.SEMICN) {
            match(curToken, LexType.SEMICN);
        } else {
            MyError error = new MyError(oldToken.getLine(), ErrorType.i);
            errors.setErrors(error);
        }

        return breakStmt;
    }

    private ContinueStmt parseContinueStmt() {
        ContinueStmt continueStmt = new ContinueStmt();
        match(curToken, LexType.CONTINUETK);
        if (curToken.getLexType() == LexType.SEMICN) {
            match(curToken, LexType.SEMICN);
        } else {
            MyError error = new MyError(oldToken.getLine(), ErrorType.i);
            errors.setErrors(error);
        }

        return continueStmt;
    }

    private ReturnStmt parseReturnStmt() {
        ReturnStmt returnStmt = new ReturnStmt();

        match(curToken, LexType.RETURNTK);
        if (firstExpPart(curToken) || curToken.getLexType() == LexType.IDENFR) {
            Exp exp = parseExp(false);
            returnStmt.setExp(exp);
        }
        if (curToken.getLexType() != LexType.SEMICN) {
            MyError error = new MyError(oldToken.getLine(), ErrorType.i);
            errors.setErrors(error);
        } else {
            match(curToken, LexType.SEMICN);
        }

        return returnStmt;
    }

    private LGetint parseLGetint() {
        LGetint lGetint = new LGetint();
        lGetint.setlVal(this.lVal);
        match(curToken, LexType.ASSIGN);
        match(curToken, LexType.GETINTTK);
        match(curToken, LexType.LPARENT);
        if (curToken.getLexType() != LexType.RPARENT) {
            MyError error = new MyError(oldToken.getLine(), ErrorType.j);
            errors.setErrors(error);
        } else {
            match(curToken, LexType.RPARENT);
        }
        if (curToken.getLexType() != LexType.SEMICN) {
            dealError(ErrorType.i);
        } else {
            match(curToken, LexType.SEMICN);
        }

        this.parseOut.add(lGetint.returnSymbolType());
        return lGetint;
    }

    private LGetchar parseLGetchar() { // TODO have param
        LGetchar lGetchar = new LGetchar();
        lGetchar.setlVal(this.lVal);
        match(curToken, LexType.ASSIGN);
        match(curToken, LexType.GETCHARTK);
        match(curToken, LexType.LPARENT);
        if (curToken.getLexType() != LexType.RPARENT) {
            MyError error = new MyError(oldToken.getLine(), ErrorType.j);
            errors.setErrors(error);
        } else {
            match(curToken, LexType.RPARENT);
        }
        if (curToken.getLexType() != LexType.SEMICN) {
            dealError(ErrorType.i);
        } else {
            match(curToken, LexType.SEMICN);
        }
        this.parseOut.add(lGetchar.returnSymbolType());
        return lGetchar;
    }

    private PrintfStmt parsePrintfStmt() {
        PrintfStmt printfStmt = new PrintfStmt();

        match(curToken, LexType.PRINTFTK);
        match(curToken, LexType.LPARENT);
        printfStmt.setString(curToken.getName());
        match(curToken, LexType.STRCON);
        while (curToken.getLexType() == LexType.COMMA) {
            match(curToken, LexType.COMMA);
            Exp exp = parseExp(false);
            printfStmt.setExps(exp);
        }
        if (curToken.getLexType() != LexType.RPARENT) {
            dealError(ErrorType.j);
        } else {
            match(curToken, LexType.RPARENT);
        }
        if (curToken.getLexType() != LexType.SEMICN) {
            dealError(ErrorType.i);
        } else {
            match(curToken, LexType.SEMICN);
        }

        return printfStmt;
    }

    private Cond parseCond() {
        LOrExp lOrExp = parseLOrExp();

        Cond cond = new Cond(lOrExp);

        this.parseOut.add(cond.returnSymbolType());
        return cond;
    }


    private LVal parseLVal() {
        LVal lVal1 = new LVal();
        lVal1.setName(curToken);
        match(curToken, LexType.IDENFR);
        if (curToken.getLexType() == LexType.LBRACK) {
            match(curToken, LexType.LBRACK);
            Exp exp = parseExp(false);
            lVal1.setExp(exp);
            if (curToken.getLexType() == LexType.RBRACK) {
                match(curToken, LexType.RBRACK);
            } else {
                dealError(ErrorType.k);
            }
        }

        this.parseOut.add(lVal1.returnSymbolType());

        return lVal1;
    }


    private Exp parseExp(boolean isLval) {
        Exp exp = new Exp();
        AddExp addExp = parseAddExp(false, isLval);
        exp.setAddExp(addExp);

        this.parseOut.add(exp.returnSymbolType());

        return exp;
    }

    private ConstExp parseConstExp() {  // notice
        AddExp addExp = parseAddExp(false, false);

        ConstExp constExp = new ConstExp(addExp);

        this.parseOut.add(constExp.returnSymbolType());
        return constExp;
    }

    private AddExp parseAddExp(boolean type, boolean isLval) {
        AddExp addExp = new AddExp();
        MulExp mulExp = parseMulExp(type, isLval);
        addExp.setMulExps(mulExp);

        this.parseOut.add(addExp.returnSymbolType());
        while (curToken.getLexType() == LexType.PLUS || curToken.getLexType() == LexType.MINU) {
            AddExp addExp1 = new AddExp();
            if (curToken.getLexType() == LexType.PLUS) {
                match(curToken, LexType.PLUS);
                addExp1.setOps("+");
            } else if (curToken.getLexType() == LexType.MINU) {
                match(curToken, LexType.MINU);
                addExp1.setOps("-");
            }
            mulExp = parseMulExp(type, false);
            addExp1.setMulExps(mulExp);
            addExp1.setAddExp(addExp);

            addExp = addExp1;
            this.parseOut.add(addExp1.returnSymbolType());
        }

        //this.parseOut.add(addExp.returnSymbolType());

        return addExp;

    }

    private MulExp parseMulExp(boolean type, boolean isLval) {
        MulExp mulExp = new MulExp();
        UnaryExp unaryExp = parseUnaryExp(type, isLval);
        mulExp.setUnaryExps(unaryExp);
        this.parseOut.add(mulExp.returnSymbolType());
        while (judgeMulExp(curToken)) {
            MulExp mulExp1 = new MulExp();
            if (curToken.getLexType() == LexType.MULT) {
                mulExp1.setOps("*");
                match(curToken, LexType.MULT);
            } else if (curToken.getLexType() == LexType.DIV) {
                mulExp1.setOps("/");
                match(curToken, LexType.DIV);
            } else if (curToken.getLexType() == LexType.MOD) {
                mulExp1.setOps("%");
                match(curToken, LexType.MOD);
            }
            unaryExp = parseUnaryExp(type, false); // TODO forwardLook maybe error
            mulExp1.setUnaryExps(unaryExp);
            mulExp1.setMulExp(mulExp);
            mulExp = mulExp1;

            this.parseOut.add(mulExp1.returnSymbolType());
        }

        //this.parseOut.add(mulExp.returnSymbolType());

        return mulExp;
    }

    private UnaryExp parseUnaryExp(boolean type, boolean isLval) {
        if (isLval) {
            PrimaryExp primaryExp = parsePrimaryExp(type, isLval);
            UnaryPrimaryExp unaryPrimaryExp = new UnaryPrimaryExp();

            unaryPrimaryExp.setPrimaryExp(primaryExp);
            this.parseOut.add(unaryPrimaryExp.returnSymbolType());

            return unaryPrimaryExp;
        }

        if (curToken.getLexType() == LexType.LPARENT || curToken.getLexType() == LexType.INTCON ||
                curToken.getLexType() == LexType.CHRCON) {
            PrimaryExp primaryExp = parsePrimaryExp(type, false);
            UnaryPrimaryExp unaryPrimaryExp = new UnaryPrimaryExp();

            unaryPrimaryExp.setPrimaryExp(primaryExp);
            this.parseOut.add(unaryPrimaryExp.returnSymbolType());
            return unaryPrimaryExp;
        } else if (judgeUnaryOpFirst(curToken, type)) {
            OpUnaryExp opUnaryExp = parseOpUnaryExp(type);

            this.parseOut.add(opUnaryExp.returnSymbolType());
            return opUnaryExp;
        } else if (curToken.getLexType() == LexType.IDENFR) {
            if (!buffer.isEmpty()) {
                if (buffer.element().getLexType() == LexType.LPARENT) {
                    FuncUExp funcUExp = parseFuncUExp();

                    this.parseOut.add(funcUExp.returnSymbolType());
                    return funcUExp;
                } else {
                    PrimaryExp primaryExp = parsePrimaryExp(type, false);
                    UnaryPrimaryExp unaryPrimaryExp = new UnaryPrimaryExp();
                    unaryPrimaryExp.setPrimaryExp(primaryExp);
                    this.parseOut.add(unaryPrimaryExp.returnSymbolType());
                    return unaryPrimaryExp;
                }
            } else {
                Token temp = forwardToken();
                if (temp.getLexType() == LexType.LPARENT) {
                    FuncUExp funcUExp = parseFuncUExp();

                    this.parseOut.add(funcUExp.returnSymbolType());
                    return funcUExp;
                } else {
                    PrimaryExp primaryExp = parsePrimaryExp(type, false);

                    UnaryPrimaryExp unaryPrimaryExp = new UnaryPrimaryExp();
                    unaryPrimaryExp.setPrimaryExp(primaryExp);
                    this.parseOut.add(unaryPrimaryExp.returnSymbolType());
                    return unaryPrimaryExp;
                }
            }
        } else {
            System.out.println("UnaryExp error");
            return null;
        }
    }

    private OpUnaryExp parseOpUnaryExp(boolean type) {
        ArrayList<String> ops = new ArrayList<>();
        while (judgeUnaryOpFirst(curToken, type)) {
            ops.add(parseUnaryOp().get(0));
        }
        UnaryExp unaryExp = parseUnaryExp(type, false);


        OpUnaryExp opUnaryExp = new OpUnaryExp(ops, unaryExp);

        for (int i = 0; i < ops.size() - 1; i++) {
            this.parseOut.add(opUnaryExp.returnSymbolType());
        }

        return opUnaryExp;
    }

    private ArrayList<String> parseUnaryOp() {
        ArrayList<String> ops = new ArrayList<>();
        if (curToken.getLexType() == LexType.PLUS) {
            match(curToken, LexType.PLUS);
            ops.add("+");
        } else if (curToken.getLexType() == LexType.MINU) {
            match(curToken, LexType.MINU);
            ops.add("-");
        } else if (curToken.getLexType() == LexType.NOT) {
            match(curToken, LexType.NOT);
            ops.add("!");
        }
        this.parseOut.add("<UnaryOp>");

        return ops;
    }

    private FuncUExp parseFuncUExp() {  // 函数使用
        Token token;
        FuncRParams funcRParams;
        FuncUExp funcUExp;
        token = curToken;
        match(curToken, LexType.IDENFR);
        match(curToken, LexType.LPARENT);
        if (firstExpPart(curToken) || curToken.getLexType() == LexType.IDENFR) {
            funcRParams = parseFuncRParams();
            funcUExp = new FuncUExp(token, funcRParams);
        } else {
            funcUExp = new FuncUExp(token);
        }
        if (curToken.getLexType() != LexType.RPARENT) {
            dealError(ErrorType.j);
        } else {
            match(curToken, LexType.RPARENT);
        }

        return funcUExp;
    }

    private FuncRParams parseFuncRParams() {
        FuncRParams funcRParams = new FuncRParams();
        Exp exp = parseExp(false);
        funcRParams.setExps(exp);
        while (curToken.getLexType() == LexType.COMMA) {
            match(curToken, LexType.COMMA);
            exp = parseExp(false);
            funcRParams.setExps(exp);
        }

        this.parseOut.add(funcRParams.returnSymbolType());
        return funcRParams;
    }

    private PrimaryExp parsePrimaryExp(boolean type, boolean isLval) {
        if (isLval) {
            PrimaryLVal primaryLVal = new PrimaryLVal();
            primaryLVal.setlVal(this.lVal);

            this.parseOut.add(primaryLVal.returnSymbolType());
            return primaryLVal;
        }
        if (curToken.getLexType() == LexType.LPARENT) {
            PrimaryExpExp expExp = new PrimaryExpExp();
            match(curToken, LexType.LPARENT);
            Exp exp = parseExp(false); // TODO maybe another Exp
            expExp.setExp(exp);
            if (curToken.getLexType() != LexType.RPARENT) {
                dealError(ErrorType.j);
            } else {
                match(curToken, LexType.RPARENT);
            }

            this.parseOut.add(expExp.returnSymbolType());
            return expExp;
        } else if (curToken.getLexType() == LexType.IDENFR) {
            PrimaryLVal primaryLVal = new PrimaryLVal();
            LVal lVal1 = parseLVal();
            primaryLVal.setlVal(lVal1);

            this.parseOut.add(primaryLVal.returnSymbolType());
            return primaryLVal;
        } else if (curToken.getLexType() == LexType.INTCON) {
            MyNumber myNumber = parseNumber();

            this.parseOut.add("<PrimaryExp>");
            return myNumber;
        } else if (curToken.getLexType() == LexType.CHRCON) {
            MyCharacter myCharacter = parseCharacter();

            this.parseOut.add("<PrimaryExp>");
            return myCharacter;
        }
        return null;
    }

    private MyNumber parseNumber() {
        MyNumber myNumber = new MyNumber(curToken);
        match(curToken, LexType.INTCON);

        this.parseOut.add(myNumber.returnSymbolType());
        return myNumber;
    }

    private MyCharacter parseCharacter() {
        MyCharacter myCharacter = new MyCharacter(curToken);
        match(curToken, LexType.CHRCON);

        this.parseOut.add(myCharacter.returnSymbolType());
        return myCharacter;
    }

    private LOrExp parseLOrExp() {
        LOrExp lOrExp = new LOrExp();
        LAndExp lAndExp = parseLAndExp();
        lOrExp.addLAndExp(lAndExp);
        this.parseOut.add(lOrExp.returnSymbolType());
        while (curToken.getLexType() == LexType.OR) {
            LOrExp lOrExp1 = new LOrExp();
            match(curToken, LexType.OR);
            lAndExp = parseLAndExp();
            lOrExp1.addLAndExp(lAndExp);
            lOrExp1.setlOrExp(lOrExp);

            lOrExp = lOrExp1;
            this.parseOut.add(lOrExp1.returnSymbolType());
        }

        //this.parseOut.add(lOrExp.returnSymbolType());
        return lOrExp;
    }

    private LAndExp parseLAndExp() {
        LAndExp lAndExp = new LAndExp();
        EqExp exp = parseEqExp();
        lAndExp.setEqExps(exp);
        this.parseOut.add(lAndExp.returnSymbolType());
        while (curToken.getLexType() == LexType.AND) {
            LAndExp lAndExp1 = new LAndExp();
            match(curToken, LexType.AND);
            exp = parseEqExp();
            lAndExp1.setEqExps(exp);
            lAndExp1.setlAndExp(lAndExp);
            lAndExp = lAndExp1;

            this.parseOut.add(lAndExp1.returnSymbolType());
        }

        //this.parseOut.add(lAndExp.returnSymbolType());
        return lAndExp;

    }

    private EqExp parseEqExp() {
        EqExp eqExp = new EqExp();
        RelExp relExp = parseRelExp();
        eqExp.setRelExps(relExp);
        this.parseOut.add(eqExp.returnSymbolType());
        while (curToken.getLexType() == LexType.EQL || curToken.getLexType() == LexType.NEQ) {
            EqExp eqExp1 = new EqExp();
            if (curToken.getLexType() == LexType.EQL) {
                match(curToken, LexType.EQL);
                eqExp1.setOps("==");
            } else if (curToken.getLexType() == LexType.NEQ) {
                match(curToken, LexType.NEQ);
                eqExp1.setOps("!=");
            }
            relExp = parseRelExp();
            eqExp1.setRelExps(relExp);
            eqExp1.setEqExp(eqExp);

            eqExp = eqExp1;
            this.parseOut.add(eqExp1.returnSymbolType());
        }

        //this.parseOut.add(eqExp.returnSymbolType());
        return eqExp;

    }

    private RelExp parseRelExp() {
        RelExp relExp = new RelExp();
        AddExp addExp = parseAddExp(true, false);
        relExp.setAddExps(addExp);

        this.parseOut.add(relExp.returnSymbolType());

        while (curToken.getLexType() == LexType.LSS || curToken.getLexType() == LexType.GRE
                || curToken.getLexType() == LexType.LEQ || curToken.getLexType() == LexType.GEQ) {
            RelExp relExp1 = new RelExp();
            if (curToken.getLexType() == LexType.LSS) {
                relExp1.setOps("<");
                match(curToken, LexType.LSS);
            } else if (curToken.getLexType() == LexType.GRE) {
                relExp1.setOps(">");
                match(curToken, LexType.GRE);
            } else if (curToken.getLexType() == LexType.LEQ) {
                relExp1.setOps("<=");
                match(curToken, LexType.LEQ);
            } else if (curToken.getLexType() == LexType.GEQ) {
                relExp1.setOps(">=");
                match(curToken, LexType.GEQ);
            }
            addExp = parseAddExp(true, false);
            relExp1.setAddExps(addExp);
            relExp1.setRelExp(relExp);

            relExp = relExp1;

            this.parseOut.add(relExp1.returnSymbolType());
        }

        //this.parseOut.add(relExp.returnSymbolType());
        return relExp;
    }

    private boolean firstExpPart(Token token) {
        if (token.getLexType() == LexType.PLUS || token.getLexType() == LexType.MINU
                || token.getLexType() == LexType.LPARENT || token.getLexType() == LexType.CHRCON
                || token.getLexType() == LexType.INTCON) {
            return true;
        } else {
            return false;
        }
    }

    private void getNextToken() {
        if (buffer.isEmpty()) {
            if (lexer.getArriveEnd()) {
                Token token = new Token(LexType.ISEND, "error", -1);
                oldToken = curToken;
                curToken = token;
            } else {
                lexer.next();
                oldToken = curToken;
                curToken = lexer.getNewToken();
            }
        } else {
            oldToken = curToken;
            curToken = buffer.poll();
        }
        this.parseOut.add(oldToken.getLexType() + " " + oldToken.getName());
    }

    private Token forwardToken() {
        Token tempToken;
        lexer.next();
        tempToken = lexer.getNewToken();
        buffer.offer(tempToken);
        return tempToken;
    }

    private boolean match(Token token, LexType lexType) {
        if (token.getLexType() != lexType) {
            System.out.println("haha");
            return false;
        } else {
            getNextToken();
            return true;
        }
    }

    private boolean judgeMulExp(Token token) {
        if (token.getLexType() == LexType.MULT || token.getLexType() == LexType.DIV
                || token.getLexType() == LexType.MOD) {
            return true;
        }
        return false;
    }

    private boolean judgeUnaryOpFirst(Token token, Boolean all) {
        if (all) {
            if (token.getLexType() == LexType.PLUS || token.getLexType() == LexType.MINU
                    || token.getLexType() == LexType.NOT) {
                return true;
            } else {
                return false;
            }
        } else {
            if (token.getLexType() == LexType.PLUS || token.getLexType() == LexType.MINU) {
                return true;
            } else {
                return false;
            }
        }
    }

    private void dealError(ErrorType errorType) {
        MyError error = new MyError(oldToken.getLine(), errorType);
        errors.setErrors(error);
    }

    public ArrayList<String> getParseOut() {
        return this.parseOut;
    }
}

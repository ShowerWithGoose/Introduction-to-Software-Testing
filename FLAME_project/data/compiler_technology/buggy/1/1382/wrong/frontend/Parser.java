package frontend;

import frontend.SyntaxUnits.*;
import frontend.SyntaxUnits.ConstInits.ConstExps;
import frontend.SyntaxUnits.ConstInits.StringCon;
import frontend.SyntaxUnits.Exps.*;
import frontend.SyntaxUnits.Exps.Character;
import frontend.SyntaxUnits.Exps.Number;
import frontend.SyntaxUnits.StmtUnits.*;
import frontend.SyntaxUnits.VarInits.InitExps;
import frontend.SyntaxUnits.VarInits.InitString;

import java.util.ArrayList;

public class Parser {
    private final ErrorList errorList;
    private final TokenIterator tokenIterator;
    private CompUnit compUnit;
    private boolean fakeMode;
    private int step;

    public Parser(ErrorList errorList, TokenIterator tokenIterator) {
        this.errorList = errorList;
        this.tokenIterator = tokenIterator;
        fakeMode = false;
        step = 0;
        parserScan();
    }

    public CompUnit getCompUnit() {
        return compUnit;
    }

    private void switchFake(boolean fakeMode) {
        this.fakeMode = fakeMode;
        step = 0;
    }

    private void parserScan() {
        ArrayList<Decl>  decls = declsParser();
        ArrayList<FuncDef> funcDefs = funcDefsParser();
        MainFuncDef mainFuncDef = mainFuncDefParser();
        compUnit = new CompUnit(decls, funcDefs, mainFuncDef);
        System.out.println(compUnit.toPrint());//
    }

    private ArrayList<Decl> declsParser()  {
        ArrayList<Decl> decls = new ArrayList<>();
        Token pos1 = tokenIterator.getNext();
        Token pos2 = tokenIterator.getNext();
        Token pos3 = tokenIterator.getNext();
        while (tokenIterator.hasNext()) {
            if (pos3.getLexType().equals(LexType.LPARENT)) {
                tokenIterator.getBack(3);
                return decls;
            }
            else {
                if (pos1.getLexType().equals(LexType.CONSTTK)
                        || ((pos1.getLexType().equals(LexType.INTTK)
                        || pos1.getLexType().equals(LexType.CHARTK))
                        && (pos2.getLexType().equals(LexType.IDENFR)))) {
                    tokenIterator.getBack(3);
                    Decl decl = declParser();
                    decls.add(decl);
                }
                else {
                    tokenIterator.getBack(3);//error
                    break;
                }
            }
            pos1 = tokenIterator.getNext();
            pos2 = tokenIterator.getNext();
            pos3 = tokenIterator.getNext();
        }
        return decls;
    }

    private Decl declParser() {
        Token pos1 = tokenIterator.getNext();
        if (pos1.getLexType().equals(LexType.CONSTTK)) {
            ConstDecl constDecl = constDeclParser();
            return new Decl(constDecl);
        }
        else {
            tokenIterator.getPrevious();
            VarDecl varDecl = varDeclParser();
            return new Decl(varDecl);
        }
    }

    private VarDecl varDeclParser() {
        Token pos1 = tokenIterator.getNext();
        //pos1.getLexType().equals(LexType.CHARTK) || pos1.getLexType().equals(LexType.INTTK)
        BType bType = new BType(pos1);
        ArrayList<VarDef> varDefs = varDefsParser();
        return new VarDecl(varDefs, bType);
    }

    private ArrayList<VarDef> varDefsParser() {
        ArrayList<VarDef> varDefs = new ArrayList<>();
        VarDef varDef0 = varDefParser();
        varDefs.add(varDef0);
        Token pos1 = tokenIterator.getNext();
        while (pos1.getLexType().equals(LexType.COMMA)) {
            VarDef varDef = varDefParser();
            varDefs.add(varDef);
            pos1 = tokenIterator.getNext();
        }
        if (! pos1.getLexType().equals(LexType.SEMICN)) {
            addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
        }
        return varDefs;
    }

    private VarDef varDefParser() {
        Token pos1 = tokenIterator.getNext();
        Token ident = pos1;
        pos1 = tokenIterator.getNext();
        if (pos1.getLexType().equals(LexType.ASSIGN)) {
            InitVal initVal = initValParser();
            return new VarDef(ident, initVal);
        }
        else if (pos1.getLexType().equals(LexType.LBRACK)) {
            ConstExp constExp = constExpParser();
            if (! tokenIterator.getNext().getLexType().equals(LexType.RBRACK)) {
                addErrorK(tokenIterator.getPrevious().getLineNum());//k  error
            }
            if (tokenIterator.getNext().getLexType().equals(LexType.ASSIGN)) {
                InitVal initVal = initValParser();
                return new VarDef(ident, constExp, initVal);
            }
            else {
                tokenIterator.getPrevious();
                return new VarDef(ident,  constExp);
            }
        }
        else {
            tokenIterator.getPrevious();
            return new VarDef(ident);
        }
    }

    private InitVal  initValParser() {
        Token pos1 = tokenIterator.getNext();
        if (pos1.getLexType().equals(LexType.STRCON)) {
            return new InitVal(new InitString(pos1));
        }
        else if (pos1.getLexType().equals(LexType.LBRACE)) {
            ArrayList<Exp> exps = new ArrayList<>();
            pos1 = tokenIterator.getNext();
            if (! pos1.getLexType().equals(LexType.RBRACE)) {
                pos1 = tokenIterator.getPrevious();
                Exp exp0 = expParser();
                exps.add(exp0);
                pos1 = tokenIterator.getNext();
                while (pos1.getLexType().equals(LexType.COMMA)) {
                    Exp exp = expParser();
                    exps.add(exp);
                    pos1 = tokenIterator.getNext();
                }
            }
            return new InitVal(new InitExps(exps));
        }
        else {
            tokenIterator.getPrevious();
            Exp exp = expParser();
            return new InitVal(exp);
        }
    }

    private ConstDecl constDeclParser() {
        Token pos1 = tokenIterator.getNext();
        //pos1.getLexType().equals(LexType.CHARTK) || pos1.getLexType().equals(LexType.INTTK)
        BType bType = new BType(pos1);
        ArrayList<ConstDef> constDefs = constDefsParser();
        return new ConstDecl(constDefs, bType);
    }

    private ArrayList<ConstDef> constDefsParser() {
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        ConstDef constDef0 = constDefParer();
        constDefs.add(constDef0);
        Token pos1 = tokenIterator.getNext();
        while (pos1.getLexType().equals(LexType.COMMA)) {
            ConstDef constDef = constDefParer();
            constDefs.add(constDef);
            pos1 = tokenIterator.getNext();
        }
        if (! pos1.getLexType().equals(LexType.SEMICN)) {
            addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
        }
        return constDefs;
    }

    private ConstDef constDefParer() {
        Token pos1 = tokenIterator.getNext();
        Token ident = pos1;
        pos1 = tokenIterator.getNext();
        if (pos1.getLexType().equals(LexType.LBRACK))  {
            ConstExp constExp = constExpParser();
            pos1 = tokenIterator.getNext();
            if (! pos1.getLexType().equals(LexType.RBRACK)) {
                addErrorK(tokenIterator.getPrevious().getLineNum());//k  error
            }
            tokenIterator.getNext();
            ConstInitVal constInitVal = constInitValParser();
            return new ConstDef(ident, constExp, constInitVal);
        }
        else {
            ConstInitVal constInitVal = constInitValParser();
            return new ConstDef(ident, constInitVal);
        }
    }

    private ConstInitVal constInitValParser() {
        Token pos1 = tokenIterator.getNext();
        if (pos1.getLexType().equals(LexType.STRCON)) {
            return new ConstInitVal(new StringCon(pos1));
        }
        else if (pos1.getLexType().equals(LexType.LBRACE)) {
            ArrayList<ConstExp> constExps = new ArrayList<>();
            pos1 = tokenIterator.getNext();
            if (! pos1.getLexType().equals(LexType.RBRACE)) {
                pos1 = tokenIterator.getPrevious();
                ConstExp constExp0 = constExpParser();
                constExps.add(constExp0);
                pos1 = tokenIterator.getNext();
                while (pos1.getLexType().equals(LexType.COMMA)) {
                    ConstExp constExp = constExpParser();
                    constExps.add(constExp);
                    pos1 = tokenIterator.getNext();
                }
            }
            return new ConstInitVal(new ConstExps(constExps));
        }
        else {
            tokenIterator.getPrevious();
            ConstExp constExp = constExpParser();
            return new ConstInitVal(constExp);
        }
    }

    private ConstExp constExpParser() {
        AddExp addExp = addExpParser();
        return new ConstExp(addExp);
    }

    private ArrayList<FuncDef> funcDefsParser()  {
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        Token pos1 = tokenIterator.getNext();
        Token pos2 = tokenIterator.getNext();
        while (tokenIterator.hasNext()) {
            if (pos2.getLexType().equals(LexType.MAINTK)) {
                tokenIterator.getBack(2);
                return funcDefs;
            }
            else {
                tokenIterator.getBack(2);
                FuncType funcType = funcTypeParser();
                Token ident = tokenIterator.getNext();
                tokenIterator.getNext();
                Token pos3 = tokenIterator.getNext();
                if (pos3.getLexType().equals(LexType.RPARENT)) {
                    Block block = blockParser();
                    FuncDef funcDef = new FuncDef(funcType, ident, block);
                    funcDefs.add(funcDef);
                }
                else if (pos3.getLexType().equals(LexType.LBRACE)) {
                    addErrorJ(tokenIterator.getPrevious().getLineNum());//j  error
                    Block block = blockParser();
                    FuncDef funcDef = new FuncDef(funcType, ident, block);
                    funcDefs.add(funcDef);
                }
                else {
                    tokenIterator.getPrevious();
                    FuncFParams funcFParams = funcFParamsParser();
                    if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                        addErrorJ(tokenIterator.getPrevious().getLineNum());//j  error
                    }
                    Block block = blockParser();
                    FuncDef funcDef = new FuncDef(funcType, ident, funcFParams, block);
                    funcDefs.add(funcDef);
                }
            }
            pos1 = tokenIterator.getNext();
            pos2 = tokenIterator.getNext();
        }
        return funcDefs;
    }

    private FuncType funcTypeParser() {
        return new FuncType(tokenIterator.getNext());
    }

    private MainFuncDef mainFuncDefParser() {
        Token pos1 = tokenIterator.getNext();
        if (! pos1.getLexType().equals(LexType.INTTK)) {
            return null;
        }
        Token pos2 = tokenIterator.getNext();
        Token pos3 = tokenIterator.getNext();
        Token pos4 = tokenIterator.getNext();
        /*
        pos1.getLexType().equals(LexType.INTTK);
        pos2.getLexType().equals(LexType.MAINTK);
        pos3.getLexType().equals(LexType.LPARENT);
        pos4.getLexType().equals(LexType.RPARENT);
         */
        if (! pos4.getLexType().equals(LexType.RPARENT)) {
            addErrorJ(tokenIterator.getPrevious().getLineNum());//j  error
        }
        Block block = blockParser();
        return new MainFuncDef(block);
    }

    private Block blockParser() {
        Token pos1 = tokenIterator.getNext();
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        if (pos1.getLexType().equals(LexType.RBRACE))  {
            return new Block(blockItems);
        }
        pos1 = tokenIterator.getNext();
        while (! pos1.getLexType().equals(LexType.RBRACE)) {
            if (pos1.getLexType().equals(LexType.INTTK)
                    || pos1.getLexType().equals(LexType.CHARTK)
                    || pos1.getLexType().equals(LexType.CONSTTK)) {
                tokenIterator.getPrevious();
                Decl decl = declParser();
                BlockItem blockItem = new BlockItem(decl);
                blockItems.add(blockItem);
            }
            else {
                tokenIterator.getPrevious();
                Stmt  stmt = stmtParser();
                BlockItem blockItem = new BlockItem(stmt);
                blockItems.add(blockItem);
            }
            pos1 = tokenIterator.getNext();
        }
        return new Block(blockItems);
    }

    private Stmt stmtParser() {
        Token pos1 = tokenIterator.getNext();
        switch (pos1.getLexType()) {
            case IFTK: {
                tokenIterator.getNext();
                Cond cond = condParser();
                if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                    addErrorJ(tokenIterator.getPrevious().getLineNum());//j  error
                }
                Stmt stmt = stmtParser();
                if (tokenIterator.getNext().getLexType().equals(LexType.ELSETK)) {
                    Stmt elseStmt = stmtParser();
                    return new Stmt(new IfElseStmt(cond, stmt, elseStmt));
                }
                else {
                    tokenIterator.getPrevious();
                    return new Stmt(new IfElseStmt(cond, stmt));
                }
            }
            case FORTK:  {
                return new Stmt(forBlockStmtParser());
            }
            case BREAKTK: {
                if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                    addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                }
                return new Stmt(new BreakStmt());
            }
            case CONTINUETK: {
                if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                    addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                }
                return new Stmt(new ContinueStmt());
            }
            case RETURNTK: {
                if (tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                    return new Stmt(new ReturnStmt());
                }
                else {
                    tokenIterator.getPrevious();
                    if (CheckReturnError()) {
                        addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                        return new Stmt(new ReturnStmt());
                    }
                    else {
                        Exp exp = expParser();
                        if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                            addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                        }
                        return new Stmt(new ReturnStmt(exp));
                    }
                }

            }
            case PRINTFTK: {
                tokenIterator.getNext();
                Token string = tokenIterator.getNext();
                pos1 = tokenIterator.getNext();
                ArrayList<Exp> exps = new ArrayList<>();
                while (pos1.getLexType().equals(LexType.COMMA)) {
                    Exp exp = expParser();
                    exps.add(exp);
                    pos1 = tokenIterator.getNext();
                }
                if (! pos1.getLexType().equals(LexType.RPARENT)) {
                    pos1 = tokenIterator.getPrevious();
                    addErrorJ(pos1.getLineNum());//j  error
                }
                if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                    addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                }
                if (exps.isEmpty()) {
                    return new Stmt(new PrintfStmt(string));
                }
                else {
                    return new Stmt(new PrintfStmt(string, exps));
                }
            }
            case LBRACE: {
                tokenIterator.getPrevious();
                Block block = blockParser();
                return new Stmt(new BlockStmt(block));
            }
            case IDENFR: {
                tokenIterator.getPrevious();
                switchFake(true);
                lValParser();
                if (tokenIterator.getNext().getLexType().equals(LexType.ASSIGN)) {
                    tokenIterator.getBack(step + 1);
                    switchFake(false);
                    LVal lVal = lValParser();
                    tokenIterator.getNext();
                    pos1 = tokenIterator.getNext();
                    if (pos1.getLexType().equals(LexType.GETINTTK)) {
                        tokenIterator.getNext();
                        if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                            addErrorJ(tokenIterator.getPrevious().getLineNum());//j  error
                        }
                        if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                            addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                        }
                        return new Stmt(new getIntStmt(lVal));
                    }
                    else if (pos1.getLexType().equals(LexType.GETCHARTK)) {
                        tokenIterator.getNext();
                        if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                            addErrorJ(tokenIterator.getPrevious().getLineNum());//j  error
                        }
                        if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                            addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                        }
                        return new Stmt(new getCharStmt(lVal));
                    }
                    else {
                        tokenIterator.getPrevious();
                        Exp exp = expParser();
                        if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                            addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                        }
                        return new Stmt(new AssignStmt(lVal,  exp));
                    }
                }
                else {
                    tokenIterator.getBack(step + 1);
                    switchFake(false);
                    Exp exp = expParser();
                    if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                        addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                    }
                    return new Stmt(new ExpStmt(exp));
                }
            }
            case SEMICN: {
                return new Stmt(new ExpStmt());
            }
            default: {
                tokenIterator.getPrevious();
                Exp exp = expParser();
                if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                    addErrorI(tokenIterator.getPrevious().getLineNum());//i  error
                }
                return new Stmt(new ExpStmt(exp));
            }
        }
    }

    private boolean CheckReturnError() {
        Token pos1 = tokenIterator.getNext();
        if (pos1.getLexType().equals(LexType.BREAKTK)
                || pos1.getLexType().equals(LexType.IFTK)
                || pos1.getLexType().equals(LexType.CONTINUETK)
                || pos1.getLexType().equals(LexType.FORTK)
                || pos1.getLexType().equals(LexType.PRINTFTK)
                || pos1.getLexType().equals(LexType.RETURNTK)
                || pos1.getLexType().equals(LexType.LBRACE)
                || pos1.getLexType().equals(LexType.INTTK)
                || pos1.getLexType().equals(LexType.CHARTK)) {
            return true;
        }
        else if (pos1.getLexType().equals(LexType.IDENFR)) {
            tokenIterator.getPrevious();
            switchFake(true);
            lValParser();
            boolean flag = tokenIterator.getNext().getLexType().equals(LexType.ASSIGN);
            tokenIterator.getBack(step  + 1);
            switchFake(false);
            if (flag) tokenIterator.getNext();
            return flag;
        }
        else {
            tokenIterator.getPrevious();
            return false;
        }
    }

    private ForStmt forStmtParser() {
        LVal lVal = lValParser();
        tokenIterator.getNext();
        Exp exp = expParser();
        return new ForStmt(lVal, exp);
    }

    private ForBlockStmt forBlockStmtParser() {
        tokenIterator.getNext();
        if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
            tokenIterator.getPrevious();
            ForStmt forStmt = forStmtParser();
            tokenIterator.getNext();
            if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                tokenIterator.getPrevious();
                Cond cond = condParser();
                tokenIterator.getNext();
                if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                    tokenIterator.getPrevious();
                    ForStmt forStmt2 = forStmtParser();
                    tokenIterator.getNext();
                    Stmt stmt = stmtParser();
                    return new ForBlockStmt(stmt, forStmt, cond, forStmt2);
                }
                else {
                    Stmt stmt = stmtParser();
                    return new ForBlockStmt(stmt, cond, forStmt, true);
                }
            }
            else {
                if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                    tokenIterator.getPrevious();
                    ForStmt forStmt2 = forStmtParser();
                    tokenIterator.getNext();
                    Stmt stmt = stmtParser();
                    return new ForBlockStmt(stmt, forStmt, forStmt2);
                }
                else {
                    Stmt stmt = stmtParser();
                    return new ForBlockStmt(stmt, forStmt, true);
                }
            }
        }
        else {
            if (! tokenIterator.getNext().getLexType().equals(LexType.SEMICN)) {
                tokenIterator.getPrevious();
                Cond cond = condParser();
                tokenIterator.getNext();
                if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                    tokenIterator.getPrevious();
                    ForStmt forStmt2 = forStmtParser();
                    tokenIterator.getNext();
                    Stmt stmt = stmtParser();
                    return new ForBlockStmt(stmt, cond, forStmt2, false);
                }
                else {
                    Stmt stmt = stmtParser();
                    return new ForBlockStmt(stmt, cond);
                }
            }
            else {
                if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                    tokenIterator.getPrevious();
                    ForStmt forStmt2 = forStmtParser();
                    tokenIterator.getNext();
                    Stmt stmt = stmtParser();
                    return new ForBlockStmt(stmt, forStmt2, false);
                }
                else {
                    Stmt stmt = stmtParser();
                    return new ForBlockStmt(stmt);
                }
            }
        }
    }

    private Exp expParser() {
        AddExp addExp = addExpParser();
        return new Exp(addExp);
    }

    private AddExp addExpParser() {
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<MulExp> operands = new ArrayList<>();
        MulExp toBegin = mulExpParser();
        Token pos1 = tokenIterator.getNext();
        if (fakeMode) step++;
        while (pos1.getLexType().equals(LexType.PLUS) || pos1.getLexType().equals(LexType.MINU)) {
            operators.add(pos1);
            MulExp mulExp = mulExpParser();
            operands.add(mulExp);
            pos1 = tokenIterator.getNext();
            if (fakeMode) step++;
        }
        tokenIterator.getPrevious();
        if (fakeMode) step--;
        return new AddExp(toBegin, operators, operands);
    }

    private MulExp mulExpParser() {
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<UnaryExp> operands = new ArrayList<>();
        UnaryExp toBegin = unaryExpParser();
        Token pos1 = tokenIterator.getNext();
        if (fakeMode) step++;
        while (pos1.getLexType().equals(LexType.MULT)
                || pos1.getLexType().equals(LexType.DIV)
                || pos1.getLexType().equals(LexType.MOD)) {
            operators.add(pos1);
            UnaryExp unaryExp = unaryExpParser();
            operands.add(unaryExp);
            pos1 = tokenIterator.getNext();
            if (fakeMode) step++;
        }
        tokenIterator.getPrevious();
        if (fakeMode)  step--;
        return new MulExp(toBegin, operators, operands);
    }
    private UnaryExp unaryExpParser() {
        Token pos1 = tokenIterator.getNext();
        Token pos2 = tokenIterator.getNext();
        if (pos2.getLexType().equals(LexType.END)) {
            if (fakeMode)  step -= 1;
        }
        if (fakeMode)  step += 2;
        if (pos1.getLexType().equals(LexType.IDENFR)
                && pos2.getLexType().equals(LexType.LPARENT)) {
            tokenIterator.getBack(2);
            if (fakeMode) step -= 2;
            FuncCall funcCall = funcCallParser();
            return new UnaryExp(funcCall);
        }
        else {
            tokenIterator.getPrevious();
            if (fakeMode) step--;
            if (pos1.getLexType().equals(LexType.PLUS)
                    || pos1.getLexType().equals(LexType.MINU)
                    || pos1.getLexType().equals(LexType.NOT)) {
                tokenIterator.getPrevious();
                if (fakeMode) step--;
                UnaryExpExp unaryExpExp = unaryExpExpParser();
                return new UnaryExp(unaryExpExp);
            }
            else {
                tokenIterator.getPrevious();
                if (fakeMode) step--;
                PrimaryExp primaryExp = primaryExpParser();
                return new UnaryExp(primaryExp);
            }
        }
    }

    private UnaryExpExp unaryExpExpParser() {
        UnaryOp unaryOp = unaryOpParser();
        UnaryExp unaryExp = unaryExpParser();
        return new UnaryExpExp(unaryOp, unaryExp);
    }

    private UnaryOp unaryOpParser() {
        if (fakeMode) step++;
        return new UnaryOp(tokenIterator.getNext());
    }

    private PrimaryExp primaryExpParser() {
        Token pos1 = tokenIterator.getNext();
        if (fakeMode) step++;
        if (pos1.getLexType().equals(LexType.INTCON)) {
            Number number = new Number(pos1);
            return new PrimaryExp(number);
        }
        else if (pos1.getLexType().equals(LexType.CHRCON)) {
            Character character = new Character(pos1);
            return new PrimaryExp(character);
        }
        else if (pos1.getLexType().equals(LexType.IDENFR)) {
            tokenIterator.getPrevious();
            if (fakeMode) step--;
            LVal lVal  = lValParser();
            return new PrimaryExp(lVal);
        }
        else {
            Exp exp = expParser();
            if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                if (fakeMode) {
                    step--;
                    tokenIterator.getPrevious();
                }
                if (! fakeMode) addErrorJ(tokenIterator.getPrevious().getLineNum());//j  error
            }
            PrimaryExpExp primaryExpExp = new PrimaryExpExp(exp);
            if (fakeMode) step++;
            return new PrimaryExp(primaryExpExp);
        }
    }

    private Cond condParser() {
        LOrExp  lOrExp = lOrExpParser();
        return new Cond(lOrExp);
    }

    private LOrExp lOrExpParser() {
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<LAndExp> operands = new ArrayList<>();
        LAndExp toBegin = lAndExpParser();
        Token pos1 = tokenIterator.getNext();
        while (pos1.getLexType().equals(LexType.OR)) {
            operators.add(pos1);
            LAndExp lAndExp = lAndExpParser();
            operands.add(lAndExp);
            pos1 = tokenIterator.getNext();
        }
        tokenIterator.getPrevious();
        return new LOrExp(toBegin, operators, operands);
    }

    private LAndExp lAndExpParser() {
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<EqExp> operands = new ArrayList<>();
        EqExp toBegin = eqExpParser();
        Token pos1 = tokenIterator.getNext();
        while (pos1.getLexType().equals(LexType.AND)) {
            operators.add(pos1);
            EqExp eqExp = eqExpParser();
            operands.add(eqExp);
            pos1 = tokenIterator.getNext();
        }
        tokenIterator.getPrevious();
        return new LAndExp(toBegin, operators, operands);
    }

    private EqExp eqExpParser() {
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<RelExp> operands = new ArrayList<>();
        RelExp toBegin = relExpParser();
        Token pos1 = tokenIterator.getNext();
        while (pos1.getLexType().equals(LexType.EQL) || pos1.getLexType().equals(LexType.NEQ)) {
            operators.add(pos1);
            RelExp relExp = relExpParser();
            operands.add(relExp);
            pos1 = tokenIterator.getNext();
        }
        tokenIterator.getPrevious();
        return new EqExp(toBegin, operators, operands);
    }

    private RelExp relExpParser() {
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<AddExp> operands = new ArrayList<>();
        AddExp toBegin = addExpParser();
        Token pos1 = tokenIterator.getNext();
        while (pos1.getLexType().equals(LexType.LEQ) || pos1.getLexType().equals(LexType.LSS)
                || pos1.getLexType().equals(LexType.GEQ) || pos1.getLexType().equals(LexType.GRE)) {
            operators.add(pos1);
            AddExp addExp = addExpParser();
            operands.add(addExp);
            pos1 = tokenIterator.getNext();
        }
        tokenIterator.getPrevious();
        return new RelExp(toBegin, operators, operands);
    }

    private LVal lValParser() {
        Token pos1 = tokenIterator.getNext();
        if (fakeMode) step++;
        Token ident = pos1;
        if (tokenIterator.getNext().getLexType().equals(LexType.LBRACK)) {
            if (fakeMode) step++;
            Exp exp = expParser();
            if (! tokenIterator.getNext().getLexType().equals(LexType.RBRACK)) {
                if (fakeMode) {
                    step--;
                    tokenIterator.getPrevious();
                }
                if (! fakeMode) addErrorK(tokenIterator.getPrevious().getLineNum());//K  error
            }
            if (fakeMode) step++;
            return new LVal(ident, exp);
        }
        else {
            tokenIterator.getPrevious();
            return new LVal(ident);
        }
    }

    private FuncCall funcCallParser() {
        Token ident = tokenIterator.getNext();
        Token pos1 = tokenIterator.getNext();
        //pos1.getLexType().equals(LexType.LPARENT)
        pos1 = tokenIterator.getNext();
        if (fakeMode) step += 3;
        if (pos1.getLexType().equals(LexType.RPARENT)) {
            return new FuncCall(ident);
        }
        else if (pos1.getLexType().equals(LexType.SEMICN)) {
            if (! fakeMode) addErrorJ(tokenIterator.getPrevious().getLineNum());//j  error
            if (fakeMode) {
                step--;
                tokenIterator.getPrevious();
            }
            return new FuncCall(ident);
        }
        else {
            tokenIterator.getPrevious();
            if (fakeMode) step--;
            FuncRParams funcRParams = funcRParamsParser();
            if (! tokenIterator.getNext().getLexType().equals(LexType.RPARENT)) {
                if (! fakeMode) addErrorJ(tokenIterator.getPrevious().getLineNum());//j  error
                if (fakeMode) {
                    step--;
                    tokenIterator.getPrevious();
                }
            }
            if (fakeMode) step++;
            return new FuncCall(ident, funcRParams);
        }
    }

    private FuncRParams funcRParamsParser() {
        ArrayList<Exp> exps = new ArrayList<>();
        Exp exp0 = expParser();
        exps.add(exp0);
        while (tokenIterator.getNext().getLexType().equals(LexType.COMMA)) {
            if (fakeMode) step++;
            Exp exp = expParser();
            exps.add(exp);
        }
        tokenIterator.getPrevious();
        if (fakeMode) step--;
        return new FuncRParams(exps);
    }

    private FuncFParams funcFParamsParser() {
        FuncFParam funcFParam0 = funcFParamParser();
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        funcFParams.add(funcFParam0);
        while (tokenIterator.getNext().getLexType().equals(LexType.COMMA)) {
            if (fakeMode) step++;
            FuncFParam funcFParam = funcFParamParser();
            funcFParams.add(funcFParam);
        }
        tokenIterator.getPrevious();
        return new FuncFParams(funcFParams);
    }

    private FuncFParam funcFParamParser() {
        BType bType = new BType(tokenIterator.getNext());
        Token ident = tokenIterator.getNext();
        if (fakeMode) step += 2;
        if (tokenIterator.getNext().getLexType().equals(LexType.LBRACK)) {
            if (fakeMode) step++;
            if (! tokenIterator.getNext().getLexType().equals(LexType.RBRACK)) {
                if (! fakeMode) addErrorK(tokenIterator.getPrevious().getLineNum());//k  error
                if (fakeMode) {
                    step--;
                    tokenIterator.getPrevious();
                }
            }
            if (fakeMode) step++;
            return new FuncFParam(bType, ident, true);
        }
        else {
            tokenIterator.getPrevious();
            if (fakeMode) step--;
            return new FuncFParam(bType, ident, false);
        }
    }

    private void addErrorI(int lineNum) {
        Error error = new Error(lineNum, 'i');
        errorList.addError(error);
    }

    private void addErrorJ(int lineNum) {
        Error error = new Error(lineNum, 'j');
        errorList.addError(error);
    }

    private void addErrorK(int lineNum) {
        Error error = new Error(lineNum, 'k');
        errorList.addError(error);
    }
}

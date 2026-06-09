package frontend.Parser;

import frontend.Error;
import frontend.Lexer.Token.*;
import frontend.Parser.SyntaxNode.*;
import frontend.Parser.SyntaxNode.ConstInitVal.*;
import frontend.Parser.SyntaxNode.InitVal.*;
import frontend.Parser.SyntaxNode.Number;
import frontend.Parser.SyntaxNode.PrimaryExp.*;
import frontend.Parser.SyntaxNode.Stmt.*;
import frontend.Parser.SyntaxNode.UnaryExp.*;


import java.util.ArrayList;

public class Parser {
    private TokensIterator iterator;
    private CompUnit compUnit;
    private boolean addError;


    public Parser(TokensIterator iterator) {
        this.iterator = iterator;
        this.addError = true;
        compUnit = compUnitParser();
    }

    public CompUnit getCompUnit() {
        return compUnit;
    }

    private CompUnit compUnitParser() {
        ArrayList<Decl> decls = parseDecls();
        ArrayList<FuncDef> funcs = parseFuncs();
        return new CompUnit(decls, funcs, mainFuncDefParser());
    }

    private ArrayList<Decl> parseDecls() {
        ArrayList<Decl> decls = new ArrayList<>();
        while (iterator.hasNextToken()) {
            Token token = iterator.nextToken(2);
            if (token.isType(TokenType.LPARENT)) {
                break;
            }
            decls.add(declParser());
        }
        return decls;
    }

    private ArrayList<FuncDef> parseFuncs() {
        ArrayList<FuncDef> funcs = new ArrayList<>();
        while (iterator.hasNextToken()) {
            Token token = iterator.nextToken(1);
            if (token.isType(TokenType.MAINTK)) {
                break;
            }
            funcs.add(funcDefParser());
        }
        return funcs;
    }

    private Decl declParser() {
        Token token = iterator.nextToken();
        if (token.isType(TokenType.CONSTTK)) {
            return constDeclParser();
        } else {
            return varDeclParser();
        }
    }

    private ConstDecl constDeclParser() {
        Token constTk = iterator.readNextToken();
        BType bType = bTypeParser();
        ConstDef firstConstDef = constDefParser();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        while (iterator.nextToken().isType(TokenType.COMMA)) {
            commas.add(iterator.readNextToken());
            constDefs.add(constDefParser());
        }
        Token semicn = null;
        if (iterator.nextToken().isType(TokenType.SEMICN)) {
            semicn = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.i, iterator.lastToken().getLineNum()));
            }
        }
        return new ConstDecl(constTk, bType, firstConstDef, constDefs, commas, semicn);
    }

    private BType bTypeParser() {
        Token token = iterator.readNextToken();
        return new BType(token);
    }

    private ConstDef constDefParser() {
        Token ident = iterator.readNextToken();
        Token lbrack = null;
        ConstExp constExp = null;
        Token rbrack = null;
        if (iterator.nextToken().isType(TokenType.LBRACK)) {
            lbrack = iterator.readNextToken();
            constExp = constExpParser();
            if (iterator.nextToken().isType(TokenType.RBRACK)) {
                rbrack = iterator.readNextToken();
            } else {
                if (addError) {
                    Error.addError(new Error(Error.ErrorType.k, iterator.lastToken().getLineNum()));
                }
            }
        }
        Token assign = iterator.readNextToken();
        ConstInitVal constInitVal = constInitValParser();
        return new ConstDef(ident, lbrack, constExp, rbrack, assign, constInitVal);
    }

    private ConstInitVal constInitValParser() {
        if (iterator.nextToken().isType(TokenType.LBRACE)) {
            return constInitValExpsParser();
        } else if (iterator.nextToken().isType(TokenType.STRCON)) {
            return constInitValStringParser();
        } else {
            return constInitValExpParser();
        }
    }

    private ConstInitValExp constInitValExpParser() {
        return new ConstInitValExp(constExpParser());
    }
    
    private ConstInitValExps constInitValExpsParser() {
        Token lbrace = iterator.readNextToken();
        ConstExp firstConstExp = null;
        ArrayList<ConstExp> constExps = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        if (!iterator.nextToken().isType(TokenType.RBRACE)) {
            firstConstExp = constExpParser();
            while (iterator.nextToken().isType(TokenType.COMMA)) {
                commas.add(iterator.readNextToken());
                constExps.add(constExpParser());
            }
        }
        Token rbrace = iterator.readNextToken();
        return new ConstInitValExps(lbrace, firstConstExp, constExps, commas, rbrace);
    }
    
    private ConstInitValString constInitValStringParser() {
        return new ConstInitValString(iterator.readNextToken());
    }
    
    private VarDecl varDeclParser() {
        BType bType = bTypeParser();
        VarDef firstVarDef = varDefParser();
        ArrayList<VarDef> varDefs = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        while (iterator.nextToken().isType(TokenType.COMMA)) {
            commas.add(iterator.readNextToken());
            varDefs.add(varDefParser());
        }
        Token semicn = null;
        if (iterator.nextToken().isType(TokenType.SEMICN)) {
            semicn = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.i, iterator.lastToken().getLineNum()));
            }
        }
        return new VarDecl(bType, firstVarDef, varDefs, commas, semicn);
    }

    private VarDef varDefParser() {
        Token ident = iterator.readNextToken();
        Token lbrack = null;
        ConstExp constExp = null;
        Token rbrack = null;
        Token assign = null;
        InitVal initVal = null;
        if (iterator.nextToken().isType(TokenType.LBRACK)) {
            lbrack = iterator.readNextToken();
            constExp = constExpParser();
            if (iterator.nextToken().isType(TokenType.RBRACK)) {
                rbrack = iterator.readNextToken();
            } else {
                if (addError) {
                    Error.addError(new Error(Error.ErrorType.k, iterator.lastToken().getLineNum()));
                }
            }
        }
        if (iterator.nextToken().isType(TokenType.ASSIGN)) {
            assign = iterator.readNextToken();
            initVal = initValParser();
        }
        return new VarDef(ident, lbrack, constExp, rbrack, assign, initVal);
    }

    private InitVal initValParser() {
        if (iterator.nextToken().isType(TokenType.LBRACE)) {
            return initValExpsParser();
        } else if (iterator.nextToken().isType(TokenType.STRCON)) {
            return initValStringParser();
        } else {
            return initValExpParser();
        }
    }

    private InitValExp initValExpParser() {
        return new InitValExp(expParser());
    }

    private InitValExps initValExpsParser() {
        Token lbrace = iterator.readNextToken();
        Exp firstExp = null;
        ArrayList<Exp> exps = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        if (!iterator.nextToken().isType(TokenType.RBRACE)) {
            firstExp = expParser();
            while (iterator.nextToken().isType(TokenType.COMMA)) {
                commas.add(iterator.readNextToken());
                exps.add(expParser());
            }
        }
        Token rbrace = iterator.readNextToken();
        return new InitValExps(lbrace, firstExp, exps, commas, rbrace);
    }

    private InitValString initValStringParser() {
        return new InitValString(iterator.readNextToken());
    }

    private FuncDef funcDefParser() {
        FuncType funcType = funcTypeParser();
        Token ident = iterator.readNextToken();
        Token lparent = iterator.readNextToken();
        FuncFParam firstFuncFParam = null;
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        if (FuncFParam.getFirst().contains(iterator.nextToken().getType())) {
            firstFuncFParam = funcFParamParser();
            while (iterator.nextToken().isType(TokenType.COMMA)) {
                commas.add(iterator.readNextToken());
                funcFParams.add(funcFParamParser());
            }
        }
        Token rparent = null;
        if (iterator.nextToken().isType(TokenType.RPARENT)) {
            rparent = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.j, iterator.lastToken().getLineNum()));
            }
        }
        Block block = blockParser();
        return new FuncDef(funcType, ident, lparent, firstFuncFParam, funcFParams, commas, rparent, block);
    }

    private MainFuncDef mainFuncDefParser() {
        Token intTk = iterator.readNextToken();
        Token mainTk = iterator.readNextToken();
        Token lParent = iterator.readNextToken();
        Token rParent = null;
        if (iterator.nextToken().isType(TokenType.RPARENT)) {
            rParent = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.j, iterator.lastToken().getLineNum()));
            }
        }
        Block block = blockParser();
        return new MainFuncDef(intTk, mainTk, lParent, rParent, block);
    }

    private FuncType funcTypeParser() {
        return new FuncType(iterator.readNextToken());
    }

    private FuncFParam funcFParamParser() {
        BType bType = bTypeParser();
        Token ident = iterator.readNextToken();
        Token lbrack = null;
        Token rbrack = null;
        if (iterator.nextToken().isType(TokenType.LBRACK)) {
            lbrack = iterator.readNextToken();
            rbrack = null;
            if (iterator.nextToken().isType(TokenType.RBRACK)) {
                rbrack = iterator.readNextToken();
            } else {
                if (addError) {
                    Error.addError(new Error(Error.ErrorType.k, iterator.lastToken().getLineNum()));
                }
            }
        }
        return new FuncFParam(bType, ident, lbrack, rbrack);
    }

    private Block blockParser() {
        Token lbrace = iterator.readNextToken();
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        while (iterator.hasNextToken() &&
                !iterator.nextToken().isType(TokenType.RBRACE)) {
            blockItems.add(blockItemParser());
        }
        Token rbrace = iterator.readNextToken();
        return new Block(lbrace, blockItems, rbrace);
    }

    private BlockItem blockItemParser() {
        Token token = iterator.nextToken();
        if (token.isType(TokenType.CONSTTK) || token.isType(TokenType.INTTK)
                || token.isType(TokenType.CHARTK)) {
            return declParser();
        } else {
            return stmtParser();
        }
    }

    private Stmt stmtParser() {
        Token token0 = iterator.nextToken();
        if (token0.isType(TokenType.IDENFR)) {
            iterator.addRecord();
            addError = false;
            LVal lVal = lValParser();
            Token token1 = iterator.nextToken();
            Token token2 = iterator.nextToken(1);
            addError = true;
            iterator.returnToRecord();
            if (token1 != null && token1.isType(TokenType.ASSIGN)) {
                if (token2.isType(TokenType.GETINTTK)) {
                    return stmtGetIntParser();
                } else if (token2.isType(TokenType.GETCHARTK)) {
                    return stmtGetCharParser();
                } else {
                    return stmtAssignParser();
                }
            } else {
                return stmtExpParser();
            }
        } else if (token0.isType(TokenType.IFTK)) {
            return stmtIfParser();
        } else if (token0.isType(TokenType.FORTK)) {
            return stmtForParser();
        } else if (token0.isType(TokenType.RETURNTK)) {
            return stmtReturnParser();
        } else if (token0.isType(TokenType.PRINTFTK)) {
            return stmtPrintfParser();
        } else if (token0.isType(TokenType.BREAKTK) || token0.isType(TokenType.CONTINUETK)) {
            return stmtBreakParser();
        } else if (token0.isType(TokenType.LBRACE)) {
            return stmtBlockParser();
        } else {
            return stmtExpParser();
        }
    }

    private StmtAssign stmtAssignParser() {
        LVal lVal = lValParser();
        Token assign = iterator.readNextToken();
        Exp exp = expParser();
        Token semicn = null;
        if (iterator.nextToken().isType(TokenType.SEMICN)) {
            semicn = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.i, iterator.lastToken().getLineNum()));
            }

        }
        return new StmtAssign(lVal, assign, exp, semicn);
    }

    private StmtBlock stmtBlockParser() {
        return new StmtBlock(blockParser());
    }

    private StmtBreak stmtBreakParser() {
        Token token = iterator.readNextToken();
        Token semicn = null;
        if (iterator.nextToken().isType(TokenType.SEMICN)) {
            semicn = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.i, iterator.lastToken().getLineNum()));
            }
        }
        return new StmtBreak(token, semicn);
    }

    private StmtExp stmtExpParser() {
        Exp exp = null;
        if (Exp.getFirst().contains(iterator.nextToken().getType())) {
            exp = expParser();
        }
        Token semicn = null;
        if (iterator.nextToken().isType(TokenType.SEMICN)) {
            semicn = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.i, iterator.lastToken().getLineNum()));
            }

        }
        return new StmtExp(exp, semicn);
    }

    private StmtFor stmtForParser() {
        Token forTk = iterator.readNextToken();
        Token lParent = iterator.readNextToken();
        ForStmt forStmt1 = null;
        if (!iterator.nextToken().isType(TokenType.SEMICN)) {
            forStmt1 = forStmtParser();
        }
        Token semicn1 = iterator.readNextToken();
        Cond cond = null;
        if (!iterator.nextToken().isType(TokenType.SEMICN)) {
            cond = condParser();
        }
        Token semicn2 = iterator.readNextToken();
        ForStmt forStmt2 = null;
        if (!iterator.nextToken().isType(TokenType.RPARENT)) {
            forStmt2 = forStmtParser();
        }
        Token rParent = iterator.readNextToken();
        Stmt stmt = stmtParser();
        return new StmtFor(forTk, lParent, forStmt1, semicn1, cond, semicn2, forStmt2, rParent, stmt);
    }

    private StmtGetInt stmtGetIntParser() {
        LVal lVal = lValParser();
        Token assign = iterator.readNextToken();
        Token getIntTk = iterator.readNextToken();
        Token lParent = iterator.readNextToken();
        Token rParent = null;
        if (iterator.nextToken().isType(TokenType.RPARENT)) {
            rParent = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.j, iterator.lastToken().getLineNum()));
            }

        }
        Token semicn = null;
        if (iterator.nextToken().isType(TokenType.SEMICN)) {
            semicn = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.i, iterator.lastToken().getLineNum()));
            }

        }
        return new StmtGetInt(lVal, assign, getIntTk, lParent, rParent, semicn);
    }

    private StmtGetChar stmtGetCharParser() {
        LVal lVal = lValParser();
        Token assign = iterator.readNextToken();
        Token getCharTk = iterator.readNextToken();
        Token lParent = iterator.readNextToken();
        Token rParent = null;
        if (iterator.nextToken().isType(TokenType.RPARENT)) {
            rParent = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.j, iterator.lastToken().getLineNum()));
            }

        }
        Token semicn = null;
        if (iterator.nextToken().isType(TokenType.SEMICN)) {
            semicn = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.i, iterator.lastToken().getLineNum()));
            }

        }
        return new StmtGetChar(lVal, assign, getCharTk, lParent, rParent, semicn);
    }

    private StmtIf stmtIfParser() {
        Token ifTk = iterator.readNextToken();
        Token lParent = iterator.readNextToken();
        Cond cond = condParser();
        Token rParent = null;
        if (iterator.nextToken().isType(TokenType.RPARENT)) {
            rParent = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.j, iterator.lastToken().getLineNum()));
            }

        }
        Stmt stmt1 = stmtParser();
        Token elseTk = null;
        Stmt stmt2 = null;
        if (iterator.nextToken().isType(TokenType.ELSETK)) {
            elseTk = iterator.readNextToken();
            stmt2 = stmtParser();
        }
        return new StmtIf(ifTk, lParent, cond, rParent, stmt1, elseTk, stmt2);
    }

    private StmtPrintf stmtPrintfParser() {
        Token printfTk = iterator.readNextToken();
        Token lParent = iterator.readNextToken();
        Token stringConst = iterator.readNextToken();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        while (iterator.nextToken().isType(TokenType.COMMA)) {
            commas.add(iterator.readNextToken());
            exps.add(expParser());
        }
        Token rParent = null;
        if (iterator.nextToken().isType(TokenType.RPARENT)) {
            rParent = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.j, iterator.lastToken().getLineNum()));
            }

        }
        Token semicn = null;
        if (iterator.nextToken().isType(TokenType.SEMICN)) {
            semicn = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.i, iterator.lastToken().getLineNum()));
            }

        }
        return new StmtPrintf(printfTk, lParent, stringConst, commas, exps, rParent, semicn);
    }

    private StmtReturn stmtReturnParser() {
        Token returnTk = iterator.readNextToken();
        Exp exp = null;
        if (Exp.getFirst().contains(iterator.nextToken().getType())) {
            exp = expParser();
        }
        Token semicn = null;
        if (iterator.nextToken().isType(TokenType.SEMICN)) {
            semicn = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.i, iterator.lastToken().getLineNum()));
            }

        }
        return new StmtReturn(returnTk, exp, semicn);
    }

    private ForStmt forStmtParser() {
        LVal lVal = lValParser();
        Token assign = iterator.readNextToken();
        Exp exp = expParser();
        return new ForStmt(lVal, assign, exp);
    }

    private Exp expParser() {
        return new Exp(addExpParser());
    }

    private Cond condParser() {
        return new Cond(lOrExpParser());
    }

    private LVal lValParser() {
        Token ident = iterator.readNextToken();
        Token lbrack = null;
        Exp exp = null;
        Token rbrack = null;
        if (iterator.nextToken().isType(TokenType.LBRACK)) {
            lbrack = iterator.readNextToken();
            exp = expParser();
            if (iterator.nextToken().isType(TokenType.RBRACK)) {
                rbrack = iterator.readNextToken();
            } else {
                if (addError) {
                    Error.addError(new Error(Error.ErrorType.k, iterator.lastToken().getLineNum()));
                }

            }
        }
        return new LVal(ident, lbrack, exp, rbrack);
    }

    private PrimaryExp primaryExpParser() {
        if (iterator.nextToken().isType(TokenType.LPARENT)) {
            return primaryExpExpParser();
        } else if (iterator.nextToken().isType(TokenType.INTCON)) {
            return primaryExpNumParser();
        } else if (iterator.nextToken().isType(TokenType.CHRCON)) {
            return primaryExpCharParser();
        } else {
            return primaryExpLValParser();
        }
    }

    private PrimaryExpChar primaryExpCharParser() {
        return new PrimaryExpChar(charParser());
    }

    private PrimaryExpExp primaryExpExpParser() {
        Token lparent = iterator.readNextToken();
        Exp exp = expParser();
        Token rparent = null;
        if (iterator.nextToken().isType(TokenType.RPARENT)) {
            rparent = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.j, iterator.lastToken().getLineNum()));
            }

        }
        return new PrimaryExpExp(lparent, exp, rparent);
    }

    private PrimaryExpLVal primaryExpLValParser() {
        return new PrimaryExpLVal(lValParser());
    }

    private PrimaryExpNum primaryExpNumParser() {
        return new PrimaryExpNum(numberParser());
    }

    private Number numberParser() {
        return new Number(iterator.readNextToken());
    }

    private Char charParser() {
        return new Char(iterator.readNextToken());
    }

    private UnaryExp unaryExpParser() {
        Token token0 = iterator.nextToken();
        Token token1 = iterator.nextToken(1);
        if (token0.isType(TokenType.PLUS) ||
                token0.isType(TokenType.MINU) || token0.isType(TokenType.NOT)) {
            return unaryExpOpParser();
        } else if (token0.isType(TokenType.IDENFR) && token1.isType(TokenType.LPARENT)) {
            return unaryExpFuncParser();
        } else {
            return unaryExpPriParser();
        }
    }

    private UnaryExpPri unaryExpPriParser() {
        return new UnaryExpPri(primaryExpParser());
    }

    private UnaryExpFunc unaryExpFuncParser() {
        Token ident = iterator.readNextToken();
        Token lParent = iterator.readNextToken();
        Exp firstExp = null;
        ArrayList<Exp> exps = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        if (Exp.getFirst().contains(iterator.nextToken().getType())) {
            firstExp = expParser();
            while (iterator.nextToken().isType(TokenType.COMMA)) {
                commas.add(iterator.readNextToken());
                exps.add(expParser());
            }
        }
        Token rParent = null;
        if (iterator.nextToken().isType(TokenType.RPARENT)) {
            rParent = iterator.readNextToken();
        } else {
            if (addError) {
                Error.addError(new Error(Error.ErrorType.j, iterator.lastToken().getLineNum()));
            }

        }
        return new UnaryExpFunc(ident, lParent, firstExp, exps, commas, rParent);
    }

    private UnaryExpOp unaryExpOpParser() {
        UnaryOp unaryOp = unaryOpParser();
        UnaryExp unaryExp = unaryExpParser();
        return new UnaryExpOp(unaryOp, unaryExp);
    }

    private UnaryOp unaryOpParser() {
        return new UnaryOp(iterator.readNextToken());
    }

    private MulExp mulExpParser() {
        UnaryExp firstUnaryExp = unaryExpParser();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<UnaryExp> unaryExps = new ArrayList<>();
        while (iterator.nextToken().isType(TokenType.MULT) ||
                iterator.nextToken().isType(TokenType.DIV) ||
                iterator.nextToken().isType(TokenType.MOD) ) {
            ops.add(iterator.readNextToken());
            unaryExps.add(unaryExpParser());
        }
        return new MulExp(firstUnaryExp, ops, unaryExps);
    }

    private AddExp addExpParser() {
        MulExp firstMulExp = mulExpParser();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<MulExp> mulExps = new ArrayList<>();
        while (iterator.nextToken().isType(TokenType.PLUS) ||
                iterator.nextToken().isType(TokenType.MINU)) {
            ops.add(iterator.readNextToken());
            mulExps.add(mulExpParser());
        }
        return new AddExp(firstMulExp, ops, mulExps);
    }

    private RelExp relExpParser() {
        AddExp firstAddExp = addExpParser();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<AddExp> addExps = new ArrayList<>();
        while (iterator.nextToken().isType(TokenType.LSS) ||
                iterator.nextToken().isType(TokenType.LEQ) ||
                iterator.nextToken().isType(TokenType.GRE) ||
                iterator.nextToken().isType(TokenType.GEQ)) {
            ops.add(iterator.readNextToken());
            addExps.add(addExpParser());
        }
        return new RelExp(firstAddExp, ops, addExps);
    }

    private EqExp eqExpParser() {
        RelExp firstRelExp = relExpParser();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<RelExp> relExps = new ArrayList<>();
        while (iterator.nextToken().isType(TokenType.EQL) ||
                iterator.nextToken().isType(TokenType.NEQ)) {
            ops.add(iterator.readNextToken());
            relExps.add(relExpParser());
        }
        return new EqExp(firstRelExp, ops, relExps);
    }

    private LAndExp lAndExpParser() {
        EqExp firstEqExp = eqExpParser();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<EqExp> eqExps = new ArrayList<>();
        while (iterator.nextToken().isType(TokenType.AND)) {
            ops.add(iterator.readNextToken());
            eqExps.add(eqExpParser());
        }
        return new LAndExp(firstEqExp, ops, eqExps);
    }

    private LOrExp lOrExpParser() {
        LAndExp firstLAndExp = lAndExpParser();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<LAndExp> lAndExps = new ArrayList<>();
        while (iterator.nextToken().isType(TokenType.OR)) {
            ops.add(iterator.readNextToken());
            lAndExps.add(lAndExpParser());
        }
        return new LOrExp(firstLAndExp, ops, lAndExps);
    }

    private ConstExp constExpParser() {
        return new ConstExp(addExpParser());
    }
}

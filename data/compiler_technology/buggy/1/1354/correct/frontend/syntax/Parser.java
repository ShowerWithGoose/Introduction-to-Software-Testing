package frontend.syntax;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class Parser {
    private final TokenList tokenList;



    public Parser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public Ast parseAst() {
        return new Ast(parseCompUnit());
    }

    public Ast.CompUnit parseCompUnit() {
        ArrayList<Ast.Decl> decls = new ArrayList<>();
        ArrayList<Ast.FuncDef> funcDefs = new ArrayList<>();
        Ast.MainFuncDef mainFuncDef = null;
        while (tokenList.hasNext()) {
            if (tokenList.checkAheadChar(2).type == TokenType.LPARENT && tokenList.checkAheadChar(1).type == TokenType.MAINTK) {
                mainFuncDef = parseMainFuncDef();
            } else if (tokenList.checkAheadChar(2).type == TokenType.LPARENT) {
                funcDefs.add(parseFuncDef());
            } else {
                decls.add(parseDecl());
            }
        }
        return new Ast.CompUnit(decls,funcDefs,mainFuncDef);
    }

    private Ast.FuncDef parseFuncDef() {
        Token type = tokenList.getCharWithJudge(TokenType.INTTK, TokenType.VOIDTK, TokenType.CHARTK);
        Ast.Ident ident = new Ast.Ident(tokenList.getCharWithJudge(TokenType.IDENFR));
        ArrayList<Ast.FuncFParam> params  = null;
        tokenList.getCharWithJudge(TokenType.LPARENT);
        if (!(tokenList.checkAheadChar(0).type == TokenType.RPARENT || tokenList.checkAheadChar(0).type == TokenType.LBRACE)) {
            params = parseFuncFParams();
        }
        tokenList.getCharWithJudge(TokenType.RPARENT);
        Ast.Block block = parseBlock();
        return new Ast.FuncDef(type, ident, params, block);
    }

    private Ast.MainFuncDef parseMainFuncDef() {
        Token type = tokenList.getCharWithJudge(TokenType.INTTK);
        Ast.Ident ident = new Ast.Ident(tokenList.getCharWithJudge(TokenType.MAINTK));
        tokenList.getCharWithJudge(TokenType.LPARENT);
        tokenList.getCharWithJudge(TokenType.RPARENT);
        Ast.Block block = parseBlock();
        return new Ast.MainFuncDef(type, ident, block);
    }

    private ArrayList<Ast.FuncFParam> parseFuncFParams() {
        ArrayList<Ast.FuncFParam> params = new ArrayList<>();
        params.add(parseSingleParam());
        while (tokenList.hasNext() && tokenList.checkAheadChar(0).type == TokenType.COMMA) {
            tokenList.getChar();
            params.add(parseSingleParam());
        }
        return params;
    }

    private Ast.FuncFParam parseSingleParam() {
        Token token = tokenList.getCharWithJudge(TokenType.INTTK, TokenType.CHARTK);
        Ast.Ident  ident = new Ast.Ident(tokenList.getCharWithJudge(TokenType.IDENFR));
        boolean isArrayItem = false;
        if (tokenList.hasNext() && tokenList.checkAheadChar(0).type == TokenType.LBRACK ) {
                isArrayItem = true;
                tokenList.getCharWithJudge(TokenType.LBRACK);
                tokenList.getCharWithJudge(TokenType.RBRACK);

        }
        return new Ast.FuncFParam(token, ident, isArrayItem);
    }

    private Ast.Block parseBlock() {
        ArrayList<Ast.BlockItem> blockItems = new ArrayList<>();
        tokenList.getCharWithJudge(TokenType.LBRACE);
        while (tokenList.checkAheadChar(0).type != TokenType.RBRACE) {
            blockItems.add(parseBlockItem());
        }
        tokenList.getCharWithJudge(TokenType.RBRACE);
        return new Ast.Block(blockItems);
    }

    private Ast.BlockItem parseBlockItem() {
        if (tokenList.checkAheadChar(0).type == TokenType.INTTK ||
                tokenList.checkAheadChar(0).type == TokenType.CHARTK ||
                tokenList.checkAheadChar(0).type == TokenType.CONSTTK) {
            return parseDecl();
        } else {
            return parseStmt();
        }
    }

    private Ast.Decl parseDecl() {
        if (tokenList.checkAheadChar(2).type == TokenType.LPARENT) {
            return parseFuncDef();
        }
        if (tokenList.checkAheadChar(0).type == TokenType.CONSTTK) {
            return parseConstDecl();
        }
        else {
            return parseVarDecl();
        }

    }

    private Ast.ConstDecl parseConstDecl() {
        tokenList.getCharWithJudge(TokenType.CONSTTK);
        Token bType= tokenList.getCharWithJudge(TokenType.INTTK, TokenType.CHARTK);
        ArrayList<Ast.ConstDef> constDefs = new ArrayList<>();
        constDefs.add(parseConstDef());
        while (tokenList.checkAheadChar(0).type == TokenType.COMMA) {
            tokenList.getChar();
            constDefs.add(parseConstDef());
        }
        tokenList.getCharWithJudge(TokenType.SEMICN);
        return new Ast.ConstDecl(bType, constDefs);
    }

    private Ast.ConstDef parseConstDef() {
        Ast.Ident  ident = new Ast.Ident(tokenList.getCharWithJudge(TokenType.IDENFR));
        if (tokenList.checkAheadChar(0).type == TokenType.LBRACK) {
            tokenList.getChar();
            Ast.AddExp constExp = parseAddExp();
            tokenList.getCharWithJudge(TokenType.RBRACK);
            tokenList.getCharWithJudge(TokenType.ASSIGN);
            Ast.ConstInitVal constInitVal = parseConstInitVal();
            return new Ast.ConstDef(ident, constExp, constInitVal);
        }
        else {
            tokenList.getCharWithJudge(TokenType.ASSIGN);
            Ast.ConstInitVal constInitVal = parseConstInitVal();
            return new Ast.ConstDef(ident, constInitVal);
        }
    }

    private Ast.VarDecl parseVarDecl()  {
        Token bType= tokenList.getCharWithJudge(TokenType.INTTK, TokenType.CHARTK);
        ArrayList<Ast.VarDef> varDefs = new ArrayList<>();
        varDefs.add(parseVarDef());
        while (tokenList.checkAheadChar(0).type == TokenType.COMMA) {
            tokenList.getChar();
            varDefs.add(parseVarDef());
        }
        tokenList.getCharWithJudge(TokenType.SEMICN);
        return new Ast.VarDecl(bType, varDefs);
    }

    private Ast.InitVal parseInitVal() {
        if (tokenList.checkAheadChar(0).type == TokenType.STRCON) {
            Ast.StringConst stringConst = new Ast.StringConst(tokenList.getCharWithJudge(TokenType.STRCON));
            return new Ast.InitVal(stringConst);
        } else if (tokenList.checkAheadChar(0).type == TokenType.LBRACE) {
            tokenList.getChar();
            if (tokenList.checkAheadChar(0).type == TokenType.RBRACE) {
                tokenList.getCharWithJudge(TokenType.RBRACE);
                return new Ast.InitVal();
            } else {
                ArrayList<Ast.AddExp> exps = new ArrayList<>();
                Ast.AddExp exp = parseAddExp();
                exps.add(exp);
                while (tokenList.checkAheadChar(0).type == TokenType.COMMA) {
                    tokenList.getChar();
                    exps.add(parseAddExp());
                }
                tokenList.getCharWithJudge(TokenType.RBRACE);
                return new Ast.InitVal(exps);
            }
        } else {
            Ast.AddExp exp = parseAddExp();
            return new Ast.InitVal(exp);
        }
    }

    private Ast.ConstInitVal parseConstInitVal() {
        if (tokenList.checkAheadChar(0).type == TokenType.STRCON) {
            Ast.StringConst stringConst = new Ast.StringConst(tokenList.getCharWithJudge(TokenType.STRCON));
            return new Ast.ConstInitVal(stringConst);
        } else if (tokenList.checkAheadChar(0).type == TokenType.LBRACE) {
            tokenList.getChar();
            if (tokenList.checkAheadChar(0).type == TokenType.RBRACE) {
                tokenList.getCharWithJudge(TokenType.RBRACE);
                return new Ast.ConstInitVal();
            } else {
                ArrayList<Ast.AddExp> exps = new ArrayList<>();
                Ast.AddExp exp = parseAddExp();
                exps.add(exp);
                while (tokenList.checkAheadChar(0).type == TokenType.COMMA) {
                    tokenList.getChar();
                    exps.add(parseAddExp());
                }
                tokenList.getCharWithJudge(TokenType.RBRACE);
                return new Ast.ConstInitVal(exps);
            }
        }
        else {
            Ast.AddExp exp = parseAddExp();
            return new Ast.ConstInitVal(exp);
        }
    }

    private Ast.AddExp parseAddExp() {
        Ast.MulExp mulExp = parseMulExp();
        Ast.AddExpSuffix addExpSuffix = parseAddExpSuffix();
        return new Ast.AddExp(mulExp, addExpSuffix);
    }

    private Ast.MulExp parseMulExp() {
        Ast.UnaryExp unaryExp = parseUnaryExp();
        Ast.MulExpSuffix mulExpSuffix = parseMulExpSuffix();
        return new Ast.MulExp(unaryExp, mulExpSuffix);
    }

    private Ast.AddExpSuffix parseAddExpSuffix() {
        if (tokenList.checkAheadChar(0).type == TokenType.PLUS) {
            Token addOp = tokenList.getCharWithJudge(TokenType.PLUS);
            Ast.MulExp mulExp = parseMulExp();
            Ast.AddExpSuffix addExpSuffix = parseAddExpSuffix();
            return new Ast.AddExpSuffix(mulExp, addExpSuffix, addOp);
        }
        else if (tokenList.checkAheadChar(0).type == TokenType.MINU) {
            Token subOp = tokenList.getCharWithJudge(TokenType.MINU);
            Ast.MulExp mulExp = parseMulExp();
            Ast.AddExpSuffix addExpSuffix = parseAddExpSuffix();
            return new Ast.AddExpSuffix(mulExp, addExpSuffix, subOp);
        } else {
            return new Ast.AddExpSuffix();
        }
    }

    private Ast.UnaryExp parseUnaryExp() {
        if (tokenList.checkAheadChar(0).type == TokenType.IDENFR && tokenList.checkAheadChar(1).type == TokenType.LPARENT) {
            Ast.Ident ident = new Ast.Ident(tokenList.getChar());
            tokenList.getChar();
            if (tokenList.checkAheadChar(0).type == TokenType.RPARENT || tokenList.checkAheadChar(0).type == TokenType.SEMICN) {
                tokenList.getCharWithJudge(TokenType.RPARENT);
                return new Ast.UnaryExp(ident);
            }
            Ast.FuncRParams funcRParams = parseFuncRParams();
            tokenList.getCharWithJudge(TokenType.RPARENT);
            return new Ast.UnaryExp(ident, funcRParams);
        } else if (tokenList.checkAheadChar(0).type == TokenType.PLUS || tokenList.checkAheadChar(0).type == TokenType.MINU || tokenList.checkAheadChar(0).type == TokenType.NOT) {
            Token op = tokenList.getChar();
            Ast.UnaryExp unaryExp = parseUnaryExp();
            return new Ast.UnaryExp(op, unaryExp);
        } else {
            Ast.PrimaryExp primaryExp = parsePrimaryExp();
            return new Ast.UnaryExp(primaryExp);
        }
    }

    private Ast.FuncRParams parseFuncRParams() {
        ArrayList<Ast.AddExp> params = new ArrayList<>();
        params.add(parseAddExp());
        while (tokenList.hasNext() && tokenList.checkAheadChar(0).type == TokenType.COMMA) {
            tokenList.getChar();
            params.add(parseAddExp());
        }
        return new Ast.FuncRParams(params);
    }

    private Ast.MulExpSuffix parseMulExpSuffix() {
        if (tokenList.checkAheadChar(0).type == TokenType.MULT || tokenList.checkAheadChar(0).type == TokenType.DIV || tokenList.checkAheadChar(0).type == TokenType.MOD) {
            Token mulOp = tokenList.getCharWithJudge(TokenType.MULT, TokenType.DIV, TokenType.MOD);
            Ast.UnaryExp unaryExp = parseUnaryExp();
            Ast.MulExpSuffix mulExpSuffix = parseMulExpSuffix();
            return new Ast.MulExpSuffix(unaryExp, mulExpSuffix, mulOp);
        }
        else {
            return new Ast.MulExpSuffix();
        }
    }

    private Ast.PrimaryExp parsePrimaryExp() {
        if (tokenList.checkAheadChar(0).type == TokenType.LPARENT) {
            tokenList.getCharWithJudge(TokenType.LPARENT);
            Ast.AddExp exp = parseAddExp();
            tokenList.getCharWithJudge(TokenType.RPARENT);
            return new Ast.PrimaryExp(exp);
        } else if (tokenList.checkAheadChar(0).type == TokenType.IDENFR) {
            return new Ast.PrimaryExp(parseLval());
        } else if (tokenList.checkAheadChar(0).type == TokenType.INTCON) {
            return new Ast.PrimaryExp(tokenList.getCharWithJudge(TokenType.INTCON));
        } else {
            return new Ast.PrimaryExp(tokenList.getCharWithJudge(TokenType.CHRCON));
        }
    }

    private Ast.Lval parseLval() {
        Ast.Ident ident = new Ast.Ident(tokenList.getCharWithJudge(TokenType.IDENFR));
        if (tokenList.checkAheadChar(0).type == TokenType.LBRACK) {
            tokenList.getCharWithJudge(TokenType.LBRACK);
            Ast.AddExp exp = parseAddExp();
            tokenList.getCharWithJudge(TokenType.RBRACK);
            return new Ast.Lval(ident, exp);
        } else {
            return new Ast.Lval(ident);
        }
    }

    private Ast.VarDef parseVarDef() {
        Ast.Ident  ident = new Ast.Ident(tokenList.getCharWithJudge(TokenType.IDENFR));
        if (tokenList.checkAheadChar(0).type == TokenType.LBRACK) {
            tokenList.getChar();
            Ast.AddExp constExp = parseAddExp();
            tokenList.getCharWithJudge(TokenType.RBRACK);
            if (tokenList.checkAheadChar(0).type == TokenType.ASSIGN) {
                tokenList.getCharWithJudge(TokenType.ASSIGN);
                Ast.InitVal InitVal = parseInitVal();
                return new Ast.VarDef(ident, constExp, InitVal);
            }
            return new Ast.VarDef(ident, constExp);
        }
        else if (tokenList.checkAheadChar(0).type == TokenType.ASSIGN) {
            tokenList.getChar();
            Ast.InitVal initVal = parseInitVal();
            return new Ast.VarDef(ident, initVal);
        }
        else {
            return new Ast.VarDef(ident);
        }
    }

    private Ast.LOrExp parseLOrExp() {
        Ast.LAndExp lAndExp = parseLAndExp();
        Ast.LOrExpSuffix lOrExpSuffix = parseLorExpSuffix();
        return new Ast.LOrExp(lAndExp,lOrExpSuffix);
    }

    private Ast.LOrExpSuffix parseLorExpSuffix() {
        if (tokenList.checkAheadChar(0).type == TokenType.OR) {
            Token orOp = tokenList.getCharWithJudge(TokenType.OR);
            Ast.LAndExp lAndExp = parseLAndExp();
            Ast.LOrExpSuffix lOrExpSuffix = parseLorExpSuffix();
            return new Ast.LOrExpSuffix(orOp,lAndExp,lOrExpSuffix);
        } else {
            return new Ast.LOrExpSuffix();
        }
    }

    private Ast.LAndExp parseLAndExp() {
        Ast.EqExp eqExp = parseEqExp();
        Ast.LAndExpSuffix lAndExpSuffix = parseLAndExpSuffix();
        return new Ast.LAndExp(eqExp,lAndExpSuffix);
    }

    private Ast.LAndExpSuffix parseLAndExpSuffix() {
        if (tokenList.checkAheadChar(0).type == TokenType.AND) {
            Token orOp = tokenList.getCharWithJudge(TokenType.AND);
            Ast.EqExp eqExp = parseEqExp();
            Ast.LAndExpSuffix lAndExpSuffix = parseLAndExpSuffix();
            return new Ast.LAndExpSuffix(orOp,eqExp,lAndExpSuffix);
        } else {
            return new Ast.LAndExpSuffix();
        }
    }

    private Ast.EqExp parseEqExp() {
        Ast.RelExp relExp = parseRelExp();
        Ast.EqExpSuffix eqExpSuffix = parseEqExpSuffix();
        return new Ast.EqExp(relExp,eqExpSuffix);
    }

    private Ast.EqExpSuffix parseEqExpSuffix() {
        if (tokenList.checkAheadChar(0).type == TokenType.EQL || tokenList.checkAheadChar(0).type == TokenType.NEQ) {
            Token eqOp = tokenList.getChar();
            Ast.RelExp relExp = parseRelExp();
            Ast.EqExpSuffix eqExpSuffix = parseEqExpSuffix();
            return new Ast.EqExpSuffix(eqOp,relExp,eqExpSuffix);
        } else {
            return new Ast.EqExpSuffix();
        }
    }

    private Ast.RelExp parseRelExp() {
        Ast.AddExp addExp = parseAddExp();
        Ast.RelExpSuffix relExpSuffix = parseRelExpSuffix();
        return new Ast.RelExp(addExp,relExpSuffix);
    }

    private Ast.RelExpSuffix parseRelExpSuffix() {
        if (tokenList.checkAheadChar(0).type == TokenType.LSS || tokenList.checkAheadChar(0).type == TokenType.LEQ || tokenList.checkAheadChar(0).type == TokenType.GEQ || tokenList.checkAheadChar(0).type == TokenType.GRE) {
            Token relOp = tokenList.getChar();
            Ast.AddExp addExp = parseAddExp();
            Ast.RelExpSuffix relExpSuffix = parseRelExpSuffix();
            return new Ast.RelExpSuffix(relOp,addExp,relExpSuffix);
        } else {
            return new Ast.RelExpSuffix();
        }
    }

    private Ast.Stmt parseStmt() {
        Token firstToken = tokenList.checkAheadChar(0);
        switch (firstToken.type) {
            case IDENFR -> {
                if (tokenList.checkAheadChar(1).type == TokenType.LPARENT) {
                    Ast.AddExp exp = parseAddExp();
                    tokenList.getCharWithJudge(TokenType.SEMICN);
                    return new Ast.ExpStmt(exp);
                }
                Ast.AddExp exp = parseAddExp();
                if (!(tokenList.checkAheadChar(0).type == TokenType.ASSIGN)) {
                    tokenList.getCharWithJudge(TokenType.SEMICN);
                    return new Ast.ExpStmt(exp);
                }
                Ast.Lval lval = exactLval(exp);
                tokenList.getCharWithJudge(TokenType.ASSIGN);
                if (tokenList.checkAheadChar(0).type == TokenType.GETINTTK) {
                    tokenList.getCharWithJudge(TokenType.GETINTTK);
                    tokenList.getCharWithJudge(TokenType.LPARENT);
                    tokenList.getCharWithJudge(TokenType.RPARENT);
                    tokenList.getCharWithJudge(TokenType.SEMICN);
                    return new Ast.GetIntStmt(lval);
                }
                if (tokenList.checkAheadChar(0).type == TokenType.GETCHARTK) {
                    tokenList.getCharWithJudge(TokenType.GETCHARTK);
                    tokenList.getCharWithJudge(TokenType.LPARENT);
                    tokenList.getCharWithJudge(TokenType.RPARENT);
                    tokenList.getCharWithJudge(TokenType.SEMICN);
                    return new Ast.GetCharStmt(lval);
                }
                Ast.AddExp rExp = parseAddExp();
                tokenList.getCharWithJudge(TokenType.SEMICN);
                return new Ast.AssignStmt(lval, rExp);
            }
            case SEMICN -> {
                tokenList.getCharWithJudge(TokenType.SEMICN);
                return new Ast.VoidStmt();
            }
            case LBRACE -> {
                Ast.Block block = parseBlock();
                return new Ast.BlockStmt(block);
            }
            case IFTK -> {
                tokenList.getCharWithJudge(TokenType.IFTK);
                tokenList.getCharWithJudge(TokenType.LPARENT);
                Ast.LOrExp cond = parseLOrExp();
                tokenList.getCharWithJudge(TokenType.RPARENT);
                Ast.Stmt stmt = parseStmt();
                if (tokenList.checkAheadChar(0).type == (TokenType.ELSETK)) {
                    tokenList.getCharWithJudge(TokenType.ELSETK);
                    Ast.Stmt stmt1 = parseStmt();
                    return new Ast.IfElStmt(cond, stmt, stmt1);
                }
                return new Ast.IfStmt(cond, stmt);
            }
            case FORTK -> {
                tokenList.getCharWithJudge(TokenType.FORTK);
                tokenList.getCharWithJudge(TokenType.LPARENT);
                Ast.ForAssignStmt assignStmt1 = null;
                Ast.ForAssignStmt assignStmt2 = null;
                Ast.LOrExp cond = null;
                if (tokenList.checkAheadChar(0).type != (TokenType.SEMICN)) {
                    Ast.Lval lval = parseLval();
                    tokenList.getCharWithJudge(TokenType.ASSIGN);
                    Ast.AddExp rExp = parseAddExp();
                    assignStmt1 = new Ast.ForAssignStmt(lval, rExp);
                }
                tokenList.getCharWithJudge(TokenType.SEMICN);
                if (tokenList.checkAheadChar(0).type != (TokenType.SEMICN)) {
                    cond = parseLOrExp();
                }
                tokenList.getCharWithJudge(TokenType.SEMICN);
                if (!(tokenList.checkAheadChar(0).type == TokenType.RPARENT || tokenList.checkAheadChar(0).type == (TokenType.LBRACE))) {
                    Ast.Lval lval = parseLval();
                    tokenList.getCharWithJudge(TokenType.ASSIGN);
                    Ast.AddExp rExp = parseAddExp();
                    assignStmt2 = new Ast.ForAssignStmt(lval, rExp);;
                }
                tokenList.getCharWithJudge(TokenType.RPARENT);
                Ast.Stmt stmt = parseStmt();
                return new Ast.ForStmt(assignStmt1,cond,assignStmt2,stmt);
            }
            case BREAKTK -> {
                tokenList.getCharWithJudge(TokenType.BREAKTK);
                tokenList.getCharWithJudge(TokenType.SEMICN);
                return new Ast.BreakStmt();
            }
            case CONTINUETK -> {
                tokenList.getCharWithJudge(TokenType.CONTINUETK);
                tokenList.getCharWithJudge(TokenType.SEMICN);
                return new Ast.ContinueStmt();
            }
            case RETURNTK -> {
                Token returnTk  = tokenList.getCharWithJudge(TokenType.RETURNTK);
                if (tokenList.checkAheadChar(0).type == (TokenType.SEMICN) || tokenList.checkAheadChar(0).lineIndex != returnTk.lineIndex) {
                    tokenList.getCharWithJudge(TokenType.SEMICN);
                    return new Ast.ReturnStmt();
                }
                Ast.AddExp exp = parseAddExp();
                tokenList.getCharWithJudge(TokenType.SEMICN);
                return new Ast.ReturnStmt(exp);
            }
            case PRINTFTK -> {
                tokenList.getCharWithJudge(TokenType.PRINTFTK);
                tokenList.getCharWithJudge(TokenType.LPARENT);
                Ast.StringConst stringConst = new Ast.StringConst(tokenList.getCharWithJudge(TokenType.STRCON));
                ArrayList<Ast.AddExp> exps = new ArrayList<>();
                while (tokenList.checkAheadChar(0).type == (TokenType.COMMA)) {
                    tokenList.getChar();
                    exps.add(parseAddExp());
                }
                tokenList.getCharWithJudge(TokenType.RPARENT);
                tokenList.getCharWithJudge(TokenType.SEMICN);
                return new Ast.PrintfStmt(stringConst, exps);
            }
            default -> {
                Ast.AddExp exp = parseAddExp();
                tokenList.getCharWithJudge(TokenType.SEMICN);
                return new Ast.ExpStmt(exp);
            }
        }
    }

    private Ast.Lval exactLval(Ast.AddExp exp) {
        Ast.Lval lval;
        lval = exp.getMulExp().getUnaryExp().getPrimaryExp().getLval();
        assert lval != null;
        return lval;
    }

}

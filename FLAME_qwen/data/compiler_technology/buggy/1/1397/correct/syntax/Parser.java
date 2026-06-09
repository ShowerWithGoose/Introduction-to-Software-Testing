package syntax;

import lexical.Lexer;
import lexical.Token;
import lexical.TokenList;
import lexical.TokenType;
import syntax.Unit;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.TreeMap;

public class Parser {
    private final TokenList tokenList;
    private BufferedWriter errorWriter;
    private BufferedWriter parserWriter;
    private TreeMap<Integer, String> errors;
    private ArrayList<String> parsers;

    public Parser(TokenList tokenList, BufferedWriter errorWriter, BufferedWriter parserWriter, TreeMap<Integer, String> errors, ArrayList<String> parsers) {
        this.tokenList = tokenList;
        this.errorWriter = errorWriter;
        this.parserWriter = parserWriter;
        this.errors = errors;
        this.parsers = parsers;
    }

    public Unit.CompUnit run() {
        ArrayList<Unit.Decl> decls = new ArrayList<>();
        ArrayList<Unit.FuncDef> funcDefs = new ArrayList<>();
        while (tokenList.hasNext()) {
            if (tokenList.ahead(2).getType().equals(TokenType.LPARENT)) {
                break;
            } else {
                decls.add(parseDecl());
            }
        }
        while (tokenList.hasNext()) {
            if (tokenList.ahead(1).getType().equals(TokenType.MAINTK)) {
                break;
            } else {
                funcDefs.add(parseFuncDef());
            }
        }
        Unit.MainFuncDef mainFuncDef = parseMainFuncDef();
        printSyntax("CompUnit");
        return new Unit.CompUnit(decls, funcDefs, mainFuncDef);
    }

    public Unit.Decl parseDecl() {
        if (tokenList.ahead(0).getType().equals(TokenType.CONSTTK)) {
            return parseConstDecl();
        } else {
            return parseVarDecl();
        }
    }

    public Unit.ConstDecl parseConstDecl() {
        tokenList.consume(TokenType.CONSTTK);
        String bType = tokenList.consume(TokenType.INTTK, TokenType.CHARTK).getRawString();
        ArrayList<Unit.ConstDef> constDefs = new ArrayList<>();
        while (tokenList.hasNext()) {
            constDefs.add(parseConstDef());
            if (tokenList.ahead(0).getType().equals(TokenType.COMMA)) {
                tokenList.consume();
            } else {
                if (tokenList.ahead(0).getType().equals(TokenType.SEMICN)) {
                    tokenList.consume();
                } else {
                    printError("i");
                }
                break;
            }
        }
        printSyntax("ConstDecl");
        return new Unit.ConstDecl(bType, constDefs);
    }

    public Unit.ConstDef parseConstDef() {
        String ident = tokenList.consume(TokenType.IDENFR).getRawString();
        Unit.ConstExp constExp = null;
        if (tokenList.ahead(0).getType().equals(TokenType.LBRACK)) {
            tokenList.consume(TokenType.LBRACK);
            constExp = parseConstExp();
            if (tokenList.consume(TokenType.RBRACK) == null) {
                printError("k");
            }
        }
        tokenList.consume(TokenType.ASSIGN);
        Unit.ConstInitVal constInitVal = parseConstInitVal();
        printSyntax("ConstDef");
        return new Unit.ConstDef(ident, constExp, constInitVal);
    }

    public Unit.ConstInitVal parseConstInitVal() {
        Unit.ConstInitVal ret;
        if (tokenList.ahead(0).getType().equals(TokenType.LBRACE)) {
            tokenList.consume();
            if (tokenList.ahead(0).getType().equals(TokenType.RBRACE)) {
                tokenList.consume(TokenType.RBRACE);
                ret = new Unit.ArrayConstInitVal(new ArrayList<>());
            } else {
                ArrayList<Unit.ConstExp> constExps = new ArrayList<>();
                constExps.add(parseConstExp());
                while (tokenList.ahead(0).getType().equals(TokenType.COMMA)) {
                    tokenList.consume();
                    constExps.add(parseConstExp());
                }
                tokenList.consume(TokenType.RBRACE);
                ret = new Unit.ArrayConstInitVal(constExps);
            }
        } else if (tokenList.ahead(0).getType().equals(TokenType.STRCON)) {
            ret = new Unit.StringConst(tokenList.consume().getRawString());
        } else {
            ret = parseConstExp();
        }
        printSyntax("ConstInitVal");
        return ret;
    }

    public Unit.VarDecl parseVarDecl() {
        String bType = tokenList.consume(TokenType.INTTK, TokenType.CHARTK).getRawString();
        ArrayList<Unit.VarDef> varDefs = new ArrayList<>();
        while (tokenList.hasNext()) {
            varDefs.add(parseVarDef());
            if (tokenList.ahead(0).getType().equals(TokenType.COMMA)) {
                tokenList.consume();
            } else {
                if (tokenList.ahead(0).getType().equals(TokenType.SEMICN)) {
                    tokenList.consume();
                } else {
                    printError("i");
                }
                break;
            }
        }
        printSyntax("VarDecl");
        return new Unit.VarDecl(bType, varDefs);
    }

    public Unit.VarDef parseVarDef() {
        String ident = tokenList.consume(TokenType.IDENFR).getRawString();
        Unit.ConstExp constExp = null;
        if (tokenList.ahead(0).getType().equals(TokenType.LBRACK)) {
            tokenList.consume(TokenType.LBRACK);
            constExp = parseConstExp();
            if (tokenList.consume(TokenType.RBRACK) == null) {
                printError("k");
            }
        }
        Unit.InitVal initVal = null;
        if (tokenList.ahead(0).getType().equals(TokenType.ASSIGN)) {
            tokenList.consume();
            initVal = parseInitVal();
        }
        printSyntax("VarDef");
        return new Unit.VarDef(ident, constExp, initVal);
    }

    public Unit.InitVal parseInitVal() {
        Unit.InitVal ret;
        if (tokenList.ahead(0).getType().equals(TokenType.LBRACE)) {
            tokenList.consume();
            if (tokenList.ahead(0).getType().equals(TokenType.RBRACE)) {
                ret = new Unit.ArrayInitVal(new ArrayList<>());
            } else {
                ArrayList<Unit.Exp> exps = new ArrayList<>();
                exps.add(parseExp());
                while (tokenList.ahead(0).getType().equals(TokenType.COMMA)) {
                    tokenList.consume();
                    exps.add(parseExp());
                }
                tokenList.consume(TokenType.RBRACE);
                ret = new Unit.ArrayInitVal(exps);
            }
        } else if (tokenList.ahead(0).getType().equals(TokenType.STRCON)) {
            ret = new Unit.StringConst(tokenList.consume().getRawString());
        } else {
            ret = parseExp();
        }
        printSyntax("InitVal");
        return ret;
    }

    public Unit.FuncDef parseFuncDef() {
        String funcType = tokenList.consume(TokenType.INTTK, TokenType.CHARTK, TokenType.VOIDTK).getRawString();
        printSyntax("FuncType");
        String ident = tokenList.consume(TokenType.IDENFR).getRawString();
        tokenList.consume(TokenType.LPARENT);
        Unit.FuncFParams funcFParams = parseFuncFParams();
        if (!tokenList.ahead(0).getType().equals(TokenType.RPARENT)) {
            printError("j");
        }
        tokenList.consume(TokenType.RPARENT);
        Unit.Block block = parseBlock();
        printSyntax("FuncDef");
        return new Unit.FuncDef(funcType, ident, funcFParams, block);
    }

    public Unit.MainFuncDef parseMainFuncDef() {
        tokenList.consume(TokenType.INTTK);
        tokenList.consume(TokenType.MAINTK);
        tokenList.consume(TokenType.LPARENT);
        if (tokenList.consume(TokenType.RPARENT) == null) {
            printError("j");
        }
        Unit.Block block = parseBlock();
        printSyntax("MainFuncDef");
        return new Unit.MainFuncDef(block);
    }

    public Unit.FuncFParams parseFuncFParams() {
        ArrayList<Unit.FuncFParam> funcFParams = new ArrayList<>();
        while (tokenList.hasNext()) {
            if (tokenList.ahead(0).getType().equals(TokenType.RPARENT) || tokenList.ahead(0).getType().equals(TokenType.LBRACE)) {
                break;
            }
            funcFParams.add(parseFuncFParam());
            tokenList.consume(TokenType.COMMA);
        }
        if (!funcFParams.isEmpty()) {
            printSyntax("FuncFParams");
        }
        return new Unit.FuncFParams(funcFParams);
    }

    public Unit.FuncFParam parseFuncFParam() {
        String bType = tokenList.consume(TokenType.INTTK, TokenType.CHARTK).getRawString();
        String ident = tokenList.consume(TokenType.IDENFR).getRawString();
        if (tokenList.consume(TokenType.LBRACK) == null) {
            printSyntax("FuncFParam");
            return new Unit.FuncFParam(bType, ident, false);
        } else {
            if (tokenList.consume(TokenType.RBRACK) == null) {
                printError("k");
            }
            printSyntax("FuncFParam");
            return new Unit.FuncFParam(bType, ident, true);
        }
    }

    public Unit.Block parseBlock() {
        tokenList.consume(TokenType.LBRACE);
        ArrayList<Unit.BlockItem> blockItems = new ArrayList<>();
        while (tokenList.hasNext()) {
            if (tokenList.ahead(0).getType().equals(TokenType.RBRACE)) {
                break;
            }
            blockItems.add(parseBlockItem());
        }
        tokenList.consume(TokenType.RBRACE);
        printSyntax("Block");
        return new Unit.Block(blockItems);
    }

    public Unit.BlockItem parseBlockItem() {
        if (tokenList.ahead(0).getType().equals(TokenType.INTTK) || tokenList.ahead(0).getType().equals(TokenType.CHARTK) || tokenList.ahead(0).getType().equals(TokenType.CONSTTK)) {
            return parseDecl();
        } else {
            return parseStmt();
        }
    }

    public Unit.Stmt parseStmt() {
        Unit.Stmt ret;
        if (tokenList.ahead(0).getType().equals(TokenType.IFTK)) {
            tokenList.consume(TokenType.IFTK);
            tokenList.consume(TokenType.LPARENT);
            Unit.Cond cond = parseCond();
            if (tokenList.consume(TokenType.RPARENT) == null) {
                printError("j");
            }
            Unit.Stmt thenStmt = parseStmt();
            if (tokenList.ahead(0).getType().equals(TokenType.ELSETK)) {
                tokenList.consume(TokenType.ELSETK);
                Unit.Stmt elseStmt = parseStmt();
                ret = new Unit.IfStmt(cond, thenStmt, elseStmt);
            } else {
                ret = new Unit.IfStmt(cond, thenStmt, null);
            }
        } else if (tokenList.ahead(0).getType().equals(TokenType.FORTK)) {
            tokenList.consume(TokenType.FORTK);
            tokenList.consume(TokenType.LPARENT);
            Unit.ForStmt initForStmt;
            if (tokenList.ahead(0).getType().equals(TokenType.SEMICN)) {
                initForStmt = null;
            } else {
                initForStmt = parseForStmt();
            }
            tokenList.consume(TokenType.SEMICN);
            Unit.Cond cond;
            if (tokenList.ahead(0).getType().equals(TokenType.SEMICN)) {
                cond = null;
            } else {
                cond = parseCond();
            }
            tokenList.consume(TokenType.SEMICN);
            Unit.ForStmt updateForStmt;
            if (tokenList.ahead(0).getType().equals(TokenType.RPARENT)) {
                updateForStmt = null;
            } else {
                updateForStmt = parseForStmt();
            }
            // 可能要错误处理
            tokenList.consume(TokenType.RPARENT);
            Unit.Stmt bodyStmt = parseStmt();
            ret = new Unit.ForLoopStmt(initForStmt, cond, updateForStmt, bodyStmt);
        } else if (tokenList.ahead(0).getType().equals(TokenType.BREAKTK)) {
            tokenList.consume(TokenType.BREAKTK);
            if (tokenList.consume(TokenType.SEMICN) == null) {
                printError("i");
            }
            ret = new Unit.BreakStmt();
        } else if (tokenList.ahead(0).getType().equals(TokenType.CONTINUETK)) {
            tokenList.consume(TokenType.CONTINUETK);
            if (tokenList.consume(TokenType.SEMICN) == null) {
                printError("i");
            }
            ret = new Unit.ContinueStmt();
        } else if (tokenList.ahead(0).getType().equals(TokenType.RETURNTK)) {
            // 注：这里可能存在错误（错误处理少考虑了）
            tokenList.consume(TokenType.RETURNTK);
            Unit.Exp exp;
            if (tokenList.get().getType().equals(TokenType.SEMICN)) {
                tokenList.consume(TokenType.SEMICN);
                exp = null;
            } else if (tokenList.get().getType().equals(TokenType.LPARENT) || tokenList.get().getType().equals(TokenType.IDENFR) || tokenList.get().getType().equals(TokenType.PLUS) || tokenList.get().getType().equals(TokenType.MINU) || tokenList.get().getType().equals(TokenType.NOT) || tokenList.get().getType().equals(TokenType.INTCON) || tokenList.get().getType().equals(TokenType.CHRCON)) {
                exp = parseExp();
                if (tokenList.consume(TokenType.SEMICN) == null) {
                    printError("i");
                }
            } else {
                printError("i");
                exp = null;
            }
            ret = new Unit.ReturnStmt(exp);
        } else if (tokenList.get().getType().equals(TokenType.PRINTFTK)) {
            tokenList.consume(TokenType.PRINTFTK);
            tokenList.consume(TokenType.LPARENT);
            String stringConst = tokenList.consume(TokenType.STRCON).getRawString();
            ArrayList<Unit.Exp> exps = new ArrayList<>();
            while (tokenList.hasNext()) {
                if (tokenList.get().getType().equals(TokenType.COMMA)) {
                    tokenList.consume(TokenType.COMMA);
                    exps.add(parseExp());
                } else {
                    break;
                }
            }
            if (tokenList.consume(TokenType.RPARENT) == null) {
                printError("j");
            }
            if (tokenList.consume(TokenType.SEMICN) == null) {
                printError("i");
            }
            ret = new Unit.PrintfStmt(stringConst, exps);
        } else if (tokenList.get().getType().equals(TokenType.SEMICN)) {
            // 可能存在错误
            tokenList.consume(TokenType.SEMICN);
            ret = new Unit.ExpStmt(null);
        } else if (tokenList.get().getType().equals(TokenType.LBRACE)) {
            ret = parseBlock();
        } else {
            Unit.Exp exp = parseExp();
            if (tokenList.get().getType().equals(TokenType.ASSIGN)) {
                Unit.LVal lVal = fromExpToLVal(exp);
                int size = parsers.size();
                for (int i = 0; i < 5 && size - i > 0; i++) {
                    parsers.remove(parsers.size() - 1);
                }

                tokenList.consume(TokenType.ASSIGN);
                if (tokenList.get().getType().equals(TokenType.GETINTTK)) {
                    tokenList.consume(TokenType.GETINTTK);
                    tokenList.consume(TokenType.LPARENT);
                    if (tokenList.consume(TokenType.RPARENT) == null) {
                        printError("j");
                    }
                    if (tokenList.consume(TokenType.SEMICN) == null) {
                        printError("i");
                    }
                    ret = new Unit.GetIntStmt(lVal);
                } else if (tokenList.get().getType().equals(TokenType.GETCHARTK)) {
                    tokenList.consume(TokenType.GETCHARTK);
                    tokenList.consume(TokenType.LPARENT);
                    if (tokenList.consume(TokenType.RPARENT) == null) {
                        printError("j");
                    }
                    if (tokenList.consume(TokenType.SEMICN) == null) {
                        printError("i");
                    }
                    ret = new Unit.GetCharStmt(lVal);
                } else {
                    Unit.Exp rExp = parseExp();
                    if (tokenList.consume(TokenType.SEMICN) == null) {
                        printError("i");
                    }
                    ret = new Unit.AssignStmt(lVal, rExp);
                }
            } else {
                if (tokenList.consume(TokenType.SEMICN) == null) {
                    printError("i");
                }
                ret = new Unit.ExpStmt(exp);
            }
        }
        printSyntax("Stmt");
        return ret;
    }

    public Unit.ForStmt parseForStmt() {
        Unit.LVal lVal = parseLVal();
        tokenList.consume(TokenType.ASSIGN);
        Unit.Exp exp = parseExp();
        printSyntax("ForStmt");
        return new Unit.ForStmt(lVal, exp);
    }

    public Unit.Exp parseExp() {
        Unit.Exp ret = parseAddExp();
        printSyntax("Exp");
        return ret;
    }

    public Unit.Cond parseCond() {
        Unit.Cond ret = parseLOrExp();
        printSyntax("Cond");
        return ret;
    }

    public Unit.LVal parseLVal() {
        String ident = tokenList.consume(TokenType.IDENFR).getRawString();
        Unit.Exp exp = null;
        if (tokenList.get().getType().equals(TokenType.LBRACK)) {
            tokenList.consume(TokenType.LBRACK);
            exp = parseExp();
            if (tokenList.consume(TokenType.RBRACK) == null) {
                printError("k");
            }
        }
        printSyntax("LVal");
        return new Unit.LVal(ident, exp);
    }

    public Unit.PrimaryExp parsePrimaryExp() {
        Unit.PrimaryExp ret;
        if (tokenList.get().getType().equals(TokenType.LPARENT)) {
            tokenList.consume(TokenType.LPARENT);
            Unit.Exp exp = parseExp();
            if (tokenList.consume(TokenType.RPARENT) == null) {
                printError("j");
            }
            ret = new Unit.BracePrimaryExp(exp);
        } else if (tokenList.get().getType().equals(TokenType.INTCON)) {
            int number = tokenList.consume().getInt();
            printSyntax("Number");
            ret = new Unit.Number(number);
        } else if (tokenList.get().getType().equals(TokenType.CHRCON)) {
            char c = tokenList.consume().getChar();
            printSyntax("Character");
            ret = new Unit.Character(c);
        } else {
            ret = parseLVal();
        }
        printSyntax("PrimaryExp");
        return ret;
    }

    public Unit.UnaryExp parseUnaryExp() {
        ArrayList<String> unaryOps = new ArrayList<>();
        while (tokenList.hasNext()) {
            Token token = tokenList.consume(TokenType.PLUS, TokenType.MINU, TokenType.NOT);
            if (token == null) {
                break;
            } else {
                unaryOps.add(token.getRawString());
                printSyntax("UnaryOp");
            }
        }
        Unit.SingleUnaryExp singleUnaryExp = parseSingleUnaryExp();
        for (int i = 0; i < unaryOps.size(); i++) {
            printSyntax("UnaryExp");
        }
        printSyntax("UnaryExp");
        return new Unit.UnaryExp(unaryOps, singleUnaryExp);
    }

    public Unit.SingleUnaryExp parseSingleUnaryExp() {
        if (tokenList.get().getType().equals(TokenType.IDENFR) && tokenList.ahead(1).getType().equals(TokenType.LPARENT)) {
            return parseFuncCall();
        } else {
            return parsePrimaryExp();
        }
    }

    public Unit.FuncCall parseFuncCall() {
        String ident = tokenList.consume(TokenType.IDENFR).getRawString();
        tokenList.consume(TokenType.LPARENT);
        if (tokenList.get().getType().equals(TokenType.RPARENT)) {
            tokenList.consume(TokenType.RPARENT);
            return new Unit.FuncCall(ident, new Unit.FuncRParams(new ArrayList<>()));
        } else if (tokenList.get().getType().equals(TokenType.LPARENT) || tokenList.get().getType().equals(TokenType.IDENFR) || tokenList.get().getType().equals(TokenType.PLUS) || tokenList.get().getType().equals(TokenType.MINU) || tokenList.get().getType().equals(TokenType.NOT) || tokenList.get().getType().equals(TokenType.INTCON) || tokenList.get().getType().equals(TokenType.CHRCON)) {
            Unit.FuncRParams funcRParams = parseFuncRParams();
            if (tokenList.consume(TokenType.RPARENT) == null) {
                printError("j");
            }
            return new Unit.FuncCall(ident, funcRParams);
        } else {
            tokenList.consume(TokenType.RPARENT);
            printError("j");
            return new Unit.FuncCall(ident, new Unit.FuncRParams(new ArrayList<>()));
        }
    }

    public Unit.FuncRParams parseFuncRParams() {
        ArrayList<Unit.Exp> exps = new ArrayList<>();
        exps.add(parseExp());
        while (tokenList.hasNext()) {
            if (tokenList.get().getType().equals(TokenType.COMMA)) {
                tokenList.consume(TokenType.COMMA);
                exps.add(parseExp());
            } else {
                break;
            }
        }
        printSyntax("FuncRParams");
        return new Unit.FuncRParams(exps);
    }

    public Unit.MulExp parseMulExp() {
        ArrayList<Unit.UnaryExp> unaryExps = new ArrayList<>();
        ArrayList<String> ops = new ArrayList<>();
        unaryExps.add(parseUnaryExp());
        printSyntax("MulExp");
        while (tokenList.hasNext()) {
            Token token = tokenList.consume(TokenType.MULT, TokenType.DIV, TokenType.MOD);
            if (token == null) {
                break;
            }
            ops.add(token.getRawString());
            unaryExps.add(parseUnaryExp());
            printSyntax("MulExp");
        }
        return new Unit.MulExp(unaryExps, ops);
    }

    public Unit.AddExp parseAddExp() {
        ArrayList<Unit.MulExp> mulExps = new ArrayList<>();
        ArrayList<String> ops = new ArrayList<>();
        mulExps.add(parseMulExp());
        printSyntax("AddExp");
        while (tokenList.hasNext()) {
            Token token = tokenList.consume(TokenType.PLUS, TokenType.MINU);
            if (token == null) {
                break;
            }
            ops.add(token.getRawString());
            mulExps.add(parseMulExp());
            printSyntax("AddExp");
        }
        return new Unit.AddExp(mulExps, ops);
    }

    public Unit.RelExp parseRelExp() {
        ArrayList<Unit.AddExp> addExps = new ArrayList<>();
        ArrayList<String> ops = new ArrayList<>();
        addExps.add(parseAddExp());
        printSyntax("RelExp");
        while (tokenList.hasNext()) {
            Token token = tokenList.consume(TokenType.GRE, TokenType.LSS, TokenType.GEQ, TokenType.LEQ);
            if (token == null) {
                break;
            }
            ops.add(token.getRawString());
            addExps.add(parseAddExp());
            printSyntax("RelExp");
        }
        return new Unit.RelExp(addExps, ops);
    }

    public Unit.EqExp parseEqExp() {
        ArrayList<Unit.RelExp> relExps = new ArrayList<>();
        ArrayList<String> ops = new ArrayList<>();
        relExps.add(parseRelExp());
        printSyntax("EqExp");
        while (tokenList.hasNext()) {
            Token token = tokenList.consume(TokenType.EQL, TokenType.NEQ);
            if (token == null) {
                break;
            }
            ops.add(token.getRawString());
            relExps.add(parseRelExp());
            printSyntax("EqExp");
        }
        return new Unit.EqExp(relExps, ops);
    }

    public Unit.LAndExp parseLAndExp() {
        ArrayList<Unit.EqExp> eqExps = new ArrayList<>();
        eqExps.add(parseEqExp());
        printSyntax("LAndExp");
        while (tokenList.hasNext()) {
            Token token = tokenList.consume(TokenType.AND);
            if (token == null) {
                break;
            }
            eqExps.add(parseEqExp());
            printSyntax("LAndExp");
        }
        return new Unit.LAndExp(eqExps);
    }

    public Unit.LOrExp parseLOrExp() {
        ArrayList<Unit.LAndExp> lAndExps = new ArrayList<>();
        lAndExps.add(parseLAndExp());
        printSyntax("LOrExp");
        while (tokenList.hasNext()) {
            Token token = tokenList.consume(TokenType.OR);
            if (token == null) {
                break;
            }
            lAndExps.add(parseLAndExp());
            printSyntax("LOrExp");
        }
        return new Unit.LOrExp(lAndExps);
    }

    public Unit.ConstExp parseConstExp() {
        Unit.ConstExp ret = parseAddExp();
        printSyntax("ConstExp");
        return ret;
    }

    public Unit.LVal fromExpToLVal(Unit.Exp exp) {
        return (Unit.LVal) (((Unit.AddExp) exp).mulExps().get(0).unaryExps().get(0).singleUnaryExp());
    }

    public void printError(String s) {
//        try {
//            errorWriter.write(tokenList.ahead(-1).getLine() + " " + s);
//            errorWriter.newLine();
//        } catch (IOException e) {
//            throw new RuntimeException(e);
//        }
        errors.put(tokenList.ahead(-1).getLine(), s);
    }

    public void printParser(String s) {
//        try {
//            parserWriter.write(s);
//            parserWriter.newLine();
//        } catch (IOException e) {
//            throw new RuntimeException(e);
//        }
        parsers.add(s);
    }

    public void printSyntax(String s) {
        printParser("<" + s + ">");
    }
}

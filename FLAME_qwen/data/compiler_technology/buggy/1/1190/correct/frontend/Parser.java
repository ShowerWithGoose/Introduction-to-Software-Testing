package frontend;

import frontend.Nodes.Character;
import frontend.Nodes.Number;
import frontend.Nodes.*;

import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.util.List;

public class Parser {
    private final List<Token> tokens;
    private int currentTokenIndex;
    private Token currentToken;
    private CompUnit compUnit;

    public Parser(Lexer lexer) {
        this.tokens = lexer.getTokens();
        this.currentTokenIndex = 0;
        this.currentToken = tokens.get(0);
        this.compUnit = parseCompUnit();
    }

    public CompUnit getCompUnit() {
        return compUnit;
    }

    public void print() throws Exception {
        OutputStreamWriter writer1 = new OutputStreamWriter(new FileOutputStream("parser.txt"));
        OutputStreamWriter writer2 = new OutputStreamWriter(new FileOutputStream("error.txt"));
        writer1.write(compUnit.toString());
        writer2.write(compUnit.error());
        writer1.close();
        writer2.close();
    }

    // TODO: index越界问题

    private Token currentToken() {
        return currentToken;
    }

    private Token peekToken(int number) {
        if (currentTokenIndex + number >= tokens.size()) {
            return tokens.get(tokens.size() - 1);
        }
        if (currentTokenIndex + number < 0) {
            return tokens.get(0);
        }
        return tokens.get(currentTokenIndex + number);
    }

    private void advance() {
        currentTokenIndex++;
        if (currentTokenIndex >= tokens.size()) {
            currentTokenIndex = tokens.size() - 1;
        }
        currentToken = tokens.get(currentTokenIndex);
    }

    private boolean match(Token.Type type) {
        return currentToken.getType() == type;
    }

    private CompUnit parseCompUnit() {
        CompUnit compUnit = new CompUnit();
        while (match(Token.Type.CONSTTK) ||
                ((match(Token.Type.INTTK) || match(Token.Type.CHARTK)) &&
                        (peekToken(2).getType() == Token.Type.LBRACK ||
                                peekToken(2).getType() == Token.Type.COMMA ||
                                peekToken(2).getType() == Token.Type.SEMICN ||
                                peekToken(2).getType() == Token.Type.ASSIGN))) {
            compUnit.addDecl(parseDecl()); // {Decl}
        }
        while (peekToken(1).getType() != Token.Type.MAINTK) {
            compUnit.addFuncDef(parseFuncDef()); // {FuncDef}
        }
        compUnit.addMainFuncDef(parseMainFuncDef()); // MainFuncDef
        return compUnit;
    }

    private Decl parseDecl() {
        Decl decl = new Decl();
        if (match(Token.Type.CONSTTK)) {
            decl.setType(1);
            decl.addConstDecl(parseConstDecl()); // ConstDecl
        } else {
            decl.setType(2);
            decl.addVarDecl(parseVarDecl()); // VarDecl
        }
        return decl;
    }

    private ConstDecl parseConstDecl() {
        ConstDecl constDecl = new ConstDecl();
        constDecl.addConstToken(currentToken()); // 'const'
        advance();
        constDecl.addBType(parseBType()); // BType
        constDecl.addConstDef(parseConstDef()); // ConstDef
        while (match(Token.Type.COMMA)) {
            constDecl.addComma(currentToken()); // ','
            advance();
            constDecl.addConstDef(parseConstDef()); // ConstDef
        }
        if (match(Token.Type.SEMICN)) {
            constDecl.addSemicn(currentToken()); // ';'
            advance();
        } else {
            peekToken(-1).setErrorCode('i');
        }
        return constDecl;
    }

    private VarDecl parseVarDecl() {
        VarDecl varDecl = new VarDecl();
        varDecl.addBType(parseBType()); // BType
        varDecl.addVarDef(parseVarDef()); // VarDef
        while (match(Token.Type.COMMA)) {
            varDecl.addComma(currentToken()); // ','
            advance();
            varDecl.addVarDef(parseVarDef()); // VarDef
        }
        if (match(Token.Type.SEMICN)) {
            varDecl.addSemicn(currentToken()); // ';'
            advance();
        } else {
            peekToken(-1).setErrorCode('i');
        }
        return varDecl;
    }

    private ConstDef parseConstDef() {
        ConstDef constDef = new ConstDef();
        constDef.addIdent(currentToken()); // Ident
        advance();
        if (currentToken().getType() == Token.Type.LBRACK) {
            constDef.addLBrack(currentToken()); // '['
            advance();
            constDef.addConstExp(parseConstExp()); // ConstExp
            if (match(Token.Type.RBRACK)) {
                constDef.addRBrack(currentToken()); // ']'
                advance();
            } else {
                peekToken(-1).setErrorCode('k');
            }
        }
        constDef.addAssign(currentToken()); // '='
        advance();
        constDef.addConstInitVal(parseConstInitVal()); // ConstInitVal
        return constDef;
    }

    private VarDef parseVarDef() {
        VarDef varDef = new VarDef();
        varDef.addIdent(currentToken()); // Ident
        advance();
        if (match(Token.Type.LBRACK)) {
            varDef.addLBrack(currentToken()); // '['
            advance();
            varDef.addConstExp(parseConstExp()); // ConstExp
            if (match(Token.Type.RBRACK)) {
                varDef.addRBrack(currentToken()); // ']'
                advance();
            } else {
                peekToken(-1).setErrorCode('k');
            }
        }
        varDef.setType(1);
        if (match(Token.Type.ASSIGN)) {
            varDef.setType(2);
            varDef.addAssign(currentToken()); // '='
            advance();
            varDef.addInitVal(parseInitVal()); // InitVal
        }
        return varDef;
    }

    private ConstInitVal parseConstInitVal() {
        ConstInitVal constInitVal = new ConstInitVal();
        if (match(Token.Type.LBRACE)) {
            constInitVal.setType(2);
            constInitVal.addLBrace(currentToken()); // '{'
            advance();
            if (!match(Token.Type.RBRACE)) {
                constInitVal.addConstExpList(parseConstExp()); // ConstExp
                while (match(Token.Type.COMMA)) {
                    constInitVal.addCommaList(currentToken()); // ','
                    advance();
                    constInitVal.addConstExpList(parseConstExp()); // ConstExp
                }
            }
            constInitVal.addRBrace(currentToken()); // '}'
            advance();
        } else if (match(Token.Type.STRCON)) {
            constInitVal.setType(3);
            constInitVal.addStringConst(currentToken()); // STRCON
            advance();
        } else {
            constInitVal.setType(1);
            constInitVal.addConstExp(parseConstExp()); // ConstExp
        }
        return constInitVal;
    }

    private InitVal parseInitVal() {
        InitVal initVal = new InitVal();
        if (match(Token.Type.LBRACE)) {
            initVal.setType(2);
            initVal.addLBrace(currentToken()); // '{'
            advance();
            if (!match(Token.Type.RBRACE)) {
                initVal.addExpList(parseExp()); // Exp
                while (match(Token.Type.COMMA)) {
                    initVal.addCommaList(currentToken()); // ','
                    advance();
                    initVal.addExpList(parseExp()); // Exp
                }
            }
            initVal.addRBrace(currentToken()); // '}'
            advance();
        } else if (match(Token.Type.STRCON)) {
            initVal.setType(3);
            initVal.addStringConst(currentToken()); // StringConst
            advance();
        } else {
            initVal.setType(1);
            initVal.addExp(parseExp()); // Exp
        }
        return initVal;
    }

    private FuncDef parseFuncDef() {
        FuncDef funcDef = new FuncDef();
        funcDef.addFuncType(parseFuncType()); // FuncType
        funcDef.addIdent(currentToken()); // Ident
        advance();
        funcDef.addLParent(currentToken()); // '('
        advance();
        if (match(Token.Type.INTTK) || match(Token.Type.CHARTK)) {
            funcDef.addFuncFParams(parseFuncFParams()); // FuncFParams
        }
        if (match(Token.Type.RPARENT)) {
            funcDef.addRParent(currentToken()); // ')'
            advance();
        } else {
            peekToken(-1).setErrorCode('j');
        }
        funcDef.addBlock(parseBlock()); // Block
        return funcDef;
    }

    private MainFuncDef parseMainFuncDef() {
        MainFuncDef mainFuncDef = new MainFuncDef();
        mainFuncDef.addInt(currentToken()); // 'int'
        advance();
        mainFuncDef.addMain(currentToken()); // 'main'
        advance();
        mainFuncDef.addLParent(currentToken()); // '('
        advance();
        if (match(Token.Type.RPARENT)) {
            mainFuncDef.addRParent(currentToken()); // ')'
            advance();
        } else {
            peekToken(-1).setErrorCode('j');
        }
        mainFuncDef.addBlock(parseBlock()); // Block
        return mainFuncDef;
    }

    private FuncType parseFuncType() {
        FuncType funcType = new FuncType();
        funcType.addType(currentToken()); // 'void' | 'int' | 'char'
        advance();
        return funcType;
    }

    private FuncFParams parseFuncFParams() {
        FuncFParams funcFParams = new FuncFParams();
        funcFParams.addFuncFParam(parseFuncFParam()); // FuncFParam
        while (match(Token.Type.COMMA)) {
            funcFParams.addComma(currentToken()); // ','
            advance();
            funcFParams.addFuncFParam(parseFuncFParam()); // FuncFParam
        }
        return funcFParams;
    }

    private FuncFParam parseFuncFParam() {
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.addBType(parseBType()); // BType
        funcFParam.addIdent(currentToken()); // Ident
        advance();
        if (match(Token.Type.LBRACK)) {
            funcFParam.addLBrack(currentToken()); // '['
            advance();
            if (match(Token.Type.RBRACK)) {
                funcFParam.addRBrack(currentToken()); // ']'
                advance();
            } else {
                peekToken(-1).setErrorCode('k');
            }
        }
        return funcFParam;
    }

    private Block parseBlock() {
        Block block = new Block();
        block.addLBrace(currentToken()); // '{'
        advance();
        while (!match(Token.Type.RBRACE)) {
            block.addBlockItem(parseBlockItem()); // BlockItem
        }
        block.addRBrace(currentToken()); // '}'
        advance();
        return block;
    }

    private BlockItem parseBlockItem() {
        BlockItem blockItem = new BlockItem();
        if (match(Token.Type.CONSTTK) ||
                match(Token.Type.INTTK) ||
                match(Token.Type.CHARTK)) {
            blockItem.setType(1);
            blockItem.addDecl(parseDecl()); // Decl
        } else {
            blockItem.setType(2);
            blockItem.addStmt(parseStmt()); // Stmt
        }
        return blockItem;
    }

    private Stmt parseStmt() {
        Stmt stmt = new Stmt();
        switch (currentToken().getType()) {
            case IDENFR:
                Exp tmpExp = parseExp();
                if (!match(Token.Type.ASSIGN)) {
                    stmt.setType(2);
                    stmt.addExp(tmpExp); // Exp
                    if (match(Token.Type.SEMICN)) {
                        stmt.addSemicn(currentToken()); // ';'
                        advance();
                    } else {
                        peekToken(-1).setErrorCode('i');
                    }
                    break;
                }
                stmt.addLVal(tmpExp.getAddExp().getMulExp().getUnaryExp().getPrimaryExp().getLVal()); // LVal
                stmt.addAssign(currentToken()); // '='
                advance();
                if (match(Token.Type.GETINTTK)) {
                    stmt.setType(9);
                    stmt.addToken(currentToken()); // 'getint'
                    advance();
                    stmt.addLParent(currentToken()); // '('
                    advance();
                    if (match(Token.Type.RPARENT)) {
                        stmt.addRParent(currentToken()); // ')'
                        advance();
                    } else {
                        peekToken(-1).setErrorCode('j');
                    }
                } else if (match(Token.Type.GETCHARTK)) {
                    stmt.setType(10);
                    stmt.addToken(currentToken()); // 'getchar'
                    advance();
                    stmt.addLParent(currentToken()); // '('
                    advance();
                    if (match(Token.Type.RPARENT)) {
                        stmt.addRParent(currentToken()); // ')'
                        advance();
                    } else {
                        peekToken(-1).setErrorCode('j');
                    }
                } else {
                    stmt.setType(1);
                    stmt.addExp(parseExp()); // Exp
                }
                if (match(Token.Type.SEMICN)) {
                    stmt.addSemicn(currentToken()); // ';'
                    advance();
                } else {
                    peekToken(-1).setErrorCode('i');
                }
                break;
            case LBRACE:
                stmt.setType(3);
                stmt.addBlock(parseBlock()); // Block
                break;
            case IFTK:
                stmt.setType(4);
                stmt.addToken(currentToken()); // 'if'
                advance();
                stmt.addLParent(currentToken()); // '('
                advance();
                stmt.addCond(parseCond()); // Cond
                if (match(Token.Type.RPARENT)) {
                    stmt.addRParent(currentToken()); // ')'
                    advance();
                } else {
                    peekToken(-1).setErrorCode('j');
                }
                stmt.addStmt(parseStmt()); // Stmt
                if (match(Token.Type.ELSETK)) {
                    stmt.addElseToken(currentToken()); // 'else'
                    advance();
                    stmt.addElseStmt(parseStmt()); // Stmt
                }
                break;
            case FORTK:
                stmt.setType(5);
                stmt.addToken(currentToken()); // 'for'
                advance();
                stmt.addLParent(currentToken()); // '('
                advance();
                if (!match(Token.Type.SEMICN)) {
                    stmt.addForStmt1(parseForStmt()); // ForStmt
                }
                stmt.addForSemicn1(currentToken()); // ';'
                advance();
                if (!match(Token.Type.SEMICN)) {
                    stmt.addCond(parseCond()); // Cond
                }
                stmt.addForSemicn2(currentToken()); // ';'
                advance();
                if (!match(Token.Type.RPARENT)) {
                    stmt.addForStmt2(parseForStmt()); // ForStmt
                }
                stmt.addRParent(currentToken()); // ')'
                advance();
                stmt.addStmt(parseStmt()); // Stmt
                break;
            case BREAKTK:
                stmt.setType(6);
                stmt.addToken(currentToken()); // 'break'
                advance();
                if (match(Token.Type.SEMICN)) {
                    stmt.addSemicn(currentToken()); // ';'
                    advance();
                } else {
                    peekToken(-1).setErrorCode('i');
                }
                break;
            case CONTINUETK:
                stmt.setType(7);
                stmt.addToken(currentToken()); // 'continue'
                advance();
                if (match(Token.Type.SEMICN)) {
                    stmt.addSemicn(currentToken()); // ';'
                    advance();
                } else {
                    peekToken(-1).setErrorCode('i');
                }
                break;
            case RETURNTK:
                stmt.setType(8);
                stmt.addToken(currentToken()); // 'return'
                advance();
                if (match(Token.Type.LPARENT) || match(Token.Type.IDENFR) ||
                        match(Token.Type.INTCON) || match(Token.Type.CHRCON) ||
                        match(Token.Type.PLUS) || match(Token.Type.MINU) || match(Token.Type.NOT)) {
                    stmt.addExp(parseExp()); // Exp
                }
                if (match(Token.Type.SEMICN)) {
                    stmt.addSemicn(currentToken()); // ';'
                    advance();
                } else {
                    peekToken(-1).setErrorCode('i');
                }
                break;
            case PRINTFTK:
                stmt.setType(11);
                stmt.addToken(currentToken()); // 'printf'
                advance();
                stmt.addLParent(currentToken()); // '('
                advance();
                stmt.addStringConst(currentToken()); // StringConst
                advance();
                while (match(Token.Type.COMMA)) {
                    stmt.addCommaList(currentToken()); // ','
                    advance();
                    stmt.addExpList(parseExp()); // Exp
                }
                if (match(Token.Type.RPARENT)) {
                    stmt.addRParent(currentToken()); // ')'
                    advance();
                } else {
                    peekToken(-1).setErrorCode('j');
                }
                if (match(Token.Type.SEMICN)) {
                    stmt.addSemicn(currentToken()); // ';'
                    advance();
                } else {
                    peekToken(-1).setErrorCode('i');
                }
                break;
            default:
                stmt.setType(2);
                if (!match(Token.Type.SEMICN)) {
                    stmt.addExp(parseExp()); // Exp
                    if (match(Token.Type.SEMICN)) {
                        stmt.addSemicn(currentToken()); // ';'
                        advance();
                    } else {
                        peekToken(-1).setErrorCode('i');
                    }
                    break;
                }
                assert match(Token.Type.SEMICN);
                stmt.addSemicn(currentToken()); // ';'
                advance();
                break;
        }
        return stmt;
    }

    private ForStmt parseForStmt() {
        ForStmt forStmt = new ForStmt();
        forStmt.addLVal(parseLVal()); // LVal
        forStmt.addAssign(currentToken()); // '='
        advance();
        forStmt.addExp(parseExp()); // Exp
        return forStmt;
    }

    private Exp parseExp() {
        Exp exp = new Exp();
        exp.addAddExp(parseAddExp()); // AddExp
        return exp;
    }

    private Cond parseCond() {
        Cond cond = new Cond();
        cond.addLOrExp(parseLOrExp()); // LOrExp
        return cond;
    }

    private LVal parseLVal() {
        LVal lVal = new LVal();
        lVal.addIdent(currentToken()); // Ident
        advance();
        if (match(Token.Type.LBRACK)) {
            lVal.addLBrack(currentToken()); // '['
            advance();
            lVal.addExp(parseExp()); // Exp
            if (match(Token.Type.RBRACK)) {
                lVal.addRBrack(currentToken()); // ']'
                advance();
            } else {
                peekToken(-1).setErrorCode('k');
            }
        }
        return lVal;
    }

    private PrimaryExp parsePrimaryExp() {
        PrimaryExp primaryExp = new PrimaryExp();
        switch (currentToken().getType()) {
            case LPARENT:
                primaryExp.setType(1);
                primaryExp.addLParent(currentToken()); // '('
                advance();
                primaryExp.addExp(parseExp()); // Exp
                if (match(Token.Type.RPARENT)) {
                    primaryExp.addRParent(currentToken()); // ')'
                    advance();
                } else {
                    peekToken(-1).setErrorCode('j');
                }
                break;
            case IDENFR:
                primaryExp.setType(2);
                primaryExp.addLVal(parseLVal()); // LVal
                break;
            case INTCON:
                primaryExp.setType(3);
                primaryExp.addNumber(parseNumber()); // Number
                break;
            case CHRCON:
                primaryExp.setType(4);
                primaryExp.addCharacter(parseCharacter()); // Character
                break;
            default:
                break;
        }
        return primaryExp;
    }

    private Number parseNumber() {
        Number number = new Number();
        number.addIntConst(currentToken()); // IntConst
        advance();
        return number;
    }

    private Character parseCharacter() {
        Character character = new Character();
        character.addCharConst(currentToken()); // CharConst
        advance();
        return character;
    }

    private UnaryExp parseUnaryExp() {
        UnaryExp unaryExp = new UnaryExp();
        if (match(Token.Type.PLUS) || match(Token.Type.MINU) || match(Token.Type.NOT)) {
            unaryExp.setType(3);
            unaryExp.addUnaryOp(parseUnaryOp()); // '+' | '-' | '!'
            unaryExp.addUnaryExp(parseUnaryExp()); // UnaryExp
        } else if (match(Token.Type.IDENFR) &&
                peekToken(1).getType() == Token.Type.LPARENT) {
            unaryExp.setType(2);
            unaryExp.addIdent(currentToken()); // Ident
            advance();
            unaryExp.addLParent(currentToken()); // '('
            advance();
            if (match(Token.Type.LPARENT) || match(Token.Type.IDENFR) ||
                    match(Token.Type.INTCON) || match(Token.Type.CHRCON) ||
                    match(Token.Type.PLUS) || match(Token.Type.MINU) || match(Token.Type.NOT)) {
                unaryExp.addFuncRParams(parseFuncRParams()); // FuncRParams
            }
            if (match(Token.Type.RPARENT)) {
                unaryExp.addRParent(currentToken()); // ')'
                advance();
            } else {
                peekToken(-1).setErrorCode('j');
            }
        } else {
            unaryExp.setType(1);
            unaryExp.addPrimaryExp(parsePrimaryExp()); // PrimaryExp
        }
        return unaryExp;
    }

    private UnaryOp parseUnaryOp() {
        UnaryOp unaryOp = new UnaryOp();
        unaryOp.addOp(currentToken()); // '+' | '-' | '!'
        advance();
        return unaryOp;
    }

    private FuncRParams parseFuncRParams() {
        FuncRParams funcRParams = new FuncRParams();
        funcRParams.addExp(parseExp()); // Exp
        while (match(Token.Type.COMMA)) {
            funcRParams.addComma(currentToken()); // ','
            advance();
            funcRParams.addExp(parseExp()); // Exp
        }
        return funcRParams;
    }

    private MulExp parseMulExp() {
        MulExp mulExp = new MulExp();
        mulExp.addUnaryExp(parseUnaryExp()); // UnaryExp
        while (match(Token.Type.MULT) || match(Token.Type.DIV) || match(Token.Type.MOD)) {
            mulExp.addOp(currentToken()); // '*' | '/' | '%'
            advance();
            mulExp.addUnaryExp(parseUnaryExp()); // UnaryExp
        }
        return mulExp;
    }

    private AddExp parseAddExp() {
        AddExp addExp = new AddExp();
        addExp.addMulExp(parseMulExp()); // MulExp
        while (match(Token.Type.PLUS) || match(Token.Type.MINU)) {
            addExp.addOp(currentToken()); // '+' | '-'
            advance();
            addExp.addMulExp(parseMulExp()); // MulExp
        }
        return addExp;
    }

    private RelExp parseRelExp() {
        RelExp relExp = new RelExp();
        relExp.addAddExp(parseAddExp()); // AddExp
        while (match(Token.Type.LSS) || match(Token.Type.GRE) || match(Token.Type.LEQ) || match(Token.Type.GEQ)) {
            relExp.addOp(currentToken()); // '<' | '>' | '<=' | '>='
            advance();
            relExp.addAddExp(parseAddExp()); // AddExp
        }
        return relExp;
    }

    private EqExp parseEqExp() {
        EqExp eqExp = new EqExp();
        eqExp.addRelExp(parseRelExp()); // RelExp
        while (match(Token.Type.EQL) || match(Token.Type.NEQ)) {
            eqExp.addOp(currentToken()); // '==' | '!='
            advance();
            eqExp.addRelExp(parseRelExp()); // RelExp
        }
        return eqExp;
    }

    private LAndExp parseLAndExp() {
        LAndExp lAndExp = new LAndExp();
        lAndExp.addEqExp(parseEqExp()); // EqExp
        while (match(Token.Type.AND)) {
            lAndExp.addOp(currentToken()); // '&&'
            advance();
            lAndExp.addEqExp(parseEqExp()); // EqExp
        }
        return lAndExp;
    }

    private LOrExp parseLOrExp() {
        LOrExp lOrExp = new LOrExp();
        lOrExp.addLAndExp(parseLAndExp()); // LAndExp
        while (match(Token.Type.OR)) {
            lOrExp.addOp(currentToken()); // '||'
            advance();
            lOrExp.addLAndExp(parseLAndExp()); // LAndExp
        }
        return lOrExp;
    }

    private ConstExp parseConstExp() {
        ConstExp constExp = new ConstExp();
        constExp.addAddExp(parseAddExp()); // AddExp
        return constExp;
    }

    private BType parseBType() {
        BType bType = new BType();
        bType.addBType(currentToken()); // 'int' | 'char'
        advance();
        return bType;
    }
}

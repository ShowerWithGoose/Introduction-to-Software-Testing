package frontend;

import frontend.GrammaticalElements.CompUnit;
import frontend.GrammaticalElements.UnaryOp;
import frontend.GrammaticalElements.declaration.*;
import frontend.GrammaticalElements.expression.*;
import frontend.GrammaticalElements.function.FuncFParam;
import frontend.GrammaticalElements.function.FuncFParams;
import frontend.GrammaticalElements.function.FuncRParams;
import frontend.GrammaticalElements.function.FuncType;
import frontend.GrammaticalElements.statement.*;
import frontend.GrammaticalElements.terminal.Character;
import frontend.GrammaticalElements.terminal.Number;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class Parser {
    private boolean errorState = true;
    private CompUnit compUnit;
    private Lexer lexer;
    private Token last;
    private Token now;
    private Token preRead;
    private Token prePreRead;
    private ArrayList<Token> tokens;
    private int cur = 0;

    public Parser(ArrayList<Token> tokens, Lexer lexer) {
        last = null;
        this.tokens = tokens;
        this.lexer = lexer;
        if (this.hasToken()) {
            now = this.tokens.get(cur++);
        } else {
            now = null;
        }
        if (this.hasToken()) {
            preRead = this.tokens.get(cur++);
        } else {
            preRead = null;
        }
        if (this.hasToken()) {
            prePreRead = this.tokens.get(cur++);
        } else {
            prePreRead = null;
        }
    }

    private boolean hasToken() {
        return cur < tokens.size();
    }

    private void getToken() {
        if (this.hasToken()) {
            last = now;
            now = preRead;
            preRead = prePreRead;
            prePreRead = this.tokens.get(cur++);
        } else {
            last = now;
            now = preRead;
            preRead = prePreRead;
            prePreRead = null;
        }
    }

    private void backTracking(int tmpCur) {
        last = this.tokens.get(tmpCur - 4);
        now = this.tokens.get(tmpCur - 3);
        preRead = this.tokens.get(tmpCur - 2);
        prePreRead = this.tokens.get(tmpCur - 1);
        cur = tmpCur;
    }

    public void syntaxAnalysis() {
        if (now == null) {
            return;
        }
        this.compUnit = parseCompUnit();
        String content = this.compUnit.toString();
        String filePath = "parser.txt";
        try {
            Files.write(Paths.get(filePath), content.getBytes(), StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING);
        } catch (IOException e) {
            throw new RuntimeException("Failed to write content to file.", e);
        }
        lexer.errorOutput();
    }

    public CompUnit parseCompUnit() {
        ArrayList<Decl> decls = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        while (now.getType() == TokenType.CONSTTK || now.getType() == TokenType.INTTK || now.getType() == TokenType.CHARTK) {
            if (now.getType() == TokenType.CONSTTK) {
                decls.add(parseDecl());
                // this.compUnit.addDecl(parseDecl());
            } else if (preRead.getType() == TokenType.IDENFR && (prePreRead.getType() != TokenType.LPARENT)/*(prePreRead.getType() == TokenType.ASSIGN || prePreRead.getType() == TokenType.COMMA || prePreRead.getType() == TokenType.SEMICN)*/) {
                decls.add(parseDecl());
                // this.compUnit.addDecl(parseDecl());
            } else {
                break;
            }
        }
        while (now.getType() == TokenType.VOIDTK || now.getType() == TokenType.INTTK || now.getType() == TokenType.CHARTK) {
            if (now.getType() == TokenType.VOIDTK) {
                funcDefs.add(parseFuncDef());
                // this.compUnit.addFuncDef(parseFuncDef());
            } else if (preRead.getType() == TokenType.IDENFR && prePreRead.getType() == TokenType.LPARENT) {
                funcDefs.add(parseFuncDef());
                // this.compUnit.addFuncDef(parseFuncDef());
            } else {
                break;
            }
        }
        if (now.getType() == TokenType.INTTK) {
            MainFuncDef mainFuncDef = parseMainFuncDef();
            return new CompUnit(decls, funcDefs, mainFuncDef);
            // this.compUnit.addMainFuncDef(mainFuncDef);
        } else {
            // TODO: Error handling
        }
        return null;
    }

    private Token checkRightParen() {
        Token rightParen;
        if (now.getType() == TokenType.RPARENT) {
            rightParen = now;
            getToken();
        } else {
            rightParen = new Token(TokenType.RPARENT, ")", last.getLineNum());
            if (errorState) lexer.addError(last.getLineNum(), ErrorType.j);
        }
        return rightParen;
    }

    private Token checkRightRacket() {
        Token rightRacket;
        if (now.getType() == TokenType.RBRACK) {
            rightRacket = now;
            getToken();
        } else {
            rightRacket = new Token(TokenType.RBRACK, "]", last.getLineNum());
            if (errorState) lexer.addError(last.getLineNum(), ErrorType.k);
        }
        return rightRacket;
    }

    private Token checkSemicolon() {
        Token semicolon;
        if (now.getType() == TokenType.SEMICN) {
            semicolon = now;
            getToken();
        } else {
            semicolon = new Token(TokenType.SEMICN, ";", last.getLineNum());
            if (errorState) lexer.addError(last.getLineNum(), ErrorType.i);
        }
        return semicolon;
    }

    private MainFuncDef parseMainFuncDef() {
        Token _int = now;
        getToken();
        Token _main = now;
        getToken();
        Token leftParent = now;
        getToken();
        Token rightParent = checkRightParen();
        Block block = parseBlock();
        return new MainFuncDef(_int, _main, leftParent, rightParent, block);
    }

    private FuncDef parseFuncDef() {
        FuncType funcType = parseFuncType();
        Token ident = now;
        getToken();
        Token leftParent = now;
        getToken();
        if (now.getType() == TokenType.INTTK || now.getType() == TokenType.CHARTK) {
            FuncFParams funcFParams = parseFuncFParams();
            Token rightParent = checkRightParen();
            Block block = parseBlock();
            return new FuncDef(funcType, ident, leftParent, funcFParams, rightParent, block);
        } else {
            Token rightParent = checkRightParen();
            Block block = parseBlock();
            return new FuncDef(funcType, ident, leftParent, rightParent, block);
        }
    }

    private FuncFParams parseFuncFParams() {
        FuncFParam firstFuncFParam = parseFuncFParam();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        while (now.getType() == TokenType.COMMA) {
            Token comma = now;
            commas.add(comma);
            getToken();
            FuncFParam funcFParam = parseFuncFParam();
            funcFParams.add(funcFParam);
        }
        return new FuncFParams(firstFuncFParam, commas, funcFParams);
    }

    private FuncFParam parseFuncFParam() {
        BType bType = parseBType();
        Token ident = now;
        getToken();
        if (now.getType() == TokenType.LBRACK) {
            Token leftBracket = now;
            getToken();
            Token rightBracket = checkRightRacket();
            return new FuncFParam(bType, ident, leftBracket, rightBracket);
        } else {
            return new FuncFParam(bType, ident);
        }
    }

    private Block parseBlock() {
        Token leftBrace = now;
        getToken();
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        while (now.getType() != TokenType.RBRACE) {
            BlockItem blockItem = parseBlockItem();
            blockItems.add(blockItem);
        }
        Token rightBrace = now;
        getToken();
        return new Block(leftBrace, blockItems, rightBrace);
    }

    private BlockItem parseBlockItem() {
        if (now.getType() == TokenType.INTTK || now.getType() == TokenType.CHARTK || now.getType() == TokenType.CONSTTK) {
            Decl decl = parseDecl();
            return new BlockItem(decl);
        } else {
            Stmt stmt = parseStmt();
            return new BlockItem(stmt);
        }
    }

    private Stmt parseStmt() {
        StmtEle stmtEle = parseStmtEle();
        return new Stmt(stmtEle);
    }

    private StmtEle parseStmtEle() {
        if (now.getType() == TokenType.IFTK) {
            return parseStmtIf();
        }
        if (now.getType() == TokenType.FORTK) {
            return parseStmtFor();
        }
        if (now.getType() == TokenType.BREAKTK) {
            return parseStmtBreak();
        }
        if (now.getType() == TokenType.CONTINUETK) {
            return parseStmtContinue();
        }
        if (now.getType() == TokenType.RETURNTK) {
            return parseStmtReturn();
        }
        if (now.getType() == TokenType.PRINTFTK) {
            return parseStmtPrintf();
        }
        if (now.getType() == TokenType.LBRACE) {
            return parseStmtBlock();
        }
        if (now.getType() == TokenType.SEMICN) {
            return parseStmtExp();
        }
        if (preRead.getType() != TokenType.LBRACK && preRead.getType() != TokenType.ASSIGN) {
            return parseStmtExp();
        }
        int tmpCur = cur;
        this.errorState = false;
        Exp exp = parseExp();
        this.errorState = true;
        if (now.getType() != TokenType.ASSIGN) {
            backTracking(tmpCur);
            return parseStmtExp();
            /*Token semicolon = checkSemicolon();
            return new StmtExp(exp, semicolon);*/
        } else {
            if (preRead.getType() == TokenType.GETINTTK) {
                backTracking(tmpCur);
                return parseStmtGetInt();
            } else if (preRead.getType() == TokenType.GETCHARTK) {
                backTracking(tmpCur);
                return parseStmtGetChar();
            } else {
                backTracking(tmpCur);
                return parseStmtAssign();
            }
        }
    }

    private StmtAssign parseStmtAssign() {
        LVal lVal = parseLVal();
        Token assign = now;
        getToken();
        Exp exp = parseExp();
        Token semicolon = checkSemicolon();
        return new StmtAssign(lVal, assign, exp, semicolon);
    }

    private StmtGetChar parseStmtGetChar() {
        LVal lVal = parseLVal();
        Token assign = now;
        getToken();
        Token getChar = now;
        getToken();
        Token leftParen = now;
        getToken();
        Token rightParen = checkRightParen();
        Token semicolon = checkSemicolon();
        return new StmtGetChar(lVal, assign, getChar, leftParen, rightParen, semicolon);
    }

    private StmtGetInt parseStmtGetInt() {
        LVal lVal = parseLVal();
        Token assign = now;
        getToken();
        Token getInt = now;
        getToken();
        Token leftParen = now;
        getToken();
        Token rightParen = checkRightParen();
        Token semicolon = checkSemicolon();
        return new StmtGetInt(lVal, assign, getInt, leftParen, rightParen, semicolon);
    }

    private StmtExp parseStmtExp() {
        if (now.getType() == TokenType.SEMICN) {
            Token semicolon = now;
            getToken();
            return new StmtExp(semicolon);
        } else {
            Exp exp = parseExp();
            Token semicolon = checkSemicolon();
            return new StmtExp(exp, semicolon);
        }
    }

    private StmtBlock parseStmtBlock() {
        Block block = parseBlock();
        return new StmtBlock(block);
    }

    private StmtPrintf parseStmtPrintf() {
        Token printf = now;
        getToken();
        Token leftParen = now;
        getToken();
        Token stringConst = now;
        getToken();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        while (now.getType() == TokenType.COMMA) {
            Token comma = now;
            commas.add(comma);
            getToken();
            Exp exp = parseExp();
            exps.add(exp);
        }
        Token rightParen = checkRightParen();
        Token semicolon = checkSemicolon();
        return new StmtPrintf(printf, leftParen, stringConst, commas, exps, rightParen, semicolon);
    }

    private StmtReturn parseStmtReturn() {
        Token returnTK = now;
        getToken();
        /*if (now.getType() == TokenType.SEMICN) {
            Token semicolon = now;
            getToken();
            return new StmtReturn(returnTK, semicolon);
        } else {
            Exp exp = parseExp();
            Token semicolon = checkSemicolon();
            return new StmtReturn(returnTK, exp, semicolon);
        }*/
        if (this.mayExp()) {
            Exp exp = parseExp();
            Token semicolon = checkSemicolon();
            return new StmtReturn(returnTK, exp, semicolon);
        } else {
            Token semicolon = checkSemicolon();
            return new StmtReturn(returnTK, semicolon);
        }
    }

    private StmtContinue parseStmtContinue() {
        Token continueTK = now;
        getToken();
        Token semicolon = checkSemicolon();
        return new StmtContinue(continueTK, semicolon);
    }

    private StmtIf parseStmtIf() {
        Token ifTK = now;
        getToken();
        Token leftParen = now;
        getToken();
        Cond cond = parseCond();
        Token rightParen = checkRightParen();
        Stmt stmt = parseStmt();
        if (now.getType() == TokenType.ELSETK) {
            Token elseTK = now;
            getToken();
            Stmt stmt_1 = parseStmt();
            return new StmtIf(ifTK, leftParen, cond, rightParen, stmt, elseTK, stmt_1);
        } else {
            return new StmtIf(ifTK, leftParen, cond, rightParen, stmt);
        }
    }

    private StmtBreak parseStmtBreak() {
        Token breakTK = now;
        getToken();
        Token semicolon = checkSemicolon();
        return new StmtBreak(breakTK, semicolon);
    }

    private StmtFor parseStmtFor() {
        Token for_ = now;
        getToken();
        Token leftParen = now;
        getToken();
        ForStmt forStmt1 = null;
        Token semicolon1;
        Cond cond = null;
        Token semicolon2;
        ForStmt forStmt2 = null;
        Token rightParen;
        Stmt stmt;
        if (now.getType() != TokenType.SEMICN) {
            forStmt1 = parseForStmt();
        }
        semicolon1 = checkSemicolon();
        if (now.getType() != TokenType.SEMICN) {
            cond = parseCond();
        }
        semicolon2 = checkSemicolon();
        if (now.getType() != TokenType.RPARENT) {
            forStmt2 = parseForStmt();
        }
        rightParen = checkRightParen();
        stmt = parseStmt();
        return new StmtFor(for_, leftParen, forStmt1, semicolon1, cond, semicolon2, forStmt2, rightParen, stmt);
    }

    private FuncType parseFuncType() {
        Token v_i_c = now;
        getToken();
        return new FuncType(v_i_c);
    }

    private Decl parseDecl() {
        if (now.getType() == TokenType.CONSTTK) {
            ConstDecl constDecl = parseConstDecl();
            return new Decl(constDecl);
        } else {
            VarDecl varDecl = parseVarDecl();
            return new Decl(varDecl);
        }
    }

    private VarDecl parseVarDecl() {
        BType bType = parseBType();
        VarDef varDef = parseVarDef();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<VarDef> varDefs = new ArrayList<>();
        while (now.getType() == TokenType.COMMA) {
            Token comma = now;
            commas.add(comma);
            getToken();
            VarDef varDef_1 = parseVarDef();
            varDefs.add(varDef_1);
        }
        Token semicolon = checkSemicolon();
        /*if (now.getType() == TokenType.SEMICN) {
            semicolon = now;
            getToken();
        } else {
            // TODO: Error handling
            lexer.addError(last.getLineNum(), ErrorType.i);
            semicolon = new Token(TokenType.SEMICN, ";", last.getLineNum());
        }*/
        if (commas.isEmpty()) {
            return new VarDecl(bType, varDef, semicolon);
        } else {
            return new VarDecl(bType, varDef, commas, varDefs, semicolon);
        }
    }

    private VarDef parseVarDef() {
        Token ident = now;
        getToken();
        if (now.getType() == TokenType.LBRACK) {
            Token leftBracket = now;
            getToken();
            ConstExp constExp = parseConstExp();
            Token rightBracket = checkRightRacket();
            if (now.getType() == TokenType.ASSIGN) {
                Token assign = now;
                getToken();
                InitVal initVal = parseInitVal();
                return new VarDef(ident, leftBracket, constExp, rightBracket, assign, initVal);
            } else {
                return new VarDef(ident, leftBracket, constExp, rightBracket);
            }
        } else if (now.getType() == TokenType.ASSIGN) {
            Token assign = now;
            getToken();
            InitVal initVal = parseInitVal();
            return new VarDef(ident, assign, initVal);
        } else {
            return new VarDef(ident);
        }
    }

    private ConstDecl parseConstDecl() {
        Token constTK = now;
        getToken();
        BType bType = parseBType();
        ConstDef constDef = parseConstDef();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        while (now.getType() == TokenType.COMMA) {
            Token comma = now;
            commas.add(comma);
            getToken();
            ConstDef constDef_1 = parseConstDef();
            constDefs.add(constDef_1);
        }
        Token semicolon;
        if (now.getType() == TokenType.SEMICN) {
            semicolon = now;
            getToken();
        } else {
            // TODO: Error handling
            lexer.addError(last.getLineNum(), ErrorType.i);
            semicolon = new Token(TokenType.SEMICN, ";", last.getLineNum());
        }
        if (commas.isEmpty()) {
            return new ConstDecl(constTK, bType, constDef, semicolon);
        } else {
            return new ConstDecl(constTK, bType, constDef, commas, constDefs, semicolon);
        }
    }
    
    private ConstDef parseConstDef() {
        Token ident = now;
        getToken();
        if (now.getType() == TokenType.LBRACK) {
            Token leftBracket = now;
            getToken();
            ConstExp constExp = parseConstExp();
            Token rightBracket = checkRightRacket();
            /*if (now.getType() == TokenType.RBRACK) {
                rightBracket = now;
                getToken();
            } else {
                rightBracket = new Token(TokenType.RBRACK, "]", last.getLineNum());
                lexer.addError(last.getLineNum(), ErrorType.k);
            }*/
            Token assign = now;
            getToken();
            ConstInitVal constInitVal = parseConstInitVal();
            return new ConstDef(ident, leftBracket, constExp, rightBracket, assign, constInitVal);
        } else {
            Token assign = now;
            getToken();
            ConstInitVal constInitVal = parseConstInitVal();
            return new ConstDef(ident, assign, constInitVal);
        }
    }

    private ConstInitVal parseConstInitVal() {
        if (now.getType() == TokenType.STRCON) {
            Token stringConst = now;
            getToken();
            return new ConstInitVal(stringConst);
        } else if (now.getType() == TokenType.LBRACE) {
            Token leftBrace = now;
            getToken();
            if (now.getType() != TokenType.RBRACE) {
                ConstExp firstExp = parseConstExp();
                ArrayList<Token> commas = new ArrayList<>();
                ArrayList<ConstExp> constExps = new ArrayList<>();
                while (now.getType() == TokenType.COMMA) {
                    Token comma = now;
                    commas.add(comma);
                    getToken();
                    ConstExp constExp = parseConstExp();
                    constExps.add(constExp);
                }
                Token rightBrace = now;
                getToken();
                return new ConstInitVal(leftBrace, firstExp, commas, constExps, rightBrace);
            } else {
                Token rightBrace = now;
                getToken();
                return new ConstInitVal(leftBrace, rightBrace);
            }
        } else {
            ConstExp constExp = parseConstExp();
            return new ConstInitVal(constExp);
        }
    }

    private ConstExp parseConstExp() {
        AddExp addExp = parseAddExp();
        return new ConstExp(addExp);
    }

    private BType parseBType() {
        Token int_or = now;
        getToken();
        return new BType(int_or);
    }

    private InitVal parseInitVal() {
        if (now.getType() == TokenType.STRCON) {
            Token stringConst = now;
            getToken();
            return new InitVal(stringConst);
        } else if (now.getType() == TokenType.LBRACE) {
            Token leftBrace = now;
            getToken();
            if (now.getType() != TokenType.RBRACE) {
                Exp firstExp = parseExp();
                ArrayList<Token> commas = new ArrayList<>();
                ArrayList<Exp> exps = new ArrayList<>();
                while (now.getType() == TokenType.COMMA) {
                    Token comma = now;
                    commas.add(comma);
                    getToken();
                    Exp exp = parseExp();
                    exps.add(exp);
                }
                Token rightBrace = now;
                getToken();
                return new InitVal(leftBrace, firstExp, commas, exps, rightBrace);
            } else {
                Token rightBrace = now;
                getToken();
                return new InitVal(leftBrace, rightBrace);
            }
        } else {
            Exp exp = parseExp();
            return new InitVal(exp);
        }
    }

    private Exp parseExp() {
        AddExp addExp = parseAddExp();
        return new Exp(addExp);
    }

    private AddExp parseAddExp() {
        MulExp mulExp = parseMulExp();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<MulExp> mulExps = new ArrayList<>();
        while (now.getType() == TokenType.PLUS || now.getType() == TokenType.MINU) {
            Token op = now;
            ops.add(op);
            getToken();
            MulExp mulExp_1 = parseMulExp();
            mulExps.add(mulExp_1);
        }
        return new AddExp(mulExp, ops, mulExps);
    }

    private ForStmt parseForStmt() {
        LVal lVal = parseLVal();
        Token assign = now;
        getToken();
        Exp exp = parseExp();
        return new ForStmt(lVal, exp, assign);
    }

    private LVal parseLVal() {
        Token ident = now;
        getToken();
        if (now.getType() == TokenType.LBRACK) {
            Token leftBracket = now;
            getToken();
            Exp exp = parseExp();
            Token rightBracket = checkRightRacket();
            return new LVal(ident, leftBracket, exp, rightBracket);
        } else {
            return new LVal(ident);
        }
    }
    
    private Cond parseCond() {
        LOrExp lOrExp = parseLOrExp();
        return new Cond(lOrExp);
    }

    private LOrExp parseLOrExp() {
        LAndExp lAndExp = parseLAndExp();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<LAndExp> lAndExps = new ArrayList<>();
        while (now.getType() == TokenType.OR) {
            Token op = now;
            ops.add(op);
            getToken();
            LAndExp lAndExp_1 = parseLAndExp();
            lAndExps.add(lAndExp_1);
        }
        return new LOrExp(lAndExp, ops, lAndExps);
    }

    private LAndExp parseLAndExp() {
        EqExp eqExp = parseEqExp();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<EqExp> eqExps = new ArrayList<>();
        while (now.getType() == TokenType.AND) {
            Token op = now;
            ops.add(op);
            getToken();
            EqExp eqExp_1 = parseEqExp();
            eqExps.add(eqExp_1);
        }
        return new LAndExp(eqExp, ops, eqExps);
    }

    private EqExp parseEqExp() {
        RelExp relExp = parseRelExp();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<RelExp> relExps = new ArrayList<>();
        while (now.getType() == TokenType.EQL || now.getType() == TokenType.NEQ) {
            Token op = now;
            ops.add(op);
            getToken();
            RelExp relExp_1 = parseRelExp();
            relExps.add(relExp_1);
        }
        return new EqExp(relExp, ops, relExps);
    }

    private RelExp parseRelExp() {
        AddExp addExp = parseAddExp();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<AddExp> addExps = new ArrayList<>();
        while (now.getType() == TokenType.LSS || now.getType() == TokenType.LEQ || now.getType() == TokenType.GRE || now.getType() == TokenType.GEQ) {
            Token op = now;
            ops.add(op);
            getToken();
            AddExp addExp_1 = parseAddExp();
            addExps.add(addExp_1);
        }
        return new RelExp(addExp, ops, addExps);
    }

    private PrimaryExp parsePrimaryExp() {
        if (now.getType() == TokenType.LPARENT) {
            Token leftParen = now;
            getToken();
            Exp exp = parseExp();
            Token rightParen = checkRightParen();
            return new PrimaryExp(leftParen, exp, rightParen);
        } else if (now.getType() == TokenType.IDENFR) {
            LVal lVal = parseLVal();
            return new PrimaryExp(lVal);
        } else {
            if (now.getType() == TokenType.INTCON) {
                Token intCon = now;
                getToken();
                return new PrimaryExp(new Number(intCon));
            } else {
                Token charCon = now;
                getToken();
                return new PrimaryExp(new Character(charCon));
            }
        }
    }

    private Number parseNumber() {
        Token intCon = now;
        getToken();
        return new Number(now);
    }

    private Character parserCharacter() {
        Token charCon = now;
        getToken();
        return new Character(charCon);
    }

    private boolean mayExp() {
        return now.getType() == TokenType.IDENFR || now.getType() == TokenType.LPARENT || now.getType() == TokenType.INTCON || now.getType() == TokenType.CHRCON || now.getType() == TokenType.PLUS || now.getType() == TokenType.MINU || now.getType() == TokenType.NOT;
    }

    private UnaryExp parseUnaryExp() {
        if (now.getType() == TokenType.PLUS || now.getType() == TokenType.MINU || now.getType() == TokenType.NOT) {
            UnaryOp unaryOp = parseUnaryOp();
            UnaryExp unaryExp = parseUnaryExp();
            return new UnaryExp(unaryOp, unaryExp);
        } else if (now.getType() == TokenType.IDENFR && preRead.getType() == TokenType.LPARENT) {
            Token ident = now;
            getToken();
            Token leftParen = now;
            getToken();
            if (!this.mayExp()) {
                Token rightParen = checkRightParen();
                return new UnaryExp(ident, leftParen, rightParen);
            } else {
                FuncRParams funcRParams = parseFuncRParams();
                Token rightParen = checkRightParen();
                return new UnaryExp(ident, leftParen, funcRParams, rightParen);
            }
        } else {
            PrimaryExp primaryExp = parsePrimaryExp();
            return new UnaryExp(primaryExp);
        }
    }

    private FuncRParams parseFuncRParams() {
        Exp firstExp = parseExp();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        while (now.getType() == TokenType.COMMA) {
            Token comma = now;
            commas.add(comma);
            getToken();
            Exp exp = parseExp();
            exps.add(exp);
        }
        return new FuncRParams(firstExp, commas, exps);
    }

    private UnaryOp parseUnaryOp() {
        Token op = now;
        getToken();
        return new UnaryOp(op);
    }

    private MulExp parseMulExp() {
        UnaryExp unaryExp = parseUnaryExp();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<UnaryExp> unaryExps = new ArrayList<>();
        while (now.getType() == TokenType.MULT || now.getType() == TokenType.DIV || now.getType() == TokenType.MOD) {
            Token op = now;
            ops.add(op);
            getToken();
            UnaryExp unaryExp_1 = parseUnaryExp();
            unaryExps.add(unaryExp_1);
        }
        return new MulExp(unaryExp, ops, unaryExps);
    }
}

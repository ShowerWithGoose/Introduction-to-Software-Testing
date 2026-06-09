package frontend.parser;

import frontend.check.ErrorMap;
import frontend.check.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.cst.AddExpNode;
import frontend.parser.cst.AssignStmtNode;
import frontend.parser.cst.BTypeNode;
import frontend.parser.cst.BlockItemNode;
import frontend.parser.cst.BlockNode;
import frontend.parser.cst.BreakStmtNode;
import frontend.parser.cst.CSTNode;
import frontend.parser.cst.CalleeNode;
import frontend.parser.cst.CharacterNode;
import frontend.parser.cst.CondNode;
import frontend.parser.cst.ConditionStmtNode;
import frontend.parser.cst.ConstDeclNode;
import frontend.parser.cst.ConstDefNode;
import frontend.parser.cst.ConstExpNode;
import frontend.parser.cst.ConstInitValNode;
import frontend.parser.cst.ContinueStmtNode;
import frontend.parser.cst.EqExpNode;
import frontend.parser.cst.ExpNode;
import frontend.parser.cst.ExpStmtNode;
import frontend.parser.cst.ForLoopStmtNode;
import frontend.parser.cst.ForStmtNode;
import frontend.parser.cst.FuncDefNode;
import frontend.parser.cst.FuncFParamNode;
import frontend.parser.cst.FuncFParamsNode;
import frontend.parser.cst.FuncRParamsNode;
import frontend.parser.cst.FuncTypeNode;
import frontend.parser.cst.InStmtNode;
import frontend.parser.cst.InitValNode;
import frontend.parser.cst.LAndExpNode;
import frontend.parser.cst.LOrExpNode;
import frontend.parser.cst.LValNode;
import frontend.parser.cst.MainFuncDefNode;
import frontend.parser.cst.MulExpNode;
import frontend.parser.cst.NumberNode;
import frontend.parser.cst.OutStmtNode;
import frontend.parser.cst.PrimaryExpNode;
import frontend.parser.cst.RelExpNode;
import frontend.parser.cst.ReturnStmtNode;
import frontend.parser.cst.RootNode;
import frontend.parser.cst.StmtNode;
import frontend.parser.cst.StringConstNode;
import frontend.parser.cst.TokenNode;
import frontend.parser.cst.UnaryExpNode;
import frontend.parser.cst.UnaryOpNode;
import frontend.parser.cst.VarDeclNode;
import frontend.parser.cst.VarDefNode;

import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Parser {
    private ParseSupporter parseSupporter;
    private final ErrorMap errorMap;

    public Parser(ArrayList<Token> tokens, ErrorMap errorMap) {
        parseSupporter = new ParseSupporter(tokens);
        this.errorMap = errorMap;
    }

    public CSTNode assertToken(TokenType type, int lineNum) throws RuntimeException {
        try {
            CSTNode node = parseSupporter.checkToken(type);
            if (type == TokenType.SEMICN) {
                parseSupporter.addComponent("SEMICN" + " " + parseSupporter.getCurrentToken().getContent());
            } else if (type == TokenType.RBRACK) {
                parseSupporter.addComponent("RBRACK" + " " + parseSupporter.getCurrentToken().getContent());
            } else if (type == TokenType.RPARENT) {
                parseSupporter.addComponent("RPARENT" + " " + parseSupporter.getCurrentToken().getContent());
            }
            return node;
        } catch (RuntimeException e) {
            return handleTokenException(type, lineNum, e);
        }
    }

    private CSTNode handleTokenException(TokenType type, int lineNum, RuntimeException e) throws RuntimeException {
        switch (type) {
            case SEMICN:
                errorMap.addError(lineNum, ErrorType.MISSING_SEMICOLON);
                return new TokenNode(new Token(TokenType.SEMICN, lineNum, ";"), true);
            case RBRACK:
                errorMap.addError(lineNum, ErrorType.MISSING_RIGHT_BRACE);
                return new TokenNode(new Token(TokenType.RBRACK, lineNum, "]"), true);
            case RPARENT:
                errorMap.addError(lineNum, ErrorType.MISSING_RIGHT_PAREN);
                return new TokenNode(new Token(TokenType.RPARENT, lineNum, ")"), true);
            default:
                throw e;
        }
    }

    public CSTNode parse() {
        try {
            return parseCompUnit();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public String display() {
        StringBuilder sb = new StringBuilder();
        for (String log : parseSupporter.getParseLog()) {
            sb.append(log).append("\n");
        }
        return sb.toString();
    }

    private RootNode parseCompUnit() throws Exception {
        RootNode rootNode = new RootNode();
        while (!parseSupporter.isParseEnd()) {
            if (parseSupporter.isDeclFirst()) {
                rootNode.addChild(parseDecl());
            } else if (parseSupporter.isFunDef()) {
                rootNode.addChild(parseFuncDef());
            } else if (parseSupporter.isMainFuncDef()) {
                rootNode.addChild(parseMainFuncDef());
            } else {
                System.err.println("CompUnit error");
                throw new Exception("CompUnit error");

            }
        }
        parseSupporter.addParseLog("CompUnit");

        return rootNode;
    }

    private CSTNode parseDecl() throws Exception {
        CSTNode declNode = new CSTNode();
        if (parseSupporter.isConstDecl()) {
            declNode.addChild(parseConstDecl());
        } else {
            declNode.addChild(parseVarDecl());
        }
        return declNode;
    }

    private ConstDeclNode parseConstDecl() throws Exception {
        ConstDeclNode constDeclNode = new ConstDeclNode();

        constDeclNode.addChild(parseSupporter.checkToken(TokenType.CONSTTK));
        parseSupporter.addComponent("CONSTTK" + " " + parseSupporter.getCurrentToken().getContent());
        constDeclNode.addChild(parseBType());
        constDeclNode.addChild(parseConstDef());
        while (parseSupporter.isComma() && !parseSupporter.isParseEnd()) {
            constDeclNode.addChild(parseSupporter.checkToken(TokenType.COMMA));
            parseSupporter.addComponent("COMMA" + " " + parseSupporter.getCurrentToken().getContent());
            constDeclNode.addChild(parseConstDef());
        }
        constDeclNode.addChild(assertToken(TokenType.SEMICN, parseSupporter.getLineNum()));
        parseSupporter.addParseLog("ConstDecl");
        return constDeclNode;
    }

    private CSTNode parseBType() throws Exception {
        BTypeNode bTypeNode = new BTypeNode();
        if (parseSupporter.isIntTk()) {
            bTypeNode.addChild(parseSupporter.checkToken(TokenType.INTTK));
            parseSupporter.addComponent("INTTK" + " " + parseSupporter.getCurrentToken().getContent());
        } else if (parseSupporter.isCharTk()) {
            bTypeNode.addChild(parseSupporter.checkToken(TokenType.CHARTK));
            parseSupporter.addComponent("CHARTK" + " " + parseSupporter.getCurrentToken().getContent());
        }
        return bTypeNode;
    }

    private CSTNode parseConstDef() throws Exception {
        ConstDefNode constDefNode = new ConstDefNode();
        constDefNode.addChild(parseSupporter.checkToken(TokenType.IDENFR));
        parseSupporter.addComponent("IDENFR" + " " + parseSupporter.getCurrentToken().getContent());
        while (parseSupporter.isLBracket()) {
            constDefNode.addChild(parseSupporter.checkToken(TokenType.LBRACK));
            parseSupporter.addComponent("LBRACK" + " " + parseSupporter.getCurrentToken().getContent());
            constDefNode.addChild(parseConstExp());
            constDefNode.addChild(assertToken(TokenType.RBRACK, parseSupporter.getLineNum()));
        }
        constDefNode.addChild(parseSupporter.checkToken(TokenType.ASSIGN));
        parseSupporter.addComponent("ASSIGN" + " " + parseSupporter.getCurrentToken().getContent());
        constDefNode.addChild(parseConstInitVal());
        parseSupporter.addParseLog("ConstDef");
        return constDefNode;
    }

    private ConstInitValNode parseConstInitVal() throws Exception {
        ConstInitValNode constInitValNode = new ConstInitValNode();
        if (parseSupporter.isLBrace()) {
            constInitValNode.addChild(parseSupporter.checkToken(TokenType.LBRACE));
            parseSupporter.addComponent("LBRACE" + " " + parseSupporter.getCurrentToken().getContent());
            if (!parseSupporter.isRBrace()) {
                constInitValNode.addChild(parseConstExp());
                while (parseSupporter.isComma()) {
                    constInitValNode.addChild(parseSupporter.checkToken(TokenType.COMMA));
                    parseSupporter.addComponent("COMMA" + " " + parseSupporter.getCurrentToken().getContent());
                    constInitValNode.addChild(parseConstExp());
                }
            }
            constInitValNode.addChild(parseSupporter.checkToken(TokenType.RBRACE));
            parseSupporter.addComponent("RBRACE" + " " + parseSupporter.getCurrentToken().getContent());
        } else if (parseSupporter.isStrConst()) {
            constInitValNode.addChild(parseStringConst());
        } else {
            constInitValNode.addChild(parseConstExp());
        }
        parseSupporter.addParseLog("ConstInitVal");
        return constInitValNode;
    }

    private ConstExpNode parseConstExp() throws Exception {
        ConstExpNode constExpNode = new ConstExpNode();
        constExpNode.addChild(parseAddExp());
        parseSupporter.addParseLog("ConstExp");
        return constExpNode;
    }

    private VarDeclNode parseVarDecl() throws Exception {
        VarDeclNode varDeclNode = new VarDeclNode();
        varDeclNode.addChild(parseBType());
        varDeclNode.addChild(parseVarDef());
        while (parseSupporter.isComma() && !parseSupporter.isParseEnd()) {
            varDeclNode.addChild(parseSupporter.checkToken(TokenType.COMMA));
            parseSupporter.addComponent("COMMA" + " " + parseSupporter.getCurrentToken().getContent());
            varDeclNode.addChild(parseVarDef());
        }
        varDeclNode.addChild(assertToken(TokenType.SEMICN, parseSupporter.getLineNum()));
        parseSupporter.addParseLog("VarDecl");
        return varDeclNode;
    }

    private VarDefNode parseVarDef() throws Exception {
        VarDefNode varDefNode = new VarDefNode();
        varDefNode.addChild(parseSupporter.checkToken(TokenType.IDENFR));
        parseSupporter.addComponent("IDENFR" + " " + parseSupporter.getCurrentToken().getContent());
        while (parseSupporter.isLBracket()) {
            varDefNode.addChild(parseSupporter.checkToken(TokenType.LBRACK));
            parseSupporter.addComponent("LBRACK" + " " + parseSupporter.getCurrentToken().getContent());
            varDefNode.addChild(parseConstExp());
            varDefNode.addChild(assertToken(TokenType.RBRACK, parseSupporter.getLineNum()));
        }
        if (parseSupporter.isAssign()) {
            varDefNode.addChild(parseSupporter.checkToken(TokenType.ASSIGN));
            parseSupporter.addComponent("ASSIGN" + " " + parseSupporter.getCurrentToken().getContent());
            varDefNode.addChild(parseInitVal());
        }
        parseSupporter.addParseLog("VarDef");
        return varDefNode;
    }

    private InitValNode parseInitVal() throws Exception {
        InitValNode initValNode = new InitValNode();
        if (parseSupporter.isLBrace()) {
            initValNode.addChild(parseSupporter.checkToken(TokenType.LBRACE));
            parseSupporter.addComponent("LBRACE" + " " + parseSupporter.getCurrentToken().getContent());
            if (!parseSupporter.isRBrace()) {
                initValNode.addChild(parseExp());
                while (parseSupporter.isComma()) {
                    initValNode.addChild(parseSupporter.checkToken(TokenType.COMMA));
                    parseSupporter.addComponent("COMMA" + " " + parseSupporter.getCurrentToken().getContent());
                    initValNode.addChild(parseExp());
                }
                initValNode.addChild(parseSupporter.checkToken(TokenType.RBRACE));
                parseSupporter.addComponent("RBRACE" + " " + parseSupporter.getCurrentToken().getContent());
            }
        } else if (parseSupporter.isStrConst()) {
            initValNode.addChild(parseStringConst());
        } else {
            initValNode.addChild(parseExp());
        }
        parseSupporter.addParseLog("InitVal");
        return initValNode;
    }
    
    private StringConstNode parseStringConst() throws Exception {
        StringConstNode stringConstNode = new StringConstNode();
        stringConstNode.addChild(parseSupporter.checkToken(TokenType.STRCON));
        parseSupporter.addComponent("STRCON" + " " + parseSupporter.getCurrentToken().getContent());
        return stringConstNode;
    }

    private FuncDefNode parseFuncDef() throws Exception {
        FuncDefNode funcDefNode = new FuncDefNode();

        funcDefNode.addChild(parseFuncType());
        funcDefNode.addChild(parseSupporter.checkToken(TokenType.IDENFR));
        parseSupporter.addComponent("IDENFR" + " " + parseSupporter.getCurrentToken().getContent());
        funcDefNode.addChild(parseSupporter.checkToken(TokenType.LPARENT));
        parseSupporter.addComponent("LPARENT" + " " + parseSupporter.getCurrentToken().getContent());

        if (parseSupporter.isFuncParaFirst()) {
            funcDefNode.addChild(parseFuncPara());
        }

        funcDefNode.addChild(assertToken(TokenType.RPARENT, parseSupporter.getLineNum()));
        parseSupporter.addComponent("RPARENT" + " " + parseSupporter.getCurrentToken().getContent());
        funcDefNode.addChild(parseBlock());
        parseSupporter.addParseLog("FuncDef");
        return funcDefNode;
    }

    private FuncTypeNode parseFuncType() throws Exception {
        FuncTypeNode funcTypeNode = new FuncTypeNode();

        if (parseSupporter.isVoidTk()) {
            funcTypeNode.addChild(parseSupporter.checkToken(TokenType.VOIDTK));
            parseSupporter.addComponent("VOIDTK" + " " + parseSupporter.getCurrentToken().getContent());
        } else if (parseSupporter.isIntTk()) {
            funcTypeNode.addChild(parseSupporter.checkToken(TokenType.INTTK));
            parseSupporter.addComponent("INTTK" + " " + parseSupporter.getCurrentToken().getContent());
        } else if (parseSupporter.isCharTk()) {
            funcTypeNode.addChild(parseSupporter.checkToken(TokenType.CHARTK));
            parseSupporter.addComponent("CHARTK" + " " + parseSupporter.getCurrentToken().getContent());
        }
        parseSupporter.addParseLog("FuncType");
        return funcTypeNode;
    }

    private FuncFParamsNode parseFuncPara() throws Exception {
        FuncFParamsNode funcFParamsNode = new FuncFParamsNode();
        funcFParamsNode.addChild(parseFuncFParam());
        while (parseSupporter.isComma()) {
            funcFParamsNode.addChild(parseSupporter.checkToken(TokenType.COMMA));
            parseSupporter.addComponent("COMMA" + " " + parseSupporter.getCurrentToken().getContent());
            funcFParamsNode.addChild(parseFuncFParam());
        }
        parseSupporter.addParseLog("FuncFParams");
        return funcFParamsNode;
    }

    private FuncFParamNode parseFuncFParam() throws Exception {
        FuncFParamNode funcFParamNode = new FuncFParamNode();
        funcFParamNode.addChild(parseBType());
        funcFParamNode.addChild(parseSupporter.checkToken(TokenType.IDENFR));
        parseSupporter.addComponent("IDENFR" + " " + parseSupporter.getCurrentToken().getContent());
        if (parseSupporter.isLBracket()) {
            funcFParamNode.addChild(parseSupporter.checkToken(TokenType.LBRACK));
            parseSupporter.addComponent("LBRACK" + " " + parseSupporter.getCurrentToken().getContent());
            funcFParamNode.addChild(assertToken(TokenType.RBRACK, parseSupporter.getLineNum()));
            parseSupporter.addComponent("RBRACK" + " " + parseSupporter.getCurrentToken().getContent());
            while (parseSupporter.isLBracket()) {
                funcFParamNode.addChild(parseSupporter.checkToken(TokenType.LBRACK));
                parseSupporter.addComponent("LBRACK" + " " + parseSupporter.getCurrentToken().getContent());
                funcFParamNode.addChild(parseConstExp());
                funcFParamNode.addChild(parseSupporter.checkToken(TokenType.RBRACK));
                parseSupporter.addComponent("RBRACK" + " " + parseSupporter.getCurrentToken().getContent());
            }
        }
        parseSupporter.addParseLog("FuncFParam");
        return funcFParamNode;
    }

    private BlockNode parseBlock() throws Exception {
        BlockNode blockNode = new BlockNode();
        blockNode.addChild(parseSupporter.checkToken(TokenType.LBRACE));
        parseSupporter.addComponent("LBRACE" + " " + parseSupporter.getCurrentToken().getContent());
        while (!parseSupporter.isRBrace()) {
            blockNode.addChild(parseBlockItem());
        }
        blockNode.addChild(parseSupporter.checkToken(TokenType.RBRACE));
        parseSupporter.addComponent("RBRACE" + " " + parseSupporter.getCurrentToken().getContent());
        parseSupporter.addParseLog("Block");
        return blockNode;
    }

    private BlockItemNode parseBlockItem() throws Exception {
        BlockItemNode blockItemNode = new BlockItemNode();
        if (parseSupporter.isDeclFirst()) {
            blockItemNode.addChild(parseDecl());
        } else {
            blockItemNode.addChild(parseStmt());
        }
        return blockItemNode;
    }

    private StmtNode parseStmt() throws Exception {
        StmtNode stmtNode = new StmtNode();
        if (parseSupporter.isLBrace()) {
            stmtNode.addChild(parseBlock());
        } else if (parseSupporter.isIfTk()) {
            stmtNode.addChild(parseConditionStmt());
        } else if (parseSupporter.isForTk()) {
            stmtNode.addChild(parseForLoopStmt());
        } else if (parseSupporter.isBreakTk()) {
            stmtNode.addChild(parseBreakStmt());
        } else if (parseSupporter.isContinueTk()) {
            stmtNode.addChild(parseContinueStmt());
        } else if (parseSupporter.isReturnTk()) {
            stmtNode.addChild(parseReturnStmt());
        } else if (parseSupporter.isPrintfTk()) {
            stmtNode.addChild(parseOutStmt());
        } else {
            ParseSupporter oldSupporter = this.parseSupporter;
            this.parseSupporter = new ParseSupporter(oldSupporter);
            try {
                parseLVal();
                parseSupporter.checkToken(TokenType.ASSIGN);
                if (parseSupporter.lookAhead(0).getType() == TokenType.GETINTTK) {
                    this.parseSupporter = oldSupporter;
                    stmtNode.addChild(parseInStmt());
                } else if (parseSupporter.lookAhead(0).getType() == TokenType.GETCHARTK) {
                    this.parseSupporter = oldSupporter;
                    stmtNode.addChild(parseInStmt());
                } else {
                    this.parseSupporter = oldSupporter;
                    stmtNode.addChild(parseAssignStmt());
                }
            } catch (RuntimeException e) {
                this.parseSupporter = oldSupporter;
                stmtNode.addChild(parseExpStmt());
            }
        }
        parseSupporter.addParseLog("Stmt");
        return stmtNode;
    }

    private AssignStmtNode parseAssignStmt() throws Exception {
        AssignStmtNode assignStmtNode = new AssignStmtNode();
        assignStmtNode.addChild(parseLVal());
        assignStmtNode.addChild(parseSupporter.checkToken(TokenType.ASSIGN));
        parseSupporter.addComponent("ASSIGN" + " " + parseSupporter.getCurrentToken().getContent());
        assignStmtNode.addChild(parseExp());
        assignStmtNode.addChild(assertToken(TokenType.SEMICN, parseSupporter.getLineNum()));
        return assignStmtNode;
    }

    private ExpStmtNode parseExpStmt() throws Exception {
        ExpStmtNode expStmtNode = new ExpStmtNode();
        if (!parseSupporter.isSemiColon()) {
            expStmtNode.addChild(parseExp());
        }
        expStmtNode.addChild(assertToken(TokenType.SEMICN, parseSupporter.getLineNum()));
        return expStmtNode;
    }

    private InStmtNode parseInStmt() throws Exception {
        InStmtNode inStmtNode = new InStmtNode();
        inStmtNode.addChild(parseLVal());
        inStmtNode.addChild(parseSupporter.checkToken(TokenType.ASSIGN));
        parseSupporter.addComponent("ASSIGN" + " " + parseSupporter.getCurrentToken().getContent());
        if (parseSupporter.lookAhead(0).getType() == TokenType.GETINTTK) {
            inStmtNode.addChild(parseSupporter.checkToken(TokenType.GETINTTK));
            parseSupporter.addComponent("GETINTTK" + " " + parseSupporter.getCurrentToken().getContent());
        } else if (parseSupporter.lookAhead(0).getType() == TokenType.GETCHARTK) {
            inStmtNode.addChild(parseSupporter.checkToken(TokenType.GETCHARTK));
            parseSupporter.addComponent("GETCHARTK" + " " + parseSupporter.getCurrentToken().getContent());
        }
        inStmtNode.addChild(parseSupporter.checkToken(TokenType.LPARENT));
        parseSupporter.addComponent("LPARENT" + " " + parseSupporter.getCurrentToken().getContent());
        inStmtNode.addChild(assertToken(TokenType.RPARENT, parseSupporter.getLineNum()));
        inStmtNode.addChild(assertToken(TokenType.SEMICN, parseSupporter.getLineNum()));
        return inStmtNode;
    }

    private ConditionStmtNode parseConditionStmt() throws Exception {
        ConditionStmtNode conditionStmtNode = new ConditionStmtNode();
        conditionStmtNode.addChild(parseSupporter.checkToken(TokenType.IFTK));
        parseSupporter.addComponent("IFTK" + " " + parseSupporter.getCurrentToken().getContent());
        conditionStmtNode.addChild(parseSupporter.checkToken(TokenType.LPARENT));
        parseSupporter.addComponent("LPARENT" + " " + parseSupporter.getCurrentToken().getContent());
        conditionStmtNode.addChild(parseCond());
        conditionStmtNode.addChild(assertToken(TokenType.RPARENT, parseSupporter.getLineNum()));
        conditionStmtNode.addChild(parseStmt());
        if (parseSupporter.isElseTk()) {
            conditionStmtNode.addChild(parseSupporter.checkToken(TokenType.ELSETK));
            parseSupporter.addComponent("ELSETK" + " " + parseSupporter.getCurrentToken().getContent());
            conditionStmtNode.addChild(parseStmt());
        }
        return conditionStmtNode;
    }

    private ForLoopStmtNode parseForLoopStmt() throws Exception {
        ForLoopStmtNode forLoopStmtNode = new ForLoopStmtNode();
        forLoopStmtNode.addChild(parseSupporter.checkToken(TokenType.FORTK));
        parseSupporter.addComponent("FORTK" + " " + parseSupporter.getCurrentToken().getContent());
        forLoopStmtNode.addChild(parseSupporter.checkToken(TokenType.LPARENT));
        parseSupporter.addComponent("LPARENT" + " " + parseSupporter.getCurrentToken().getContent());
        if (!parseSupporter.isSemiColon()) {
            forLoopStmtNode.addChild(parseForStmt());
        }
        forLoopStmtNode.addChild(parseSupporter.checkToken(TokenType.SEMICN));
        parseSupporter.addComponent("SEMICN" + " " + parseSupporter.getCurrentToken().getContent());
        if (!parseSupporter.isSemiColon()) {
            forLoopStmtNode.addChild(parseCond());
        }
        forLoopStmtNode.addChild(parseSupporter.checkToken(TokenType.SEMICN));
        parseSupporter.addComponent("SEMICN" + " " + parseSupporter.getCurrentToken().getContent());
        if (!parseSupporter.isRParent()) {
            forLoopStmtNode.addChild(parseForStmt());
        }
        forLoopStmtNode.addChild(parseSupporter.checkToken(TokenType.RPARENT));
        parseSupporter.addComponent("RPARENT" + " " + parseSupporter.getCurrentToken().getContent());
        forLoopStmtNode.addChild(parseStmt());
        return forLoopStmtNode;
    }

    private ForStmtNode parseForStmt() throws Exception {
        ForStmtNode forStmtNode = new ForStmtNode();
        forStmtNode.addChild(parseLVal());
        forStmtNode.addChild(parseSupporter.checkToken(TokenType.ASSIGN));
        parseSupporter.addComponent("ASSIGN" + " " + parseSupporter.getCurrentToken().getContent());
        forStmtNode.addChild(parseExp());
        parseSupporter.addParseLog("ForStmt");
        return forStmtNode;
    }

    private BreakStmtNode parseBreakStmt() throws Exception {
        BreakStmtNode breakStmtNode = new BreakStmtNode();
        breakStmtNode.addChild(parseSupporter.checkToken(TokenType.BREAKTK));
        parseSupporter.addComponent("BREAKTK" + " " + parseSupporter.getCurrentToken().getContent());
        breakStmtNode.addChild(assertToken(TokenType.SEMICN, parseSupporter.getLineNum()));
        return breakStmtNode;
    }

    private ContinueStmtNode parseContinueStmt() throws Exception {
        ContinueStmtNode continueStmtNode = new ContinueStmtNode();
        continueStmtNode.addChild(parseSupporter.checkToken(TokenType.CONTINUETK));
        parseSupporter.addComponent("CONTINUETK" + " " + parseSupporter.getCurrentToken().getContent());
        continueStmtNode.addChild(assertToken(TokenType.SEMICN, parseSupporter.getLineNum()));
        return continueStmtNode;
    }

    private ReturnStmtNode parseReturnStmt() throws Exception {
        ReturnStmtNode returnStmtNode = new ReturnStmtNode();
        returnStmtNode.addChild(parseSupporter.checkToken(TokenType.RETURNTK));
        parseSupporter.addComponent("RETURNTK" + " " + parseSupporter.getCurrentToken().getContent());
        ParseSupporter oldSupporter = this.parseSupporter;
        try {
            this.parseSupporter = new ParseSupporter(oldSupporter);
            parseExp();
            this.parseSupporter = oldSupporter;
            returnStmtNode.addChild(parseExp());

        } catch (RuntimeException ignored) {
        }
        returnStmtNode.addChild(assertToken(TokenType.SEMICN, parseSupporter.getLineNum()));
        return returnStmtNode;
    }

    private OutStmtNode parseOutStmt() throws Exception {
        OutStmtNode outStmtNode = new OutStmtNode();
        outStmtNode.addChild(parseSupporter.checkToken(TokenType.PRINTFTK));
        parseSupporter.addComponent("PRINTFTK" + " " + parseSupporter.getCurrentToken().getContent());
        outStmtNode.addChild(parseSupporter.checkToken(TokenType.LPARENT));
        parseSupporter.addComponent("LPARENT" + " " + parseSupporter.getCurrentToken().getContent());
        outStmtNode.addChild(parseSupporter.checkToken(TokenType.STRCON));
        parseSupporter.addComponent("STRCON" + " " + parseSupporter.getCurrentToken().getContent());

        while (parseSupporter.isComma()) {
            outStmtNode.addChild(parseSupporter.checkToken(TokenType.COMMA));
            parseSupporter.addComponent("COMMA" + " " + parseSupporter.getCurrentToken().getContent());
            outStmtNode.addChild(parseExp());
        }
        outStmtNode.addChild(assertToken(TokenType.RPARENT, parseSupporter.getLineNum()));
        outStmtNode.addChild(assertToken(TokenType.SEMICN, parseSupporter.getLineNum()));
        return outStmtNode;
    }

    private ExpNode parseExp() throws Exception {
        ExpNode expNode = new ExpNode();
        expNode.addChild(parseAddExp());
        parseSupporter.addParseLog("Exp");
        return expNode;
    }

    private CondNode parseCond() throws Exception {
        CondNode condNode = new CondNode();
        condNode.addChild(parseLOrExp());
        parseSupporter.addParseLog("Cond");
        return condNode;
    }

    private LValNode parseLVal() throws Exception {
        LValNode lValNode = new LValNode();
        lValNode.addChild(parseSupporter.checkToken(TokenType.IDENFR));
        parseSupporter.addComponent("IDENFR" + " " + parseSupporter.getCurrentToken().getContent());
        while (parseSupporter.isLBracket()) {
            lValNode.addChild(parseSupporter.checkToken(TokenType.LBRACK));
            parseSupporter.addComponent("LBRACK" + " " + parseSupporter.getCurrentToken().getContent());
            lValNode.addChild(parseExp());
            lValNode.addChild(assertToken(TokenType.RBRACK, parseSupporter.getLineNum()));
        }
        parseSupporter.addParseLog("LVal");
        return lValNode;
    }

    private LOrExpNode parseLOrExp() throws Exception {
        LOrExpNode lOrExpNode = new LOrExpNode();
        lOrExpNode.addChild(parseLAndExp());
        parseSupporter.addParseLog("LOrExp");
        while (parseSupporter.isOr()) {
            lOrExpNode.addChild(parseSupporter.checkToken(TokenType.OR));
            parseSupporter.addComponent("OR" + " " + parseSupporter.getCurrentToken().getContent());
            lOrExpNode.addChild(parseLAndExp());
            parseSupporter.addParseLog("LOrExp");
        }
        return lOrExpNode;
    }

    private LAndExpNode parseLAndExp() throws Exception {
        LAndExpNode lAndExpNode = new LAndExpNode();
        lAndExpNode.addChild(parseEqExp());
        parseSupporter.addParseLog("LAndExp");
        while (parseSupporter.isAnd()) {
            lAndExpNode.addChild(parseSupporter.checkToken(TokenType.AND));
            parseSupporter.addComponent("AND" + " " + parseSupporter.getCurrentToken().getContent());
            lAndExpNode.addChild(parseEqExp());
            parseSupporter.addParseLog("LAndExp");
        }
        return lAndExpNode;
    }

    private EqExpNode parseEqExp() throws Exception {
        EqExpNode eqExpNode = new EqExpNode();
        eqExpNode.addChild(parseRelExp());
        parseSupporter.addParseLog("EqExp");
        while (parseSupporter.isEqOp()) {
            eqExpNode.addChild(parseSupporter.checkToken(parseSupporter.lookAhead(0).getType()));
            parseSupporter.addComponent(parseSupporter.lookAhead(-1).getType().toString() + " " + parseSupporter.getCurrentToken().getContent());
            eqExpNode.addChild(parseRelExp());
            parseSupporter.addParseLog("EqExp");
        }
        return eqExpNode;
    }

    private RelExpNode parseRelExp() throws Exception {
        RelExpNode relExpNode = new RelExpNode();
        relExpNode.addChild(parseAddExp());
        parseSupporter.addParseLog("RelExp");
        while (parseSupporter.isRelOp()) {
            relExpNode.addChild(parseSupporter.checkToken(parseSupporter.lookAhead(0).getType()));
            parseSupporter.addComponent(parseSupporter.lookAhead(-1).getType().toString() + " " + parseSupporter.getCurrentToken().getContent());
            relExpNode.addChild(parseAddExp());
            parseSupporter.addParseLog("RelExp");
        }
        return relExpNode;
    }

    private AddExpNode parseAddExp() throws Exception {
        AddExpNode addExpNode = new AddExpNode();
        addExpNode.addChild(parseMulExp());
        parseSupporter.addParseLog("AddExp");
        while (parseSupporter.isAddOp()) {
            addExpNode.addChild(parseSupporter.checkToken(parseSupporter.lookAhead(0).getType()));
            parseSupporter.addComponent(parseSupporter.lookAhead(-1).getType().toString() + " " + parseSupporter.getCurrentToken().getContent());
            addExpNode.addChild(parseMulExp());
            parseSupporter.addParseLog("AddExp");
        }
        return addExpNode;
    }

    private MulExpNode parseMulExp() throws Exception {
        MulExpNode mulExpNode = new MulExpNode();
        mulExpNode.addChild(parseUnaryExp());
        parseSupporter.addParseLog("MulExp");
        while (parseSupporter.isMulOp()) {
            mulExpNode.addChild(parseSupporter.checkToken(parseSupporter.lookAhead(0).getType()));
            parseSupporter.addComponent(parseSupporter.lookAhead(-1).getType().toString() + " " + parseSupporter.getCurrentToken().getContent());
            mulExpNode.addChild(parseUnaryExp());
            parseSupporter.addParseLog("MulExp");
        }
        return mulExpNode;
    }

    private UnaryExpNode parseUnaryExp() throws Exception {
        UnaryExpNode unaryExpNode = new UnaryExpNode();
        if (parseSupporter.isUnaryOp()) {
            unaryExpNode.addChild(parseUnaryOp());
            unaryExpNode.addChild(parseUnaryExp());
        } else if (parseSupporter.isCallee()) {
            unaryExpNode.addChild(parseCallee());
        } else {
            unaryExpNode.addChild(parsePrimaryExp());
        }
        parseSupporter.addParseLog("UnaryExp");
        return unaryExpNode;
    }

    private UnaryOpNode parseUnaryOp() throws Exception {
        UnaryOpNode unaryOpNode = new UnaryOpNode();
        unaryOpNode.addChild(parseSupporter.checkToken(parseSupporter.lookAhead(0).getType()));
        parseSupporter.addComponent(parseSupporter.lookAhead(-1).getType().toString() + " " + parseSupporter.getCurrentToken().getContent());
        parseSupporter.addParseLog("UnaryOp");
        return unaryOpNode;
    }

    private PrimaryExpNode parsePrimaryExp() throws Exception {
        PrimaryExpNode primaryExpNode = new PrimaryExpNode();
        if (parseSupporter.isLParent()) {
            primaryExpNode.addChild(parseSupporter.checkToken(TokenType.LPARENT));
            parseSupporter.addComponent(TokenType.LPARENT + " " + parseSupporter.getCurrentToken().getContent());
            primaryExpNode.addChild(parseExp());
            primaryExpNode.addChild(assertToken(TokenType.RPARENT, parseSupporter.getLineNum()));
        } else if (parseSupporter.isIdentifier()) {
            primaryExpNode.addChild(parseLVal());
        } else if (parseSupporter.isNumber()) {
            primaryExpNode.addChild(parseNumber());
        } else {
            primaryExpNode.addChild(parseCharacter());
        }
        parseSupporter.addParseLog("PrimaryExp");
        return primaryExpNode;
    }

    private CharacterNode parseCharacter() throws Exception {
        CharacterNode characterNode = new CharacterNode();
        characterNode.addChild(parseSupporter.checkToken(TokenType.CHRCON));
        parseSupporter.addComponent(TokenType.CHRCON + " " + parseSupporter.getCurrentToken().getContent());
        parseSupporter.addParseLog("Character");
        return characterNode;
    }
    
    private CalleeNode parseCallee() throws Exception {
        CalleeNode calleeNode = new CalleeNode();
        calleeNode.addChild(parseSupporter.checkToken(TokenType.IDENFR));
        parseSupporter.addComponent(TokenType.IDENFR + " " + parseSupporter.getCurrentToken().getContent());
        calleeNode.addChild(parseSupporter.checkToken(TokenType.LPARENT));
        parseSupporter.addComponent(TokenType.LPARENT + " " + parseSupporter.getCurrentToken().getContent());

        ParseSupporter old = this.parseSupporter;
        try {
            this.parseSupporter = new ParseSupporter(old);
            parseExp();
            this.parseSupporter = old;
            calleeNode.addChild(parseFuncRParams());
        } catch (RuntimeException ignored) {
        }
        calleeNode.addChild(assertToken(TokenType.RPARENT, parseSupporter.getLineNum()));
        return calleeNode;
    }

    private FuncRParamsNode parseFuncRParams() throws Exception {
        FuncRParamsNode funcRParamsNode = new FuncRParamsNode();
        funcRParamsNode.addChild(parseExp());
        while (parseSupporter.isComma()) {
            funcRParamsNode.addChild(parseSupporter.checkToken(TokenType.COMMA));
            parseSupporter.addComponent(TokenType.COMMA + " " + parseSupporter.getCurrentToken().getContent());
            funcRParamsNode.addChild(parseExp());
        }
        parseSupporter.addParseLog("FuncRParams");
        return funcRParamsNode;
    }

    private NumberNode parseNumber() throws Exception {
        NumberNode numberNode = new NumberNode();
        numberNode.addChild(parseSupporter.checkToken(TokenType.INTCON));
        parseSupporter.addComponent(TokenType.INTCON + " " + parseSupporter.getCurrentToken().getContent());
        parseSupporter.addParseLog("Number");
        return numberNode;
    }

    private MainFuncDefNode parseMainFuncDef() throws Exception {
        MainFuncDefNode mainFuncDefNode = new MainFuncDefNode();

        mainFuncDefNode.addChild(parseSupporter.checkToken(TokenType.INTTK));
        parseSupporter.addComponent(TokenType.INTTK + " " + parseSupporter.getCurrentToken().getContent());
        mainFuncDefNode.addChild(parseSupporter.checkToken(TokenType.MAINTK));
        parseSupporter.addComponent(TokenType.MAINTK + " " + parseSupporter.getCurrentToken().getContent());
        mainFuncDefNode.addChild(parseSupporter.checkToken(TokenType.LPARENT));
        parseSupporter.addComponent(TokenType.LPARENT + " " + parseSupporter.getCurrentToken().getContent());
        mainFuncDefNode.addChild(assertToken(TokenType.RPARENT, parseSupporter.getLineNum()));
        mainFuncDefNode.addChild(parseBlock());
        parseSupporter.addParseLog("MainFuncDef");
        return mainFuncDefNode;
    }

    public void printParseLog(OutputStream outputStream) {
        try (PrintWriter writer = new PrintWriter(new OutputStreamWriter(outputStream))) {
            for (String log : parseSupporter.getParseLog()) {
                writer.println(log);
            }
        } catch (Exception e) {
            System.err.println("Error");
        }
    }
}

package Frontend;

import Token.Token;
import Token.TokenTypes;
import Error.Error;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import Node.*;
public class Parser {
    public Token currentToken;
    public int index = 0;
    public List<Token> tokens = new ArrayList<>();
    public Parser(List<Token> tokens){
        this.tokens = tokens;
        this.currentToken = tokens.get(0);
    }
    public Token findToken(TokenTypes tokenType){
        if(currentToken.type == tokenType){
            Token currentToken1 = currentToken;
            if(index + 1 < tokens.size()){
                index++;
                currentToken = tokens.get(index);
            }
            return currentToken1;
        }
        else if(tokenType == TokenTypes.SEMICN){
            Error.errors.add(new Error(tokens.get(index - 1).line, 'i'));
            return new Token(TokenTypes.SEMICN, tokens.get(index - 1).line, ";");
        }
        else if(tokenType == TokenTypes.RPARENT){
            Error.errors.add(new Error(tokens.get(index - 1).line, 'j'));
            return new Token(TokenTypes.RBRACE, tokens.get(index - 1).line, ")");
        }
        else if(tokenType == TokenTypes.RBRACK){
            Error.errors.add(new Error(tokens.get(index - 1).line, 'k'));
            return new Token(TokenTypes.RBRACK, tokens.get(index - 1).line, "]");
        }
        else {
            throw new RuntimeException("Can't find at line " + currentToken.line);
        }
    }
    public CompUnitNode compUnitAnalyze(){
        List<DeclNode> declNodes = new ArrayList<>();
        List<FuncDefNode> funcDefNodes = new ArrayList<>();
        MainFuncDefNode mainFuncDefNode;
        while (tokens.get(index + 1).type != TokenTypes.MAINTK && tokens.get(index + 2).type != TokenTypes.LPARENT){
            declNodes.add(declAnalyze());
        }
        while (tokens.get(index + 1).type != TokenTypes.MAINTK){
            funcDefNodes.add(funcDefAnalyze());
        }
        mainFuncDefNode = mainFuncDefAnalyze();
        return new CompUnitNode(declNodes, funcDefNodes, mainFuncDefNode);
    }
    public DeclNode declAnalyze(){
        ConstDeclNode constDeclNode;
        VarDeclNode varDeclNode;
        if(currentToken.type == TokenTypes.CONSTTK){
            constDeclNode = constDeclAnalyze();
            return new DeclNode(constDeclNode);
        }
        else {
            varDeclNode = varDeclAnalyze();
            return new DeclNode(varDeclNode);
        }

    }
    public ConstDeclNode constDeclAnalyze(){
        Token const1 = findToken(TokenTypes.CONSTTK);
        BTypeNode bTypeNode;
        if(currentToken.type == TokenTypes.INTTK){
            bTypeNode = new BTypeNode(findToken(TokenTypes.INTTK));
        }
        else {
            bTypeNode = new BTypeNode(findToken(TokenTypes.CHARTK));
        }
        List<ConstDefNode> constDefNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        constDefNodes.add(constDefAnalyze());
        while (currentToken.type == TokenTypes.COMMA){
            commas.add(findToken(TokenTypes.COMMA));
            constDefNodes.add(constDefAnalyze());
        }
        Token semicolon = findToken(TokenTypes.SEMICN);
        return new ConstDeclNode(const1, bTypeNode, commas, semicolon, constDefNodes);
    }
    public ConstDefNode constDefAnalyze(){
        Token Ident;
        Token leftBracket = null;
        Token rightBracket = null;
        Token equal;
        ConstInitValNode constInitValNode;
        ConstExpNode constExpNode = null;
        Ident = findToken(TokenTypes.IDENFR);
        if(currentToken.type == TokenTypes.LBRACK){
            leftBracket = findToken(TokenTypes.LBRACK);
            constExpNode = constExpAnalyze();
            rightBracket = findToken(TokenTypes.RBRACK);
        }
        equal = findToken(TokenTypes.ASSIGN);
        constInitValNode = constInitValAnalyze();
        if(leftBracket != null){
            return new ConstDefNode(Ident, leftBracket, rightBracket, equal, constExpNode, constInitValNode);
        }
        else {
            return new ConstDefNode(Ident, equal, constInitValNode);
        }
    }
    public ConstInitValNode constInitValAnalyze(){
        List<ConstExpNode> constExpNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token leftBrace;
        Token rightBrace;
        Token stringConst;
        if(currentToken.type == TokenTypes.STRCON){
            stringConst = findToken(TokenTypes.STRCON);
            return new ConstInitValNode(stringConst);
        }
        else if(currentToken.type == TokenTypes.LBRACE){
            leftBrace = findToken(TokenTypes.LBRACE);
            if(currentToken.type != TokenTypes.RBRACE){
                constExpNodes.add(constExpAnalyze());
                while (currentToken.type == TokenTypes.COMMA){
                    commas.add(findToken(TokenTypes.COMMA));
                    constExpNodes.add(constExpAnalyze());
                }
            }
            rightBrace = findToken(TokenTypes.RBRACE);
            return new ConstInitValNode(leftBrace, rightBrace, commas, constExpNodes);
        }
        else {
            return new ConstInitValNode(constExpAnalyze());
        }
    }
    public VarDeclNode varDeclAnalyze(){
        BTypeNode bTypeNode;
        List<Token> commas = new ArrayList<>();
        Token semicolon;
        List<VarDefNode> varDefNodes = new ArrayList<>();
        if(currentToken.type == TokenTypes.INTTK){
            bTypeNode = new BTypeNode(findToken(TokenTypes.INTTK));
        }
        else {
            bTypeNode = new BTypeNode(findToken(TokenTypes.CHARTK));
        }
        varDefNodes.add(varDefAnalyze());
        while (currentToken.type == TokenTypes.COMMA){
            commas.add(findToken(TokenTypes.COMMA));
            varDefNodes.add(varDefAnalyze());
        }
        semicolon = findToken(TokenTypes.SEMICN);
        return new VarDeclNode(bTypeNode, commas, semicolon, varDefNodes);
    }
    public VarDefNode varDefAnalyze(){
        Token Ident;
        Token leftBracket = null;
        Token rightBracket = null;
        Token equal = null;
        InitValNode initValNode = null;
        ConstExpNode constExpNode = null;
        Ident = findToken(TokenTypes.IDENFR);
        if(currentToken.type == TokenTypes.LBRACK){
            leftBracket = findToken(TokenTypes.LBRACK);
            constExpNode = constExpAnalyze();
            rightBracket = findToken(TokenTypes.RBRACK);
        }
        if(currentToken.type == TokenTypes.ASSIGN){
            equal = findToken(TokenTypes.ASSIGN);
            initValNode = initValAnalyze();
        }
        return new VarDefNode(Ident, leftBracket, rightBracket, equal, constExpNode, initValNode);
    }
    public InitValNode initValAnalyze(){
        List<ExpNode> expNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token leftBrace;
        Token rightBrace;
        Token stringConst;
        if(currentToken.type == TokenTypes.STRCON){
            stringConst = findToken(TokenTypes.STRCON);
            return new InitValNode(stringConst);
        }
        else if(currentToken.type == TokenTypes.LBRACE){
            leftBrace = findToken(TokenTypes.LBRACE);
            if(currentToken.type != TokenTypes.RBRACE){
                expNodes.add(expAnalyze());
                while (currentToken.type == TokenTypes.COMMA){
                    commas.add(findToken(TokenTypes.COMMA));
                    expNodes.add(expAnalyze());
                }
            }
            rightBrace = findToken(TokenTypes.RBRACE);
            return new InitValNode(leftBrace, rightBrace, commas, expNodes);
        }
        else {
            return new InitValNode(expAnalyze());
        }
    }
    public FuncDefNode funcDefAnalyze(){
        FuncTypeNode funcTypeNode;
        Token Ident;
        Token leftParent;
        Token rightParent;
        FuncFParamsNode funcFParamsNode = null;
        BlockNode blockNode;
        funcTypeNode = funcTypeAnalyze();
        Ident = findToken(TokenTypes.IDENFR);
        leftParent = findToken(TokenTypes.LPARENT);
        if(currentToken.type != TokenTypes.RPARENT){
            funcFParamsNode = funcFParamsAnalyze();
        }
        rightParent = findToken(TokenTypes.RPARENT);
        blockNode = blockAnalyze();
        return new FuncDefNode(funcTypeNode, Ident, leftParent, rightParent, funcFParamsNode, blockNode);
    }
    public FuncTypeNode funcTypeAnalyze(){
        if(currentToken.type == TokenTypes.INTTK){
            return new FuncTypeNode(findToken(TokenTypes.INTTK));
        }
        else if(currentToken.type == TokenTypes.CHARTK){
            return new FuncTypeNode(findToken(TokenTypes.CHARTK));
        }
        else {
            return new FuncTypeNode(findToken(TokenTypes.VOIDTK));
        }
    }
    public FuncFParamsNode funcFParamsAnalyze(){
        List<FuncFParamNode> funcFParamNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        funcFParamNodes.add(funcFParamAnalyze());
        while (currentToken.type == TokenTypes.COMMA){
            commas.add(findToken(TokenTypes.COMMA));
            funcFParamNodes.add(funcFParamAnalyze());
        }
        return new FuncFParamsNode(funcFParamNodes, commas);
    }
    public FuncFParamNode funcFParamAnalyze(){
        BTypeNode bTypeNode;
        Token Ident;
        Token leftBracket = null;
        Token rightBracket = null;
        if(currentToken.type == TokenTypes.INTTK){
            bTypeNode = new BTypeNode(findToken(TokenTypes.INTTK));
        }
        else {
            bTypeNode = new BTypeNode(findToken(TokenTypes.CHARTK));
        }
        Ident = findToken(TokenTypes.IDENFR);
        if(currentToken.type == TokenTypes.LBRACK){
            leftBracket = findToken(TokenTypes.LBRACK);
            rightBracket = findToken(TokenTypes.RBRACK);
        }
        return new FuncFParamNode(bTypeNode, Ident, leftBracket, rightBracket);
    }
    public BlockNode blockAnalyze(){
        Token leftBrace;
        Token rightBrace;
        List<BlockItemNode> blockItemNodes = new ArrayList<>();
        leftBrace = findToken(TokenTypes.LBRACE);
        while (currentToken.type != TokenTypes.RBRACE){
            blockItemNodes.add(blockItemAnalyze());
        }
        rightBrace = findToken(TokenTypes.RBRACE);
        return new BlockNode(leftBrace, rightBrace, blockItemNodes);
    }
    public BlockItemNode blockItemAnalyze(){
        DeclNode declNode;
        StmtNode stmtNode;
        if(currentToken.type == TokenTypes.CONSTTK || currentToken.type == TokenTypes.INTTK || currentToken.type == TokenTypes.CHARTK){
            declNode = declAnalyze();
            return new BlockItemNode(declNode);
        }
        else {
            stmtNode = stmtAnalyze();
            return new BlockItemNode(stmtNode);
        }
    }
    public MainFuncDefNode mainFuncDefAnalyze(){
        Token int1;
        Token main;
        Token leftParent;
        Token rightParent;
        BlockNode blockNode;
        int1 = findToken(TokenTypes.INTTK);
        main = findToken(TokenTypes.MAINTK);
        leftParent = findToken(TokenTypes.LPARENT);
        rightParent = findToken(TokenTypes.RPARENT);
        blockNode = blockAnalyze();
        return new MainFuncDefNode(int1, main, leftParent, rightParent, blockNode);
    }
    public StmtNode stmtAnalyze(){
        if(currentToken.type == TokenTypes.LBRACE){
            BlockNode blockNode = blockAnalyze();
            return new StmtNode(StmtNode.types.Block, blockNode);
        }
        else if(currentToken.type == TokenTypes.IFTK){
            Token if1 = findToken(TokenTypes.IFTK);
            Token leftParent = findToken(TokenTypes.LPARENT);
            CondNode condNode = condAnalyze();
            Token rightParent = findToken(TokenTypes.RPARENT);
            StmtNode stmtNode1 = stmtAnalyze();
            Token else1 = null;
            StmtNode stmtNode2 = null;
            if(currentToken.type == TokenTypes.ELSETK){
                else1 = findToken(TokenTypes.ELSETK);
                stmtNode2 = stmtAnalyze();
            }
            return new StmtNode(StmtNode.types.If, if1, leftParent, condNode, rightParent, stmtNode1, else1, stmtNode2);
        }
        else if(currentToken.type == TokenTypes.FORTK){
            Token for1 = null;
            Token leftParent = null;
            ForStmtNode forStmtNode1 = null;
            Token semicolon1 = null;
            CondNode condNode = null;
            Token semicolon2 = null;
            ForStmtNode forStmtNode2 = null;
            Token rightParent = null;
            StmtNode stmtNode = null;
            for1 = findToken(TokenTypes.FORTK);
            leftParent = findToken(TokenTypes.LPARENT);
            if(currentToken.type != TokenTypes.SEMICN){
                forStmtNode1 = forStmtAnalyze();
            }
            semicolon1 = findToken(TokenTypes.SEMICN);
            if(currentToken.type != TokenTypes.SEMICN){
                condNode = condAnalyze();
            }
            semicolon2 = findToken(TokenTypes.SEMICN);
            if(currentToken.type != TokenTypes.RPARENT){
                forStmtNode2 = forStmtAnalyze();
            }
            rightParent = findToken(TokenTypes.RPARENT);
            stmtNode = stmtAnalyze();
            return new StmtNode(StmtNode.types.For, for1, leftParent, forStmtNode1, semicolon1, condNode, semicolon2, forStmtNode2, rightParent, stmtNode);
        }
        else if(currentToken.type == TokenTypes.BREAKTK){
            Token break1 = findToken(TokenTypes.BREAKTK);
            Token semicolon = findToken(TokenTypes.SEMICN);
            return new StmtNode(StmtNode.types.Break, break1, semicolon);
        }
        else if(currentToken.type == TokenTypes.CONTINUETK){
            Token break1 = findToken(TokenTypes.CONTINUETK);
            Token semicolon = findToken(TokenTypes.SEMICN);
            return new StmtNode(StmtNode.types.Break, break1, semicolon);
        }
        else if (currentToken.type == TokenTypes.PRINTFTK){
            Token printf1 = findToken(TokenTypes.PRINTFTK);
            Token leftParent = findToken(TokenTypes.LPARENT);
            Token stringConst = findToken(TokenTypes.STRCON);
            List<Token> commas = new ArrayList<>();
            List<ExpNode> expNodes = new ArrayList<>();
            while (currentToken.type == TokenTypes.COMMA){
                commas.add(findToken(TokenTypes.COMMA));
                expNodes.add(expAnalyze());
            }
            Token rightParent = findToken(TokenTypes.RPARENT);
            Token semicolon = findToken(TokenTypes.SEMICN);
            return new StmtNode(StmtNode.types.Printf, printf1, leftParent, stringConst, commas, expNodes, rightParent, semicolon);
        }
        else if(currentToken.type == TokenTypes.RETURNTK){
            Token return1 = findToken(TokenTypes.RETURNTK);
            ExpNode expNode = null;
            if(currentToken.type != TokenTypes.SEMICN){
                expNode = expAnalyze();
            }
            Token semicolon = findToken(TokenTypes.SEMICN);
            return new StmtNode(StmtNode.types.Return, return1, expNode, semicolon);
        }
        else {
            boolean isAssign = false;
            for(int i = index; tokens.get(i).line <= currentToken.line; i++){
                if(tokens.get(i).type == TokenTypes.ASSIGN){
                    isAssign = true;
                    break;
                }
            }
            if(isAssign){
                LValNode lValNode = lValAnalyze();
                Token equal = findToken(TokenTypes.ASSIGN);
                if(currentToken.type == TokenTypes.GETINTTK){
                    Token getInt = findToken(TokenTypes.GETINTTK);
                    Token leftParent = findToken(TokenTypes.LPARENT);
                    Token rightParent = findToken(TokenTypes.RPARENT);
                    Token semicolon = findToken(TokenTypes.SEMICN);
                    return new StmtNode(StmtNode.types.Get, lValNode, equal, getInt, leftParent, rightParent, semicolon);
                }
                else if(currentToken.type == TokenTypes.GETCHARTK){
                    Token getChar = findToken(TokenTypes.GETCHARTK);
                    Token leftParent = findToken(TokenTypes.LPARENT);
                    Token rightParent = findToken(TokenTypes.RPARENT);
                    Token semicolon = findToken(TokenTypes.SEMICN);
                    return new StmtNode(StmtNode.types.Get, lValNode, equal, getChar, leftParent, rightParent, semicolon);
                }
                else {
                    ExpNode expNode = expAnalyze();
                    Token semicolon = findToken(TokenTypes.SEMICN);
                    return new StmtNode(StmtNode.types.LVal, lValNode, equal, expNode, semicolon);
                }
            }
            else {
                ExpNode expNode = null;
                if(currentToken.type != TokenTypes.SEMICN){
                    expNode = expAnalyze();
                }
                Token semicolon = findToken(TokenTypes.SEMICN);
                return new StmtNode(StmtNode.types.Exp, expNode, semicolon);
            }
        }
    }
    public ForStmtNode forStmtAnalyze(){
        LValNode lValNode = lValAnalyze();
        Token equal = findToken(TokenTypes.ASSIGN);
        ExpNode expNode = expAnalyze();
        return new ForStmtNode(lValNode, expNode, equal);
    }
    public ExpNode expAnalyze(){
        AddExpNode addExpNode = addExpAnalyze();
        return new ExpNode(addExpNode);
    }
    public CondNode condAnalyze(){
        LOrExpNode lOrExpNode = lOrExpAnalyze();
        return new CondNode(lOrExpNode);
    }
    public LValNode lValAnalyze(){
        Token Ident = findToken(TokenTypes.IDENFR);
        Token leftBracket = null;
        Token rightBracket = null;
        ExpNode expNode = null;
        if(currentToken.type == TokenTypes.LBRACK){
            leftBracket = findToken(TokenTypes.LBRACK);
            expNode = expAnalyze();
            rightBracket = findToken(TokenTypes.RBRACK);
        }
        return new LValNode(Ident, leftBracket, expNode, rightBracket);
    }
    public PrimaryExpNode primaryExpAnalyze(){
        if(currentToken.type == TokenTypes.INTCON){
            NumberNode numberNode = numberAnalyze();
            return new PrimaryExpNode(numberNode);
        }
        else if(currentToken.type == TokenTypes.CHRCON){
            CharacterNode characterNode = characterAnalyze();
            return new PrimaryExpNode(characterNode);
        }
        else if(currentToken.type == TokenTypes.LPARENT){
            Token leftParent = findToken(TokenTypes.LPARENT);
            ExpNode expNode = expAnalyze();
            Token rightParent = findToken(TokenTypes.RPARENT);
            return new PrimaryExpNode(expNode, leftParent, rightParent);
        }
        else {
            LValNode lValNode = lValAnalyze();
            return new PrimaryExpNode(lValNode);
        }
    }
    public NumberNode numberAnalyze(){
        Token number = findToken(TokenTypes.INTCON);
        return new NumberNode(number);
    }
    public CharacterNode characterAnalyze(){
        Token character = findToken(TokenTypes.CHRCON);
        return new CharacterNode(character);
    }
    public UnaryExpNode unaryExpAnalyze(){
        if(currentToken.type == TokenTypes.IDENFR && tokens.get(index + 1).type == TokenTypes.LPARENT){
            Token Ident = findToken(TokenTypes.IDENFR);
            Token leftParent = findToken(TokenTypes.LPARENT);
            FuncRParamsNode funcRParamsNode = null;
            if(currentToken.type != TokenTypes.RPARENT){
                funcRParamsNode = funcRParamsAnalyze();
            }
            Token rightParent = findToken(TokenTypes.RPARENT);
            return new UnaryExpNode(Ident, leftParent, rightParent, funcRParamsNode);
        }
        else if(currentToken.type == TokenTypes.PLUS || currentToken.type == TokenTypes.MINU || currentToken.type == TokenTypes.NOT){
            UnaryOpNode unaryOpNode = unaryOpAnalyze();
            UnaryExpNode unaryExpNode = unaryExpAnalyze();
            return new UnaryExpNode(unaryOpNode, unaryExpNode);
        }
        else {
            PrimaryExpNode primaryExpNode = primaryExpAnalyze();
            return new UnaryExpNode(primaryExpNode);
        }
    }
    public UnaryOpNode unaryOpAnalyze(){
        Token op = null;
        if(currentToken.type == TokenTypes.PLUS){
            op = findToken(TokenTypes.PLUS);
        }
        else if(currentToken.type == TokenTypes.MINU){
            op = findToken(TokenTypes.MINU);
        }
        else {
            op = findToken(TokenTypes.NOT);
        }
        return new UnaryOpNode(op);
    }
    public FuncRParamsNode funcRParamsAnalyze(){
        List<ExpNode> expNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        expNodes.add(expAnalyze());
        while (currentToken.type == TokenTypes.COMMA){
            commas.add(findToken(TokenTypes.COMMA));
            expNodes.add(expAnalyze());
        }
        return new FuncRParamsNode(expNodes, commas);
    }
    public MulExpNode mulExpAnalyze(){
        UnaryExpNode unaryExpNode = unaryExpAnalyze();
        MulExpNode mulExpNode = null;
        Token op = null;
        if(currentToken.type == TokenTypes.MULT){
            op = findToken(TokenTypes.MULT);
            mulExpNode = mulExpAnalyze();
        }
        else if(currentToken.type == TokenTypes.DIV){
            op = findToken(TokenTypes.DIV);
            mulExpNode = mulExpAnalyze();
        }
        else if(currentToken.type == TokenTypes.MOD){
            op = findToken(TokenTypes.MOD);
            mulExpNode = mulExpAnalyze();
        }
        return new MulExpNode(mulExpNode, op, unaryExpNode);
    }
    public AddExpNode addExpAnalyze(){
        MulExpNode mulExpNode = mulExpAnalyze();
        Token op = null;
        AddExpNode addExpNode = null;
        if(currentToken.type == TokenTypes.PLUS){
            op = findToken(TokenTypes.PLUS);
            addExpNode = addExpAnalyze();
        }
        else if(currentToken.type == TokenTypes.MINU){
            op = findToken(TokenTypes.MINU);
            addExpNode = addExpAnalyze();
        }
        return new AddExpNode(mulExpNode, op, addExpNode);
    }
    public RelExpNode relExpAnalyze(){
        AddExpNode addExpNode = addExpAnalyze();
        Token op = null;
        RelExpNode relExpNode = null;
        if(currentToken.type == TokenTypes.LSS){
            op = findToken(TokenTypes.LSS);
            relExpNode = relExpAnalyze();
        }
        else if(currentToken.type == TokenTypes.GRE){
            op = findToken(TokenTypes.GRE);
            relExpNode = relExpAnalyze();
        }
        else if(currentToken.type == TokenTypes.LEQ){
            op = findToken(TokenTypes.LEQ);
            relExpNode = relExpAnalyze();
        }
        else if(currentToken.type == TokenTypes.GEQ){
            op = findToken(TokenTypes.GEQ);
            relExpNode = relExpAnalyze();
        }
        return new RelExpNode(relExpNode, op, addExpNode);
    }
    public EqExpNode eqExpAnalyze(){
        RelExpNode relExpNode = relExpAnalyze();
        Token op = null;
        EqExpNode eqExpNode = null;
        if(currentToken.type == TokenTypes.EQL){
            op = findToken(TokenTypes.EQL);
            eqExpNode = eqExpAnalyze();
        }
        else if(currentToken.type == TokenTypes.NEQ){
            op = findToken(TokenTypes.NEQ);
            eqExpNode = eqExpAnalyze();
        }
        return new EqExpNode(relExpNode, op, eqExpNode);
    }
    public LAndExpNode lAndExpAnalyze(){
        EqExpNode eqExpNode = eqExpAnalyze();
        Token op = null;
        LAndExpNode lAndExpNode = null;
        if(currentToken.type == TokenTypes.AND){
            op = findToken(TokenTypes.AND);
            lAndExpNode = lAndExpAnalyze();
        }
        return new LAndExpNode(lAndExpNode, op, eqExpNode);
    }
    public LOrExpNode lOrExpAnalyze(){
        LAndExpNode lAndExpNode = lAndExpAnalyze();
        Token op = null;
        LOrExpNode lOrExpNode = null;
        if(currentToken.type == TokenTypes.OR){
            op = findToken(TokenTypes.OR);
            lOrExpNode = lOrExpAnalyze();
        }
        return new LOrExpNode(lAndExpNode, op, lOrExpNode);
    }
    public ConstExpNode constExpAnalyze(){
        AddExpNode addExpNode = addExpAnalyze();
        return new ConstExpNode(addExpNode);
    }
}

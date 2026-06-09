package frontend;
import Token.*;
import Node.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Parser {
    private static Parser onlyParser;
    private Parser(){}
    public static Parser getInstance(){
        if(onlyParser == null){
            onlyParser = new Parser();
        }
        return onlyParser;
    }

    ArrayList<Token> tokens;
    int index ;
    int tokenlen;
    String filePath;
    boolean isPrint ;
    CompUnitNode compUnitNode;

    Map<NodeType, String> nodeName = new HashMap<>(){
        {
            put(NodeType.CompUnit, "<CompUnit>");
            put(NodeType.Decl, "<Decl>");
            put(NodeType.ConstDecl, "<ConstDecl>");
            put(NodeType.BType, "<BType>");
            put(NodeType.ConstDef, "<ConstDef>");
            put(NodeType.ConstInitVal, "<ConstInitVal>");
            put(NodeType.VarDecl, "<VarDecl>");
            put(NodeType.VarDef, "<VarDef>");
            put(NodeType.InitVal, "<InitVal>");
            put(NodeType.FuncDef, "<FuncDef>");
            put(NodeType.MainFuncDef, "<MainFuncDef>");
            put(NodeType.FuncType, "<FuncType>");
            put(NodeType.FuncFParams, "<FuncFParams>");
            put(NodeType.FuncFParam, "<FuncFParam>");
            put(NodeType.Block, "<Block>");
            put(NodeType.BlockItem, "<BlockItem>");
            put(NodeType.Stmt, "<Stmt>");
            put(NodeType.ForStmt, "<ForStmt>");
            put(NodeType.Exp, "<Exp>");
            put(NodeType.Cond, "<Cond>");
            put(NodeType.LVal, "<LVal>");
            put(NodeType.PrimaryExp, "<PrimaryExp>");
            put(NodeType.Number, "<Number>");
            put(NodeType.Character, "<Character>");
            put(NodeType.UnaryExp, "<UnaryExp>");
            put(NodeType.UnaryOp, "<UnaryOp>");
            put(NodeType.FuncRParams, "<FuncRParams>");
            put(NodeType.MulExp, "<MulExp>");
            put(NodeType.AddExp, "<AddExp>");
            put(NodeType.RelExp, "<RelExp>");
            put(NodeType.EqExp, "<EqExp>");
            put(NodeType.LAndExp, "<LAndExp>");
            put(NodeType.LOrExp, "<LOrExp>");
            put(NodeType.ConstExp, "<ConstExp>");
        }
    };


    public void handle(ArrayList<Token> tokenlist){
        init();
        this.tokens = tokenlist;
        this.tokenlen = tokens.size();
        getsym();//index = 0;
        this.compUnitNode = this.compUnit();
        startPrint();
    }

    void init(){
        this.index = -1;
        this.filePath =  "parser.txt";
        this.isPrint = true;
        clearFile();
    }

    Token match(Token token, TokenType expectedType){
        if(token.getType() == expectedType){
            //匹配成功

            getsym();
            return token;
        }else {

            return token;
        }
    }

    Token match(Token token, TokenType[] expectedTypes){
        boolean success = false;
        for(TokenType type : expectedTypes){
            if(token.getType() == type){
                success = true;
                break;
            }
        }

        //匹配成功
        if(success){

            getsym();
            return token;
        }else {

            return token;
        }
    }

    void clearFile(){
        try{
            BufferedWriter writer = new BufferedWriter(new FileWriter(this.filePath, false));  // 或者直接省略false
            writer.close();
        }catch (Exception e){
            System.out.println(e);
        }
    }

     public void output(Token token){
        try{
            if(isPrint){
                BufferedWriter writer = new BufferedWriter(new FileWriter(this.filePath, true));
                writer.write(token.toString());
                writer.close();
            }
        }catch(Exception e){
            System.out.println(e);
        }
    }

     public void output(NodeType type){
        try{
            if(isPrint){
                BufferedWriter writer = new BufferedWriter(new FileWriter(this.filePath, true));
                writer.write(nodeName.getOrDefault(type, "None"));
                writer.write("\n");
                writer.close();
            }
        }catch (Exception e){
            System.out.println(e);
        }
    }

    CompUnitNode compUnit(){
        //CompUnit -> {Decl} {FuncDef} MainFuncDef
        ArrayList<DeclNode> declNodes = new ArrayList<DeclNode>();
        ArrayList<FuncDefNode> funcDefNodes = new ArrayList<FuncDefNode>();
        MainFuncDefNode mainFuncDefNode;
        while(tokens.get(index + 1).getType() != TokenType.MAINTK && tokens.get(index + 2).getType() != TokenType.LPARENT){
            declNodes.add(Decl());
        }
        while(tokens.get(index + 1).getType() != TokenType.MAINTK){
            funcDefNodes.add(FuncDef());
        }
        mainFuncDefNode = MainFuncDef();

        return new CompUnitNode(declNodes, funcDefNodes, mainFuncDefNode);
    }

    DeclNode Decl(){
        // Decl → ConstDecl | VarDecl
        ConstDeclNode constDeclNode = null;
        VarDeclNode varDeclNode = null;
        if(tokens.get(index).getType() == TokenType.CONSTTK){
            constDeclNode = ConstDecl();
        }else {
            varDeclNode = VarDecl();
        }
        return new DeclNode(constDeclNode, varDeclNode);
    }

    ConstDeclNode ConstDecl(){
        // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        BTypeNode bTypeNode;
        ArrayList<ConstDefNode> constDefNodes = new ArrayList<ConstDefNode>();

        ArrayList<Token> commas = new ArrayList<Token>();
        Token constToken;
        Token semicnToken;

        constToken = match(tokens.get(index), TokenType.CONSTTK);
        bTypeNode = BType();
        constDefNodes.add(ConstDef());
        while(tokens.get(index).getType() == TokenType.COMMA){
            commas.add(match(tokens.get(index), TokenType.COMMA));
            constDefNodes.add(ConstDef());
        }
        semicnToken = match(tokens.get(index), TokenType.SEMICN);

        return new ConstDeclNode(constToken, bTypeNode, constDefNodes, commas, semicnToken);
    }

    BTypeNode BType(){
        //BType → 'int' | 'char'
        Token type = match(tokens.get(index), new TokenType[]{TokenType.INTTK, TokenType.CHARTK});
        return new BTypeNode(type);
    }

    ConstDefNode ConstDef(){
        // ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        Token ident;
        Token leftBrack = null;
        Token rightBrack = null;
        ConstExpNode constExpNode = null;
        ConstInitValNode constInitValNode;

        Token EqToken;

        ident = match(tokens.get(index), TokenType.IDENFR);
        if(tokens.get(index).getType() == TokenType.LBRACK){
            leftBrack = match(tokens.get(index), TokenType.LBRACK);
            constExpNode = ConstExp();
            rightBrack = match(tokens.get(index), TokenType.RBRACK);
        }
        EqToken = match(tokens.get(index), TokenType.ASSIGN);
        constInitValNode = ConstInitVal();
        return new ConstDefNode(ident, leftBrack, rightBrack, constExpNode, EqToken, constInitValNode);
    }

    ConstInitValNode ConstInitVal(){
        // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        // 1.常表达式初值 2.一维数组初值
        ArrayList<ConstExpNode> constExpNodes = new ArrayList<ConstExpNode>();
        Token leftBrace = null;
        Token rightBrace = null;
        Token stringConst = null;
        ArrayList<Token> commas = new ArrayList<Token>();
        if(tokens.get(index).getType() == TokenType.LBRACE){
            //'{' [ ConstExp { ',' ConstExp } ] '}'
            leftBrace = match(tokens.get(index), TokenType.LBRACE);



            if(tokens.get(index).getType() != TokenType.RBRACE){
                constExpNodes.add(ConstExp());
                while(tokens.get(index).getType() == TokenType.COMMA){
                    commas.add(match(tokens.get(index), TokenType.COMMA));
                    constExpNodes.add(ConstExp());
                }
                rightBrace = match(tokens.get(index), TokenType.RBRACE);
            }else{
                rightBrace = match(tokens.get(index), TokenType.RBRACE);
            }
        }
        else if(tokens.get(index).getType() == TokenType.STRCON){
            //StringConst
            stringConst = match(tokens.get(index), TokenType.STRCON);
        }else {
            //ConstExp
            constExpNodes.add(ConstExp());
        }
        return new ConstInitValNode(constExpNodes, leftBrace, rightBrace, stringConst, commas);
    }

    VarDeclNode VarDecl(){
        // VarDecl → BType VarDef { ',' VarDef } ';'
        BTypeNode bTypeNode;
        ArrayList<VarDefNode> varDefNodes = new ArrayList<VarDefNode>();

        ArrayList<Token> commas = new ArrayList<Token>();
        Token semicnToken;

        bTypeNode = BType();
        varDefNodes.add(VarDef());
        while(tokens.get(index).getType() == TokenType.COMMA){
            commas.add(match(tokens.get(index), TokenType.COMMA));
            varDefNodes.add(VarDef());
        }
        semicnToken = match(tokens.get(index), TokenType.SEMICN);

        return new VarDeclNode(bTypeNode, varDefNodes, commas, semicnToken);
    }

    VarDefNode VarDef(){
        //VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        // 包含普通常量、一维数组定义
        Token ident;
        ConstExpNode constExpNode = null;
        InitValNode initValNode = null;

        Token leftBrack = null;
        Token rightBrack = null;
        Token eqToken = null;
        ident = match(tokens.get(index), TokenType.IDENFR);
        if(tokens.get(index).getType() == TokenType.LBRACK){
            leftBrack = match(tokens.get(index), TokenType.LBRACK);
            constExpNode = ConstExp();
            rightBrack = match(tokens.get(index), TokenType.RBRACK);
        }
        if(tokens.get(index).getType() == TokenType.ASSIGN){
            eqToken = match(tokens.get(index), TokenType.ASSIGN);
            initValNode = InitVal();
        }
        return new VarDefNode(ident, constExpNode, initValNode, leftBrack, rightBrack, eqToken);
    }

    InitValNode InitVal(){
        // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        // 1.表达式初值 2.一维数组初值
        ArrayList<ExpNode> expNodes = new ArrayList<ExpNode>();
        Token leftBrace = null;
        Token rightBrace = null;
        Token stringConst = null;
        ArrayList<Token> commas = new ArrayList<Token>();

        if(tokens.get(index).getType() == TokenType.LBRACE){
            //'{' [ Exp { ',' Exp } ] '}'
            leftBrace = match(tokens.get(index), TokenType.LBRACE);

            if(tokens.get(index).getType() != TokenType.RBRACE){
                expNodes.add(Exp());
                while(tokens.get(index).getType() == TokenType.COMMA){
                    commas.add(match(tokens.get(index), TokenType.COMMA));
                    expNodes.add(Exp());
                }
                rightBrace = match(tokens.get(index), TokenType.RBRACE);
            }else {
                rightBrace = match(tokens.get(index), TokenType.RBRACE);
            }
        }
        else if(tokens.get(index).getType() == TokenType.STRCON){
            //StringConst
            stringConst = match(tokens.get(index), TokenType.STRCON);
        }
        else {
            //Exp
            expNodes.add(Exp());
        }
        return new InitValNode(expNodes, leftBrace, rightBrace, stringConst, commas);
    }

    FuncDefNode FuncDef(){
        // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // 1.无形参 2.有形参
        FuncTypeNode funcTypeNode;
        Token ident;
        FuncFParamsNode funcFParamsNode = null;
        BlockNode blockNode;

        Token leftParent;
        Token rightParent;
        funcTypeNode = FuncType();
        ident = match(tokens.get(index), TokenType.IDENFR);
        leftParent = match(tokens.get(index), TokenType.LPARENT);
        if(tokens.get(index).getType() != TokenType.RPARENT){
            funcFParamsNode = FuncFParams();
        }
        rightParent = match(tokens.get(index), TokenType.RPARENT);
        blockNode = Block();
        return new FuncDefNode(funcTypeNode, ident, funcFParamsNode, blockNode, leftParent, rightParent);
    }

    MainFuncDefNode MainFuncDef(){
        //MainFuncDef → 'int' 'main' '(' ')' Block
        BlockNode blockNode;

        Token intToken;
        Token mainToken;
        Token leftParent;
        Token rightParent;

        intToken = match(tokens.get(index), TokenType.INTTK);
        mainToken = match(tokens.get(index), TokenType.MAINTK);
        leftParent = match(tokens.get(index), TokenType.LPARENT);
        rightParent = match(tokens.get(index), TokenType.RPARENT);
        blockNode = Block();

        return new MainFuncDefNode(intToken, mainToken, leftParent, rightParent, blockNode);

    }

    FuncTypeNode FuncType(){
        //FuncType → 'void' | 'int' | 'char'
        Token type;
        type = match(tokens.get(index), new TokenType[]{TokenType.VOIDTK, TokenType.INTTK, TokenType.CHARTK});
        return new FuncTypeNode(type);
    }

    FuncFParamsNode FuncFParams(){
        // FuncFParams → FuncFParam { ',' FuncFParam }
        ArrayList<FuncFParamNode> funcFParamNodes = new ArrayList<FuncFParamNode>();

        ArrayList<Token> commas = new ArrayList<Token>();

        funcFParamNodes.add(FuncFParam());
        while(tokens.get(index).getType() == TokenType.COMMA){
            commas.add(match(tokens.get(index), TokenType.COMMA));
            funcFParamNodes.add(FuncFParam());
        }
        return new FuncFParamsNode(funcFParamNodes, commas);
    }

    FuncFParamNode FuncFParam(){
        // FuncFParam → BType Ident ['[' ']']
        BTypeNode bTypeNode;
        Token ident;
        Token leftBrack = null;
        Token rightBrack = null;

        bTypeNode = BType();
        ident = match(tokens.get(index), TokenType.IDENFR);
        if(tokens.get(index).getType() == TokenType.LBRACK){
            leftBrack = match(tokens.get(index), TokenType.LBRACK);
            rightBrack = match(tokens.get(index), TokenType.RBRACK);
        }
        return new FuncFParamNode(bTypeNode, ident, leftBrack, rightBrack);
    }

    BlockNode Block(){
        // Block → '{' { BlockItem } '}'
        ArrayList<BlockItemNode> blockItemNodes = new ArrayList<BlockItemNode>();

        Token leftBrace;
        Token rightBrace;

        leftBrace = match(tokens.get(index), TokenType.LBRACE);
        while(tokens.get(index).getType() != TokenType.RBRACE){
            blockItemNodes.add(BlockItem());
        }
        rightBrace = match(tokens.get(index), TokenType.RBRACE);
        return new BlockNode(blockItemNodes, leftBrace, rightBrace);
    }

    BlockItemNode BlockItem(){
        //BlockItem → Decl | Stmt
        DeclNode declNode = null;
        StmtNode stmtNode = null;

        if(tokens.get(index).getType() == TokenType.CONSTTK
                || tokens.get(index).getType() == TokenType.INTTK
                || tokens.get(index).getType() == TokenType.CHARTK){
            declNode = Decl();
        }else {
            stmtNode = Stmt();
        }
        return new BlockItemNode(declNode, stmtNode);
    }

    StmtNode Stmt(){
    /* Stmt → LVal '=' Exp ';'
    | [Exp] ';'
    | Block
    | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
    | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    | 'break' ';' | 'continue' ';'
    | 'return' [Exp] ';' // 1.有Exp 2.无Exp
    | LVal '=' 'getint''('')'';'
    | LVal '=' 'getchar''('')'';'
    | 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
    */
        LValNode lValNode;
        ArrayList<ExpNode> expNodes = new ArrayList<ExpNode>();
        BlockNode blockNode;
        Token ifToken;
        CondNode condNode = null;
        ArrayList<StmtNode> stmtNodes = new ArrayList<StmtNode>();
        Token forToken;
        ForStmtNode forStmtNode_1 = null;
        ForStmtNode forStmtNode_3 = null;
        Token breakToken;
        Token continueToken;
        Token returnToken;
        Token getIntToken;
        Token getCharToken;
        Token printfToken;
        Token stringConstToken;

        ExpNode expNode = null;
        Token eqToken;
        Token leftParent;
        Token rightParent;
        Token semicn;
        Token commaToken;
        Token elseToken = null;
        ArrayList<Token> semicns = new ArrayList<Token>();
        ArrayList<Token> commas = new ArrayList<Token>();

        switch (tokens.get(index).getType()){
            case LBRACE:
                //Block
                blockNode = Block();
                return new StmtNode(blockNode);
            case IFTK:
                // 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
                ifToken = match(tokens.get(index), TokenType.IFTK);
                leftParent = match(tokens.get(index), TokenType.LPARENT);
                condNode = Cond();
                rightParent = match(tokens.get(index), TokenType.RPARENT);
                stmtNodes.add(Stmt());
                if(tokens.get(index).getType() == TokenType.ELSETK){
                    elseToken = match(tokens.get(index), TokenType.ELSETK);
                    stmtNodes.add(Stmt());
                }
                return new StmtNode(ifToken, condNode, stmtNodes, leftParent, rightParent, elseToken);
            case FORTK:
                // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                forToken = match(tokens.get(index), TokenType.FORTK);
                leftParent = match(tokens.get(index), TokenType.LPARENT);
                if(tokens.get(index).getType() != TokenType.SEMICN){
                    forStmtNode_1 = ForStmt();
                }
                semicns.add(match(tokens.get(index), TokenType.SEMICN));
                if(tokens.get(index).getType() != TokenType.SEMICN){
                    condNode = Cond();
                }
                semicns.add(match(tokens.get(index), TokenType.SEMICN));
                if(tokens.get(index).getType() != TokenType.RPARENT){
                    forStmtNode_3 = ForStmt();
                }
                rightParent = match(tokens.get(index), TokenType.RPARENT);
                stmtNodes.add(Stmt());
                return new StmtNode(forToken, forStmtNode_1, forStmtNode_3, condNode, stmtNodes, leftParent, rightParent, semicns);
            case BREAKTK:
                // 'break' ';'
                breakToken = match(tokens.get(index), TokenType.BREAKTK);
                semicn = match(tokens.get(index), TokenType.SEMICN);
                return new StmtNode(breakToken, semicn);
            case CONTINUETK:
                // 'continue' ';'
                continueToken = match(tokens.get(index), TokenType.CONTINUETK);
                semicn = match(tokens.get(index), TokenType.SEMICN);
                return new StmtNode(continueToken, semicn);
            case RETURNTK:
                //'return' [Exp] ';'
                returnToken = match(tokens.get(index), TokenType.RETURNTK);
                if(tokens.get(index).getType() != TokenType.SEMICN){
                    expNode = Exp();
                }
                semicn = match(tokens.get(index), TokenType.SEMICN);
                return new StmtNode(returnToken, expNode, semicn);
            case PRINTFTK:
                // 'printf''('StringConst {','Exp} ')' ';'
                printfToken = match(tokens.get(index), TokenType.PRINTFTK);
                leftParent = match(tokens.get(index), TokenType.LPARENT);
                stringConstToken = match(tokens.get(index), TokenType.STRCON);
                while(tokens.get(index).getType() == TokenType.COMMA){
                    commas.add(match(tokens.get(index), TokenType.COMMA));
                    expNodes.add(Exp());
                }
                rightParent = match(tokens.get(index), TokenType.RPARENT);
                semicn = match(tokens.get(index), TokenType.SEMICN);
                return new StmtNode(printfToken, stringConstToken, expNodes, leftParent, rightParent, commas, semicn);
            default:
                int eq = index;
                for (int i = index; i < tokens.size() && tokens.get(i).getLine() == tokens.get(index).getLine(); i++) {
                    if (tokens.get(i).getType() == TokenType.ASSIGN) {
                        eq = i;
                    }
                }

                if(eq > index){
                    //LVal '=' Exp ';' || LVal '=' 'getint''('')' ';' ||  LVal '=' 'getchar''('')'';'
                    lValNode = LVal();
                    eqToken = match(tokens.get(index), TokenType.ASSIGN);
                    if(tokens.get(index).getType() == TokenType.GETINTTK){
                        //LVal '=' 'getint''('')' ';'
                        getIntToken = match(tokens.get(index), TokenType.GETINTTK);
                        leftParent = match(tokens.get(index), TokenType.LPARENT);
                        rightParent = match(tokens.get(index), TokenType.RPARENT);
                        semicn = match(tokens.get(index), TokenType.SEMICN);
                        return new StmtNode(getIntToken, lValNode, eqToken, leftParent, rightParent, semicn);
                    }
                    else if(tokens.get(index).getType() == TokenType.GETCHARTK){
                        //LVal '=' 'getchar''('')'';
                        getCharToken = match(tokens.get(index), TokenType.GETCHARTK);
                        leftParent = match(tokens.get(index), TokenType.LPARENT);
                        rightParent = match(tokens.get(index), TokenType.RPARENT);
                        semicn = match(tokens.get(index), TokenType.SEMICN);
                        return new StmtNode(getCharToken, lValNode, eqToken, leftParent, rightParent, semicn);
                    }
                    else {
                        //LVal '=' Exp ';'
                        expNode = Exp();
                        semicn = match(tokens.get(index), TokenType.SEMICN);
                        return new StmtNode(lValNode, expNode, eqToken, semicn);
                    }
                }else {
                    // [Exp] ';'
                    if(tokens.get(index).getType() != TokenType.SEMICN){
                        expNode = Exp();
                    }
                    semicn = match(tokens.get(index), TokenType.SEMICN);
                    return new StmtNode(expNode, semicn);
                }
        }

    }

    ForStmtNode ForStmt(){
        // ForStmt → LVal '=' Exp
        LValNode lValNode;
        ExpNode expNode;

        Token eqToken;

        lValNode = LVal();
        eqToken = match(tokens.get(index), TokenType.ASSIGN);
        expNode = Exp();
        return new ForStmtNode(lValNode, expNode, eqToken);
    }

    ExpNode Exp(){
        // Exp → AddExp
        AddExpNode addExpNode;
        addExpNode = AddExp();
        return new ExpNode(addExpNode);
    }

    CondNode Cond(){
        // Cond → LOrExp
        LOrExpNode lOrExpNode;
        lOrExpNode = LOrExp();
        return new CondNode(lOrExpNode);
    }

    LValNode LVal(){
        // LVal → Ident ['[' Exp ']']
        Token ident;
        ExpNode expNode = null;

        Token leftBrack = null;
        Token rightBrack = null;

        ident = match(tokens.get(index), TokenType.IDENFR);
        if(tokens.get(index).getType() == TokenType.LBRACK){
            leftBrack = match(tokens.get(index), TokenType.LBRACK);
            expNode = Exp();
            rightBrack = match(tokens.get(index), TokenType.RBRACK);
        }
        return new LValNode(ident, expNode, leftBrack, rightBrack);
    }

    PrimaryExpNode PrimaryExp(){
        //PrimaryExp → '(' Exp ')' | LVal | Number | Character
        enum PriExpType{
            Exp,
            LVal,
            Number,
            Character
        }
        PriExpType type;
        ExpNode expNode;
        LValNode lValNode;
        NumberNode numberNode;
        CharacterNode characterNode;

        Token leftParent;
        Token rightParent;

        if(tokens.get(index).getType() == TokenType.LPARENT){
            //'(' Exp ')'
            leftParent = match(tokens.get(index), TokenType.LPARENT);
            expNode = Exp();
            rightParent = match(tokens.get(index), TokenType.RPARENT);
            return new PrimaryExpNode(expNode, leftParent, rightParent);
        }
        else if(tokens.get(index).getType() == TokenType.INTCON){
            //Number
            numberNode = Number();
            return new PrimaryExpNode(numberNode);
        }
        else if(tokens.get(index).getType() == TokenType.CHRCON){
            //Character
            characterNode = Character();
            return new PrimaryExpNode(characterNode);
        }
        else {
            //LVal
            lValNode = LVal();
            return new PrimaryExpNode(lValNode);
        }
    }

    NumberNode Number(){
        //Number → IntConst
        Token intCon;
        intCon = match(tokens.get(index), TokenType.INTCON);
        return new NumberNode(intCon);
    }

    CharacterNode Character(){
        // Character → CharConst
        Token charCon;
        charCon = match(tokens.get(index), TokenType.CHRCON);
        return new CharacterNode(charCon);
    }

    UnaryExpNode UnaryExp(){
        //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        enum UnaryExpType{
            PriExp,
            Ident,
            Op
        }
        PrimaryExpNode priExpNode;
        Token ident;
        FuncRParamsNode funcRParamsNode = null;
        UnaryOpNode unaryOpNode;
        UnaryExpNode unaryExpNode;
        UnaryExpType type;

        Token leftParent;
        Token rightParent;

        if(tokens.get(index).getType() == TokenType.PLUS
                ||tokens.get(index).getType() == TokenType.MINU
                ||tokens.get(index).getType() == TokenType.NOT){
            //UnaryOp UnaryExp
            unaryOpNode = UnaryOp();
            unaryExpNode = UnaryExp();
            return new UnaryExpNode(unaryOpNode, unaryExpNode);
        }
        else if(tokens.get(index).getType() == TokenType.IDENFR
                &&tokens.get(index+1).getType() == TokenType.LPARENT){
            //Ident '(' [FuncRParams] ')'
            ident = match(tokens.get(index), TokenType.IDENFR);
            leftParent = match(tokens.get(index), TokenType.LPARENT);
            if(tokens.get(index).getType() != TokenType.RPARENT){
                funcRParamsNode = FuncRParams();
            }
            rightParent = match(tokens.get(index), TokenType.RPARENT);
            return new UnaryExpNode(ident, funcRParamsNode, leftParent, rightParent);
        }
        else {
            //PrimaryExp
            priExpNode = PrimaryExp();
            return new UnaryExpNode(priExpNode);
        }
    }

    UnaryOpNode UnaryOp(){
        // UnaryOp → '+' | '−' | '!'
        Token op;
        op = match(tokens.get(index), new TokenType[]{TokenType.PLUS, TokenType.MINU, TokenType.NOT});
        return new UnaryOpNode(op);
    }

    FuncRParamsNode FuncRParams(){
        // FuncRParams → Exp { ',' Exp }

        ArrayList<Token> commas = new ArrayList<Token>();

        ArrayList<ExpNode> expNodes = new ArrayList<ExpNode>();
        expNodes.add(Exp());
        while(tokens.get(index).getType() == TokenType.COMMA){
            commas.add(match(tokens.get(index), TokenType.COMMA));
            expNodes.add(Exp());
        }
        return new FuncRParamsNode(expNodes, commas);
    }

    MulExpNode MulExp(){
        //MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        //MulExp -> UnaryExp { ('*' | '/' | '%') UnaryExp }
        //MulExp -> UnaryExp | UnaryExp ('*' | '/' | '%') MulExp


//        ArrayList<UnaryExpNode> unaryExpNodes = new ArrayList<UnaryExpNode>();
//        ArrayList<Token> ops = new ArrayList<Token>();
//
//        Token op;
//
//        unaryExpNodes.add(UnaryExp());
//        while(tokens.get(index).getType() == TokenType.MULT
//                ||tokens.get(index).getType() == TokenType.DIV
//                ||tokens.get(index).getType() == TokenType.MOD){
//            op = match(tokens.get(index), new TokenType[]{TokenType.MULT, TokenType.DIV, TokenType.MOD});
//            ops.add(op);
//            unaryExpNodes.add(UnaryExp());
//        }
//        output(NodeType.MulExp);
//        return new MulExpNode(unaryExpNodes, ops);

        UnaryExpNode unaryExpNode;
        Token op = null;
        MulExpNode mulExpNode = null;

        unaryExpNode = UnaryExp();
        if(tokens.get(index).getType() == TokenType.MULT){
            op = match(tokens.get(index), TokenType.MULT);
            mulExpNode = MulExp();
        }else if(tokens.get(index).getType() == TokenType.DIV){
            op = match(tokens.get(index), TokenType.DIV);
            mulExpNode = MulExp();
        }else if(tokens.get(index).getType() == TokenType.MOD){
            op = match(tokens.get(index), TokenType.MOD);
            mulExpNode = MulExp();
        }
        return new MulExpNode(unaryExpNode, op, mulExpNode);
    }

    AddExpNode AddExp(){
        //AddExp → MulExp | AddExp ('+' | '−') MulExp
        //AddExp -> MulExp{ ('+' | '−') MulExp }
        //AddExp -> MulExp | MulExp ('+' | '−') AddExp
//        ArrayList<MulExpNode> mulExpNodes = new ArrayList<MulExpNode>();
//        ArrayList<Token> ops = new ArrayList<Token>();
//
//        Token op;
//
//        mulExpNodes.add(MulExp());
//        while(tokens.get(index).getType() == TokenType.PLUS
//                ||tokens.get(index).getType() == TokenType.MINU){
//            op = match(tokens.get(index), new TokenType[]{TokenType.PLUS, TokenType.MINU});
//            ops.add(op);
//            mulExpNodes.add(MulExp());
//        }
//        output(NodeType.AddExp);
//        return new AddExpNode(mulExpNodes, ops);
        MulExpNode mulExpNode;
        Token op = null;
        AddExpNode addExpNode = null;

        mulExpNode = MulExp();
        if(tokens.get(index).getType() == TokenType.PLUS){
            op = match(tokens.get(index), TokenType.PLUS);
            addExpNode = AddExp();
        }else if(tokens.get(index).getType() == TokenType.MINU){
            op = match(tokens.get(index), TokenType.MINU);
            addExpNode = AddExp();
        }
        return new AddExpNode(mulExpNode, op, addExpNode);
    }

    RelExpNode RelExp(){
        // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        // RelExp -> AddExp { ('<' | '>' | '<=' | '>=') AddExp }
        // RelExp -> AddExp | AddExp ('<' | '>' | '<=' | '>=') RelExp

//        ArrayList<AddExpNode> addExpNodes = new ArrayList<AddExpNode>();
//        ArrayList<Token> ops = new ArrayList<Token>();
//
//        Token op;
//
//        addExpNodes.add(AddExp());
//        while(tokens.get(index).getType() == TokenType.LSS
//                ||tokens.get(index).getType() == TokenType.GRE
//                ||tokens.get(index).getType() == TokenType.LEQ
//                ||tokens.get(index).getType() == TokenType.GEQ){
//            op = match(tokens.get(index), new TokenType[]{TokenType.LSS, TokenType.LEQ, TokenType.GRE, TokenType.GEQ});
//            ops.add(op);
//            addExpNodes.add(AddExp());
//        }
//        output(NodeType.RelExp);
//        return new RelExpNode(addExpNodes, ops);

        AddExpNode addExpNode;
        Token op = null;
        RelExpNode relExpNode = null;

        addExpNode = AddExp();
        if(tokens.get(index).getType() == TokenType.LSS){
            op = match(tokens.get(index), TokenType.LSS);
            relExpNode = RelExp();
        }else if(tokens.get(index).getType() == TokenType.GRE){
            op = match(tokens.get(index), TokenType.GRE);
            relExpNode = RelExp();
        }else if(tokens.get(index).getType() == TokenType.LEQ){
            op = match(tokens.get(index), TokenType.LEQ);
            relExpNode = RelExp();
        }else if(tokens.get(index).getType() == TokenType.GEQ){
            op = match(tokens.get(index), TokenType.GEQ);
            relExpNode = RelExp();
        }
        return new RelExpNode(addExpNode, op, relExpNode);
    }

    EqExpNode EqExp(){
        // EqExp → RelExp | EqExp ('==' | '!=') RelExp
        // EqExp -> RelExp { ('==' | '!=') RelExp }
        // EqExp -> RelExp | RelExp ('==' | '!=') EqExp
//        ArrayList<RelExpNode> relExpNodes = new ArrayList<RelExpNode>();
//        ArrayList<Token> ops = new ArrayList<Token>();
//
//        Token op;
//
//        relExpNodes.add(RelExp());
//        while(tokens.get(index).getType() == TokenType.EQL
//                ||tokens.get(index).getType() == TokenType.NEQ){
//            op = match(tokens.get(index), new TokenType[]{TokenType.EQL, TokenType.NEQ});
//            ops.add(op);
//            relExpNodes.add(RelExp());
//        }
//        output(NodeType.EqExp);
//        return new EqExpNode(relExpNodes, ops);

        RelExpNode relExpNode;
        Token op = null;
        EqExpNode eqExpNode = null;

        relExpNode = RelExp();
        if(tokens.get(index).getType() == TokenType.EQL){
            op = match(tokens.get(index), TokenType.EQL);
            eqExpNode = EqExp();
        }else if(tokens.get(index).getType() == TokenType.NEQ){
            op = match(tokens.get(index), TokenType.NEQ);
            eqExpNode = EqExp();
        }
        return new EqExpNode(relExpNode, op, eqExpNode);
    }

    LAndExpNode LAndExp(){
        // LAndExp → EqExp | LAndExp '&&' EqExp
        // LAndExp -> EqExp { '&&' EqExp }
        // LAndExp -> EqExp | EqExp '&&' LAndExp
//        ArrayList<EqExpNode> eqExpNodes = new ArrayList<EqExpNode>();
//        ArrayList<Token> andTokens = new ArrayList<Token>();
//
//        Token op;
//
//        eqExpNodes.add(EqExp());
//        while(tokens.get(index).getType() == TokenType.AND){
//            op = match(tokens.get(index), TokenType.AND);
//            andTokens.add(op);
//            eqExpNodes.add(EqExp());
//        }
//        output(NodeType.LAndExp);
//        return new LAndExpNode(eqExpNodes, andTokens);

        EqExpNode eqExpNode;
        Token op = null;
        LAndExpNode lAndExpNode = null;

        eqExpNode = EqExp();
        if(tokens.get(index).getType() == TokenType.AND){
            op = match(tokens.get(index), TokenType.AND);
            lAndExpNode = LAndExp();
        }
        return new LAndExpNode(eqExpNode, op, lAndExpNode);
    }

    LOrExpNode LOrExp(){
        // LOrExp → LAndExp | LOrExp '||' LAndExp
        // LOrExp -> LAndExp { '||' LAndExp }
        // LOrExp -> LAndExp | LAndExp '||' LOrExp
//        ArrayList<LAndExpNode> lAndExpNodes = new ArrayList<LAndExpNode>();
//        ArrayList<Token> orTokens = new ArrayList<Token>();
//
//        Token op;
//
//        lAndExpNodes.add(LAndExp());
//        while(tokens.get(index).getType() == TokenType.OR){
//            op = match(tokens.get(index), TokenType.OR);
//            orTokens.add(op);
//            lAndExpNodes.add(LAndExp());
//        }
//        output(NodeType.LOrExp);
//        return new LOrExpNode(lAndExpNodes, orTokens);

        LAndExpNode lAndExpNode;
        Token op = null;
        LOrExpNode lOrExpNode = null;

        lAndExpNode = LAndExp();
        if(tokens.get(index).getType() == TokenType.OR){
            op = match(tokens.get(index), TokenType.OR);
            lOrExpNode = LOrExp();
        }
        return new LOrExpNode(lAndExpNode, op, lOrExpNode);
    }

    ConstExpNode ConstExp(){
        //ConstExp → AddExp
        AddExpNode addExpNode;
        addExpNode = AddExp();
        return new ConstExpNode(addExpNode);
    }

    private void getsym(){
        if(this.index < this.tokenlen-1){
            index++;
        }
    }

    private void startPrint(){
        this.compUnitNode.print();
    }
}

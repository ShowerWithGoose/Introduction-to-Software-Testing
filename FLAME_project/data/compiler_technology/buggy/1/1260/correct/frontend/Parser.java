package frontend;

import frontend.node.*;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Parser {
    private Token currentToken;
    private Lexer lexer;
    private int pos = 0;
    private CompUnitNode compUnitNode;
    public Parser(Lexer lexer) {
        this.lexer = lexer;
        this.currentToken = lexer.tokenList.get(pos);
    }
    private Token match(Token.LexType tokenType) {
        if (currentToken.getType() == tokenType) {
            Token tmp = currentToken;
            if (pos < lexer.tokenList.size() - 1) {
                currentToken = lexer.tokenList.get(++pos);
            }
            return tmp;
        } else if (tokenType == Token.LexType.SEMICN) {
            Error.addError(new Error(lexer.tokenList.get(pos-1).lineNum, Error.ErrorType.i));
            return new Token(Token.LexType.SEMICN, new StringBuilder(";"), lexer.tokenList.get(pos - 1).lineNum);
        } else if (tokenType == Token.LexType.RPARENT) {
            Error.addError(new Error(lexer.tokenList.get(pos-1).lineNum, Error.ErrorType.j));
            return new Token(Token.LexType.RPARENT, new StringBuilder(")"), lexer.tokenList.get(pos - 1).lineNum);
        } else if (tokenType == Token.LexType.RBRACK) {
            Error.addError(new Error(lexer.tokenList.get(pos-1).lineNum, Error.ErrorType.k));
            return new Token(Token.LexType.RBRACK, new StringBuilder("]"), lexer.tokenList.get(pos - 1).lineNum);
        } else {
            throw new RuntimeException("Syntax error at line " + currentToken.lineNum + ": " + currentToken.getContent() + " is not " + tokenType);
        }
    }
    public void parse(){
        compUnitNode = CompUnit();
    }
    public void print() {
        compUnitNode.print();
    }

    // CompUnit -> {Decl} {FuncDef} MainFuncDef
    private CompUnitNode CompUnit() {
        List<DeclNode> declNodes = new ArrayList<>();
        List<FuncDefNode> funcDefNodes = new ArrayList<>();
        MainFuncDefNode mainFuncDefNode;
        while (lexer.tokenList.get(pos + 1).getType() != Token.LexType.MAINTK && lexer.tokenList.get(pos + 2).getType() != Token.LexType.LPARENT) {
            DeclNode declNode = Decl();
            declNodes.add(declNode);
        }
        while (lexer.tokenList.get(pos + 1).getType() != Token.LexType.MAINTK) {
            FuncDefNode funcDefNode = FuncDef();
            funcDefNodes.add(funcDefNode);
        }
        mainFuncDefNode = MainFuncDef();
        return new CompUnitNode(declNodes, funcDefNodes, mainFuncDefNode);
    }

    private DeclNode Decl() {
        ConstDeclNode constDeclNode = null;
        VarDeclNode varDeclNode = null;
        if(currentToken.getType() == Token.LexType.CONSTTK){
            constDeclNode = ConstDecl();
        }else {
            varDeclNode = VarDecl();
        }
        return new DeclNode(constDeclNode, varDeclNode);
    }

    private ConstDeclNode ConstDecl() {
        Token constToken = match(Token.LexType.CONSTTK);
        BTypeNode bTypeNode = BType();
        List<ConstDefNode> constDefNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token semicnToken;
        constDefNodes.add(ConstDef());
        while (currentToken.getType() == Token.LexType.COMMA) {
            commas.add(match(Token.LexType.COMMA));
            constDefNodes.add(ConstDef());
        }
        semicnToken = match(Token.LexType.SEMICN);
        return new ConstDeclNode(constToken, bTypeNode, constDefNodes, commas, semicnToken);
    }
    // MainFuncDef -> 'int' 'main' '(' ')' Block
    private MainFuncDefNode MainFuncDef() {
        Token intToken = match(Token.LexType.INTTK);
        Token mainToken = match(Token.LexType.MAINTK);
        Token leftParentToken = match(Token.LexType.LPARENT);
        Token rightParentToken = match(Token.LexType.RPARENT);
        BlockNode blockNode = Block();
        return new MainFuncDefNode(intToken, mainToken, leftParentToken, rightParentToken, blockNode);
    }
    private BTypeNode BType() {
        if(currentToken.getType() == Token.LexType.INTTK){
            Token intToken = match(Token.LexType.INTTK);
            return new BTypeNode(intToken);
        }else{
            Token charToken = match(Token.LexType.CHARTK);
            return new BTypeNode(charToken);
        }

    }
    private ConstDefNode ConstDef() {
        Token ident = match(Token.LexType.IDENFR);
        Token lbrackToken = null;
        ConstExpNode constExpNode = null;
        Token rbrackToken = null;
        if(currentToken.getType() == Token.LexType.LBRACK){
            lbrackToken = match(Token.LexType.LBRACK);
            constExpNode = ConstExp();
            rbrackToken = match(Token.LexType.RBRACK);
        }
        Token equalToken = match(Token.LexType.ASSIGN);
        ConstInitValNode constInitValNode = ConstInitVal();
        return new ConstDefNode(ident, lbrackToken, constExpNode, rbrackToken, equalToken, constInitValNode);
    }

    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ConstInitValNode ConstInitVal() {
        ConstExpNode constExpNode = null;
        Token lBraceToken = null;
        Token rBraceToken = null;
        List<ConstExpNode> constExpNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token strconToken = null;
        if(currentToken.getType() == Token.LexType.LBRACE){
            lBraceToken = match(Token.LexType.LBRACE);
            if(currentToken.getType() != Token.LexType.RBRACE){
                constExpNodes.add(ConstExp());
                while (currentToken.getType() != Token.LexType.RBRACE) {
                    commas.add(match(Token.LexType.COMMA));
                    constExpNodes.add(ConstExp());
                }
            }
            rBraceToken = match(Token.LexType.RBRACE);
            
        }else if(currentToken.getType() == Token.LexType.STRCON){
            strconToken = match(Token.LexType.STRCON);
        }else{
            constExpNode = ConstExp();
        }
        return new ConstInitValNode(constExpNode, lBraceToken, constExpNodes, commas, rBraceToken, strconToken);
    }

    private VarDeclNode VarDecl() {
        BTypeNode bTypeNode = BType();
        List<Token> commas = new ArrayList<>();
        List<VarDefNode> varDefNodes = new ArrayList<>();
        Token semicnToken;
        varDefNodes.add(VarDef());
        while(currentToken.getType() == Token.LexType.COMMA){
            commas.add(match(Token.LexType.COMMA));
            varDefNodes.add(VarDef());
        }
        semicnToken = match(Token.LexType.SEMICN);
        return new VarDeclNode(bTypeNode, commas, varDefNodes, semicnToken);
    }

    // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
    private VarDefNode VarDef() {
        Token ident = match(Token.LexType.IDENFR);
        Token lbrackToken = null;
        ConstExpNode constExpNode = null;
        Token rbrackToken = null;
        Token equalToken = null;
        InitValNode initValNode = null;
        if(currentToken.getType() == Token.LexType.LBRACK){
            lbrackToken = match(Token.LexType.LBRACK);
            constExpNode = ConstExp();
            rbrackToken = match(Token.LexType.RBRACK);
        }
        if(currentToken.getType() == Token.LexType.ASSIGN){
            equalToken = match(Token.LexType.ASSIGN);
            initValNode = InitVal();
        }
        return new VarDefNode(ident, lbrackToken, constExpNode, rbrackToken, equalToken, initValNode);
    }

    private InitValNode InitVal() {
        Token strConToken = null;
        ExpNode expNode = null;
        List<ExpNode> expNodes = new ArrayList<>();
        Token lBrace = null;
        Token rBrace = null;
        List<Token> commas = new ArrayList<>();
        if(currentToken.getType() == Token.LexType.STRCON){
            strConToken = match(Token.LexType.STRCON);
        }else if(currentToken.getType() == Token.LexType.LBRACE){
            lBrace = match(Token.LexType.LBRACE);
            if(currentToken.getType() != Token.LexType.RBRACE){
                expNodes.add(Exp());
                while(currentToken.getType() != Token.LexType.RBRACE){
                    commas.add(match(Token.LexType.COMMA));
                    expNodes.add(Exp());
                }
            }
            rBrace = match(Token.LexType.RBRACE);
        }else{
            expNode = Exp();
        }
        return new InitValNode(expNode, lBrace, expNodes, rBrace, commas, strConToken);
    }

    //FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
    private FuncDefNode FuncDef(){
        FuncTypeNode funcTypeNode = FuncType();
        Token Ident = match(Token.LexType.IDENFR);
        Token lParentToken = match(Token.LexType.LPARENT);
        FuncFParamsNode funcFParamsNode = null;
        if(currentToken.getType() == Token.LexType.INTTK || currentToken.getType() == Token.LexType.CHARTK) {
            funcFParamsNode = FuncFParams();
        }
        Token rParentToken = match(Token.LexType.RPARENT);
        BlockNode blockNode = Block();
        return new FuncDefNode(funcTypeNode, Ident, lParentToken, funcFParamsNode, rParentToken, blockNode);
    }

    // FuncType → 'void' | 'int' | 'char'
    private FuncTypeNode FuncType() {
        if (currentToken.getType() == Token.LexType.VOIDTK) {
            Token voidToken = match(Token.LexType.VOIDTK);
            return new FuncTypeNode(voidToken);
        } else if(currentToken.getType() == Token.LexType.INTTK){
            Token intToken = match(Token.LexType.INTTK);
            return new FuncTypeNode(intToken);
        } else{
            Token charToken = match(Token.LexType.CHARTK);
            return new FuncTypeNode(charToken);
        }
    }

    //FuncFParams → FuncFParam { ',' FuncFParam }
    private FuncFParamsNode FuncFParams() {
        List <Token> commas = new ArrayList<>();
        List<FuncFParamNode> funcFParamNodes = new ArrayList<>();
        funcFParamNodes.add(FuncFParam());
        while(currentToken.getType() == Token.LexType.COMMA){
            commas.add(match(Token.LexType.COMMA));
            funcFParamNodes.add(FuncFParam());
        }
        return new FuncFParamsNode(commas, funcFParamNodes);
    }

    //FuncFParam → BType Ident ['[' ']'] // k
    private FuncFParamNode FuncFParam() {
        BTypeNode bTypeNode = BType();
        Token ident = match(Token.LexType.IDENFR);
        Token lBrack = null;
        Token rBrack = null;
        if(currentToken.getType() == Token.LexType.LBRACK){
            lBrack = match(Token.LexType.LBRACK);
            rBrack = match(Token.LexType.RBRACK);
        }
        return new FuncFParamNode(bTypeNode, ident, lBrack, rBrack);
    }

    private BlockNode Block() {
        Token lBrace = match(Token.LexType.LBRACE);
        List <BlockItemNode> blockItemNodes = new ArrayList<>();
        while(currentToken.getType() != Token.LexType.RBRACE){
            blockItemNodes.add(BlockItem());
        }
        Token rBrace = match(Token.LexType.RBRACE);
        return new BlockNode(lBrace, blockItemNodes, rBrace);
    }

    private BlockItemNode BlockItem() {
        DeclNode declNode = null;
        StmtNode stmtNode = null;
        if(currentToken.getType() == Token.LexType.CONSTTK || currentToken.getType() == Token.LexType.INTTK || currentToken.getType() == Token.LexType.CHARTK){
            declNode = Decl();
        } else {
            stmtNode = Stmt();
        }
        return new BlockItemNode(declNode, stmtNode);
    }

    // 语句 Stmt → LVal '=' Exp ';' // i
    // | [Exp] ';' // i
    // | Block
    // | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
    // | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    // | 'break' ';' | 'continue' ';' // i
    // | 'return' [Exp] ';' // i
    // | LVal '=' 'getint''('')'';' // i j
    // | LVal '=' 'getchar''('')'';' // i j
    // | 'printf''('StringConst {','Exp}')'';' // i j
    private StmtNode Stmt() {

        if(currentToken.getType() == Token.LexType.LBRACE){
            BlockNode blockNode = Block();
            return new StmtNode(blockNode, StmtNode.StmtCategory.Block);
        } else if(currentToken.getType() == Token.LexType.IFTK){
            Token ifToken = match(Token.LexType.IFTK);
            Token lParent = match(Token.LexType.LPARENT);
            CondNode condNode = Cond();
            Token rParent = match(Token.LexType.RPARENT);
            StmtNode stmtNode = Stmt();
            Token elseToken = null;
            StmtNode stmtNode1 = null;
            if(currentToken.getType() == Token.LexType.ELSETK){
                elseToken = match(Token.LexType.ELSETK);
                stmtNode1 = Stmt();
            }
            return new StmtNode(ifToken, lParent, condNode, rParent, stmtNode, elseToken, stmtNode1, StmtNode.StmtCategory.IF);
        } else if (currentToken.getType() == Token.LexType.FORTK) {
            Token forToken = match(Token.LexType.FORTK);
            Token lParent = match(Token.LexType.LPARENT);
            ForStmtNode forStmtNode = null;
            if(currentToken.getType() == Token.LexType.IDENFR){
                forStmtNode = ForStmt();
            }
            Token semicn = match(Token.LexType.SEMICN);
            CondNode condNode = null;
            if(isExp()){
                condNode = Cond();
            }
            Token semicn2 = match(Token.LexType.SEMICN);
            ForStmtNode forStmtNode2 = null;
            if(currentToken.getType() == Token.LexType.IDENFR){
                forStmtNode2 = ForStmt();
            }
            Token rParent = match(Token.LexType.RPARENT);
            StmtNode stmtNode = Stmt();
            return new StmtNode(forToken, lParent, forStmtNode, semicn, condNode, semicn2, forStmtNode2, rParent, stmtNode, StmtNode.StmtCategory.FOR);
        } else if (currentToken.getType() == Token.LexType.BREAKTK) {
            Token breakToken = match(Token.LexType.BREAKTK);
            Token semicn = match(Token.LexType.SEMICN);
            return new StmtNode(breakToken, semicn, StmtNode.StmtCategory.BREAK);
        } else if (currentToken.getType() == Token.LexType.CONTINUETK) {
            Token continueToken = match(Token.LexType.CONTINUETK);
            Token semicn = match(Token.LexType.SEMICN);
            return new StmtNode(continueToken, semicn, StmtNode.StmtCategory.CONTINUE);
        } else if (currentToken.getType() == Token.LexType.RETURNTK) {
            Token returnToken = match(Token.LexType.RETURNTK);
            ExpNode expNode = null;
            if(isExp()){
                expNode = Exp();
            }
            Token semicn = match(Token.LexType.SEMICN);
            return new StmtNode(returnToken, expNode, semicn, StmtNode.StmtCategory.RETURN);
        } else if (currentToken.getType() == Token.LexType.PRINTFTK) {

            Token printfToken = match(Token.LexType.PRINTFTK);
            Token lParentToken = match(Token.LexType.LPARENT);
            Token strConToken = match(Token.LexType.STRCON);
            List<Token> commas = new ArrayList<>();
            List<ExpNode> expNodes = new ArrayList<>();
            while(currentToken.getType() == Token.LexType.COMMA){
                commas.add(match(Token.LexType.COMMA));
                expNodes.add(Exp());
            }
            Token rParentToken = match(Token.LexType.RPARENT);
            Token semicn = match(Token.LexType.SEMICN);
            return new StmtNode(printfToken, lParentToken, rParentToken, strConToken, commas, expNodes, semicn, StmtNode.StmtCategory.PRINTF);
        } else {
            boolean flag = false;
            for(int i = pos+1;true;++i){
                if(lexer.tokenList.get(i).getType() == Token.LexType.ASSIGN){
                    flag = true;
                    break;
                }
                if(lexer.tokenList.get(i).lineNum != currentToken.lineNum){
                    break;
                }
            }
            if(flag){
                LValNode lValNode = LVal();
                Token equalToken = match(Token.LexType.ASSIGN);
                if(currentToken.getType() == Token.LexType.GETINTTK){
                    Token getintToken = match(Token.LexType.GETINTTK);
                    Token lParent = match(Token.LexType.LPARENT);
                    Token rParent = match(Token.LexType.RPARENT);
                    Token semicn = match(Token.LexType.SEMICN);
                    return new StmtNode(lValNode, equalToken, getintToken, lParent, rParent, semicn, StmtNode.StmtCategory.GETINT);
                } else if (currentToken.getType() == Token.LexType.GETCHARTK) {
                    Token getcharToken = match(Token.LexType.GETCHARTK);
                    Token lParent = match(Token.LexType.LPARENT);
                    Token rParent = match(Token.LexType.RPARENT);
                    Token semicn = match(Token.LexType.SEMICN);
                    return new StmtNode(lValNode, equalToken, getcharToken, lParent, rParent, semicn, StmtNode.StmtCategory.GETCHAR);
                }else{
                    ExpNode expNode = Exp();
                    Token semicn = match(Token.LexType.SEMICN);
                    return new StmtNode(lValNode, equalToken, expNode, semicn, StmtNode.StmtCategory.LVal);
                }
            } else {
                ExpNode expNode = null;
                if(isExp()){
                    expNode = Exp();
                }
                Token semicn = match(Token.LexType.SEMICN);
                return new StmtNode(expNode, semicn, StmtNode.StmtCategory.EXP);
            }
        }
    }
    private boolean isExp(){
        if (currentToken.getType() == Token.LexType.IDENFR || currentToken.getType() == Token.LexType.PLUS || currentToken.getType() == Token.LexType.MINU || currentToken.getType() == Token.LexType.NOT || currentToken.getType() == Token.LexType.LPARENT || currentToken.getType() == Token.LexType.INTCON || currentToken.getType() == Token.LexType.CHRCON) {
            return true;
        }
        return false;
    }
    private ForStmtNode ForStmt() {
        LValNode lValNode = LVal();
        Token equalToken = match(Token.LexType.ASSIGN);
        ExpNode expNode = Exp();
        return new ForStmtNode(lValNode, equalToken, expNode);
    }

    private ExpNode Exp() {
        AddExpNode addExpNode = AddExp();
        return new ExpNode(addExpNode);
    }

    private CondNode Cond() {
        LOrExpNode lOrExpNode = LOrExp();
        return new CondNode(lOrExpNode);
    }

    private LValNode LVal() {
        Token ident = match(Token.LexType.IDENFR);
        Token lBrack = null;
        Token rBrack = null;
        ExpNode expNode = null;
        if(currentToken.getType() == Token.LexType.LBRACK){
            lBrack = match(Token.LexType.LBRACK);
            expNode = Exp();
            rBrack = match(Token.LexType.RBRACK);
        }
        return new LValNode(ident, lBrack, expNode, rBrack);
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
    private PrimaryExpNode PrimaryExp() {
        Token lParent = null;
        ExpNode expNode = null;
        Token rParent = null;
        LValNode lValNode = null;
        NumberNode numberNode = null;
        CharacterNode characterNode = null;
        if(currentToken.getType() == Token.LexType.LPARENT){
            lParent = match(Token.LexType.LPARENT);
            expNode = Exp();
            rParent = match(Token.LexType.RPARENT);
        }else if(currentToken.getType() == Token.LexType.INTCON){
            numberNode = Number();
        }else if(currentToken.getType() == Token.LexType.CHRCON){
            characterNode = Character();
        }else{
            lValNode = LVal();
        }
        return new PrimaryExpNode(lParent, expNode, rParent, lValNode, numberNode, characterNode);
    }

    private NumberNode Number() {
        Token intConToken = match(Token.LexType.INTCON);
        return new NumberNode(intConToken);
    }

    private CharacterNode Character() {
        Token chrConToken = match(Token.LexType.CHRCON);
        return new CharacterNode(chrConToken);
    }

    // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
    private UnaryExpNode UnaryExp() {
        PrimaryExpNode primaryExpNode = null;
        UnaryOpNode unaryOpNode = null;
        UnaryExpNode unaryExpNode = null;
        Token ident = null;
        Token lParent = null;
        Token rParent = null;
        FuncRParamsNode funcRParamsNode = null;
        if(currentToken.getType() == Token.LexType.PLUS || currentToken.getType() == Token.LexType.MINU || currentToken.getType() == Token.LexType.NOT){
            unaryOpNode = UnaryOp();
            unaryExpNode = UnaryExp();
        }else if(currentToken.getType() == Token.LexType.IDENFR && lexer.tokenList.get(pos+1).getType() == Token.LexType.LPARENT){
            ident = match(Token.LexType.IDENFR);
            lParent = match(Token.LexType.LPARENT);
            if(isExp()){
                funcRParamsNode = FuncRParams();
            }
            rParent = match(Token.LexType.RPARENT);
        }else{
            primaryExpNode = PrimaryExp();
        }
        return new UnaryExpNode(primaryExpNode, ident, lParent, funcRParamsNode, rParent, unaryOpNode, unaryExpNode);
    }

    private UnaryOpNode UnaryOp() {
        Token op = null;
        if (currentToken.getType() == Token.LexType.PLUS) {
            op = match(Token.LexType.PLUS);
        } else if (currentToken.getType() == Token.LexType.MINU) {
            op = match(Token.LexType.MINU);
        } else if(currentToken.getType() == Token.LexType.NOT){
            op = match(Token.LexType.NOT);
        }
        return new UnaryOpNode(op);
    }

    // FuncRParams → Exp { ',' Exp }
    private FuncRParamsNode FuncRParams() {
        List<ExpNode> expNodes = new ArrayList<>();
        expNodes.add(Exp());
        List<Token> commas = new ArrayList<>();
        while(currentToken.getType() == Token.LexType.COMMA){
            commas.add(match(Token.LexType.COMMA));
            expNodes.add(Exp());
        }
        return new FuncRParamsNode(expNodes, commas);
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private MulExpNode MulExp() {
        UnaryExpNode unaryExpNode = UnaryExp();
        MulExpNode mulExpNode = null;
        Token opToken = null;
        if(currentToken.getType() == Token.LexType.MULT){
            opToken = match(Token.LexType.MULT);
            mulExpNode = MulExp();
        }else if(currentToken.getType() == Token.LexType.DIV){
            opToken = match(Token.LexType.DIV);
            mulExpNode = MulExp();
        }else if(currentToken.getType() == Token.LexType.MOD){
            opToken = match(Token.LexType.MOD);
            mulExpNode = MulExp();
        }
        return new MulExpNode(unaryExpNode, opToken, mulExpNode);
    }

    private AddExpNode AddExp() {
        MulExpNode mulExpNode = MulExp();
        Token opToken = null;
        AddExpNode addExpNode = null;
        if(currentToken.getType() == Token.LexType.PLUS){
            opToken = match(Token.LexType.PLUS);
            addExpNode = AddExp();
        }else if(currentToken.getType() == Token.LexType.MINU){
            opToken = match(Token.LexType.MINU);
            addExpNode = AddExp();
        }
        return new AddExpNode(mulExpNode, opToken, addExpNode);
    }

    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private RelExpNode RelExp() {
        AddExpNode addExpNode = AddExp();
        Token opToken = null;
        RelExpNode relExpNode = null;
        if(currentToken.getType() == Token.LexType.LSS){
            opToken = match(Token.LexType.LSS);
            relExpNode = RelExp();
        }else if(currentToken.getType() == Token.LexType.GRE){
            opToken = match(Token.LexType.GRE);
            relExpNode = RelExp();
        }else if(currentToken.getType() == Token.LexType.GEQ){
            opToken = match(Token.LexType.GEQ);
            relExpNode = RelExp();
        }else if(currentToken.getType() == Token.LexType.LEQ){
            opToken = match(Token.LexType.LEQ);
            relExpNode = RelExp();
        }
        return new RelExpNode(addExpNode, opToken, relExpNode);
    }

    // EqExp → RelExp | EqExp ('==' | '!=') RelExp
    private EqExpNode EqExp() {
        RelExpNode relExpNode = RelExp();
        Token opToken = null;
        EqExpNode eqExpNode = null;
        if(currentToken.getType() == Token.LexType.EQL){
            opToken = match(Token.LexType.EQL);
            eqExpNode = EqExp();
        }else if(currentToken.getType() == Token.LexType.NEQ){
            opToken = match(Token.LexType.NEQ);
            eqExpNode = EqExp();
        }
        return new EqExpNode(relExpNode, opToken, eqExpNode);
    }

    // LAndExp → EqExp | LAndExp '&&' EqExp
    private LAndExpNode LAndExp() {
        EqExpNode eqExpNode = EqExp();
        Token andToken = null;
        LAndExpNode lAndExpNode = null;
        if(currentToken.getType() == Token.LexType.AND){
            andToken = match(Token.LexType.AND);
            lAndExpNode = LAndExp();
        }
        return new LAndExpNode(eqExpNode, andToken, lAndExpNode);
    }

    // LOrExp → LAndExp | LOrExp '||' LAndExp
    private LOrExpNode LOrExp() {
        LAndExpNode lAndExpNode = LAndExp();
        Token orToken = null;
        LOrExpNode lOrExpNode = null;
        if (currentToken.getType() == Token.LexType.OR) {
            orToken = match(Token.LexType.OR);
            lOrExpNode = LOrExp();
        }
        return new LOrExpNode(lAndExpNode, orToken, lOrExpNode);
    }

    private ConstExpNode ConstExp() {
        AddExpNode addExpNode = AddExp();
        return new ConstExpNode(addExpNode);
    }
}
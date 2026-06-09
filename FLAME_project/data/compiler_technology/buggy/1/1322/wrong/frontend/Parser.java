package frontend;

import ast.*; // 确保导入 AST 节点类
import enum_package.NodeType;
import enum_package.StmtType;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Parser {
    public List<Token> tokens;
    public List<MyError> myErrors;
    private int currentTokenIndex;

    boolean flag = false;

    public Parser(List<Token> tokens, List<MyError> myErrors) {
        this.tokens = tokens;
        this.currentTokenIndex = 0;
        this.myErrors = myErrors;
    }

    public CompUnitNode Parse() {

        return CompUnit();

    }

    public static Map<NodeType, String> nodeTypeLabel = new HashMap<NodeType, String>() {{
        put(NodeType.CompUnit, "<CompUnit>\n");
        put(NodeType.Decl, "<Decl>\n");
        put(NodeType.ConstDecl, "<ConstDecl>\n");
        put(NodeType.BType, "<BType>\n");
        put(NodeType.ConstDef, "<ConstDef>\n");
        put(NodeType.ConstInitVal, "<ConstInitVal>\n");
        put(NodeType.VarDecl, "<VarDecl>\n");
        put(NodeType.VarDef, "<VarDef>\n");
        put(NodeType.InitVal, "<InitVal>\n");
        put(NodeType.FuncDef, "<FuncDef>\n");
        put(NodeType.MainFuncDef, "<MainFuncDef>\n");
        put(NodeType.FuncType, "<FuncType>\n");
        put(NodeType.FuncFParams, "<FuncFParams>\n");
        put(NodeType.FuncFParam, "<FuncFParam>\n");
        put(NodeType.Block, "<Block>\n");
        put(NodeType.BlockItem, "<BlockItem>\n");
        put(NodeType.Stmt, "<Stmt>\n");
        put(NodeType.ForStmt,"<ForStmt>\n");
        put(NodeType.Exp, "<Exp>\n");
        put(NodeType.Cond, "<Cond>\n");
        put(NodeType.LVal, "<LVal>\n");
        put(NodeType.PrimaryExp, "<PrimaryExp>\n");
        put(NodeType.Number, "<Number>\n");
        put(NodeType.Character, "<Character>\n");
        put(NodeType.UnaryExp, "<UnaryExp>\n");
        put(NodeType.UnaryOp, "<UnaryOp>\n");
        put(NodeType.FuncRParams, "<FuncRParams>\n");
        put(NodeType.MulExp, "<MulExp>\n");
        put(NodeType.AddExp, "<AddExp>\n");
        put(NodeType.RelExp, "<RelExp>\n");
        put(NodeType.EqExp, "<EqExp>\n");
        put(NodeType.LAndExp, "<LAndExp>\n");
        put(NodeType.LOrExp, "<LOrExp>\n");
        put(NodeType.ConstExp, "<ConstExp>\n");
    }};

    // CompUnit -> {Decl} {FuncDef} MainFuncDef
    private CompUnitNode CompUnit()   {
        List<DeclNode> declNodes = new ArrayList<>();
        List<FuncDefNode> funcDefNodes = new ArrayList<>();
        MainFuncDefNode mainFuncDefNode = null;
        int count = 0;

        while(tokens.get(currentTokenIndex + 2).getLexType() != LexType.LPARENT) {
            DeclNode declNode = Decl();
            declNodes.add(declNode);
        }
        while (tokens.get(currentTokenIndex + 1).getLexType() != LexType.MAINTK) {
            // break;
            funcDefNodes.add(FuncDef());
            count ++ ;
            if (count == 9) {
                break;
            }
        }
        for(int i = currentTokenIndex; i < tokens.size(); ++i) {
            if (tokens.get(i).getLexType() == LexType.INTTK && tokens.get(i+1).getLexType() == LexType.MAINTK) {
                currentTokenIndex = i;
                break;
            }
        }
        mainFuncDefNode = MainFuncDef();

        return new CompUnitNode(declNodes,funcDefNodes,mainFuncDefNode); // 返回构建的编译单元节点
    }

    // Decl -> ConstDecl | VarDecl
    private DeclNode Decl()   {
        ConstDeclNode constDeclNode = null;
        VarDeclNode varDeclNode = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.CONSTTK) {
            constDeclNode = ConstDecl();
        } else {
            varDeclNode = VarDecl();
        }

        return new DeclNode(constDeclNode, varDeclNode);
    }

    // ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
    // i
    private ConstDeclNode ConstDecl()   {
        Token consttk = null;
        BTypeNode bTypeNode = null;
        List<ConstDefNode> constDeclNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token semicn = null;

        consttk = match(LexType.CONSTTK);
        bTypeNode = BType();
        constDeclNodes.add(ConstDef());
        while(tokens.get(currentTokenIndex).getLexType() == LexType.COMMA) {
            commas.add(match(LexType.COMMA));
            constDeclNodes.add(ConstDef());
        }
        semicn = match(LexType.SEMICN);

        return new ConstDeclNode(consttk, bTypeNode, constDeclNodes, commas, semicn); // 返回构建的常量声明节点
    }

    // BType -> 'int' | 'char'
    private BTypeNode BType() {
        Token token = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.INTTK) {
            token = match(LexType.INTTK);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.CHARTK) {
            token = match(LexType.CHARTK);
        }

        return new BTypeNode(token);
    }

    // ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    private ConstDefNode ConstDef()   {
        Token idenfr = null;
        Token lBracket = null;
        ConstExpNode constExp = null;
        Token rBracket = null;
        Token assign = null;
        ConstInitValNode constInitVal = null;

        idenfr = match(LexType.IDENFR);
        if (tokens.get(currentTokenIndex).getLexType() == LexType.LBRACK) {
            lBracket = match(LexType.LBRACK);
            constExp = ConstExp();
            rBracket = match(LexType.RBRACK);
        }
        assign = match(LexType.ASSIGN);
        constInitVal = ConstInitVal();

        return new ConstDefNode(idenfr,lBracket,constExp,rBracket,assign,constInitVal); // 返回构建的变量声明节点
    }

    // ConstInitVal -> ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ConstInitValNode ConstInitVal()   {
        ConstExpNode constExp = null;
        Token lBrace = null;
        List<ConstExpNode> constExps = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token rBrace = null;
        Token stringConst = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.LBRACE) {
            lBrace = match(LexType.LBRACE);
            if (tokens.get(currentTokenIndex).getLexType() != LexType.RBRACE) {
                constExps.add(ConstExp());
                while (tokens.get(currentTokenIndex).getLexType() == LexType.COMMA) {
                    commas.add(match(LexType.COMMA));
                    constExps.add(ConstExp());
                }
            }
            rBrace = match(LexType.RBRACE);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.STRCON){
            stringConst = match(LexType.STRCON);
        } else {
            constExp = ConstExp();
        }

        return new ConstInitValNode(constExp, lBrace, constExps, commas, rBrace, stringConst);
    }

    // VarDecl -> BType VarDef { ',' VarDef } ';'
    private VarDeclNode VarDecl()   {
        BTypeNode bTypeNode = null;
        List<VarDefNode> varDefNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token semicn = null;

        bTypeNode = BType();
        varDefNodes.add(VarDef());
        while(tokens.get(currentTokenIndex).getLexType() == LexType.COMMA) {
            commas.add(match(LexType.COMMA));
            varDefNodes.add(VarDef());
        }
        semicn = match(LexType.SEMICN);

        return new VarDeclNode(bTypeNode, varDefNodes, commas, semicn);
    }

    // VarDef -> Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    private VarDefNode VarDef()   {
        Token idenfr = null;
        Token lBracket = null;
        ConstExpNode constExp = null;
        Token rBracket = null;
        Token assign = null;
        InitValNode initVal = null;

        idenfr = match(LexType.IDENFR);
        if (tokens.get(currentTokenIndex).getLexType() == LexType.LBRACK) {
            lBracket = match(LexType.LBRACK);
            constExp = ConstExp();
            rBracket = match(LexType.RBRACK);
        }
        if (tokens.get(currentTokenIndex).getLexType() == LexType.ASSIGN) {
            assign = match(LexType.ASSIGN);
            initVal = InitVal();
        }

        return new VarDefNode(idenfr, lBracket, constExp, rBracket, assign, initVal);
    }

    // InitVal -> Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private InitValNode InitVal()   {
        ExpNode exp = null;
        Token lBrace = null;
        List<ExpNode> exps = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token rBrace = null;
        Token strcon = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.LBRACE) {
            lBrace = match(LexType.LBRACE);
            if (tokens.get(currentTokenIndex).getLexType() != LexType.RBRACE) {
                exps.add(Exp());
                while (tokens.get(currentTokenIndex).getLexType() == LexType.COMMA) {
                    commas.add(match(LexType.COMMA));
                    exps.add(Exp());
                }
            }
            rBrace = match(LexType.RBRACE);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.STRCON){
            strcon = match(LexType.STRCON);
        } else {
            exp = Exp();
        }

        return new InitValNode(exp, lBrace, exps, commas, rBrace, strcon);
    }

    // FuncDef -> FuncType Ident '(' [FuncFParams] ')'  // j
    private FuncDefNode FuncDef()   {
        FuncTypeNode funcType = null;
        Token idenfr = null;
        Token lParent = null;
        FuncFParamsNode funcFParamsNode = null;
        Token rParent = null;
        BlockNode block = null;

        funcType = FuncType();
        idenfr = match(LexType.IDENFR);
        lParent = match(LexType.LPARENT);
        if (tokens.get(currentTokenIndex).getLexType() != LexType.RPARENT &&
                tokens.get(currentTokenIndex).getLexType() != LexType.LBRACE) {
            funcFParamsNode = FuncFParams();
        }
        rParent = match(LexType.RPARENT);
        block = Block();

        return new FuncDefNode(funcType, idenfr, lParent, funcFParamsNode, rParent, block); // 返回构建的函数定义节点
    }

    // MainFuncDef → 'int' 'main' '(' ')' Block
    private MainFuncDefNode MainFuncDef()   {
        Token inttk = null;
        Token maintk = null;
        Token lParent = null;
        Token rParent = null;
        BlockNode block = null;

        inttk = match(LexType.INTTK);
        maintk = match(LexType.MAINTK);
        lParent = match(LexType.LPARENT);
        rParent = match(LexType.RPARENT);
        block = Block();

        return new MainFuncDefNode(inttk, maintk, lParent, rParent, block);
    }

    // FuncType → 'void' | 'int' | 'char'
    private FuncTypeNode FuncType() {
        Token token = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.VOIDTK) {
            token = match(LexType.VOIDTK);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.INTTK) {
            token = match(LexType.INTTK);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.CHARTK) {
            token = match(LexType.CHARTK);
        }

        return new FuncTypeNode(token);
    }

    // FuncFParams -> FuncFParam { ',' FuncFParam }
    private FuncFParamsNode FuncFParams() {
        List<FuncFParamNode> funcFParams = new ArrayList<>();
        List<Token> commas = new ArrayList<>();

        funcFParams.add(FuncFParam());
        while (tokens.get(currentTokenIndex).getLexType() == LexType.COMMA) {
            commas.add(match(LexType.COMMA));
            funcFParams.add(FuncFParam());
        }

        return new FuncFParamsNode(funcFParams, commas);
    }

    // FuncFParam -> BType Ident ['[' ']']
    private FuncFParamNode FuncFParam() {
        BTypeNode bType = null;
        Token idenfr = null;
        Token lBracket = null;
        Token rBracket = null;

        bType = BType();
        idenfr = match(LexType.IDENFR);
        if (tokens.get(currentTokenIndex).getLexType() == LexType.LBRACK) {
            lBracket = match(LexType.LBRACK);
            rBracket = match(LexType.RBRACK);
        }

        return new FuncFParamNode(bType, idenfr, lBracket, rBracket);
    }

    // Block -> '{' { BlockItem } '}'
    private BlockNode Block()   {
        Token lBrace = null;
        List<BlockItemNode> blockItems = new ArrayList<>();
        Token rBrace = null;

        lBrace = match(LexType.LBRACE);
        while (tokens.get(currentTokenIndex).getLexType() != LexType.RBRACE) {
            //优化方法？
            blockItems.add(BlockItem());
        }
        rBrace = match(LexType.RBRACE);

        return new BlockNode(lBrace, blockItems, rBrace); // 返回块节点
    }

    // BlockItem -> Decl | Stmt
    private BlockItemNode BlockItem()   {
        DeclNode decl = null;
        StmtNode stmt = null;
        if (
                tokens.get(currentTokenIndex).getLexType() == LexType.INTTK ||
                    tokens.get(currentTokenIndex).getLexType() == LexType.CHARTK ||
                        tokens.get(currentTokenIndex).getLexType() == LexType.CONSTTK) {
            decl = Decl();
        } else {
            stmt = Stmt();
        }

        return new BlockItemNode(decl, stmt);
    }

    //  Stmt → LVal '=' Exp ';' // i
    //  | [Exp] ';' // i

    ////  | Block
    ////  | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
        ////  | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    ////  | 'break' ';' | 'continue' ';' // i
    ////  | 'return' [Exp] ';' // i

    //  | LVal '=' 'getint''('')'';' // i j
    //  | LVal '=' 'getchar''('')'';' // i j

    ////  | 'printf''('StringConst {','Exp}')'';' // i j
    private StmtNode Stmt()   {
        //debug begin




        //debug end


        if (tokens.get(currentTokenIndex).getLexType() == LexType.LBRACE) {
            // Block
            BlockNode block = Block();
            return new StmtNode(StmtType.BLOCK_STMT, block);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.IFTK) {
            // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            Token iftk = match(LexType.IFTK);
            CondNode cond = null;
            StmtNode if_stmt = null;
            Token elsetk = null;
            StmtNode else_stmt = null;
            Token lParent = null;
            Token rParent = null;

            lParent = match(LexType.LPARENT);
            cond = Cond();
            rParent = match(LexType.RPARENT);
            if_stmt = Stmt();
            if (tokens.get(currentTokenIndex).getLexType() == LexType.ELSETK) {
                elsetk = match(LexType.ELSETK);
                else_stmt = Stmt();
            }

            return new StmtNode(StmtType.IF_STMT, iftk, lParent, cond, rParent, if_stmt, elsetk, else_stmt);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.FORTK) {
            // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            Token fortk = match(LexType.FORTK);
            ForStmtNode first_forStmt = null;
            Token first_semicn = null;
            CondNode cond = null;
            Token last_semicn = null;
            ForStmtNode last_forStmt = null;
            StmtNode stmt = null;
            Token lParent = null;
            Token rParent = null;

            lParent = match(LexType.LPARENT);
            if (tokens.get(currentTokenIndex).getLexType() != LexType.SEMICN) { // s1
                first_forStmt = ForStmt();
            }
            first_semicn = match(LexType.SEMICN);
            if (tokens.get(currentTokenIndex).getLexType() != LexType.SEMICN) { // cond
                cond = Cond();
            }
            last_semicn = match(LexType.SEMICN);
            if (tokens.get(currentTokenIndex).getLexType() != LexType.RPARENT) { //s2
                last_forStmt = ForStmt();
            }
            rParent = match(LexType.RPARENT);
            stmt = Stmt();

            return new StmtNode(StmtType.FOR_STMT, fortk, lParent, first_forStmt, first_semicn, cond, last_semicn, last_forStmt, rParent, stmt);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.BREAKTK) {
            // 'break' ';'
            Token breaktk = match(LexType.BREAKTK);
            Token semicn = null;

            semicn = match(LexType.SEMICN);

            return new StmtNode(StmtType.BREAK_STMT, breaktk, semicn);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.CONTINUETK) {
            // 'continue' ';'
            Token continuetk = match(LexType.CONTINUETK);
            Token semicn = null;

            semicn = match(LexType.SEMICN);

            return new StmtNode(StmtType.CONTINUE_STMT, continuetk, semicn);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.RETURNTK) {
            // 'return' [Exp] ';'
            Token returntk = match(LexType.RETURNTK);
            ExpNode exp = null;
            Token semicn = null;

            if (tokens.get(currentTokenIndex).getLexType() != LexType.SEMICN) {
                if (isExp()){
                    exp = Exp();
                }
            }
            semicn = match(LexType.SEMICN);

            return new StmtNode(StmtType.RETURN_STMT, returntk, exp, semicn);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.PRINTFTK) {
            // 'printf''('StringConst {','Exp}')'';'
            Token printftk = match(LexType.PRINTFTK);
            Token strcon = null;
            List<Token> commas = new ArrayList<>();
            List<ExpNode> exps = new ArrayList<>();
            Token lParent = null;
            Token rParent = null;
            Token semicn = null;

            lParent = match(LexType.LPARENT);
            strcon = match(LexType.STRCON);
            while (tokens.get(currentTokenIndex).getLexType() == LexType.COMMA) {
                commas.add(match(LexType.COMMA));
                exps.add(Exp());
            }
            rParent = match(LexType.RPARENT);
            semicn = match(LexType.SEMICN);

            return new StmtNode(StmtType.PRINTF_STMT, printftk, lParent, strcon, commas, exps, rParent, semicn);
        } else {
            int assign = currentTokenIndex;
            int number = tokens.get(currentTokenIndex).getLine();
            for (int i = currentTokenIndex; i < tokens.size() && tokens.get(i).getLine() == number; i++) {
                if (tokens.get(i).getLexType() == LexType.ASSIGN) {
                    assign = i;
                }
            }
            if (assign > currentTokenIndex) {
                // LVal '=' Exp ';'
                // LVal '=' 'getint' '(' ')' ';'
                // LVal '=' 'getchar' '(' ')' ';'
                LValNode lValNode = LVal();
                Token assignToken = match(LexType.ASSIGN);
                if (tokens.get(currentTokenIndex).getLexType() == LexType.GETINTTK) {
                    Token getintToken = match(LexType.GETINTTK);
                    Token leftParentToken = match(LexType.LPARENT);
                    Token rightParentToken = match(LexType.RPARENT);
                    Token semicnToken = match(LexType.SEMICN);
                    return new StmtNode(StmtType.GETINT_STMT, lValNode, assignToken, getintToken, leftParentToken, rightParentToken, semicnToken);
                } else if (tokens.get(currentTokenIndex).getLexType() == LexType.GETCHARTK) {
                    Token getcharToken = match(LexType.GETCHARTK);
                    Token leftParentToken = match(LexType.LPARENT);
                    Token rightParentToken = match(LexType.RPARENT);
                    Token semicnToken = match(LexType.SEMICN);
                    return new StmtNode(StmtType.GETCHAR_STMT, lValNode, assignToken, getcharToken, leftParentToken, rightParentToken, semicnToken);
                } else {
                    ExpNode expNode = Exp();
                    Token semicnToken = match(LexType.SEMICN);
                    return new StmtNode(StmtType.LVAL_STMT, lValNode, assignToken, expNode, semicnToken);
                }
            } else {
                // [Exp] ';'
                ExpNode expNode = null;
                if (tokens.get(currentTokenIndex).getLexType() != LexType.SEMICN) {
                    if (isExp()) {
                        expNode = Exp();
                    }
                }
                Token semicnToken = match(LexType.SEMICN);
                return new StmtNode(StmtType.EXP_STMT, expNode, semicnToken);
            }
        }
        // return new StmtNode();


    }

    // ForStmt -> LVal '=' Exp
    private ForStmtNode ForStmt()   {
        LValNode lVal = null;
        Token assign = null;
        ExpNode exp = null;

        lVal = LVal();
        assign = match(LexType.ASSIGN);
        exp = Exp();

        return new ForStmtNode(lVal, assign, exp);
    }

    // Exp -> AddExp
    private ExpNode Exp()   {
        AddExpNode addExp = null;

        addExp = AddExp();

        return new ExpNode(addExp);
    }

    // Cond -> LOrExp
    private CondNode Cond()   {
        LOrExpNode cond = null;

        cond = LOrExp();

        return new CondNode(cond);
    }

    // LVal -> Ident ['[' Exp ']']
    private LValNode LVal()   {
        Token idenfr = null;
        Token lBracket = null;
        ExpNode exp = null;
        Token rBracket = null;

        idenfr = match(LexType.IDENFR);
        if (tokens.get(currentTokenIndex).getLexType() == LexType.LBRACK) {
            lBracket = match(LexType.LBRACK);
            exp = Exp();
            rBracket = match(LexType.RBRACK);
        }

        return new LValNode(idenfr, lBracket, exp, rBracket);
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character
    private PrimaryExpNode PrimaryExp()   {
        Token lParent = null;
        ExpNode exp = null;
        Token rParent = null;
        LValNode lVal = null;
        NumberNode number = null;
        CharacterNode character = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.LPARENT) {
            lParent = match(LexType.LPARENT);
            exp = Exp();
            rParent = match(LexType.RPARENT);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.INTCON) {
            number = Number();
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.CHRCON) {
            character = Character();
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.IDENFR){
            lVal = LVal();
        }

        return new PrimaryExpNode(lParent, exp, rParent, lVal, number, character);
    }

    // Number -> IntConst
    private NumberNode Number() {
        Token intcon = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.INTCON) {
            intcon = match(LexType.INTCON);
        }

        return new NumberNode(intcon);
    }

    // Character -> CharConst
    private CharacterNode Character() {
        Token chrcon = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.CHRCON) {
            chrcon = match(LexType.CHRCON);
        }

        return new CharacterNode(chrcon);
    }

    // UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    private UnaryExpNode UnaryExp()   {
        PrimaryExpNode primaryExp = null;
        Token idenfr = null;
        Token lparent = null;
        FuncRParamsNode funcRParams = null;
        Token rparent = null;
        UnaryOpNode unaryOp = null;
        UnaryExpNode unaryExp = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.IDENFR &&
                tokens.get(currentTokenIndex + 1).getLexType() == LexType.LPARENT) {
            idenfr = match(LexType.IDENFR);
            lparent = match(LexType.LPARENT);
            if (tokens.get(currentTokenIndex).getLexType() != LexType.RPARENT) {
                if (isExp()){
                    funcRParams = FuncRParams();
                }
            }
            rparent = match(LexType.RPARENT);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.PLUS ||
                tokens.get(currentTokenIndex).getLexType() == LexType.MINU ||
                tokens.get(currentTokenIndex).getLexType() == LexType.NOT) {
            unaryOp = UnaryOp();
            unaryExp = UnaryExp();
        } else {
            primaryExp = PrimaryExp();
        }

        return new UnaryExpNode(primaryExp, idenfr, lparent, funcRParams, rparent, unaryOp, unaryExp);


    }

    // UnaryOp -> '+' | '−' | '!'
    private UnaryOpNode UnaryOp() {
        Token token = null;

        if (tokens.get(currentTokenIndex).getLexType() == LexType.PLUS) {
            token = match(LexType.PLUS);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.MINU) {
            token = match(LexType.MINU);
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.NOT) {
            token = match(LexType.NOT);
        }

        return new UnaryOpNode(token);
    }

    // FuncRParams -> Exp { ',' Exp }
    private FuncRParamsNode FuncRParams()   {
        List<ExpNode> exps = new ArrayList<>();
        List<Token> commas = new ArrayList<>();

        exps.add(Exp());
        while (tokens.get(currentTokenIndex).getLexType() == LexType.COMMA) {
            commas.add(match(LexType.COMMA));
            exps.add(Exp());
        }

        return new FuncRParamsNode(exps, commas);
    }

    // MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private MulExpNode MulExp()   {
        UnaryExpNode unaryExp = null;
        MulExpNode mulExp = null;
        Token op = null;

        unaryExp = UnaryExp();
        if (tokens.get(currentTokenIndex).getLexType() == LexType.MULT) {
            op = match(LexType.MULT);
            mulExp = MulExp();
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.DIV) {
            op = match(LexType.DIV);
            mulExp = MulExp();
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.MOD) {
            op = match(LexType.MOD);
            mulExp = MulExp();
        }

        return new MulExpNode(unaryExp, mulExp, op);
    }

    // AddExp -> MulExp | AddExp ('+' | '−') MulExp
    private AddExpNode AddExp()   {
        MulExpNode mulExp = null;
        AddExpNode addExp = null;
        Token op = null;

        mulExp = MulExp();
        if (tokens.get(currentTokenIndex).getLexType() == LexType.PLUS) {
            op = match(LexType.PLUS);
            addExp = AddExp();
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.MINU) {
            op = match(LexType.MINU);
            addExp = AddExp();
        }

        return new AddExpNode(mulExp, addExp, op);
    }

    // RelExp -> AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private RelExpNode RelExp()   {
        AddExpNode addExp = null;
        RelExpNode relExp = null;
        Token op = null;

        addExp = AddExp();
        if (tokens.get(currentTokenIndex).getLexType() == LexType.LSS) {
            op = match(LexType.LSS);
            relExp = RelExp();
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.GRE) {
            op = match(LexType.GRE);
            relExp = RelExp();
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.LEQ) {
            op = match(LexType.LEQ);
            relExp = RelExp();
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.GEQ) {
            op = match(LexType.GEQ);
            relExp = RelExp();
        }

        return new RelExpNode(addExp, relExp, op);
    }

    // EqExp -> RelExp | EqExp ('==' | '!=') RelExp
    private EqExpNode EqExp()   {
        RelExpNode relExp = null;
        EqExpNode eqExp = null;
        Token op = null;

        relExp = RelExp();
        if (tokens.get(currentTokenIndex).getLexType() == LexType.EQL) {
            op = match(LexType.EQL);
            eqExp = EqExp();
        } else if (tokens.get(currentTokenIndex).getLexType() == LexType.NEQ) {
            op = match(LexType.NEQ);
            eqExp = EqExp();
        }

        return new EqExpNode(relExp, eqExp, op);
    }

    // LAndExp -> EqExp | LAndExp '&&' EqExp
    private LAndExpNode LAndExp()   {
        EqExpNode eqExp = null;
        LAndExpNode lAndExp = null;
        Token op = null;

        eqExp = EqExp();
        if (tokens.get(currentTokenIndex).getLexType() == LexType.AND) {
            op = match(LexType.AND);
            lAndExp = LAndExp();
        }

        return new LAndExpNode(eqExp, lAndExp, op);
    }

    // LOrExp -> LAndExp | LOrExp '||' LAndExp
    private LOrExpNode LOrExp()   {
        LAndExpNode lAndExp = null;
        LOrExpNode lOrExp = null;
        Token op = null;

        lAndExp = LAndExp();
        if (tokens.get(currentTokenIndex).getLexType() == LexType.OR) {
            op = match(LexType.OR);
            lOrExp = LOrExp();
        }

        return new LOrExpNode(lAndExp, lOrExp, op);
    }

    // ConstExp -> AddExp
    private ConstExpNode ConstExp()   {
        AddExpNode addExp = null;

        addExp = AddExp();

        return new ConstExpNode(addExp);
    }

    public boolean isExp() {
        return (tokens.get(currentTokenIndex).getLexType() == LexType.IDENFR || tokens.get(currentTokenIndex).getLexType() == LexType.PLUS || tokens.get(currentTokenIndex).getLexType() == LexType.MINU || tokens.get(currentTokenIndex).getLexType() == LexType.NOT ||
                tokens.get(currentTokenIndex).getLexType() == LexType.LPARENT || tokens.get(currentTokenIndex).getLexType() == LexType.INTCON || tokens.get(currentTokenIndex).getLexType() == LexType.CHRCON);
    }

    private Token match(LexType tokenType) {
        if (tokens.get(currentTokenIndex).getLexType() == tokenType) {
            Token tmpNow = tokens.get(currentTokenIndex);
            if (currentTokenIndex < tokens.size() - 1) {
                currentTokenIndex++;
            }
            return tmpNow;
        } else if (tokenType == LexType.SEMICN) {
            myErrors.add(new MyError(tokens.get(currentTokenIndex - 1).getLine(), "i"));
            return new Token(LexType.SEMICN, ";", tokens.get(currentTokenIndex - 1).getLine());
        } else if (tokenType == LexType.RPARENT) {
            myErrors.add(new MyError(tokens.get(currentTokenIndex - 1).getLine(), "j"));
            return new Token(LexType.RPARENT, ")", tokens.get(currentTokenIndex - 1).getLine());
        } else if (tokenType == LexType.RBRACK) {
            myErrors.add(new MyError(tokens.get(currentTokenIndex - 1).getLine(), "k"));
            return new Token(LexType.RBRACK, "]", tokens.get(currentTokenIndex - 1).getLine());
        } else {

            throw new RuntimeException("Syntax error at line " + tokens.get(currentTokenIndex).getLine() + ": " + tokens.get(currentTokenIndex).getValue() + " is not " + tokenType);
        }
    }
}

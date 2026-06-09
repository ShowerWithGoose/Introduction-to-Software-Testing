package LexParser;

import Node.*;
import Token.*;

import java.util.ArrayList;
import java.util.HashMap;

public class Parser {
    private ArrayList<Token> tokens;
    private int index = 0;
    private CompUnitNode compUnitNode;
    private HashMap<Integer,Character> errors;
    public static HashMap<NodeType,String> nodeType= new HashMap<NodeType, String>() {{
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
        put(NodeType.Character,"<Character>");
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
    }};

    public Parser(ArrayList<Token> tokens,HashMap<Integer,Character> errors) {
        this.tokens = tokens;
        this.errors = errors;
    }

    public CompUnitNode getCompUnitNode() {
        return compUnitNode;
    }

    public void analyze() {
        this.compUnitNode = CompUnit();
    }

    //检查当前位置是否与 tokenType 匹配
    public boolean check(TOKENTYPE tokentype) {
        return tokens.get(index).getWordType() == tokentype;
    }

    public Token match(TOKENTYPE tokenType) {
        //System.out.println(String.valueOf(index) + ' ' + tokens.get(index).getContent() + ' ' + tokenType);
        if (tokens.get(index).getWordType() == tokenType) {
            Token result = tokens.get(index);
            if (index < tokens.size() - 1) {
                index++;
            }
            return result;
        }
        else if (tokenType == TOKENTYPE.SEMICN) {
            this.errors.put(tokens.get(index - 1).getLineNum(),'i');
            return new Token(";",TOKENTYPE.SEMICN,tokens.get(index).getLineNum());
        }
        else if (tokenType == TOKENTYPE.RPARENT) {
            this.errors.put(tokens.get(index - 1).getLineNum(),'j');
            return new Token(")",TOKENTYPE.RPARENT,tokens.get(index).getLineNum());
        }
        else if (tokenType == TOKENTYPE.RBRACK) {
            this.errors.put(tokens.get(index - 1).getLineNum(),'k');
            return new Token("]",TOKENTYPE.RBRACK,tokens.get(index).getLineNum());
        }
        else {
            throw new RuntimeException("UNKNOWN ERROR:" + index + ' ' +
                    tokens.get(index).getContent() + ' ' + tokenType);
        }
    }

    // CompUnit -> {Decl} {FuncDef} MainFuncDef
    public CompUnitNode CompUnit() {
        ArrayList<DeclNode> declNodes = new ArrayList<>();
        ArrayList<FuncDefNode> funcDefNodes = new ArrayList<>();
        while (tokens.get(index + 1).getWordType() != TOKENTYPE.MAINTK &&
                tokens.get(index + 2).getWordType() != TOKENTYPE.LPARENT) {
            DeclNode declNode = Decl();
            declNodes.add(declNode);
        }
        while (tokens.get(index + 1).getWordType() != TOKENTYPE.MAINTK) {
            FuncDefNode funcDef = FuncDef();
            funcDefNodes.add(funcDef);
        }
        MainFuncDefNode mainFuncDefNode = MainFuncDef();
        return new CompUnitNode(declNodes,funcDefNodes,mainFuncDefNode);
    }

    //声明 Decl → ConstDecl | VarDecl // 覆盖两种声明
    public DeclNode Decl() {
        ConstDeclNode constDeclNode = null;
        VarDeclNode varDeclNode = null;
        if (check(TOKENTYPE.CONSTTK)) {
            constDeclNode = ConstDecl();
        } else {
            varDeclNode = VarDecl();
        }
        return new DeclNode(constDeclNode, varDeclNode);
    }

    //常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // 1.花括号内重复0次
    //2.花括号内重复多次
    public ConstDeclNode ConstDecl() {
        Token constToken = match(TOKENTYPE.CONSTTK);
        BTypeNode bTypeNode = BType();
        ArrayList<ConstDefNode> constDefNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        ConstDefNode constDefNode = ConstDef();
        constDefNodes.add(constDefNode);
        while (check(TOKENTYPE.COMMA)) {
            commas.add(match(TOKENTYPE.COMMA));
            constDefNode = ConstDef();
            constDefNodes.add(constDefNode);
        }
        Token semicnToken = match(TOKENTYPE.SEMICN);
        return new ConstDeclNode(constToken,bTypeNode,constDefNodes,commas,semicnToken);
    }

    //基本类型 BType → 'int' | 'char' // 覆盖两种数据类型的定义
    public BTypeNode BType() {
        if (check(TOKENTYPE.INTTK)) {
            return new BTypeNode(match(TOKENTYPE.INTTK));
        }
        else {
            return new BTypeNode(match(TOKENTYPE.CHARTK));
        }
    }

    //常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // 包含普通变量、一维
    //数组两种情况
    public ConstDefNode ConstDef() {
        Token identToken = match(TOKENTYPE.IDENFR);
        Token leftBracket = null;
        Token rightBracket = null;
        ConstExpNode constExpNode = null;
        if (check(TOKENTYPE.LBRACK)) {
            leftBracket = match(TOKENTYPE.LBRACK);
            constExpNode = ConstExp();
            rightBracket = match(TOKENTYPE.RBRACK);
        }
        Token assignToken = match(TOKENTYPE.ASSIGN);
        ConstInitValNode constInitValNode = ConstInitVal();
        return new ConstDefNode(identToken,leftBracket,constExpNode,rightBracket,assignToken,constInitValNode);
    }

    //常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' |
    //StringConst // 1.常表达式初值 2.一维数组初值
    public ConstInitValNode ConstInitVal() {
        Token leftBraceToken = null;
        ArrayList<ConstExpNode> constExpNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        Token rightBraceToken = null;
        Token stringConst = null;
        if (check(TOKENTYPE.LBRACE)) {
            leftBraceToken = match(TOKENTYPE.LBRACE);
            if (!check(TOKENTYPE.RBRACE)) {
                ConstExpNode constExpNode = ConstExp();
                constExpNodes.add(constExpNode);
                while (!check(TOKENTYPE.RBRACE)) {
                    Token comma = match(TOKENTYPE.COMMA);
                    commas.add(comma);
                    constExpNode = ConstExp();
                    constExpNodes.add(constExpNode);
                }
            }
            rightBraceToken = match(TOKENTYPE.RBRACE);
        }
        else if (check(TOKENTYPE.STRCON)) {
            stringConst = match(TOKENTYPE.STRCON);
        }
        else {
            ConstExpNode constExpNode = ConstExp();
            constExpNodes.add(constExpNode);
        }
        return new ConstInitValNode(leftBraceToken,constExpNodes,commas,rightBraceToken,stringConst);
    }

    //变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // 1.花括号内重复0次 2.花括号内重复
    //多次
    public VarDeclNode VarDecl() {
        BTypeNode bTypeNode = BType();
        ArrayList<VarDefNode> varDefNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        varDefNodes.add(VarDef());
        while (check(TOKENTYPE.COMMA)) {
            commas.add(match(TOKENTYPE.COMMA));
            varDefNodes.add(VarDef());
        }
        Token semicnToken = match(TOKENTYPE.SEMICN);
        return new VarDeclNode(bTypeNode,varDefNodes,commas,semicnToken);
    }

    //变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '='
    //InitVal // 包含普通常量、一维数组定义
    public VarDefNode VarDef() {
        Token ident = match(TOKENTYPE.IDENFR);
        Token leftBracket = null;
        Token rightBracket = null;
        ConstExpNode constExpNode = null;
        Token assign = null;
        InitValNode initValNode = null;
        if (check(TOKENTYPE.LBRACK)) {
            leftBracket = match(TOKENTYPE.LBRACK);
            constExpNode = ConstExp();
            rightBracket = match(TOKENTYPE.RBRACK);
        }
        if (check(TOKENTYPE.ASSIGN)) {
            assign = match(TOKENTYPE.ASSIGN);
            initValNode = InitVal();
        }
        return new VarDefNode(ident,leftBracket,constExpNode,rightBracket,assign,initValNode);
    }

    //变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst // 1.表达式初值
    //2.一维数组初值
    public InitValNode InitVal() {
        Token leftBracket = null;
        Token rightBracket = null;
        ArrayList<ExpNode> exps = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        Token stringConst = null;
        if (check(TOKENTYPE.LBRACE)) {
            leftBracket = match(TOKENTYPE.LBRACE);
            exps.add(Exp());
            while (check(TOKENTYPE.COMMA)){
                commas.add(match(TOKENTYPE.COMMA));
                exps.add(Exp());
            }
            rightBracket = match(TOKENTYPE.RBRACE);
        }
        else if (check(TOKENTYPE.STRCON)) {
            stringConst = match(TOKENTYPE.STRCON);
        }
        else {
            exps.add(Exp());
        }
        return new InitValNode(leftBracket,exps,commas,rightBracket,stringConst);
    }

    //函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // 1.无形参 2.有形参
    public FuncDefNode FuncDef() {
        FuncTypeNode funcTypeNode = FuncType();
        Token ident = match(TOKENTYPE.IDENFR);
        Token leftParent = match(TOKENTYPE.LPARENT);
        FuncFParamsNode funcFParamsNode = null;
        //如果不是 ')' -> 存在参数，同时不是 '{' -> 不是缺少右括号
        if (!check(TOKENTYPE.RPARENT) && !check(TOKENTYPE.LBRACE)) {
            funcFParamsNode = FuncFParams();
        }
        Token rightParent = match(TOKENTYPE.RPARENT);
        BlockNode blockNode = Block();
        return new FuncDefNode(funcTypeNode,ident,leftParent,funcFParamsNode,rightParent,blockNode);
    }

    //主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // 存在main函数
    public MainFuncDefNode MainFuncDef() {
        Token intToken = match(TOKENTYPE.INTTK);
        Token mainToken = match(TOKENTYPE.MAINTK);
        Token leftParentToken = match(TOKENTYPE.LPARENT);
        Token rightParentToken = match(TOKENTYPE.RPARENT);
        BlockNode blockNode = Block();
        return new MainFuncDefNode(intToken,mainToken,leftParentToken,rightParentToken,blockNode);
    }

    //函数类型 FuncType → 'void' | 'int' | 'char'// 覆盖三种类型的函数
    public FuncTypeNode FuncType() {
        if (check(TOKENTYPE.VOIDTK)) {
            return new FuncTypeNode(match(TOKENTYPE.VOIDTK));
        }
        else if (check(TOKENTYPE.INTTK)) {
            return new FuncTypeNode(match(TOKENTYPE.INTTK));
        }
        else {
            return new FuncTypeNode(match(TOKENTYPE.CHARTK));
        }
    }

    //函数形参表 FuncFParams → FuncFParam { ',' FuncFParam } // 1.花括号内重复0次 2.花括号内
    //重复多次
    public FuncFParamsNode FuncFParams() {
        ArrayList<FuncFParamNode> funcFParamNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        funcFParamNodes.add(FuncFParam());
        while (check(TOKENTYPE.COMMA)) {
            commas.add(match(TOKENTYPE.COMMA));
            funcFParamNodes.add(FuncFParam());
        }
        return new FuncFParamsNode(funcFParamNodes,commas);
    }

    //函数形参 FuncFParam → BType Ident ['[' ']'] // 1.普通变量2.一维数组变量
    public FuncFParamNode FuncFParam() {
        BTypeNode bTypeNode = BType();
        Token identToken = match(TOKENTYPE.IDENFR);
        Token leftBracket = null;
        Token rightBracket = null;
        if (check(TOKENTYPE.LBRACK)) {
            leftBracket = match(TOKENTYPE.LBRACK);
            rightBracket = match(TOKENTYPE.RBRACK);
        }
        return new FuncFParamNode(bTypeNode,identToken,leftBracket,rightBracket);
    }

    //语句块 Block → '{' { BlockItem } '}' // 1.花括号内重复0次 2.花括号内重复多次
    public BlockNode Block() {
        Token leftBrace = match(TOKENTYPE.LBRACE);
        ArrayList<BlockItemNode> blockItemNodes = new ArrayList<>();
        while (!check(TOKENTYPE.RBRACE)) {
            blockItemNodes.add(BlockItem());
        }
        Token rightBrace = match(TOKENTYPE.RBRACE);
        return new BlockNode(leftBrace,blockItemNodes,rightBrace);
    }

    //语句块项 BlockItem → Decl | Stmt // 覆盖两种语句块项
    public BlockItemNode BlockItem() {
        DeclNode declNode = null;
        StmtNode stmtNode = null;
        if (check(TOKENTYPE.CONSTTK) || check(TOKENTYPE.INTTK) || check(TOKENTYPE.CHARTK)) {
            declNode = Decl();
        }
        else {
            stmtNode = Stmt();
        }
        return new BlockItemNode(declNode, stmtNode);
    }

    //语句 Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
    //| [Exp] ';' //有无Exp两种情况
    //| Block
    //| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
    //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // 1. 无缺省，1种情况 2.
    //ForStmt与Cond中缺省一个，3种情况 3. ForStmt与Cond中缺省两个，3种情况 4. ForStmt与Cond全部
    //缺省，1种情况
    //| 'break' ';' | 'continue' ';'
    //| 'return' [Exp] ';' // 1.有Exp 2.无Exp
    //| LVal '=' 'getint''('')'';'
    //| LVal '=' 'getchar''('')'';'
    //| 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp

    public StmtNode Stmt() {
        // Block
        if (check(TOKENTYPE.LBRACE)) {
            BlockNode blockNode = Block();
            return new StmtNode(StmtNode.StmtType.Block,blockNode);
        }
        //'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
        else if (check(TOKENTYPE.IFTK)) {
            Token ifToken = match(TOKENTYPE.IFTK);
            Token leftParent = match(TOKENTYPE.LPARENT);
            CondNode condNode = Cond();
            Token rightParent = match(TOKENTYPE.RPARENT);
            ArrayList<StmtNode>  stmtNodes = new ArrayList<>();
            stmtNodes.add(Stmt());
            Token elseToken = null;
            if (check(TOKENTYPE.ELSETK)) {
                elseToken = match(TOKENTYPE.ELSETK);
                stmtNodes.add(Stmt());
            }
            return new StmtNode(StmtNode.StmtType.If,ifToken,leftParent,condNode,rightParent,stmtNodes,elseToken);
        }
        //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        else if (check(TOKENTYPE.FORTK)) {
            Token forToken = match(TOKENTYPE.FORTK);
            Token leftParent = match(TOKENTYPE.LPARENT);
            ForStmtNode forStmtNode1 = null;
            if (!check(TOKENTYPE.SEMICN)) {
                forStmtNode1 = ForStmt();
            }
            Token semicn1 = match(TOKENTYPE.SEMICN);
            CondNode condNode = null;
            if (!check(TOKENTYPE.SEMICN)) {
                condNode = Cond();
            }
            Token semicn2 = match(TOKENTYPE.SEMICN);
            ForStmtNode forStmtNode2 = null;
            if (!check(TOKENTYPE.RPARENT)) {
                forStmtNode2 = ForStmt();
            }
            Token rightParent = match(TOKENTYPE.RPARENT);
            StmtNode stmtNode = Stmt();
            return new StmtNode(StmtNode.StmtType.For,forToken,leftParent,
                    forStmtNode1,semicn1,condNode,forStmtNode2,semicn2,rightParent,stmtNode);
        }
        //'break' ';'
        else if (check(TOKENTYPE.BREAKTK)) {
            Token breakToken = match(TOKENTYPE.BREAKTK);
            Token semicnToken = match(TOKENTYPE.SEMICN);
            return new StmtNode(StmtNode.StmtType.BreakOrContinue,breakToken,semicnToken);
        }
        //'continue' ';'
        else if (check(TOKENTYPE.CONTINUETK)) {
            Token continueToken = match(TOKENTYPE.CONTINUETK);
            Token semicnToken = match(TOKENTYPE.SEMICN);
            return new StmtNode(StmtNode.StmtType.BreakOrContinue,continueToken,semicnToken);
        }
        //'return' [Exp] ';'
        else if (check(TOKENTYPE.RETURNTK)) {
            Token returnToken = match(TOKENTYPE.RETURNTK);
            ExpNode expNode = null;
            if (!check(TOKENTYPE.SEMICN)) {
                expNode = Exp();
            }
            Token semicnToken = match(TOKENTYPE.SEMICN);
            return new StmtNode(StmtNode.StmtType.Return,returnToken,expNode,semicnToken);
        }
        //'printf''('StringConst {','Exp}')'';'
        else if (check(TOKENTYPE.PRINTFTK)) {
            Token printfToken = match(TOKENTYPE.PRINTFTK);
            Token leftParent = match(TOKENTYPE.LPARENT);
            Token stringToken = match(TOKENTYPE.STRCON);
            ArrayList<Token> commas = new ArrayList<>();
            ArrayList<ExpNode> expNodes = new ArrayList<>();
            while (check(TOKENTYPE.COMMA)) {
                commas.add(match(TOKENTYPE.COMMA));
                expNodes.add(Exp());
            }
            Token rightParentToken = match(TOKENTYPE.RPARENT);
            Token semicnToken = match(TOKENTYPE.SEMICN);
            return new StmtNode(StmtNode.StmtType.Printf,printfToken,leftParent,stringToken,
                    commas,expNodes,rightParentToken,semicnToken);
        }
        else {
            boolean assignJudge = false;
            for (int i = index;i < tokens.size() && tokens.get(index).getLineNum().
                    equals(tokens.get(i).getLineNum());i++) {
                if (tokens.get(i).getWordType() == TOKENTYPE.ASSIGN) {
                    assignJudge = true;
                    break;
                }
            }
            if (assignJudge) {
                //LVal '=' Exp ';'
                //LVal '=' 'getint''('')'';'
                //LVal '=' 'getchar''('')'';'
                if (check(TOKENTYPE.IDENFR)) {
                    LValNode lvalNode = LVal();
                    Token assignToken = match(TOKENTYPE.ASSIGN);
                    if (check(TOKENTYPE.GETINTTK)) {
                        Token getIntToken = match(TOKENTYPE.GETINTTK);
                        Token leftParent = match(TOKENTYPE.LPARENT);
                        Token rightParent = match(TOKENTYPE.RPARENT);
                        Token semicnToken = match(TOKENTYPE.SEMICN);
                        return new StmtNode(StmtNode.StmtType.LvalAssignGetIntOrChar,lvalNode,
                                assignToken,getIntToken,leftParent,rightParent,semicnToken);
                    }
                    else if (check(TOKENTYPE.GETCHARTK)) {
                        Token getIntToken = match(TOKENTYPE.GETCHARTK);
                        Token leftParent = match(TOKENTYPE.LPARENT);
                        Token rightParent = match(TOKENTYPE.RPARENT);
                        Token semicnToken = match(TOKENTYPE.SEMICN);
                        return new StmtNode(StmtNode.StmtType.LvalAssignGetIntOrChar,lvalNode,
                                assignToken,getIntToken,leftParent,rightParent,semicnToken);
                    }
                    else {
                        ExpNode expNode = Exp();
                        Token semicnToken = match(TOKENTYPE.SEMICN);
                        return new StmtNode(StmtNode.StmtType.LvalAssignExp,lvalNode,assignToken,expNode,semicnToken);
                    }
                }
            }
            else {
                // [Exp] ';'
                ExpNode expNode = null;
                if (!check(TOKENTYPE.SEMICN)) {
                    expNode = Exp();
                }
                Token semicnToken = match(TOKENTYPE.SEMICN);
                return new StmtNode(StmtNode.StmtType.Exp, expNode, semicnToken);
            }
        }
        return null;
    }

    //语句 ForStmt → LVal '=' Exp
    public ForStmtNode ForStmt() {
        LValNode lvalNode = LVal();
        Token assignToken = match(TOKENTYPE.ASSIGN);
        ExpNode expNode = Exp();
        return new ForStmtNode(lvalNode,assignToken,expNode);
    }

    //表达式 Exp → AddExp // 存在即可
    public ExpNode Exp() {
        return new ExpNode(AddExp());
    }

    //条件表达式 Cond → LOrExp
    public CondNode Cond() {
        return new CondNode(LOrExp());
    }

    //左值表达式 LVal → Ident ['[' Exp ']'] //1.普通变量、常量 2.一维数组
    public LValNode LVal() {
        Token identToken = match(TOKENTYPE.IDENFR);
        Token leftBracket = null;
        ExpNode expNode = null;
        Token rightBracket = null;
        if (check(TOKENTYPE.LBRACK)) {
            leftBracket = match(TOKENTYPE.LBRACK);
            expNode = Exp();
            rightBracket = match(TOKENTYPE.RBRACK);
        }
        return new LValNode(identToken,leftBracket,expNode,rightBracket);
    }

    //基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// 四种情况均需覆盖
    public PrimaryExpNode PrimaryExp() {
        Token leftParent = null;
        Token rightParent = null;
        ExpNode expNode = null;
        LValNode lValNode = null;
        NumberNode numberNode = null;
        CharacterNode characterNode = null;
        if (check(TOKENTYPE.LPARENT)) {
            leftParent = match(TOKENTYPE.LPARENT);
            expNode = Exp();
            rightParent = match(TOKENTYPE.RPARENT);
        }
        else if (check(TOKENTYPE.IDENFR)) {
            lValNode = LVal();
        }
        else if (check(TOKENTYPE.INTCON)) {
            numberNode = Number();
        }
        else if (check(TOKENTYPE.CHRCON)) {
            characterNode = Character();
        }
        return new PrimaryExpNode(leftParent,expNode,rightParent,lValNode,numberNode,characterNode);
    }

    //数值 Number → IntConst // 存在即可，IntConst详细解释见下方 (3) 数值常量
    public NumberNode Number() {
        return new NumberNode(match(TOKENTYPE.INTCON));
    }

    //字符 Character → CharConst // CharConst详细解释见下方 (4) 字符常量
    public CharacterNode Character() {
        return new CharacterNode(match(TOKENTYPE.CHRCON));
    }

    //一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    //// 3种情况均需覆盖,函数调用也需要覆盖FuncRParams的不同情况
    public UnaryExpNode UnaryExp() {
        PrimaryExpNode primaryExpNode = null;
        Token identToken = null;
        Token leftParent = null;
        FuncRParamsNode funcRParamsNode = null;
        Token rightParent = null;
        UnaryOpNode unaryOpNode = null;
        UnaryExpNode unaryExpNode = null;
        if (check(TOKENTYPE.IDENFR) && tokens.get(index + 1).getWordType() == TOKENTYPE.LPARENT) {
            identToken = match(TOKENTYPE.IDENFR);
            leftParent = match(TOKENTYPE.LPARENT);
            if (!check(TOKENTYPE.RPARENT)) {
                funcRParamsNode = FuncRParams();
            }
            rightParent = match(TOKENTYPE.RPARENT);
        }
        else if (check(TOKENTYPE.PLUS) || check(TOKENTYPE.MINU) || check(TOKENTYPE.NOT)) {
            unaryOpNode = UnaryOp();
            unaryExpNode = UnaryExp();
        }
        else {
            primaryExpNode = PrimaryExp();
        }
        return new UnaryExpNode(primaryExpNode,identToken,leftParent,
                funcRParamsNode,rightParent,unaryOpNode,unaryExpNode);
    }

    //单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中 // 三种均需覆盖
    public UnaryOpNode UnaryOp() {
        if (check(TOKENTYPE.PLUS)) {
            return new UnaryOpNode(match(TOKENTYPE.PLUS));
        }
        else if (check(TOKENTYPE.MINU)) {
            return new UnaryOpNode(match(TOKENTYPE.MINU));
        }
        else {
            return new UnaryOpNode(match(TOKENTYPE.NOT));
        }
    }

    //函数实参表 FuncRParams → Exp { ',' Exp } // 1.花括号内重复0次 2.花括号内重复多次 3.Exp需
    //要覆盖数组传参和部分数组传参
    public FuncRParamsNode FuncRParams() {
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        expNodes.add(Exp());
        while(check(TOKENTYPE.COMMA)) {
            commas.add(match(TOKENTYPE.COMMA));
            expNodes.add(Exp());
        }
        return new FuncRParamsNode(expNodes,commas);
    }

    //乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp // 1.UnaryExp
    //2.* 3./ 4.% 均需覆盖
    //改写:MulExp → UnaryExp | UnaryExp ('*' | '/' | '%') MulExp
    public MulExpNode MulExp() {
        UnaryExpNode unaryExpNode = UnaryExp();
        Token operator = null;
        MulExpNode mulExpNode = null;
        if (check(TOKENTYPE.MULT)) {
            operator = match(TOKENTYPE.MULT);
            mulExpNode = MulExp();
        }
        else if (check(TOKENTYPE.DIV)) {
            operator = match(TOKENTYPE.DIV);
            mulExpNode = MulExp();
        }
        else if (check(TOKENTYPE.MOD)) {
            operator = match(TOKENTYPE.MOD);
            mulExpNode = MulExp();
        }
        return new MulExpNode(unaryExpNode, operator, mulExpNode);
    }

    //加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp // 1.MulExp 2.+ 需覆盖 3.- 需
    //覆盖
    //改写:AddExp → MulExp | MulExp ('+' | '−') AddExp
    public AddExpNode AddExp() {
        MulExpNode mulExpNode = MulExp();
        Token operator = null;
        AddExpNode addExpNode = null;
        if (check(TOKENTYPE.PLUS)) {
            operator = match(TOKENTYPE.PLUS);
            addExpNode = AddExp();
        }
        else if (check(TOKENTYPE.MINU)) {
            operator = match(TOKENTYPE.MINU);
            addExpNode = AddExp();
        }
        return new AddExpNode(mulExpNode,operator,addExpNode);
    }

    //关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp // 1.AddExp 2.
    //< 3.> 4.<= 5.>= 均需覆盖
    //改写:RelExp → AddExp | AddExp ('<' | '>' | '<=' | '>=') RelExp
    public RelExpNode RelExp() {
        AddExpNode addExpNode = AddExp();
        Token operator = null;
        RelExpNode relExpNode = null;
        if (check(TOKENTYPE.LSS)) {
            operator = match(TOKENTYPE.LSS);
            relExpNode = RelExp();
        }
        else if (check(TOKENTYPE.GRE)) {
            operator = match(TOKENTYPE.GRE);
            relExpNode = RelExp();
        }
        else if (check(TOKENTYPE.LEQ)) {
            operator = match(TOKENTYPE.LEQ);
            relExpNode = RelExp();
        }
        else if (check(TOKENTYPE.GEQ)) {
            operator = match(TOKENTYPE.GEQ);
            relExpNode = RelExp();
        }
        return new RelExpNode(addExpNode,operator,relExpNode);
    }

    //相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp // 1.RelExp 2.== 3.!= 均需
    //覆盖
    // 改写:  EqExp → RelExp | RelExp ('==' | '!=')  EqExp
    public EqExpNode EqExp() {
        RelExpNode relExpNode = RelExp();
        Token operator = null;
        EqExpNode eqExpNode = null;
        if (check(TOKENTYPE.EQL)) {
            operator = match(TOKENTYPE.EQL);
            eqExpNode = EqExp();
        }
        else if (check(TOKENTYPE.NEQ)) {
            operator = match(TOKENTYPE.NEQ);
            eqExpNode = EqExp();
        }
        return new EqExpNode(relExpNode,operator,eqExpNode);
    }

    //逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp // 1.EqExp 2.&& 均需覆盖
    public LAndExpNode LAndExp() {
        EqExpNode eqExpNode = EqExp();
        LAndExpNode lAndExpNode = null;
        Token addToken = null;
        if (check(TOKENTYPE.AND)) {
            addToken = match(TOKENTYPE.AND);
            lAndExpNode = LAndExp();
        }
        return new LAndExpNode(eqExpNode,addToken,lAndExpNode);
    }

    //逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp // 1.LAndExp 2.|| 均需覆盖
    public LOrExpNode LOrExp() {
        LAndExpNode lAndExpNode  = LAndExp();
        LOrExpNode lOrExpNode = null;
        Token orToken = null;
        if (check(TOKENTYPE.OR)) {
            orToken = match(TOKENTYPE.OR);
            lOrExpNode = LOrExp();
        }
        return new LOrExpNode(lAndExpNode,orToken,lOrExpNode);
    }

    //常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量 // 存在即可
    public ConstExpNode ConstExp() {
        return new ConstExpNode(AddExp());
    }

}

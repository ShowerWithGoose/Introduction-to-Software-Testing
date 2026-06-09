import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

// 递归下降解析器
public class Parser {
    private final List<Token> tokens;
    private int pos = 0;

    public Parser(List<Token> tokens) {
        this.tokens = tokens;
    }

    // 获取当前Token
    private Token currentToken() {
        return tokens.get(pos);
    }

    // 向前移动一个Token
    private void advance() {
        pos++;
    }

    private Token latestToken() {
        return tokens.get(pos - 1);
    }

    private Token peekNextToken() {
        return peekNextToken(1);
    }

    private Token peekNextToken(int n) {
        if (pos + n < tokens.size()) {
            return tokens.get(pos + n);
        }
        return null;
    }


    private boolean match(String expectedType) {
        if (currentToken().type.equals(expectedType)) {
            advance();
            return true;
        }
        else{
            switch (expectedType){
                case "SEMICN":
                    Compiler.isError = true;
                    Compiler.errors.add(new Errors(latestToken().n, 'i'));
                    break;
                case "RBRACK":
                    Compiler.isError = true;
                    Compiler.errors.add(new Errors(latestToken().n, 'k'));
                    break;
                case "RPARENT":
                    Compiler.isError = true;
                    Compiler.errors.add(new Errors(latestToken().n, 'j'));
                    break;
            }
        }
        return false;
    }

    // Main entry point to parse CompUnit → {Decl} {FuncDef} MainFuncDef
    public CompUnitNode parseCompUnit() {
        List<DeclNode> declNodes = new ArrayList<>();
        List<FuncDefNode> funcDefNodes = new ArrayList<>();

        // Parse declarations
        while (isDecl()) {
            declNodes.add(parseDecl());
        }

        while (isFuncDef()) {
            funcDefNodes.add(parseFuncDef());
        }

        MainFuncDefNode mainFuncDefNode = parseMainFuncDef();

        return new CompUnitNode(declNodes.isEmpty() ? null : declNodes,
                funcDefNodes.isEmpty() ? null : funcDefNodes,
                mainFuncDefNode);
    }

    // Check if it's a declaration (Decl → ConstDecl | VarDecl)
    private boolean isDecl() {
        return currentToken().type.equals("CONSTTK") || (isBType() && peekNextToken().type.equals("IDENFR") && !Objects.requireNonNull(peekNextToken(2)).type.equals("LPARENT"));
    }

    private boolean isBType(){
        return currentToken().type.equals("INTTK") ||  currentToken().type.equals("CHARTK");
    }

    // Parse Decl → ConstDecl | VarDecl
    private DeclNode parseDecl() {
        DeclNode declNode;
        if (match("CONSTTK")) {
            declNode = new DeclNode(parseConstDecl(), null);
        } else {
            declNode = new DeclNode(null, parseVarDecl());
        }
        return declNode;
    }

    // Parse ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    private ConstDeclNode parseConstDecl() {
        BTypeNode bTypeNode;
        List<ConstDefNode> constDefNodes = new ArrayList<>();
        bTypeNode = parseBType();
        constDefNodes.add(parseConstDef());

        while (match("COMMA")) {
            constDefNodes.add(parseConstDef());
        }

        match("SEMICN");
        return new ConstDeclNode(bTypeNode, constDefNodes);
    }

    // Parse ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    private ConstDefNode parseConstDef() {
        ConstExpNode constExpNode = null;
        ConstInitValNode constInitValNode;
        String ident;
        match("IDENFR");
        ident = latestToken().s;

        if (match("LBRACK")) {
            constExpNode = parseConstExp();
            match("RBRACK");
        }

        match("ASSIGN");
        constInitValNode = parseConstInitVal();
        return new ConstDefNode(ident, constExpNode, constInitValNode);
    }

    // Parse ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ConstInitValNode parseConstInitVal() {
        ConstInitValNode constInitValNode;
        if (match("LBRACE")) {
            List<ConstExpNode> constExpNodes = null;
            if (!match("RBRACE")) {
                do {
                    if (constExpNodes == null)
                        constExpNodes = new ArrayList<>();
                    constExpNodes.add(parseConstExp());
                } while (match("COMMA"));
                match("RBRACE");
            }
            constInitValNode = new ArrayConst(constExpNodes);
        } else if (match("STRCON")) {
            constInitValNode = new StringConst(latestToken().s);
            // Handle string constant
        } else {
            constInitValNode = new NumberConst(parseConstExp());
        }
        return constInitValNode;
    }

    // Parse VarDecl → BType VarDef { ',' VarDef } ';'
    private VarDeclNode parseVarDecl() {
        BTypeNode bTypeNode = parseBType();
        List<VarDefNode> varDefNodes = new ArrayList<>();
        varDefNodes.add(parseVarDef());

        while (match("COMMA")) {
            varDefNodes.add(parseVarDef());
        }

        match("SEMICN");
        return new VarDeclNode(bTypeNode, varDefNodes);
    }

    // Parse VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    private VarDefNode parseVarDef() {
        String ident;
        ConstExpNode constExpNode = null;
        InitValNode initValNode = null;
        match("IDENFR");
        ident = latestToken().s;

        // Parse initial value
        if (match("LBRACK")) {
            constExpNode = parseConstExp();
            match("RBRACK");
        }
        if (match("ASSIGN")) {
            initValNode = parseInitVal();
        }
        return new VarDefNode(ident, constExpNode, initValNode);
    }

    // Parse InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private InitValNode parseInitVal() {
        if (match("LBRACE")) {
            List<ExpNode> expNodes = null;
            if (!match("RBRACE")) {
                do {
                    if (expNodes == null)
                        expNodes = new ArrayList<>();
                    expNodes.add(parseExp());
                } while (match("COMMA"));
                match("RBRACE");
            }
            return new ArraryVal(expNodes);
        } else if (match("STRCON")) {
            return new StringVal(latestToken().s);
        } else {
            return new NumberVal(parseExp());
        }
    }

    // Parse FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    private FuncDefNode parseFuncDef() {
        FuncTypeNode funcTypeNode = parseFuncType();
        advance();

        String ident;
        FuncFParamsNode funcFParamsNode = null;
        BlockNode blockNode;
        match("IDENFR");
        ident = latestToken().s;

        match("LPARENT");
        if (!currentToken().type.equals("RPARENT")){
            funcFParamsNode = parseFuncFParams();
        }
        match("RPARENT");

        blockNode = parseBlock();
        return new FuncDefNode(funcTypeNode, ident, funcFParamsNode, blockNode);
    }

    private FuncTypeNode parseFuncType() {
        return new FuncTypeNode(currentToken().s);
    }


    // Parse FuncFParams → FuncFParam { ',' FuncFParam }
    private FuncFParamsNode parseFuncFParams() {
        List<FuncFParamNode> funcFParamNodes = new ArrayList<>();
        funcFParamNodes.add(parseFuncFParam());
        while (match("COMMA")) {
            funcFParamNodes.add(parseFuncFParam());
        }
        return new FuncFParamsNode(funcFParamNodes);
    }

    // Parse FuncFParam → BType Ident ['[' ']']
    private FuncFParamNode parseFuncFParam() {
        BTypeNode bTypeNode = parseBType();
        String ident;
        int n = 0;
        match("IDENFR");
        ident = latestToken().s;

        if (match("LBRACK")) {
            n = 1;
            match("RBRACK");
        }
        return new FuncFParamNode(bTypeNode, ident, n);
    }

    // Parse MainFuncDef → 'int' 'main' '(' ')' Block
    private MainFuncDefNode parseMainFuncDef() {
        match("INTTK");
        match("MAINTK");
        match("LPARENT");
        match("RPARENT");
        BlockNode blockNode = parseBlock();
        return new MainFuncDefNode(blockNode);
    }

    // Parse Block → '{' { BlockItem } '}'
    private BlockNode parseBlock() {
        List<BlockItemNode> blockItemNodes = null;
        match("LBRACE");

        while (!match("RBRACE")) {
            if (blockItemNodes == null)
                blockItemNodes = new ArrayList<>();
            blockItemNodes.add(parseBlockItem());
        }
        return new BlockNode(blockItemNodes);
    }

    // Parse BlockItem → Decl | Stmt
    private BlockItemNode parseBlockItem() {
        if (isDecl()) {
            return new DeclBlock(parseDecl());
        } else {
            return new StmtBlock(parseStmt());
        }
    }

    // Stmt → LVal '=' Exp ';' | [Exp] ';' | Block | if | for | break | continue | return 等
    public StmtNode parseStmt() {
        if (currentToken().type.equals("LBRACE")) {
            // Block → '{' { BlockItem } '}'
            BlockNode block = parseBlock();
            return new BlockStmt(block);
        } else if (match("IFTK")) {
            // if '(' Cond ')' Stmt [ 'else' Stmt ]
            match("LPARENT");
            CondNode cond = parseCond();
            match("RPARENT");
            StmtNode thenStmt = parseStmt();
            StmtNode elseStmt = null;
            if (match("ELSETK")) {
                elseStmt = parseStmt();
            }
            return new IfStmt(cond, thenStmt, elseStmt);
        } else if (match("FORTK")) {
            // for '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            ForStmtNode init, update;
            CondNode cond;
            match("LPARENT");
            if (currentToken().type.equals("SEMICN")) {
                advance();
                init = null;
            }
            else {
                init = parseForStmt();
                match("SEMICN");
            }

            if (currentToken().type.equals("SEMICN")){
                advance();
                cond = null;
            }
            else {
                cond = parseCond();
                match("SEMICN");
            }

            if (currentToken().type.equals("RPARENT")) {
                update = null;
                advance();
            }
            else{
                update = parseForStmt();
                match("RPARENT");
            }
            StmtNode body = parseStmt();
            return new ForStmt(init, cond, update, body);
        } else if (match("BREAKTK")) {
            // break ';'
            match("SEMICN");
            return new BreakStmt();
        } else if (match("CONTINUETK")) {
            // continue ';'
            match("SEMICN");
            return new ContinueStmt();
        } else if (match("RETURNTK")) {
            // return [Exp] ';'
            ExpNode expNode = null;
            if (!currentToken().type.equals("SEMICN"))
                expNode = parseExp();
            match("SEMICN");
            return new ReturnStmt(expNode);
        }else if (match("PRINTFTK")) {
            // printf '(' StringConst {',' Exp} ')' ';'
            match("LPARENT");
            String stringConst = currentToken().s;
            match("STRCON");
            List<ExpNode> expList = new ArrayList<>();
            while (match("COMMA")) {
                expList.add(parseExp());
            }
            match("RPARENT");
            match("SEMICN");
            return new PrintStmt(stringConst, expList);
        } else {
            int temp = pos, f;
            for (f = pos; !tokens.get(f).type.equals("SEMICN") && tokens.get(f).n == tokens.get(pos).n; f++){
                if (tokens.get(f).type.equals("ASSIGN")){
                    temp = f;
                    break;
                }
            }
            if (temp > pos){

                LValNode lVal = parseLVal();
                advance();
                if (match("GETINTTK")){
                    match("LPARENT");
                    match("RPARENT");
                    match("SEMICN");
                    return new IntStmt(lVal);
                }
                else if (match("GETCHARTK")){
                    match("LPARENT");
                    match("RPARENT");
                    match("SEMICN");
                    return new CharStmt(lVal);
                }
                else {
                    // LVal '=' Exp ';'
                    ExpNode exp = parseExp();
                    match("SEMICN");
                    return new AssignStmt(lVal, exp);
                }
            }
            else {
                // [Exp] ';'
                ExpNode exp;

                if (currentToken().type.equals("SEMICN"))
                    exp = null;
                else
                    exp = parseExp();
                match("SEMICN");
                return new ExpStmt(exp);
            }
        }
    }

    private CondNode parseCond() {
        LOrExpNode lOrExpNode = parseLOrExp();
        return new CondNode(lOrExpNode);
    }

    private LOrExpNode parseLOrExp() {
        LOrExpNode lOrExpNode;
        lOrExpNode = new LOrExpNode(null, parseLAndExp());
        while (match("OR")) {
            lOrExpNode = new LOrExpNode(lOrExpNode, parseLAndExp());
        }
        return lOrExpNode;
    }

    private LAndExpNode parseLAndExp() {
        LAndExpNode lAndExpNode;
        lAndExpNode = new LAndExpNode(parseEqExp(), null);
        while (match("AND")) {
            lAndExpNode = new LAndExpNode(parseEqExp(), lAndExpNode);
        }
        return lAndExpNode;
    }

    private EqExpNode parseEqExp() {
        EqExpNode expNode;
        expNode = new EqExpNode(parseRelExp(), null, "");
        while (match("EQL") || match("NEQ")) {
            String s = latestToken().s;
            expNode = new EqExpNode(parseRelExp(), expNode, s);
        }
        return expNode;
    }

    private RelExpNode parseRelExp() {
        RelExpNode relExpNode;
        relExpNode = new RelExpNode(parseAddExp(), null, "");
        while (match("GRE") || match("GEQ") || match("LSS") || match("LEQ")) {
            String s = latestToken().s;
            relExpNode = new RelExpNode(parseAddExp(), relExpNode, s);
        }
        return relExpNode;
    }


    private ForStmtNode parseForStmt() {
        LValNode lValNode = parseLVal();
        advance();
        ExpNode expNode = parseExp();

        return new ForStmtNode(lValNode, expNode);
    }


    // Parse Exp → AddExp
    private ExpNode parseExp() {
        return new ExpNode(parseAddExp());
    }

    // Parse ConstExp → AddExp (constant expression)
    private ConstExpNode parseConstExp() {
        return new ConstExpNode(parseAddExp());
    }

    // Parse AddExp → MulExp | AddExp ('+' | '−') MulExp
    private AddExpNode parseAddExp() {
        AddExpNode addExpNode;
        addExpNode = new AddExpNode(null, parseMulExp(), ' ');
        while (match("PLUS") || match("MINU")) {
            char ch = latestToken().s.charAt(0);
            addExpNode = new AddExpNode(addExpNode, parseMulExp(), ch);
        }
        return addExpNode;
    }

    // Parse MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private MulExpNode parseMulExp() {
        MulExpNode mulExpNode;
        mulExpNode = new MulExpNode(parseUnaryExp(), null, ' ');
        while (match("MULT") || match("DIV") || match("MOD")) {
            char ch = latestToken().s.charAt(0);
            mulExpNode = new MulExpNode(parseUnaryExp(), mulExpNode, ch);// Parse multiplication/division/mod expressions
        }
        return mulExpNode;
    }

    // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public UnaryExpNode parseUnaryExp() {
        if (isUnaryOp()) {
            char unaryOp = currentToken().s.charAt(0);
            UnaryOpNode unaryOpNode = new UnaryOpNode(unaryOp);
            advance();
            UnaryExpNode unaryExp = parseUnaryExp();
            return new UUExp(unaryOpNode, unaryExp);
        }

        if (currentToken().type.equals("IDENFR")) {
            String ident = currentToken().s;  // 获取标识符 Ident
            advance();

            if (match("LPARENT")) {
                FuncRParamsNode funcRParamsNode = null;
                if (!currentToken().type.equals("RPARENT")) {
                    funcRParamsNode = parseFuncRParams();
                }
                match("RPARENT");
                return new IdentUExp(ident, funcRParamsNode);
            } else {
                pos--;
                return new PrimaryUExp(parsePrimaryExp());
            }

        }
        return new PrimaryUExp(parsePrimaryExp());
    }

    private boolean isUnaryOp() {
        return currentToken().type.equals("PLUS") || currentToken().type.equals("MINU") || currentToken().type.equals("NOT");
    }

    private FuncRParamsNode parseFuncRParams() {
        List<ExpNode> params = new ArrayList<>();
        params.add(parseExp());

        while (match("COMMA")) {
            params.add(parseExp());
        }

        return new FuncRParamsNode(params);
    }


    // Parse PrimaryExp → '(' Exp ')' | LVal | Number |Character
    private PrimaryExpNode parsePrimaryExp() {
        ExpNode expNode;
        if (match("LPARENT")) {
            expNode = parseExp();
            match("RPARENT");
            return new ParentExp(expNode);
        } else if (match("INTCON"))
            return new NumberExp(Integer.parseInt(latestToken().s));
        else if (match("CHRCON")) {
            return new CharExp(latestToken().s);
        } else
            return new LvalExp(parseLVal());
    }

    // Parse LVal → Ident ['[' Exp ']']
    private LValNode parseLVal() {
        String ident;
        ExpNode expNode = null;
        match("IDENFR");
        ident = latestToken().s;
        if (match("LBRACK")) {
            expNode = parseExp();
            match("RBRACK");
        }
        return new LValNode(ident, expNode);
    }

    private BTypeNode parseBType() {
        if (!match("INTTK") && !match("CHARTK"))
            return null;
        else
            return new BTypeNode(latestToken().s);
    }

    private boolean isFuncDef() {
        return (currentToken().type.equals("VOIDTK") || currentToken().type.equals("INTTK") || currentToken().type.equals("CHARTK")) && peekNextToken().type.equals("IDENFR") && Objects.requireNonNull(peekNextToken(2)).type.equals("LPARENT");
    }
}
package parser;

import error.Error;
import error.ErrorList;
import lexer.Token;
import lexer.TokenType;
import parser.node.*;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;

public class ParserAnalysis {
    ArrayList<Token> tokens;

    public void setTokens(ArrayList<Token> tokens) {
        this.tokens = tokens;
    }

    private int index = 0;
    private Token currentToken;
    private CompUnitNode rootNode;

    public CompUnitNode getRootNode() {
        return rootNode;
    }

    public void run() throws FileNotFoundException {
        currentToken = tokens.get(0);
        this.rootNode = compUnit();
        print();
    }
    public void print() throws FileNotFoundException {
        PrintStream origin = System.out;
        if (!ErrorList.getInstance().errors.isEmpty())
        {
            PrintStream out = new PrintStream("error.txt");
            System.setOut(out);
            ErrorList.getInstance().print();
        }
        else
        {
            PrintStream out = new PrintStream("parser.txt");
            System.setOut(out);
            this.rootNode.print();
        }
        System.setOut(origin);
    }
    private CompUnitNode compUnit() {
//        CompUnit -> {Decl} {FuncDef} MainFuncDef
        ArrayList<DeclNode> declNodes = new ArrayList<>();
        ArrayList<FuncDefNode> funcDefNodes = new ArrayList<>();
        MainFuncDefNode mainFuncDefNode;
        while (!tokens.get(index + 2).getType().equals(TokenType.LPARENT))
        {
            DeclNode declNode = decl();
            declNodes.add(declNode);
        }
        while (!tokens.get(index + 1).getType().equals(TokenType.MAIN))
        {
            FuncDefNode funcDefNode = funcDef();
            funcDefNodes.add(funcDefNode);
        }
        mainFuncDefNode = mainFuncDef();
        return new CompUnitNode(declNodes, funcDefNodes, mainFuncDefNode);
    }


    private DeclNode decl() {
//        Decl -> ConstDecl | VarDecl
        if (currentToken.getType().equals(TokenType.CONST))
        {
            ConstDeclNode constDeclNode = constDecl();
            return new DeclNode(constDeclNode, null);
        }
        else
        {
            VarDeclNode varDeclNode = varDecl();
            return new DeclNode(null, varDeclNode);
        }
    }

    private ConstDeclNode constDecl() {
        match(TokenType.CONST);
        Token constTK = tokens.get(index - 1);
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<ConstDefNode> constDefNodes = new ArrayList<>();
        BTypeNode bTypeNode = bType();
        constDefNodes.add(constDef());
        while (currentToken.getType().equals(TokenType.COMMA))
        {
            commas.add(match(TokenType.COMMA));
            constDefNodes.add(constDef());
        }
        Token semicnTK = match(TokenType.SEMICN);
        return new ConstDeclNode(bTypeNode, constDefNodes, commas, constTK, semicnTK);
    }

    private BTypeNode bType() {
        Token bTypeTK = currentToken;
        currentToken = tokens.get(++index);
        return new BTypeNode(bTypeTK);
    }

    private ConstDefNode constDef() {
        Token identTK = match(TokenType.IDENFR);
        Token lBrackTK = null;
        Token rBrackTK = null;
        Token assignTK;
        ConstExpNode constExpNode = null;
        if (currentToken.getType().equals(TokenType.LBRACK))
        {
            lBrackTK = match(TokenType.LBRACK);
            constExpNode = constExp();
            rBrackTK = match(TokenType.RBRACK);
        }
        assignTK = match(TokenType.ASSIGN);
        ConstInitValNode constInitValNode = constInitVal();
        return new ConstDefNode(identTK, lBrackTK, rBrackTK, constExpNode, assignTK, constInitValNode);
    }

    private ConstInitValNode constInitVal() {
        Token lBraceTK = null;
        Token rBraceTK = null;
        ArrayList<ConstExpNode> constExpNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        Token stringTK = null;
        if (currentToken.getType().equals(TokenType.LBRACE))
        {
            lBraceTK = match(TokenType.LBRACE);
            if (!currentToken.getType().equals(TokenType.RBRACE))
            {
                constExpNodes.add(constExp());
                while (currentToken.getType().equals(TokenType.COMMA))
                {
                    commas.add(match(TokenType.COMMA));
                    constExpNodes.add(constExp());
                }
            }
            rBraceTK = match(TokenType.RBRACE);
        }
        else if (currentToken.getType().equals(TokenType.STRCON))
        {
            stringTK = match(TokenType.STRCON);
        }
        else
        {
            constExpNodes.add(constExp());
        }
        return new ConstInitValNode(constExpNodes, lBraceTK, rBraceTK, commas, stringTK);
    }

    private VarDeclNode varDecl() {
        BTypeNode bTypeNode = bType();
        ArrayList<VarDefNode> varDefNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        Token semicnTK;
        varDefNodes.add(varDef());
        while (currentToken.getType().equals(TokenType.COMMA))
        {
            commas.add(match(TokenType.COMMA));
            varDefNodes.add(varDef());
        }
        semicnTK = match(TokenType.SEMICN);
        return new VarDeclNode(bTypeNode, varDefNodes, commas, semicnTK);
    }

    private VarDefNode varDef() {
        Token identTK = match(TokenType.IDENFR);
        Token lBrackTK = null;
        Token rBrackTK = null;
        ConstExpNode constExpNode = null;
        Token assignTK = null;
        InitValNode initValNode = null;
        if (currentToken.getType().equals(TokenType.LBRACK))
        {
            lBrackTK = match(TokenType.LBRACK);
            constExpNode = constExp();
            rBrackTK = match(TokenType.RBRACK);
        }
        if (currentToken.getType().equals(TokenType.ASSIGN))
        {
            assignTK = match(TokenType.ASSIGN);
            initValNode = initVal();
        }
        return new VarDefNode(identTK, lBrackTK, rBrackTK, constExpNode, assignTK, initValNode);
    }

    private InitValNode initVal() {
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        Token lBraceTK = null;
        ArrayList<Token> commas = new ArrayList<>();
        Token rBraceTK = null;
        Token stringTK = null;
        if (currentToken.getType().equals(TokenType.STRCON))
        {
            stringTK = match(TokenType.STRCON);
        }
        else if (currentToken.getType().equals(TokenType.LBRACE))
        {
            lBraceTK = match(TokenType.LBRACE);
            if (!currentToken.getType().equals(TokenType.RBRACE))
            {
                expNodes.add(exp());
                while (currentToken.getType().equals(TokenType.COMMA))
                {
                    commas.add(match(TokenType.COMMA));
                    expNodes.add(exp());
                }
            }
            rBraceTK = match(TokenType.RBRACE);
        }
        else
        {
            expNodes.add(exp());
        }
        return new InitValNode(expNodes, lBraceTK, commas, rBraceTK, stringTK);
    }

    private FuncDefNode funcDef() {
        FuncTypeNode funcTypeNode = funcType();
        Token identTK = match(TokenType.IDENFR);
        Token lParent = match(TokenType.LPARENT);
        FuncFParamsNode funcFParamNodes = null;
        if (!currentToken.getType().equals(TokenType.RPARENT))
        {
            funcFParamNodes = funcFParams();
        }
        Token rParent = match(TokenType.RPARENT);
        BlockNode blockNode = block();
        return new FuncDefNode(funcTypeNode, identTK, lParent, funcFParamNodes, rParent, blockNode);
    }

    private MainFuncDefNode mainFuncDef() {
        Token intTK = match(TokenType.INT);
        Token mainTK = match(TokenType.MAIN);
        Token lParent = match(TokenType.LPARENT);
        Token rParent = match(TokenType.RPARENT);
        BlockNode blockNode = block();
        return new MainFuncDefNode(intTK, mainTK, lParent, rParent, blockNode);
    }

    private FuncTypeNode funcType() {
        Token funcTypeTK = currentToken;
        currentToken = tokens.get(++index);
        return new FuncTypeNode(funcTypeTK);
    }

    private FuncFParamsNode funcFParams() {
        ArrayList<FuncFParamNode> funcFParamNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        funcFParamNodes.add(funcFParam());
        while (currentToken.getType().equals(TokenType.COMMA))
        {
            commas.add(match(TokenType.COMMA));
            funcFParamNodes.add(funcFParam());
        }
        return new FuncFParamsNode(funcFParamNodes, commas);
    }

    private FuncFParamNode funcFParam() {
        BTypeNode bTypeNode = bType();
        Token identTK = match(TokenType.IDENFR);
        Token lBrackTK = null;
        Token rBrackTK = null;
        if (currentToken.getType().equals(TokenType.LBRACK))
        {
            lBrackTK = match(TokenType.LBRACK);
            rBrackTK = match(TokenType.RBRACK);
        }
        return new FuncFParamNode(bTypeNode, identTK, lBrackTK, rBrackTK);
    }

    private BlockNode block() {
        Token lBrace = match(TokenType.LBRACE);
        ArrayList<BlockItemNode> blockItemNodes = new ArrayList<>();
        while (!currentToken.getType().equals(TokenType.RBRACE))
        {
            blockItemNodes.add(blocItem());
        }
        Token rBrace = match(TokenType.RBRACE);
        return new BlockNode(blockItemNodes, lBrace, rBrace);
    }

    private BlockItemNode blocItem() {
        DeclNode declNode = null;
        StmtNode stmtNode = null;
        if (currentToken.getType().equals(TokenType.CONST) || currentToken.getType().equals(TokenType.INT)
                || currentToken.getType().equals(TokenType.CHAR))
        {
            declNode = decl();
        }
        else
        {
            stmtNode = stmt();
        }
        return new BlockItemNode(declNode, stmtNode);
    }

    private StmtNode stmt() {
        /*
          Stmt â†’ LVal '=' Exp ';' // i
            | [Exp] ';' // i
            | Block
            | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
            | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            | 'break' ';' | 'continue' ';' // i
            | 'return' [Exp] ';' // i
            | LVal '=' 'getint''('')'';' // i j
            | LVal '=' 'getchar''('')'';' // i j
            | 'printf''('StringConst {','Exp}')'';' // i j
         */


        switch (currentToken.getType())
        {
            case LBRACE:
            {
                BlockNode blockNode = block();
                return new StmtNode(5, blockNode);
            }
            case IF:
            {
                Token ifTK = match(TokenType.IF);
                Token lParentTK = match(TokenType.LPARENT);
                CondNode condNode = cond();
                Token rParentTK = match(TokenType.RPARENT);
                StmtNode stmtNode1 = stmt();
                Token elseTK = null;
                StmtNode stmtNode2 = null;
                if (currentToken.getType().equals(TokenType.ELSE))
                {
                    elseTK = match(TokenType.ELSE);
                    stmtNode2 = stmt();
                }
                return new StmtNode(6, ifTK, lParentTK, rParentTK, condNode, stmtNode1, stmtNode2, elseTK);
            }
            case FOR:
            {
                Token forTK = match(TokenType.FOR);
                Token lBraceTK = match(TokenType.LPARENT);
                ForStmtNode forStmtNode1 = null, forStmtNode2 = null;
                CondNode condNode = null;
                Token semicnTK;
                if (!currentToken.getType().equals(TokenType.SEMICN))
                {
                    forStmtNode1 = forStmt();
                }
                match(TokenType.SEMICN);
                if (!currentToken.getType().equals(TokenType.SEMICN))
                {
                    condNode = cond();
                }
                semicnTK = match(TokenType.SEMICN);
                if (!currentToken.getType().equals(TokenType.RPARENT))
                {
                    forStmtNode2 = forStmt();
                }
                Token rBraceTK = match(TokenType.RPARENT);
                StmtNode stmtNode = stmt();
                return new StmtNode(7, forTK, semicnTK, lBraceTK, rBraceTK, condNode, forStmtNode1, forStmtNode2, stmtNode);
            }
            case BREAK:
            {
                Token breakTK = match(TokenType.BREAK);
                Token semicnTK = match(TokenType.SEMICN);
                return new StmtNode(8, breakTK, semicnTK);
            }
            case CONTINUE:
            {
                Token continueTK = match(TokenType.CONTINUE);
                Token semicnTK = match(TokenType.SEMICN);
                return new StmtNode(9, continueTK, semicnTK);
            }
            case RETURN:
            {
                Token returnTK = match(TokenType.RETURN);
                ArrayList<ExpNode> expNodes = new ArrayList<>();
                if (!currentToken.getType().equals(TokenType.SEMICN))
                {
                    expNodes.add(exp());
                }
                Token semicnTK = match(TokenType.SEMICN);
                return new StmtNode(10, returnTK, expNodes, semicnTK);
            }
            case PRINTF:
            {
                Token printTK = match(TokenType.PRINTF);
                Token lParentTK = match(TokenType.LPARENT);
                Token stringTK = match(TokenType.STRCON);
                ArrayList<Token> commas = new ArrayList<>();
                ArrayList<ExpNode> expNodes = new ArrayList<>();
                while (currentToken.getType().equals(TokenType.COMMA))
                {
                    commas.add(match(TokenType.COMMA));
                    expNodes.add(exp());
                }
                Token rParentTK = match(TokenType.RPARENT);
                Token semicnTK = match(TokenType.SEMICN);
                return new StmtNode(11, printTK, lParentTK, stringTK, commas, expNodes, rParentTK, semicnTK);
            }
            default:
                break;
        }
        for (int i = index; i < tokens.size() && tokens.get(i).getLineNum() == currentToken.getLineNum(); i++)
        {
            if (tokens.get(i).getType().equals(TokenType.ASSIGN))
            {
                LValNode lValNode = lVal();
                Token assignTK = match(TokenType.ASSIGN);
                if (currentToken.getType().equals(TokenType.GETINT))
                {
                    Token getintTK = match(TokenType.GETINT);
                    Token lParentTK = match(TokenType.LPARENT);
                    Token rParentTK = match(TokenType.RPARENT);
                    Token semicnTK = match(TokenType.SEMICN);
                    return new StmtNode(2, lValNode, assignTK, getintTK, lParentTK, rParentTK, semicnTK);
                }
                else if (currentToken.getType().equals(TokenType.GETCHAR))
                {
                    Token getcharTK = match(TokenType.GETCHAR);
                    Token lParentTK = match(TokenType.LPARENT);
                    Token rParentTK = match(TokenType.RPARENT);
                    Token semicnTK = match(TokenType.SEMICN);
                    return new StmtNode(2, lValNode, assignTK, getcharTK, lParentTK, rParentTK, semicnTK);
                }
                else
                {
                    ArrayList<ExpNode> expNodes = new ArrayList<>();
                    expNodes.add(exp());
                    Token semicnTK = match(TokenType.SEMICN);
                    return new StmtNode(1, lValNode, assignTK, expNodes, semicnTK);
                }
            }
        }
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        if (!currentToken.getType().equals(TokenType.SEMICN))
        {
            expNodes.add(exp());
        }
        Token semicnTK = match(TokenType.SEMICN);
        return new StmtNode(4, expNodes, semicnTK);
    }

    private ForStmtNode forStmt() {
        LValNode lValNode = lVal();
        Token assignTK = match(TokenType.ASSIGN);
        ExpNode expNode = exp();
        return new ForStmtNode(lValNode, assignTK, expNode);
    }

    private ExpNode exp() {
        AddExpNode addExpNode = addExp();
        return new ExpNode(addExpNode);
    }

    private CondNode cond() {
        LOrExpNode lOrExpNode = lOrExp();
        return new CondNode(lOrExpNode);
    }

    private LValNode lVal() {
        Token identTK = match(TokenType.IDENFR);
        Token lBrackTK = null, rBrackTK = null;
        ExpNode expNode = null;
        if (currentToken.getType().equals(TokenType.LBRACK))
        {
            lBrackTK = match(TokenType.LBRACK);
            expNode = exp();
            rBrackTK = match(TokenType.RBRACK);
        }
        return new LValNode(identTK, lBrackTK, rBrackTK, expNode);
    }

    private PrimaryExpNode primaryExp() {
        if (currentToken.getType().equals(TokenType.LPARENT))
        {
            Token lParentTK = match(TokenType.LPARENT);
            ExpNode expNode = exp();
            Token rParentTK = match(TokenType.RPARENT);
            return new PrimaryExpNode(1, lParentTK, rParentTK, expNode);
        }
        else if (currentToken.getType().equals(TokenType.INTCON))
        {
            NumberNode numberNode = number();
            return new PrimaryExpNode(3, numberNode);
        }
        else if (currentToken.getType().equals(TokenType.CHRCON))
        {
            CharacterNode characterNode = character();
            return new PrimaryExpNode(4, characterNode);
        }
        else
        {
            LValNode lValNode = lVal();
            return new PrimaryExpNode(2, lValNode);
        }
    }

    private NumberNode number() {
        Token intconTK = match(TokenType.INTCON);
        return new NumberNode(intconTK);
    }

    private CharacterNode character() {
        Token chrconTK = match(TokenType.CHRCON);
        return new CharacterNode(chrconTK);
    }

    private UnaryExpNode unaryExp() {
        if (currentToken.getType().equals(TokenType.PLUS) || currentToken.getType().equals(TokenType.MINU)
                || currentToken.getType().equals(TokenType.NOT))
        {
            UnaryOpNode unaryOpNode = unaryOp();
            UnaryExpNode unaryExpNode = unaryExp();
            return new UnaryExpNode(3, unaryOpNode, unaryExpNode);
        }
        else if (tokens.get(index + 1).getType().equals(TokenType.LPARENT))
        {
            Token identTK = match(TokenType.IDENFR);
            Token lParentTK = match(TokenType.LPARENT);
            FuncRParamsNode funcRParamsNode = null;
            if (!currentToken.getType().equals(TokenType.RPARENT))
            {
                funcRParamsNode = funcRParams();
            }
            Token rParentTK = match(TokenType.RPARENT);
            return new UnaryExpNode(2, identTK, lParentTK, rParentTK, funcRParamsNode);
        }
        else
        {
            PrimaryExpNode primaryExpNode = primaryExp();
            return new UnaryExpNode(1, primaryExpNode);
        }
    }

    private UnaryOpNode unaryOp() {
        Token unaryOpTK = currentToken;
        currentToken = tokens.get(++index);
        return new UnaryOpNode(unaryOpTK);
    }

    private FuncRParamsNode funcRParams() {
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        expNodes.add(exp());
        while (currentToken.getType().equals(TokenType.COMMA))
        {
            commas.add(match(TokenType.COMMA));
            expNodes.add(exp());
        }
        return new FuncRParamsNode(expNodes, commas);
    }

    private MulExpNode mulExp() {
        ArrayList<UnaryExpNode> unaryExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        unaryExpNodes.add(unaryExp());
        TokenType type = currentToken.getType();
        while (type.equals(TokenType.MULT) || type.equals(TokenType.DIV) || type.equals(TokenType.MOD))
        {
            operators.add(currentToken);
            currentToken = tokens.get(++index);
            unaryExpNodes.add(unaryExp());
            type = currentToken.getType();
        }
        return new MulExpNode(unaryExpNodes,operators);
    }
    private AddExpNode addExp() {
        ArrayList<MulExpNode> mulExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        mulExpNodes.add(mulExp());
        TokenType type = currentToken.getType();
        while (type.equals(TokenType.PLUS) || type.equals(TokenType.MINU))
        {
            operators.add(currentToken);
            currentToken = tokens.get(++index);
            mulExpNodes.add(mulExp());
            type = currentToken.getType();
        }
        return new AddExpNode(mulExpNodes,operators);
    }
    private RelExpNode relExp() {
        ArrayList<AddExpNode> addExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        addExpNodes.add(addExp());
        TokenType type = currentToken.getType();
        while (type.equals(TokenType.LSS) || type.equals(TokenType.LEQ) || type.equals(TokenType.GRE) || type.equals(TokenType.GEQ))
        {
            operators.add(currentToken);
            currentToken = tokens.get(++index);
            addExpNodes.add(addExp());
            type = currentToken.getType();
        }
        return new RelExpNode(addExpNodes,operators);
    }
    private EqExpNode eqExp() {
        ArrayList<RelExpNode> relExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        relExpNodes.add(relExp());
        TokenType type = currentToken.getType();
        while (type.equals(TokenType.EQL) || type.equals(TokenType.NEQ))
        {
            operators.add(currentToken);
            currentToken = tokens.get(++index);
            relExpNodes.add(relExp());
            type = currentToken.getType();
        }
        return new EqExpNode(relExpNodes,operators);
    }
    private LAndExpNode lAndExp() {
        ArrayList<EqExpNode> eqExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        eqExpNodes.add(eqExp());
        while (currentToken.getValue().equals("&") || currentToken.getValue().equals("&&"))
        {
            operators.add(match(TokenType.AND));
            eqExpNodes.add(eqExp());
        }
        return new LAndExpNode(eqExpNodes,operators);
    }
    private LOrExpNode lOrExp() {
        ArrayList<LAndExpNode> lAndExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        lAndExpNodes.add(lAndExp());
        while (currentToken.getValue().equals("|") || currentToken.getValue().equals("||"))
        {
            operators.add(match(TokenType.OR));
            lAndExpNodes.add(lAndExp());
        }
        return new LOrExpNode(lAndExpNodes,operators);
    }
    private ConstExpNode constExp() {
        AddExpNode addExpNode = addExp();
        return new ConstExpNode(addExpNode);
    }

    private Token match(TokenType expected) {
        if (currentToken.getType().equals(expected))
        {
            Token old = currentToken;
            if (index < tokens.size() - 1)
            {
                currentToken = tokens.get(++index);
            }
            return old;
        }
        else if (expected.equals(TokenType.SEMICN))
        {
            ErrorList.getInstance().errors.add(new Error(tokens.get(index - 1).getLineNum(),'i'));
            return new Token(TokenType.SEMICN,";",tokens.get(index - 1).getLineNum());
        }
        else if (expected.equals(TokenType.RBRACK))
        {
            ErrorList.getInstance().errors.add(new Error(tokens.get(index - 1).getLineNum(),'k'));
            return new Token(TokenType.LBRACK,"]",tokens.get(index - 1).getLineNum());
        }
        else if (expected.equals(TokenType.RPARENT))
        {
            ErrorList.getInstance().errors.add(new Error(tokens.get(index - 1).getLineNum(),'j'));
            return new Token(TokenType.RPARENT,")",tokens.get(index - 1).getLineNum());
        }
        return null;
    }
}

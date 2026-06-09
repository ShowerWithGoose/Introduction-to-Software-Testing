package Parser;

import AST.*;
import Lexer.Token;

import Error.*;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class ParserTokens {

    private List<Token> tokens;
    private int currentTokenIndex = 0;

    private ArrayList<error> errors;

    private errorMessage errorMessage;


    public ParserTokens(List<Token> tokens, errorMessage errorMessage) {
        this.tokens = tokens;
        this.errors = new ArrayList<>();
        this.errorMessage = errorMessage;
    }

    private Token currentToken() {
        return tokens.get(currentTokenIndex);
    }

    private void eat(String expectedType) {
        if (currentToken().getType().equals(expectedType)) {
            currentTokenIndex++;
        } else {
            if (expectedType.equals("SEMICN")) {
                errors.add(new error(null, LToken1().getLineNumber(), "i"));
            } else if (expectedType.equals("RPARENT")) {
                errors.add(new error(null, LToken1().getLineNumber(), "j"));
            } else if (expectedType.equals("RBRACK")){
                errors.add(new error(null, LToken1().getLineNumber(), "k"));
            }
        }
    }

    private Token LToken1() {
        if (currentTokenIndex - 1 >= 0) {
            return tokens.get(currentTokenIndex - 1);
        } else {
            return null;
        }
    }

    private Token LToken1(int i) {
        if (i - 1 >= 0) {
            return tokens.get(currentTokenIndex - 1 + i);
        } else {
            return null;
        }
    }

    public CompUnitNode parseCompUnit() {
        CompUnitNode root = new CompUnitNode();
        while(isDecl()) {
            root.addDecls(parseDecl());
        }
        while(isFuncDef() && !isMainFuncDef()) {
            root.addFuncDefs(parseFuncDef());
        }
        root.setMainFuncDef(parseMainFuncDef());
        errorMessage.addError(errors);
        return root;
    }

    private MainFuncDef parseMainFuncDef() {
        Token t = currentToken();
        eat("INTTK");
        Token t1 = currentToken();
        eat("MAINTK");
        eat("LPARENT");
        eat("RPARENT");
        BlockNode block = parseBlock();
        return new MainFuncDef(block);
    }

    private DeclNode parseDecl() {
        if (isConst()) {
            return new DeclNode(parseConstDecl());
        } else {
            return new DeclNode(parseVarDecl());
        }
    }

    private boolean isConst() {
        return currentToken().getType().equals("CONSTTK");
    }

    private ConstDeclNode parseConstDecl() {
        ArrayList<ConstDefNode> constDefs = new ArrayList<>();
        eat("CONSTTK");
        Token type = currentToken();
        eat(type.getType());
        constDefs.add(parseConstDef());
        while (currentToken().getType().equals("COMMA")) {
            eat("COMMA");
            constDefs.add(parseConstDef());
        }
        eat("SEMICN");
        return new ConstDeclNode(type, constDefs);
    }

    private ConstDefNode parseConstDef() {
        Token ident = currentToken();
        ConstExpNode constExpNode = null;
        ConstInitValNode constInitValNode = null;
        eat("IDENFR");
        if (currentToken().getType().equals("LBRACK")) {
            eat("LBRACK");
            constExpNode = parseConstExp();
            eat("RBRACK");
        }
        eat("ASSIGN");
        constInitValNode = parseConstInitVal();
        return new ConstDefNode(ident, constExpNode, constInitValNode);
    }

    private ConstExpNode parseConstExp() {
        return new ConstExpNode(parseAddExp());
    }

    private AddExpNode parseAddExp() {
        ArrayList<MulExpNode> addDefs = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        addDefs.add(parseMulExp());
        while (currentToken().getType().equals("PLUS") || currentToken().getType().equals("MINU")) {
            ops.add(currentToken());
            eat(currentToken().getType());
            addDefs.add(parseMulExp());
        }
        return new AddExpNode(addDefs, ops);
    }

    private MulExpNode parseMulExp() {
        ArrayList<UnaryExpNode> mulDefs = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        mulDefs.add(parseUnaryExp());
        while (currentToken().getType().equals("MULT") || currentToken().getType().equals("DIV") ||
                currentToken().getType().equals("MOD")) {
            ops.add(currentToken());
            eat(currentToken().getType());
            mulDefs.add(parseUnaryExp());
        }
        return new MulExpNode(mulDefs, ops);
    }

    private UnaryExpNode parseUnaryExp() {
        if (currentToken().getType().equals("PLUS") || currentToken().getType().equals("MINU") || currentToken().getType().equals("NOT")) {
            Token op = currentToken();
            eat(currentToken().getType());
            return new UnaryExpNode(new UnaryOpNode(op), parseUnaryExp());
        }
        else if (currentToken().getType().equals("IDENFR")) {
            Token varName = currentToken();
            if (Objects.requireNonNull(NextToken1()).getType().equals("LPARENT")) {
                eat("IDENFR");
                eat("LPARENT");
                FuncRNode funcRNode = null;
                if (BeginExp()) {
                    funcRNode = parseFuncRParams();
                    eat("RPARENT");
                } else {
                    funcRNode = new FuncRNode(new ArrayList<>());
                    eat("RPARENT");
                }
                return new UnaryExpNode(varName, funcRNode);
            } else {
                return new UnaryExpNode(parsePrimaryExp());
            }
        } else {
            return new UnaryExpNode(parsePrimaryExp());
        }
    }

    private PrimaryExp parsePrimaryExp() {
        if (currentToken().getType().equals("LPARENT")) {
            eat("LPARENT");
            ExprNode expr = parseExp();
            eat("RPARENT");
            return new PrimaryExp(expr);
        } else if (currentToken().getType().equals("IDENFR")) {
            return new PrimaryExp(parseLVal());
        } else if (currentToken().getType().equals("INTCON")) {
            return new PrimaryExp(parseNumber());
        } else {
            return new PrimaryExp(parseCharacter());
        }
    }

    private CharacterNode parseCharacter() {
        Token character = currentToken();
        eat("CHRCON");
        return new CharacterNode(character);
    }

    private NumberNode parseNumber() {
        Token number = currentToken();
        eat("INTCON");
        return new NumberNode(number);
    }

    private LValNode parseLVal() {
        Token id = currentToken();
        ExprNode expr = null;
        eat("IDENFR");
        if (currentToken().getType().equals("LBRACK")) {
            eat("LBRACK");
            expr = parseExp();
            eat("RBRACK");
        }
        return new LValNode(id, expr);
    }

    private FuncRNode parseFuncRParams() {
        ArrayList<ExprNode> exprs = new ArrayList<>();
        exprs.add(parseExp());
        while (currentToken().getType().equals("COMMA")) {
            eat("COMMA");
            exprs.add(parseExp());
        }
        return new FuncRNode(exprs);
    }

    private ConstInitValNode parseConstInitVal() {
        ArrayList<ConstExpNode> constExps = new ArrayList<>();
        StringConst stringConst = null;
        if (currentToken().getType().equals("LBRACE")) {
            eat("LBRACE");
            if (currentToken().getType().equals("RBRACE")) {
                eat("RBRACE");

                // 空的 {}
                return new ConstInitValNode(constExps, 2);
            } else {
                constExps.add(parseConstExp());
                while (currentToken().getType().equals("COMMA")) {
                    eat("COMMA");
                    constExps.add(parseConstExp());
                }
                eat("RBRACE");
                // 非空的{}
                return new ConstInitValNode(constExps, 2);
            }
        } else if (currentToken().getType().equals("STRCON")) {
            // stringConst
            stringConst =  parseStringConst();
            return new ConstInitValNode(stringConst);
        } else {
            // 只有一个ConstExp ，没有{}
            constExps.add(parseConstExp());
            return new ConstInitValNode(constExps, 1);
        }
    }

    private StringConst parseStringConst() {
        StringConst stringConst = new StringConst(currentToken());
        eat("STRCON");
        return stringConst;
    }

    private VarDeclNode parseVarDecl() {
        Token type = currentToken();
        ArrayList<VarDefNode> varDefs = new ArrayList<>();
        eat(type.getType()); // 处理类型（如 int 或 char）
        varDefs.add(parseVarDef());
        while (currentToken().getType().equals("COMMA")) {
            eat("COMMA");
            varDefs.add(parseVarDef());
        }
        eat("SEMICN");
        return new VarDeclNode(type, varDefs);
    }

    private VarDefNode parseVarDef() {
        Token ident = currentToken();
        ConstExpNode constExpNode = null;
        InitVal initVal = null;
        eat(currentToken().getType());
        if(currentToken().getType().equals("LBRACK")) {
            eat("LBRACK");
            constExpNode = parseConstExp();
            eat("RBRACK");
        }
        if (currentToken().getType().equals("ASSIGN")) {
            eat("ASSIGN");
            initVal = parseInitVal();
        }
        return new VarDefNode(ident, constExpNode, initVal);
    }

    private InitVal parseInitVal() {
        ArrayList<ExprNode> exps = new ArrayList<>();
        if (currentToken().getType().equals("LBRACE")) {
            eat("LBRACE");
            if (currentToken().getType().equals("RBRACE")) {
                eat("RBRACE");
                return new InitVal(exps, 1);
            } else {
                exps.add(parseExp());
                while (currentToken().getType().equals("COMMA")) {
                    eat("COMMA");
                    exps.add(parseExp());
                }
                eat("RBRACE");
                return new InitVal(exps, 1);
            }
        } else if (currentToken().getType().equals("STRCON")){
            return new InitVal(parseStringConst());
        } else {
            exps.add(parseExp());
            return new InitVal(exps, 2);
        }
    }

    private FuncDefNode parseFuncDef() {
        Token returnType = currentToken();
        FuncType type = new FuncType(returnType);
        eat(returnType.getType()); // 处理函数返回类型
        Token functionName = currentToken();
        eat("IDENFR");
        eat("LPARENT");
        if (currentToken().getType().equals("INTTK") || currentToken().getType().equals("CHARTK")) {
            FuncFParamsNode fpParams = parseFuncFParams();
            eat("RPARENT");
            BlockNode blockNode = parseBlock();
            return new FuncDefNode(type, functionName, fpParams , blockNode);
        } else {
            eat("RPARENT");
            BlockNode blockNode = parseBlock();
            return new FuncDefNode(type, functionName, null, blockNode);
        }
    }

    private FuncFParamsNode parseFuncFParams() {
        ArrayList<FuncFParamNode> params = new ArrayList<>();
        params.add(parseFuncFParam());
        while (currentToken().getType().equals("COMMA")) {
            eat("COMMA");
            params.add(parseFuncFParam());
        }
        return new FuncFParamsNode(params);
    }

    private FuncFParamNode parseFuncFParam() {
        boolean isArray = false;
        Token type = currentToken();
        eat(type.getType());
        Token ident = currentToken();
        eat("IDENFR");
        if (currentToken().getType().equals("LBRACK")) {
            eat("LBRACK");
            eat("RBRACK");
            isArray = true;
        }
        return new FuncFParamNode(type, ident, isArray);
    }

    private BlockNode parseBlock() {
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        eat("LBRACE");
        while (!currentToken().getType().equals("RBRACE")) {
            blockItems.add(parseBlockItem());
        }
        int endLine = currentToken().getLineNumber();
        eat("RBRACE");
        return new BlockNode(blockItems, endLine);
    }

    private BlockItem parseBlockItem() {
        if ((currentToken().getType().equals("INTTK")|| currentToken().getType().equals("CHARTK")) || currentToken().getType().equals("CONSTTK")) {
            return new BlockItem(parseDecl());
        } else {
            return new BlockItem(parseStmt());
        }
    }

    private int isLVal() {
        int flag = 0;
        if (NextToken(1).getToken().equals("=")) {
            flag = 1;
        } else if (NextToken(1).getToken().equals("(")) {
            flag = 2;
        } else if (NextToken(1).getToken().equals("[")) {
            int k = 1;
            while (NextToken(k).getToken().equals("[")) {
                k++;
                int level = 1;
                while (level > 0) {
                    if (NextToken(k).getToken().equals("[")) {
                        level++;
                    }
                    else if (NextToken(k).getToken().equals("]")) {
                        level--;
                    }
                    else if (NextToken(k).getToken().equals(";") || NextToken(k).getToken().equals("=")) {
                        break;
                    }
                    k++;
                }
            }
            if (NextToken(k).getToken().equals("=")) {
                flag = 1;
            } else {
                flag = 2;
            }
        } else {
            flag = 2;
        }
        return flag;

    }
    private StmtNode parseStmt() {
        if (currentToken().getType().equals("IDENFR")) {
            if (isLVal() == 1) {
//                System.out.println("isLVal");
                LValNode Lval = parseLVal();
                eat("ASSIGN");
                if (currentToken().getType().equals("GETINTTK")) {
                    eat("GETINTTK");
                    eat("LPARENT");
                    eat("RPARENT");
                    eat("SEMICN");
                    return new StmtNode(new GetIntStmt(Lval));
                } else if (currentToken().getType().equals("GETCHARTK")) {
                    eat("GETCHARTK");
                    eat("LPARENT");
                    eat("RPARENT");
                    eat("SEMICN");
                    return new StmtNode(new GetCharStmt(Lval));
                } else {
                    ExprNode e = parseExp();
                    eat("SEMICN");
                    return new StmtNode(new LValStmt(Lval, e));
                }
            } else {
//                System.out.println("noLval");
                ExprNode e = parseExp();
                eat("SEMICN");
                return new StmtNode(e);
            }

        } else if (currentToken().getType().equals("IFTK")) {
            eat("IFTK");
            eat("LPARENT");
            CondNode cond = parseCond();
            eat("RPARENT");
            StmtNode stmtNode = parseStmt();
            if (currentToken().getType().equals("ELSETK")) {
                eat("ELSETK");
                StmtNode stmtNode1 = parseStmt();
                return new StmtNode(new IfElseStmtNode(cond, stmtNode, stmtNode1));
            } else {
                return new StmtNode(new IfStmtNode(cond, stmtNode));
            }
        }
        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        else if (currentToken().getType().equals("FORTK")) {
            eat("FORTK");
            eat("LPARENT");
            ForStmt forStmt = null;
            if (!currentToken().getType().equals("SEMICN")) {
                forStmt = parseForStmt();
            }
            eat("SEMICN");
            CondNode condNode = null;
            if (!currentToken().getType().equals("SEMICN")) {
                condNode = parseCond();
            }
            eat("SEMICN");
            ForStmt forStmt1 = null;
            if (!currentToken().getType().equals("RPARENT")) {
                forStmt1 = parseForStmt();
            }
            eat("RPARENT");
            StmtNode stmtNode =  parseStmt();
            return new StmtNode(new ForNode(forStmt, condNode, forStmt1, stmtNode));
        } else if (currentToken().getType().equals("BREAKTK")) {
            Token t = currentToken();
            eat("BREAKTK");
            eat("SEMICN");
            return new StmtNode(new BreakStmt(t));
        } else if (currentToken().getType().equals("CONTINUETK")) {
            Token t = currentToken();
            eat("CONTINUETK");
            eat("SEMICN");
            return new StmtNode(new ContinueStmt(t));
        } else if (currentToken().getType().equals("RETURNTK")) {
            Token t = currentToken();
            eat("RETURNTK");
            ExprNode e = null;
            if (BeginExp()) {
                e = parseExp();
            }
            eat("SEMICN");
            return new StmtNode(new ReturnStmt(t, e));
        } else if (currentToken().getType().equals("PRINTFTK")) {
            int line = currentToken().getLineNumber();
            eat("PRINTFTK");
            eat("LPARENT");
            StringConst stringConst = parseStringConst();
            ArrayList<ExprNode> exps = new ArrayList<>();
            while (currentToken().getType().equals("COMMA")) {
                eat("COMMA");
                exps.add(parseExp());
            }
            eat("RPARENT");
            eat("SEMICN");
            return new StmtNode(new PrintfStmt(line, stringConst, exps));
        } else if (currentToken().getType().equals("SEMICN")){
            eat("SEMICN");
            return new StmtNode(new NullStmt());
        } else if (BeginExp()){
            ExprNode expr = parseExp();
            eat("SEMICN");
            return new StmtNode(expr);
        } else {
            return new StmtNode(parseBlock());
        }
    }

    private boolean BeginExp() {
        return currentToken().getType().equals("LPARENT") || currentToken().getType().equals("IDENFR") ||
                currentToken().getType().equals("MINU") ||
                currentToken().getType().equals("PLUS") || currentToken().getType().equals("NOT") ||
                currentToken().getType().equals("INTCON") ||
                currentToken().getType().equals("CHRCON") ;
    }

    private boolean BeginExp(int i) {
        return NextToken(i).getType().equals("LPARENT") || NextToken(i).getType().equals("IDENFR") ||
                NextToken(i).getType().equals("MINU") ||
                NextToken(i).getType().equals("PLUS") || NextToken(i).getType().equals("NOT") ||
                NextToken(i).getType().equals("INTCON") ||
                NextToken(i).getType().equals("CHRCON") ;
    }


    private ForStmt parseForStmt() {
        LValNode lValNode = parseLVal();
        eat("ASSIGN");
        ExprNode exprNode = parseExp();
        return new ForStmt(lValNode, exprNode);
    }

    private CondNode parseCond() {
        // 简化的条件解析
        LOrExpNode lOrExpNode = parseLOrExp();
        return new CondNode(lOrExpNode);
    }

    private LOrExpNode parseLOrExp() {
        ArrayList<LAndExpNode> lAndExpNodes = new ArrayList<>();
        lAndExpNodes.add(parseLAndExp());
        while (currentToken().getType().equals("OR")) {
            eat(currentToken().getType());
            lAndExpNodes.add(parseLAndExp());

        }
        return new LOrExpNode(lAndExpNodes);
    }

    private LAndExpNode parseLAndExp() {
        ArrayList<EqExpNode> eqExpNodes = new ArrayList<>();
        eqExpNodes.add(parseEqExp());
        while (currentToken().getType().equals("AND")) {

            eat("AND");
            eqExpNodes.add(parseEqExp());
        }
        return new LAndExpNode(eqExpNodes);
    }

    private EqExpNode parseEqExp() {
        ArrayList<RelExpNode> relExpNodes = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        relExpNodes.add(parseRelExp());
        if (currentToken().getType().equals("EQL") || currentToken().getType().equals("NEQ")) {
            Token op = currentToken();
            ops.add(op);
            eat(currentToken().getType());
            relExpNodes.add(parseRelExp());
        }
        return new EqExpNode(relExpNodes, ops);
    }

    private RelExpNode parseRelExp() {
        ArrayList<AddExpNode> relExpNodes = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        relExpNodes.add(parseAddExp());
        while (currentToken().getType().equals("LSS") || currentToken().getType().equals("LEQ") ||
                currentToken().getType().equals("GRE") || currentToken().getType().equals("GEQ")) {
            Token op = currentToken();
            ops.add(op);
            eat(currentToken().getType());
            relExpNodes.add(parseAddExp());

        }
        return new RelExpNode(relExpNodes, ops);
    }

    private ExprNode parseExp() {
        return new ExprNode(parseAddExp());
    }

    private boolean isDecl() {
        if (currentToken().getType().equals("CONSTTK")) {
            return true;
        }
        if ((currentToken().getType().equals("INTTK") || currentToken().getType().equals("CHARTK"))
                && !Objects.requireNonNull(NextToken2()).getType().equals("LPARENT")) {
            return true;
        }
        return false;
    }

    private Token NextToken2() {
        if (currentTokenIndex + 2 < tokens.size()) {
            return tokens.get(currentTokenIndex + 2);
        } else {
            return null;
        }
    }

    private boolean isFuncDef() {
        return (currentToken().getType().equals("INTTK") || currentToken().getType().equals("CHARTK") ||
                currentToken().getType().equals("VOIDTK")) && (Objects.requireNonNull(NextToken1()).getType().equals("IDENFR"));
    }

    private boolean isMainFuncDef() {
        return currentToken().getType().equals("INTTK") && Objects.requireNonNull(NextToken1()).getType().equals("MAINTK");
    }

    private Token NextToken1() {
        if (currentTokenIndex + 1 < tokens.size()) {
            return tokens.get(currentTokenIndex + 1);
        } else {
            return null;
        }
    }

    private Token NextToken(int i) {
        if (currentTokenIndex + i < tokens.size()) {
            return tokens.get(currentTokenIndex + i);
        } else {
            return null;
        }
    }

}

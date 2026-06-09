package front.parser;

import fault.Fault;
import front.lexer.Lexer;
import front.lexer.Token;
import front.lexer.TokenType;

import java.io.PrintStream;
import java.util.LinkedList;
import java.util.List;

/**
 * 语法分析类
 */
public class Parser {
    /**
     * 从 Lexer 获取的 token 列表
     */
    private List<Token> tokenList;
    /**
     * 当前的 token 索引
     */
    private int index;
    /**
     * 语法树
     */
    private V tree;
    /**
     * 构建过程中的指针
     */
    private V root;
    /**
     * 获取到的 Fault 单例
     */
    private Fault fault;

    /**
     * Parser 构造方法，将作用域限定为 private，从词法分析获取 token 列表
     */
    private Parser() {
        index = 0;
        tree = null;
        root = null;
        fault = Fault.getFault();
        tokenList = Lexer.getLexer().getTokenList();
    }

    /**
     * Parser 单例
     */
    private static Parser parser;

    /**
     * 获取 Parser 单例
     *
     * @return Parser 单例
     */
    public static Parser getParser() {
        if (parser == null) {
            if (Lexer.getLexer().getTokenList() != null) {
                parser = new Parser();
            }
        }
        return parser;
    }

    /**
     * 获取指定索引的 token
     *
     * @param index 索引
     * @return token / OUT_INDEX on out of index
     */
    public Token getToken(int index) {
        if (index < tokenList.size()) {
            return tokenList.get(index);
        } else {
            return Token.OUT_INDEX;
        }
    }

    /**
     * 检验 token 是否为某一类型
     *
     * @param tokenType 需要检验的类型
     * @return 是否为该类型
     */
    private boolean isTokenType(TokenType tokenType) {
        return getToken(index) != Token.OUT_INDEX && getToken(index).getTokenType() == tokenType;
    }

    /**
     * 断言当前 token 为某一类型并在树上添加节点（无论断言成功与否），若正确会自动读取下一个 token，若错误会添加错误信息
     *
     * @param tokenType 断言的类型
     */
    private void assertTokenType(TokenType tokenType) {
        if (getToken(index) != Token.OUT_INDEX) {
            root.addChild(new V(false, null, getToken(index)));
            if (isTokenType(tokenType)) {
                index++;
            } else {
                switch (tokenType) {
                    // -> 会自动 break;
                    case SEMICN -> fault.lackFen(getToken(index - 1).getLine());
                    case RPARENT -> fault.lackRXiao(getToken(index - 1).getLine());
                    case RBRACK -> fault.lackRZhong(getToken(index - 1).getLine());
                    default -> fault.otherInParse(getToken(index).getLine());
                }
            }
        }
    }

    /**
     * 当前 token 是不是在 Vt 的首字集中
     *
     * @param vnType Vt 类型
     * @return 是否在首字集中
     */
    private boolean inFirst(VnType vnType) {
        return vnType.inFirst(getToken(index)) || vnType == VnType.Stmt;
    }

    /**
     * 添加 Vn 子节点，并更新 root 到新的 Vt 子节点
     *
     * @param vnType Vn 子节点类型
     */
    private void addVn(VnType vnType) {
        if (tree == null) {
            tree = new V(true, new Vn(vnType), null);
            root = tree;
        } else {
            V child = new V(true, new Vn(vnType), null);
            root.addChild(child);
            root = child;
        }
    }

    /**
     * 回到父节点
     */
    private void toParent() {
        if (root.getParent() != null) {
            root = root.getParent();
        }
    }

    /*
    在确认 entry 和判断可选/循环子程序时使用 isTokenType 避免影响到 当前的 token，其余使用 assertTokenType
    对于不存在可选/循环子程序时（即子程序必须出现），错误应该由子程序检测，避免重复报错
    在所有的子程序开头都应该调用 addVn， 结束都应该调用 toParent
     */

    /**
     * CompUnit 子程序
     */
    private void compUnit() {
        addVn(VnType.CompUnit);
        while (getToken(index + 2).getTokenType() != TokenType.LPARENT) {
            decl();
        }
        while (getToken(index + 1).getTokenType() != TokenType.MAINTK) {
            funcDef();
        }
        mainFuncDef();
        toParent();
    }

    /**
     * Decl 子程序
     */
    private void decl() {
        addVn(VnType.Decl);
        if (inFirst(VnType.ConstDecl)) {
            constDecl();
        } else if (inFirst(VnType.VarDecl)) {
            varDecl();
        } else {
            fault.otherInParse(getToken(index).getLine());
        }
        toParent();
    }

    /**
     * ConstDecl 子程序
     */
    private void constDecl() {
        addVn(VnType.ConstDecl);
        assertTokenType(TokenType.CONSTTK);
        bType();
        constDef();
        while (isTokenType(TokenType.COMMA)) {
            assertTokenType(TokenType.COMMA);
            constDef();
        }
        assertTokenType(TokenType.SEMICN);
        toParent();
    }

    /**
     * BType 子程序
     */
    private void bType() {
        addVn(VnType.BType);
        if (isTokenType(TokenType.INTTK)) {
            assertTokenType(TokenType.INTTK);
        } else if (isTokenType(TokenType.CHARTK)) {
            assertTokenType(TokenType.CHARTK);
        } else {
            fault.otherInParse(getToken(index).getLine());
        }
        toParent();
    }

    /**
     * ConstDef 子程序
     */
    private void constDef() {
        addVn(VnType.ConstDef);
        assertTokenType(TokenType.IDENFR);
        if (isTokenType(TokenType.LBRACK)) {
            assertTokenType(TokenType.LBRACK);
            constExp();
            assertTokenType(TokenType.RBRACK);
        }
        assertTokenType(TokenType.ASSIGN);
        constInitVal();
        toParent();
    }

    /**
     * ConstInitVal 子程序
     */
    private void constInitVal() {
        addVn(VnType.ConstInitVal);
        if (inFirst(VnType.ConstExp)) {
            constExp();
        } else if (isTokenType(TokenType.LBRACE)) {
            assertTokenType(TokenType.LBRACE);
            if (inFirst(VnType.ConstExp)) {
                constExp();
                while (isTokenType(TokenType.COMMA)) {
                    assertTokenType(TokenType.COMMA);
                    constExp();
                }
            }
            assertTokenType(TokenType.RBRACE);
        } else if (isTokenType(TokenType.STRCON)) {
            assertTokenType(TokenType.STRCON);
        } else {
            fault.otherInParse(getToken(index).getLine());
        }
        toParent();
    }

    /**
     * VarDecl 子程序
     */
    private void varDecl() {
        addVn(VnType.VarDecl);
        bType();
        varDef();
        while (isTokenType(TokenType.COMMA)) {
            assertTokenType(TokenType.COMMA);
            varDef();
        }
        assertTokenType(TokenType.SEMICN);
        toParent();
    }

    /**
     * VarDef 子程序
     */
    private void varDef() {
        addVn(VnType.VarDef);
        assertTokenType(TokenType.IDENFR);
        if (isTokenType(TokenType.LBRACK)) {
            assertTokenType(TokenType.LBRACK);
            constExp();
            assertTokenType(TokenType.RBRACK);
        }
        if (isTokenType(TokenType.ASSIGN)) {
            assertTokenType(TokenType.ASSIGN);
            initVal();
        }
        toParent();
    }

    /**
     * InitVal 子程序
     */
    private void initVal() {
        addVn(VnType.InitVal);
        if (inFirst(VnType.Exp)) {
            exp();
        } else if (isTokenType(TokenType.LBRACE)) {
            assertTokenType(TokenType.LBRACE);
            if (inFirst(VnType.Exp)) {
                exp();
                while (isTokenType(TokenType.COMMA)) {
                    assertTokenType(TokenType.COMMA);
                    exp();
                }
            }
            assertTokenType(TokenType.RBRACE);
        } else if (isTokenType(TokenType.STRCON)) {
            assertTokenType(TokenType.STRCON);
        } else {
            fault.otherInParse(getToken(index).getLine());
        }
        toParent();
    }

    /**
     * FuncDef 子程序
     */
    private void funcDef() {
        addVn(VnType.FuncDef);
        funcType();
        assertTokenType(TokenType.IDENFR);
        assertTokenType(TokenType.LPARENT);
        if (inFirst(VnType.FuncFParams)) {
            funcFParams();
        }
        assertTokenType(TokenType.RPARENT);
        block();
        toParent();
    }

    /**
     * MainFuncDef 子程序
     */
    private void mainFuncDef() {
        addVn(VnType.MainFuncDef);
        assertTokenType(TokenType.INTTK);
        assertTokenType(TokenType.MAINTK);
        assertTokenType(TokenType.LPARENT);
        assertTokenType(TokenType.RPARENT);
        block();
        toParent();
    }

    /**
     * FuncType 子程序
     */
    private void funcType() {
        addVn(VnType.FuncType);
        if (isTokenType(TokenType.VOIDTK)) {
            assertTokenType(TokenType.VOIDTK);
        } else if (isTokenType(TokenType.INTTK)) {
            assertTokenType(TokenType.INTTK);
        } else if (isTokenType(TokenType.CHARTK)) {
            assertTokenType(TokenType.CHARTK);
        } else {
            fault.otherInParse(getToken(index).getLine());
        }
        toParent();
    }

    /**
     * FuncFParams 子程序
     */
    private void funcFParams() {
        addVn(VnType.FuncFParams);
        funcFParam();
        while (isTokenType(TokenType.COMMA)) {
            assertTokenType(TokenType.COMMA);
            funcFParam();
        }
        toParent();
    }

    /**
     * FuncFParam 子程序
     */
    private void funcFParam() {
        addVn(VnType.FuncFParam);
        bType();
        assertTokenType(TokenType.IDENFR);
        if (isTokenType(TokenType.LBRACK)) {
            assertTokenType(TokenType.LBRACK);
            assertTokenType(TokenType.RBRACK);
        }
        toParent();
    }

    /**
     * Block 子程序
     */
    private void block() {
        addVn(VnType.Block);
        assertTokenType(TokenType.LBRACE);
        while (inFirst(VnType.BlockItem)) {
            blockItem();
        }
        assertTokenType(TokenType.RBRACE);
        toParent();
    }

    /**
     * BlockItem 子程序
     */
    private void blockItem() {
        addVn(VnType.BlockItem);
        if (inFirst(VnType.Decl)) {
            decl();
        } else if (inFirst(VnType.Stmt)) {
            stmt();
        } else {
            fault.otherInParse(getToken(index).getLine());
        }
        toParent();
    }

    /**
     * Stmt 子程序                                                   |
     */
    /*
    Exp 的开头可能是 LVal，在获取 LVal 后通过判断下一个 token 是否为 ASSIGN 确认分支（需要重构树）
     */
    private void stmt() {
        addVn(VnType.Stmt);
        if (inFirst(VnType.LVal)) { // 包括 LVal '=' ... 和由 LVal 开头的 Exp
            int saveIndex = index; // 记录最初的 index 用于回溯
            lVal();
            // ==== 构造好了 root -> LVal
            if (isTokenType(TokenType.ASSIGN)) {
                // ==== 确认是 LVal '='
                assertTokenType(TokenType.ASSIGN);
                if (inFirst(VnType.Exp)) {
                    exp();
                } else if (isTokenType(TokenType.GETINTTK)) {
                    assertTokenType(TokenType.GETINTTK);
                    assertTokenType(TokenType.LPARENT);
                    assertTokenType(TokenType.RPARENT);
                } else if (isTokenType(TokenType.GETCHARTK)) {
                    assertTokenType(TokenType.GETCHARTK);
                    assertTokenType(TokenType.LPARENT);
                    assertTokenType(TokenType.RPARENT);
                } else {
                    fault.otherInParse(getToken(index).getLine());
                }
                assertTokenType(TokenType.SEMICN);
            } else {
                // ==== 确认了是 LVal 开头的 Exp ;
                root.removeLastChild(); // 移除 root -> LVal
                index = saveIndex; // 回溯
                if (inFirst(VnType.Exp)) {
                    exp();
                }
                assertTokenType(TokenType.SEMICN);
            }
        } else if (inFirst(VnType.Exp) || isTokenType(TokenType.SEMICN)) { // 不包括 LVal 开头的 [Exp] ';'
            if (inFirst(VnType.Exp)) {
                exp();
            }
            assertTokenType(TokenType.SEMICN);
        } else if (inFirst(VnType.Block)) {
            block();
        } else if (isTokenType(TokenType.IFTK)) {
            assertTokenType(TokenType.IFTK);
            assertTokenType(TokenType.LPARENT);
            cond();
            assertTokenType(TokenType.RPARENT);
            stmt();
            if (isTokenType(TokenType.ELSETK)) {
                assertTokenType(TokenType.ELSETK);
                stmt();
            }
        } else if (isTokenType(TokenType.FORTK)) {
            assertTokenType(TokenType.FORTK);
            assertTokenType(TokenType.LPARENT);
            if (inFirst(VnType.ForStmt)) {
                forStmt();
            }
            assertTokenType(TokenType.SEMICN);
            if (inFirst(VnType.Cond)) {
                cond();
            }
            assertTokenType(TokenType.SEMICN);
            if (inFirst(VnType.ForStmt)) {
                forStmt();
            }
            assertTokenType(TokenType.RPARENT);
            stmt();
        } else if (isTokenType(TokenType.BREAKTK)) {
            assertTokenType(TokenType.BREAKTK);
            assertTokenType(TokenType.SEMICN);
        } else if (isTokenType(TokenType.CONTINUETK)) {
            assertTokenType(TokenType.CONTINUETK);
            assertTokenType(TokenType.SEMICN);
        } else if (isTokenType(TokenType.RETURNTK)) {
            assertTokenType(TokenType.RETURNTK);
            if (inFirst(VnType.Exp)) {
                exp();
            }
            assertTokenType(TokenType.SEMICN);
        } else if (isTokenType(TokenType.PRINTFTK)) {
            assertTokenType(TokenType.PRINTFTK);
            assertTokenType(TokenType.LPARENT);
            assertTokenType(TokenType.STRCON);
            while (isTokenType(TokenType.COMMA)) {
                assertTokenType(TokenType.COMMA);
                exp();
            }
            assertTokenType(TokenType.RPARENT);
            assertTokenType(TokenType.SEMICN);
        } else {
            fault.lackFen(getToken(index - 1).getLine());
        }
        toParent();
    }

    /**
     * ForStmt 子程序
     */
    private void forStmt() {
        addVn(VnType.ForStmt);
        lVal();
        assertTokenType(TokenType.ASSIGN);
        exp();
        toParent();
    }

    /**
     * Exp 子程序
     */
    private void exp() {
        addVn(VnType.Exp);
        addExp();
        toParent();
    }

    /**
     * Cond 子程序
     */
    private void cond() {
        addVn(VnType.Cond);
        lOrExp();
        toParent();
    }

    /**
     * LVal 子程序
     */
    private void lVal() {
        addVn(VnType.LVal);
        assertTokenType(TokenType.IDENFR);
        if (isTokenType(TokenType.LBRACK)) {
            assertTokenType(TokenType.LBRACK);
            exp();
            assertTokenType(TokenType.RBRACK);
        }
        toParent();
    }

    /**
     * PrimaryExp 子程序
     */
    private void primaryExp() {
        addVn(VnType.PrimaryExp);
        if (isTokenType(TokenType.LPARENT)) {
            assertTokenType(TokenType.LPARENT);
            exp();
            assertTokenType(TokenType.RPARENT);
        } else if (inFirst(VnType.LVal)) {
            lVal();
        } else if (inFirst(VnType.Number)) {
            number();
        } else if (inFirst(VnType.Character)) {
            character();
        } else {
            fault.otherInParse(getToken(index).getLine());
        }
        toParent();
    }

    /**
     * Number 子程序
     */
    private void number() {
        addVn(VnType.Number);
        assertTokenType(TokenType.INTCON);
        toParent();
    }

    /**
     * Character 子程序
     */
    private void character() {
        addVn(VnType.Character);
        assertTokenType(TokenType.CHRCON);
        toParent();
    }

    /**
     * UnaryExp 子程序
     */
    /*
    PrimaryExp | Ident '(' [FuncRParams] ')' 都可能是 Ident 开头
    如果 Ident 后面是 '(' 为后者，反之为前者
     */
    private void unaryExp() {
        addVn(VnType.UnaryExp);
        if (isTokenType(TokenType.IDENFR) && tokenList.get(index + 1).getTokenType() == TokenType.LPARENT) {
            assertTokenType(TokenType.IDENFR);
            assertTokenType(TokenType.LPARENT);
            if (inFirst(VnType.FuncRParams)) {
                funcRParams();
            }
            assertTokenType(TokenType.RPARENT);
        } else if (inFirst(VnType.PrimaryExp)) {
            primaryExp();
        } else if (inFirst(VnType.UnaryOp)) {
            unaryOp();
            unaryExp();
        } else {
            fault.otherInParse(tokenList.get(index).getLine());
        }
        toParent();
    }

    /**
     * UnaryOp 子程序
     */
    private void unaryOp() {
        addVn(VnType.UnaryOp);
        if (isTokenType(TokenType.PLUS)) {
            assertTokenType(TokenType.PLUS);
        } else if (isTokenType(TokenType.MINU)) {
            assertTokenType(TokenType.MINU);
        } else if (isTokenType(TokenType.NOT)) {
            assertTokenType(TokenType.NOT);
        } else {
            fault.otherInParse(tokenList.get(index).getLine());
        }
        toParent();
    }

    /**
     * FuncRParams 子程序
     */
    private void funcRParams() {
        addVn(VnType.FuncRParams);
        exp();
        while (isTokenType(TokenType.COMMA)) {
            assertTokenType(TokenType.COMMA);
            exp();
        }
        toParent();
    }

    /*
    MulExp, AddExp, RelExp, EqExp, LAndExp, LOrExp 的文法存在左递归
    使用消除左递归的文法生成的语法树会压缩到一层，需要特殊处理恢复到所需的语法树结构
     */

    /**
     * 左递归文法恢复语法树结构辅助方法
     *
     * @param vnType        递归的 Vn 类型
     * @param vnTypeList    关键 Vn 列表（说明前面的是递归内容）
     * @param tokenTypeList 关键 Vt 列表（说明前面的是递归内容）
     */
    private void plain2tree(VnType vnType, List<VnType> vnTypeList, List<TokenType> tokenTypeList) {
        List<V> list = new LinkedList<>();
        for (V child : root.getChildren()) {
            if (child.inType(vnTypeList, tokenTypeList)) {
                V v = new V(true, new Vn(vnType), null);
                while (!list.isEmpty()) {
                    v.addChild(list.remove(0));
                }
                list.add(v);
            }
            list.add(child);
        }
        root.setChildren(list);
    }

    /**
     * MulExp 子程序
     */
    private void mulExp() {
        addVn(VnType.MulExp);
        unaryExp();
        while (isTokenType(TokenType.MULT) || isTokenType(TokenType.DIV) || isTokenType(TokenType.MOD)) {
            if (isTokenType(TokenType.MULT)) {
                assertTokenType(TokenType.MULT);
            } else if (isTokenType(TokenType.DIV)) {
                assertTokenType(TokenType.DIV);
            } else if (isTokenType(TokenType.MOD)) {
                assertTokenType(TokenType.MOD);
            } else {
                fault.otherInParse(tokenList.get(index).getLine());
            }
            unaryExp();
        }
        plain2tree(VnType.MulExp, null, List.of(TokenType.MULT, TokenType.DIV, TokenType.MOD));
        toParent();
    }

    /**
     * AddExp 子程序
     */
    private void addExp() {
        addVn(VnType.AddExp);
        mulExp();
        while (isTokenType(TokenType.PLUS) || isTokenType(TokenType.MINU)) {
            if (isTokenType(TokenType.PLUS)) {
                assertTokenType(TokenType.PLUS);
            } else if (isTokenType(TokenType.MINU)) {
                assertTokenType(TokenType.MINU);
            } else {
                fault.otherInParse(tokenList.get(index).getLine());
            }
            mulExp();
        }
        plain2tree(VnType.AddExp, null, List.of(TokenType.PLUS, TokenType.MINU));
        toParent();
    }

    /**
     * RelExp 子程序
     */
    private void relExp() {
        addVn(VnType.RelExp);
        addExp();
        while (isTokenType(TokenType.LSS) || isTokenType(TokenType.GRE) || isTokenType(TokenType.LEQ) || isTokenType(TokenType.GEQ)) {
            if (isTokenType(TokenType.LSS)) {
                assertTokenType(TokenType.LSS);
            } else if (isTokenType(TokenType.GRE)) {
                assertTokenType(TokenType.GRE);
            } else if (isTokenType(TokenType.LEQ)) {
                assertTokenType(TokenType.LEQ);
            } else if (isTokenType(TokenType.GEQ)) {
                assertTokenType(TokenType.GEQ);
            } else {
                fault.otherInParse(tokenList.get(index).getLine());
            }
            addExp();
        }
        plain2tree(VnType.RelExp, null, List.of(TokenType.LSS, TokenType.GRE, TokenType.LEQ, TokenType.GEQ));
        toParent();
    }

    /**
     * EqExp 子程序
     */
    private void eqExp() {
        addVn(VnType.EqExp);
        relExp();
        while (isTokenType(TokenType.EQL) || isTokenType(TokenType.NEQ)) {
            if (isTokenType(TokenType.EQL)) {
                assertTokenType(TokenType.EQL);
            } else if (isTokenType(TokenType.NEQ)) {
                assertTokenType(TokenType.NEQ);
            } else {
                fault.otherInParse(tokenList.get(index).getLine());
            }
            relExp();
        }
        plain2tree(VnType.EqExp, null, List.of(TokenType.EQL, TokenType.NEQ));
        toParent();
    }

    /**
     * LAndExp 子程序
     */
    private void lAndExp() {
        addVn(VnType.LAndExp);
        eqExp();
        while (isTokenType(TokenType.AND)) {
            assertTokenType(TokenType.AND);
            eqExp();
        }
        plain2tree(VnType.LAndExp, null, List.of(TokenType.AND));
        toParent();
    }

    /**
     * LOrExp 子程序
     */
    private void lOrExp() {
        addVn(VnType.LOrExp);
        lAndExp();
        while (isTokenType(TokenType.OR)) {
            assertTokenType(TokenType.OR);
            lAndExp();
        }
        plain2tree(VnType.LOrExp, null, List.of(TokenType.OR));
        toParent();
    }

    /**
     * ConstExp 子程序
     */
    private void constExp() {
        addVn(VnType.ConstExp);
        addExp();
        toParent();
    }

    /**
     * 执行语法分析
     */
    public void pass() {
        compUnit();
    }

    /**
     * 输出语法树的内容
     *
     * @param printStream 输出流
     */
    public void printTree(PrintStream printStream) {
        printStream.println(tree);
    }
}

package front.parser;

import fault.Fault;
import front.lexer.Lexer;
import front.lexer.Token;
import front.lexer.TokenType;

import java.io.FileReader;
import java.util.List;

/**
 * 语法分析类
 */
public class Parser {
    /**
     * 从 Lexer 获取的 token 列表
     */
    private final List<Token> tokenList = Lexer.getLexer().getTokenList();
    /**
     * 当前的 token 索引
     */
    private int index = 0;
    /**
     * 语法树
     */
    private V tree = null;
    /**
     * 构建过程中的指针
     */
    private V root = null;
    /**
     * 行计数器
     */
    private int line = 1;
    /**
     * 获取到的 Fault 单例
     */
    private Fault fault = Fault.getFault();

    /**
     * Parser 构造方法，将作用域限定为 private
     *
     * @param fileReader 输入流封装的 reader
     */
    private Parser(FileReader fileReader) {
    }

    /**
     * Parser 单例
     */
    private static Parser parser;

    /**
     * 初始化 Parser
     *
     * @param fileReader 输入流封装的 reader
     */
    public static void initParser(FileReader fileReader) {
        parser = new Parser(fileReader);
    }

    /**
     * 获取 Parser 单例
     *
     * @return Parser 单例
     */
    public static Parser getParser() {
        if (parser == null) {
            System.out.println("init parser first!!!");
        }
        return parser;
    }

    /**
     * 检验 token 是否为某一类型
     *
     * @param tokenType 需要检验的类型
     * @return 是否为该类型
     */
    private boolean isTokenType(TokenType tokenType) {
        return tokenList.get(index).getTokenType() == tokenType;
    }

    /**
     * 添加 Vn 子节点
     *
     * @param vnType Vn 子节点类型
     */
    private void addVn(VnType vnType) {
        if (tree == null) {
            tree = new V(true, new Vn(vnType), null);
            root = tree;
        } else {
            root.addChild(new V(true, new Vn(vnType), null));
        }
    }

    /**
     * 断言当前 token 为某一类型并在树上添加节点（无论断言成功与否），若正确会自动读取下一个 token，若错误会添加错误信息
     *
     * @param tokenType 断言的类型
     */
    private void assertTokenType(TokenType tokenType) {
        root.addChild(new V(false, null, tokenList.get(index)));
        if (isTokenType(tokenType)) {
            index++;
        } else {
            switch (tokenType) {
                // -> 会自动 break;
                case SEMICN -> fault.lackFen(line);
                case RPARENT -> fault.lackRXiao(line);
                case RBRACK -> fault.lackRZhong(line);
                default -> fault.otherInParse(line);
            }
        }
    }

    /*
    在确认 entry 和判断可选/循环子程序时使用 isTokenType 避免影响到 当前的 token，其余使用 assertTokenType 避免遗忘 nextToken
    对于不存在可选/循环子程序时（即子程序必须出现），错误应该由子程序检测，避免重复报错
    在所有的子程序开头都应该调用 addVn， 结束都应该返回父节点 root = getParent
     */

    /**
     * CompUnit 子程序
     */
    private void compUnit() {
        addVn(VnType.CompUnit);
    }

    /**
     * 通过预读判断 Decl （充分条件）
     */
    private boolean isDecl() {
        return false;
    }
    /**
     * Decl 子程序
     */

    /**
     * 通过预读判断 ConstDecl （充分条件）
     */

    /**
     * ConstDecl 子程序
     */

    /**
     * 通过预读判断 BType （充分条件）
     */

    /**
     * BType 子程序
     */

    /**
     * 通过预读判断 ConstDef （充分条件）
     */

    /**
     * ConstDef 子程序
     */

    /**
     * 通过预读判断 ConstInitVal （充分条件）
     */

    /**
     * ConstInitVal 子程序
     */

    /**
     * 通过预读判断 VarDecl （充分条件）
     */

    /**
     * VarDecl 子程序
     */

    /**
     * 通过预读判断 VarDef （充分条件）
     */

    /**
     * VarDef 子程序
     */

    /**
     * 通过预读判断 InitVal （充分条件）
     */

    /**
     * InitVal 子程序
     */

    /**
     * 通过预读判断 FuncDef （充分条件）
     */

    /**
     * FuncDef 子程序
     */

    /**
     * 通过预读判断 MainFuncDef （充分条件）
     */

    /**
     * MainFuncDef 子程序
     */

    /**
     * 通过预读判断 FuncType （充分条件）
     */

    /**
     * FuncType 子程序
     */

    /**
     * 通过预读判断 FuncFParams （充分条件）
     */

    /**
     * FuncFParams 子程序
     */

    /**
     * 通过预读判断 FuncFParam （充分条件）
     */

    /**
     * FuncFParam 子程序
     */

    /**
     * 通过预读判断 Block （充分条件）
     */

    /**
     * Block 子程序
     */

    /**
     * 通过预读判断 BlockItem （充分条件）
     */

    /**
     * BlockItem 子程序
     */

    /**
     * 通过预读判断 Stmt （充分条件）
     */

    /**
     * Stmt 子程序
     */

    /**
     * 通过预读判断 ForStmt （充分条件）
     */

    /**
     * ForStmt 子程序
     */

    /**
     * 通过预读判断 Exp （充分条件）
     */

    /**
     * Exp 子程序
     */

    /**
     * 通过预读判断 Cond （充分条件）
     */

    /**
     * Cond 子程序
     */

    /**
     * 通过预读判断 LVal （充分条件）
     */

    /**
     * LVal 子程序
     */

    /**
     * 通过预读判断 PrimaryExp （充分条件）
     */

    /**
     * PrimaryExp 子程序
     */

    /**
     * 通过预读判断 Number （充分条件）
     */

    /**
     * Number 子程序
     */

    /**
     * 通过预读判断 Character （充分条件）
     */

    /**
     * Character 子程序
     */

    /**
     * 通过预读判断 UnaryExp （充分条件）
     */

    /**
     * UnaryExp 子程序
     */

    /**
     * 通过预读判断 UnaryOp （充分条件）
     */

    /**
     * UnaryOp 子程序
     */

    /**
     * 通过预读判断 FuncRParams （充分条件）
     */

    /**
     * FuncRParams 子程序
     */

    /**
     * 通过预读判断 MulExp （充分条件）
     */

    /**
     * MulExp 子程序
     */

    /**
     * 通过预读判断 AddExp （充分条件）
     */

    /**
     * AddExp 子程序
     */

    /**
     * 通过预读判断 RelExp （充分条件）
     */

    /**
     * RelExp 子程序
     */

    /**
     * 通过预读判断 EqExp （充分条件）
     */

    /**
     * EqExp 子程序
     */

    /**
     * 通过预读判断 LAndExp （充分条件）
     */

    /**
     * LAndExp 子程序
     */

    /**
     * 通过预读判断 LOrExp （充分条件）
     */

    /**
     * LOrExp 子程序
     */

    /**
     * 通过预读判断 ConstExp （充分条件）
     */

    /**
     * ConstExp 子程序
     */
}

package frontend.parser.expression.unaryexp;

import frontend.lexer.TokenListIterator;

/**
 * UnaryExpOpParser <UnaryExp>Op子节点解析器类
 * <UnaryOp> <UnaryExp>
 */
public class UnaryExpOpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * unary <UnaryOp>
     * unaryExp <UnaryExp>，右递归
     */
    private TokenListIterator iterator;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExpOpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseUnaryExpOp()
     * 解析<UnaryExp>Op子节点方法
     * 依次调用<UnaryOp>、<UnaryExp>解析器
     * @return UnaryExpOp实例
     */
    public UnaryExpOp parseUnaryExpOp() {
        UnaryOpParser unaryOpParser = new UnaryOpParser(this.iterator);
        this.unaryOp = unaryOpParser.parseUnaryOp();
        UnaryExpParser unaryExpParser = new UnaryExpParser(this.iterator);
        this.unaryExp = unaryExpParser.parseUnaryExp();
        UnaryExpOp unaryExpOp = new UnaryExpOp(this.unaryOp, this.unaryExp);
        return unaryExpOp;
    }
}

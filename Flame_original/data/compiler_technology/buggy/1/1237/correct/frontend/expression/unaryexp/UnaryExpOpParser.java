package frontend.expression.unaryexp;

import frontend.TokenListIterator;

/**
 * 解析器: UnaryExpOp (单目运算表达式)
 * 对应文法: UnaryExp → UnaryOp UnaryExp
 *
 * 解析过程：
 * 1. 解析 UnaryOp (单目运算符)
 * 2. 解析后续的 UnaryExp (单目表达式)
 */
public class UnaryExpOpParser {
    private final TokenListIterator iterator;
    private UnaryOp unaryOp; // 单目运算符
    private UnaryExp unaryExp; // 单目表达式

    public UnaryExpOpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public UnaryExpOp parseUnaryExpOp() {
        // 解析 UnaryOp (单目运算符)
        UnaryOpParser unaryOpParser = new UnaryOpParser(this.iterator);
        this.unaryOp = unaryOpParser.parseUnaryOp();

        // 解析后续的 UnaryExp (单目表达式)
        UnaryExpParser unaryExpParser = new UnaryExpParser(this.iterator);
        this.unaryExp = unaryExpParser.parseUnaryExp();

        // 构建 UnaryExpOp 对象并返回
        return new UnaryExpOp(this.unaryOp, this.unaryExp);
    }
}

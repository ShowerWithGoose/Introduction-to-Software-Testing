package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

/**
 * UnaryOpParser 单目运算符解析器类
 * <UnaryOp> -> '+' | '-' | '!'
 */
public class UnaryOpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     */
    private TokenListIterator iterator;

    public UnaryOpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseUnaryOp()
     * 解析<UnaryOp>方法
     * 判断读入的单词是不是'+'，'-'，'!'三者之一
     * @return UnaryOp实例
     */
    public UnaryOp parseUnaryOp() {
        Token token = this.iterator.next();
        if (token.getTokenType().equals(TokenType.PLUS) ||
                token.getTokenType().equals(TokenType.MINU) ||
                token.getTokenType().equals(TokenType.NOT)) {
            UnaryOp unaryOp = new UnaryOp(token);
            return unaryOp;
        }else {
            System.out.println("EXPECT UNARYOP HERE");
            return null;
        }
    }
}

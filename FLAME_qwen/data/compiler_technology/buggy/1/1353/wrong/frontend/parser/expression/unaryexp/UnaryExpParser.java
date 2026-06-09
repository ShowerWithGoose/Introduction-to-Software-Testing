package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.primaryexp.PrimaryExpParser;

/**
 * UnaryExpParser 一元表达式解析器类
 * <AddExp> -> <PrimaryExp> | <Ident> '(' [<FuncRParams> ')' | <UnaryOp> <UnaryExp>
 */
public class UnaryExpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * unaryExpEle <UnaryExp>分支
     */
    private TokenListIterator iterator;
    private UnaryExpEle unaryExpEle = null;

    public UnaryExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseUnaryExp()
     * 解析一元表达式方法
     * 预读2个单词，分别调用三个预读判断方法进行判断
     * 若符合其中任何一个，则回退2个单词，调用对应的解析器，并创造子节点
     * @return UnaryExp实例
     */
    public UnaryExp parseUnaryExp() {
        Token first = this.iterator.next();
        Token second = this.iterator.next();
        if (isIdentFirst(first, second)) {
            this.iterator.unRead(2);
            UnaryExpFuncParser unaryExpFuncParser = new UnaryExpFuncParser(this.iterator);
            this.unaryExpEle = unaryExpFuncParser.parseUnaryExpFunc();
        } else if (isPrimaryExpFirst(first)) {
            this.iterator.unRead(2);
            PrimaryExpParser primaryExpParser = new PrimaryExpParser(this.iterator);
            this.unaryExpEle = primaryExpParser.parsePrimaryExp();
        } else if (isUnaryFirst(first)) {
            this.iterator.unRead(2);
            UnaryExpOpParser unaryExpOpParser = new UnaryExpOpParser(this.iterator);
            this.unaryExpEle = unaryExpOpParser.parseUnaryExpOp();
        }
        UnaryExp unaryExp = new UnaryExp(this.unaryExpEle);
        return unaryExp;
    }

    /**
     * isPrimaryExpFirst(Token first)
     * PrimaryExp预读检测方法
     * @param first 预读的第一个单词
     * @return 是否符合PrimaryExp的第一个单词
     */
    private boolean isPrimaryExpFirst(Token first) {
        return first.getTokenType().equals(TokenType.LPARENT) ||
                first.getTokenType().equals(TokenType.IDENFR) ||
                first.getTokenType().equals(TokenType.INTCON);
    }
    /**
     * isIdentFirst(Token first, Token second)
     * Ident预读检测方法
     * @param first,second 预读的前两个单词
     * @return 是否符合Ident和'('
     */
    private boolean isIdentFirst(Token first, Token second) {
        return first.getTokenType().equals(TokenType.IDENFR) &&
                second.getTokenType().equals(TokenType.LPARENT);
    }
    /**
     * isUnaryFirst(Token first)
     * Unary预读检测方法
     * @param first 预读的第一个单词
     * @return 是否符合UnaryOp
     */
    private boolean isUnaryFirst(Token first) {
        return first.getTokenType().equals(TokenType.PLUS) ||
                first.getTokenType().equals(TokenType.MINU) ||
                first.getTokenType().equals(TokenType.NOT);
    }
}

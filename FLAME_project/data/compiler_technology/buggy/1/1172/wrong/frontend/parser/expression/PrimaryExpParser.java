package frontend.parser.expression;

import frontend.SyntaxError.*;
import frontend.lexer.*;

/**
 * 解析基本表达式的解析器类。
 */
public class PrimaryExpParser {
    // Token 列表迭代器
    private TokenListIterator iterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param iterator TokenListIterator 对象
     */
    public PrimaryExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析基本表达式。
     *
     * @return 解析得到的 PrimaryExp 对象
     */
    public PrimaryExp parsePrimaryExp() {
        // 初始化变量
        Token leftParenToken = null;
        AddExp innerExpression = null;
        Token rightParenToken = null;
        Lval lValue = null;
        Token intConstToken = null;
        Token charConstToken = null;

        AddExpParser expressionParser = new AddExpParser(iterator);
        LvalParser lvalParser = new LvalParser(iterator);

        // 读取下一个 Token
        Token currentToken = iterator.readNextToken();
        if (currentToken.getType() == TokenType.LPARENT) {
            // 左括号表达式
            leftParenToken = currentToken;
            // 解析加法表达式
            innerExpression = expressionParser.parseAddExp();
            // 读取右括号 Token
            Token nextToken = iterator.readNextToken();
            if (nextToken.getType() == TokenType.RPARENT) {
                rightParenToken = nextToken;
            } else {
                // 缺少右括号，回退一个 Token 并记录错误
                iterator.unReadTokens(1);
                SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.j, leftParenToken.getLine());
            }
        } else if (currentToken.getType() == TokenType.INTCON || currentToken.getType() == TokenType.CHRCON) {
            // 常量
            if (currentToken.getType() == TokenType.INTCON) {
                intConstToken = currentToken;
            } else {
                charConstToken = currentToken;
            }
        } else {
            // 回退一个 Token，尝试解析左值
            iterator.unReadTokens(1);
            lValue = lvalParser.parseLval();
        }

        // 创建并返回 PrimaryExp 对象
        return new PrimaryExp(leftParenToken, innerExpression, rightParenToken, lValue, intConstToken, charConstToken);
    }
}

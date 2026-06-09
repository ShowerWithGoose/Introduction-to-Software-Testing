package frontend.parser.expression;

import frontend.SyntaxError.ErrorType;
import frontend.SyntaxError.SyntaxErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

/**
 * 解析左值（变量或数组元素）的解析器类。
 */
public class LvalParser {
    // Token 列表迭代器
    private TokenListIterator iterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param iterator TokenListIterator 对象
     */
    public LvalParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析左值。
     *
     * @return 解析得到的 Lval 对象，如果解析失败返回 null
     */
    public Lval parseLval() {
        // 初始化变量
        Token identifierToken = null;
        Token leftBracketToken = null;
        AddExp indexExpression = null;
        Token rightBracketToken = null;

        AddExpParser expressionParser = new AddExpParser(iterator);

        // 读取标识符 Token
        identifierToken = iterator.readNextToken();
        if (identifierToken.getType() != TokenType.IDENFR) {
            // 不是标识符，回退并返回 null
            iterator.unReadTokens(1);
            return null;
        }

        // 预读取下一个 Token
        Token nextToken = iterator.readNextToken();
        if (nextToken.getType() == TokenType.LBRACK) { // [
            // 是左中括号，可能是数组访问
            leftBracketToken = nextToken;
            // 解析下标表达式
            indexExpression = expressionParser.parseAddExp();
            // 读取下一个 Token
            Token followingToken = iterator.readNextToken();
            if (followingToken.getType() == TokenType.RBRACK) { // ]
                // 匹配到右中括号
                rightBracketToken = followingToken;
            } else {
                // 缺少右中括号，回退一个 Token并记录错误
                iterator.unReadTokens(1);
                SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.k, leftBracketToken.getLine());
            }
        } else {
            // 不是左中括号，回退一个 Token
            iterator.unReadTokens(1);
        }
        // 创建并返回 Lval 对象
        return new Lval(identifierToken, leftBracketToken, indexExpression, rightBracketToken);
    }

    /**
     * 尝试解析左值，不处理语法错误。
     *
     * @return 解析得到的 Lval 对象，如果解析失败返回 null
     */
    public Lval tryParseLval() {
        // 初始化变量
        Token identifierToken = null;
        Token leftBracketToken = null;
        AddExp indexExpression = null;
        Token rightBracketToken = null;

        AddExpParser expressionParser = new AddExpParser(iterator);

        // 读取标识符 Token
        identifierToken = iterator.readNextToken();
        if (identifierToken.getType() != TokenType.IDENFR) {
            // 不是标识符，回退并返回 null
            iterator.unReadTokens(1);
            return null;
        }

        // 预读取下一个 Token
        Token nextToken = iterator.readNextToken();
        if (nextToken.getType() == TokenType.LBRACK) { // [
            // 是左中括号，可能是数组访问
            leftBracketToken = nextToken;
            // 解析下标表达式
            indexExpression = expressionParser.parseAddExp();
            // 读取下一个 Token
            Token followingToken = iterator.readNextToken();
            if (followingToken.getType() == TokenType.RBRACK) { // ]
                // 匹配到右中括号
                rightBracketToken = followingToken;
            } else {
                // 缺少右中括号，回退一个 Token，但不处理错误
                iterator.unReadTokens(1);
            }
        } else {
            // 不是左中括号，回退一个 Token
            iterator.unReadTokens(1);
        }
        // 创建并返回 Lval 对象
        return new Lval(identifierToken, leftBracketToken, indexExpression, rightBracketToken);
    }
}

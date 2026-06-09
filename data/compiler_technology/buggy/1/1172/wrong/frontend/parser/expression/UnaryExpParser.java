package frontend.parser.expression;

import frontend.SyntaxError.*;
import frontend.lexer.*;
import frontend.parser.funcparas.*;

/**
 * 负责解析一元表达式的解析器类。
 */
public class UnaryExpParser {
    // Token 列表的迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator TokenListIterator 对象
     */
    public UnaryExpParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析一元表达式的方法。
     *
     * @return 解析得到的 UnaryExp 对象
     */
    public UnaryExp parseUnaryExp() {
        // 声明解析过程中需要的变量
        Token operatorToken = null;
        Token identifierToken = null;
        Token leftParenToken = null;
        Token rightParenToken = null;
        FuncRParams funcRParams = null;
        UnaryExp recursiveUnaryExp = null;
        PrimaryExp primaryExp = null;

        // 初始化子解析器
        FuncRParamsParser funcRParamsParser = new FuncRParamsParser(tokenIterator);
        PrimaryExpParser primaryExpParser = new PrimaryExpParser(tokenIterator);

        // 读取当前 Token
        Token currentToken = tokenIterator.readNextToken();

        // 判断当前 Token 是否为一元运算符
        if (isUnaryOperator(currentToken)) {
            // 当前 Token 是一元运算符
            operatorToken = currentToken;
            // 递归解析下一层一元表达式
            recursiveUnaryExp = parseUnaryExp();
            // 返回解析结果
            return new UnaryExp(operatorToken, primaryExp, recursiveUnaryExp,
                    identifierToken, leftParenToken, funcRParams, rightParenToken);
        } else {
            // 当前 Token 不是一元运算符，回退一个 Token
            tokenIterator.unReadTokens(1);
        }

        // 尝试解析函数调用或基本表达式
        currentToken = tokenIterator.readNextToken();
        if (currentToken.getType() == TokenType.IDENFR) {
            // 可能是函数调用
            Token nextToken = tokenIterator.readNextToken();
            if (nextToken.getType() == TokenType.LPARENT) {
                // 确认为函数调用
                identifierToken = currentToken;
                leftParenToken = nextToken;

                // 预读取下一个 Token，判断是否有函数实参
                Token lookaheadToken = tokenIterator.readNextToken();
                if (isExpressionStart(lookaheadToken)) {
                    // 有函数实参，回退一个 Token 并解析函数实参列表
                    tokenIterator.unReadTokens(1);
                    funcRParams = funcRParamsParser.parseFuncRParams();
                } else {
                    // 无函数实参，回退一个 Token
                    tokenIterator.unReadTokens(1);
                }

                // 读取右括号 Token
                Token closingToken = tokenIterator.readNextToken();
                if (closingToken.getType() == TokenType.RPARENT) {
                    rightParenToken = closingToken;
                } else {
                    // 缺少右括号，回退一个 Token 并记录错误
                    tokenIterator.unReadTokens(1);
                    SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.j, nextToken.getLine());
                }
            } else {
                // 非函数调用，回退 Tokens，解析为基本表达式
                tokenIterator.unReadTokens(2);
                primaryExp = primaryExpParser.parsePrimaryExp();
            }
        } else {
            // 非标识符，回退一个 Token，解析为基本表达式
            tokenIterator.unReadTokens(1);
            primaryExp = primaryExpParser.parsePrimaryExp();
        }

        // 返回解析结果
        return new UnaryExp(operatorToken, primaryExp, recursiveUnaryExp,
                identifierToken, leftParenToken, funcRParams, rightParenToken);
    }

    /**
     * 判断给定的 Token 是否为一元运算符。
     *
     * @param token 要判断的 Token
     * @return 如果是一元运算符，返回 true；否则返回 false
     */
    private boolean isUnaryOperator(Token token) {
        return token.getType() == TokenType.PLUS ||
                token.getType() == TokenType.MINU ||
                token.getType() == TokenType.NOT;
    }

    /**
     * 判断 Token 是否可以作为表达式的开始。
     *
     * @param token 要判断的 Token
     * @return 如果可以作为表达式的开始，返回 true；否则返回 false
     */
    private boolean isExpressionStart(Token token) {
        switch (token.getType()) {
            case IDENFR:
            case LPARENT:
            case INTCON:
            case CHRCON:
            case PLUS:
            case MINU:
            case NOT:
                return true;
            default:
                return false;
        }
    }
}

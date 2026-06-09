package frontend.parser.funcparas;

import frontend.SyntaxError.ErrorType;
import frontend.SyntaxError.SyntaxErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

/**
 * 解析函数形式参数的解析器类。
 */
public class FuncFParamParser {
    // Token 列表迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator TokenListIterator 对象
     */
    public FuncFParamParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析函数形式参数。
     *
     * @return 解析得到的 FuncFParam 对象
     */
    public FuncFParam parseFuncFParam() {
        // 读取基本类型 Token
        Token typeToken = tokenIterator.readNextToken();
        // 读取标识符 Token
        Token nameToken = tokenIterator.readNextToken();
        // 初始化中括号 Token
        Token leftBracketToken = null;
        Token rightBracketToken = null;

        // 预读取下一个 Token
        Token lookaheadToken = tokenIterator.readNextToken();

        switch (lookaheadToken.getType()) {
            case LBRACK:
                // 如果是左中括号，表示数组参数
                leftBracketToken = lookaheadToken;
                Token nextToken = tokenIterator.readNextToken();
                if (nextToken.getType() == TokenType.RBRACK) {
                    // 匹配到右中括号
                    rightBracketToken = nextToken;
                } else {
                    // 缺少右中括号，处理错误
                    rightBracketToken = handleMissingRightBracket(leftBracketToken);
                }
                break;
            default:
                // 不是左中括号，回退一个 Token
                tokenIterator.unReadTokens(1);
                break;
        }

        // 冗余代码：检查参数类型是否为 int，非必要的检查
        if (typeToken.getType() == TokenType.INTTK) {
            // 可以在这里添加特定的处理逻辑
        }

        // 创建并返回 FuncFParam 对象
        return new FuncFParam(typeToken, nameToken, leftBracketToken, rightBracketToken);
    }

    /**
     * 处理缺失右中括号的情况，记录错误并生成补全的右中括号 Token。
     *
     * @param leftBracketToken 左中括号 Token，用于获取错误行号
     * @return 补全的右中括号 Token
     */
    private Token handleMissingRightBracket(Token leftBracketToken) {
        // 回退一个 Token，因为刚刚读取的 Token 不是右中括号
        tokenIterator.unReadTokens(1);
        // 记录语法错误
        SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.k, leftBracketToken.getLine());
        // 返回一个补全的右中括号 Token
        return new Token(TokenType.RBRACK, "]", leftBracketToken.getLine());
    }
}

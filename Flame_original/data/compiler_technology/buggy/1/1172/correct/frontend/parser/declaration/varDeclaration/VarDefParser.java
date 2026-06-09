package frontend.parser.declaration.varDeclaration;

import frontend.SyntaxError.ErrorType;
import frontend.SyntaxError.SyntaxErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;

/**
 * 解析变量定义的解析器类。
 */
public class VarDefParser {
    // Token 列表迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public VarDefParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析变量定义。
     *
     * @return 解析得到的 VarDef 对象
     */
    public VarDef parseVarDef() {
        // 初始化变量
        Token identifierToken = tokenStream.readNextToken();
        Token leftBracketToken = null;
        ConstExp arraySizeExpression = null;
        Token rightBracketToken = null;
        Token assignToken = null;
        InitVal initialValue = null;

        // 初始化子解析器
        ConstExpParser constExpParser = new ConstExpParser(tokenStream);
        InitValParser initValParser = new InitValParser(tokenStream);

        // 解析可能的数组大小
        Token currentToken = tokenStream.readNextToken();
        if (currentToken.getType() == TokenType.LBRACK) {
            leftBracketToken = currentToken;
            // 解析常量表达式作为数组大小
            arraySizeExpression = constExpParser.parseConstExp();
            // 期待右中括号
            Token nextToken = tokenStream.readNextToken();
            if (nextToken.getType() == TokenType.RBRACK) {
                rightBracketToken = nextToken;
            } else {
                // 缺少右中括号，记录错误
                tokenStream.unReadTokens(1);
                rightBracketToken = new Token(TokenType.RBRACK, "]", currentToken.getLine());
                SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.k, currentToken.getLine());
            }
        } else {
            // 不是数组，回退一个 Token
            tokenStream.unReadTokens(1);
        }

        // 解析可能的初始化
        Token followingToken = tokenStream.readNextToken();
        if (followingToken.getType() == TokenType.ASSIGN) {
            assignToken = followingToken;
            initialValue = initValParser.parseInitVal();
        } else {
            // 没有初始化，回退一个 Token
            tokenStream.unReadTokens(1);
        }

        // 创建并返回 VarDef 对象
        return new VarDef(identifierToken, leftBracketToken, arraySizeExpression,
                rightBracketToken, assignToken, initialValue);
    }
}

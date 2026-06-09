package frontend.parser.declaration.constDeclaration;

import frontend.SyntaxError.ErrorType;
import frontend.SyntaxError.SyntaxErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;

/**
 * 解析常量定义的解析器类。
 */
public class ConstDefParser {
    // Token 列表的迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public ConstDefParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析常量定义。
     *
     * @return 解析得到的 ConstDef 对象
     */
    public ConstDef parseConstDef() {
        // 声明解析过程中需要的变量
        Token identifierToken = null;
        Token leftBracketToken = null;
        ConstExp arraySizeExp = null;
        Token rightBracketToken = null;
        Token assignToken = null;
        ConstInitVal constInitValue = null;

        // 初始化子解析器
        ConstExpParser constExpParser = new ConstExpParser(tokenStream);
        ConstInitValParser constInitValParser = new ConstInitValParser(tokenStream);

        // 读取标识符 Token
        Token currentToken = tokenStream.readNextToken();
        if (currentToken.getType() == TokenType.IDENFR) {
            identifierToken = currentToken;

            // 预读取下一个 Token
            Token nextToken = tokenStream.readNextToken();
            if (nextToken.getType() == TokenType.LBRACK) {
                // 解析数组大小
                leftBracketToken = nextToken;
                arraySizeExp = constExpParser.parseConstExp();

                // 读取右中括号 Token
                Token closingBracketToken = tokenStream.readNextToken();
                if (closingBracketToken.getType() == TokenType.RBRACK) {
                    rightBracketToken = closingBracketToken;
                } else {
                    // 缺少右中括号，回退一个 Token 并记录错误
                    tokenStream.unReadTokens(1);
                    rightBracketToken = new Token(TokenType.RBRACK, "]", currentToken.getLine());
                    SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.k, nextToken.getLine());
                }

                // 读取等号 Token
                assignToken = tokenStream.readNextToken();
                if (assignToken.getType() != TokenType.ASSIGN) {
                    throw new Error("Expected ASSIGN in ConstDef");
                }
            } else if (nextToken.getType() == TokenType.ASSIGN) {
                // 非数组常量定义
                assignToken = nextToken;
            } else {
                throw new Error("Expected LBRACK or ASSIGN in ConstDef");
            }

            // 解析常量初始化值
            constInitValue = constInitValParser.parseConstInitVal();

            // 创建并返回 ConstDef 对象
            return new ConstDef(identifierToken, leftBracketToken, arraySizeExp,
                    rightBracketToken, assignToken, constInitValue);
        } else {
            throw new Error("Expected IDENFR in ConstDef");
        }
    }
}

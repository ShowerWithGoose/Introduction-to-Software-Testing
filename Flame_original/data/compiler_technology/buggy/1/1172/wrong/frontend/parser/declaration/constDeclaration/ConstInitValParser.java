package frontend.parser.declaration.constDeclaration;

import frontend.SyntaxError.ErrorType;
import frontend.SyntaxError.SyntaxErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;

import java.util.LinkedList;

/**
 * 解析常量初始化值的解析器类。
 */
public class ConstInitValParser {
    // Token 列表的迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public ConstInitValParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析常量初始化值。
     *
     * @return 解析得到的 ConstInitVal 对象
     */
    public ConstInitVal parseConstInitVal() {
        // 声明解析过程中需要的变量
        LinkedList<ConstExp> constExpList = new LinkedList<>();
        LinkedList<Token> commaTokenList = new LinkedList<>();
        Token leftBraceToken = null;
        Token rightBraceToken = null;
        Token stringConstToken = null;

        // 初始化子解析器
        ConstExpParser constExpParser = new ConstExpParser(tokenStream);

        // 读取当前 Token
        Token currentToken = tokenStream.readNextToken();
        if (currentToken.getType() == TokenType.LBRACE) {
            // 数组形式的常量初始化
            leftBraceToken = currentToken;

            // 预读取下一个 Token
            Token nextToken = tokenStream.readNextToken();
            if (nextToken.getType() == TokenType.RBRACE) {
                // 空的数组初始化
                rightBraceToken = nextToken;
                return new ConstInitVal(constExpList, leftBraceToken, rightBraceToken, commaTokenList, stringConstToken);
            } else {
                // 回退一个 Token，继续解析
                tokenStream.unReadTokens(1);
            }

            // 解析第一个常量表达式
            ConstExp firstConstExp = constExpParser.parseConstExp();
            constExpList.add(firstConstExp);

            // 循环解析后续的常量表达式
            while (true) {
                Token separatorToken = tokenStream.readNextToken();
                if (separatorToken.getType() == TokenType.COMMA) {
                    // 添加逗号 Token
                    commaTokenList.add(separatorToken);
                    // 解析下一个常量表达式
                    ConstExp nextConstExp = constExpParser.parseConstExp();
                    constExpList.add(nextConstExp);
                } else if (separatorToken.getType() == TokenType.RBRACE) {
                    // 结束数组初始化
                    rightBraceToken = separatorToken;
                    break;
                } else {
                    // 遇到意外的 Token，抛出错误
                    throw new Error("Expected COMMA or RBRACE in ConstInitVal");
                }
            }
        } else if (currentToken.getType() == TokenType.STRCON) {
            // 字符串常量初始化
            stringConstToken = currentToken;
        } else {
            // 回退一个 Token，解析常量表达式
            tokenStream.unReadTokens(1);
            ConstExp constExp = constExpParser.parseConstExp();
            constExpList.add(constExp);
        }

        // 创建并返回 ConstInitVal 对象
        return new ConstInitVal(constExpList, leftBraceToken, rightBraceToken, commaTokenList, stringConstToken);
    }
}

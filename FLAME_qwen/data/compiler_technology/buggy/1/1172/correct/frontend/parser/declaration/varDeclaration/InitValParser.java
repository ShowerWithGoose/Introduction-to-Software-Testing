package frontend.parser.declaration.varDeclaration;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.AddExp;
import frontend.parser.expression.AddExpParser;

import java.util.LinkedList;

/**
 * 解析变量声明中的初始化值的解析器类。
 */
public class InitValParser {
    // Token 列表迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator TokenListIterator 对象
     */
    public InitValParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析初始化值。
     *
     * @return 解析得到的 InitVal 对象
     */
    public InitVal parseInitVal() {
        // 初始化变量
        LinkedList<AddExp> exprList = new LinkedList<>();
        LinkedList<Token> commaList = new LinkedList<>();
        Token leftBraceToken = null;
        Token rightBraceToken = null;
        Token stringConstToken = null;

        AddExpParser addExpParser = new AddExpParser(tokenIterator);

        // 读取下一个 Token
        Token currentToken = tokenIterator.readNextToken();

        switch (currentToken.getType()) {
            case STRCON:
                // 字符串常量初始化
                stringConstToken = currentToken;
                break;

            case LBRACE:
                // 大括号初始化（数组或结构体）
                leftBraceToken = currentToken;
                Token nextToken = tokenIterator.readNextToken();
                if (nextToken.getType() == TokenType.RBRACE) {
                    // 空初始化
                    rightBraceToken = nextToken;
                    return new InitVal(exprList, leftBraceToken, rightBraceToken, commaList, stringConstToken);
                } else {
                    // 回退一个 Token
                    tokenIterator.unReadTokens(1);
                }
                // 解析第一个表达式
                AddExp firstExpr = addExpParser.parseAddExp();
                exprList.add(firstExpr);
                // 解析逗号分隔的后续表达式
                while (true) {
                    Token separatorToken = tokenIterator.readNextToken();
                    if (separatorToken.getType() == TokenType.COMMA) {
                        commaList.add(separatorToken);
                        AddExp nextExpr = addExpParser.parseAddExp();
                        exprList.add(nextExpr);
                    } else if (separatorToken.getType() == TokenType.RBRACE) {
                        rightBraceToken = separatorToken;
                        break;
                    } else {
                        // 回退一个 Token并抛出错误
                        tokenIterator.unReadTokens(1);
                        throw new Error("Expected '}' in InitVal");
                    }
                }
                break;

            default:
                // 回退一个 Token并解析表达式
                tokenIterator.unReadTokens(1);
                AddExp expr = addExpParser.parseAddExp();
                exprList.add(expr);
                break;
        }

        // 创建并返回 InitVal 对象
        return new InitVal(exprList, leftBraceToken, rightBraceToken, commaList, stringConstToken);
    }
}

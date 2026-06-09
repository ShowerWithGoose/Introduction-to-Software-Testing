package frontend.parser.block;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.AddExp;
import frontend.parser.expression.AddExpParser;

import java.util.LinkedList;

/**
 * 解析关系表达式的解析器类。
 */
public class RelExpParser {
    // Token 列表迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public RelExpParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析关系表达式。
     *
     * @return 解析得到的 RelExp 对象
     */
    public RelExp parseRelExp() {
        // 初始化加法表达式解析器
        AddExpParser additiveExpParser = new AddExpParser(tokenStream);
        // 存储解析结果的列表
        LinkedList<AddExp> additiveExpList = new LinkedList<>();
        LinkedList<Token> relationOperatorList = new LinkedList<>();

        // 解析第一个加法表达式
        AddExp firstAddExp = additiveExpParser.parseAddExp();
        additiveExpList.add(firstAddExp);

        // 循环解析后续的关系操作符和加法表达式
        while (true) {
            Token operatorToken = tokenStream.readNextToken();
            TokenType tokenType = operatorToken.getType();
            if (tokenType == TokenType.LSS || tokenType == TokenType.LEQ ||
                    tokenType == TokenType.GRE || tokenType == TokenType.GEQ) {
                // 添加关系操作符
                relationOperatorList.add(operatorToken);
                // 解析下一个加法表达式
                AddExp nextAddExp = additiveExpParser.parseAddExp();
                additiveExpList.add(nextAddExp);
            } else {
                // 非关系操作符，回退一个 Token，结束循环
                tokenStream.unReadTokens(1);
                break;
            }
        }

        // 创建并返回 RelExp 对象
        return new RelExp(additiveExpList, relationOperatorList);
    }
}

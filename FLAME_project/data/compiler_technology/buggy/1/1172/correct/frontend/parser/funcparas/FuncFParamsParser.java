package frontend.parser.funcparas;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.LinkedList;

/**
 * 解析函数形式参数列表的解析器类。
 */
public class FuncFParamsParser {
    // Token 列表迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator TokenListIterator 对象
     */
    public FuncFParamsParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析函数形式参数列表。
     *
     * @return 解析得到的 FuncFParams 对象
     */
    public FuncFParams parseFuncFParams() {
        // 使用 LinkedList 存储参数和逗号
        LinkedList<FuncFParam> paramList = new LinkedList<>();
        LinkedList<Token> separatorTokens = new LinkedList<>();

        FuncFParamParser paramParser = new FuncFParamParser(tokenIterator);

        // 解析第一个参数
        FuncFParam firstParam = paramParser.parseFuncFParam();
        paramList.add(firstParam);

        // 循环解析后续参数
        while (true) {
            Token nextToken = tokenIterator.readNextToken();
            if (nextToken.getType() == TokenType.COMMA) {
                // 添加逗号 Token
                separatorTokens.add(nextToken);
                // 解析下一个参数
                FuncFParam nextParam = paramParser.parseFuncFParam();
                paramList.add(nextParam);
            } else {
                // 回退一个 Token，因为不是逗号
                tokenIterator.unReadTokens(1);
                break;
            }
        }

        // 冗余代码：检查参数列表是否为空
        if (paramList.isEmpty()) {
            System.err.println("Error: Function parameters cannot be empty.");
        }

        // 创建并返回 FuncFParams 对象
        return new FuncFParams(paramList, separatorTokens);
    }
}

package frontend.parser.block;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.AddExp;
import frontend.parser.expression.AddExpParser;
import frontend.parser.expression.Lval;
import frontend.parser.expression.LvalParser;

/**
 * 解析 for 语句的解析器类。
 */
public class ForStmtParser {
    // Token 列表迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public ForStmtParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析 for 语句。
     *
     * @return 解析得到的 ForStmt 对象
     */
    public ForStmt parseForStmt() {
        // 初始化变量
        Lval loopVariable = null;
        Token assignToken = null;
        AddExp expression = null;

        // 初始化子解析器
        LvalParser lvalParser = new LvalParser(tokenStream);
        AddExpParser addExpParser = new AddExpParser(tokenStream);

        // 读取下一个 Token
        Token currentToken = tokenStream.readNextToken();
        if (currentToken.getType() == TokenType.IDENFR) {
            // 回退一个 Token，开始解析左值
            tokenStream.unReadTokens(1);
            loopVariable = lvalParser.parseLval();
            // 读取赋值号 Token
            assignToken = tokenStream.readNextToken();
            if (assignToken.getType() != TokenType.ASSIGN) {
                throw new Error("Expected '=' in ForStmt");
            }
            // 解析表达式
            expression = addExpParser.parseAddExp();
            // 创建并返回 ForStmt 对象
            return new ForStmt(loopVariable, assignToken, expression);
        } else {
            // 非法的 for 语句，回退一个 Token，返回 null
            tokenStream.unReadTokens(1);
            return null;
        }
    }
}

package frontend.expression.multiexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import java.util.ArrayList;

/**
 * 解析器: LOrExp (逻辑或表达式)
 * 对应文法: LOrExp → LAndExp { '||' LAndExp }
 *
 * 解析逻辑或表达式 (LOrExp)，由一个或多个逻辑与表达式 (LAndExp) 通过 '||' 连接。
 */
public class LOrExpParser {
    private final TokenListIterator iterator;
    private LAndExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<LAndExp> operands = new ArrayList<>();

    public LOrExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public LOrExp parseLOrExp() {
        // 初始化操作数和操作符的列表
        operands = new ArrayList<>();
        operators = new ArrayList<>();

        // 解析第一个 LAndExp
        LAndExpParser landExpParser = new LAndExpParser(this.iterator);
        first = landExpParser.parseLAndExp();

        // 检查是否有 '||' 操作符并解析后续的 LAndExp
        Token token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.OR)) { // '||'
            operators.add(token);
            operands.add(landExpParser.parseLAndExp());
            token = this.iterator.readNextToken();
        }

        // 回退最后一个不匹配的 Token
        this.iterator.unReadToken(1);

        // 创建并返回 LOrExp 对象
        return new LOrExp(first, operators, operands);
    }
}

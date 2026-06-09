package frontend.expression.multiexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import java.util.ArrayList;

/**
 * 解析器: LAndExp (逻辑与表达式)
 * 对应文法: LAndExp → EqExp { '&&' EqExp }
 *
 * 解析逻辑与表达式 (LAndExp)，由一个或多个相等性表达式 (EqExp) 通过 '&&' 连接。
 */
public class LAndExpParser {
    private final TokenListIterator iterator;
    private EqExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<EqExp> operands = new ArrayList<>();

    public LAndExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public LAndExp parseLAndExp() {
        // 初始化操作数和操作符的列表
        operands = new ArrayList<>();
        operators = new ArrayList<>();

        // 解析第一个 EqExp
        EqExpParser eqExpParser = new EqExpParser(this.iterator);
        first = eqExpParser.parseEqExp();

        // 检查是否有 '&&' 操作符并解析后续的 EqExp
        Token token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.AND)) { // '&&'
            operators.add(token);
            operands.add(eqExpParser.parseEqExp());
            token = this.iterator.readNextToken();
        }

        // 回退最后一个不匹配的 Token
        this.iterator.unReadToken(1);

        // 创建并返回 LAndExp 对象
        return new LAndExp(first, operators, operands);
    }
}

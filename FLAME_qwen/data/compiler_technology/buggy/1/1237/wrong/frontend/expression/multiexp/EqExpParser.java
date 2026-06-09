package frontend.expression.multiexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import java.util.ArrayList;

/**
 * 解析器: EqExp (相等性表达式)
 * 对应文法: EqExp → RelExp { ('==' | '!=') RelExp }
 *
 * 解析相等性表达式 (EqExp)，由一个或多个关系表达式 (RelExp) 通过 '==' 或 '!=' 连接。
 */
public class EqExpParser {
    private final TokenListIterator iterator;
    private RelExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<RelExp> operands = new ArrayList<>();

    public EqExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public EqExp parseEqExp() {
        // 初始化操作数和操作符的列表
        operands = new ArrayList<>();
        operators = new ArrayList<>();

        // 解析第一个 RelExp
        RelExpParser relExpParser = new RelExpParser(this.iterator);
        first = relExpParser.parseRelExp();

        // 检查是否有 '==' 或 '!=' 操作符并解析后续的 RelExp
        Token token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.EQL) || token.getType().equals(TokenType.NEQ)) { // '==' 或 '!='
            operators.add(token);
            operands.add(relExpParser.parseRelExp());
            token = this.iterator.readNextToken();
        }

        // 回退最后一个不匹配的 Token
        this.iterator.unReadToken(1);

        // 创建并返回 EqExp 对象
        return new EqExp(first, operators, operands);
    }
}

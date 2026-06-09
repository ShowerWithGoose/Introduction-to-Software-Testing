package frontend.expression.multiexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import java.util.ArrayList;

/**
 * 解析器: RelExp (关系表达式)
 * 对应文法: RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp }
 *
 * 解析关系表达式 (RelExp)，由一个或多个加减表达式 (AddExp) 通过 '<', '>', '<=', '>=' 连接。
 */
public class RelExpParser {
    private final TokenListIterator iterator;
    private AddExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<AddExp> operands = new ArrayList<>();

    public RelExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public RelExp parseRelExp() {
        // 初始化操作数和操作符的列表
        operands = new ArrayList<>();
        operators = new ArrayList<>();

        // 解析第一个 AddExp
        AddExpParser addExpParser = new AddExpParser(this.iterator);
        first = addExpParser.parseAddExp();

        // 检查是否有关系运算符并解析后续的 AddExp
        Token token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.LSS) || // '<'
                token.getType().equals(TokenType.GRE) || // '>'
                token.getType().equals(TokenType.LEQ) || // '<='
                token.getType().equals(TokenType.GEQ)) { // '>='
            operators.add(token);
            operands.add(addExpParser.parseAddExp());
            token = this.iterator.readNextToken();
        }

        // 回退最后一个不匹配的 Token
        this.iterator.unReadToken(1);

        // 创建并返回 RelExp 对象
        return new RelExp(first, operators, operands);
    }
}

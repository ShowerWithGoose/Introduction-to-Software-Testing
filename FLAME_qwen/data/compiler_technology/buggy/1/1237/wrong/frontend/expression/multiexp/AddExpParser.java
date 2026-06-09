package frontend.expression.multiexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import java.util.ArrayList;

/**
 * 解析器: AddExp (加减表达式)
 * 对应文法: AddExp → MulExp { ('+' | '-') MulExp }
 *
 * 解析加减表达式 (AddExp)，由一个或多个乘除表达式 (MulExp) 通过 '+' 或 '-' 连接。
 */
public class AddExpParser {
    private final TokenListIterator iterator;
    private MulExp first = null;
    private ArrayList<Token> operators = new ArrayList<>(); // '+' '-'
    private ArrayList<MulExp> operands = new ArrayList<>();

    public AddExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public AddExp parseAddExp() {
        // 初始化操作数和操作符的列表
        operands = new ArrayList<>();
        operators = new ArrayList<>();

        // 解析第一个 MulExp
        MulExpParser mulExpParser = new MulExpParser(this.iterator);
        first = mulExpParser.parseMulExp();

        // 检查是否有 '+' 或 '-' 操作符并解析后续的 MulExp
        Token token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.PLUS) || token.getType().equals(TokenType.MINU)) {
            operators.add(token);
            operands.add(mulExpParser.parseMulExp());
            token = this.iterator.readNextToken();
        }

        // 回退最后一个不匹配的 Token
        this.iterator.unReadToken(1);

        // 创建并返回 AddExp 对象
        return new AddExp(first, operators, operands);
    }
}

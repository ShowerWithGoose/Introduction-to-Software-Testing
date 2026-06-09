package frontend.expression.multiexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.unaryexp.UnaryExpParser;
import frontend.expression.unaryexp.UnaryExp;
import java.util.ArrayList;

/**
 * 解析器: MulExp (乘除模表达式)
 * 对应文法: MulExp → UnaryExp { ('*' | '/' | '%') UnaryExp }
 *
 * 解析乘除模表达式 (MulExp)，由一个或多个一元表达式 (UnaryExp) 通过 '*', '/', '%' 连接。
 */
public class MulExpParser {
    private final TokenListIterator iterator;
    private UnaryExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<UnaryExp> operands = new ArrayList<>();

    public MulExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public MulExp parseMulExp() {
        // 初始化操作数和操作符的列表
        operators = new ArrayList<>();
        operands = new ArrayList<>();

        // 解析第一个 UnaryExp
        UnaryExpParser unaryExpParser = new UnaryExpParser(this.iterator);
        first = unaryExpParser.parseUnaryExp();

        // 检查是否有 '*'、'/' 或 '%' 操作符并解析后续的 UnaryExp
        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.MULT) || // '*'
                token.getType().equals(TokenType.DIV) || // '/'
                token.getType().equals(TokenType.MOD)) { // '%'
            operators.add(token);
            operands.add(unaryExpParser.parseUnaryExp());
            token = iterator.readNextToken();
        }

        // 回退最后一个不匹配的 Token
        iterator.unReadToken(1);

        // 创建并返回 MulExp 对象
        return new MulExp(first, operators, operands);
    }
}

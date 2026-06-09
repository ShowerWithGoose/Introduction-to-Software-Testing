package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

/**
 * AddExpParser 加减表达式解析器类
 * <AddExp> -> <MulExp> { ('+' | '-') <MulExp> }
 * n个<MulExp>乘除模表达式用'+'或'-'相连
 */
public class AddExpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * first 首个<MulExp>乘除模表达式
     * operators 操作符子节点表
     * operands <MulExp>子节点表
     */
    private TokenListIterator iterator;
    private MulExp first = null;
    private ArrayList<Token> operators = new ArrayList<>(); // '+' '-'
    private ArrayList<MulExp> operands = new ArrayList<>();

    public AddExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseAddExp()
     * 解析加减表达式方法
     * 先读入一个MulExp，并解析
     * 若读入2个操作符之一，则加入operators
     * 调用解析后续的MulExp
     * 直至无法读入正确的操作符后，创建AddExp实例并返回
     * @return AddExp实例
     */
    public AddExp parseAddExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        MulExpParser mulExpParser = new MulExpParser(this.iterator);
        this.first = mulExpParser.parseMulExp();
        Token token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.PLUS) ||
                token.getTokenType().equals(TokenType.MINU)) {
            this.operators.add(token);
            this.operands.add(mulExpParser.parseMulExp());
            token = this.iterator.next();
        }
        this.iterator.unRead(1);
        AddExp addExp = new AddExp(this.first, this.operators, this.operands);
        return addExp;
    }
}

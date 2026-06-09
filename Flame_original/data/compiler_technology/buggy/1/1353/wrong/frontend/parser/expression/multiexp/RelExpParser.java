package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

/**
 * RelExpParser 关系表达式解析器类
 * <RelExp> -> <AddExp> { ('<' | '>' | '<=' | '>=') <AddExp> }
 * n个<AddExp>加减表达式用'<'或'>'或'<='或'>='相连
 */
public class RelExpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * first 首个<AddExp>加减表达式
     * operators 关系符子节点表
     * operands <AddExp>子节点表
     */
    private TokenListIterator iterator;
    private AddExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<AddExp> operands = new ArrayList<>();

    public RelExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseRelExp()
     * 解析关系表达式方法
     * 先读入一个AddExp，并解析
     * 若读入4个关系符之一，则加入operators
     * 调用解析后续的AddExp
     * 直至无法读入正确的操作符后，创建RelExp实例并返回
     * @return RelExp实例
     */
    public RelExp parseRelExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        AddExpParser addExpParser = new AddExpParser(this.iterator);
        first = addExpParser.parseAddExp();
        Token token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.LEQ) || token.getTokenType().equals(TokenType.GEQ) || token.getTokenType().equals(TokenType.LSS) || token.getTokenType().equals(TokenType.GRE)) {
            this.operators.add(token);
            this.operands.add(addExpParser.parseAddExp());
            token = this.iterator.next();
        }
        this.iterator.unRead(1);
        RelExp relExp = new RelExp(this.first, this.operators, this.operands);
        return relExp;
    }
}

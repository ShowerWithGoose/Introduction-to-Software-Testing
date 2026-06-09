package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

/**
 * EqExpParser 相等性表达式解析器类
 * <EqExp> -> <RelExp> { ('==' | '!=') <RelExp> }
 * n个<RelExp>加减表达式用'=='或'!='相连
 */
public class EqExpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * first 首个<RelExp>加减表达式
     * operators 关系符子节点表
     * operands <RelExp>子节点表
     */
    private TokenListIterator iterator;
    private RelExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<RelExp> operands = new ArrayList<>();

    public EqExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseEqExp()
     * 解析相等性表达式方法
     * 先读入一个RelExp，并解析
     * 若读入2个关系符之一，则加入operators
     * 调用解析后续的RelExp
     * 直至无法读入正确的操作符后，创建EqExp实例并返回
     * @return EqExp实例
     */
    public EqExp parseEqExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        RelExpParser relExpParser = new RelExpParser(this.iterator);
        this.first = relExpParser.parseRelExp();
        Token token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.EQL) || token.getTokenType().equals(TokenType.NEQ)) {
            this.operators.add(token);
            this.operands.add(relExpParser.parseRelExp());
            token = this.iterator.next();
        }
        this.iterator.unRead(1);
        EqExp eqExp = new EqExp(this.first, this.operators, this.operands);
        return eqExp;
    }
}

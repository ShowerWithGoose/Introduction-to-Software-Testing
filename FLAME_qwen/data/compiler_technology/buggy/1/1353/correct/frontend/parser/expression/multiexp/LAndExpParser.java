package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

/**
 * LAndExpParser 逻辑与表达式解析器类
 * <LAndExp> -> <EqExp> { '&&' <EqExp> }
 * n个<EqExp>加减表达式用'&&'相连
 */
public class LAndExpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * first 首个<EqExp>加减表达式
     * operators 逻辑运算符子节点表
     * operands <EqExp>子节点表
     */
    private TokenListIterator iterator;
    private EqExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<EqExp> operands = new ArrayList<>();

    public LAndExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseLAndExp()
     * 解析逻辑与表达式方法
     * 先读入一个EqExp，并解析
     * 若读入'&&'，则加入operators
     * 调用解析后续的RelExp
     * 直至无法读入'&&'后，创建LAndExp实例并返回
     * @return LAndExp实例
     */
    public LAndExp parseLAndExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        EqExpParser eqExpParser = new EqExpParser(this.iterator);
        this.first = eqExpParser.parseEqExp();
        Token token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.AND)) { // '&&'
            this.operators.add(token);
            this.operands.add(eqExpParser.parseEqExp());
            token = this.iterator.next();
        }
        this.iterator.unRead(1);
        LAndExp landExp = new LAndExp(this.first, this.operators, this.operands);
        return landExp;
    }
}

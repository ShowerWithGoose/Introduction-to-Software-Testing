package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

/**
 * LOrExpParser 逻辑或表达式解析器类
 * <LOrExp> -> <LAndExp> { '||' <LAndExp> }
 * n个<LAndExp>加减表达式用'||'相连
 */
public class LOrExpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * first 首个<LAndExp>加减表达式
     * operators 逻辑运算符子节点表
     * operands <LAndExp>子节点表
     */
    private TokenListIterator iterator;
    private LAndExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<LAndExp> operands = new ArrayList<>();

    public LOrExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseLOrExp()
     * 解析逻辑或表达式方法
     * 先读入一个LAndExp，并解析
     * 若读入'||'，则加入operators
     * 调用解析后续的LAndExp
     * 直至无法读入'||'后，创建LOrExp实例并返回
     * @return LOrExp实例
     */
    public LOrExp parseLOrExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        LAndExpParser landExpParser = new LAndExpParser(this.iterator);
        this.first = landExpParser.parseLAndExp();
        Token token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.OR)) {
            this.operators.add(token);
            this.operands.add(landExpParser.parseLAndExp());
            token = this.iterator.next();
        }
        this.iterator.unRead(1);
        LOrExp lorExp = new LOrExp(this.first, this.operators, this.operands);
        return lorExp;
    }

}

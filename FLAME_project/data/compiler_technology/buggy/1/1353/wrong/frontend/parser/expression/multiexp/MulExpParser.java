package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.unaryexp.UnaryExp;
import frontend.parser.expression.unaryexp.UnaryExpParser;

import java.util.ArrayList;

/**
 * MulExpParser 乘除模表达式解析器类
 * <MulExp> -> <UnaryExp> | { ('*' | '/' | '%') <UnaryExp> }
 * n个<UnaryExp>一元表达式用'*'或'/'或'%'相连
 */
public class MulExpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * first 首个一元表达式
     * operators 操作符子节点表
     * operands <UnaryExp>子节点表
     */
    private TokenListIterator iterator;
    private UnaryExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<UnaryExp> operands = new ArrayList<>();

    public MulExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseMulExp()
     * 解析乘除模表达式方法
     * 先读入一个UnaryExp，并解析
     * 若读入3个操作符之一，则加入operators
     * 解析后续的UnaryExp
     * 直至无法读入正确的操作符后，创建MulExp实例并返回
     * @return MulExp实例
     */
    public MulExp parseMulExp() {
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
        UnaryExpParser unaryExpParser = new UnaryExpParser(this.iterator);
        this.first = unaryExpParser.parseUnaryExp();
        Token token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.MULT) ||
                token.getTokenType().equals(TokenType.DIV) ||
                token.getTokenType().equals(TokenType.MOD)) {
            /* token -> * / % */
            this.operators.add(token);
            this.operands.add(unaryExpParser.parseUnaryExp());
            token = this.iterator.next();
        }
        this.iterator.unRead(1);
        MulExp mulExp = new MulExp(this.first, this.operators, this.operands);
        return mulExp;
    }
}
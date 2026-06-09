package frontend.parser.expression.primaryexp;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

/**
 * PrimaryExpExpParser <PrimaryExp>Exp子节点解析类
 * '(' <Exp> ')'
 */
public class PrimaryExpExpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * leftParent '('
     * exp <Exp>
     * rightParent ')'
     */
    private TokenListIterator iterator;
    private Token leftParent = null;
    private Exp exp = null;
    private Token rightParent = null;

    public PrimaryExpExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parsePrimaryExpExp()
     * 解析<PrimaryExp>Exp子节点方法
     * @return PrimaryExp实例
     */
    public PrimaryExpExp parsePrimaryExpExp() {
        this.leftParent = this.iterator.next();
        ExpParser expParser = new ExpParser(this.iterator);
        this.exp = expParser.parseExp();
        this.rightParent = this.iterator.next();
        if (!rightParent.getTokenType().equals(TokenType.RPARENT)) {
            System.out.println("ERROR: EXPECT RPARENT");
            handleJError();
        }
        PrimaryExpExp primaryExpExp = new
                PrimaryExpExp(this.leftParent, this.exp, this.rightParent);
        return primaryExpExp;
    }

    /**
     * j error
     * missing ')'
     */
    private void handleJError() {
        iterator.unRead(2); // 后退两个以确定上一个非终结符的位置
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_RBRACK, iterator.next().getLine()));
        rightParent = null;
    }
}

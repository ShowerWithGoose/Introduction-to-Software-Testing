package frontend.parser.expression.primaryexp;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

/**
 * LValParser 左值表达式解析器类
 * <LVal> -> <Ident> [ '[' <Exp> ']' ]
 */
public class LValParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * ident <Ident>
     * leftBracket '['，可选
     * left <Exp>，可选
     * RightBracket ']'，可选
     */
    private TokenListIterator iterator;
    private Ident ident = null;
    private Token leftBracket = null; // '['
    private Exp exp = null;
    private Token rightBracket = null;

    public LValParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    /**
     * parseLVal()
     * 解析左值表达式方法
     * @return LVal实例
     */
    public LVal parseLVal() {
        IdentParser identParser = new IdentParser(this.iterator);
        this.ident = identParser.parseIdent();
        Token token = this.iterator.next();
        if (token.getTokenType().equals(TokenType.LBRACK)) { // '['
            ExpParser expParser = new ExpParser(this.iterator);
            token = this.iterator.next();
            if (!token.getTokenType().equals(TokenType.RBRACK)) {// ']'
                System.out.println("ERROR : EXPECT RBRACK");
                handleKError();
            }
            LVal lval = new LVal(this.ident, this.leftBracket, this.exp, this.rightBracket);
            return lval;
        } else {
            iterator.unRead(1);
            LVal lval = new LVal(this.ident);
            return lval;
        }
    }

    /**
     * k error
     * missing ']'
     */
    private void handleKError() {
        iterator.unRead(2); // 后退两个以确定上一个非终结符的位置
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_RBRACK, iterator.next().getLine()));
        rightBracket = null;
    }
}

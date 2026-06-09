package frontend.parser.declaration.constant;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.constant.constInitVal.ConstInitVal;
import frontend.parser.declaration.constant.constInitVal.ConstInitValParser;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;
/**
 * ConstDef 常量定义类
 * <ConstDef> -> <Ident> [ '[' <ConstExp> ']' ] '=' <ConstInitVal>
 * 普通变量，一维数组
 */
public class ConstDefParser {
    private TokenListIterator iterator;
    /* ConstDef Attributes */
    private Ident ident;
    private Token leftBracket = null;
    private ConstExp constExp = null;
    private Token rightBracket = null;
    private Token eq; // =
    private ConstInitVal constInitVal;

    public ConstDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ConstDef parseConstDef() {
        IdentParser identParser = new IdentParser(this.iterator);
        ident = identParser.parseIdent();
        Token token = iterator.next();
        if (token.getTokenType().equals(TokenType.LBRACK)) {
            /* '[' */
            this.leftBracket = token;
            /* ConstExp */
            ConstExpParser constExpParser = new ConstExpParser(this.iterator);
            ConstExp constExp = constExpParser.parseConstExp();
            this.constExp = constExp;
            token = this.iterator.next();
            /* ']' */
            if (token.getTokenType().equals(TokenType.RBRACK)) {
                this.rightBracket = token;
            } else {
                System.out.println("EXPECT RBRACK HERE");
                handleKError();
            }
            token = this.iterator.next();
        }
        if (!token.getTokenType().equals(TokenType.ASSIGN)) {
            System.out.println("EXPECT ASSIGN HERE");
        }
        this.eq = token;
        ConstInitValParser constInitValParser = new ConstInitValParser(this.iterator);
        this.constInitVal = constInitValParser.parseConstInitVal();
        ConstDef constDef = new ConstDef(this.ident, this.leftBracket, this.constExp,
                this.rightBracket, this.eq, this.constInitVal);
        return constDef;
    }

    /**
     * k error
     * missing ']'
     */
    private void handleKError() {
        iterator.unRead(2); // 后退两个以确定上一个非终结符的位置
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_RBRACK, iterator.next().getLine()));
        this.rightBracket = null;
    }
}

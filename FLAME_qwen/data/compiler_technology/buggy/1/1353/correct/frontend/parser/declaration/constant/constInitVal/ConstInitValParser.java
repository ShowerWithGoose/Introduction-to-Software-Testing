package frontend.parser.declaration.constant.constInitVal;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.terminal.StringConst;
import frontend.parser.terminal.StringConstParser;

/**
 * ConstInitValParser 常量初值解析器类
 * <ConstInitVal> -> <ConstExp> | '{' [ <ConstExp> { ',' <ConstExp> } '}' | <StringConst>
 */
public class ConstInitValParser {
    private TokenListIterator iterator;
    /* ConstInitVal Attribute */
    private ConstInitValEle constInitValEle;

    public ConstInitValParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ConstInitVal parseConstInitVal() {
        Token token = this.iterator.next();
        if (token.getTokenType().equals(TokenType.LBRACE)) { // '{'
            this.iterator.unRead(1);
            ConstInitValMultiParser constInitValMultiParser = new ConstInitValMultiParser(this.iterator);
            this.constInitValEle = constInitValMultiParser.parseConstInitValMulti();
        } else if (token.getTokenType().equals(TokenType.STRCON)) { // String Const
            this.iterator.unRead(1);
            StringConstParser stringConstParser = new StringConstParser(this.iterator);
            this.constInitValEle = stringConstParser.parseStringConst();
        } else {    // <ConstExp>
            this.iterator.unRead(1);
            ConstExpParser constExpParser = new ConstExpParser(this.iterator);
            this.constInitValEle = constExpParser.parseConstExp();
        }
        ConstInitVal constInitVal = new ConstInitVal(this.constInitValEle);
        return constInitVal;
    }
}

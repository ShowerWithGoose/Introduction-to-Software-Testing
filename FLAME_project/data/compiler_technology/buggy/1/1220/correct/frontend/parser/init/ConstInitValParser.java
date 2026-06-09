package frontend.parser.init;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExpParser;

public class ConstInitValParser {
    private TokenIterator iterator;
    private ConstInitValUnit constInitValUnit;

    public ConstInitValParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public ConstInitVal parseConstInitVal() {
        //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' |StringConst
        //StringConst → '"' {ASCII} '"'
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.LBRACE) {
            iterator.ungetToken(1);
            ConstInitValMultiParser constInitValMultiParser = new ConstInitValMultiParser(iterator);
            constInitValUnit = constInitValMultiParser.parseConstInitValMulti();
        } else if (t1.getType() == TokenType.STRCON) {
            constInitValUnit = new StringConst(t1);
        } else {
            iterator.ungetToken(1);
            ConstExpParser constExpParser = new ConstExpParser(iterator);
            constInitValUnit = constExpParser.parseConstExp();
        }
        return new ConstInitVal(constInitValUnit);
    }
}

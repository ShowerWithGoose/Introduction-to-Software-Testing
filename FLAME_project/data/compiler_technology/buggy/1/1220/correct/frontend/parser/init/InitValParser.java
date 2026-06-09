package frontend.parser.init;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ExpParser;

public class InitValParser {
    private TokenIterator iterator;
    private InitValUnit initValUnit;

    public InitValParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public InitVal parseInitVal() {
        //InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.LBRACE) {
            iterator.ungetToken(1);
            InitValMultiParser initValMultiParser = new InitValMultiParser(iterator);
            initValUnit = initValMultiParser.parseInitValMulti();
        } else if (t1.getType() == TokenType.STRCON){
            initValUnit = new StringConst(t1);
        } else {
            iterator.ungetToken(1);
            ExpParser expParser = new ExpParser(iterator);
            initValUnit = expParser.parseExp();
        }
        return new InitVal(initValUnit);
    }
}

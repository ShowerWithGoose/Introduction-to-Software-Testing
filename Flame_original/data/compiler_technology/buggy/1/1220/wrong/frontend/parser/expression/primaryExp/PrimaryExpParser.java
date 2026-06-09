package frontend.parser.expression.primaryExp;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

public class PrimaryExpParser {
    private TokenIterator iterator;

    public PrimaryExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public PrimaryExp parsePrimaryExp() {
        //PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.INTCON) {
            Number number = new Number(t1);
            return new PrimaryExp(number);
        } else if (t1.getType() == TokenType.CHRCON) {
            Character character = new Character(t1);
            return new PrimaryExp(character);
        } else if (t1.getType() == TokenType.LPARENT) {
            iterator.ungetToken(1);
            ExpBraceParser expBraceParser = new ExpBraceParser(iterator);
            ExpBrace expBrace = expBraceParser.parseExpBrace();
            return new PrimaryExp(expBrace);
        } else {
            iterator.ungetToken(1);
            LValParser lValParser = new LValParser(iterator);
            LVal lVal = lValParser.parseLVal();
            return new PrimaryExp(lVal);
        }
    }
}

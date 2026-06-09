package frontend.parser.init;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;

import java.util.ArrayList;

public class ConstInitValMultiParser {
    private TokenIterator iterator;
    private Token leftBrace;
    private Token rightBrace;
    private ConstExp first = null;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<ConstExp> constExps = new ArrayList<>();
    public ConstInitValMultiParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public ConstInitValMulti parseConstInitValMulti() {
        // '{' [ ConstExp { ',' ConstExp } ] '}'
        leftBrace = iterator.getNextToken();
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.RBRACE) {
            rightBrace = t1;
            return new ConstInitValMulti(leftBrace, rightBrace, first, commas, constExps);
        } else {
            iterator.ungetToken(1);
            ConstExpParser constExpParser = new ConstExpParser(iterator);
            first = constExpParser.parseConstExp();
            Token t2 = iterator.getNextToken();
            while (t2.getType() == TokenType.COMMA) {
                commas.add(t2);
                ConstExpParser constExpParser1 = new ConstExpParser(iterator);
                constExps.add(constExpParser1.parseConstExp());
                t2 = iterator.getNextToken();
            }
            if (t2.getType() != TokenType.RBRACE) {
                rightBrace = null;
                System.out.println("parseConstInitValMulti WA!-1, expect }");
                return null;
            }
            rightBrace = t2;
        }
        return new ConstInitValMulti(leftBrace, rightBrace, first, commas, constExps);
    }
}

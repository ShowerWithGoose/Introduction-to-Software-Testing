package frontend.parser.init;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

public class InitValMultiParser {
    private TokenIterator iterator;
    private Token leftBrace;
    private Token rightBrace;
    private Exp first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();

    public InitValMultiParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public InitValMulti parseInitValMulti() {
        // '{' [ Exp { ',' Exp } ] '}'
        leftBrace = iterator.getNextToken();
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.RBRACE) {
            rightBrace = t1;
            first = null;
            return new InitValMulti(leftBrace, rightBrace, first, commas, exps);
        } else {
            iterator.ungetToken(1);
            ExpParser expParser = new ExpParser(iterator);
            first = expParser.parseExp();
            Token t2 = iterator.getNextToken();
            while (t2.getType() == TokenType.COMMA) {
                commas.add(t2);
                ExpParser expParser1 = new ExpParser(iterator);
                exps.add(expParser1.parseExp());
                t2 = iterator.getNextToken();
            }
            if (t2.getType() != TokenType.RBRACE) {
                System.out.println("parseInitValMulti WA-1");
                return null;
            } else {
                rightBrace = t2;
                return new InitValMulti(leftBrace, rightBrace, first, commas, exps);
            }
        }
    }
}

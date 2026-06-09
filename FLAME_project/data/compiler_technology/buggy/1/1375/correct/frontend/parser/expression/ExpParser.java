package frontend.parser.expression;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.parser.expression.multiexp.AddExp;
import frontend.parser.expression.multiexp.AddExpParser;

import java.util.ArrayList;

public class ExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;

    public ExpParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public Exp parseExp() {
        AddExpParser addExpParser = new AddExpParser(this.iterator,this.error_tokens);
        AddExp addExp = addExpParser.parseAddExp();
        Exp exp = new Exp(addExp);
        return exp;
    }
}

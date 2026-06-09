package frontend.parser.expression;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.parser.expression.multiexp.AddExp;
import frontend.parser.expression.multiexp.AddExpParser;

import java.util.ArrayList;

public class ConstExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* ConstExp Attributes */
    public AddExp addExp = null;

    public ConstExpParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public ConstExp parseConstExp() {
        AddExpParser addExpParser = new AddExpParser(this.iterator,this.error_tokens);
        this.addExp = addExpParser.parseAddExp();
        ConstExp constExp = new ConstExp(this.addExp);
        return constExp;
    }
}

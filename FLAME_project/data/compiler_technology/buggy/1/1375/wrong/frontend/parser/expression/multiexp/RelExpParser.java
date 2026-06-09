package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

/**
 * <RelExp> -> <AddExp> { ('<' | '>' | '<=' | '>=') <AddExp> }
 */
public class RelExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* RelExp Attributes */
    public AddExp first = null;
    public ArrayList<Token> operators = new ArrayList<>();
    public ArrayList<AddExp> operands = new ArrayList<>();

    public RelExpParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public RelExp parseRelExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        AddExpParser addExpParser = new AddExpParser(this.iterator,this.error_tokens);
        first = addExpParser.parseAddExp();
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.LSS) || // <
                token.type.equals(TokenType.GRE) || // >
                token.type.equals(TokenType.LEQ) || // <=
                token.type.equals(TokenType.GEQ)) { // >=
            this.operators.add(token);
            AddExpParser addExpParser1 = new AddExpParser(this.iterator,this.error_tokens);
            this.operands.add(addExpParser1.parseAddExp());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        RelExp relExp = new RelExp(this.first, this.operators, this.operands);
        return relExp;
    }
}

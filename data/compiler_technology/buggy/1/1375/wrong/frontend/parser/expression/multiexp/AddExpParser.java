package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class AddExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* AddExp Attributes */
    public MulExp first = null;
    public ArrayList<Token> operators = new ArrayList<>(); // '+' '-'
    public ArrayList<MulExp> operands = new ArrayList<>();

    public AddExpParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public AddExp parseAddExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        MulExpParser mulExpParser = new MulExpParser(this.iterator,this.error_tokens);
        this.first = mulExpParser.parseMulExp();
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.PLUS) ||
                token.type.equals(TokenType.MINU)) {
            this.operators.add(token);
            MulExpParser mulExpParser1 = new MulExpParser(this.iterator,this.error_tokens);
            this.operands.add(mulExpParser1.parseMulExp());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        AddExp addExp = new AddExp(this.first, this.operators, this.operands);
        return addExp;
    }
}

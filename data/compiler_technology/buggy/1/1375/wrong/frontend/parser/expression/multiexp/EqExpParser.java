package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class EqExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* EqExp Attributes */
    public RelExp first = null;
    public ArrayList<Token> operators = new ArrayList<>();
    public ArrayList<RelExp> operands = new ArrayList<>();

    public EqExpParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public EqExp parseEqExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        RelExpParser relExpParser = new RelExpParser(this.iterator,this.error_tokens);
        this.first = relExpParser.parseRelExp();
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.EQL) || // '=='
                token.type.equals(TokenType.NEQ)) { // '!='
            this.operators.add(token);
            RelExpParser relExpParser1 = new RelExpParser(this.iterator,this.error_tokens);
            this.operands.add(relExpParser1.parseRelExp());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        EqExp eqExp = new EqExp(this.first, this.operators, this.operands);
        return eqExp;
    }
}

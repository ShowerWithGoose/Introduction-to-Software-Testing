package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

/**
 * <LAndExp> -> <EqExp> { '&&' <EqExp> }
 */
public class LAndExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* LAndExp Attributes */
    public EqExp first = null;
    public ArrayList<Token> operators = new ArrayList<>();
    public ArrayList<EqExp> operands = new ArrayList<>();

    public LAndExpParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public LAndExp parseLAndExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        EqExpParser eqExpParser = new EqExpParser(this.iterator,this.error_tokens);
        this.first = eqExpParser.parseEqExp();
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.AND)) { // '&&'
            this.operators.add(token);
            EqExpParser eqExpParser1 = new EqExpParser(this.iterator,this.error_tokens);
            this.operands.add(eqExpParser1.parseEqExp());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        LAndExp landExp = new LAndExp(this.first, this.operators, this.operands);
        return landExp;
    }
}

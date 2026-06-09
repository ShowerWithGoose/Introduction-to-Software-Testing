package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

/**
 * <LOrExp> -> <LAndExp> { '||' <LAndExp> }
 */
public class LOrExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* LOrExp Attributes */
    public LAndExp first = null;
    public ArrayList<Token> operators = new ArrayList<>();
    public ArrayList<LAndExp> operands = new ArrayList<>();

    public LOrExpParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public LOrExp parseLOrExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        LAndExpParser landExpParser = new LAndExpParser(this.iterator,this.error_tokens);
        this.first = landExpParser.parseLAndExp();
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.OR)) { // '||'
            this.operators.add(token);
            LAndExpParser landExpParser1 = new LAndExpParser(this.iterator,this.error_tokens);
            this.operands.add(landExpParser1.parseLAndExp());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        LOrExp lorExp = new LOrExp(this.first, this.operators, this.operands);
        return lorExp;
    }

}

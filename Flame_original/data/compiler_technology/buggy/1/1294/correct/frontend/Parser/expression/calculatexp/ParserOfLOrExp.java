package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Error;

import java.util.ArrayList;

public class ParserOfLOrExp {
    private TokenListManager tokenListManager;
    private LAndExp theOne;
    private ArrayList<Token> operators;
    private ArrayList<LAndExp> operands;
    private ArrayList<Error> errors;
    public ParserOfLOrExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public LOrExp parseLOrExp() {
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
        this.errors = new ArrayList<>();
        ParserOfLAndExp parserOfLAndExp = new ParserOfLAndExp(tokenListManager);
        this.theOne = parserOfLAndExp.parseLAndExp();
        this.errors.addAll(parserOfLAndExp.getErrors());
        Token next = tokenListManager.getTokenAndMove();
        while(next.getTokenType().equals(TokenType.OR)){
            this.operators.add(next);
            LAndExp lAndExp = parserOfLAndExp.parseLAndExp();
            this.operands.add(lAndExp);
            this.errors.addAll(parserOfLAndExp.getErrors());
            next = tokenListManager.getTokenAndMove();
        }
        tokenListManager.lookBackToken(1);
        return new LOrExp(this.theOne, this.operators, this.operands);
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}

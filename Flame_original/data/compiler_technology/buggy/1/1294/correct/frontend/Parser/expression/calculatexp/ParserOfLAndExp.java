package frontend.Parser.expression.calculatexp;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.unaryexp.UnaryExp;

import java.util.ArrayList;

public class ParserOfLAndExp {
    private TokenListManager tokenListManager;
    private EqExp theOne;
    private ArrayList<Token> operators;
    private ArrayList<EqExp> operands;
    private ArrayList<Error> errors;

    public ParserOfLAndExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public LAndExp parseLAndExp() {
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
        this.errors = new ArrayList<>();
        ParserOfEqExp parserOfEqExp = new ParserOfEqExp(tokenListManager);
        this.theOne = parserOfEqExp.parseEqExp();
        this.errors.addAll(parserOfEqExp.getErrors());
        Token next = tokenListManager.getTokenAndMove();
        while (next.getTokenType().equals(TokenType.AND)) {
            this.operators.add(next);
            EqExp eqExp = parserOfEqExp.parseEqExp();
            this.operands.add(eqExp);
            this.errors.addAll(parserOfEqExp.getErrors());
            next = tokenListManager.getTokenAndMove();
        }
        tokenListManager.lookBackToken(1);
        return new LAndExp(this.theOne, this.operators, this.operands);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}

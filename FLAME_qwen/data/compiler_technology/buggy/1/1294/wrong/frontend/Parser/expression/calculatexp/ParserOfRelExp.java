package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Error;

import java.util.ArrayList;

public class ParserOfRelExp {
    private TokenListManager tokenListManager;
    private AddExp theOne;
    private ArrayList<Token> operators;
    private ArrayList<AddExp> operands;
    private ArrayList<Error> errors;

    public ParserOfRelExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public RelExp parseRelExp() {
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
        this.errors = new ArrayList<>();
        ParserOfAddExp parserOfAddExp = new ParserOfAddExp(tokenListManager);
        this.theOne = parserOfAddExp.parseAddExp();
        this.errors.addAll(parserOfAddExp.getErrors());
        Token next = tokenListManager.getTokenAndMove();
        while (next.getTokenType().equals(TokenType.LSS) ||
                next.getTokenType().equals(TokenType.GRE) ||
                next.getTokenType().equals(TokenType.LEQ) ||
                next.getTokenType().equals(TokenType.GEQ)) {
            this.operators.add(next);
            AddExp addExp = parserOfAddExp.parseAddExp();
            this.errors.addAll(parserOfAddExp.getErrors());
            this.operands.add(addExp);
            next = tokenListManager.getTokenAndMove();
        }
        tokenListManager.lookBackToken(1);
        return new RelExp(theOne, operators, operands);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}

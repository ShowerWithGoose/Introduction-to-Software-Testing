package frontend.Parser.expression.calculatexp;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;

import java.util.ArrayList;

public class ParserOfEqExp {
    private TokenListManager tokenListManager;
    private RelExp theOne;
    private ArrayList<Token> operators;
    private ArrayList<RelExp> operands;
    private ArrayList<Error> errors;
    public ParserOfEqExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public EqExp parseEqExp(){
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
        this.errors = new ArrayList<>();
        ParserOfRelExp parserOfRelExp = new ParserOfRelExp(tokenListManager);
        this.theOne = parserOfRelExp.parseRelExp();
        this.errors.addAll(parserOfRelExp.getErrors());
        Token next = tokenListManager.getTokenAndMove();
        while(next.getTokenType().equals(TokenType.EQL) || next.getTokenType().equals(TokenType.NEQ)){
            this.operators.add(next);
            RelExp relExp = parserOfRelExp.parseRelExp();
            this.operands.add(relExp);
            this.errors.addAll(parserOfRelExp.getErrors());
            next = tokenListManager.getTokenAndMove();
        }
        tokenListManager.lookBackToken(1);
        return new EqExp(theOne, operators, operands);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}

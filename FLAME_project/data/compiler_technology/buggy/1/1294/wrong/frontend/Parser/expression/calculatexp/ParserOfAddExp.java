package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Error;

import java.util.ArrayList;

/*
文法：AddExp -> MulExp {('+' | '-') MulExp}
 */
public class ParserOfAddExp {
    private TokenListManager tokenListManager;
    private MulExp theOne = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<MulExp> operands = new ArrayList<>();
    private ArrayList<Error> errors;

    public ParserOfAddExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public AddExp parseAddExp() {
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
        this.errors = new ArrayList<>();
        ParserOfMulExp parserOfMulExp = new ParserOfMulExp(tokenListManager);
        this.theOne = parserOfMulExp.parseMulExp();
        this.errors.addAll(parserOfMulExp.getErrors());
        Token next = tokenListManager.getTokenAndMove();
        while (next.getTokenType().equals(TokenType.PLUS)
                || next.getTokenType().equals(TokenType.MINU)) {
            this.operators.add(next);
            MulExp mulExp = parserOfMulExp.parseMulExp();
            this.operands.add(mulExp);
            this.errors.addAll(parserOfMulExp.getErrors());
            next = tokenListManager.getTokenAndMove();
        }
        tokenListManager.lookBackToken(1);
        return new AddExp(this.theOne, this.operators, this.operands);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}

package frontend.Parser.expression.calculatexp;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.unaryexp.ParserOfUnaryExp;
import frontend.Parser.expression.unaryexp.UnaryExp;

import java.util.ArrayList;

public class ParserOfMulExp {
    private TokenListManager tokenListManager;
    private UnaryExp theOne;
    private ArrayList<Token> operators;
    private ArrayList<UnaryExp> operands;
    private ArrayList<Error> errors;
    public ParserOfMulExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public MulExp parseMulExp() {
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
        this.errors = new ArrayList<>();
        ParserOfUnaryExp parserOfUnaryExp = new ParserOfUnaryExp(tokenListManager);
        this.theOne = parserOfUnaryExp.parseUnaryExp();
        this.errors.addAll(parserOfUnaryExp.getErrors());
        Token next = tokenListManager.getTokenAndMove();
        while(next.getTokenType().equals(TokenType.MULT)
                || next.getTokenType().equals(TokenType.DIV)
                || next.getTokenType().equals(TokenType.MOD)) {
            this.operators.add(next);
            UnaryExp unaryExp = parserOfUnaryExp.parseUnaryExp();
            this.operands.add(unaryExp);
            this.errors.addAll(parserOfUnaryExp.getErrors());
            next = tokenListManager.getTokenAndMove();
        }
        tokenListManager.lookBackToken(1);
        return new MulExp(this.theOne, this.operators, this.operands);
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}

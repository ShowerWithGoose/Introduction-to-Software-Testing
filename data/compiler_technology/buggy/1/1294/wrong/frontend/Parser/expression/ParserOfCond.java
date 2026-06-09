package frontend.Parser.expression;

import frontend.Error;
import frontend.Lexer.TokenListManager;
import frontend.Parser.expression.calculatexp.LOrExp;
import frontend.Parser.expression.calculatexp.ParserOfLOrExp;

import java.util.ArrayList;

public class ParserOfCond {
    private TokenListManager tokenListManager;
    private LOrExp lOrExp;
    private ArrayList<Error> errors;

    public ParserOfCond(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public Cond parseCond() {
        this.errors = new ArrayList<>();
        ParserOfLOrExp parserOfLOrExp = new ParserOfLOrExp(tokenListManager);
        this.lOrExp = parserOfLOrExp.parseLOrExp();
        this.errors.addAll(parserOfLOrExp.getErrors());
        return new Cond(this.lOrExp);
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}

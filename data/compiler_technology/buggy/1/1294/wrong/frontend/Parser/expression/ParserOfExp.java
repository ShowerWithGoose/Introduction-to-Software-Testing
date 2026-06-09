package frontend.Parser.expression;

import frontend.Lexer.TokenListManager;
import frontend.Parser.expression.calculatexp.AddExp;
import frontend.Parser.expression.calculatexp.ParserOfAddExp;
import frontend.Error;

import java.util.ArrayList;

public class ParserOfExp {
    private TokenListManager tokenListManager;
    private AddExp addExp;
    private ArrayList<Error> errors;

    public ParserOfExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public Exp parseExp() {
        this.errors = new ArrayList<>();
        ParserOfAddExp parserOfAddExp = new ParserOfAddExp(tokenListManager);
        AddExp addExp = parserOfAddExp.parseAddExp();
        this.errors.addAll(parserOfAddExp.getErrors());
        return new Exp(addExp);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}

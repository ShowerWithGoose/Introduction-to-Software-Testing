package frontend.Parser.expression;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Parser.expression.calculatexp.AddExp;
import frontend.Parser.expression.calculatexp.ParserOfAddExp;

import java.util.ArrayList;

public class ParserOfConstExp {
    private TokenListManager tokenListManager;
    private AddExp addExp;
    private ArrayList<Error> errors;

    public ParserOfConstExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public ConstExp parseConstExp(){
        this.errors = new ArrayList<>();
        ParserOfAddExp parserOfAddExp = new ParserOfAddExp(tokenListManager);
        this.addExp = parserOfAddExp.parseAddExp();
        this.errors.addAll(parserOfAddExp.getErrors());
        return new ConstExp(this.addExp);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}

package frontend.Parser.expression.primaryexp;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.ParserOfExp;

import java.util.ArrayList;

public class ParserOfPrimaryParentExp {
    private TokenListManager tokenListManager;
    private Token lParent;
    private Exp exp;
    private Token rParent;
    private ArrayList<Error> errors;
    public ParserOfPrimaryParentExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public PrimaryParentExp parsePrimaryParentExp() {
        this.errors = new ArrayList<>();
        Token token = tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.LPARENT)){
            this.lParent = token;
        }
        ParserOfExp parserOfExp = new ParserOfExp(tokenListManager);
        Exp exp = parserOfExp.parseExp();
        this.errors.addAll(parserOfExp.getErrors());
        this.exp = exp;
        token = tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.RPARENT)){
            this.rParent = token;
        } else {
            tokenListManager.lookBackToken(2);
            token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.j);
            this.errors.add(error);
        }
        return new PrimaryParentExp(this.lParent, this.exp, this.rParent);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}

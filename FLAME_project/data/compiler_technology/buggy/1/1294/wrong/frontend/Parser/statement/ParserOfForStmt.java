package frontend.Parser.statement;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.LVal;
import frontend.Parser.expression.ParserOfExp;
import frontend.Parser.expression.ParserOfLVal;

import java.util.ArrayList;

public class ParserOfForStmt {
    private TokenListManager tokenListManager;
    private LVal lVal;
    private Token assignSign;
    private Exp exp;
    private ArrayList<Error> errors;

    public ParserOfForStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public ForStmt parseForStmt() {
        this.errors = new ArrayList<>();
        ParserOfLVal parserOfLVal = new ParserOfLVal(tokenListManager);
        this.lVal = parserOfLVal.parseLVal();
        this.errors.addAll(parserOfLVal.getErrors());
        Token token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.ASSIGN)) {
            this.assignSign = token;
        } else {
            System.out.println("expected assign token in ForStmt");
        }
        ParserOfExp parserOfExp = new ParserOfExp(tokenListManager);
        this.exp = parserOfExp.parseExp();
        this.errors.addAll(parserOfExp.getErrors());

        return new ForStmt(this.lVal, this.assignSign, this.exp);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}

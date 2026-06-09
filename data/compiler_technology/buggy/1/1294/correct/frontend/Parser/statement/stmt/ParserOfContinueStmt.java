package frontend.Parser.statement.stmt;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;

import java.util.ArrayList;

public class ParserOfContinueStmt {
    private TokenListManager tokenListManager;
    private Token continueTk;
    private Token semicn;
    private ArrayList<Error> errors;

    public ParserOfContinueStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public ContinueStmt parseContinueStmt() {
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        Token sec = tokenListManager.getTokenAndMove();
        if (fir.getTokenType().equals(TokenType.CONTINUETK) &&
                sec.getTokenType().equals(TokenType.SEMICN)) {
            this.continueTk = fir;
            this.semicn = sec;
        } else if (fir.getTokenType().equals(TokenType.CONTINUETK) &&
                !sec.getTokenType().equals(TokenType.SEMICN)) {
            this.continueTk = fir;
            tokenListManager.lookBackToken(2);
            Token token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.i);
            this.errors.add(error);
            System.out.println("Error in parsing continue statement");
        }
        return new ContinueStmt(this.continueTk,this.semicn);
    }
    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}

package frontend.Parser.statement.stmt;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;

import java.util.ArrayList;

public class ParserOfBreakStmt {
    private TokenListManager tokenListManager;
    private Token breakTk;
    private Token semicn;
    private ArrayList<Error> errors;

    public ParserOfBreakStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public BreakStmt parseBreakStmt() {
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        Token sec = tokenListManager.getTokenAndMove();
        if (fir.getTokenType().equals(TokenType.BREAKTK) &&
                sec.getTokenType().equals(TokenType.SEMICN)) {
            this.breakTk = fir;
            this.semicn = sec;
        } else if (fir.getTokenType().equals(TokenType.BREAKTK) &&
                !sec.getTokenType().equals(TokenType.SEMICN)) {
            this.breakTk = fir;
            tokenListManager.lookBackToken(2);
            Token token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.i);
            this.errors.add(error);
            System.out.println("Error in parsing break statement");
        }
        return new BreakStmt(this.breakTk, this.semicn);
    }
    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}

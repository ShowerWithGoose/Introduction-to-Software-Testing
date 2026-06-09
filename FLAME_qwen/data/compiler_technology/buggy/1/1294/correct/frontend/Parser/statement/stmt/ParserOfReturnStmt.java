package frontend.Parser.statement.stmt;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.ParserOfExp;

import java.util.ArrayList;

public class ParserOfReturnStmt {
    private TokenListManager tokenListManager;
    private Token returnTk;
    private Exp exp;
    private Token semicn;
    private ArrayList<Error> errors;

    public ParserOfReturnStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public ReturnStmt parseReturnStmt() {
        this.exp = null;
        this.errors = new ArrayList<>();
        Token token = this.tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.RETURNTK)) {
            this.returnTk = token;
        } else {
            System.out.println("expected return token in parseReturnStmt");
        }
        token = this.tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.SEMICN)) {
            this.semicn = token;
        } else {
            if (token.getTokenType().equals(TokenType.RBRACE) || token.getLineNo() > returnTk.getLineNo()) {
                tokenListManager.lookBackToken(2);
                token = tokenListManager.getTokenAndMove();
                Error error = new Error(token.getLineNo(), MyErrorType.i);
                this.errors.add(error);
            } else {
                this.tokenListManager.lookBackToken(1);
                ParserOfExp parserOfExp = new ParserOfExp(tokenListManager);
                Exp exp = parserOfExp.parseExp();
                this.errors.addAll(parserOfExp.getErrors());
                this.exp = exp;
                token = this.tokenListManager.getTokenAndMove();
                if (token.getTokenType().equals(TokenType.SEMICN)) {
                    this.semicn = token;
                } else {
                    tokenListManager.lookBackToken(2);
                    token = tokenListManager.getTokenAndMove();
                    Error error = new Error(token.getLineNo(), MyErrorType.i);
                    this.errors.add(error);
                    System.out.println("expected semicn token in parseReturnStmt");
                }
            }
        }
        return new ReturnStmt(this.returnTk, this.exp, this.semicn);
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}

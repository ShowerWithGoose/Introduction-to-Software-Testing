package frontend.Parser.statement.stmt;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.ParserOfExp;

import java.util.ArrayList;

public class ParserOfExpStmt {
    private TokenListManager tokenListManager;
    private Exp exp;
    private Token semicn;
    private ArrayList<Error> errors;

    public ParserOfExpStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public ExpStmt parseExpStmt() {
        this.exp = null;
        this.errors = new ArrayList<>();
        Token token = this.tokenListManager.getTokenAndMove();
        if (!token.getTokenType().equals(TokenType.SEMICN)) {
            this.tokenListManager.lookBackToken(1);
            ParserOfExp parserOfExp = new ParserOfExp(tokenListManager);
            Exp exp = parserOfExp.parseExp();
            this.errors.addAll(parserOfExp.getErrors());
            this.exp = exp;
            token = this.tokenListManager.getTokenAndMove();
        }
        if (token.getTokenType().equals(TokenType.SEMICN)) {
            this.semicn = token;
        } else {
            tokenListManager.lookBackToken(2);
            token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.i);
            this.errors.add(error);
        }
        return new ExpStmt(this.exp, this.semicn);
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}

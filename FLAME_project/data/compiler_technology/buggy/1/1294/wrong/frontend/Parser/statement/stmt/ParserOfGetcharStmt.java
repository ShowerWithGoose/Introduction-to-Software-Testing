package frontend.Parser.statement.stmt;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.LVal;
import frontend.Parser.expression.ParserOfLVal;

import java.util.ArrayList;

public class ParserOfGetcharStmt {
    private TokenListManager tokenListManager;
    private LVal lVal;
    private Token assignTk;
    private Token getcharTk;
    private Token lParent;
    private Token rParent;
    private Token semicn;
    private ArrayList<Error> errors;

    public ParserOfGetcharStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public GetcharStmt parseGetcharStmt() {
        this.errors = new ArrayList<>();
        ParserOfLVal parserOfLVal = new ParserOfLVal(tokenListManager);
        LVal lVal = parserOfLVal.parseLVal();
        this.lVal = lVal;
        this.errors.addAll(parserOfLVal.getErrors());
        Token token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.ASSIGN)) {
            this.assignTk = token;
        } else {
            System.out.println("not assign token in second token");
        }
        token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.GETCHARTK)) {
            this.getcharTk = token;
        } else {
            System.out.println("not getchar token in third token");
        }
        token = tokenListManager.getTokenAndMove();
        this.lParent = token;
        token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.RPARENT)) {
            this.rParent = token;
        } else {
            tokenListManager.lookBackToken(2);
            token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.j);
            this.errors.add(error);
        }
        token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.SEMICN)) {
            this.semicn = token;
        } else {
            tokenListManager.lookBackToken(2);
            token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.i);
            this.errors.add(error);
        }
        return new GetcharStmt(this.lVal, this.assignTk, this.getcharTk,
                this.lParent, this.rParent, this.semicn);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}

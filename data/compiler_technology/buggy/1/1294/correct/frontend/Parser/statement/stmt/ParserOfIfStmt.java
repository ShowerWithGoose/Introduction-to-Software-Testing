package frontend.Parser.statement.stmt;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.Cond;
import frontend.Parser.expression.ParserOfCond;
import frontend.Parser.statement.ParserOfStmt;
import frontend.Parser.statement.Stmt;

import java.util.ArrayList;

public class ParserOfIfStmt {
    private TokenListManager tokenListManager;
    private Token ifTk;
    private Token lParent;
    private Cond cond;
    private Token rParent;
    private Stmt if2Stmt;
    private Token elseTk;
    private Stmt else2Stmt;
    private ArrayList<Error> errors;

    public ParserOfIfStmt(final TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public IfStmt parseIfStmt() {
        this.elseTk = null;
        this.else2Stmt = null;
        this.errors = new ArrayList<>();
        Token token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.IFTK)) {
            this.ifTk = token;
        } else {
            System.out.println("not if Token in ifStmt");
        }
        token = tokenListManager.getTokenAndMove();
        this.lParent = token;
        ParserOfCond parserOfCond = new ParserOfCond(tokenListManager);
        this.cond = parserOfCond.parseCond();
        this.errors.addAll(parserOfCond.getErrors());
        token = tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.RPARENT)){
            this.rParent = token;
        } else{
            tokenListManager.lookBackToken(2);
            Token token1 = tokenListManager.getTokenAndMove();
            Error error = new Error(token1.getLineNo(), MyErrorType.j);
            this.errors.add(error);
        }
        ParserOfStmt parserOfStmt = new ParserOfStmt(tokenListManager);
        this.if2Stmt = parserOfStmt.parseStmt();
        this.errors.addAll(parserOfStmt.getErrors());
        token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.ELSETK)) {
            this.elseTk = token;
            this.else2Stmt = parserOfStmt.parseStmt();
            this.errors.addAll(parserOfStmt.getErrors());
        } else {
            tokenListManager.lookBackToken(1);
        }
        return new IfStmt(this.ifTk, this.lParent, this.cond,
                this.rParent, this.if2Stmt, this.elseTk, this.else2Stmt);
    }
    public ArrayList<Error> getErrors() {
        return errors;
    }
}

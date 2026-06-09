package frontend.Parser.statement.stmt;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.Cond;
import frontend.Parser.expression.ParserOfCond;
import frontend.Parser.statement.ForStmt;
import frontend.Parser.statement.ParserOfForStmt;
import frontend.Parser.statement.ParserOfStmt;
import frontend.Parser.statement.Stmt;

import java.util.ArrayList;

public class ParserOfForLoopStmt {
    private TokenListManager tokenListManager;
    private Token forTk;
    private Token lParent;
    private Token semicn1;
    private Token semicn2;
    private Token rParent;
    private Stmt stmt;
    private ForStmt forStmt1;
    private Cond cond;
    private ForStmt forStmt2;
    private ArrayList<Error> errors;

    public ParserOfForLoopStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public ForLoopStmt parseForLoopStmt() {
        this.forStmt1 = null;
        this.cond = null;
        this.forStmt2 = null;
        this.errors = new ArrayList<>();
        Token token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.FORTK)) {
            this.forTk = token;
        } else {
            System.out.println("not for in forLoopStmt");
        }
        token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.LPARENT)) {
            this.lParent = token;
        } else {
            System.out.println("not ( in forLoopStmt");
        }
        token = tokenListManager.getTokenAndMove();
        if (!token.getTokenType().equals(TokenType.SEMICN)) {
            tokenListManager.lookBackToken(1);
            ParserOfForStmt parserOfForStmt = new ParserOfForStmt(tokenListManager);
            this.forStmt1 = parserOfForStmt.parseForStmt();
            this.errors.addAll(parserOfForStmt.getErrors());
            token = tokenListManager.getTokenAndMove();
        }
        if(token.getTokenType().equals(TokenType.SEMICN)) {
            this.semicn1 = token;
        } else {
            System.out.println("not semicn1 in forLoopStmt");
        }
        token = tokenListManager.getTokenAndMove();
        if (!token.getTokenType().equals(TokenType.SEMICN)) {
            tokenListManager.lookBackToken(1);
            ParserOfCond parserOfCond = new ParserOfCond(tokenListManager);
            this.cond = parserOfCond.parseCond();
            this.errors.addAll(parserOfCond.getErrors());
            token = tokenListManager.getTokenAndMove();
        }
        if(token.getTokenType().equals(TokenType.SEMICN)) {
            this.semicn2 = token;
        } else {
            System.out.println("not semicn2 in forLoopStmt");
        }
        token = tokenListManager.getTokenAndMove();
        if (!token.getTokenType().equals(TokenType.RPARENT)) {
            tokenListManager.lookBackToken(1);
            ParserOfForStmt parserOfForStmt = new ParserOfForStmt(tokenListManager);
            this.forStmt2 = parserOfForStmt.parseForStmt();
            this.errors.addAll(parserOfForStmt.getErrors());
            token = tokenListManager.getTokenAndMove();
        }
        if(token.getTokenType().equals(TokenType.RPARENT)) {
            this.rParent = token;
        } else {
            System.out.println("not rParent in forLoopStmt");
        }
        ParserOfStmt parserOfStmt = new ParserOfStmt(tokenListManager);
        this.stmt = parserOfStmt.parseStmt();
        this.errors.addAll(parserOfStmt.getErrors());
        return new ForLoopStmt(this.forTk, this.lParent, this.semicn1, this.semicn2,
                this.rParent, this.stmt, this.forStmt1, this.cond, this.forStmt2);
    }
    public ArrayList<Error> getErrors() {
        return errors;
    }
}

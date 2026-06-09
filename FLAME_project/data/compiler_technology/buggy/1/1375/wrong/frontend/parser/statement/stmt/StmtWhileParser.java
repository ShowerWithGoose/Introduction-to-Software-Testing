package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Cond;
import frontend.parser.expression.CondParser;

import java.util.ArrayList;

public class StmtWhileParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtWhile Attributes */
    public Token forTk; // 'for'
    public Token leftParent; // '('
    public ForStmt forStmtFirst=null;
    public Token semicnFirst; // ';'
    public Cond cond=null;
    public Token semicnSecond; // ';'
    public ForStmt forStmtSecond=null;
    public Token rightParent; // ')'
    public Stmt stmt;

    public StmtWhileParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtWhile parseStmtWhile() {
        this.forTk = this.iterator.readNextToken();
        this.leftParent = this.iterator.readNextToken();
        Token token = this.iterator.readNextToken();
        if(!token.type.equals(TokenType.SEMICN)) {
            this.iterator.unReadToken(1);
            ForStmtParser forStmtParser = new ForStmtParser(this.iterator,this.error_tokens);
            this.forStmtFirst= forStmtParser.forStmtParser();
            this.semicnFirst=this.iterator.readNextToken();
        } else {
            this.forStmtFirst=null;
            this.semicnFirst=token;
        }
        token = this.iterator.readNextToken();
        if(!token.type.equals(TokenType.SEMICN))
        {
            this.iterator.unReadToken(1);
            CondParser condParser = new CondParser(this.iterator,this.error_tokens);
            this.cond=condParser.parseCond();
            this.semicnSecond=this.iterator.readNextToken();
        }else{
            this.cond=null;
            this.semicnSecond=token;
        }
        token = this.iterator.readNextToken();
        if(!token.type.equals(TokenType.RPARENT)) {
            this.iterator.unReadToken(1);
            ForStmtParser forStmtParser = new ForStmtParser(this.iterator,this.error_tokens);
            this.forStmtSecond= forStmtParser.forStmtParser();
            this.rightParent=this.iterator.readNextToken();
        }else{
            this.forStmtSecond=null;
            this.rightParent=token;
        }
        StmtParser stmtParser = new StmtParser(this.iterator,this.error_tokens);
        this.stmt = stmtParser.parseStmt();
        StmtWhile stmtWhile = new StmtWhile(this.forTk, this.leftParent,this.forStmtFirst,this.semicnFirst,
                this.cond, this.semicnSecond,this.forStmtSecond,this.rightParent, this.stmt);
        return stmtWhile;
    }

}

package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class StmtBreakParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtBreak Attributes */
    public Token breakTk; // 'break'
    public Token semicn; // ';'

    public StmtBreakParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtBreak parseStmtBreak() {
        this.breakTk = this.iterator.readNextToken();
        Token token = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        if (!token.type.equals(TokenType.SEMICN)) {
            this.semicn = new Token(TokenType.SEMICN,this.breakTk.linenum,";");
            this.error_tokens.add(new Token(TokenType.SEMICN,this.breakTk.linenum,"i"));
        }else{
            this.semicn = this.iterator.readNextToken();
        }
        StmtBreak stmtBreak = new StmtBreak(this.breakTk, this.semicn);
        return stmtBreak;
    }
}

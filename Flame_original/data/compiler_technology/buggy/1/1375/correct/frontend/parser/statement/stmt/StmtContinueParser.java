package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class StmtContinueParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtContinue Attributes */
    public Token continueTk; // 'continue'
    public Token semicn; // ';'

    public StmtContinueParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtContinue parseStmtContinue() {
        this.continueTk = this.iterator.readNextToken();
        Token token = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        if (!token.type.equals(TokenType.SEMICN)) {
            this.semicn = new Token(TokenType.SEMICN,this.continueTk.linenum,";");
            this.error_tokens.add(new Token(TokenType.SEMICN,this.continueTk.linenum,"i"));
        }else{
            this.semicn = this.iterator.readNextToken();
        }
        StmtContinue stmtContinue = new StmtContinue(this.continueTk, this.semicn);
        return stmtContinue;
    }
}

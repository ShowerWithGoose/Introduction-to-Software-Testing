package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class StmtNullParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtNull Attributes */
    public Token semicn = null; // ';'

    public StmtNullParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtNull pasreStmtNull() {
        this.semicn = this.iterator.readNextToken();
        StmtNull stmtNull = new StmtNull(this.semicn);
        if (!this.semicn.type.equals(TokenType.SEMICN)) {
            System.out.println("EXPECT SEMICN IN STMTNULLPARSER");
        }
        return stmtNull;
    }
}

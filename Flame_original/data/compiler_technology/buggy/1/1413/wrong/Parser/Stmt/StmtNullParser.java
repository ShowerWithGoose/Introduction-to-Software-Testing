package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;

public class StmtNullParser {
    private TokenListIterator iterator;
    /* StmtNull Attributes */
    private Token semicn = null; // ';'

    public StmtNullParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtNull pasreStmtNull() {
        this.semicn = this.iterator.readNextToken();
        StmtNull stmtNull = new StmtNull(this.semicn);
        if (!this.semicn.getType().equals("SEMICN")) {
            System.out.println("EXPECT SEMICN IN STMTNULLPARSER");
        }
        return stmtNull;
    }
}

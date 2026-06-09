package frontend.Parser.Stmt;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class StmtVoidParser {
    private TokenListReader reader;
    private Token semicn;

    public StmtVoidParser(TokenListReader reader) {
        this.reader = reader;
    }

    public StmtVoid parseStmtVoid() {
        this.semicn = this.reader.getnextToken();
        StmtVoid stmtVoid = new StmtVoid(this.semicn);
        if (!this.semicn.getType().equals(TokenType.SEMICN)) {
            System.out.println("error: invalid stmtvoid");
        }
        return stmtVoid;
    }

}

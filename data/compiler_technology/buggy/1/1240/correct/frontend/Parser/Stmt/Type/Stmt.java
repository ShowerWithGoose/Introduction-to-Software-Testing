package frontend.Parser.Stmt.Type;

import frontend.Lexer.LexType;
import frontend.Lexer.TokenList;

public class Stmt {
    // Stmt --> StmtInter ';'
    private final StmtInter stmtInter;
    private final LexType semicolon;

    public Stmt(StmtInter stmt) {
        this.stmtInter = stmt;
        this.semicolon = null;
    }

    public Stmt(StmtInter stmt, TokenList tokens) {
        this.stmtInter = stmt;
        if (tokens.getToken().getType() != LexType.TokenType.SEMICN) {
            this.semicolon = null;
        } else {
            this.semicolon = tokens.getAndMove();
        }
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        if (stmtInter != null) {
            stringBuilder.append(stmtInter);
        }
        if (semicolon != null) {
            stringBuilder.append(semicolon);
        }
        stringBuilder.append("<Stmt>\n");
        return stringBuilder.toString();
    }
}

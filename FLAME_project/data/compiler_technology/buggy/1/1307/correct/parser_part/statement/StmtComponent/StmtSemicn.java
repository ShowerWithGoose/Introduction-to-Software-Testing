package parser_part.statement.StmtComponent;

import lexer_part.Token;

public class StmtSemicn implements StmtComponent {
    private Token semicn;

    public StmtSemicn(Token semicn) {
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        return semicn.toString();
    }
}

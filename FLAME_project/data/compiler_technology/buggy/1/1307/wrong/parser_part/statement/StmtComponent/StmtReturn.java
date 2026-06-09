package parser_part.statement.StmtComponent;

import lexer_part.Token;
import parser_part.expression.Exp;

public class StmtReturn implements StmtComponent {
    private Token returnToken;
    private Exp exp;
    private Token semicn;

    public StmtReturn(Token returnToken, Exp exp, Token semicn) {
        this.returnToken = returnToken;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(returnToken.toString());
        if (exp != null) {
            sb.append(exp);
        }
        sb.append(semicn.toString());
        return sb.toString();
    }

    public int checkReturn() {
        return exp == null ? 0 : 1;
    }

    public int getLineIndex() {
        return returnToken.getLineIndex();
    }
}

package parser_part.statement.StmtComponent;

import lexer_part.Token;
import parser_part.expression.Exp;

public class StmtExp implements StmtComponent {
    private Exp exp;
    private Token semicn;

    public StmtExp(Exp exp, Token semicn) {
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        return exp.toString() + semicn.toString();
    }

}

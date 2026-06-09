package parser.block;

import parser.exp.LVal;

public class GetCharStmt implements Stmt {
    private final LVal lVal;

    public GetCharStmt(LVal lVal) {
        this.lVal = lVal;
    }

    public String toString() {
        return this.lVal.toString() +
                "ASSIGN =\nGETCHARTK getchar\nLPARENT (\nRPARENT )\nSEMICN ;\n<Stmt>\n";
    }
}

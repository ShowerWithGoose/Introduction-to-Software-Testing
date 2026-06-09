package parser.block;

import parser.exp.LVal;

public class GetIntStmt implements Stmt {
    private final LVal lVal;

    public GetIntStmt(LVal lVal) {
        this.lVal = lVal;
    }

    public String toString() {
        return this.lVal.toString() +
                "ASSIGN =\nGETINTTK getint\nLPARENT (\nRPARENT )\nSEMICN ;\n<Stmt>\n";
    }
}

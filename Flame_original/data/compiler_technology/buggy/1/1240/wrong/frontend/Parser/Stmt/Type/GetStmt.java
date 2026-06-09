package frontend.Parser.Stmt.Type;

import frontend.Lexer.LexType;
import frontend.Parser.Exp.Type.LVal;

import java.util.ArrayList;

public class GetStmt implements StmtInter {
    // LVal '=' 'getint''('')'
    // LVal '=' 'getchar''('')'
    private final LVal lVal;
    private final ArrayList<LexType> sybmols;

    public GetStmt(LVal lVal, ArrayList<LexType> sybmols) {
        this.lVal = lVal;
        this.sybmols = sybmols;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        for (LexType sybmol : sybmols) {
            sb.append(sybmol);
        }
        return sb.toString();
    }
}

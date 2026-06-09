package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.expression.LVal;
import frontend.Parser.statement.StmtPort;

public class GetcharStmt implements StmtPort {
    private LVal lVal;
    private Token assignTk;
    private Token getcharTk;
    private Token lParent;
    private Token rParent;
    private Token semicn;

    public GetcharStmt(LVal lVal, Token assignTk, Token getcharTk, Token lParent, Token rParent, Token semicn) {
        this.lVal = lVal;
        this.assignTk = assignTk;
        this.getcharTk = getcharTk;
        this.lParent = lParent;
        this.rParent = rParent;
        this.semicn = semicn;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.grammarOutput());
        sb.append(assignTk.grammarOutput());
        sb.append(getcharTk.grammarOutput());
        sb.append(lParent.grammarOutput());
        sb.append(rParent.grammarOutput());
        sb.append(semicn.grammarOutput());
        return sb.toString();
    }
}

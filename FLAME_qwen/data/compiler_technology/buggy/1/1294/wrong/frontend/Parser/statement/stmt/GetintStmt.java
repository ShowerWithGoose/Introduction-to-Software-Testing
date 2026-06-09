package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.expression.LVal;
import frontend.Parser.statement.StmtPort;

public class GetintStmt implements StmtPort {
    private LVal lVal;
    private Token assignTk;
    private Token getintTk;
    private Token lParent;
    private Token rParent;
    private Token semicn;

    public GetintStmt(LVal lVal,Token assignTk, Token getintTk, Token lParent, Token rParent, Token semicn) {
        this.lVal = lVal;
        this.assignTk = assignTk;
        this.getintTk = getintTk;
        this.lParent = lParent;
        this.rParent = rParent;
        this.semicn = semicn;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.grammarOutput());
        sb.append(assignTk.grammarOutput());
        sb.append(getintTk.grammarOutput());
        sb.append(lParent.grammarOutput());
        sb.append(rParent.grammarOutput());
        sb.append(semicn.grammarOutput());
        return sb.toString();
    }
}

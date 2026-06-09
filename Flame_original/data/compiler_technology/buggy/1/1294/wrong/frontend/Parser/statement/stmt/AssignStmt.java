package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.LVal;
import frontend.Parser.statement.StmtPort;

public class AssignStmt implements StmtPort {
    private LVal lVal;
    private Token assignSign;
    private Exp exp;
    private Token semicn;

    public AssignStmt(LVal lVal, Token assignSign, Exp exp, Token semicn) {
        this.lVal = lVal;
        this.assignSign = assignSign;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.grammarOutput());
        sb.append(assignSign.grammarOutput());
        sb.append(exp.grammarOutput());
        sb.append(semicn.grammarOutput());
        return sb.toString();
    }
}

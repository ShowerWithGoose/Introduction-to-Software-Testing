package frontend.statement.stmt;
import frontend.SyntaxNode;
import frontend.Token;
import frontend.expression.Exp;
import frontend.expression.primaryexp.LVal;

public class ForStmt implements SyntaxNode {
    private final String name = "<ForStmt>";  // 文法中的标记
    private final LVal lval;
    private final Token assign;
    private final Exp exp;

    public ForStmt(LVal lval, Token assign, Exp exp) {
        this.lval = lval;
        this.assign = assign;
        this.exp = exp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lval.syntaxOutput());
        sb.append(this.assign.syntaxOutput());
        sb.append(this.exp.syntaxOutput());
        sb.append(name).append("\n");  // 输出 <ForStmt> 标记
        return sb.toString();
    }
}

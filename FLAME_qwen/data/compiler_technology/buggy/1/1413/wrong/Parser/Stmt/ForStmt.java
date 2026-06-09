package Parser.Stmt;

import Lexer.Token;
import Parser.Exp.Exp;
import Parser.LVal;
import Parser.TreeNode;

/**
 * @Description:
 * @date 2024/10/13
 */
public class ForStmt implements TreeNode {
    private final String value="<ForStmt>";
    private LVal lVal;
    private Token equal;
    private Exp exp;

    public ForStmt(LVal lVal, Token equal, Exp exp) {
        this.lVal = lVal;
        this.equal = equal;
        this.exp = exp;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(lVal.print_tree());
        sb.append(equal.toStringprint());
        sb.append(exp.print_tree());
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}

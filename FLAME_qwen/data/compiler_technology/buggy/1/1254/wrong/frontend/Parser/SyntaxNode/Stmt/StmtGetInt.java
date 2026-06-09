package frontend.Parser.SyntaxNode.Stmt;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.LVal;

public class StmtGetInt extends Stmt {
    private LVal lVal;
    private Token assign;
    private Token getIntTk;
    private Token lParent;
    private Token rParent;
    private Token semicn;

    public StmtGetInt(LVal lVal, Token assign, Token getIntTk, Token lParent, Token rParent, Token semicn) {
        this.lVal = lVal;
        this.assign = assign;
        this.getIntTk = getIntTk;
        this.lParent = lParent;
        this.rParent = rParent;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal);
        sb.append(assign);
        sb.append(getIntTk);
        sb.append(lParent);
        sb.append(rParent);
        sb.append(semicn);
        sb.append(name + "\n");
        return sb.toString();
    }
}

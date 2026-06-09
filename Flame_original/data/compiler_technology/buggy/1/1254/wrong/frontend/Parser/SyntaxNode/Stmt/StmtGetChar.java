package frontend.Parser.SyntaxNode.Stmt;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.LVal;

public class StmtGetChar extends Stmt {
    private LVal lVal;
    private Token assign;
    private Token getCharTk;
    private Token lParent;
    private Token rParent;
    private Token semicn;

    public StmtGetChar(LVal lVal, Token assign, Token getCharTk, Token lParent, Token rParent, Token semicn) {
        this.lVal = lVal;
        this.assign = assign;
        this.getCharTk = getCharTk;
        this.lParent = lParent;
        this.rParent = rParent;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal);
        sb.append(assign);
        sb.append(getCharTk);
        sb.append(lParent);
        sb.append(rParent);
        sb.append(semicn);
        sb.append(name + "\n");
        return sb.toString();
    }
}

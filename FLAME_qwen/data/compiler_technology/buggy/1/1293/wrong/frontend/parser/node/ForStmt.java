package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class ForStmt extends TreeNode {
    private LVal lVal = null;

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setAssignToken(Token assignToken) {
        this.assignToken = assignToken;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    private Token assignToken = null;
    private Exp exp = null;
    public ForStmt(ParserType parserType, Token token) {
        super(parserType, token);
    }
}

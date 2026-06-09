package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;

public class ForStmt implements SyntaxNode {
    private final String name = "<ForStmt>";
    private LVal lVal;
    private Token assign;
    private Exp exp;

    public ForStmt(LVal lVal, Token assign, Exp exp) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal);
        sb.append(assign);
        sb.append(exp);
        sb.append(name + "\n");
        return sb.toString();
    }
}

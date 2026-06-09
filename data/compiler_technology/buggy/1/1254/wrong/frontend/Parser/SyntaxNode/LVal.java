package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
/*
 LVal â†’ Ident ['[' Exp ']'] // k
 */
public class LVal implements SyntaxNode {
    private final String name = "<LVal>";
    private Token ident;
    private Token lbrack = null;
    private Exp exp = null;
    private Token rbrack = null;

    public LVal(Token ident) {
        this.ident = ident;
    }

    public LVal(Token ident, Token lbrack, Exp exp, Token rbrack) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.exp = exp;
        this.rbrack = rbrack;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident);
        if (lbrack != null) {
            sb.append(lbrack);
            sb.append(exp);
            sb.append(rbrack);
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}

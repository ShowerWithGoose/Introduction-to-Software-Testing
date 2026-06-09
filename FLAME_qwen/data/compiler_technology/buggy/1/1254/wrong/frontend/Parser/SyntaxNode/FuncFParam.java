package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
/*
FuncFParam â†’ BType Ident ['[' ']'] // k
 */
public class FuncFParam implements SyntaxNode {
    private final String name = "<FuncFParam>";
    private BType bType;
    private Token ident;
    private Token lbrack = null;
    private Token rbrack = null;

    public FuncFParam(BType bType, Token ident, Token lbrack, Token rbrack) {
        this.bType = bType;
        this.ident = ident;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType);
        sb.append(ident);
        if (lbrack != null) {
            sb.append(lbrack);
            sb.append(rbrack);
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}

package frontend.Parser.SyntaxNode;
import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.ConstInitVal.ConstInitVal;
/*
ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal
 */

public class ConstDef implements SyntaxNode {
    private final String name = "<ConstDef>";
    private Token ident;
    private Token lbrack = null;
    private ConstExp constExp = null;
    private Token rbrack = null;
    private Token assign;
    private ConstInitVal constInitVal;

    public ConstDef(Token ident, Token lbrack, ConstExp constExp,
                    Token rbrack, Token assign, ConstInitVal constInitVal) {
        this.ident = ident;
        this.assign = assign;
        this.constInitVal = constInitVal;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident);
        if (lbrack != null) {
            sb.append(lbrack);
            sb.append(constExp);
            sb.append(rbrack);
        }
        sb.append(assign);
        sb.append(constInitVal);
        sb.append(name + "\n");
        return sb.toString();
    }
}

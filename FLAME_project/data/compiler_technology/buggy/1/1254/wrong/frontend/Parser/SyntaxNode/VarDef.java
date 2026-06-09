package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.InitVal.InitVal;

/*
VarDef â†’ Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
 */
public class VarDef implements SyntaxNode {
    private final String name = "<VarDef>";
    private Token ident;
    private Token lbrack = null;
    private ConstExp constExp = null;
    private Token rbrack = null;
    private Token assign = null;
    private InitVal initVal = null;

    public VarDef(Token ident, Token lbrack, ConstExp constExp, Token rbrack,
                  Token assign, InitVal initVal) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
        this.assign = assign;
        this.initVal = initVal;
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
        if (assign != null) {
            sb.append(assign);
            sb.append(initVal);
        }
        sb.append(name + '\n');
        return sb.toString();
    }
}

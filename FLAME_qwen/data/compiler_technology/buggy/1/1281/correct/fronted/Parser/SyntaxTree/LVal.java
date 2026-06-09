package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/12 21:31
 */
public class LVal implements SyntaxNode{
    private final String name = "<LVal>";
    private Token ident;
    private Token leftBrack; // '['
    private Exp exp;
    private Token rightBrack; // ']'

    public LVal(Token ident, Token leftBrack, Exp exp, Token rightBrack) {
        this.ident = ident;
        this.leftBrack = leftBrack;
        this.exp = exp;
        this.rightBrack = rightBrack;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.output());
        if(this.leftBrack != null){
            sb.append(this.leftBrack.output());
            sb.append(this.exp.output());
            sb.append(this.rightBrack.output());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

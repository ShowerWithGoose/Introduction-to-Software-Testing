package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 10:47
 */
public class FuncFParam implements SyntaxNode{
    private final String name = "<FuncFParam>";
    private BType bType;
    private Token ident;
    private Token leftBrack; // '['  may
    private Token rightBracket; // ']'  may

    public FuncFParam(BType bType, Token ident, Token leftBrack, Token rightBracket) {
        this.bType = bType;
        this.ident = ident;
        this.leftBrack = leftBrack;
        this.rightBracket = rightBracket;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.bType.output());
        sb.append(this.ident.output());
        if(this.leftBrack != null){
            sb.append(this.leftBrack.output());
            sb.append(this.rightBracket.output());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

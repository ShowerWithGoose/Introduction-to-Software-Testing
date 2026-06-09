package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 1:30
 */
public class VarDef implements SyntaxNode{
    private final String name = "<VarDef>";
    private Token ident;
    private Token leftBrack; // '['  may
    private ConstExp constExp;  // may
    private Token rightBracket; // ']'  may
    private Token equal; // '='  may
    private InitVal Initval;  // may

    public VarDef(Token ident, Token leftBrack, ConstExp constExp, Token rightBracket, Token equal, InitVal initval) {
        this.ident = ident;
        this.leftBrack = leftBrack;
        this.constExp = constExp;
        this.rightBracket = rightBracket;
        this.equal = equal;
        Initval = initval;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.output());
        if(this.leftBrack != null){
            sb.append(this.leftBrack.output());
            sb.append(this.constExp.output());
            sb.append(this.rightBracket.output());
        }
        if(this.equal != null){
            sb.append(this.equal.output());
            sb.append(this.Initval.output());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

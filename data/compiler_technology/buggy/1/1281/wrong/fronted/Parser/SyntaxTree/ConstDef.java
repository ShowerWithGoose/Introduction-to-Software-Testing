package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/12 15:42
 */
public class ConstDef implements SyntaxNode{
    private final String name = "<ConstDef>";
    private Token ident;
    private Token leftBrack; // '['
    private ConstExp constExp;
    private Token rightBracket; // ']'
    private Token equal; // '='
    private ConstInitVal constInitval;

    public ConstDef(Token ident,
                    Token leftBrack,
                    ConstExp constExp,
                    Token rightBracket,
                    Token equal,
                    ConstInitVal constInitval) {
        this.ident = ident;
        this.leftBrack = leftBrack;
        this.constExp = constExp;
        this.rightBracket = rightBracket;
        this.equal = equal;
        this.constInitval = constInitval;
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
        sb.append(this.equal.output());
        sb.append(this.constInitval.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

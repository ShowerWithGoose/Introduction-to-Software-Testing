package frontend.parser.expression.primaryExp;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class LVal implements PrimaryExpUnit{
    //LVal â†’ Ident ['[' Exp ']']
    private String name = "<LVal>";
    private Token ident;
    private Token leftBracket;
    private Token rightBracket;
    private Exp exp;

    public LVal(Token ident, Token leftBracket, Token rightBracket,
                Exp exp) {
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
        this.exp = exp;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxPrint());
        if (leftBracket != null && exp != null && rightBracket != null) {
            sb.append(leftBracket.syntaxPrint());
            sb.append(exp.syntaxPrint());
            sb.append(rightBracket.syntaxPrint());
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}

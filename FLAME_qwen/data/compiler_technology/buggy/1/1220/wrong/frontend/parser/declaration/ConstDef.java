package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.expression.ConstExp;
import frontend.parser.init.ConstInitVal;

public class ConstDef implements SyntaxUnit {
    //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    private final String name = "<ConstDef>";
    private Token ident = null;
    private Token leftBracket = null; //[
    private ConstExp constExp = null;
    private Token rightBracket = null; //]
    private Token assign = null; //=
    private ConstInitVal constInitVal = null;

    public ConstDef(Token ident, Token leftBracket, ConstExp constExp, Token rightBracket,
                    Token assign, ConstInitVal constInitVal) {
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.constExp = constExp;
        this.rightBracket = rightBracket;
        this.assign = assign;
        this.constInitVal = constInitVal;
    }

    @Override
    public String syntaxPrint() {
        //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxPrint());
        if (leftBracket != null && constExp != null
                && rightBracket != null) {
            sb.append(leftBracket.syntaxPrint());
            sb.append(constExp.syntaxPrint());
            sb.append(rightBracket.syntaxPrint());
        }
        sb.append(assign.syntaxPrint());
        sb.append(constInitVal.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}

package frontend.parser.declaration.constant;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;
import frontend.parser.declaration.constant.constInitVal.ConstInitVal;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

/**
 * ConstDef 常量定义类
 * <ConstDef> -> <Ident> [ '[' <ConstExp> ']' ] '=' <ConstInitVal>
 */
public class ConstDef implements SyntaxNode {
    private final String name = "<ConstDef>";
    private Ident ident;
    private Token leftBrack; // '[', MAY exist
    private ConstExp constExp; // MAY exist
    private Token rightBracket; // ']', MAY exist
    private Token eq; // '='
    private ConstInitVal constInitval;

    public ConstDef(Ident ident,
                    Token leftBrack,
                    ConstExp constExp,
                    Token rightBracket,
                    Token eq,
                    ConstInitVal constInitval) {
        this.ident = ident;
        this.leftBrack = leftBrack;
        this.constExp = constExp;
        this.rightBracket = rightBracket;
        this.eq = eq;
        this.constInitval = constInitval;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.syntaxOutput());
        if (this.leftBrack != null && this.rightBracket != null && this.constExp != null) {
            sb.append(this.leftBrack.syntaxOutput());
            sb.append(this.constExp.syntaxOutput());
            sb.append(this.rightBracket.syntaxOutput());

        }
        sb.append(this.eq.syntaxOutput());
        sb.append(this.constInitval.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

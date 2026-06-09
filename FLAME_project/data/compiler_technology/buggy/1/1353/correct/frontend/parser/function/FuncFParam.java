package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;
import frontend.parser.declaration.BType;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

/**
 * FuncFParam 函数形参类
 * <FuncFParam> -> <BType> <Ident> [ '[' ']' ]
 */
public class FuncFParam implements SyntaxNode {
    private final String name = "<FuncFParam>";
    private BType btype;
    private Ident ident;
    private Token leftBracket = null; // '[' MAY exist
    private Token rightBracket = null; // ']' MAY exist

    public FuncFParam(BType btype,
                      Ident ident) {
        this.btype = btype;
        this.ident = ident;
    }

    public FuncFParam(BType btype,
                      Ident ident,
                      Token leftBracket,
                      Token rightBrack) {
        this(btype, ident);
        this.leftBracket = leftBracket;
        this.rightBracket = rightBrack;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.btype.syntaxOutput());
        sb.append(this.ident.syntaxOutput());
        if (this.leftBracket != null && this.rightBracket != null) {
            sb.append(this.leftBracket.syntaxOutput());
            sb.append(this.rightBracket.syntaxOutput());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

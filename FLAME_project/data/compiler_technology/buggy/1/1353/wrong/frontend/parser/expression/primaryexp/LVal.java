package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

/**
 * LVal 左值表达式类
 * <LVal> -> <Ident> [ '[' <Exp> ']' ]
 */
public class LVal implements PrimaryExpEle {
    /**
     * 属性：
     * name 该语法类名
     * ident <Ident>
     * leftBracket '['，可选
     * left <Exp>，可选
     * RightBracket ']'，可选
     */
    private final String name = "<LVal>";
    private Ident ident;
    private Token leftBracket;
    private Exp exp;
    private Token rightBracket;

    public LVal(Ident ident,
                Token leftBracket,
                Exp exp,
                Token rightBracket) {
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.exp = exp;
        this.rightBracket = rightBracket;
    }

    public LVal(Ident ident) {
        this.ident = ident;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        if (leftBracket != null && exp != null && rightBracket != null) {
            sb.append(leftBracket.syntaxOutput());
            sb.append(exp.syntaxOutput());
            sb.append(rightBracket.syntaxOutput());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
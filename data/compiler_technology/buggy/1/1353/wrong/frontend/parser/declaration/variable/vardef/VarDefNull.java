package frontend.parser.declaration.variable.vardef;

import frontend.lexer.Token;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

/**
 * <VarDef> 未初始化子节点接口
 * <Ident> [ '[' <ConstExp> ']' ]
 */
public class VarDefNull implements VarDefEle {
    private Ident ident;
    private Token leftBrace;
    private ConstExp constExp;
    private Token rightBrace;

    public VarDefNull(Ident ident,
                      Token leftBrace,
                      ConstExp constExp,
                      Token rightBrace) {
        this.ident = ident;
        this.leftBrace = leftBrace;
        this.constExp = constExp;
        this.rightBrace = rightBrace;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        if (this.leftBrace != null && this.constExp != null && this.rightBrace != null) {
            sb.append(this.leftBrace.syntaxOutput());
            sb.append(this.constExp.syntaxOutput());
            sb.append(this.rightBrace.syntaxOutput());
        }
        return sb.toString();
    }
}

package frontend.parser.declaration.variable.vardef;

import frontend.lexer.Token;
import frontend.parser.declaration.variable.initval.InitVal;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

/**
 * <VarDef> 已初始化子节点接口
 * <Ident> [ '[' <ConstExp> ']' ] '=' <InitVal>
 */
public class VarDefInit implements VarDefEle {
    private Ident ident;
    private Token leftBrace; // '['
    private ConstExp constExp;
    private Token rightBrace; // ']'
    private Token eq;
    private InitVal initVal;

    public VarDefInit(Ident ident,
                      Token leftBrace,
                      ConstExp constExp,
                      Token rightBrace,
                      Token eq,
                      InitVal initVal) {
        this.ident = ident;
        this.leftBrace = leftBrace;
        this.constExp = constExp;
        this.rightBrace = rightBrace;
        this.eq = eq;
        this.initVal = initVal;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        if (leftBrace != null && constExp != null && rightBrace != null) {
            sb.append(this.leftBrace.syntaxOutput());
            sb.append(this.constExp.syntaxOutput());
            sb.append(this.rightBrace.syntaxOutput());
        }
        sb.append(this.eq.syntaxOutput());
        sb.append(this.initVal.syntaxOutput());
        return sb.toString();
    }
}

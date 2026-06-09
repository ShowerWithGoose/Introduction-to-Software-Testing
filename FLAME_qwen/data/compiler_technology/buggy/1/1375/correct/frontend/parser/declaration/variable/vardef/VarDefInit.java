package frontend.parser.declaration.variable.vardef;

import frontend.lexer.Token;
import frontend.parser.declaration.variable.initval.InitVal;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

public class VarDefInit implements VarDefEle{
    public Ident ident;
    public Token leftBraces; // '['
    public ConstExp constExps;
    public Token rightBraces; // ']'
    public Token eq;
    public InitVal initVal;

    public VarDefInit(Ident ident,
                      Token leftBraces,
                      ConstExp constExps,
                      Token rightBraces,
                      Token eq,
                      InitVal initVal) {
        this.ident = ident;
        this.leftBraces = leftBraces;
        this.constExps = constExps;
        this.rightBraces = rightBraces;
        this.eq = eq;
        this.initVal = initVal;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        if (leftBraces != null && constExps != null && rightBraces != null) {
                sb.append(this.leftBraces.syntaxOutput());
                sb.append(this.constExps.syntaxOutput());
                sb.append(this.rightBraces.syntaxOutput());
        }
        sb.append(this.eq.syntaxOutput());
        sb.append(this.initVal.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        return this.initVal.my_line_num();
    }
}

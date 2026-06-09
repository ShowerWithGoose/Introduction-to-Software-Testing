package frontend.parser.declaration.variable.vardef;

import frontend.lexer.Token;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

public class VarDefNull implements VarDefEle{
    public Ident ident;
    public Token leftBraces;
    public ConstExp constExps;
    public Token rightBraces;

    public VarDefNull(Ident ident,
                      Token leftBraces,
                      ConstExp constExps,
                      Token rightBraces) {
        this.ident = ident;
        this.leftBraces = leftBraces;
        this.constExps = constExps;
        this.rightBraces = rightBraces;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        if (this.leftBraces != null && this.constExps != null && this.rightBraces != null) {
                sb.append(this.leftBraces.syntaxOutput());
                sb.append(this.constExps.syntaxOutput());
                sb.append(this.rightBraces.syntaxOutput());
        }
        return sb.toString();
    }
    public int my_line_num() {
        if(leftBraces==null){
            return this.ident.my_line_num();
        }else if(rightBraces==null){
            return this.constExps.my_line_num();
        }else{
            return rightBraces.linenum;
        }
    }
}

package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

public class LVal implements PrimaryExpEle{
    public final String name = "<LVal>";
    public Ident ident;
    public Token leftBrackets;
    public Exp exps;
    public Token rightBrackets;

    public LVal(Ident ident)
    {
        this.ident = ident;
        this.leftBrackets = null;
        this.exps = null;
        this.rightBrackets = null;
    }
    public LVal(Ident ident,
                Token leftBrackets,
                Exp exps,
                Token rightBrackets) {
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.exps = exps;
        this.rightBrackets = rightBrackets;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        if (leftBrackets != null && exps != null && rightBrackets != null) {
                sb.append(leftBrackets.syntaxOutput());
                sb.append(exps.syntaxOutput());
                sb.append(rightBrackets.syntaxOutput());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        if(this.leftBrackets==null){
            return this.ident.my_line_num();
        }else if(this.rightBrackets==null){
            return this.exps.my_line_num();
        }else{
            return this.rightBrackets.linenum;
        }
    }
}

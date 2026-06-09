package frontend.parser.declaration.constant;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;
import frontend.parser.declaration.constant.constinitval.ConstInitVal;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

public class ConstDef implements SyntaxNode{
    public final String name = "<ConstDef>";
    public Ident ident;
    public Token leftBracks; // '['
    public ConstExp constExps;
    public Token rightBrackets; // ']'
    public Token eq; // '='
    public ConstInitVal constInitval;
    public ConstDef(Ident ident,
                    Token leftBracks,
                    ConstExp constExps,
                    Token rightBrackets,
                    Token eq,
                    ConstInitVal constInitval) {
        this.ident = ident;
        this.leftBracks = leftBracks;
        this.constExps = constExps;
        this.rightBrackets = rightBrackets;
        this.eq = eq;
        this.constInitval = constInitval;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.syntaxOutput());
        if (this.leftBracks != null && this.rightBrackets != null && this.constExps != null) {
                sb.append(this.leftBracks.syntaxOutput());
                sb.append(this.constExps.syntaxOutput());
                sb.append(this.rightBrackets.syntaxOutput());
        }
        sb.append(this.eq.syntaxOutput());
        sb.append(this.constInitval.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        return this.constInitval.my_line_num();
    }
}

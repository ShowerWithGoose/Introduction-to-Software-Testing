package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;
import frontend.parser.declaration.BType;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

public class FuncFParam implements SyntaxNode {
    public final String name = "<FuncFParam>";
    public BType btype;
    public Ident ident;
    public Token leftBracketFirst = null; // '[' MAY exist
    public Token rightBracketFirst = null; // ']' MAY exist
    public FuncFParam(BType btype, Ident ident) {
        this.btype = btype;
        this.ident = ident;
    }
    public FuncFParam(BType btype,
                      Ident ident,
                      Token leftBracketFirst,
                      Token rightBrackFirst) {
        this.btype = btype;
        this.ident = ident;
        this.leftBracketFirst = leftBracketFirst;
        this.rightBracketFirst = rightBrackFirst;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.btype.syntaxOutput());
        sb.append(this.ident.syntaxOutput());
        if (this.leftBracketFirst != null && this.rightBracketFirst != null) {
            sb.append(this.leftBracketFirst.syntaxOutput());
            sb.append(this.rightBracketFirst.syntaxOutput());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num(){
        if(leftBracketFirst != null){
            if(rightBracketFirst != null){
                return rightBracketFirst.linenum;
            }else{
                return leftBracketFirst.linenum;
            }
        }else{
            return this.ident.my_line_num();
        }
    }


}

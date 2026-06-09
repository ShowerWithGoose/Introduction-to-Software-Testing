package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.parser.expression.FuncRParams;
import frontend.parser.terminal.Ident;

public class UnaryExpFunc implements UnaryExpEle{
    public Ident ident;
    public FuncRParams funcRParams = null; // MAY exist
    public Token leftParent;
    public Token rightParent;
    public UnaryExpFunc(Ident ident,
                        Token leftParent,
                        Token rightParent) {
        this.ident = ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
    }

    public UnaryExpFunc(Ident ident,
                        FuncRParams funcRParams,
                        Token leftParent,
                        Token rightParent) {
        this.ident = ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.funcRParams = funcRParams;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        sb.append(leftParent.syntaxOutput());
        if (funcRParams != null) {
            sb.append(this.funcRParams.syntaxOutput());
        }
        sb.append(rightParent.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        if(this.rightParent!=null){
            return this.rightParent.linenum;
        }else{
            if(this.funcRParams!=null){
                return this.funcRParams.my_line_num();
            }else{
                return this.leftParent.linenum;
            }
        }
    }
}

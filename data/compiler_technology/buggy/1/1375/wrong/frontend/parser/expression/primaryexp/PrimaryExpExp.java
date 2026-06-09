package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class PrimaryExpExp implements PrimaryExpEle{
    public Token leftParent; // must be '('
    public Exp exp;
    public Token rightParent; // must be ')'

    public PrimaryExpExp(Token leftBracket, Exp exp, Token rightParent) {
        this.leftParent = leftBracket;
        this.exp = exp;
        this.rightParent = rightParent;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(leftParent.syntaxOutput());
        sb.append(exp.syntaxOutput());
        sb.append(rightParent.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        if(this.rightParent!=null) {
            return this.rightParent.linenum;
        }else{
            return this.exp.my_line_num();
        }
    }
}

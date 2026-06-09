package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;
import frontend.parser.expression.Exp;
import frontend.parser.expression.primaryexp.LVal;

public class ForStmt implements SyntaxNode {
    public String name = "<ForStmt>";
    public LVal lval;
    public Token eq;
    public Exp exp;
    public ForStmt(
            LVal lval,
            Token eq,
            Exp exp) {
        this.lval = lval;
        this.eq = eq;
        this.exp = exp;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lval.syntaxOutput());
        sb.append(this.eq.syntaxOutput());
        sb.append(this.exp.syntaxOutput());
        sb.append(this.name +"\n");
        return sb.toString();
    }
    public int my_line_num(){
        return this.exp.my_line_num();
    }

}

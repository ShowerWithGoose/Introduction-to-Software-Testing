package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class StmtReturn implements StmtEle {
    public Token returnTk; // 'return'
    public Exp exp; // MAY exist
    public Token semicn; // ';'

    public StmtReturn(Token returnTk,
                      Token semicn) {
        this.returnTk = returnTk;
        this.semicn = semicn;
    }

    public StmtReturn(Token returnTk,
                      Exp exp,
                      Token semicn) {
        this(returnTk, semicn);
        this.exp = exp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.returnTk.syntaxOutput());
        if (exp != null) {
            sb.append(this.exp.syntaxOutput());
        }
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num(){
        if(semicn!=null){
            return semicn.linenum;
        }else if(exp!=null){
            return exp.my_line_num();
        }else{
            return returnTk.linenum;
        }
    }
}

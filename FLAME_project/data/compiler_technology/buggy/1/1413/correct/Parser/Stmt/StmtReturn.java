package Parser.Stmt;


import Lexer.Token;
import Parser.Exp.Exp;

public class StmtReturn implements StmtEle {
    private Token returnTk; // 'return'
    private Exp exp; // MAY exist
    private Token semicn; // ';'

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
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(returnTk.toStringprint());
        if(exp!=null){
            sb.append(exp.print_tree());
        }
        sb.append(this.semicn.toStringprint());
        return sb.toString();
    }
}

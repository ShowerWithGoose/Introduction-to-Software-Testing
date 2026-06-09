package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.expression.primaryexp.LVal;

public class StmtGetint implements StmtEle {
    public LVal lval;
    public Token eq; // '='
    public Token getint; // 'getint'
    public Token leftParent; // '('
    public Token rightParent; // ')'
    public Token semicn; // ';'

    public StmtGetint(LVal lval,
                      Token eq,
                      Token getint,
                      Token leftParent,
                      Token rightParent,
                      Token semicn) {
        this.lval = lval;
        this.eq = eq;
        this.getint = getint;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lval.syntaxOutput());
        sb.append(this.eq.syntaxOutput());
        sb.append(this.getint.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num(){
        if(semicn!=null){
            return semicn.linenum;
        }else if(rightParent!=null){
            return rightParent.linenum;
        }else{
            return leftParent.linenum;
        }
    }
}

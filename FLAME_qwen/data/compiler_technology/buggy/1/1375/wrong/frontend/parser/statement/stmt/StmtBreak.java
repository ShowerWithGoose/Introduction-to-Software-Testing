package frontend.parser.statement.stmt;

import frontend.lexer.Token;

public class StmtBreak implements StmtEle {
    public Token breakTk; // 'break'
    public Token semicn; // ';'

    public StmtBreak(Token breakTk,
                     Token semicn) {
        this.breakTk = breakTk;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.breakTk.syntaxOutput());
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num(){
        if(semicn!=null){
            return semicn.linenum;
        }else{
            return breakTk.linenum;
        }
    }
}

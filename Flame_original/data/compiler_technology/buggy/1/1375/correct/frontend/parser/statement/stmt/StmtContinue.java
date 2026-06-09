package frontend.parser.statement.stmt;

import frontend.lexer.Token;

public class StmtContinue implements StmtEle {
    public Token continueTk; // 'continue'
    public Token semicn; // ';'

    public StmtContinue(Token continueTk,
                        Token semicn) {
        this.continueTk = continueTk;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.continueTk.syntaxOutput());
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num(){
        if(semicn!=null)return semicn.linenum;
        else return continueTk.linenum;
    }
}

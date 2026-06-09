package frontend.parser.statement.stmt;

import frontend.lexer.Token;

/**
 * 仅有分号
 * Stmt -> ';'
 */
public class StmtNull implements StmtEle {
    public Token semicn;

    public StmtNull(Token semicn) {
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num(){
        return semicn.linenum;
    }
}

package frontend.Parser.Stmt;

import frontend.Token;

public class StmtVoid implements StmtInf{
    private Token semicn;

    public StmtVoid(Token semicn) {
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(semicn.toString());
        return sb.toString();
    }

}

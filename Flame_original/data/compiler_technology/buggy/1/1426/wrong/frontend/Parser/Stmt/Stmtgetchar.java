package frontend.Parser.Stmt;

import frontend.Token;
import frontend.Parser.PriExp.LVal;

//| LVal '=' 'getchar''('')'';'
public class Stmtgetchar implements StmtInf{
    private LVal lVal;
    private Token equal;
    private Token getchar;
    private Token lparent;
    private Token rparent;
    private Token semicn;

    public Stmtgetchar(LVal lVal,Token equal, Token getchar, Token lparent, Token rparent, Token semicn) {
        this.lVal = lVal;
        this.equal = equal;
        this.getchar = getchar;
        this.lparent = lparent;
        this.rparent = rparent;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lVal.Parser_Output());
        sb.append(this.equal.toString());
        sb.append(this.getchar.toString());
        sb.append(this.lparent.toString());
        sb.append(this.rparent.toString());
        sb.append(this.semicn.toString());
        return sb.toString();
    }
}

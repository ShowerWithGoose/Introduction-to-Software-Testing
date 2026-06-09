package frontend.Parser.Stmt;

import frontend.Token;
import frontend.Parser.PriExp.LVal;

//| LVal '=' 'getint''('')'';'
public class Stmtgetint implements StmtInf{
    private LVal lVal;
    private Token equal;
    private Token getint;
    private Token lparent;
    private Token rparent;
    private Token semicn;

    public Stmtgetint(LVal lVal,Token equal, Token getint, Token lparent, Token rparent, Token semicn) {
        this.lVal = lVal;
        this.equal = equal;
        this.getint = getint;
        this.lparent = lparent;
        this.rparent = rparent;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lVal.Parser_Output());
        sb.append(this.equal.toString());
        sb.append(this.getint.toString());
        sb.append(this.lparent.toString());
        sb.append(this.rparent.toString());
        sb.append(this.semicn.toString());
        return sb.toString();
    }
}

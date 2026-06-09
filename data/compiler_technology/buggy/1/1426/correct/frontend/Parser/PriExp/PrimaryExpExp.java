package frontend.Parser.PriExp;

import frontend.Token;
import frontend.Parser.Exp.Exp;

public class PrimaryExpExp implements PrimaryExpInf{
    private Token lparent;
    private Exp exp;
    private Token rparent;

    public PrimaryExpExp(Token lparent, Exp exp, Token rparent) {
        this.lparent = lparent;
        this.exp = exp;
        this.rparent = rparent;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lparent.toString());
        sb.append(this.exp.Parser_Output());
        sb.append(this.rparent.toString());
        return sb.toString();
    }
}

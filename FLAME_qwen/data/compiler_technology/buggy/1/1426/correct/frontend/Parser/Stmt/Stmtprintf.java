package frontend.Parser.Stmt;

import frontend.Token;
import frontend.Parser.Exp.Exp;
import frontend.Parser.solid.StringConst;

import java.util.ArrayList;

//| 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
public class Stmtprintf implements StmtInf{
    private Token print;
    private Token lparent;
    private StringConst stringConst;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();
    private Token rparent;
    private Token semicn;

    public Stmtprintf(Token print, Token lparent, StringConst stringConst, Token rparent, Token semicn) {
        this.print = print;
        this.lparent = lparent;
        this.stringConst = stringConst;
        this.rparent = rparent;
        this.semicn = semicn;
    }
    public Stmtprintf(Token print, Token lparent, StringConst stringConst, ArrayList<Token> commas, ArrayList<Exp> exps, Token rparent, Token semicn) {
        this.print = print;
        this.lparent = lparent;
        this.stringConst = stringConst;
        this.commas = commas;
        this.exps = exps;
        this.rparent = rparent;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.print.toString());
        sb.append(this.lparent.toString());
        sb.append(this.stringConst.Parser_Output());
        if(this.commas != null && this.exps != null && this.commas.size() == this.exps.size()) {
            for(int i = 0; i < this.commas.size(); i++) {
                sb.append(this.commas.get(i).toString());
                sb.append(this.exps.get(i).Parser_Output());
            }
        }
        sb.append(this.rparent.toString());
        sb.append(this.semicn.toString());
        return sb.toString();
    }
}

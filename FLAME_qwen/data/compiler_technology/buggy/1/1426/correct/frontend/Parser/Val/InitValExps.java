package frontend.Parser.Val;

import frontend.Token;
import frontend.Parser.Exp.Exp;

import java.util.ArrayList;

public class InitValExps implements InitValInf{
    private Token lbrace;
    private Exp first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();
    private Token rbrace;

    public InitValExps(Token lbrace, Exp first, ArrayList<Token> commas, ArrayList<Exp> exps, Token rbrace) {
        this.lbrace = lbrace;
        this.first = first;
        this.commas = commas;
        this.exps = exps;
        this.rbrace = rbrace;
    }
     public InitValExps(Token lbrace, Exp first,  Token rbrace) {
        this.lbrace = lbrace;
        this.first = first;
        this.rbrace = rbrace;
     }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lbrace.toString());
        if(this.first != null) {
            sb.append(this.first.Parser_Output());
            if(this.commas != null && this.exps != null && this.commas.size() == this.exps.size()) {
                for(int i = 0; i < this.commas.size(); i++) {
                    sb.append(this.commas.get(i).toString());
                    sb.append(this.exps.get(i).Parser_Output());
                }
            }
        }
        sb.append(this.rbrace.toString());
        return sb.toString();
    }
}

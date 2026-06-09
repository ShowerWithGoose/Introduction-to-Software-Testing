package frontend.Parser.PriExp;

import frontend.Token;
import frontend.Parser.Exp.Exp;
import frontend.Parser.solid.Ident;

import java.util.ArrayList;

//左值表达式 LVal → Ident ['[' Exp ']'] //1.普通变量、常量 2.一维数组
public class LVal implements PrimaryExpInf{
    private final String name = "<LVal>";
    private Ident ident = null;
    private ArrayList<Token> lbrace = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();
    private ArrayList<Token> rbrace = new ArrayList<>();

    public LVal(Ident ident){
        this.ident = ident;
    }
    public LVal(Ident ident, ArrayList<Token> lbrace, ArrayList<Exp> exps, ArrayList<Token> rbrace){
        this.ident = ident;
        this.lbrace = lbrace;
        this.exps = exps;
        this.rbrace = rbrace;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.Parser_Output());
        if(this.lbrace != null && this.exps != null && this.rbrace != null && this.lbrace.size() == this.rbrace.size() && this.lbrace.size() == this.exps.size()){
            for(int i = 0; i < this.lbrace.size(); i++){
                sb.append(this.lbrace.get(i).toString());
                sb.append(this.exps.get(i).Parser_Output());
                sb.append(this.rbrace.get(i).toString());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

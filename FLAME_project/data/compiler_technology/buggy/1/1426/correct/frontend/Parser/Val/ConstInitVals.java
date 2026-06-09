package frontend.Parser.Val;

import frontend.Token;
import frontend.Parser.Exp.ConstExp;

import java.util.ArrayList;

//常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' |
//StringConst // 1.常表达式初值 2.一维数组初值
public class ConstInitVals implements ConstInitValInf{
    private Token lbrace;
    private ConstExp first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<ConstExp> constExps = new ArrayList<>();
    private Token rbrace;

    public ConstInitVals(Token lbrace, ConstExp first, ArrayList<Token> commas, ArrayList<ConstExp> constExps, Token rbrace) {
        this.lbrace = lbrace;
        this.first = first;
        this.commas = commas;
        this.constExps = constExps;
        this.rbrace = rbrace;
    }
    public ConstInitVals(Token lbrace, ConstExp first, Token rbrace) {
        this.lbrace = lbrace;
        this.first = first;
        this.rbrace = rbrace;
    }
    public ConstInitVals(Token lbrace, Token rbrace) {
        this.lbrace = lbrace;
        this.rbrace = rbrace;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lbrace.toString());
        if(this.first != null) {
            sb.append(this.first.Parser_Output());
            if(this.commas != null && this.constExps != null && this.constExps.size() == this.commas.size()) {
                for(int i = 0; i < this.constExps.size(); i++) {
                    sb.append(this.commas.get(i).toString());
                    sb.append(this.constExps.get(i).Parser_Output());
                }
            }
        }
        sb.append(this.rbrace.toString());
        return sb.toString();
    }
}

package frontend.Parser.Def;

import frontend.Token;
import frontend.Parser.Val.ConstInitVal;
import frontend.Parser.Exp.ConstExp;
import frontend.Parser.Output;
import frontend.Parser.solid.Ident;

import java.util.ArrayList;
//常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
public class ConstDef implements Output {
    private final String name = "<ConstDef>";
    private Ident ident;
    private ArrayList<Token> lbracks = new ArrayList<>();
    private ArrayList<ConstExp> constExps = new ArrayList<>();
    private ArrayList<Token> rbracks = new ArrayList<>();
    private Token equal;
    private ConstInitVal constInitVal;

    public ConstDef(Ident ident, ArrayList<Token> lbracks, ArrayList<ConstExp> constExps, ArrayList<Token> rbracks, Token equal, ConstInitVal constInitVal) {
        this.ident = ident;
        this.lbracks = lbracks;
        this.constExps = constExps;
        this.rbracks = rbracks;
        this.equal = equal;
        this.constInitVal = constInitVal;
    }


    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.Parser_Output());
        if(this.lbracks != null && this.rbracks != null && this.constExps != null && this.lbracks.size() == this.rbracks.size() && this.lbracks.size() == this.constExps.size()) {
            for(int i = 0; i < this.lbracks.size(); i++) {
                sb.append(lbracks.get(i).toString());
                sb.append(constExps.get(i).Parser_Output());
                sb.append(rbracks.get(i).toString());
            }
        }
        sb.append(this.equal.toString());
        sb.append(this.constInitVal.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

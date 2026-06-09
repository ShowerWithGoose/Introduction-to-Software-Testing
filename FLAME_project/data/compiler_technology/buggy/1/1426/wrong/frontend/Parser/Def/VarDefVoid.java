package frontend.Parser.Def;

import frontend.Token;
import frontend.Parser.Exp.ConstExp;
import frontend.Parser.solid.Ident;

import java.util.ArrayList;

//变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '='
////InitVal // 包含普通常量、一维数组定义
public class VarDefVoid implements VarDefInf {
    private Ident ident;
    private ArrayList<Token> lbrace = new ArrayList<>();
    private ArrayList<ConstExp> constExps = new ArrayList<>();
    private ArrayList<Token> rbrace = new ArrayList<>();

    public VarDefVoid(Ident ident, ArrayList<Token> lbrace, ArrayList<ConstExp> constExps, ArrayList<Token> rbrace) {
        this.ident = ident;
        this.lbrace = lbrace;
        this.constExps = constExps;
        this.rbrace = rbrace;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.Parser_Output());
        //System.out.println(this.ident.Parser_Output());
        if(this.lbrace != null && this.rbrace != null && this.lbrace.size() == this.constExps.size() && this.lbrace.size() == this.rbrace.size()) {
            for(int i = 0; i < this.lbrace.size(); i++) {
                sb.append(this.lbrace.get(i).toString());
                sb.append(this.constExps.get(i).Parser_Output());
                sb.append(this.rbrace.get(i).toString());
            }
        }
        return sb.toString();
    }
}

package frontend.Parser.Def;

import frontend.Token;
import frontend.Parser.Exp.ConstExp;
import frontend.Parser.Val.InitVal;
import frontend.Parser.solid.Ident;

import java.util.ArrayList;

//变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '='
//InitVal // 包含普通常量、一维数组定义
public class VarDefInit implements VarDefInf{
    private Ident ident;
    private ArrayList<Token> lbrace;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rbrace;
    private Token equal;
    private InitVal initVal;

    public VarDefInit(Ident ident, ArrayList<Token> lbrace, ArrayList<ConstExp> constExps, ArrayList<Token> rbrace, Token equal, InitVal initVal) {
        this.ident = ident;
        this.lbrace = lbrace;
        this.constExps = constExps;
        this.rbrace = rbrace;
        this.equal = equal;
        this.initVal = initVal;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.Parser_Output());
        if(this.lbrace != null && this.rbrace != null && this.lbrace.size() == this.constExps.size() && this.lbrace.size() == this.rbrace.size()) {
            for(int i = 0; i < this.lbrace.size(); i++) {
                sb.append(this.lbrace.get(i).toString());
                sb.append(this.constExps.get(i).Parser_Output());
                sb.append(this.rbrace.get(i).toString());
            }
        }
        sb.append(this.equal.toString());
        sb.append(this.initVal.Parser_Output());
        return sb.toString();
    }
}

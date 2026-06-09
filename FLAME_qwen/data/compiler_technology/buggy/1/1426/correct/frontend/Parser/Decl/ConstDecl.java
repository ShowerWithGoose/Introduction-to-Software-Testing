package frontend.Parser.Decl;

import frontend.Token;
import frontend.Parser.Btype;
import frontend.Parser.Def.ConstDef;

import java.util.ArrayList;

//常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // 1.花括号内重复0次
//2.花括号内重复多次
public class ConstDecl implements DeclInf {
    private final String name = "<ConstDecl>";
    private Token constTk;
    private Btype btype;
    private ConstDef first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<ConstDef> constDefs = new ArrayList<>();
    private Token semicn;

    public ConstDecl(Token constTk, Btype btype, ConstDef first, ArrayList<Token> commas, ArrayList<ConstDef> constDefs, Token semicn) {
        this.constTk = constTk;
        this.btype = btype;
        this.first = first;
        this.commas = commas;
        this.constDefs = constDefs;
        this.semicn = semicn;
    }
    public ConstDecl(Token constTk, Btype btype, ConstDef first, Token semicn) {
        this.constTk = constTk;
        this.btype = btype;
        this.first = first;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.constTk.toString());
        sb.append(this.btype.Parser_Output());
        sb.append(this.first.Parser_Output());
        if(this.commas != null && this.constDefs != null && this.commas.size() == this.constDefs.size()) {
            for(int i = 0; i < this.constDefs.size(); i++) {
                sb.append(this.commas.get(i).toString());
                sb.append(this.constDefs.get(i).Parser_Output());
            }
        }
        sb.append(this.semicn.toString());
        sb.append(this.name + "\n");
        return sb.toString();
    }

}

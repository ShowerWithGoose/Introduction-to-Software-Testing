package frontend.Parser.Decl;

import frontend.Token;
import frontend.Parser.Btype;
import frontend.Parser.Def.VarDef;

import java.util.ArrayList;

//变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // 1.花括号内重复0次 2.花括号内重复
//多次
public class VarDecl implements DeclInf {
    private final String name = "<VarDecl>";
    private Btype btype;
    private VarDef first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<VarDef> varDefs = new ArrayList<>();
    private Token semicn;

    public VarDecl(Btype btype, VarDef first, Token semicn) {
        this.btype = btype;
        this.first = first;
        this.semicn = semicn;
    }
    public VarDecl(Btype btype, VarDef first, ArrayList<Token> commas, ArrayList<VarDef> varDefs, Token semicn) {
        this.btype = btype;
        this.first = first;
        this.commas = commas;
        this.varDefs = varDefs;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.btype.Parser_Output());
        sb.append(this.first.Parser_Output());
        if(this.commas != null && this.varDefs != null && this.varDefs.size() == this.commas.size()) {
            for(int i = 0; i < this.varDefs.size(); i++) {
                sb.append(this.commas.get(i).toString());
                sb.append(this.varDefs.get(i).Parser_Output());
            }
        }
        sb.append(this.semicn.toString());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

package frontend.parser.declaration.variable;

import frontend.lexer.Token;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.DeclEle;
import frontend.parser.declaration.variable.vardef.VarDef;

import java.util.ArrayList;

public class VarDecl implements DeclEle {
    public final String name = "<VarDecl>";
    public BType btype;
    public VarDef first;
    public ArrayList<Token> commas; // ','
    public ArrayList<VarDef> varDefs;
    public Token semicn; // ';'

    public VarDecl(BType btype,
                   VarDef first,
                   ArrayList<Token> commas,
                   ArrayList<VarDef> varDefs,
                   Token semicn) {
        this.btype = btype;
        this.first = first;
        this.commas = commas;
        this.varDefs = varDefs;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.btype.syntaxOutput());
        sb.append(this.first.syntaxOutput());
        if (this.commas != null && this.varDefs != null &&
                this.commas.size() == this.varDefs.size()) {
            int len = this.commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commas.get(i).syntaxOutput());
                sb.append(this.varDefs.get(i).syntaxOutput());
            }
        }
        sb.append(this.semicn.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        if(this.semicn!=null) {
            return this.semicn.linenum;
        }else{
            if(!varDefs.isEmpty()) {
                return this.varDefs.get(this.varDefs.size()-1).my_line_num();
            }else{
                return this.first.my_line_num();
            }
        }
    }
}

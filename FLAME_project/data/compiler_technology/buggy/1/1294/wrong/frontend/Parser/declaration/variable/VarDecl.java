package frontend.Parser.declaration.variable;

import frontend.Parser.GrammarNode;
import frontend.Parser.declaration.BType;
import frontend.Lexer.Token;

import java.util.ArrayList;

public class VarDecl implements GrammarNode {
    private final String grammarName = "<VarDecl>";
    private BType bType;
    private VarDef firstVarDef;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> varDefs;
    private Token semicn; // ';'

    public VarDecl(BType bType, VarDef firstVarDef, Token semicn) {
        this.bType = bType;
        this.firstVarDef = firstVarDef;
        this.semicn = semicn;
    }

    public VarDecl(BType bType, VarDef firstVarDef, ArrayList<Token> commas, ArrayList<VarDef> varDefs, Token semicn) {
        this(bType, firstVarDef, semicn);
        this.commas = commas;
        this.varDefs = varDefs;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.bType.grammarOutput());
        sb.append(this.firstVarDef.grammarOutput());
        if(this.commas!=null && this.varDefs!=null
                && this.commas.size() == this.varDefs.size()){
            for(int i = 0; i < this.commas.size(); i++){
                sb.append(this.commas.get(i).grammarOutput());
                sb.append(this.varDefs.get(i).grammarOutput());
            }
        }
        sb.append(this.semicn.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }

}

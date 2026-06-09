package frontend.Parser.declaration;

import frontend.Parser.GrammarNode;
import frontend.Parser.declaration.constant.ConstDecl;
import frontend.Parser.declaration.variable.VarDecl;

public class Decl implements GrammarNode {
    private final String grammarName = "<Decl>";
    private ConstDecl constDecl;
    private VarDecl varDecl;
    public Decl(ConstDecl constDecl){
        this.constDecl = constDecl;
        this.varDecl = null;
    }
    public Decl(VarDecl varDecl){
        this.varDecl = varDecl;
        this.constDecl = null;
    }
    public String grammarOutput(){
        StringBuilder sb = new StringBuilder();
        if(constDecl != null){
            sb.append(constDecl.grammarOutput());
        } else {
            sb.append(varDecl.grammarOutput());
        }
        return sb.toString();
    }
}

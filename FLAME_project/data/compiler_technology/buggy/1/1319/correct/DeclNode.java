import java.io.IOException;

public class DeclNode extends ASTNode {
    private ConstDeclNode constdecl;
    private VarDeclNode vardecl;

    public DeclNode(ConstDeclNode constdecl, VarDeclNode vardecl){
        this.constdecl = constdecl;
        this.vardecl = vardecl;
    }

     public ConstDeclNode getConstdecl() {
         return constdecl;
     }

     public VarDeclNode getVardecl(){
        return vardecl;
     }

     @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitDecl(this);
    }
}
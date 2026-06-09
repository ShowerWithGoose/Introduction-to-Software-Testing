package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
public class DeclNode {
    public ConstDeclNode constDeclNode = null;
    public VarDeclNode varDeclNode = null;
    public DeclNode(ConstDeclNode constDeclNode){
        this.constDeclNode = constDeclNode;
    }
    public DeclNode(VarDeclNode varDeclNode){
        this.varDeclNode = varDeclNode;
    }
    public void print() throws IOException {
        if(constDeclNode != null){
            constDeclNode.print();
        }
        else {
            varDeclNode.print();
        }
    }
}

package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;

public class VarDeclNode {
    public BTypeNode bTypeNode;
    public List<Token> commas = new ArrayList<>();
    public Token semicolon;
    public List<VarDefNode> varDefNodes = new ArrayList<>();
    public VarDeclNode(BTypeNode bTypeNode, List<Token> commas, Token semicolon, List<VarDefNode> varDefNodes){
        this.bTypeNode = bTypeNode;
        this.commas = commas;
        this.semicolon = semicolon;
        this.varDefNodes = varDefNodes;
    }
    public void print() throws IOException {
        bTypeNode.print();
        varDefNodes.get(0).print();
        for(int i = 1; i < varDefNodes.size(); i++){
            OutputUtils.parserOutput(commas.get(i - 1).toString());
            varDefNodes.get(i).print();
        }
        OutputUtils.parserOutput(semicolon.toString());
        OutputUtils.parserOutput("<VarDecl>\n");
    }
}

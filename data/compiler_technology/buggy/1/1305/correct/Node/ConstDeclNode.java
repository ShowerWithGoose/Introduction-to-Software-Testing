package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class ConstDeclNode {
    public Token const1 = null;
    public BTypeNode bTypeNode = null;
    public List<Token> commas = new ArrayList<>();
    public Token semicolon = null;
    public List<ConstDefNode> constDefNodes = new ArrayList<>();
    public ConstDeclNode(Token const1, BTypeNode bTypeNode, List<Token> commas, Token semicolon, List<ConstDefNode> constDefNodes){
        this.const1 = const1;
        this.bTypeNode = bTypeNode;
        this.commas = commas;
        this.semicolon = semicolon;
        this.constDefNodes = constDefNodes;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(const1.toString());
        bTypeNode.print();
        constDefNodes.get(0).print();
        for(int i = 1; i < constDefNodes.size(); i++){
            OutputUtils.parserOutput(commas.get(i - 1).toString());
            constDefNodes.get(i).print();
        }
        OutputUtils.parserOutput(semicolon.toString());
        OutputUtils.parserOutput("<ConstDecl>\n");
    }
}

package Node;
import java.util.ArrayList;
import java.util.List;
import Utils.OutputUtils;
import java.nio.file.StandardOpenOption;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
public class CompUnitNode {
    public List<DeclNode> declNodes = new ArrayList<>();
    public List<FuncDefNode> funcDefNodes = new ArrayList<>();
    public MainFuncDefNode mainFuncDefNode;
    public CompUnitNode(List<DeclNode> declNodes, List<FuncDefNode> funcDefNodes, MainFuncDefNode mainFuncDefNode){
        this.declNodes = declNodes;
        this.funcDefNodes = funcDefNodes;
        this.mainFuncDefNode = mainFuncDefNode;
    }
    public void print() throws IOException {
        for(DeclNode declNode : declNodes){
            declNode.print();
        }
        for(FuncDefNode funcDefNode : funcDefNodes){
            funcDefNode.print();
        }
        mainFuncDefNode.print();
        OutputUtils.parserOutput("<CompUnit>\n");
    }
}

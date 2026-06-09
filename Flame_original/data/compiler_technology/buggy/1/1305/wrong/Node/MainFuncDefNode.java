package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class MainFuncDefNode {
    public Token int1;
    public Token main;
    public Token leftParent;
    public Token rightParent;
    public BlockNode blockNode;
    public MainFuncDefNode(Token int1, Token main, Token leftParent, Token rightParent, BlockNode blockNode){
        this.blockNode = blockNode;
        this.int1 = int1;
        this.main = main;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(int1.toString());
        OutputUtils.parserOutput(main.toString());
        OutputUtils.parserOutput(leftParent.toString());
        OutputUtils.parserOutput(rightParent.toString());
        blockNode.print();
        OutputUtils.parserOutput("<MainFuncDef>\n");
    }
}

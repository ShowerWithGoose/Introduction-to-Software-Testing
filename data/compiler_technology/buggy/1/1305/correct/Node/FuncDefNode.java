package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class FuncDefNode {
    public FuncTypeNode funcTypeNode;
    public Token Ident;
    public Token leftParent;
    public Token rightParent;
    public FuncFParamsNode funcFParamsNode;
    public BlockNode blockNode;
    public FuncDefNode(FuncTypeNode funcTypeNode, Token Ident, Token leftParent, Token rightParent, FuncFParamsNode funcFParamsNode, BlockNode blockNode){
        this.funcFParamsNode = funcFParamsNode;
        this.funcTypeNode = funcTypeNode;
        this.Ident = Ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.blockNode = blockNode;
    }
    public void print() throws IOException {
        funcTypeNode.print();
        OutputUtils.parserOutput(Ident.toString());
        OutputUtils.parserOutput(leftParent.toString());
        if(funcFParamsNode != null){
            funcFParamsNode.print();
        }
        OutputUtils.parserOutput(rightParent.toString());
        blockNode.print();
        OutputUtils.parserOutput("<FuncDef>\n");
    }

}

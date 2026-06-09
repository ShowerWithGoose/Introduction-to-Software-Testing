package Node;
import Token.*;
import frontend.Parser;

public class FuncDefNode {
    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // 1.无形参 2.有形参
    private FuncTypeNode funcTypeNode;
    private Token ident;
    private FuncFParamsNode funcFParamsNode;
    private BlockNode blockNode;
    Token leftParent;
    Token rightParent;
    public FuncDefNode(FuncTypeNode funcTypeNode, Token ident, FuncFParamsNode funcFParamsNode, BlockNode blockNode, Token leftParent, Token rightParent){
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.funcTypeNode = funcTypeNode;
        this.ident = ident;
        this.funcFParamsNode = funcFParamsNode;
        this.blockNode = blockNode;
    }

    public void print(){
        funcTypeNode.print();
        Parser.getInstance().output(ident);
        Parser.getInstance().output(leftParent);
        if(funcFParamsNode != null){
            funcFParamsNode.print();
        }
        Parser.getInstance().output(rightParent);
        blockNode.print();
        Parser.getInstance().output(NodeType.FuncDef);
    }
}

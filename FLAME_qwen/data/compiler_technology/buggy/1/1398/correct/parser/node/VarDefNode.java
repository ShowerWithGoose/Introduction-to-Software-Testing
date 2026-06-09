package parser.node;

import lexer.Token;
import parser.NodeType;

public class VarDefNode {
    Token identTK;
    Token lBrackTK;
    Token rBrackTK;
    ConstExpNode constExpNode;
    Token assignTK;
    InitValNode initValNode;

    public VarDefNode(Token identTK, Token lBrackTK, Token rBrackTK, ConstExpNode constExpNode, Token assignTK, InitValNode initValNode) {
        this.identTK = identTK;
        this.lBrackTK = lBrackTK;
        this.rBrackTK = rBrackTK;
        this.constExpNode = constExpNode;
        this.assignTK = assignTK;
        this.initValNode = initValNode;
    }
    public void print() {
        identTK.print();
        if (lBrackTK!=null)
        {
            lBrackTK.print();
            constExpNode.print();
            rBrackTK.print();
        }
        if (assignTK!=null)
        {
            assignTK.print();
            initValNode.print();
        }
        System.out.println(NodeType.VarDef);
    }
}

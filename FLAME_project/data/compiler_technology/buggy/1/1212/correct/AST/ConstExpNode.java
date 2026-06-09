package AST;

import IO.*;

import java.io.IOException;

//常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量 // 存在即可
public class ConstExpNode extends ASTNode{

    ASTNodes type = ASTNodes.ConstExp;
    AddExpNode exprNode;

    public ConstExpNode(AddExpNode exprNode) {
        this.exprNode = exprNode;
    }

    public ASTNodes getType() {
        return type;
    }

    public AddExpNode getExprNode() {
        return exprNode;
    }


    
    public void postOrderTraversal(IO io) throws IOException {
        exprNode.postOrderTraversal(io);
        io.getParserWriter().write("<ConstExp>\n");
    }

    
    public void postOrderNoPrint() {
        exprNode.postOrderNoPrint();
    }
}
package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class UnaryExpNode {
    //一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    private PrimaryExpNode primaryExpNode;
    private Token ident;
    private Token leftParentToken;
    private FuncRParamsNode funcRParamsNode;
    private Token rightParentToken;
    private UnaryOpNode unaryOpNode;
    private UnaryExpNode unaryExpNode;

    public UnaryExpNode(PrimaryExpNode primaryExpNode,Token ident, Token leftParentToken,
                        FuncRParamsNode funcRParamsNode, Token rightParentToken,
                        UnaryOpNode unaryOpNode, UnaryExpNode unaryExpNode) {
        this.primaryExpNode = primaryExpNode;
        this.ident = ident;
        this.leftParentToken = leftParentToken;
        this.funcRParamsNode = funcRParamsNode;
        this.rightParentToken = rightParentToken;
        this.unaryOpNode = unaryOpNode;
        this.unaryExpNode = unaryExpNode;
    }

    public void print() {
        if (primaryExpNode != null) {
            primaryExpNode.print();
        } else if (ident != null) {
            IO.ParserOutput(ident);
            IO.ParserOutput(leftParentToken);
            if (funcRParamsNode != null) {
                funcRParamsNode.print();
            }
            IO.ParserOutput(rightParentToken);
        } else {
            unaryOpNode.print();
            unaryExpNode.print();
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.UnaryExp));
    }

}

package parser.node;

import lexer.Token;
import parser.NodeType;

public class UnaryExpNode {
    int choose;
    /*
    UnaryExp â†’ PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    choose1: PrimaryExp
    choose2: Ident '(' [FuncRParams] ')'
    choose3: UnaryOp UnaryExp
     */
    UnaryOpNode unaryOpNode;
    UnaryExpNode unaryExpNode;
    Token identTK, lParentTK, rParentTK;
    FuncRParamsNode funcRParamsNode;
    PrimaryExpNode primaryExpNode;

    public UnaryExpNode(int choose, PrimaryExpNode primaryExpNode) {
        this.choose = choose;
        this.primaryExpNode = primaryExpNode;
    }

    public UnaryExpNode(int choose, Token identTK, Token lParentTK, Token rParentTK, FuncRParamsNode funcRParamsNode) {
        this.choose = choose;
        this.identTK = identTK;
        this.lParentTK = lParentTK;
        this.rParentTK = rParentTK;
        this.funcRParamsNode = funcRParamsNode;
    }

    public UnaryExpNode(int choose, UnaryOpNode unaryOpNode, UnaryExpNode unaryExpNode) {
        this.choose = choose;
        this.unaryOpNode = unaryOpNode;
        this.unaryExpNode = unaryExpNode;
    }
    public void print() {
        switch (choose)
        {
            case 1:
                primaryExpNode.print();
                break;
            case 2:
            {
                identTK.print();
                lParentTK.print();
                if (funcRParamsNode != null)
                {
                    funcRParamsNode.print();
                }
                rParentTK.print();
                break;
            }
            case 3:
                unaryOpNode.print();
                unaryExpNode.print();
                break;
            default:
                System.out.println("error in unaryExp");
        }
        System.out.println(NodeType.UnaryExp);
    }
}

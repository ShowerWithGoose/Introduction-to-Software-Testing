package Node;
import Token.*;
import frontend.Parser;

public class UnaryExpNode {
    //UnaryExp â†’ PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    private enum UnaryExpType{
        PriExp,
        Ident,
        Op
    }
    private PrimaryExpNode priExpNode;
    private Token ident;
    private FuncRParamsNode funcRParamsNode;
    private UnaryOpNode unaryOpNode;
    private UnaryExpNode unaryExpNode;
    private UnaryExpType type;
    Token leftParent;
    Token rightParent;
    public UnaryExpNode(PrimaryExpNode priExpNode){
        //PrimaryExp
        type = UnaryExpType.PriExp;
        this.priExpNode = priExpNode;
    }

    public UnaryExpNode(Token ident, FuncRParamsNode funcRParamsNode, Token leftParent, Token rightParent){
        //Ident '(' [FuncRParams] ')'
        type = UnaryExpType.Ident;
        this.ident = ident;
        this.funcRParamsNode = funcRParamsNode;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
    }

    public UnaryExpNode(UnaryOpNode unaryOpNode, UnaryExpNode unaryExp){
        //UnaryOp UnaryExp
        type = UnaryExpType.Op;
        this.unaryOpNode = unaryOpNode;
        this.unaryExpNode = unaryExp;
    }

    public void print(){
        switch (type){
            case PriExp:
                //PrimaryExp
                priExpNode.print();
                break;
            case Ident:
                //Ident '(' [FuncRParams] ')'
                Parser.getInstance().output(ident);
                Parser.getInstance().output(leftParent);
                if(funcRParamsNode != null){
                    funcRParamsNode.print();
                }
                Parser.getInstance().output(rightParent);
                break;
            case Op:
                //UnaryOp UnaryExp
                unaryOpNode.print();
                unaryExpNode.print();
                break;
            default:
                break;
        }
        Parser.getInstance().output(NodeType.UnaryExp);
    }
}

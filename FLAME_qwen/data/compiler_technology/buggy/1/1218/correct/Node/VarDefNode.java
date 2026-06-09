package Node;
import Token.*;
import frontend.Parser;

public class VarDefNode {
    //VarDef → Ident [ '[' ConstExp ']' ]
    // | Ident [ '[' ConstExp ']' ] '=' InitVal
    // 包含普通常量、一维数组定义
    private Token ident;
    private ConstExpNode constExpNode;
    private InitValNode initValNode;
    Token leftBrack;
    Token rightBrack;
    Token eqToken;
    public VarDefNode(Token ident, ConstExpNode constExpNode, InitValNode initValNode, Token leftBrack, Token rightBrack, Token eqToken){
        this.leftBrack = leftBrack;
        this.rightBrack = rightBrack;
        this.eqToken = eqToken;
        this.ident = ident;
        this.constExpNode = constExpNode;
        this.initValNode = initValNode;
    }

    public void print(){
        Parser.getInstance().output(ident);
        if(leftBrack != null){
            Parser.getInstance().output(leftBrack);
            constExpNode.print();
            Parser.getInstance().output(rightBrack);
        }
        if(eqToken != null){
            Parser.getInstance().output(eqToken);
            initValNode.print();
        }
        Parser.getInstance().output(NodeType.VarDef);
    }

}

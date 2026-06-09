package Node;

import Token.Token;
import frontend.Parser;

import java.util.ArrayList;

public class InitValNode {
    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    // 1.表达式初值 2.一维数组初值
    private ArrayList<ExpNode> expNodes;
    private Token leftBrace;
    private Token rightBrace;
    private Token stringConst;
    ArrayList<Token> commas;

    public InitValNode(ArrayList<ExpNode> expNodes, Token leftBrace, Token rightBrace, Token stringConst, ArrayList<Token> commas){
        this.commas = commas;
        this.expNodes = expNodes;
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
        this.stringConst = stringConst;
    }

    public void print(){
        if(stringConst == null){
            if(leftBrace != null){
                //'{' [ Exp { ',' Exp } ] '}'
                Parser.getInstance().output(leftBrace);
                if(!expNodes.isEmpty()){
                    expNodes.get(0).print();
                    for(int i = 1; i < expNodes.size(); i++){
                        Parser.getInstance().output(commas.get(i - 1));
                        expNodes.get(i).print();
                    }
                }
                Parser.getInstance().output(rightBrace);
            }else {
                //Exp
                expNodes.get(0).print();
            }
        }else {
            //StringConst
            Parser.getInstance().output(stringConst);
        }
        Parser.getInstance().output(NodeType.InitVal);
    }
}

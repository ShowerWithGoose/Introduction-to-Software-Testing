package Node;

import Token.Token;
import frontend.Parser;

import java.util.ArrayList;

public class ConstInitValNode {
    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    // 1.常表达式初值 2.一维数组初值
    private ArrayList<ConstExpNode> constExpNodes;
    private Token leftBrace;
    private Token rightBrace;
    private Token stringConst;
    ArrayList<Token> commas;

    public ConstInitValNode(ArrayList<ConstExpNode> constExpNodes, Token leftBrace, Token rightBrace, Token stringConst, ArrayList<Token> commas){
        this.commas = commas;
        this.constExpNodes = constExpNodes;
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
        this.stringConst = stringConst;
    }

    public void print(){
        if(stringConst == null){
            if(leftBrace == null){
                //ConstExp
                constExpNodes.get(0).print();
            }else {
                //'{' [ ConstExp { ',' ConstExp } ] '}'
                Parser.getInstance().output(leftBrace);
                if(!constExpNodes.isEmpty()){
                    constExpNodes.get(0).print();
                    if(commas != null){
                        for(int i = 1; i < constExpNodes.size(); i++){
                            Parser.getInstance().output(commas.get(i - 1));
                            constExpNodes.get(i).print();
                        }
                    }
                }
                Parser.getInstance().output(rightBrace);
            }
        }else {
            //StringConst
            Parser.getInstance().output(stringConst);
        }
        Parser.getInstance().output(NodeType.ConstInitVal);
    }
}

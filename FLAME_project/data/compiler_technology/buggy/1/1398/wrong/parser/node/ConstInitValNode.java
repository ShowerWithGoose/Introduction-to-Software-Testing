package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class ConstInitValNode {
    ArrayList<ConstExpNode> constExpNodes;
    Token lBraceTK;
    Token rBraceTK;
    ArrayList<Token> commas;
    Token stringTK;

    public ConstInitValNode(ArrayList<ConstExpNode> constExpNodes, Token lBraceTK, Token rBraceTK, ArrayList<Token> commas, Token stringTK) {
        this.constExpNodes = constExpNodes;
        this.lBraceTK = lBraceTK;
        this.rBraceTK = rBraceTK;
        this.commas = commas;
        this.stringTK = stringTK;
    }

    public void print() {
        if (stringTK != null)
        {
            stringTK.print();
        }
        else if (lBraceTK != null)
        {
            lBraceTK.print();
            if (!constExpNodes.isEmpty())
            {
                constExpNodes.get(0).print();
                for (int i = 1; i < constExpNodes.size(); i++)
                {
                    commas.get(i - 1).print();
                    constExpNodes.get(i).print();
                }
            }
            rBraceTK.print();
        }
        else
        {
            constExpNodes.get(0).print();
        }
        System.out.println(NodeType.ConstInitVal);
    }
}

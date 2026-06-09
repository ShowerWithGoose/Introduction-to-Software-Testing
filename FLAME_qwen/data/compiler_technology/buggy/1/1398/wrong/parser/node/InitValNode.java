package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class InitValNode {
    ArrayList<ExpNode> expNodes;
    Token lBraceTK;
    ArrayList<Token> commas;
    Token rBraceTK;
    Token stringTK;

    public InitValNode(ArrayList<ExpNode> expNodes, Token lBraceTK, ArrayList<Token> commas, Token rBraceTK, Token stringTK) {
        this.expNodes = expNodes;
        this.lBraceTK = lBraceTK;
        this.commas = commas;
        this.rBraceTK = rBraceTK;
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
            if (!expNodes.isEmpty())
            {
                expNodes.get(0).print();
                for (int i = 1; i < expNodes.size(); i++)
                {
                    commas.get(i - 1).print();
                    expNodes.get(i).print();
                }
            }
            rBraceTK.print();
        }
        else
        {
            expNodes.get(0).print();
        }
        System.out.println(NodeType.InitVal);
    }

}

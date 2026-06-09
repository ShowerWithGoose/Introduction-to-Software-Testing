package parser.node;

import lexer.Token;
import parser.NodeType;

public class CharacterNode {
    Token chrconTK;

    public CharacterNode(Token chrconTK) {
        this.chrconTK = chrconTK;
    }
    public void print() {
        chrconTK.print();
        System.out.println(NodeType.Character);
    }
}

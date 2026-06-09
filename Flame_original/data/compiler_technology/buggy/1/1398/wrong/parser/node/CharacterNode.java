package parser.node;

import lexer.Token;

public class CharacterNode {
    Token chrconTK;

    public CharacterNode(Token chrconTK) {
        this.chrconTK = chrconTK;
    }
    public void print() {
        chrconTK.print();
    }
}

package node;

import token.Token;

import java.io.IOException;

public class CharacterNode {
    private Token charConst;
    
    public CharacterNode(Token charConst) {
        this.charConst = charConst;
    }
    
    public void print() throws IOException {
        charConst.print();
    }
}

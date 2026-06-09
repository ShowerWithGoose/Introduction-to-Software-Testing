package frontend.node;

import frontend.Token;

public class BTypeNode {
    private Token bTypeToken;
    public BTypeNode(Token bTypeToken){
        this.bTypeToken = bTypeToken;
    }
    public void print(){
        bTypeToken.print();
    }
}

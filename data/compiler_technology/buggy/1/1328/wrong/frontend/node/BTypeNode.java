package frontend.node;

import frontend.token.Token;
import utils.MyIO;

public class BTypeNode {
    // 基本类型 BType → 'int' | 'char'
    private Token bTypeToken;

    public BTypeNode(Token btypeToken) {
        this.bTypeToken = btypeToken;
    }

    public void print() {
        MyIO.writeToken(bTypeToken.toString());
    }
}

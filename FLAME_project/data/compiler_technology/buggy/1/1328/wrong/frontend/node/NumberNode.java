package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class NumberNode {
    // 数值 Number -> IntConst

    Token token;

    public NumberNode(Token token) {
        this.token = token;
    }

    public Token getToken() {
        return token;
    }

    public void print() {
        MyIO.writeToken(token.toString());
        MyIO.writeNode(Parser.nodeType.get(NodeType.Number));
    }
}

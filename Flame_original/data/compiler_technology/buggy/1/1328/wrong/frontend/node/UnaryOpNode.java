package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class UnaryOpNode {
    // 单目运算符 UnaryOp -> '+' | '−' | '!'

    Token token;

    public UnaryOpNode(Token token) {
        this.token = token;
    }

    public Token getToken() {
        return token;
    }

    public void print() {
        MyIO.writeToken(token.toString());
        MyIO.writeNode(Parser.nodeType.get(NodeType.UnaryOp));
    }
}

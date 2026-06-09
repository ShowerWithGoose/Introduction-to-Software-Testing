package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class FuncTypeNode {
    // 函数类型 FuncType → 'void' | 'int' | 'char'

    private Token token;

    public FuncTypeNode(Token token) {
        this.token = token;
    }

    public Token getToken() {
        return token;
    }

    public void print() {
        MyIO.writeToken(token.toString());
        MyIO.writeNode(Parser.nodeType.get(NodeType.FuncType));
    }
}

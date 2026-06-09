package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class FuncTypeNode {
    //函数类型 FuncType → 'void' | 'int' | 'char'
    private Token token;

    public FuncTypeNode(Token token) {
        this.token = token;
    }

    public void print() {
        IO.ParserOutput(token);
        IO.ParserOutput(Parser.nodeType.get(NodeType.FuncType));
    }
}

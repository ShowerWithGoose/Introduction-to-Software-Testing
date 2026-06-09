package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class UnaryOpNode {
    //单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
    Token token;

    public UnaryOpNode(Token token) {
        this.token = token;
    }

    public void print() {
        IO.ParserOutput(token);
        IO.ParserOutput(Parser.nodeType.get(NodeType.UnaryOp));
    }
}

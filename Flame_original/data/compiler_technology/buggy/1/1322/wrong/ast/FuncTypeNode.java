package ast;

import IO.IO;
import enum_package.FuncType;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class FuncTypeNode {
    // FuncType â†’ 'void' | 'int' | 'char'
    public Token token;

    public FuncTypeNode(Token token) {
        this.token = token;
    }

    public void print() {
        IO.write(token.toString());
        IO.write(Parser.nodeTypeLabel.get(NodeType.FuncType));
    }
}


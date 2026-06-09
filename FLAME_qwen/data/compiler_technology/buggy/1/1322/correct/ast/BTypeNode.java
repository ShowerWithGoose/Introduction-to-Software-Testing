package ast;

import IO.IO;
import enum_package.BasicType;
import frontend.LexType;
import frontend.Token;

public class BTypeNode {
    // BType -> 'int' | 'char'
    public Token token;

    public BTypeNode(Token token) {
        this.token = token;
    }

    public void print() {
        IO.write(token.toString());
    }
}

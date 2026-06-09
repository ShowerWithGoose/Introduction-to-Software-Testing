package Paser;

import Reader.Token;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class TokenNode extends Node{
    private Token token;

    public TokenNode(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children, Token token) {
        super(startLine, endLine, type, children);
        this.token = token;
    }

    public Token getToken() {
        return token;
    }

    public String getName() {
        return token.getDescription();
    }

    public ValueType getBtype() {
        if (token.getDescription().equals("int")) {
            return ValueType.INT;
        } else if (token.getDescription().equals("char")) {
            return ValueType.CHAR;
        } else {
            return ValueType.VOID;
        }
    }
}

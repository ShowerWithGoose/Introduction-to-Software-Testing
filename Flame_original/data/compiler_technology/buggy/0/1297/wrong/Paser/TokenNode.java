package Paser;

import Reader.Token;
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

}

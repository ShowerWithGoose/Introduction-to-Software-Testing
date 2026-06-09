package frontend.AST.Other;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;
import frontend.lexer.Token;

import java.util.ArrayList;

public class TokenNode extends Node {
    private Token token;

    public TokenNode(int startLineNum, int endLineNum,
                     SyntaxVarType type, ArrayList<Node> childNodes, Token token) {
        super(startLineNum,endLineNum, type, childNodes);
        this.token = token;
    }

    public Token getToken() {
        return this.token;
    }
}

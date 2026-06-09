package Paser.Var;

import Paser.Node;
import Paser.TokenNode;
import Reader.Token;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal
public class ConstDef extends Node {
    public ConstDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public String getName() {
        return ((TokenNode) children.get(0)).getName();
    }

    public Boolean isArray() {
        return children.get(1) instanceof TokenNode && ((TokenNode) children.get(1)).getToken().getType() == Token.TokenType.LBRACK;
    }

}

package Paser.Var;

import Paser.Node;
import Paser.TokenNode;
import Type.SyntaxVarType;

import java.util.ArrayList;

import static Reader.Token.TokenType.LBRACK;

// VarDef â†’ Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
public class VarDef extends Node{
    public VarDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public String getName() {
        return ((TokenNode)children.get(0)).getName();
    }

    public Boolean isArray() {
        if (children.size()==1)
        {
            return false;
        }
        if (children.get(1)instanceof TokenNode)
        {
            if (((TokenNode) children.get(1)).getToken().getType()==LBRACK)
            {
                return true;
            }
        }
        return false;
    }
}

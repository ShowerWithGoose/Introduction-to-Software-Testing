package frontend.AST.Other;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

//Block -> '{' {BlockItem} '}'
public class Block extends Node {
    public Block(int startLineNum, int endLineNum, SyntaxVarType type,
                    ArrayList<Node> childNodes) {
        super(startLineNum, endLineNum, type, childNodes);
    }
}

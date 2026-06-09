package frontend.AST.Other;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

//CompUnit -> {Decl} {FunDef} MainFuncDef
public class CompUnit extends Node {
    public CompUnit(int startLineNum, int endLineNum, SyntaxVarType type,
                    ArrayList<Node> childNodes) {
        super(startLineNum, endLineNum, type, childNodes);
    }
}

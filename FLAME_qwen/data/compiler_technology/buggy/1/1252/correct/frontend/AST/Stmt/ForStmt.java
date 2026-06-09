package frontend.AST.Stmt;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

public class ForStmt extends Stmt {
    public ForStmt(int startLineNum, int endLineNum, SyntaxVarType type,
                 ArrayList<Node> childNodes) {
        super(startLineNum, endLineNum, type, childNodes);
    }
}

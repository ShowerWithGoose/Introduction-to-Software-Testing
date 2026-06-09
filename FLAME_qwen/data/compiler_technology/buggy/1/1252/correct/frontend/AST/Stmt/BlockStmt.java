package frontend.AST.Stmt;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

public class BlockStmt extends Stmt {
    public BlockStmt(int startLineNum, int endLineNum, SyntaxVarType type,
                 ArrayList<Node> childNodes) {
        super(startLineNum, endLineNum, type, childNodes);
    }
}

package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class BlockItem extends TreeNode {
    private Decl decl = null;
    private Stmt stmt = null;
    public BlockItem(ParserType parserType, Token token) {
        super(parserType, token);
    }

    public void setDecl(Decl decl) {
        this.decl = decl;
    }

    public void setStmt(Stmt stmt) {
        this.stmt = stmt;
    }
}

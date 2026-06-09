package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.Parser;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class Decl extends TreeNode {
    private ConstDecl constDecl = null;

    public void setConstDecl(ConstDecl constDecl) {
        this.constDecl = constDecl;
    }
    private VarDecl varDecl = null;

    public void setVarDecl(VarDecl varDecl) {
        this.varDecl = varDecl;
    }

    public Decl(ParserType parserType, Token token) {
        super(parserType, token);
    }
}

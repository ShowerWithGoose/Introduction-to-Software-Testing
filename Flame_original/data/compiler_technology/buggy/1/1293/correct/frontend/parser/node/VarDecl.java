package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.ArrayList;

public class VarDecl extends TreeNode {
    private Btype btype = null;
    private ArrayList<VarDef> varDefs = new ArrayList<>();
    private ArrayList<Token> commas = new ArrayList<>();
    private Token semicnToken = null;

    public void setBtype(Btype btype) {
        this.btype = btype;
    }

    public void setVarDefs(VarDef varDef) {
        this.varDefs.add(varDef);
    }

    public void setCommas(Token token) {
        this.commas.add(token);
    }

    public void setSemicnToken(Token semicnToken) {
        this.semicnToken = semicnToken;
    }

    public VarDecl(ParserType parserType, Token token) {
        super(parserType, token);
    }
}

package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.ArrayList;

public class ConstDecl extends TreeNode {
    private Token constToken = null;
    private Btype btype = null;
    private ArrayList<Token> commaArraylist = new ArrayList<>();
    private ArrayList<ConstDef> constDefNodeArrayList = new ArrayList<>();
    private Token semicnToken;

    public void setConstToken(Token constToken) {
        this.constToken = constToken;
    }

    public void setBtype(Btype btype) {
        this.btype = btype;
    }

    public void setCommaArraylist(Token token) {
        this.commaArraylist.add(token);
    }

    public void setConstDefNodeArrayList(ConstDef constDef) {
        this.constDefNodeArrayList.add(constDef);
    }

    public void setSemicnToken(Token semicnToken) {
        this.semicnToken = semicnToken;
    }
    public ConstDecl(ParserType parserType, Token token) {
        super(parserType, token);
    }
}

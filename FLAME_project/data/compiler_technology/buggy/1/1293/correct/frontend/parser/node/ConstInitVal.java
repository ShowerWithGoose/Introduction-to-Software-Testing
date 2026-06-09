package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.ArrayList;

public class ConstInitVal extends TreeNode {
    private Token lToken = null;
    private Token rToken = null;
    private Token strToken = null;
    private ArrayList<ConstExp> constExpArrayList = new ArrayList<>();
    private ArrayList<Token> commaArrayList = new ArrayList<>();


    public void setlToken(Token lToken) {
        this.lToken = lToken;
    }

    public void setrToken(Token rToken) {
        this.rToken = rToken;
    }

    public void setStrToken(Token strToken) {
        this.strToken = strToken;
    }

    public void setConstExpArrayList(ConstExp constExp) {
        this.constExpArrayList.add(constExp);
    }

    public void setCommaArrayList(Token token) {
        this.commaArrayList.add(token);
    }

    public ConstInitVal(ParserType parserType, Token token) {
        super(parserType, token);
    }
}

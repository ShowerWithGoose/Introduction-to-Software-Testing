package AST;

import token.Token;

import java.util.List;
import java.util.ArrayList;

public class ASTNode {
    private List<ASTNode> childrens;
    private boolean isTerminator;
    private String nonTerminator;
    private Token terminator;

    public ASTNode() {
        childrens = new ArrayList<>();
    }

    public void addChild(ASTNode child) {
        childrens.add(child);
    }

    public List<ASTNode> getChildrens() {
        return childrens;
    }

    public void setNonTerminator(String nonTerminator) {
        this.isTerminator = false;
        this.nonTerminator = nonTerminator;
    }

    public void setTerminator(Token token) {
        this.isTerminator = true;
        this.terminator = token;
    }

    public boolean getIsTerminator() {
        return isTerminator;
    }

    public String getNonTerminator() {
        return nonTerminator;
    }

    public Token getTerminator() {
        return terminator;
    }
}

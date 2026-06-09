package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class PrimaryExpNode {
    // 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character

    private Token lparentToken;
    private ExpNode expNode;
    private Token rparentToken;
    private LValNode lValNode;
    private NumberNode numberNode;
    private CharacterNode characterNode;

    public PrimaryExpNode(Token lparentToken, ExpNode expNode, Token rparentToken) {
        this.lparentToken = lparentToken;
        this.expNode = expNode;
        this.rparentToken = rparentToken;
    }

    public PrimaryExpNode(LValNode lValNode) {
        this.lValNode = lValNode;
    }

    public PrimaryExpNode(NumberNode numberNode) {
        this.numberNode = numberNode;
    }

    public PrimaryExpNode(CharacterNode characterNode) {
        this.characterNode = characterNode;
    }

    public ExpNode getExpNode() {
        return expNode;
    }

    public LValNode getLValNode() {
        return lValNode;
    }

    public NumberNode getNumberNode() {
        return numberNode;
    }

    public CharacterNode getCharacterNode() {
        return characterNode;
    }

    public void print() {
        if (expNode != null) {
            MyIO.writeToken(lparentToken.toString());
            expNode.print();
            MyIO.writeToken(rparentToken.toString());
        } else if (lValNode != null) {
            lValNode.print();
        } else if (numberNode != null) {
            numberNode.print();
        } else {
            characterNode.print();
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.PrimaryExp));
    }
}

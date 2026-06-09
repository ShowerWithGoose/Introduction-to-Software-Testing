package frontend.syntaxTree;

import frontend.Token;
import frontend.type.GrammarType;

import java.util.ArrayList;

public class Node {
    private GrammarType type;
    private ArrayList<Node> children;
    private Token token;

    public Node(GrammarType type) {
        this.type = type;
        this.children = new ArrayList<>();
        this.token = null;
    }

    public Node(Token token) {
        this.type = GrammarType.TERMINAL;
        this.children = null;
        this.token = token;
    }

    public GrammarType getType() {
        return type;
    }

    public ArrayList<Node> getChildren() {
        return children;
    }

    public Token getToken() {
        return token;
    }

    public String toString() {
        if(type == GrammarType.TERMINAL) {
            return token.getLexType().name()+" "+token.getTokenValue();
        } else {
            return '<' + type.toString() + ">";
        }
    }

    public void add(Node node) {
        children.add(node);
    }

    public void changeType(GrammarType type) {
        Node father = new Node(type);
        for(Node child : children) {
            father.add(child);
        }
        children.clear();
        children.add(father);
    }
}

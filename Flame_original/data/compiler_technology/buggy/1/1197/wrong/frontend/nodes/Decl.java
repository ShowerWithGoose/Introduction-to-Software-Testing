package frontend.nodes;

import frontend.LexType;
import frontend.Lexer;
import frontend.NodeRegistry;
import frontend.NodeType;

import java.util.Objects;

public class Decl extends Node {
    public Decl() {
        super(NodeType.DECL);
    }

    public static Node parse() {
        Decl decl = new Decl();
        if (Objects.requireNonNull(Lexer.INSTANCE.getLexType()) == LexType.CONSTTK) {
            decl.parseAndAdd(NodeRegistry.CONST_DECL);
        } else {
            decl.parseAndAdd(NodeRegistry.VAR_DECL);
        }
        return decl;
    }
}

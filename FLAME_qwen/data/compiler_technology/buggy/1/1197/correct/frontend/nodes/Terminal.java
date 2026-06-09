package frontend.nodes;

import frontend.Lexer;
import frontend.NodeType;
import frontend.Token;

public class Terminal extends Node {
    private Token token;

    public Terminal() {
        super(NodeType.TERMINAL);
    }

    public static Node parse() {
        Terminal terminal = new Terminal();
        terminal.token = Lexer.INSTANCE.getToken();
        Lexer.INSTANCE.next();
        return terminal;
    }

    @Override
    public String toString() {
        return token.lexType() + " " + token.value();
    }
}

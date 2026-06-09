package frontend;

import config.Config;
import frontend.nodes.Node;

public class Parser {
    public static final Parser INSTANCE = new Parser();

    private Parser() {}

    public Node parse() {
        Node node = NodeRegistry.COMP_UNIT.get();
        if (Config.DEBUG) {
            Config.OUT.println("<CompUnit>");
        }
        return node;
    }
}

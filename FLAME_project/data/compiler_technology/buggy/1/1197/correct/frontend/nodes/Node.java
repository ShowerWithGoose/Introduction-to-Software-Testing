package frontend.nodes;

import frontend.*;
import config.Config;

import java.util.ArrayList;
import java.util.function.Consumer;
import java.util.function.Supplier;
import java.util.stream.Stream;

public abstract class Node {
    public static boolean PRINT = true;
    private final NodeType type;
    private final ArrayList<Node> children;

    public Node(NodeType type) {
        this.type = type;
        children = new ArrayList<>();
    }

    public void parseAndAdd(Supplier<Node> supplier) {
        Node node = supplier.get();
        node._print();
        children.add(node);
    }

    public void _print() {
        if (Config.DEBUG && PRINT) {
            if (Stream.of(BlockItem.class, Decl.class, BType.class)
                    .noneMatch((o) -> o.isInstance(this))) {
                Config.OUT.println(this);
            }
        }
    }

    public void print() {
        for (Node node : children) {
            node.print();
        }
        this._print();
    }

    public static void processError(ErrorType errorType) {
        Lexer.INSTANCE.processError(errorType);
    }

    public void terminalCheck(LexType lexType, Consumer<Node> callBack, ErrorType errorType) {
        if (Lexer.INSTANCE.getLexType() == lexType) {
            this.parseAndAdd(NodeRegistry.TERMINAL);
            callBack.accept(this);
        } else {
            processError(errorType);
        }
    }

    public void terminalCheck(LexType lexType) {
        terminalCheck(lexType, (o) -> {});
    }

    public void terminalCheck(LexType lexType, Consumer<Node> callBack) {
        terminalCheck(lexType, callBack, ErrorType.NONE);
    }

    public void terminalCheck(LexType lexType, ErrorType errorType) {
        terminalCheck(lexType, (o) -> {}, errorType);
    }

    public void add(Node node) {
        children.add(node);
    }

    public Node get(int index) {
        return children.get(index);
    }

    public void set(int index, Node node) {
        children.set(index, node);
    }

    @Override
    public String toString() {
        String res = type.toString();
        res = res.toLowerCase();
        StringBuilder sb = new StringBuilder();
        sb.append("<");
        for (int i = -1; i < res.length(); ++i) {
            if (i == -1 || res.charAt(i) == '_') {
                i++;
                sb.append((char) (res.charAt(i) - 'a' + 'A'));
            } else {
                sb.append(res.charAt(i));
            }
        }
        sb.append(">");
        return sb.toString();
    }
}

package frontend.nodes;

import frontend.LexType;
import frontend.Lexer;
import frontend.NodeRegistry;
import frontend.NodeType;

import java.util.ArrayList;
import java.util.function.Supplier;
import java.util.stream.Stream;

public abstract class ConnectExp extends Node {
    private final Supplier<Node> lower;

    public ConnectExp(NodeType nodeType, Supplier<Node> lower) {
        super(nodeType);
        this.lower = lower;
    }

    abstract public ConnectExp get();

    abstract public Stream<LexType> connectLex();

    public Node _parse() {
        ConnectExp connectExp = this.get();
        connectExp.parseAndAdd(lower);
        while (connectLex().anyMatch((o) -> o == Lexer.INSTANCE.getLexType())) {
            ConnectExp temp = this.get();
            temp.add(connectExp);
            temp._print();
            connectExp = temp;
            connectExp.parseAndAdd(NodeRegistry.TERMINAL);
            connectExp.parseAndAdd(lower);
        }
        return connectExp;
    }
}

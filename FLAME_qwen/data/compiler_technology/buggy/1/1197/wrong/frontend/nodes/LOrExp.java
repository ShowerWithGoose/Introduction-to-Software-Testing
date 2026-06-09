package frontend.nodes;

import frontend.LexType;
import frontend.NodeRegistry;
import frontend.NodeType;

import java.util.stream.Stream;

public class LOrExp extends ConnectExp {
    public LOrExp() {
        super(NodeType.L_OR_EXP, NodeRegistry.L_AND_EXP);
    }

    @Override
    public ConnectExp get() {
        return new LOrExp();
    }

    @Override
    public Stream<LexType> connectLex() {
        return Stream.of(LexType.OR);
    }

    public static Node parse() {
        LOrExp lOrExp = new LOrExp();
        return lOrExp._parse();
    }
}

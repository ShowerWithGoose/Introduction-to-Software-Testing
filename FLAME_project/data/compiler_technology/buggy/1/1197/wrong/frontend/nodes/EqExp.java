package frontend.nodes;

import frontend.LexType;
import frontend.NodeRegistry;
import frontend.NodeType;

import java.util.stream.Stream;

public class EqExp extends ConnectExp {
    public EqExp() {
        super(NodeType.EQ_EXP, NodeRegistry.REL_EXP);
    }

    @Override
    public ConnectExp get() {
        return new EqExp();
    }

    @Override
    public Stream<LexType> connectLex() {
        return Stream.of(LexType.EQL, LexType.NEQ);
    }

    public static Node parse() {
        EqExp eqExp = new EqExp();
        return eqExp._parse();
    }
}

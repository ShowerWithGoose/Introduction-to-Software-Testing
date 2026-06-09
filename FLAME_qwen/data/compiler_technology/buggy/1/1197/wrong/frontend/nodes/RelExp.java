package frontend.nodes;

import frontend.LexType;
import frontend.NodeRegistry;
import frontend.NodeType;

import java.util.stream.Stream;

public class RelExp extends ConnectExp {
    public RelExp() {
        super(NodeType.REL_EXP, NodeRegistry.ADD_EXP);
    }

    @Override
    public ConnectExp get() {
        return new RelExp();
    }

    @Override
    public Stream<LexType> connectLex() {
        return Stream.of(LexType.LEQ,
                LexType.LSS,
                LexType.GEQ,
                LexType.GRE);
    }

    public static Node parse() {
        RelExp relExp = new RelExp();
        return relExp._parse();
    }
}

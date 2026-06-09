package frontend.nodes;

import frontend.LexType;
import frontend.NodeRegistry;
import frontend.NodeType;

import java.util.stream.Stream;

public class LAndExp extends ConnectExp {
    public LAndExp() {
        super(NodeType.L_AND_EXP, NodeRegistry.EQ_EXP);
    }

    @Override
    public ConnectExp get() {
        return new LAndExp();
    }

    @Override
    public Stream<LexType> connectLex() {
        return Stream.of(LexType.AND);
    }

    public static Node parse() {
        LAndExp lAndExp = new LAndExp();
        return lAndExp._parse();
    }
}

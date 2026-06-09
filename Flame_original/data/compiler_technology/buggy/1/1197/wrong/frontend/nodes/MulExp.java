package frontend.nodes;

import frontend.LexType;
import frontend.NodeRegistry;
import frontend.NodeType;

import java.util.stream.Stream;

public class MulExp extends ConnectExp {
    public MulExp() {
        super(NodeType.MUL_EXP, NodeRegistry.UNARY_EXP);
    }

    @Override
    public ConnectExp get() {
        return new MulExp();
    }

    @Override
    public Stream<LexType> connectLex() {
        return Stream.of(LexType.MULT, LexType.DIV, LexType.MOD);
    }

    public static Node parse() {
        MulExp mulExp = new MulExp();
        return mulExp._parse();
    }
}

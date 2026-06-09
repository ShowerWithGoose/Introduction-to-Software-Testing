package frontend.nodes;

import frontend.LexType;
import frontend.NodeRegistry;
import frontend.NodeType;

import java.util.stream.Stream;

public class AddExp extends ConnectExp {
    public AddExp() {
        super(NodeType.ADD_EXP, NodeRegistry.MUL_EXP);
    }

    @Override
    public ConnectExp get() {
        return new AddExp();
    }

    @Override
    public Stream<LexType> connectLex() {
        return Stream.of(LexType.PLUS, LexType.MINU);
    }

    public static Node parse() {
        AddExp addExp = new AddExp();
        return addExp._parse();
    }
}

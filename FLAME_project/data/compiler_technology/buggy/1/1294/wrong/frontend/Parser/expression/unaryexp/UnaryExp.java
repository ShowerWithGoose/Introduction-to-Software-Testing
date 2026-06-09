package frontend.Parser.expression.unaryexp;

import frontend.Parser.GrammarNode;

public class UnaryExp implements GrammarNode {
    private final String grammarName = "<UnaryExp>";
    private UnaryExpPort unaryExpPort;
    public UnaryExp(UnaryExpPort unaryExpPort) {
        this.unaryExpPort = unaryExpPort;
    }
    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryExpPort.grammarOutput());
        sb.append(this.grammarName).append('\n');
        return sb.toString();
    }
}

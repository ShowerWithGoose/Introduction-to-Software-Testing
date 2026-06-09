package frontend.Parser.expression.primaryexp;

import frontend.Parser.expression.unaryexp.UnaryExpPort;

public class PrimaryExp implements UnaryExpPort {
    private final String grammarName = "<PrimaryExp>";
    private PrimaryExpPort primaryExpPort;

    public PrimaryExp(PrimaryExpPort primaryExpPort) {
        this.primaryExpPort = primaryExpPort;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(primaryExpPort.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}

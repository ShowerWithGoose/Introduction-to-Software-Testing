package frontend.Parser.expression.primaryexp;

import frontend.Parser.GrammarNode;
import frontend.Parser.terminal.IntConst;

public class Number implements PrimaryExpPort {
    private final String grammarName = "<Number>";
    private IntConst intConst;
    public Number(IntConst intConst) {
        this.intConst = intConst;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intConst.getToken().grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}

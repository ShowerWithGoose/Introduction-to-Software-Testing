package frontend.Parser.expression.primaryexp;

import frontend.Parser.GrammarNode;
import frontend.Parser.terminal.CharConst;

public class Character implements PrimaryExpPort {
    private final String grammarName = "<Character>";
    private CharConst charConst;
    public Character(CharConst charConst) {
        this.charConst = charConst;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.charConst.getToken().grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}

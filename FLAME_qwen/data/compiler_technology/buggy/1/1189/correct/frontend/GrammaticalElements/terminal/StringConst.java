package frontend.GrammaticalElements.terminal;

import frontend.Token;

public class StringConst {
    private final String name = "<StringConst>";
    private Token string;

    public StringConst(Token string) {
        this.string = string;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(string.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}

package frontend.parser.expression.primaryexp;

import frontend.parser.terminal.CharConst;
import frontend.parser.terminal.IntConst;

public class Character implements PrimaryExpEle{
    public final String name = "<Character>";
    public CharConst charConst;

    public Character(CharConst charConst) {
        this.charConst = charConst;
    }

    public CharConst getIntConst() {
        return charConst;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(charConst.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return String.valueOf(this.charConst.token.content);
    }
    public int my_line_num() {
        return charConst.my_line_num();
    }
}

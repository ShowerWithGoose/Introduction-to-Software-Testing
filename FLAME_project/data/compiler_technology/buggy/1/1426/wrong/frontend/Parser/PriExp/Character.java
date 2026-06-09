package frontend.Parser.PriExp;

import frontend.Parser.Output;
import frontend.Parser.solid.CharConst;
import frontend.Parser.solid.IntConst;

public class Character implements PrimaryExpInf {
    private final String name = "<Character>";
    private CharConst charConst;

    public Character(CharConst charConst) {
        this.charConst = charConst;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(charConst.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

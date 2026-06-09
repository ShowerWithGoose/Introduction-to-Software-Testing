package frontend.Parser.PriExp;

import frontend.Parser.Output;
import frontend.Parser.solid.IntConst;

public class Number implements PrimaryExpInf {
    private final String name = "<Number>";
    private IntConst intConst;

    public Number(IntConst intConst) {
        this.intConst = intConst;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(intConst.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return String.valueOf(this.intConst.getNum());
    }
}

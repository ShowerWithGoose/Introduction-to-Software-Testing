package frontend.Parser.Exp;

import frontend.Parser.Output;
import frontend.Parser.Val.ConstInitValInf;

public class ConstExp implements ConstInitValInf {
    private final String name = "<ConstExp>";
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

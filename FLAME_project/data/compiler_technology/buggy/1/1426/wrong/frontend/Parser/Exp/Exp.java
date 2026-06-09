package frontend.Parser.Exp;

import frontend.Parser.Output;
import frontend.Parser.Val.InitValInf;

public class Exp implements InitValInf {
    private final String name = "<Exp>";
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.addExp.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

package frontend.parser.expression;

import frontend.parser.declaration.variable.initval.InitValEle;
import frontend.parser.expression.multiexp.AddExp;

public class Exp implements InitValEle {
    public final String name = "<Exp>";
    public AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public AddExp getAddExp() {
        return addExp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.addExp.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        return this.addExp.my_line_num();
    }
}

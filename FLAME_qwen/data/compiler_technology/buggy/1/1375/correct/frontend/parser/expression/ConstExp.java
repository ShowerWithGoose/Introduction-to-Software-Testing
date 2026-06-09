package frontend.parser.expression;

import frontend.parser.declaration.constant.constinitval.ConstInitValEle;
import frontend.parser.expression.multiexp.AddExp;

public class ConstExp implements ConstInitValEle {
    public final String name="<ConstExp>";
    public AddExp addExp;
    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        return addExp.my_line_num();
    }
}

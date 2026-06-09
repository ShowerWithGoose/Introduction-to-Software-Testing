package frontend.parser.expression;

import frontend.parser.expression.lOrExp.AddExp;
import frontend.parser.init.ConstInitValUnit;

public class ConstExp implements ConstInitValUnit {
    private String name = "<ConstExp>";
    //ConstExp â†’ AddExp
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}

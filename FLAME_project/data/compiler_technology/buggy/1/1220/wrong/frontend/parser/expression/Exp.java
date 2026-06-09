package frontend.parser.expression;

import frontend.parser.expression.lOrExp.AddExp;
import frontend.parser.init.InitValUnit;

public class Exp implements InitValUnit {
    private String name = "<Exp>";

    private AddExp addExp;

    public Exp(AddExp addExp) {
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

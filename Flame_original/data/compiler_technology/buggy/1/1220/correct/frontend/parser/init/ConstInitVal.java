package frontend.parser.init;

import frontend.parser.SyntaxUnit;

public class ConstInitVal implements SyntaxUnit {
    //ConstInitVal â†’ ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private final String name = "<ConstInitVal>";
    private ConstInitValUnit constInitValUnit;

    public ConstInitVal(ConstInitValUnit constInitValUnit) {
        this.constInitValUnit = constInitValUnit;
    }

    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(constInitValUnit.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}

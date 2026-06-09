package frontend.parser.init;

import frontend.parser.SyntaxUnit;

public class InitVal implements SyntaxUnit {
    private String name = "<InitVal>";
    private InitValUnit initValUnit;

    public InitVal(InitValUnit initValUnit) {
        this.initValUnit = initValUnit;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(initValUnit.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}

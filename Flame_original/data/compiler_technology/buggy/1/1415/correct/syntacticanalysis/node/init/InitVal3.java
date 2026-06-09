package syntacticanalysis.node.init;

import lexicalanalysis.Token;

public class InitVal3 extends InitVal {
    private String name = "<InitVal>";
    private Token stringConst;

    public InitVal3(Token stringConst) {
        this.stringConst = stringConst;
    }

    public String syntaxOutput() {
        return stringConst + "\n" + name;
    }
}

package syntacticanalysis.node.init;

import lexicalanalysis.Token;

public class ConstInitVal3 extends ConstInitVal {
    private String name = "<ConstInitVal>";
    private Token stringConst;

    public ConstInitVal3(Token stringConst) {
        this.stringConst = stringConst;
    }

    @Override
    public String syntaxOutput() {
        return stringConst + "\n" + name;
    }
}

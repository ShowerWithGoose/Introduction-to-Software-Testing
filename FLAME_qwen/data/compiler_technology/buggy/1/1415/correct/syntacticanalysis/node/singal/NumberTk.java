package syntacticanalysis.node.singal;

import lexicalanalysis.Token;

public class NumberTk {
    private String name = "<Number>";
    private Token intCon;

    public NumberTk(Token intCon)
    {
        this.intCon = intCon;
    }

    public String syntaxOutput() {
        return intCon + "\n" + name;
    }
}

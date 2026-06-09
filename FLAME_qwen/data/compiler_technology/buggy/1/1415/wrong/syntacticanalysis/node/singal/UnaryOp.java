package syntacticanalysis.node.singal;

import lexicalanalysis.Token;

public class UnaryOp {
    private String name = "<UnaryOp>";
    private Token threeToken; //+ - !

    public UnaryOp(Token threeToken)
    {
        this.threeToken = threeToken;
    }

    public String syntaxOutput() {
        return threeToken + "\n" + name;
    }
}

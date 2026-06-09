package syntacticanalysis.node.function;

import lexicalanalysis.Token;

public class FuncType {
    private String name = "<FuncType>";
    private Token type;

    public FuncType(Token type)
    {
        this.type = type;
    }

    public String syntaxOutput()
    {
        return type + "\n" + name;
    }
}

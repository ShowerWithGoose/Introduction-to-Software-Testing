package syntacticanalysis.node.singal;

import lexicalanalysis.Token;

public class CharacterTk {
    private String name = "<Character>";
    private Token chrCon;

    public CharacterTk(Token chrCon)
    {
        this.chrCon = chrCon;
    }

    public String syntaxOutput() {
        return chrCon + "\n" + name;
    }
}

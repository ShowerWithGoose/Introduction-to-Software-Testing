package syntacticanalysis.node.expression;

import syntacticanalysis.node.singal.CharacterTk;

public class PrimaryExp4 extends PrimaryExp {
    private String name = "<PrimaryExp>";
    private CharacterTk characterTk;

    public PrimaryExp4(CharacterTk characterTk)
    {
        this.characterTk = characterTk;
    }

    @Override
    public String syntaxOutput() {
        return characterTk.syntaxOutput() + "\n" + name;
    }
}

package frontend.parseApart.NodeDef.Exps;

import frontend.Token;

public class MyCharacter extends  PrimaryExp{
    private Character character;
    private int line;

    public MyCharacter(Token token) {
        this.character = token.getName().charAt(0);
        this.line = token.getLine();
    }

    public String returnSymbolType() {
        String string = "<Character>";
        return string;
    }
}

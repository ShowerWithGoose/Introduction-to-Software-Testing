package frontend.Parser.Exp.Type;

import frontend.Lexer.LexType;

public class Character implements PEinterface {
    private final LexType character;

    public Character(LexType character) {
        this.character = character;
    }

    public int getLine() {
        return this.character.getLine();
    }

    @Override
    public String toString() {
        return character.toString() + "<Character>\n";
    }
}

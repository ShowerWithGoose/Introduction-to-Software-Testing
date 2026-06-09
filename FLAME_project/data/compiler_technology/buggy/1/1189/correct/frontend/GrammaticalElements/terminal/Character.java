package frontend.GrammaticalElements.terminal;

import frontend.Token;

public class Character {
    private final String name = "<Character>";
    private Token character;

    public Character(Token character) {
        this.character = character;
    }

    @Override
    public String toString() {
        return character.toString() + this.name + '\n';
    }
}

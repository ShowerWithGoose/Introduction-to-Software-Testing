package frontend.parser.expression.primaryexp;

import frontend.lexer.TokenListIterator;
import frontend.parser.terminal.CharConst;
import frontend.parser.terminal.CharConstParser;

public class CharacterParser {
    private TokenListIterator iterator;

    public CharacterParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Character parseCharacter() {
        CharConstParser charConstParser = new CharConstParser(this.iterator);
        CharConst charConst = charConstParser.parseCharConst();
        Character character = new Character(charConst);
        return character;
    }
}

package frontend.Parser.PriExp;

import frontend.TokenListReader;
import frontend.Parser.solid.CharConst;
import frontend.Parser.solid.CharConstParser;

public class CharacterParser {
    private TokenListReader reader;
    public CharacterParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Character parseCharacter() {
        CharConstParser charConstParser = new CharConstParser(this.reader);
        CharConst charConst = charConstParser.parseCharConst();
        Character character = new Character(charConst);
        return character;
    }
}

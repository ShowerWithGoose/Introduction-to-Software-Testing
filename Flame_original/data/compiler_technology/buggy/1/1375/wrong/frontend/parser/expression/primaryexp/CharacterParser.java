package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.parser.terminal.CharConst;
import frontend.parser.terminal.CharConstParser;
import frontend.parser.terminal.IntConst;
import frontend.parser.terminal.IntConstParser;
import frontend.parser.expression.primaryexp.Character;

import java.util.ArrayList;


public class CharacterParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public CharacterParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public Character parseCharacter() {
        CharConstParser charConstParser = new CharConstParser(this.iterator,this.error_tokens);
        CharConst charConst = charConstParser.parseCharConst();
        Character character = new Character(charConst);
        return character;
    }
}

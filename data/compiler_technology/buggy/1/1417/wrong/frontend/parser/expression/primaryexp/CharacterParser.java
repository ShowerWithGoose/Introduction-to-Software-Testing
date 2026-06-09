package frontend.parser.expression.primaryexp;

import frontend.lexer.TokenList;
import frontend.parser.Node;
import frontend.parser.terminal.CharConst;
import frontend.parser.terminal.CharConstParser;

import java.util.ArrayList;

public class CharacterParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public CharacterParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public Character parseCharacter() {
        CharConstParser characterParser = new CharConstParser(tokenList);
        CharConst charConst = characterParser.parseCharConst();
        this.nodes.add(charConst);
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        Character character = new Character(startLine, endLine, "<Character>", this.nodes);
        return character;
    }
}

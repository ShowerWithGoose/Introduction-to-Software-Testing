package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class CharacterNode {
    //字符 Character → CharConst
    private Token charConst;

    public CharacterNode(Token charConst) {
        this.charConst = charConst;
    }

    public void print() {
        IO.ParserOutput(charConst);
        IO.ParserOutput(Parser.nodeType.get(NodeType.Character));
    }
}

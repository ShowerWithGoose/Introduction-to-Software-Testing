package frontend.treenode;

import frontend.token.Token;
import java.io.IOException;
import static frontend.executor.Parser.writeParser;

// 字符 Character → CharConst
public class Character {
    public String nodeName;
    public Token charConstToken;

    public Character(String nodeName, Token charConstToken) {
        this.nodeName = nodeName;
        this.charConstToken = charConstToken;
    }

    public void print() throws IOException {
        writeParser(charConstToken.getTypeAndContent());
        writeParser(nodeName);
    }
}

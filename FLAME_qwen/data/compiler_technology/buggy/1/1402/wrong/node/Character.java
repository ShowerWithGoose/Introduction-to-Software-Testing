package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 字符 Character → CharConst
public class Character {
    private String nodeName;
    private Token charConstToken;

    public Character(String nodeName, Token charConstToken) {
        this.nodeName = nodeName;
        this.charConstToken = charConstToken;
    }

    public void print() throws IOException {
        writeParser(charConstToken.toString());
        writeParser(nodeName);
    }
}

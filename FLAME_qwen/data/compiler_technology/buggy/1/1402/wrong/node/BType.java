package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 基本类型 BType → 'int' | 'char'
public class BType {
    private Token intToken;
    private Token charToken;

    public BType(Token intToken, Token charToken) {
        this.intToken = intToken;
        this.charToken = charToken;
    }

    public void print() throws IOException {
        if (intToken != null)
            writeParser(intToken.toString());
        else
            writeParser(charToken.toString());
    }
}

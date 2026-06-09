package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 函数类型 FuncType → 'void' | 'int' | 'char'
public class FuncType {
    private String nodeName;
    private Token voidToken;
    private Token intToken;
    private Token charToken;

    public FuncType(String nodeName, Token voidToken, Token intToken, Token charToken) {
        this.nodeName = nodeName;
        this.voidToken = voidToken;
        this.intToken = intToken;
        this.charToken = charToken;
    }

    public void print() throws IOException {
        if (voidToken != null)
            writeParser(voidToken.toString());
        else if (intToken != null)
            writeParser(intToken.toString());
        else
            writeParser(charToken.toString());
        writeParser(nodeName);
    }
}

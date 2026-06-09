package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;

// 函数类型 FuncType → 'void' | 'int' | 'char'
public class FuncType {
    public String nodeName;
    public Token voidToken, intToken, charToken;

    public FuncType(String nodeName, Token voidToken, Token intToken, Token charToken) {
        this.nodeName = nodeName;
        this.voidToken = voidToken;
        this.intToken = intToken;
        this.charToken = charToken;
    }

    public void print() throws IOException {
        if (voidToken != null)
            writeParser(voidToken.getTypeAndContent());
        else if (intToken != null)
            writeParser(intToken.getTypeAndContent());
        else
            writeParser(charToken.getTypeAndContent());
        writeParser(nodeName);
    }
}

package frontend.treenode;

import frontend.token.Token;
import java.io.IOException;
import static frontend.executor.Parser.writeParser;

// 基本类型 BType → 'int' | 'char'
public class BType {
    public Token intToken;
    public Token charToken;

    public BType(Token intToken, Token charToken) {
        this.intToken = intToken;
        this.charToken = charToken;
    }

    public void print() throws IOException {
        if (intToken != null)
            writeParser(intToken.getTypeAndContent());
        else
            writeParser(charToken.getTypeAndContent());
    }
}

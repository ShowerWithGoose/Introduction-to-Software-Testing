package Symbol;

import node.Token;
import node.TokenType;

import java.util.ArrayList;

public class SignalParams {
    private Token ident;
    private int type; // 0 int/char  1 intarray 2 chararray

    public SignalParams(Token ident, int type) {
        this.ident = ident;
        this.type = type;
    }

    public int getType() {
        return type;
    }

    public Token getIdent() {
        return ident;
    }
}

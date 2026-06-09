package parser.func;

import lexer.Token;

public class FuncType {
    private final Token value;

    public FuncType(Token value) {
        this.value = value;
    }

    public String toString() {
        return this.value.toString() + "\n<FuncType>\n";
    }
}

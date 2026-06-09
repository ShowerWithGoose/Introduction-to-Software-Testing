package Fronted.parser.syntax;

import Fronted.lexer.Token;

// FuncType â†’ 'void' | 'int' | 'char'
public class FuncType {

    private static final String name = "<FuncType>";

    private Token type;

    public FuncType(Token type) {
        this.type = type;
    }

    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(type);
        out.append(name).append("\n");
        return out.toString();
    }
}

package frontend.lexer;

import frontend.Category;

public class Token {
    private final Category category;
    private final String value;
    private final int line;

    public Token(Category category, String value, int line) {
        this.category = category;
        this.value = value;
        this.line = line;
    }

    public Category getCategory() {
        return this.category;
    }

    public String getValue() {
        return this.value;
    }

    public int getLine() {
        return this.line;
    }

    @Override
    public String toString() {
        return this.category + " " + this.value;
    }
}
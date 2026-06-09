package frontend;

import nonTerminal.*;

public class Parser {
    private final CompUnit compUnit;

    public Parser(Lexer lexer) {
        compUnit = new CompUnit();
        compUnit.parser(lexer);
    }

    public CompUnit getCompUnit() {
        return compUnit;
    }
}

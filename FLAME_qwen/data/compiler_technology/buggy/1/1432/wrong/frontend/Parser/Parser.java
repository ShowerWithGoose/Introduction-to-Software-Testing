package frontend.Parser;

import frontend.Parser.AST.CompUnit;

import java.io.IOException;

public class Parser {
    private final CompUnit compUnit;

    public Parser() {
        compUnit = new CompUnit();
    }

    public void parse() throws IOException {
        compUnit.parse();
    }
}

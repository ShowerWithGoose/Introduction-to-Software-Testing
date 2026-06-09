package frontend;

import java.util.ArrayList;

import nonTerminal.*;

public class Parser {
    private final Lexer lexer;
    private CompUnit compUnit;
    private ArrayList<String> parserResult;
    private ArrayList<String> errors;

    public Parser(Lexer lexer) {
        this.lexer = lexer;
        this.compUnit = new CompUnit();
        this.parserResult = new ArrayList<>();
        this.errors = new ArrayList<>();
    }

    public void parserCompUnit() {
        compUnit.parser(lexer, errors);
    }

    public ArrayList<String> outputCompUnit() {
        compUnit.output(parserResult);
        return parserResult;
    }

    public ArrayList<String> getErrors() {
        return errors;
    }
}

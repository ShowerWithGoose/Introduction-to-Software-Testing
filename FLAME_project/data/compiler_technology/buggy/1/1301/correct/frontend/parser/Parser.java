package frontend.parser;

import frontend.lexer.TokenList;

public class Parser {
    private CompUnit compUnit;
    private TokenList tokens;
    private int errorNum;

    public Parser(TokenList tokens) {
        this.compUnit = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public void parse() {
        CompUnit compUnit = new CompUnit(tokens);
        errorNum += compUnit.parse();
        this.compUnit = compUnit;
    }

    public int getErrorNum() { return errorNum; }

    public String toSyntaxTree() {
        return compUnit.toSyntaxTree();
    }
}

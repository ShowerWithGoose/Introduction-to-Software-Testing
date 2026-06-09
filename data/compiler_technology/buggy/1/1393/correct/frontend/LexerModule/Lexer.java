package frontend.LexerModule;

public class Lexer {
    private final String name;
    private final LexerType lexerType;
    private final char errorType;
    private final int lineNumber;

    public Lexer(String name, LexerType lexerType, char errorType, int lineNumber) {
        this.name = name;
        this.lexerType = lexerType;
        this.errorType = errorType;
        this.lineNumber = lineNumber;
    }

    @Override
    public String toString() {
        if (isError()) {
            return lineNumber + " " + errorType;
        } else {
            return lexerType + " " + name;
        }
    }

    public boolean isError() {
        return errorType != '0';
    }

    public LexerType getType() {
        return lexerType;
    }

    public int getLineNumber() {
        return lineNumber;
    }
    public String getName(){
        return name;
    }
}

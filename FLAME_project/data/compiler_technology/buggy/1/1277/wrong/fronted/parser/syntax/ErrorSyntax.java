package fronted.parser.syntax;

import config.ErrorType;

public class ErrorSyntax {
    private int line;
    private ErrorType type;
    public ErrorSyntax(int line, ErrorType type) {
        this.line = line;
        this.type = type;
    }

    public int getLine() {
        return line;
    }

    public ErrorType getType() {
        return type;
    }
}

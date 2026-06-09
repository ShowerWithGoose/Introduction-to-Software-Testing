package frontend.declaration;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;

public class BTypeParser {
    private TokenListIterator iterator;

    public BTypeParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public BType parseBtype() {
        Token first = this.iterator.readNextToken();
        if (!first.getType().equals(TokenType.INTTK) && !first.getType().equals(TokenType.CHARTK)) {
            System.err.println("ERROR: Expected 'int' or 'char', but found: " + first.getContent() + " at line: " + first.getLineIndex());
        }
        return new BType(first);
    }
}

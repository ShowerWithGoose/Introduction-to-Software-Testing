package frontend.Lexer;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Token {
    private TokenType type;
    private String value;
    private int lineno;

    public Token(TokenType type, String value, int lineNum) {
        this.type = type;
        this.value = value;
        this.lineno = lineNum;
    }

    public TokenType getType() {
        return type;
    }

    public int getLineno() {
        return lineno;
    }

    @Override
    public String toString() {
        return type.toString() + ' ' + value + '\n';
    }

    public static void sortTokensByLineno(List<Token> tokens) {
        Collections.sort(tokens, new Comparator<Token>() {
            @Override
            public int compare(Token t1, Token t2) {
                return Integer.compare(t1.getLineno(), t2.getLineno());
            }
        });
    }
}


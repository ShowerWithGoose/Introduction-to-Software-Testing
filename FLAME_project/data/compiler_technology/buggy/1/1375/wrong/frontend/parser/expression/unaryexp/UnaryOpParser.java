package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class UnaryOpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public UnaryOpParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public UnaryOp parseUnaryOp() {
        Token token = this.iterator.readNextToken();
        if (!(token.type.equals(TokenType.PLUS) ||
                token.type.equals(TokenType.MINU) ||
                token.type.equals(TokenType.NOT))) {
            System.out.println("EXPECT UNARYOP HERE");
        }
        UnaryOp unaryOp = new UnaryOp(token);
        return unaryOp;
    }
}

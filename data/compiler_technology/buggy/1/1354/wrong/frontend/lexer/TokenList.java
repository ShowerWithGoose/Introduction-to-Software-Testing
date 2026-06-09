package frontend.lexer;

import Utils.WrongError;

import java.util.ArrayList;
import java.util.Arrays;

import static Utils.WrongError.errors;

public class TokenList {
    public final ArrayList<Token> tokens;
    private int index = 0;
    public TokenList() {
        tokens = new ArrayList<>();
    }
    public void append(Token token) {
        tokens.add(token);
    }
    public boolean hasNext() {
        return index < tokens.size();
    }
    public Token checkAheadChar(int count) {
        return tokens.get(index + count);
    }

    public Token getCharWithJudge(TokenType... types) {
        //TODO: 需要异常处理吗？另外，要加入EOF判断和自定义异常
        Token token = tokens.get(index);
        for (TokenType type : types) {
            if (token.type.equals(type)) {
                index++;
                return token;
            }
        }
        if (types.length == 1) {
            for (TokenType type : types) {
                if (type.equals(TokenType.SEMICN)) {
                    errors.add(new WrongError("i",tokens.get(index-1).lineIndex));
                } else if (type.equals(TokenType.RPARENT)) {
                    errors.add(new WrongError("j",tokens.get(index-1).lineIndex));
                } else if (type.equals(TokenType.RBRACK)) {
                    errors.add(new WrongError("k",tokens.get(index-1).lineIndex));
                }
            }
        }
        return null;
    }
    public Token getChar() {
        return tokens.get(index++);
    }
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token.toString());
        }
        return sb.toString();
    }
}

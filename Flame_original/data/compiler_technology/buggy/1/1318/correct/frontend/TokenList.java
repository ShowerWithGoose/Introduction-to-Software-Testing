package frontend;

import java.util.ArrayList;

import static utils.File.WriteFile;

public class TokenList {
    private final ArrayList<Token> tokens = new ArrayList<>();
    private int index = 0;

    public void add(Token token) {
        tokens.add(token);
    }

    public void print() {
        ArrayList<String> content = new ArrayList<>();
        for (Token token : this.tokens) {
            content.add(token.toString());
        }
        WriteFile("lexer.txt", content);
    }

    public boolean hasNext() {
        return index < tokens.size();
    }

    public Token get() {
        return tokens.get(index);
    }

    public Token getLast() {
        return index > 0 ? tokens.get(index - 1) : tokens.get(index);
    }

    public Token ahead(int count) {
        return tokens.get(index + count);
    }

    public Token consume(){
        return tokens.get(index++);
    }

    public boolean isType(TokenType... types){
        TokenType cur = get().getType();
        for (TokenType type : types) {
            if (cur == type) {
                return true;
            }
        }
        return false;
    }

    public Token consume(TokenType... types){
        for (TokenType type : types) {
            if (get().getType() == type) {
                return consume();
            }
        }
        return null;
    }

}
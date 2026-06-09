package frontend;

import java.util.ArrayList;

public class Terminal implements Token {
    String token;
    String type;
    int line;
    ArrayList<Token> sons = new ArrayList<>();

    public Terminal(String token, String type, int line) {
        this.token = token;
        this.type = type;
        this.line = line;
    }

    @Override
    public void addSon(Token t) {
        this.sons.add(t);
    }

    public int getLine() {
        return line;
    }

    public String getToken() {
        return token;
    }

    public String getType() {
        return type;
    }

    public String toString1() {
        return "<>";
    }

    @Override
    public ArrayList<Token> getSons() {
        return sons;
    }

    @Override
    public Token getSon(int x) {
        return sons.get(x);
    }
}

package frontend;

import java.util.ArrayList;

public class FuncDef implements Token {
    ArrayList<Token> sons = new ArrayList<>();

    @Override
    public void addSon(Token t) {
        this.sons.add(t);
    }

    @Override
    public ArrayList<Token> getSons() {
        return sons;
    }

    public String toString1() {
        return "<FuncDef>";
    }

    @Override
    public Token getSon(int x) {
        return sons.get(x);
    }
}

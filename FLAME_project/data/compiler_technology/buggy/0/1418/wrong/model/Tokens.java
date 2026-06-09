package model;

import java.util.ArrayList;
import java.util.List;

//单例模式
public class Tokens {
    private static Tokens instance;
    private List<Token> tokens;

    private Tokens() {
        tokens = new ArrayList<>();
    }

    public static Tokens getInstance() {
        if (instance == null) {
            instance = new Tokens();
        }
        return instance;
    }

    public List<Token> get() {
        return tokens;
    }

    public void add(Token token) {
        tokens.add(token);
    }
}

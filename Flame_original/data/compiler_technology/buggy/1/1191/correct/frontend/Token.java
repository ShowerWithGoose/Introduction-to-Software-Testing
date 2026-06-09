package frontend;

import java.util.ArrayList;

public interface Token {
    void addSon(Token t);

    ArrayList<Token> getSons();

    Token getSon(int x);

    String toString1();
}

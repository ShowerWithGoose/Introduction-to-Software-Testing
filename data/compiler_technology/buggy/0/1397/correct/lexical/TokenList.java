package lexical;

import java.util.ArrayList;

public class TokenList {
    ArrayList<Token> tokens = new ArrayList<>();

    public void add(Token token){
        tokens.add(token);
    }

    public ArrayList<Token> getList() {
        return tokens;
    }
}

package frontend.Lexer;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/3 22:50
 */
public class TokenList {
    private ArrayList<Token> tokenList;

    public TokenList(){
        this.tokenList = new ArrayList<>();
    }

    public void addToken(Token token){
        this.tokenList.add(token);
    }

    public ArrayList<Token> getTokenList(){
        return this.tokenList;
    }
}

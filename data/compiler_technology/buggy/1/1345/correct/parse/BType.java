package parse;

import parse.Token;

public class BType {
    private Token token;

    public Token getToken() {
        return token;
    }

    public void setToken(Token token) {
        this.token = token;
    }

    public BType(TokenList list,WrongList wrongs) {
        Token x = list.readNextToken();
        token = x;
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.printout());
        return sb.toString();
    }

}

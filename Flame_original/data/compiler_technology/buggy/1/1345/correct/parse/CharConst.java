package parse;

public class CharConst {
    private Token token;

    public Token getToken() {
        return token;
    }

    public void setToken(Token token) {
        this.token = token;
    }

    public CharConst(TokenList list,WrongList wrongs) {
        this.token = list.readNextToken();
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.printout());
        return sb.toString();
    }
}

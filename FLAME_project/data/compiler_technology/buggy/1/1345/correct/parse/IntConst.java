package parse;

public class IntConst {
    private Token token;

    public Token getToken() {
        return token;
    }

    public void setToken(Token token) {
        this.token = token;
    }

    public IntConst(TokenList list,WrongList wrongs) {
        this.token = list.readNextToken();
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.printout());
        return sb.toString();
    }
}

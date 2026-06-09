package parse;

public class UnaryOp {
    private final String name = "<UnaryOp>";
    private Token token;


    public Token getToken() {
        return token;
    }

    public void setToken(Token token) {
        this.token = token;
    }

    public String getName() {
        return name;
    }

    public UnaryOp(TokenList list,WrongList wrongs) {
        this.token = list.readNextToken();
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

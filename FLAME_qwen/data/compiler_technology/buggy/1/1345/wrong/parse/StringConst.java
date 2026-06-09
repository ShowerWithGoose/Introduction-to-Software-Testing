package parse;

public class StringConst implements InitValEle,ConstInitValEle{
    private Token token;

    public Token getToken() {
        return token;
    }

    public void setToken(Token token) {
        this.token = token;
    }

    public StringConst(TokenList list,WrongList wrongs){
        this.token = list.readNextToken();
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.printout());
        return sb.toString();
    }
}

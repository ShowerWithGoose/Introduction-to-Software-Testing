package parse;

public class FuncType {
    private final String name = "<FuncType>";
    private Token type;

    public String getName() {
        return name;
    }

    public Token getType() {
        return type;
    }

    public void setType(Token type) {
        this.type = type;
    }

    public FuncType(TokenList list,WrongList wrongs) {
        this.type = list.readNextToken();
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.type.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}

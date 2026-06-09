package frontend;

public class Sym {
    String token;
    String type;
    int line;
    public Sym(String token, String type, int line) {
        this.token = token;
        this.type = type;
        this.line = line;
    }
}

package frontend.Tree;

public class Ident {
    private String ident;
    private int line;

    public Ident(String ident, int line) {
        this.ident = ident;
        this.line = line;
    }

    public int getLine() {
        return line;
    }
}

package frontend;

public class Lexer_out {
    String type;
    String name;
    int line_num;

    public Lexer_out(String type, String name, int line_num) {
        this.name = name;
        this.type = type;
        this.line_num = line_num;
    }
    public String getType() {
        return this.type;
    }

    public String getName() {
        return this.name;
    }
    public int getLine_num() {
        return this.line_num;
    }
}


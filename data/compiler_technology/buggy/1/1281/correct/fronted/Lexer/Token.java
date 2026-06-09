package fronted.Lexer;

/**
 * @author
 * @Description:
 * @date 2024/10/11 15:33
 */
public class Token {
    TokenType type;
    String value;
    int line;

    Token(TokenType type, String value, int line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }

    public TokenType getType() {
        return type;
    }

    public int getLine() {
        return line;
    }

    public String output(){
        return this.type + " " + this.value + "\n";
    }
}
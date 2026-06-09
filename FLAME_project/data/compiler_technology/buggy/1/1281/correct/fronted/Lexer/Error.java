package fronted.Lexer;

/**
 * @author
 * @Description:
 * @date 2024/10/12 20:34
 */
public class Error {
    public int line;
    public String code;

    public Error(int line, String code) {
        this.line = line;
        this.code = code;
    }
}
/**
 * Classname Error
 * Description TODO
 * Date 2024/10/12 10:21
 * Created ZHW
 */
public class Error {
    private int line;
    private String error;

    public Error(int line, String error){
        this.error = error;
        this.line = line;
    }

    public int getLine() {
        return line;
    }

    public void setLine(int line) {
        this.line = line;
    }

    public String getError() {
        return error;
    }

    public void setError(String error) {
        this.error = error;
    }
}

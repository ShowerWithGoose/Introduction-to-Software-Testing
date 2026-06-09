
public class Error {
    private int lineNum;
    private String message;

    public Error(){}

    public Error(int lineNum, String message) {
        this.lineNum = lineNum;
        this.message = message;
    }

    public int getLineNum() {
        return lineNum;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
}

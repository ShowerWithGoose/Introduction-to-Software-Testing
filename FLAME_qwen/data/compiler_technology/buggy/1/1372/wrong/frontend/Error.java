package frontend;

public class Error {
    private final Integer lineNum;
    private final String error;

    public Error(Integer lineNum, String error) {
        this.error = error;
        this.lineNum = lineNum;
    }

    public Integer getLineNum() {
        return lineNum;
    }

    public String getError() {
        return error;
    }
}

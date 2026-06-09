package Parser;

/**
 * @Description:
 * @date 2024/10/15
 */
public class ErrorP {
    private String errorType;
    private int errorLine;

    public ErrorP(String errorType, int errorLine) {
        this.errorType = errorType;
        this.errorLine = errorLine;
    }

    public String getErrorType() {
        return errorType;
    }

    public int getErrorLine() {
        return errorLine;
    }
}

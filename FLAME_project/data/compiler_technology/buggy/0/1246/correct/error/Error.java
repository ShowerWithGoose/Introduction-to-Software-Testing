package error;

/**
 * @Description 错饭
 * @Author
 * @Date 2024/9/19
 */
public class Error {
    private ErrorType type;
    private int lineNum;

    public Error(ErrorType type, int lineNum) {
        this.type = type;
        this.lineNum = lineNum;
    }

    public ErrorType getType() {
        return type;
    }

    public int getLineNum() {
        return lineNum;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Error)) {
            return false;
        } else {
            Error error = (Error) o;
            return error.getType() == this.getType() && error.getLineNum() == this.getLineNum();
        }
    }

    @Override
    public String toString() {
        return lineNum + " " + type;
    }

    public String getOutputString() {
        return lineNum + " " + type + "\n";
    }
}

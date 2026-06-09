package error;

/**
 * 错误类
 */
public class Error implements Comparable<Error> {
    private final ErrorType type;  // 所属错误类别
    private final int lineIndex;     // 行号，从1开始

    public Error(int lineIndex, ErrorType type) {
        this.lineIndex = lineIndex;
        this.type = type;
    }

    public ErrorType getType() {
        return type;
    }

    public int getLineIndex() {
        return lineIndex;
    }

    public String getErrorTypeCode() {
        return this.type.getCode();
    }

    @Override
    public int compareTo(Error other) {
        return Integer.compare(this.lineIndex, other.lineIndex);
    }

    @Override
    public String toString() {
        return lineIndex + " " + type.getCode() + "\n";
    }

    public String output() {
        return toString();
    }
}

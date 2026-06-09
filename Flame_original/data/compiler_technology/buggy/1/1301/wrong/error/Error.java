package error;

public class Error implements Comparable<Error> {
    private int lineNum;
    private char errorType;

    public Error(int lineNum, char errorType) {
        this.lineNum = lineNum;
        this.errorType = errorType;
    }

    public int getLineNum() {
        return lineNum;
    }

    @Override
    public int compareTo(Error o) {
        return Integer.compare(this.lineNum, o.getLineNum());
    }

    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(lineNum);
        sb.append(' ');
        sb.append(errorType);
        sb.append('\n');
        return sb.toString();
    }
}

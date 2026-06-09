package node;

public class tokenError implements Comparable {
    private int lineNum;
    private String errorType;

    public tokenError(int lineNum, String errorType) {
        this.lineNum = lineNum;
        this.errorType = errorType;
    }

    public String toString() {
        return lineNum + " " + errorType;
    }


    public int getLineNum() {
        return lineNum;
    }

    @Override
    public int compareTo(Object o) {
        return lineNum - ((tokenError)o).lineNum;
    }
}

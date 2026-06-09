package frontend;

public class ErrInfo {
    int lineNum;
    char errType;

    public ErrInfo(int lineNum, char errType) {
        this.lineNum = lineNum;
        this.errType = errType;
    }

    public void print() {
//        System.err.println(this.lineNum + " " + this.errType);
        System.err.println(this.lineNum + " " + this.errType);
    }

    public char getErrType() {
        return this.errType;
    }
}

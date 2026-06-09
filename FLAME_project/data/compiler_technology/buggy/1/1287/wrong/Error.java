public class Error {
    private int linenum;
    private String type;

    public Error(int linenum, String type) {
        this.linenum = linenum;
        this.type = type;
    }

    public int getLinenum() {
        return linenum;
    }

    public String toString() {
        return linenum + " " + type;
    }
}

public class ErrorInfo {
    private String kind;
    private int Line;

    public ErrorInfo(String kind, int line) {
        this.kind = kind;
        this.Line = line;
    }

    public void printError() {
        System.out.println(Line + " " + kind);
    }

    public void setInfo(String kind, int line) {
        this.kind = kind;
        this.Line = line;
    }
}

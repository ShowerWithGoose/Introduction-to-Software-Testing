package Utils;

public class WrongError {
    private String error;
    private int lineIndex;
    public WrongError(String error, int lineIndex) {
        this.error = error;
        this.lineIndex = lineIndex;
    }
    public String getErrorMessage() {
        return lineIndex + " " + error + "\n";
    }
}

package Utils;

import java.util.ArrayList;

public class WrongError {
    private String error;
    public int lineIndex;
    public static ArrayList<WrongError> errors = new ArrayList<>();
    public WrongError(String error, int lineIndex) {
        this.error = error;
        this.lineIndex = lineIndex;
    }
    public String getErrorMessage() {
        return lineIndex + " " + error + "\n";
    }
}

package Error;

public class error {

    private int errorLineNumber;
    private String errorMessage;

    private String errorCase;

    public error(String errorMessage, int errorLineNumber, String errorCase) {
        this.errorMessage = errorMessage;
        this.errorLineNumber = errorLineNumber;
        this.errorCase = errorCase;
    }

    public String toString() {
        return errorLineNumber + " " + errorCase + "\n";
    }

    public int getErrorLineNumber() {
        return errorLineNumber;
    }

    public String getErrorCase() {
        return errorCase;
    }

    public String getErrorMessage() {
        return errorMessage;
    }

}

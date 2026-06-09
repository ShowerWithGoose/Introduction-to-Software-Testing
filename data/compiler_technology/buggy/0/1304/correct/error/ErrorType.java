package error;

public enum ErrorType {
    INVALID_TOKEN_ERROR('a');

    public final String errorCode;

    private ErrorType(char errorCode) {
        this.errorCode = String.valueOf(errorCode);
    }

    @Override
    public String toString() {
        return this.errorCode;
    }
}

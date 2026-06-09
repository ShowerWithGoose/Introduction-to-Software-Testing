package util.exception;

public class NotImplementedException extends RuntimeException {
    public static void notImplemented() {
        throw new UnsupportedOperationException("This function is not yet implemented.");
    }
}

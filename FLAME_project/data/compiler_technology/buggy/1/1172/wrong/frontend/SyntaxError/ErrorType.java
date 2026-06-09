package frontend.SyntaxError;

public enum ErrorType {
    m, l, k, j, i, h, g, f, e, d, c, b, a;

    // Added a method to get the error code as a character
    public char getCode() {
        return this.name().charAt(0);
    }
}

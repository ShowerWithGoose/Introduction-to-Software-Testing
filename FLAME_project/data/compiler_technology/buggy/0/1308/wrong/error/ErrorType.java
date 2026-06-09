package error;

public enum ErrorType {
    no,
    a;

    @Override
    public String toString() {
        return this.name();
    }

}

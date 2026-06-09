package frontend;

public enum ErrorType {
    a("a"),
    i("i"),
    j("j"),
    ij("ij"),
    k("k");
    private final String value;

    ErrorType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return value;
    }
}

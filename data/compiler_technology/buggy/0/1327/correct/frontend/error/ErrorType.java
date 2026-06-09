package frontend.error;

public enum ErrorType {
    a("lexerError");

    private String des;

    ErrorType(String des) {
        this.des = des;
    }
}

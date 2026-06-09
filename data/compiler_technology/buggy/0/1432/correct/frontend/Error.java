package frontend;

public class Error {
    private final Integer row;
    private final String type;

    public Error(Integer row, String type) {
        this.row = row;
        this.type = type;
    }

    public String toString() {
        return row + " " + type;
    }
}

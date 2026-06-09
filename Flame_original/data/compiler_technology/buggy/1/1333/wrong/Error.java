import java.util.TreeSet;

public class Error {
    private final int position;
    private final String type;

    public Error(int position, String type) {
        this.position = position;
        this.type = type;
    }

    public int getPosition() {
        return this.position;
    }

    public String toString() {
        return this.position + " " + this.type;
    }
}

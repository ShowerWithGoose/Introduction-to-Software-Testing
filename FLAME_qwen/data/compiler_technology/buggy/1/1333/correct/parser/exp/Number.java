package parser.exp;

public class Number implements PrimaryExpForm {
    private final String value;

    public Number(String value) {
        this.value = value;
    }

    public String toString() {
        return "INTCON " + this.value + "\n<Number>\n";
    }
}

package parser.exp;

public class Character implements PrimaryExpForm{
    private final String value;

    public Character(String value) {
        this.value = value;
    }

    public String toString() {
        return "CHRCON " + this.value + "\n<Character>\n";
    }
}

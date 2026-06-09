public class Element extends Node {
    private ParseType parseType;

    public Element(ParseType parseType) {
        this.parseType = parseType;
    }

    public String toString() {
        return "<" + parseType.toString() + ">";
    }
}

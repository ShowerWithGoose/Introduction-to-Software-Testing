
package frontend;

class Token {

    private String type;
    private String value;
    private int lineIndex;

    public Token(String type, String value, int lineIndex) {
        this.type = type;
        this.value = value;
        this.lineIndex = lineIndex;
    }

    public String getType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    public int getLineIndex() {
        return lineIndex;
    }

}
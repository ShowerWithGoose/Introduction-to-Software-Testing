public class ErrorToken {
    ErrorTokenType type;
    String content;
    int lineno;

    public ErrorToken(ErrorTokenType type, String content, int lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }

    public enum ErrorTokenType {
        IllegalSign("a"),
        LackOfSemicn("i"),
        LackOfRparent("j"),
        LackOfRbrack("k");

        private final String value;

        ErrorTokenType(String value) {
            this.value = value;
        }

        public String getValue() {
            return value;
        }

        public static ErrorTokenType fromValue(String value) {
            for (ErrorTokenType type : ErrorTokenType.values()) {
                if (type.value.equals(value)) {
                    return type;
                }
            }
            return null;
        }
    }

    public String toString(int lineno) {
        return String.valueOf(lineno);
    }

    public String toString(ErrorTokenType type) {
        return String.valueOf(type);
    }
}

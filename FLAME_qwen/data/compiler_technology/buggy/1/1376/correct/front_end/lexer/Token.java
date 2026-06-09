package front_end.lexer;

public class Token {
    private TokenType type;
    private String value;

    public Token(TokenType type, String value) {
        this.type = type;
        this.value = value;
    }

    public TokenType getType() {
        return type;
    }

    public void setType(TokenType type) {
        this.type = type;
    }

    public String getValue() {
        return value;
    }

    public String toString() {
        StringBuilder result = new StringBuilder();
//        if (type == TokenType.STRCON) {
//            result.append("\"");
//        }
//        if (type == TokenType.CHRCON) {
//            result.append("'");
//        }
        for (int i = 0; i < value.length(); i++) {
            char c = value.charAt(i);
            result.append(c);
//            if (c == '\n') {
//                result.append("\\n");
//            } else if (c == '\t') {
//                result.append("\\t");
//            } else if (c == '\r') {
//                result.append("\\r");
//            } else if (c == '\b') {
//                result.append("\\b");
//            } else if (c == '\f') {
//                result.append("\\f");
//            } else if (c == '\\') {
//                result.append("\\\\");
//            } else if (c == '\'') {
//                result.append("\\'");
//            } else if (c == '\"') {
//                result.append("\\\"");
//            } else if (c == '\0') {
//                result.append("\\0");
//            } else if (c == '\007') {
//                result.append("\\a");
//            } else if (c == '\013') {
//                result.append("\\v");
//            } else {
//                result.append(c);
//            }
        }
//        if (type == TokenType.STRCON) {
//            result.append("\"");
//        }
//        if (type == TokenType.CHRCON) {
//            result.append("'");
//        }
        return result.toString();
    }
}

package assist;

public class LeafNode extends Node{
    private Token.Type leafType;
    private String value;
    private char errorCode;

    public LeafNode(Token.Type type, String value, int startLine, char error) {
        this.type = SyntaxType.LeafType;
        this.leafType = type;
        this.value = value;
        this.startLine = startLine; //叶节点的startLine就是它所在的Line
        this.errorCode = error;
    }

    public String getValue() {
        return value;
    }

    public char showError() {
        return errorCode;
    }

    public void setErrorCode(char errorCode) {
        this.errorCode = errorCode;
    }

    @Override
    public String toString() {
        if (errorCode == '\0') {
            return (leafType.name() + " " + value + "\n");
        } else {
            return (leafType.name() + " " + value + " " + errorCode + "\n");
        }
    }
}

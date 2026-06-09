package AST;

public class StringConst {
    private String value;
    private String trueValue;   //no quotes

    public StringConst(String value) {
        this.value = value;
        this.trueValue = value.substring(1, value.length() - 1);
    }

    public String getValue() {
        return value;
    }
    public String getTrueValue() {
        return trueValue;
    }

}

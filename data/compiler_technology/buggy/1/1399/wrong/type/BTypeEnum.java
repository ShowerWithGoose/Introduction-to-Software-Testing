package type;

public enum BTypeEnum {
    INT(LexType.INTTK, "int"),
    CHAR(LexType.CHARTK, "char");

    private final LexType type;
    private final String content;

    BTypeEnum(LexType type, String content) {
        this.type = type;
        this.content = content;
    }


    @Override
    public String toString() {
        return type.toString() + " " + content;
    }

    public LexType getType(){
        return type;
    }
}

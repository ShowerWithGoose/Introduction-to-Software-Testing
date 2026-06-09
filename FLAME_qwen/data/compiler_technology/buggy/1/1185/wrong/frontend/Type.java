package frontend;

public enum Type {
    MAINTK(false, "main"),
    CONSTTK(false, "const"),
    INTTK(false, "int"),
    CHARTK(false, "char"),
    BREAKTK(false, "break"),
    CONTINUETK(false, "continue"),
    IFTK(false, "if"),
    ELSETK(false, "else"),
    GETINTTK(false, "getint"),
    GETCHARTK(false, "getchar"),
    PRINTFTK(false, "printf"),
    RETURNTK(false, "return"),
    VOIDTK(false, "void"),
    FORTK(false, "for"),
    INTCON(true, "[0-9]+"),
    IDENFR(true, "[_A-Za-z][_A-Za-z0-9]*"),
    STRCON(true, "\\\"[^\\\"]*\\\""),
    CHRCON(true, "\\'((?:\\\\[abfntv\\\"'0]|[\\ -\\~]|[a-z]))*?\\'");

    private final String name;
    private final boolean whether;

    Type(boolean whether, String string) {
        this.name = string;
        this.whether = whether;
    }

    public String getName() {
        return name;
    }

    public boolean getWhether() {
        return whether;
    }


}



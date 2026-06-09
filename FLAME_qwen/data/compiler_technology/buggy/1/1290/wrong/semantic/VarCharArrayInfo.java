package semantic;

import ast.AddExp;

import java.util.ArrayList;

public class VarCharArrayInfo extends Info {

    private final ArrayList<AddExp> chars;

    private final String value;

    private final AddExp size;

    public VarCharArrayInfo(String ident, ArrayList<AddExp> chars, AddExp size) {
        super(ident);
        this.chars = chars;
        this.value = null;
        this.size = size;
    }

    public VarCharArrayInfo(String ident, String str, AddExp size) {
        super(ident);
        chars = null;
        value = str;
        this.size = size;
    }

    public VarCharArrayInfo(String ident) {
        super(ident);
        chars = null;
        value = null;
        size = null;
    }

    public ArrayList<AddExp> getChars() {
        return chars;
    }

    public String getValue() {
        return value;
    }

    public AddExp getSize() {
        return size;
    }

    @Override
    public String toString() {
        return "CharArray";
    }
}

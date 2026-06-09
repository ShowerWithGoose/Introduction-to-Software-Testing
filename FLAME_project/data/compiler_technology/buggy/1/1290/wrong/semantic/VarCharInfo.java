package semantic;

import ast.AddExp;

public class VarCharInfo extends Info {

    private final AddExp value;

    public VarCharInfo(String ident, AddExp value) {
        super(ident);
        this.value = value;
    }

    public VarCharInfo(String ident) {
        super(ident);
        this.value = null;
    }

    public AddExp getValue() {
        return value;
    }

    @Override
    public String toString() {
        return "Char";
    }
}

package semantic;

import ast.AddExp;

public class VarIntInfo extends Info {

    private final AddExp value;

    public VarIntInfo(String ident, AddExp value) {
        super(ident);
        this.value = value;
    }

    public AddExp getValue() {
        return value;
    }

    @Override
    public String toString() {
        return "Int";
    }
}

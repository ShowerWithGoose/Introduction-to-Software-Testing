package semantic;

import ast.AddExp;

public class ConstIntInfo extends ConstInfo {

    private final AddExp value;

    public ConstIntInfo(String ident, AddExp value) {
        super(ident);
        this.value = value;
    }

    public AddExp getValue() {
        return value;
    }

    @Override
    public String toString() {
        return "ConstInt";
    }
}

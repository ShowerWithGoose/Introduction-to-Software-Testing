package semantic;

import ast.AddExp;

public class ConstCharInfo extends ConstInfo {

    private final AddExp value;

    public ConstCharInfo(String ident, AddExp value) {
        super(ident);
        this.value = value;
    }

    public AddExp getValue() {
        return value;
    }

    @Override
    public String toString() {
        return "ConstChar";
    }
}

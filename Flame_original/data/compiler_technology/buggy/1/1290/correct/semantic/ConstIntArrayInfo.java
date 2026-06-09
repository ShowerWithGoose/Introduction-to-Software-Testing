package semantic;

import ast.AddExp;

import java.util.ArrayList;

public class ConstIntArrayInfo extends ConstInfo {

    private final ArrayList<AddExp> list;

    private final AddExp size;

    public ConstIntArrayInfo(String ident, ArrayList<AddExp> list, AddExp size) {
        super(ident);
        this.list = list;
        this.size = size;
    }

    public ArrayList<AddExp> getList() {
        return list;
    }

    public AddExp getSize() {
        return size;
    }

    @Override
    public String toString() {
        return "ConstIntArray";
    }
}

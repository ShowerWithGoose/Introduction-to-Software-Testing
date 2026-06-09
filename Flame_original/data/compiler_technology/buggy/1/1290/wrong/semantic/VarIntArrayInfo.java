package semantic;

import ast.AddExp;

import java.util.ArrayList;

public class VarIntArrayInfo extends Info {

    private final ArrayList<AddExp> list;

    private final AddExp size;

    public VarIntArrayInfo(String ident, ArrayList<AddExp> list, AddExp size) {
        super(ident);
        this.list = list;
        this.size = size;
    }

    public VarIntArrayInfo(String ident) {
        super(ident);
        this.list = null;
        this.size = null;
    }

    public ArrayList<AddExp> getList() {
        return list;
    }

    public AddExp getSize() {
        return size;
    }

    @Override
    public String toString() {
        return "IntArray";
    }

}


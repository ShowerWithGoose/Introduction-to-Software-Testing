package frontend;

import java.util.ArrayList;

public class FuncInfo {
    private ArrayList<String> types;

    public FuncInfo() {
        this.types = new ArrayList<>();
    }

    public void addType(String type) {
        this.types.add(type);
    }

    public int getParaSize() {
        return this.types.size();
    }

    public ArrayList<String> getTypes() {
        return this.types;
    }
}

package frontend;

import java.util.ArrayList;

public class Symbol_FuncFParams {
    private ArrayList<String> paramTypes;

    public Symbol_FuncFParams() {
        this.paramTypes = new ArrayList<>();
    }

    public void addParamType(String paramType) {
        this.paramTypes.add(paramType);
    }

    public ArrayList<String> getParamTypes() {
        return paramTypes;
    }
}

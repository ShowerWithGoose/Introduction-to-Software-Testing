package frontend;

public class FuncInfo {
    private String name;
    private int paramNum;
    private String returnType;

    public FuncInfo(String name, int paramNum, String returnType) {
        this.name = name;
        this.paramNum = paramNum;
        this.returnType = returnType;
    }

    public int getParamNum() {
        return this.paramNum;
    }
}

package frontend.SymbolPackage;

import java.util.ArrayList;

public class FuncSymbol extends Symbol{
    private int tableId;
    private String returnFuncType;//void, int, char
    private int next_tableId;//函数定义的中Block对应符号表的编号
    private ArrayList<FuncParam> funcParams;

    public FuncSymbol(int tableId, int next_tableId, String returnFuncType) {
        this.tableId = tableId;
        this.next_tableId = next_tableId;
        this.returnFuncType = returnFuncType;
        this.funcParams = new ArrayList<>();
    }

    @Override
    public void setName(String name) {
        super.setName(name);
    }

    public String getReturnFuncType() {
        return returnFuncType;
    }

    public void addParam(FuncParam funcParam) {
        this.funcParams.add(funcParam);
    }

    public ArrayList<FuncParam> getFuncParams() {
        return funcParams;
    }

    public int getNext_tableId() {
        return next_tableId;
    }

    public int getTableId() {
        return tableId;
    }
}

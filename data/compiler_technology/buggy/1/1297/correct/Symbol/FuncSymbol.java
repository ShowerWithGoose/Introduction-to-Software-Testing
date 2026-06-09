package Symbol;

import java.util.ArrayList;

public class FuncSymbol extends Symbol {
    private ArrayList<ValueType> params = new ArrayList<>();
    // private ValueType returnType = null;
    private int returnLine = 0;

    public FuncSymbol(String name, ValueType type, int dim, int line) {
        super(name, type, dim);
        if (SymbolManager.hasNameInSameDim(name)) {
            SymbolManager.err += line + " b\n";
        }
        SymbolManager.ans += this.toString();
    }

    public void addParam(ValueType param) {
        params.add(param);
    }

    public void setReturnType(ValueType returnType,int line) {
        if (this.getType() == ValueType.VOID && returnType != ValueType.VOID) {
            SymbolManager.err += line + " f\n";
        }
        // if (returnType != this.getType()) {
        //     SymbolManager.err += line + " e\n";
        // }
        this.returnLine = line;
    }

    public void checkReturn(int line) {
        if (returnLine != line - 1  && this.getType() != ValueType.VOID) {
            SymbolManager.err += line + " g\n";
        }
    }

    public ArrayList<ValueType> getParams() {
        return params;
    }

    public String toString() {
        return super.getDim() + " " + getName() + " " + getType().toString() + "Func"+"\n";
    }

}

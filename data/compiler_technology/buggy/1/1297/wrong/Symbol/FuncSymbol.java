package Symbol;

import java.util.ArrayList;

public class FuncSymbol extends Symbol {
    private ArrayList<ValueType> params = new ArrayList<>();
    private ValueType returnType = null;

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
        if (this.returnType != null) {
            System.out.println("Return type has been set\n");
            return;
        }
        if (this.getType() == ValueType.VOID) {
            SymbolManager.err += line + " f\n";
            return;
        }
        if (returnType != this.getType()) {
            SymbolManager.err += line + " e\n";
        }
        this.returnType = returnType;
    }

    public void checkReturn(int line) {
        if (this.getType() != ValueType.VOID && this.returnType == null) {
            SymbolManager.err += line + " g\n";
        }
    }


}

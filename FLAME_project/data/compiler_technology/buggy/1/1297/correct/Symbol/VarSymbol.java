package Symbol;

public class VarSymbol extends Symbol{

    // public VarSymbol(String name, ValueType type, int dim,int line) {
    //     super(name, type, dim);
    //     if (SymbolManager.hasNameInSameDim(name))
    //     {
    //         SymbolManager.err += line + " b\n";
    //     }
    //     SymbolManager.ans += this.toString();
    // }

    public VarSymbol(String name, ValueType type, int dim, int line) {
        super(name, type, dim);
        if (SymbolManager.hasNameInSameDim(name))
        {
            SymbolManager.err += line + " b\n";
        }
        SymbolManager.ans += this.toString();
    }

    public String toString() {
        return super.getDim() + " " + getName() + " " + getType().toString()+"\n";
    }
}

package Symbol;

public class ConstSymbol extends Symbol{


    public ConstSymbol(String name, ValueType type, int dim,int line) {
        super(name, type, dim);
        if (SymbolManager.hasNameInSameDim(name))
        {
            SymbolManager.err += line + " b\n";
        }
        SymbolManager.ans += this.toString();
    }
}

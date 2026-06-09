package llvm_part.values;

import llvm_part.IrType;
import llvm_part.IrValue;
import symbol_part.Symbol;

public class IrGlobalDecl implements IrValue {
    private Symbol symbol;
    private IrType type;
    private boolean isConst;

    public IrGlobalDecl(Symbol symbol, IrType type, boolean isConst) {
        this.symbol = symbol;
        this.type = type;
        this.isConst = isConst;
    }

    @Override
    public String toString() {
        String global = isConst ? "constant" : "global";
        StringBuilder sb = new StringBuilder(symbol.toString() + " = " + global + " " + type);
        return sb.toString();
    }
}

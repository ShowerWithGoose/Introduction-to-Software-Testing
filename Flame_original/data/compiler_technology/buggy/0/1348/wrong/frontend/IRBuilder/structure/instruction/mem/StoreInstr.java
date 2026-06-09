package frontend.IRBuilder.structure.instruction.mem;

import frontend.IRBuilder.structure.Symbol;
import frontend.IRBuilder.structure.Value;

public class StoreInstr extends MemInstr{
    private Value storeLeft;
    private Value storeRight;
    public StoreInstr(Value storeLeft, Symbol symbol) {
        super(symbol);
        this.storeLeft = storeLeft;
        this.storeRight = symbol.allocValue;
        setUse(storeLeft);
        setUse(storeRight);
    }

    public StoreInstr(Value storeLeft, Value storeRight, Symbol symbol) {
        super(symbol);
        this.storeLeft = storeLeft;
        this.storeRight = storeRight;
        setUse(storeLeft);
        setUse(storeRight);
    }
}

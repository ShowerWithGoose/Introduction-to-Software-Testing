package frontend.IRBuilder.structure.instruction.mem;

import frontend.IRBuilder.structure.Symbol;
import type.PointerType;

public class AllocInstr extends MemInstr {
    private int index;

    public AllocInstr(int index, Symbol symbol) {
        super(symbol);
        this.index = index;
        symbol.allocValue = this;
        this.type = new PointerType(symbol.type);
    }
}

package frontend.IRBuilder.structure.instruction.mem;

import frontend.IRBuilder.structure.Symbol;
import frontend.IRBuilder.structure.Value;
import type.PointerType;

public class LoadInstr extends MemInstr {
    private final int res;
    private Value ptr;

    public LoadInstr(int res, Symbol symbol) {
        super(symbol);
        this.res = res;
        this.ptr = symbol.allocValue;
        setUse(symbol.allocValue);
        if (!(symbol.type instanceof PointerType)) {
            throw new RuntimeException("load的源对象一定是地址");
        }
        this.type = ((PointerType) symbol.type).eleType;
    }
}

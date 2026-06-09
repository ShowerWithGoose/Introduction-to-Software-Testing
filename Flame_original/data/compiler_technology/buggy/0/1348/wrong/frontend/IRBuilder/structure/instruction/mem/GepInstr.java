package frontend.IRBuilder.structure.instruction.mem;

import frontend.IRBuilder.structure.Symbol;
import frontend.IRBuilder.structure.Value;
import type.BasicType;

public class GepInstr extends MemInstr{
    private final int res;
    private final Value index;
    private final Value ptr;//指针基质
    private final BasicType arrayType;
    public GepInstr(int res, Value index, Symbol symbol) {
        super(symbol);
        this.res = res;
        this.index = index;
        this.ptr = symbol.allocValue;
        this.arrayType = symbol.type;
    }
}

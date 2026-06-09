package frontend.IRBuilder.structure.instruction.mem;

import frontend.IRBuilder.structure.Symbol;
import frontend.IRBuilder.structure.instruction.Instruction;

public class MemInstr extends Instruction {
    private Symbol symbol;
    public MemInstr(Symbol symbol) {
        this.symbol = symbol;
    }
}

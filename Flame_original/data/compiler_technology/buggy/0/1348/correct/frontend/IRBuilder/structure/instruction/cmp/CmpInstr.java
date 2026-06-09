package frontend.IRBuilder.structure.instruction.cmp;

import frontend.IRBuilder.structure.Value;
import frontend.IRBuilder.structure.instruction.Instruction;
import type.BasicType;
import type.BoolType;
import type.CmpCondType;

public class CmpInstr extends Instruction {
    public final int res;
    public final CmpCondType cond;
    public final Value value1;
    public final Value value2;
    public CmpInstr(int res, CmpCondType cond, Value value1, Value value2) {
        this.res = res;
        this.cond = cond;
        this.value1 = value1;
        this.value2 = value2;
        setUse(value1);
        setUse(value2);
    }

    public BasicType getDataType() {
        return new BoolType();
    }
}

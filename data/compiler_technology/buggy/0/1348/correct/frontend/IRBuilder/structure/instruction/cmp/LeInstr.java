package frontend.IRBuilder.structure.instruction.cmp;

import frontend.IRBuilder.structure.Value;
import type.CmpCondType;

public class LeInstr extends CmpInstr {
    public LeInstr(Value value1, Value value2, int res) {
        super(res, CmpCondType.LE, value1, value2);
    }
}

package frontend.IRBuilder.structure.instruction.cmp;

import frontend.IRBuilder.structure.Value;
import type.CmpCondType;

public class LtInstr extends CmpInstr {
    public LtInstr(Value value1, Value value2, int res) {
        super(res, CmpCondType.LT, value1, value2);
    }
}

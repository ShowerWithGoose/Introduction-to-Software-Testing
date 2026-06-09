package frontend.IRBuilder.structure.instruction.cmp;

import frontend.IRBuilder.structure.Value;
import type.CmpCondType;

public class GtInstr extends CmpInstr {
    public GtInstr(Value value1, Value value2, int res) {
        super(res, CmpCondType.GT, value1, value2);
    }
}

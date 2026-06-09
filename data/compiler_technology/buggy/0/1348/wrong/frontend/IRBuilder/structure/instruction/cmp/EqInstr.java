package frontend.IRBuilder.structure.instruction.cmp;

import frontend.IRBuilder.structure.Value;
import type.CmpCondType;

public class EqInstr extends CmpInstr {
    public EqInstr(Value value1, Value value2, int res) {
        super(res, CmpCondType.EQ, value1, value2);
    }
}

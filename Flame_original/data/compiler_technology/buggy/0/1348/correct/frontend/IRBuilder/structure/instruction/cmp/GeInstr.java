package frontend.IRBuilder.structure.instruction.cmp;

import frontend.IRBuilder.structure.Value;
import type.CmpCondType;

public class GeInstr extends CmpInstr {
    public GeInstr(Value value1, Value value2, int res) {
        super(res, CmpCondType.GE, value1, value2);
    }
}

package frontend.IRBuilder.structure.instruction.cmp;

import frontend.IRBuilder.structure.Value;
import type.CmpCondType;

public class NeInstr extends CmpInstr {
    public NeInstr(Value value1, Value value2, int res) {
        super(res, CmpCondType.NE, value1, value2);
    }
}

package frontend.IRBuilder.structure.instruction.binary;

import frontend.IRBuilder.structure.Value;
import type.IntType;

public class SubInstr extends BinaryInstr {
    public SubInstr(Value op1, Value op2, int res) {
        super(res, op1, op2, "sub");
    }
}

package frontend.IRBuilder.structure.instruction.binary;

import frontend.IRBuilder.structure.Value;

public class ShrInstr extends BinaryInstr{
    public ShrInstr(Value op1, Value op2, int res) {
        super(res, op1, op2, "shr");
    }
}

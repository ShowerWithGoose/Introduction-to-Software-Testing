package frontend.IRBuilder.structure.instruction.binary;

import frontend.IRBuilder.structure.Value;

public class DivInstr extends BinaryInstr{
    public DivInstr(Value op1, Value op2, int res) {
        super(res, op1, op2, "div");
    }
}

package frontend.IRBuilder.structure.instruction.binary;

import frontend.IRBuilder.structure.Value;

public class AndInstr extends BinaryInstr{

    public AndInstr(int result, Value value1, Value value2) {
        super(result, value1, value2, "and");
    }
}

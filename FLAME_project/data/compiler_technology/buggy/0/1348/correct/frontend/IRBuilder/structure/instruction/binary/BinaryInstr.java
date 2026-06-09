package frontend.IRBuilder.structure.instruction.binary;

import frontend.IRBuilder.structure.Value;
import frontend.IRBuilder.structure.instruction.Instruction;
import type.BasicType;

public class BinaryInstr extends Instruction {
    private final int result;
    public Value value1;
    public Value value2;
    private final String op;

    public BinaryInstr(int result, Value value1, Value value2, String op) {
        this.result = result;
        this.value1 = value1;
        this.value2 = value2;
        this.op = op;
        setUse(value1);
        setUse(value2);
    }
}

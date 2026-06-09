package frontend.IRBuilder.structure.instruction.otherInstr;

import frontend.IRBuilder.structure.Function;
import frontend.IRBuilder.structure.Value;
import frontend.IRBuilder.structure.instruction.Instruction;
import frontend.syntax.Ast;
import type.BasicType;
import type.CharType;
import type.IntType;
import type.PointerType;

import java.util.ArrayList;
import java.util.List;

public class CallInstr extends Instruction {
    private final int result;
    private final List<Value> paramList;
    private final Function function;

    public CallInstr(int result, Function function, List<Value> paramList) {
        this.result = result;
        this.paramList = paramList;
        this.function = function;
        for (Value param : paramList) {
            setUse(param);
        }
    }
}

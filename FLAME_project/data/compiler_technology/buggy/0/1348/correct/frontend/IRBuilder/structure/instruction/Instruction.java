package frontend.IRBuilder.structure.instruction;

import frontend.IRBuilder.structure.BasicBlock;
import frontend.IRBuilder.structure.Use;
import frontend.IRBuilder.structure.Value;
import frontend.IRBuilder.structure.instruction.binary.*;
import frontend.IRBuilder.structure.instruction.cmp.*;
import frontend.syntax.Ast;
import type.BasicType;
import type.IntType;
import type.PointerType;

import java.util.ArrayList;

public class Instruction extends Value {
    private BasicBlock parent;
    private ArrayList<Use> useeList;

    public void setParent(BasicBlock parent) {
        this.parent = parent;
    }

    public void setUse(Value value) {
        Use use = new Use(this, value);
        value.userList.addToTail(use);
        useeList.add(use);
    }

    public static Instruction buildInstruction(Value firstValue, Value secondValue, String op, int regIndex) {
        return switch (op) {
            case "+" -> new AddInstr(firstValue, secondValue, regIndex);
            case "-" -> new SubInstr(firstValue, secondValue, regIndex);
            case "*" -> new MulInstr(firstValue, secondValue, regIndex);
            case "/" -> new DivInstr(firstValue, secondValue, regIndex);
            case "%" -> new RemInstr(firstValue, secondValue, regIndex);
            case "==" -> new EqInstr(firstValue, secondValue, regIndex);
            case "!=" -> new NeInstr(firstValue, secondValue, regIndex);
            case "<" -> new LtInstr(firstValue, secondValue, regIndex);
            case ">" -> new GtInstr(firstValue, secondValue, regIndex);
            case "<=" -> new LeInstr(firstValue, secondValue, regIndex);
            case ">=" -> new GeInstr(firstValue, secondValue, regIndex);
            default -> throw new RuntimeException("Invalid operation");
        };
    }
}

package frontend.IRBuilder.structure;

import frontend.IRBuilder.structure.instruction.end.JumpInstr;
import utils.CustomList;
import frontend.IRBuilder.structure.instruction.Instruction;
import frontend.IRBuilder.structure.instruction.end.BranchInstr;
import frontend.IRBuilder.structure.instruction.end.ReturnInstr;

import java.util.HashSet;

public class BasicBlock extends Value {
    private CustomList instrList = new CustomList(this);
    public HashSet<BasicBlock> pres = new HashSet<>();
    public HashSet<BasicBlock> sucs = new HashSet<>();
    private int index;
    private boolean hasEnded = false;

    public BasicBlock(int index) {
        this.index = index;
    }

    public void addInstr(Instruction instr) {
        instrList.addToTail(instr);
        instr.setParent(this);
        if (hasEnded) {
            instr.removeFromList();
        } else if (instr instanceof ReturnInstr) {
            hasEnded = true;
        } else if (instr instanceof BranchInstr) {
            hasEnded = true;
            ((BranchInstr) instr).addRelation(this);
        }else if(instr instanceof JumpInstr){
            hasEnded = true;
            ((JumpInstr) instr).addRelation(this);
        }
    }
}

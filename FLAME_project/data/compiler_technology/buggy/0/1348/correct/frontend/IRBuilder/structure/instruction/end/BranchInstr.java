package frontend.IRBuilder.structure.instruction.end;

import frontend.IRBuilder.structure.BasicBlock;
import frontend.IRBuilder.structure.Value;

public class BranchInstr extends EndInstr {
    private BasicBlock trueBranch;
    private BasicBlock falseBranch;
    private Value condition;

    public BranchInstr(Value condition, BasicBlock trueBranch, BasicBlock falseBranch) {
        this.condition = condition;
        this.trueBranch = trueBranch;
        this.falseBranch = falseBranch;
        setUse(trueBranch);
        setUse(falseBranch);
        setUse(condition);
    }

    public void addRelation(BasicBlock parent) {
        //建立块与块之间的前驱后继关系
        trueBranch.pres.add(parent);
        parent.sucs.add(trueBranch);
        falseBranch.pres.add(parent);
        parent.sucs.add(falseBranch);
    }
}

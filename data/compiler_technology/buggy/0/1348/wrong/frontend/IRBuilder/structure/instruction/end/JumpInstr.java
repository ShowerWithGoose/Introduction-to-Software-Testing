package frontend.IRBuilder.structure.instruction.end;

import frontend.IRBuilder.structure.BasicBlock;

public class JumpInstr extends EndInstr{
    private BasicBlock target;
    public JumpInstr(BasicBlock target) {
        this.target = target;
        setUse(target);
    }

    public void addRelation(BasicBlock parent) {
        //建立块与块之间的前驱后继关系
        target.pres.add(parent);
        parent.sucs.add(target);
    }
}

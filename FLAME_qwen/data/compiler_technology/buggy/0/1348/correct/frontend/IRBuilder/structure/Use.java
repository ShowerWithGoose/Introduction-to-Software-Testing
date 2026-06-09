package frontend.IRBuilder.structure;

import frontend.IRBuilder.structure.instruction.Instruction;
import utils.CustomList;

public class Use extends CustomList.Node {
    private Instruction user;
    private Value usee;
    //TODO:看看这里的super构造方法
    public Use(Instruction user, Value usee) {
        this.user = user;
        this.usee = usee;
    }

}

package frontend.IRBuilder.structure;

import type.BasicType;

public class IRParam extends Value{
    private final int index;
    private final BasicType type;
    public IRParam(int index, BasicType type){
        this.index = index;
        this.type = type;
    }

}

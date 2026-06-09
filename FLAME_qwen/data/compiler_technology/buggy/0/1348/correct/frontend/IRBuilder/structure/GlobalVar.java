package frontend.IRBuilder.structure;

import type.BasicType;

public class GlobalVar extends Value{
    public String name;
    public BasicType type;
    public GlobalVar(String name, BasicType type){
        this.name = name;
        this.type = type;
    }

}

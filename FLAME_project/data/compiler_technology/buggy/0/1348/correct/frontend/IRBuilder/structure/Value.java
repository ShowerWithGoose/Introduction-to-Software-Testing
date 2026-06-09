package frontend.IRBuilder.structure;

import type.BasicType;
import utils.CustomList;

public class Value extends CustomList.Node {
    public CustomList userList = new CustomList(this);
    public BasicType type;

}

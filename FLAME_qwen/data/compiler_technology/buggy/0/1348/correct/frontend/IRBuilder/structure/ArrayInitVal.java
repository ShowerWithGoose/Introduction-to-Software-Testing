package frontend.IRBuilder.structure;

import type.BasicType;
import type.IntType;

import java.util.ArrayList;

public class ArrayInitVal extends Value {
    public BasicType type;
    //-1表示数组传参，没有index
    public int size;
    public ArrayList<Value> initValueList;
    private boolean isInit;

    public ArrayInitVal(BasicType type, int size, boolean isInit) {
        this.type = type;
        this.size = size;
        this.isInit = isInit;
    }

    public Value getValueThroughIndex(int index) {
        //TODO:对于第一维是0的情况，下面做的合理吗
        //缺省值
        if (index >= initValueList.size()) {
            if (type instanceof IntType) {
                return new ConstInt(0);
            } else {
                return new ConstChar(0);
            }
        }
        return initValueList.get(index);
    }

    public ArrayList<Integer> getNoneZeroIndex() {
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < initValueList.size(); i++) {
            if (initValueList.get(i) instanceof ConstInt) {
                if (((ConstInt) initValueList.get(i)).value != 0) {
                    res.add(i);
                }
            } else if (initValueList.get(i) instanceof ConstChar) {
                if (((ConstChar) initValueList.get(i)).value != 0) {
                    res.add(i);
                }
            }
        }
        return res;
    }
}

package llvm_part.values.elements;

import java.util.ArrayList;
import java.util.Objects;

public class IrGlobalInit {
    private int array;
    private ArrayList<Objects> initValues;

    public IrGlobalInit(int array, ArrayList<Objects> initValues) {
        this.array = array;
        this.initValues = initValues;
    }

    @Override
    public String toString() {
        if (array == 0){
            return initValues.get(0).toString();
        }
        // 一维数组
        else {
            return null;
        }
    }
}

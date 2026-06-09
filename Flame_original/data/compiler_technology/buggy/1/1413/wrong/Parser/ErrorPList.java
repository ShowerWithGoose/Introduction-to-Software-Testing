package Parser;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/15
 */
public class ErrorPList {
    private static ErrorPList instance;

    // 创建一个 ArrayList
    private ArrayList<ErrorP> errors;
    private ErrorPList(){
        errors=new ArrayList<>();
    }
    public static ErrorPList getInstance() {
        if (instance == null) { // 检查是否已经创建实例
            instance = new ErrorPList();
        }
        return instance;
    }
    public void addErrorP(ErrorP errorP){
        errors.add(errorP);
    }
    public ArrayList<ErrorP> getErrors(){
        return errors;
    }

    public void clearErrors() {
        errors.clear();;
    }
}

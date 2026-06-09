package error;

import java.util.ArrayList;
import java.util.Comparator;

/**
 * @author
 * @Description:
 * @date 2024/10/12 21:52
 */
public class errorList {
    private static final errorList instance=new errorList();
    public  ArrayList<error> errors=new ArrayList<error>();
    public static errorList getList(){
        return instance;
    }
    public void addError(error error){
        this.errors.add(error);

    }
}

package error;

import java.util.ArrayList;
import java.util.List;

/**
 * ClassName: Error
 * Package: error
 * Description:
 *
 * @Author
 * @Create 2024/9/23 19:35
 * @Version 1.0
 */
public class Error {
    public int lineNo;
    public ErrorType type;
    public int thisLineTokenNo; // the columnNo-th token
    public int thisLineCharNo; // the first char of error token

    public Error(){

    }

    public Error(int lineNo, ErrorType type, int thisLineTokenNo, int thisLineCharNo) {
        this.lineNo = lineNo;
        this.type = type;
        this.thisLineTokenNo = thisLineTokenNo;
        this.thisLineCharNo = thisLineCharNo;
    }

    public Error(int lineNo, ErrorType type, int thisLineTokenNo){
        this.lineNo = lineNo;
        this.type = type;
        this.thisLineTokenNo = thisLineTokenNo;
    }

    public Error(int lineNo, ErrorType type){
        this.lineNo = lineNo;
        this.type = type;
    }

    public static List<Error> errors = new ArrayList<>();

    public static boolean isExist(int lineNo, ErrorType type){
        for(Error error : errors){
            if(error.lineNo == lineNo && error.type == type){
                return true;
            }
        }
        return false;

    }
}

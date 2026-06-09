package error;

import utils.IO;

import java.util.ArrayList;

/**
 * @Description 单例模式 错误处理
 * @Author
 * @Date 2024/9/19
 */
public class ErrorHandler {
    private ArrayList<Error> errors;    //美丽的错误

    public ErrorHandler() {
        errors = new ArrayList<>();
    }

    //单例模式
    private static final ErrorHandler instance = new ErrorHandler();
    public static ErrorHandler getInstance(){
        return instance;
    }

    public static void addError(Error error){
        if(!instance.errors.contains(error)){
            instance.errors.add(error);
        }
    }
    public static boolean hasError(){
        return !instance.errors.isEmpty();
    }

    public static String getOutputString(){
        instance.errors.sort((o1, o2) -> {
            if(o1.getLineNum() ==  o2.getLineNum()){
                return o1.getType().toString().compareTo(o2.getType().toString());
            }
            return o1.getLineNum() - o2.getLineNum();
        });
        StringBuilder stringBuilder = new StringBuilder();
        for(Error error : getInstance().errors){
            stringBuilder.append(error.getOutputString());
        }
        return stringBuilder.toString();
    }

    public static void printErrors(){
        IO.write(IO.IOType.CHECKER, getOutputString(), false, false);
    }
}

package frontend;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

public class Errorlog {
    // 用于存储错误报告的List
    public static List<String> errors = new ArrayList<>();
    public static String ErrorFile = "error.txt";

    // 将错误添加到List的方法
    public void AddError(int lineNum,char ErrorType){
        String tmp = String.valueOf(lineNum) + " " + String.valueOf(ErrorType) + "\n";
        errors.add(tmp);
    }

    // 打印错误报告的方法
    public static void WriteError2File(){
        try(BufferedWriter bw = new BufferedWriter(new FileWriter(ErrorFile,true))) {
            for(String error : errors){
                bw.write(error);
            }
        } catch (Exception e){
            System.err.println("could not open + " + ErrorFile);
        }
    }
}

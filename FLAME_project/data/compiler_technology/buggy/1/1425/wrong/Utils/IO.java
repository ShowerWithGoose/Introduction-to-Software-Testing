package Utils;/**
 * @Description:
 * @author
 * @date 2024/9/23 16:29
 */

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import Config.Config;

/**
 * @author:
 * TODO  
 * 2024/9/23 16:29
 */
public class IO {
    public static void writeToFile(String content,String filePath){
        try(BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(filePath,true))) {
            bufferedWriter.write(content);
            bufferedWriter.close();
        }catch (Exception e) {
            e.printStackTrace();
        }

    }

//    Lexer
    public static void lexer_output(String content){
        writeToFile(content,Config.fileOutput);
    }
    public static void lexer_error(String content){
        writeToFile(content,Config.fileError);
    }

//    Parser
    public static void parser_output(String content){
    writeToFile(content,Config.fileOutput);
}
    public static void parser_error(String content){
        writeToFile(content,Config.fileError);
    }
//    clear
    public static void clear_file(String filePath){
        File file=new File(filePath);
        if(file.exists()){
            file.delete();
        }
        writeToFile("",filePath);
    }


}

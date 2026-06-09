import frontend.Lexer;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String content = new String(Files.readAllBytes(Paths.get("testfile.txt")), StandardCharsets.UTF_8);
        int re = Lexer.lexer(content);
        if(re==0){
            String filePath = "lexer.txt";
            FileOutputStream fileOutputStream = new FileOutputStream(filePath);
            for(int i=0;i<Lexer.j;i++){
                byte[] bytes = (Lexer.type_code[i]+' '+Lexer.word[i]+'\n').getBytes();
                fileOutputStream.write(bytes);
            }
        }
        else if(re==1){
            String filePath = "error.txt";
            FileOutputStream fileOutputStream = new FileOutputStream(filePath);
            for(int i=0;i<Lexer.k;i++){
                String num = Integer.toString(Lexer.error_line[i]);
                byte[] bytes = (num+' '+Lexer.error_code[i]+'\n').getBytes();
                fileOutputStream.write(bytes);
            }
        }
    }
}

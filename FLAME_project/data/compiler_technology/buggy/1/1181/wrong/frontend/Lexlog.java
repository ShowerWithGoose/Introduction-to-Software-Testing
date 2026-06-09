package frontend;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

import static frontend.Lexer.tokens;
import static frontend.Lexer.Token;

public class Lexlog {
    public static String LexAnsFile = "lexer.txt";

    public static void WriteLexAns2File(){
        try(BufferedWriter bw = new BufferedWriter(new FileWriter(LexAnsFile))){
            for(Token token : tokens){
                bw.write(token.toString()); // 调用的改写的方法
            }
        } catch(IOException e){
            System.err.println("could not open + " + LexAnsFile);
        }
    }
}

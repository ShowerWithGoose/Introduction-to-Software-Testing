import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Compiler {
    public static boolean errorExists = false;

    static String sourceFilePath = "./testfile.txt";
    static String lexerOutputFilePath = "parser.txt";
    static String errorFilePath = "error.txt";

    public static void main(String[] args) {
        FileReader fileReader = null;
        BufferedReader bufferedReader = null;

        try{
            fileReader = new FileReader(sourceFilePath);
            bufferedReader = new BufferedReader(fileReader);
            Lexer.getInstance();
            Lexer.init(bufferedReader);
            while(Lexer.read()!=-1){
                Lexer.putToken();
            }
        } catch(FileNotFoundException e){
            e.printStackTrace();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        //Lexer.output(errorExists,lexerOutputFilePath,errorFilePath);
        Parser p = new Parser();
        Parser.output(errorExists,lexerOutputFilePath,errorFilePath);
    }
}
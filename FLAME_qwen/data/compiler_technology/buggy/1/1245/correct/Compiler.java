import java.io.*;
import java.util.Comparator;

public class Compiler {
    public static boolean errorExists = false;

    static String sourceFilePath = "./testfile.txt";
    static String lexerOutputFilePath = "lexer.txt";
    static String parserOutputFilePath = "parser.txt";
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
        Lexer.output(lexerOutputFilePath);
        Parser p = new Parser();
        Parser.output(parserOutputFilePath);

        //ErrorOutPut();
        if(errorExists){
            ErrorOutPut();
        }
    }

    private static void ErrorOutPut(){
        Lexer.errorTokens.sort(Comparator.comparingInt(e -> e.lineno));
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorFilePath))) {
            for (ErrorToken errorToken : Lexer.errorTokens) {
                writer.write( errorToken.toString(errorToken.lineno)+ ' ' + errorToken.type.getValue());
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
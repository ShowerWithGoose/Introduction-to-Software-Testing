import frontend.Lexer;
import frontend.Output;

import java.io.FileReader;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        String inputFileName = "testfile.txt";
        try(FileReader fileReader = new FileReader(inputFileName)){
            Lexer lexer=new Lexer(fileReader);
            if(lexer.hasErrors == false){
                Output output = new Output(lexer.tokenList);
            }
        } catch (IOException e){
            e.printStackTrace();
        }

    }
}
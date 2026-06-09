import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import frontend.*;

public class Compiler {
    public static void main(String [] args) throws FileNotFoundException {
        String fileName = "testfile.txt";
        Lexer lexer = new Lexer();
        try (FileReader fr = new FileReader(fileName)){
            lexer.analyzeByLine(fr);

            if(lexer.judgeRightFromWrong){
                Output output = new Output(lexer.tokenList);
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}

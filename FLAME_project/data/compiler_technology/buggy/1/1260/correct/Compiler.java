import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import frontend.*;
import frontend.Error;

public class Compiler {
    public static void main(String [] args) throws FileNotFoundException {
        String fileName = "testfile.txt";
        Lexer lexer = new Lexer();

        try (FileReader fr = new FileReader(fileName)){
            lexer.analyzeByLine(fr);
            Parser parser = new Parser(lexer);
            parser.parse();
            if(Error.errors.isEmpty()){
                parser.print();
            }else {
                try (FileWriter fw = new FileWriter("error.txt",true)){
                    Error.sortErrors();
                    for(Error error : Error.errors){
                        fw.write(error.getLineNum() + " " + error.getErrorType() + "\n");
                    }
                }catch (IOException e) {
                    e.printStackTrace();
                }

            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}

import java.io.FileNotFoundException;
//import frontend.*;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        IOStream.readFile();
        //IOStream.debug38();
        Lexer lexer = Lexer.getInstance();
        lexer.setInputStrings(IOStream.toInputStrings());
        IOStream.createOutput();
        IOStream.output();
    }
}

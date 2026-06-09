import frontend.Lexer;
import utils.IO;
import utils.IO.*;
import frontend.Lexer.*;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer.Lexical_Analyse(IO.read());
    }
}

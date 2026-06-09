import frontend.Lexer;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public class Compiler {
    public static void main(String[] arg) {
        Lexer.run();
    }
}
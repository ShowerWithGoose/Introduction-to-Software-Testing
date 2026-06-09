import mainSys.*;

import java.io.*;

public class Compiler {
    public static void main(String[] args) throws IOException {
        FileIO.read();
        Lexer.lex();
        FileIO.output();
    }
}

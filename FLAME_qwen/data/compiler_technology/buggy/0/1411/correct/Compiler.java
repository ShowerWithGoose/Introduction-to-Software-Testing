import frontend.Lexer;
import io.Read;
import io.Write;

import java.io.File;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String code = Read.read("./testfile.txt");
        Lexer.lexer().analyse(code);
        if (Lexer.lexer().noError()) {
            Write.write("./lexer.txt", Lexer.lexer().exportToken());
        }
        else {
            Write.write("./error.txt", Lexer.lexer().exportError());
        }

    }
}
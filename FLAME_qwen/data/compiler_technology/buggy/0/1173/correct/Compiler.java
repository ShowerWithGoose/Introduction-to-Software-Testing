import frontend.Lexer;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        Lexer lexer = Lexer.instance();
        while(lexer.havNext()){
            lexer.next();
        }
        try {
            lexer.printResult();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
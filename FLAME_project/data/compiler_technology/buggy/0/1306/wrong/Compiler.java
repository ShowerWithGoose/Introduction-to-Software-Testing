

import error.Error;
import frontend.Lexer;
import token.Token;

import java.io.IOException;
import java.util.List;
import myUtil.FileOperation;
public class Compiler {
    public static void main(String[] args) throws IOException {
        String path = "testfile.txt";
        String content = FileOperation.readFileToString(path);
        Lexer lexer = new Lexer();
        lexer.read(content.toString());
        List<Token> tokens = lexer.tokens;
        List<Error> errors = lexer.errors;
        if(errors.isEmpty()) {
            FileOperation.outputLexer(tokens);
        }else{
            FileOperation.outputError(errors);
        }
    }
}
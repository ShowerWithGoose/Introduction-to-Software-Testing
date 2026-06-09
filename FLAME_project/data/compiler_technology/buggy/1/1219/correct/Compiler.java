import CompileErrors.CompileErrorHandler;
import Datas.Token;
import Lexical.Lexer;
import Syntax.Parser;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PushbackReader;

/**
 * @author
 * @Description:
 * @date 2024/9/22 13:18
 */
public class Compiler {
    public static void main(String[] args) {
        try (
                PushbackReader reader = new PushbackReader(new FileReader("testfile.txt"));
                FileWriter lexWriter = new FileWriter("lexer.txt", false);
                FileWriter correctWriter = new FileWriter("parser.txt", false);
                FileWriter errorWriter = new FileWriter("error.txt", false)){
            CompileErrorHandler compileErrorHandler = CompileErrorHandler.getInstance();
            Lexer lexerInstance = Lexer.getInstance();
            lexerInstance.setReader(reader);
            lexerInstance.analyze();
            Token.outputLexicalResult(lexWriter);
//            if (compileErrorHandler.errors.isEmpty()) {
//                Token.outputLexicalResult(correctWriter);
//            } else {
//                compileErrorHandler.outputErrorMessage(errorWriter);
//            }

            Parser parserInstance = Parser.getInstance(lexerInstance.tokens);
            parserInstance.setWriter(correctWriter);
            parserInstance.analyze();
            if (!compileErrorHandler.errors.isEmpty()) {
                compileErrorHandler.outputErrorMessage(errorWriter);
            }

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}

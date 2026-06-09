import frontend.check.ErrorMap;
import frontend.lexer.Lexer;
import frontend.lexer.Token;
import frontend.parser.Parser;
import frontend.parser.cst.CSTNode;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {
        String inputName = "testfile.txt";
        String outputParserName = "parser.txt";
        String outputLexerName = "lexer.txt";
        String errorName = "error.txt";
        InputStream inputStream = null;
        OutputStream outputParserStream = null;
        OutputStream outputLexerStream = null;
        OutputStream errorStream = null;

        boolean ifPrint = true;
        try {
            inputStream = new FileInputStream(inputName);
            outputParserStream = new FileOutputStream(outputParserName);
            outputLexerStream = new FileOutputStream(outputLexerName);           
            errorStream = new FileOutputStream(errorName);
            ErrorMap errorMap = ErrorMap.getInstance();
            Lexer lexer = new Lexer(inputStream,errorMap);
            lexer.tokenize();
            List<Token> tokens = lexer.getTokens();
            Parser parser = new Parser((ArrayList<Token>) tokens,errorMap);
            CSTNode root = parser.parse();
            String display = parser.display();
            if (ifPrint) {
                if (errorMap.hasError()) {
                    parser.printParseLog(outputParserStream);
                    lexer.printTokens(outputLexerStream);
                    errorMap.printError(errorStream);
                } else {
                    parser.printParseLog(outputParserStream);
                    lexer.printTokens(outputLexerStream);
                }
            }
        } catch (IOException e) {
            System.out.println("Error!!");
        }


    }
}

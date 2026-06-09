import frontend.Lexer;
import frontend.Token;
import frontend.LexerException;

import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        try (BufferedReader inFile = new BufferedReader(new FileReader("testfile.txt"));
             FileOutputStream outFile = new FileOutputStream("lexer.txt");
            PrintStream out = new PrintStream(outFile)){

                String str;
                int line = 1;
                int annotationFlag = 0;
                Lexer lexer = new Lexer();
                while ((str = inFile.readLine()) != null) {
                    lexer.analyze(str, line, annotationFlag);
                    annotationFlag = lexer.getAnnotationFlag();
                    line++;
                }
                if(lexer.error() != 0){
                    for(LexerException lexerException: lexer.getLexerExceptionArrayList()){
                        out.println(lexerException);
                    }
                }
                else {
                    for (Token token : lexer.getTokens()) {
                        out.println(token);
                    }

                }

        }catch (IOException e){
            System.err.println(e);
        }
    }
}
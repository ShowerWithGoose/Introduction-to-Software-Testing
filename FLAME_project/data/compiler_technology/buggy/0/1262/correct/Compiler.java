import frontend.SourceLexer;
import frontend.TokenLexer;

import java.io.*;

public class Compiler{
        public static void main(String[] args) {
            String inputFileName = "testfile.txt";
            InputStream inputFileStream = null;
            try {
                inputFileStream = new FileInputStream(inputFileName);
            } catch (FileNotFoundException e) {
                System.out.println("Can not open " + inputFileName);
            }
            SourceLexer sourceLexer = new SourceLexer(inputFileStream);
            TokenLexer tokenLexer = new TokenLexer(sourceLexer);
            String outputFileName1 = "lexer.txt";
            String outputFileName2 = "error.txt";
                try (OutputStream outputStream1 = new FileOutputStream(outputFileName1)){
                    outputStream1.write(tokenLexer.getTokenList().toString().getBytes());
                } catch (IOException e) {
                    System.out.println("Can not write " + outputFileName1);
                }
                try (OutputStream outputStream2 = new FileOutputStream(outputFileName2)) {
                    outputStream2.write(tokenLexer.getErrorList().toErrorString().getBytes());
                } catch (IOException e) {
                    System.out.println("Can not write " + outputFileName2);
                }
        }
}

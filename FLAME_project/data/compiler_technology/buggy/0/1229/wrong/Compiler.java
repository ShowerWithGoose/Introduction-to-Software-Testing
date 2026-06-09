import frontend.lexer.TokenLexer;
import frontend.lexer.TokenList;

import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        String inputFileName = "testfile.txt";
        InputStream inputStream = null;
        try {
            inputStream = new FileInputStream(inputFileName);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        TokenLexer tokenLexer = new TokenLexer(inputStream);
        TokenList tokenList = tokenLexer.getTokenList();

        if (tokenList.getIsError()) {
            String outputFileName = "error.txt";
            //有error的情况
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName))) {
                writer.write(tokenList.getErrors().get(0).toString() + " a");
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            String outputFileName = "lexer.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName))) {
                writer.write(tokenList.toString());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        //System.out.println("Hello world!");
    }
}
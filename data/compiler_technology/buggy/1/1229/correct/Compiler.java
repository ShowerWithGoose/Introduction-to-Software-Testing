import frontend.lexer.TokenLexer;
import frontend.lexer.TokenList;
import frontend.parser.CompUnit;
import middle.error.ErrorTable;

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

        CompUnit compUnit = new CompUnit(tokenList);
        compUnit.parseCompUnit();



        if (ErrorTable.hasError()){
            String outputFileName = "error.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName))) {
                writer.write(ErrorTable.output());
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            String outputFileName = "parser.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName))) {
                writer.write(compUnit.syntaxOutput());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
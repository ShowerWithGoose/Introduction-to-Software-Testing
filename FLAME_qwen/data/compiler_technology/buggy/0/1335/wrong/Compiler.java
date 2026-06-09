import frontend.Error;
import frontend.Lexer;
import frontend.Token;

import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        String inputFileName = "testfile.txt";
        String lexerOutputFileName = "lexer.txt";
        String errorOutputFileName = "error.txt";

        try {
            BufferedReader reader = new BufferedReader(new FileReader(inputFileName));
            BufferedWriter lexerWriter = new BufferedWriter(new FileWriter(lexerOutputFileName));
            BufferedWriter errorWriter = new BufferedWriter(new FileWriter(errorOutputFileName));
            Lexer lexer = new Lexer();
            String line;
            int lineNumber = 1;

            while ((line = reader.readLine()) != null) {
                lexer.addLine(lineNumber,line);
                lineNumber++;
            }
            lexer.tokenize();
            if(!lexer.isHasError()) {
                for (Token token : lexer.getTokens()) {
                    lexerWriter.write(token.getType() + " " + token.getTokenString());
                    lexerWriter.newLine();
                }
            }  else {
                // 输出错误信息
                for (Error error : lexer.getErrorInformation()) {
                    errorWriter.write(error.getLineNumber() + " " + error.getErrorCode());
                    errorWriter.newLine();
                }
            }
            reader.close();
            lexerWriter.close();
            errorWriter.close();
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("IO Error: " + e.getMessage());
        }
    }
}

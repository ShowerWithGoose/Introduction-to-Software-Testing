import frontend.SrcReader;
import frontend.Lexer;


import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        String inputFileName = "testfile.txt";
        String outputFileName = "lexer.txt";
        String errorFileName = "error.txt";

        try (InputStream inputFileStream = new FileInputStream(inputFileName);
             OutputStream outputStream = new FileOutputStream(outputFileName);
             OutputStream errorStream = new FileOutputStream(errorFileName);) {

            SrcReader srcReader = new SrcReader(inputFileStream);
            Lexer lexer = new Lexer(srcReader);

            // 检查是否有错误
            if (!lexer.getErrorList().isEmpty()) {
                errorStream.write(lexer.getErrorList().getBytes());
            } else {
                outputStream.write(lexer.getTokenList().getBytes());
            }

        } catch (FileNotFoundException e) {
            System.err.println("Cannot open file: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("I/O error: " + e.getMessage());
        }
    }
}

import frontend.Lexer.*;

import java.io.*;


public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        String inputPath = "testfile.txt";
        String rightOutputPath = "lexer.txt";
        String wrongOuputPath = "error.txt";
        try (InputStream in = new BufferedInputStream(new FileInputStream(inputPath))) {
            Lexer lexer = new Lexer(in);
            lexer.printTokens(rightOutputPath,wrongOuputPath);
        } catch (FileNotFoundException e) {
            System.err.println("文件未找到: " + e.getMessage());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

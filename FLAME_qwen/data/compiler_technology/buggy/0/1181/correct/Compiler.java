import frontend.Lexer;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Compiler {
    public static String TestFile = "testfile.txt"; // 文件路径

    public static void main(String[] args) {
        //System.out.println("Current working directory: " + System.getProperty("user.dir"));
        try(BufferedReader br = new BufferedReader(new FileReader(TestFile))){
            Lexer lexer = new Lexer();
            lexer.Lexer(br);
        } catch (FileNotFoundException fnfe) {
            System.err.println("file not found : " + TestFile);
        } catch (IOException e) {
            System.err.println("IOException");
        }

    }
}

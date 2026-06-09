import Fronted.Lexer;

import java.io.*;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputFileStream = null;
        try {
            inputFileStream = new FileInputStream("testfile.txt");
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        Lexer lexer = new Lexer(inputFileStream);
        try {
            OutputStream outputStream = new FileOutputStream("lexer.txt");
            try {
                outputStream.write(lexer.getOutput().getBytes());
            } catch (IOException e) {
                throw new RuntimeException();
            }
        } catch (FileNotFoundException e) {
            throw new FileNotFoundException();
        }
        try {
            OutputStream outputStream = new FileOutputStream("error.txt");
            try {
                outputStream.write(lexer.getErrorOutput().getBytes());
            } catch (IOException e) {
                throw new RuntimeException();
            }
        } catch (FileNotFoundException e) {
            throw new FileNotFoundException();
        }
    }
}
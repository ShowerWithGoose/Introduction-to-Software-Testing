import error_part.Debug;
import error_part.ErrorList;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Compiler {
    public static void main(String[] args) {
        InputStream inputStream = null;
        Debug.status = true;
        try {
            inputStream = new FileInputStream("testfile.txt");
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        LineSplitter lineSplitter = new LineSplitter(inputStream);
        Lexer lexer = new Lexer(lineSplitter);
        String output = "lexer.txt";
        String s = lexer.toString();
        if (!ErrorList.isEmpty() && Debug.status){
            output = "error.txt";
            s = ErrorList.errorOutput();
        }
        try {
            OutputStream outputStream = new FileOutputStream(output);
            try {
                outputStream.write(s.getBytes());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}

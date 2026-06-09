import frontend.error.MyError;
import frontend.Lexer;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        String inputFile = "testfile.txt";
        FileInputStream fi = new FileInputStream(inputFile);
        BufferedInputStream b = new BufferedInputStream(fi);
        ArrayList<MyError> errorList = new ArrayList<>();


        String lexerPath = "lexer.txt";
        FileOutputStream lexerOS = new FileOutputStream(lexerPath);
        OutputStreamWriter lexerOW = new OutputStreamWriter(lexerOS, StandardCharsets.UTF_8);
        BufferedWriter lexerBW = new BufferedWriter(lexerOW);
        Lexer lexer = new Lexer(b, errorList, lexerBW);


        String errorPath = "error.txt";
        FileOutputStream errorOS = new FileOutputStream(errorPath);
        OutputStreamWriter errorOW = new OutputStreamWriter(errorOS, StandardCharsets.UTF_8);
        BufferedWriter errorBW = new BufferedWriter(errorOW);
        try {
            for (MyError error : errorList) {
                errorBW.append(String.valueOf(error)).append("\n");
            }
            errorBW.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
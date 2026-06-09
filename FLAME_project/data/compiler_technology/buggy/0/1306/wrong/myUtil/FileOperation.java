package myUtil;

import error.Error;
import token.Token;

import java.io.*;
import java.util.List;

public class FileOperation {
    public static String readFileToString(String path){
        StringBuilder content = new StringBuilder();

        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = br.readLine()) != null) {
                content.append(line).append(System.lineSeparator());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return content.toString();
    }
    public static void outputLexer(List<Token> tokens){
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("lexer.txt"));
            for (Token token : tokens) {
                bw.write(token.toString());
                bw.newLine();
            }
            bw.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public static void outputError(List<Error> errors){
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("error.txt"));
            for (Error error: errors) {
                bw.write(error.toString());
                bw.newLine();
            }
            bw.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

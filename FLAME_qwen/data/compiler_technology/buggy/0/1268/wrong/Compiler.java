import frontend.Error;
import frontend.ErrorList;
import frontend.Lexer;
import frontend.Token;

import java.io.*;
import java.util.ArrayList;

public class Compiler {

    public static void main(String[] args) {  //未考虑单引号
        ArrayList<String> lines = new ArrayList<>();

        // 读取 testfile.txt 文件
        try (BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lines.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        Lexer lexer = new Lexer();
        ArrayList<Token> tokenList = lexer.parse(lines);
        if (lexer.getCorrect()) {
            try (PrintWriter writer = new PrintWriter(new FileWriter("lexer.txt"))) {
                for (Token token : tokenList) {
                    //System.out.println(token.getType() + " " + token.getContent());
                    writer.println(token.getType() + " " + token.getContent());
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        else {
            try (PrintWriter writer = new PrintWriter(new FileWriter("error.txt"))) {
                for (Error error : ErrorList.getErrorList()) {
                    //System.out.println(error.getLineNumber() + " " + error.getErrorType());
                    writer.println(error.getLineNumber() + " " + error.getErrorType());
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
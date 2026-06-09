import error.Err;
import frontend.LexType;
import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Compiler {
    public static void main(String[] args) throws IOException {
        ArrayList<Err> errorList = new ArrayList<>();
        List<Token> tokens = new ArrayList<>();
        List<String> lines = new ArrayList<>();
        try {
            lines = Files.readAllLines(Paths.get("testfile.txt"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        Lexer lexer = new Lexer(lines);
        tokens = lexer.tokenize(errorList);

        /**************************************   输出部分    *****************************************/
        boolean flag = true;
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
            for (Err error : errorList) {
                flag = false;
                writer.write(error.getLineNum() + " " + error.getCode());
                writer.newLine();
            }
            System.out.println("Error written to file successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }

        if (flag) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter("lexer.txt"))) {
                for (Token token : tokens) {
                    if (token.getLexType() != LexType.NOTE) {
                        writer.write(token.getLexType() + " " + token.getName());
                        writer.newLine();
                    }
                }
                System.out.println("Tokens written to file successfully.");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}
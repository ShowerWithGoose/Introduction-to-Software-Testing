import frontend.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) {
        String filePath = "testfile.txt"; // 文件路径
        StringBuilder contentBuilder = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                contentBuilder.append(line).append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        String content = contentBuilder.toString();

        Lexer lexer = new Lexer(content);
        //System.out.println(content);
        lexer.run();

        ArrayList<Token> tokens = lexer.getTokens();
        for (Token token : tokens) {
            String outputFilePath = "lexer.txt";
            try (FileWriter fw = new FileWriter(outputFilePath, true)) { // true表示追加
                fw.write(token.getType() + " " + token.getName() + "\n");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
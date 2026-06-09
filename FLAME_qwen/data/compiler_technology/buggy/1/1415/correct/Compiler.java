import lexicalanalysis.ErrorInfo;
import lexicalanalysis.Lexical;
import lexicalanalysis.Token;
import syntacticanalysis.Syntactic;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) {
        String filePath = "testfile.txt"; // 文件路径
        StringBuilder contentBuilder = new StringBuilder();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                contentBuilder.append(line).append(System.lineSeparator());
            }
            String content = contentBuilder.toString();
            ArrayList<Token> words = new ArrayList<>();
            ErrorInfo errorInfo = new ErrorInfo();
            Lexical lexical = new Lexical(content, words, errorInfo);
            lexical.lexical_analysis();
            lexical.lexical_print();
            Syntactic syntactic = new Syntactic(words, errorInfo);
            syntactic.syntax_print();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

import fronted.Lexer.*;
import fronted.Lexer.Error;
import fronted.Parser.Parser;
import fronted.Parser.SyntaxTree.SyntaxNode;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * @author
 * @Description:
 * @date 2024/9/24 16:05
 */
public class Compiler {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"))) {
            StringBuilder sourceCode = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                sourceCode.append(line).append("\n");
            }

            Lexer lexer = new Lexer(sourceCode.toString());
            lexer.tokenize();
            List<Error> lexerErrors = lexer.getErrors();
            // lexer.output();

            Parser parser = new Parser(lexer.getTokens());
            parser.parse();
            List<Error> parserErrors = parser.getErrors();

            // Merge lexerErrors and parserErrors
            List<Error> allErrors = new ArrayList<>();
            allErrors.addAll(lexerErrors);
            allErrors.addAll(parserErrors);
            allErrors.sort(Comparator.comparingInt(e -> e.line));

            if (!allErrors.isEmpty()) {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
                    for (Error error : allErrors) {
                        writer.write(error.line + " " + error.code);
                        writer.newLine(); // Move to the next line
                    }
                }
            }else{
                parser.output();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

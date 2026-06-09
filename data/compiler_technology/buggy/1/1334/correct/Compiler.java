import java.io.*;

import frontend.*;

/**
 * @author
 * @Description
 * @date 2024/10/4 17:09
 */
public class Compiler {
    private static String fileContent;

    public static void main(String[] args) throws IOException {
        String filePath = "./testfile.txt";

        StringBuilder contentBuilder = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(new File(filePath).getCanonicalPath()))) {
            String line;
            while ((line = reader.readLine()) != null) {
                contentBuilder.append(line).append("\n");
            }
        }
        fileContent = contentBuilder.toString();

        Lexer testLexer = new Lexer(fileContent);
        testLexer.lexTestFile();

        Parser testParser = new Parser(testLexer.tokenList, testLexer.errorList);
        testParser.parseTestFile();
    }
}

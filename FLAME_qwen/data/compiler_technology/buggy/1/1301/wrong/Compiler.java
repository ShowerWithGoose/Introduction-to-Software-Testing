import error.ErrorHandling;
import frontend.lexer.Lexer;
import frontend.lexer.TokenList;
import frontend.parser.Parser;

import java.io.*;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String sourceFileName = "testfile.txt";
        String aimFileName = "parser.txt";

        InputStream sourceFileStream = null;
        try {
            sourceFileStream = new FileInputStream(sourceFileName);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        StringBuffer sb = new StringBuffer();
        BufferedReader reader = new BufferedReader(new InputStreamReader(sourceFileStream));
        try {
            String line = reader.readLine();
            while (line != null) {
                sb.append(line);
                sb.append("\n");
                line = reader.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        reader.close();
        sourceFileStream.close();
        String sourceFile = sb.toString();

        Lexer lexer = new Lexer(sourceFile);
        TokenList tokenList = lexer.getAllTokens();
        Parser parser = new Parser(tokenList);
        parser.parse();

        if (lexer.getErrorNum() == 0 && parser.getErrorNum() == 0) { //没有错误
            try {
                OutputStream aimFileStream = new FileOutputStream(aimFileName);
                try {
                    aimFileStream.write(parser.toSyntaxTree().getBytes());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        } else {
            ErrorHandling.output();
        }
    }
}

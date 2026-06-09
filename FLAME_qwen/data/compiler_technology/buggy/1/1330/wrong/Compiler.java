import java.io.*;
import java.util.Collections;
import java.util.List;

public class Compiler {

    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"));
            StringBuilder buffer = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                buffer.append(line).append("\n");
            }
            reader.close();

            Lexer lexer = new Lexer(buffer.toString());
            lexer.lex(); // 开始词法分析

            Parser parser = new Parser(lexer.getTokenList(),lexer.getErrorList());
            parser.parseCompUnit();//开始语法分析

            writeError(parser.getErrorList());

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    private static void writeError(List<Error> errorList) {
        Collections.sort(errorList, (e1, e2) -> Integer.compare(e1.getLineNum(), e2.getLineNum()));

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
            for (Error error : errorList) {
                writer.write(error.getLineNum() + " " + error.getMessage());
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


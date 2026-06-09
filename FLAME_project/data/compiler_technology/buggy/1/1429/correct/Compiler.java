import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * Classname ${CLASSNAME}
 * Description TODO
 * Date 2024/10/2 22:25
 * Created ZHW
 */
public class Compiler {
    public static void main(String[] args) {
        try {
            // 读取文件内容
            String sourceCode = readSourceFile("testfile.txt");
            Token token = new Token(sourceCode);

            //整理所有error
            List<Error> allErrors = new ArrayList<>();

            // 创建 Lexer 对象并进行词法分析
            Lexer lexer = new Lexer(token);
            lexer.getAllTokens(); // 开始词法分析
            allErrors.addAll(lexer.getErrors());

            Parser parser = new Parser(lexer.getTokens());
            parser.parseCompUnit();//语法分析
            allErrors.addAll(parser.getErrors());

            writeAllErrors(allErrors);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //读取文件并返回字符串
    private static String readSourceFile(String filePath) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            StringBuilder buffer = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                buffer.append(line).append("\n");
            }
            return buffer.toString();
        }
    }

    //对于所有错误按照行号排序，在写入error.txt文件中
    private static void writeAllErrors(List<Error> allErrors) throws IOException {
        allErrors.sort(Comparator.comparingInt(Error::getLine));

        BufferedWriter errors = new BufferedWriter(new FileWriter("error.txt"));

        int currentLine = -1;
        for (Error error : allErrors){
            if (currentLine != error.getLine()){
                errors.write(error.getLine() + " " + error.getError());
                errors.newLine();
                currentLine = error.getLine();
            }
        }

        errors.close();
    }
}
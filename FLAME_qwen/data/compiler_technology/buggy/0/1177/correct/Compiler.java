import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) {
        String inputFilePath = "testfile.txt";
        String outputFilePath = "lexer.txt";

        // 用于存储读取的文件内容
        StringBuilder fileContent = new StringBuilder();

        // 读取 testfile.txt 文件内容
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFilePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                fileContent.append(line).append("\n"); // 逐行读取并追加到字符串
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        Lexer lexer = new Lexer(fileContent.toString());
        boolean noError = lexer.analyze();

        ArrayList<Message> tokens = lexer.getTokens();

        if (noError) {
            // 向 output.txt 写入一些新的内容
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFilePath))) {
                for (int i = 0; i < tokens.size(); i++) {
                    Message m = tokens.get(i);
                    writer.write(m.getType().toString());
                    writer.write(" ");
                    writer.write(m.getMess());
                    writer.write("\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}

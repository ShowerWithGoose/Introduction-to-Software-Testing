import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

import frontend.Lexer;
import frontend.Token;
import frontend.TokenType;

public class Compiler {
    public static void main(String[] args) {
        try {
            String source = readFile("testfile.txt");

            Lexer lexer = Lexer.getInstance();
            lexer.setSource(source);
            lexer.analyze();

            List<Token> tokens = lexer.getTokens();

            writeResults(tokens);
        } catch (IOException e) {
            System.err.println("File error: " + e.getMessage());
        }
    }

    public static String readFile(String filePath) {
        Path path = Paths.get(filePath);
        try {
            // 检查文件是否存在
            if (!Files.exists(path)) {
                throw new NoSuchFileException("文件路径不存在: " + filePath);
            }
            // 使用 UTF-8 编码读取文件
            return new String(Files.readAllBytes(path), StandardCharsets.UTF_8);
        } catch (NoSuchFileException e) {
            System.err.println("Error: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("文件读取失败: " + e.getMessage());
        }
        return null; // 如果读取失败返回 null
    }


    private static void writeResults(List<Token> tokens) throws IOException {
        try (BufferedWriter lexerOut = new BufferedWriter(new FileWriter("lexer.txt"));
             BufferedWriter errorOut = new BufferedWriter(new FileWriter("error.txt"))) {

            for (Token token : tokens) {
                if (token.getType() == TokenType.ERROR) {
                    errorOut.write(token.getLineno() + " a\n");
                } else {
                    lexerOut.write(token + "\n");
                }
            }
        }
    }
}

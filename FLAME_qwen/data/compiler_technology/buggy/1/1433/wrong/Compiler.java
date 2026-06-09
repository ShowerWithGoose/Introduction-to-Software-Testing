import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

import frontend.Lexer.Lexer;
import frontend.Lexer.Token;
import frontend.Lexer.TokenType;
import frontend.Parser.CompUnit;
import frontend.Parser.Parser;

import static frontend.Lexer.Token.sortTokensByLineno;

public class Compiler {
    public static void main(String[] args) {
        try {
            String source = readFile("testfile.txt");

            Lexer lexer = Lexer.getInstance();
            lexer.setSource(source);
            lexer.analyze();

            List<Token> tokens = lexer.getTokens();

            Parser parser = new Parser(tokens);
            CompUnit compUnit = parser.parseCompUnit();

            List<Token> errorList = parser.getErrorTokens();
            errorList.addAll(lexer.getErrorTokens());
            writeResults(compUnit, errorList);
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

    private static void writeResults(CompUnit compUnit, List<Token> errorTokens) throws IOException {
        try (BufferedWriter lexerOut = new BufferedWriter(new FileWriter("lexer.txt"));
             BufferedWriter errorOut = new BufferedWriter(new FileWriter("error.txt"))) {

            lexerOut.write(compUnit.printString());

            sortTokensByLineno(errorTokens);
            for (Token token : errorTokens) {
                errorOut.write(token.getLineno() + " " + token.getType().toString() + "\n");
            }
        }
    }
}

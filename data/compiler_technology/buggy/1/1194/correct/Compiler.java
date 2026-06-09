import frontend.Lexer;
import frontend.SyntaxAnalyzer;
import frontend.Token;
import frontend.TreeNode;

import java.util.List;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileWriter;
import java.nio.file.Paths;
import java.nio.file.Files;

public class Compiler {
    public static void main(String[] args) {
        try {
            List<String> lines = Files.readAllLines(Paths.get("testfile.txt"));
            // 初始化词法分析器
            Lexer lexer = new Lexer(lines);
            List<Token> tokens = lexer.analyze();
            SyntaxAnalyzer syntaxAnalyzer = new SyntaxAnalyzer(tokens);
            TreeNode treeNode = syntaxAnalyzer.analyze();
            List<Token> errors = syntaxAnalyzer.getErrors();

            // 写入lexer.txt文件
            BufferedWriter lexerWriter = new BufferedWriter(new FileWriter("parser.txt"));
            lexerWriter.write(treeNode.toString());
            lexerWriter.close();

            // 写入error.txt文件
            BufferedWriter errorWriter = new BufferedWriter(new FileWriter("error.txt"));
            for (Token token : errors) {
                errorWriter.write(token.toError());
                errorWriter.newLine();
            }
            errorWriter.close();
        } catch (IOException e) {
        }
    }
}
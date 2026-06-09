import frontend.Lexer;

public class Compiler {
    public static void main(String[] args) {
        String sourceCode = "";
        try {
            sourceCode = new String(java.nio.file.Files.readAllBytes(java.nio.file.Paths.get("testfile.txt")));
        } catch (java.io.IOException e) {
            System.out.println("读取文件时发生错误：" + e.getMessage());
            return;
        }
        Lexer lexer = new Lexer(sourceCode);
        lexer.toTokens();
        lexer.printTokens("lexer.txt");
    }

}

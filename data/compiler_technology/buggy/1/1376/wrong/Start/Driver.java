package Start;

import exception.ErrorTackle;
import front_end.ast.ASTVisitor;
import front_end.lexer.Lexer;
import front_end.parser.Parser;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Driver {
    // 单例模式
    private static Driver instance = new Driver();
    private Driver() {}
    public static Driver getInstance() {
        return instance;
    }

    public String input(String path) {
        // read from Config.in_path
        File file = new File(Config.in_path);
        if (!file.exists()) {
            System.out.println("File not found: " + Config.in_path);
            return null;
        }
        // read content from file
        try {
            return new String(Files.readAllBytes(Paths.get(Config.in_path)));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    public void output(String content) {
        // write to Config.out_path
        try {
            Files.write(Paths.get(Config.out_path), content.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        String input = input(Config.in_path);
        Lexer lexer = new Lexer(input);
//        output(lexer.toString());
        Parser parser = new Parser(lexer);
        String ans = ASTVisitor.astToString(parser.parseCompUnit());
        // delete the last '\n'
        ans = ans.substring(0, ans.length() - 1);
        output(ans);
//        ASTVisitor visitor = new ASTVisitor(parser.parseCompUnit(), "ASTToString");
//        visitor.run();
        ErrorTackle.printErrors(Config.err_path);
    }
}

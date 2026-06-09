import frontend.Lexer;

import java.io.*;
import java.util.Scanner;

public class Compiler {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        try(Scanner scanner = new Scanner(new File("testfile.txt"))) {
            while(scanner.hasNextLine()) {
                sb.append(scanner.nextLine()).append("\n");
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        Lexer lexer = new Lexer(sb.toString());

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("lexer.txt"))) {
            writer.write(lexer.toString());  // 将字符串写入文件
        } catch (IOException e) {
            // 捕获并处理可能的 IO 异常
            System.err.println("写入文件时发生错误: " + e.getMessage());
        }

    }
}
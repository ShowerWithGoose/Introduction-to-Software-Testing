import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String inputFilePath = "testfile.txt";  // 输入文件
        String normalOutputFilePath = "lexer.txt"; // 正常输出文件
        String errorOutputFilePath = "error.txt";   // 错误输出文件
        try (Scanner scanner = new Scanner(new File(inputFilePath));
             FileWriter normalWriter = new FileWriter(normalOutputFilePath);
             FileWriter errorWriter = new FileWriter(errorOutputFilePath)) {
            int right = 1;
            int num = 1;
            int zhushi = 0;
            ArrayList<Word> words = new ArrayList<>();
            while (scanner.hasNextLine()) {
                String input = scanner.nextLine();
                if (input.trim().isEmpty()) {
                    num = num + 1;
                    continue; // 如果输入的是空行，则跳过本次循环
                }
                Lexer lexer = new Lexer(input, zhushi);
                while (lexer.getIfEnd() == 0) {
                    String name = lexer.peek();
                    int right1 = lexer.getRight();
                    if (right1 == 0) {
                        right = right1;
                        lexer.setRight();
                    }
                    String leiBie = lexer.getLeiBie();
                    zhushi = lexer.ifZhushi();
                    if (zhushi == 0) {
                        words.add(new Word(num,name,leiBie,right1));
                    }
                    lexer.next();
                }
                zhushi = lexer.ifZhushi();
                num = num + 1;
            }
            if (right == 1) {
                for (Word it : words) {
                    normalWriter.write(it.getLeiBie() + " " + it.getStr() + "\n");
                }
            } else {
                for (Word it : words) {
                    if (it.getRight() == 0) {
                        errorWriter.write(it.getNum() + " a\n");
                    }
                }
            }
            /*if (right == 1) {
                for (Word it : words) {
                    System.out.println(it.getLeiBie() + " " + it.getStr());
                }
            } else {
                for (Word it : words) {
                    if (it.getRight() == 0) {
                        System.out.println(it.getNum() + " a");
                    }
                }
            }*/
        } catch (IOException e) {
            e.printStackTrace(); // 输出错误信息
        }
    }
}
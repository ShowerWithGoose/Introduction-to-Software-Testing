import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import frontend.Lexer;
import frontend.Parser;

public class Compiler {
    public static void main(String[] args) {
        String filePath = "testfile.txt";

        StringBuilder input = new StringBuilder();

        try(Scanner scanner = new Scanner(new File(filePath))){
            while(scanner.hasNextLine()){
                String line = scanner.nextLine();
                input.append(line).append('\n');
            }
        }catch (FileNotFoundException e){
            System.out.printf("文件未找到！！！");
        }
        input.append("?");
        Parser parser = new Parser(input.toString());
        parser.parse();
    }
}
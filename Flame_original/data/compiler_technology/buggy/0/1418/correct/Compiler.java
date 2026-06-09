import common.GlobalData;
import lexer.*;
import model.Token;
import model.Tokens;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {
//        System.out.println("Compiler start");

        Tokens instance = Tokens.getInstance();
        List<Token> tokens = instance.get();

        String filePath = "testfile.txt"; // 输入文件路径
        BufferedWriter bw;

        try {
            bw = new BufferedWriter(new FileWriter("lexer.txt"));
        } catch (IOException e) {
            System.out.println("Comiler.java Line-25: BufferWriter Error");
            return;
        }

        // 调用 Lexer 进行词法分析
        Lexer lexer = new Lexer(filePath);
        try {
            lexer.run();
        } catch (IOException e) {
            System.out.println("Compiler.java Line-34");
            throw new RuntimeException(e);
        }

        try {
            if(GlobalData.Lexerflag == true) {
                for(Token token: tokens) {
                    bw.write(token.getType() + " " + token.getName() + "\n");
                }
//                System.out.println(token.getType() + " " + token.getName());
            }
            bw.close();
        } catch (IOException e) {
            System.out.println("Comiler.java Line-46: BufferWriter Error");
            return;
        }


    }
}

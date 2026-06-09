import common.GlobalData;
import lexer.*;
import model.Token;
import model.Tokens;
import parser.Parser;
import util.ErrorPrint;
import util.ParserSuccessPrint;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {
//        System.out.println("Compiler start");

        Tokens instance = Tokens.getInstance();
        List<Token> tokens = instance.get();

        String InputFilePath = "testfile.txt"; // 输入文件路径
        BufferedWriter bw;

        try {
            bw = new BufferedWriter(new FileWriter("lexer.txt"));
        } catch (IOException e) {
            System.out.println("Comiler.java Line-25: BufferWriter Error");
            return;
        }

        // 调用 Lexer 进行词法分析
        Lexer lexer = new Lexer(InputFilePath);
        try {
            lexer.run();
        } catch (IOException e) {
            System.out.println("Comiler.java Line-34: Lexer Error");
            throw new RuntimeException(e);
        }

        //Lexer成功结果输出到 lexer.txt
        try {
            if(GlobalData.Lexerflag) {
                for(Token token: tokens) {
                    bw.write(token.getType() + " " + token.getName() + "\n");
                }
            }
            bw.close();
        } catch (IOException e) {
            System.out.println("Comiler.java Line-46: BufferWriter Error");
            return;
        }

        //调用 Parser 进行语法分析
        Parser parser = new Parser();
        parser.run();

        //Parser成功结果输出到 parser.txt
        String ParserPrintFilePath = "parser.txt";
        try {
            bw = new BufferedWriter(new FileWriter(ParserPrintFilePath));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        if(GlobalData.Parserflag) {
            StringBuilder sb = new StringBuilder();
            ParserSuccessPrint parserSuccessPrint = new ParserSuccessPrint();
            parserSuccessPrint.run(GlobalData.CompUnitNode, sb, parserSuccessPrint);

            try {
                bw.write(sb.toString());
                bw.close();
            } catch (IOException e) {
                System.out.println("Comiler.java Line-64: BufferWriter Error");
                throw new RuntimeException(e);
            }
        }

        //输出错误结果到 error.txt
        if(GlobalData.Errorflag) {
            ErrorPrint.run(GlobalData.Errors);
        }
    }
}

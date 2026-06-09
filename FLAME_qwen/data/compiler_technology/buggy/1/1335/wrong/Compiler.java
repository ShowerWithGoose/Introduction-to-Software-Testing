import frontend.error.ErrorInformation;
import frontend.lexer.Lexer;
import frontend.parser.Parser;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import static frontend.parser.ast.ASTNode.postOrderPrint; // Adjust this if needed

public class Compiler {
    public static void main(String[] args) {
        String inputFileName = "testfile.txt";
        String parserOutputFileName = "parser.txt";
        String errorOutputFileName = "error.txt";

        try {
            BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\86136\\Desktop\\hw2_Lexer\\hw2_Lexer\\testfile.txt"));
            BufferedWriter parserWriter = new BufferedWriter(new FileWriter(parserOutputFileName));
            BufferedWriter errorWriter = new BufferedWriter(new FileWriter(errorOutputFileName));
            ArrayList<ErrorInformation> errors = new ArrayList<>();
            Lexer lexer = new Lexer(errors);
            String line;
            int lineNumber = 1;

            // 读取输入文件
            while ((line = reader.readLine()) != null) {
                // Skip empty lines
                if (line.trim().isEmpty()) {
                    lineNumber++;
                    continue;
                }
                lexer.addLine(lineNumber, line);
                lineNumber++;
            }

            lexer.tokenize();
            for(int i = 0;i<lexer.getTokens().size();i++){
                System.out.println(lexer.getTokens().get(i));
            }
            Parser parser = new Parser(lexer.getTokens(),errors);  // 创建Parser实例
            parser.parse();  // 进行语法分析

            // 判断是否有词法或语法错误
            if (!lexer.isHasError() && !parser.hasError()) {
                // 输出语法分析结果
                postOrderPrint(parser.getCompUnitNode(), parserWriter);  // Pass the writer here
            } else {
                Collections.sort(errors, new Comparator<ErrorInformation>() {
                    @Override
                    public int compare(ErrorInformation e1, ErrorInformation e2) {
                        return Integer.compare(e1.getLineNumber(), e2.getLineNumber());
                    }
                });
                for (ErrorInformation error : errors) {
                    errorWriter.write(error.getLineNumber() + " " + error.getErrorCode());  // Use the toPrint method to get the string representation
                    errorWriter .newLine();
                    System.out.println(error.getLineNumber() + " " + error.getErrorCode()+"\n");
                }

            }

            reader.close();
            parserWriter.close();
            errorWriter.close();
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("IO Error: " + e.getMessage());
        }
    }
}
import frontend.*;
import error.ErrorTable;

import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        String inputFileName = "testfile.txt";
        String outputFileName = "parser.txt"; // 输出语法分析结果
        String errorFileName = "error.txt";   // 输出错误

        try (InputStream inputFileStream = new FileInputStream(inputFileName);
             OutputStream outputStream = new FileOutputStream(outputFileName);
             OutputStream errorStream = new FileOutputStream(errorFileName)) {

            // 词法分析阶段
            SrcReader srcReader = new SrcReader(inputFileStream);
            Lexer lexer = new Lexer(srcReader);

            // 如果词法分析有错误，则加入错误表

            // 语法分析阶段
            CompUnitParser compUnitParser = new CompUnitParser(lexer.getTokenList());
            CompUnit compUnit = compUnitParser.parseCompUnit();

            // 检查是否有词法或语法错误
            if (!ErrorTable.getErrors().isEmpty()) {
                // 输出所有错误
                errorStream.write(ErrorTable.output().getBytes());
            } else {
                // 如果没有错误，输出语法分析结果
                outputStream.write(compUnit.syntaxOutput().getBytes());
            }

        } catch (FileNotFoundException e) {
            System.err.println("Cannot open file: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("I/O error: " + e.getMessage());
        }
    }
}

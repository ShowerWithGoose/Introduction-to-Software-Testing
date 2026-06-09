import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import frontend.*;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String testFilePath = "testfile.txt";
        String lexerFilePath = "lexer.txt";
        String parserFilePath = "parser.txt";
        String unSortedFilePath = "output.txt";
        String symbolFilePath = "symbol.txt";
        String errorFilePath = "error.txt";

        Lexer lexer = new Lexer(testFilePath);
        Parser parser = new Parser(lexer);
        Analyzer analyzer = new Analyzer(parser);

        SymbolTable symbolTable = analyzer.getSymbolTable();
        ArrayList<SymbolTableItem> items = symbolTable.getItems();
        ArrayList<String> errors = symbolTable.getErrors();

        ArrayList<String> results = new ArrayList<>();
        for (SymbolTableItem item : items) {
            results.add(item.getDomainNum() + " " + item.getName() + " " + item.getType());
        }

        // 使用自定义比较器对列表进行稳定排序
        Collections.sort(results, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                // 分割出数字部分并转换为整数
                int num1 = Integer.parseInt(o1.split(" ")[0]);
                int num2 = Integer.parseInt(o2.split(" ")[0]);

                // 比较数字大小
                return Integer.compare(num1, num2);
            }
        });

        if (!errors.isEmpty()) {
            try (BufferedWriter bw = new BufferedWriter(new FileWriter(errorFilePath))) {
                for (String error : errors) {
                    bw.write(error);
                    bw.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            // 将排序后的内容写回另一个文件
            try (BufferedWriter bw = new BufferedWriter(new FileWriter(symbolFilePath))) {
                for (String result : results) {
                    bw.write(result);
                    bw.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

//        try (BufferedWriter bw = new BufferedWriter(new FileWriter(symbolFilePath))) {
//            for (String result : results) {
//                bw.write(result);
//                bw.newLine();
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//        try (BufferedWriter bw = new BufferedWriter(new FileWriter(errorFilePath))) {
//            for (String error : errors) {
//                bw.write(error);
//                bw.newLine();
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
    }
}
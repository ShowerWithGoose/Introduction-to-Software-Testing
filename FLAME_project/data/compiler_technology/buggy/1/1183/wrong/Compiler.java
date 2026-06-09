import error.Err;
import frontend.Lexer;
import frontend.Node.Node;
import frontend.Parser;
import frontend.SemanticAnalyzer;
import frontend.Symbol.SymbolTable;
import frontend.Token.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Compiler {
    public static void main(String[] args) throws IOException {
        ArrayList<Err> errorList = new ArrayList<>();
        List<String> lines = new ArrayList<>();
        try {
            lines = Files.readAllLines(Paths.get("testfile.txt"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        Lexer lexer = new Lexer(lines);
        ArrayList<Token> tokens = lexer.tokenize(errorList);
        Parser parser = new Parser(tokens);
        Node rootNode = parser.parseCompUnit(errorList);
        //SemanticAnalyzer analyzer = new SemanticAnalyzer(errorList);
        //SymbolTable symbolTable = analyzer.analysis(rootNode);


        /********************************* 语义分析输出 *********************************/
        /*
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("symbol.txt"))) {
            symbolTable.print(writer);  // 确保遍历写入后再关闭 writer
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Symbol written to file successfully.");

        Collections.sort(errorList, new Comparator<Err>() {
            @Override
            public int compare(Err e1, Err e2) {
                return Integer.compare(e1.getLineNum(), e2.getLineNum());
            }
        });
*/
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("parser.txt"))) {
            rootNode.postOrderTraversal(rootNode, writer);  // 确保遍历写入后再关闭 writer
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Tokens written to file successfully.");

        try (BufferedWriter writer1 = new BufferedWriter(new FileWriter("error.txt"))) {
            for (Err error : errorList) {
                writer1.write(error.getLineNum() + " " + error.getCode());
                writer1.newLine();
            }
            System.out.println("Error written to file successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}





/************************************   词法分析输出部分    *****************************************/
/*boolean flag = true;
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
            for (Err error : errorList) {
                flag = false;
                writer.write(error.getLineNum() + " " + error.getCode());
                writer.newLine();
            }
            System.out.println("Error written to file successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (flag) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter("lexer.txt"))) {
                for (Token token : tokens) {
                    if (token.getLexType() != LexType.NOTE) {
                        writer.write(token.getLexType() + " " + token.getName());
                        writer.newLine();
                    }
                }
                System.out.println("Tokens written to file successfully.");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
 */

/****************************************** 语法分析输出 *********************************************/
/*        try (BufferedWriter writer = new BufferedWriter(new FileWriter("parser.txt"))) {
        rootNode.postOrderTraversal(rootNode, writer);  // 确保遍历写入后再关闭 writer
        } catch (IOException e) {
        e.printStackTrace();
        }
                System.out.println("Tokens written to file successfully.");
 */
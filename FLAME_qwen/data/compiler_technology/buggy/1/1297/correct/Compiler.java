import Paser.Paser;
import Paser.Node;
import Paser.TokenNode;
import Reader.LexicalAnalyzer;
import Reader.TokenStream;
import Symbol.SymbolManager;
import Symbol.SymbolTable;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class Compiler {
    static String lexerfilePath = "lexer.txt";
    static String parserfilePath = "parser.txt";
    static String errorfilePath = "error.txt";
    static String symbolfilePath = "symbol.txt";


    public static void main(String[] args) {

        LexicalAnalyzer lexicalAnalyzer = new LexicalAnalyzer();
        TokenStream tokenStream = lexicalAnalyzer.getWordTypes();
        // lexerOut(tokenStream);
        Paser paser = new Paser(tokenStream);
        Node AST = paser.parseUnitNode();
        nodeOut(tokenStream,AST);
        // SymbolManager symbolManager = new SymbolManager(AST);
        // SymbolTable symbolTable = SymbolManager.topTable;
        // symbolOut(tokenStream,symbolTable);
    }

    public static void symbolOut(TokenStream tokenStream,SymbolTable symbolTable)
    {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(symbolfilePath))) {
            writer.write(symbolTable.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorfilePath))){
            String error = tokenStream.toStringWithErr() + Paser.error + SymbolManager.err;
            writer.write(sortByLineNumber(error));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void lexerOut(TokenStream tokenStream) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(lexerfilePath))) {
            writer.write(tokenStream.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorfilePath))) {
            writer.write(tokenStream.toStringWithErr());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void nodeOut(TokenStream tokenStream,Node node) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(parserfilePath))) {
            // writer.write(node2String(node));
            writer.write(node.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorfilePath))){
            String error = tokenStream.toStringWithErr() + Paser.error;
            writer.write(sortByLineNumber(error));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static String sortByLineNumber(String inputString) {
        // 将输入字符串分割成行
        String[] lines = inputString.split("\n");

        // 使用Arrays的sort方法进行排序，需要一个比较器
        Arrays.sort(lines, new Comparator<String>() {
            @Override
            public int compare(String line1, String line2) {
                // 提取行号，假设行号总是字符串的前几位数字
                int lineNum1 = Integer.parseInt(line1.split(" ")[0]);
                int lineNum2 = Integer.parseInt(line2.split(" ")[0]);
                return Integer.compare(lineNum1, lineNum2);
            }
        });

        // 将排序后的行重新组合成一个字符串，并移除重复行
        StringBuilder sortedString = new StringBuilder();
        String previousLine = "";
        for (String line : lines) {
            if (!line.equals(previousLine)) {
                sortedString.append(line).append("\n");
                previousLine = line;
            }
        }
        // 移除最后一个多余的换行符
        if (sortedString.length() > 0) {
            sortedString.setLength(sortedString.length() - 1);
        }
        return sortedString.toString();
    }

    // public static String node2String(Node node) {
    //     StringBuffer sb = new StringBuffer();
    //     ArrayList<Node> childNode = node.getChildren();
    //     if (childNode == null && node instanceof TokenNode) {
    //         sb.append(((TokenNode) node).getToken().toString());
    //         return sb.toString();
    //     }
    //     for (Node n : childNode) {
    //         sb.append(node2String(n)).append('\n');
    //     }
    //     sb.append('<'+node.getType().toString()+'>');
    //     return sb.toString();
    // }
}
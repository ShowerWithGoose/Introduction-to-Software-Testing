import frontend.Lexer.Lexer;
import frontend.Symbol.SymbolTree;
import frontend.Tree.CompUnit;
import frontend.parser.Parser;
import frontend.Error.ErrorTool;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) throws IOException {
        File filePath;
        filePath = new File("testfile.txt");
        String filePath2 = "parser.txt";
        String filePath3 = "error.txt";
        String filePath4 = "symbol.txt";
        BufferedWriter writer1 = new BufferedWriter(new FileWriter(filePath2));
        BufferedWriter writer2 = new BufferedWriter(new FileWriter(filePath3));
        BufferedWriter writer3 = new BufferedWriter(new FileWriter(filePath4));
        byte[] bytes = Files.readAllBytes(Paths.get(filePath.getAbsolutePath()));
        String source = new String(bytes, StandardCharsets.UTF_8);
        ErrorTool errorTool = new ErrorTool(writer2);
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer, writer1, errorTool);
        CompUnit compUnit = parser.parseCompUnit();
        SymbolTree symbolTree = parser.getParentTree();
        symbolTree.printTree(writer3);

        writer1.close();
        writer2.close();
        writer3.close();
    }
}
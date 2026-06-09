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
        boolean ceshi = false;
        File filePath;
        String filePath2;
        String filePath3;
        filePath = new File("testfile.txt");
        filePath2 = "parser.txt";
        filePath3 = "error.txt";
        BufferedWriter writer1 = new BufferedWriter(new FileWriter(filePath2));
        BufferedWriter writer2 = new BufferedWriter(new FileWriter(filePath3));
        byte[] bytes = Files.readAllBytes(Paths.get(filePath.getAbsolutePath()));
        String source = new String(bytes, StandardCharsets.UTF_8);
        ErrorTool errorTool = new ErrorTool(writer2);
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer, writer1, errorTool);
        CompUnit compUnit = parser.parseCompUnit();
        //SymbolTree symbolTree=compUnit.formSympolTree();
        writer1.close();
        writer2.close();
    }
}
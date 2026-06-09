import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Lexer;
import frontend.lexer.Token;
import frontend.parser.Parser;
import frontend.tree.Node;
import frontend.semantic.Symbol;
import frontend.semantic.SymbolManager;
import frontend.semantic.SymbolTable;
import frontend.tree.Tree;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PushbackInputStream;
import java.util.ArrayList;
import java.util.List;

public class Compiler {
    public static void main(String[] args) throws IOException {
        PushbackInputStream inputStream = new PushbackInputStream(new FileInputStream("testfile.txt"));
        Lexer lexer = new Lexer(inputStream);
        // 词法分析
        ArrayList<Token> tokens = lexer.getTokens();
        // 语法分析
        Parser parser = new Parser(tokens);
        Node root = parser.parseCompUnit();
        // 语义分析
        root.semanticAnalysis();

        if (!ErrorList.getInstance().isEmpty()) {
//            System.out.println("Errors found!");
            printErrors();
        } else {
//            printTokens(tokens);
//            printSyntaxTree(root);
            printSymbols();
        }
        inputStream.close();
    }

    public static void printErrors() throws IOException {
        ErrorList.getInstance().sort();
        try (FileWriter fw = new FileWriter("error.txt")) {
            for (Error error : ErrorList.getInstance().getErrors()) {
                fw.write(error.getLineNum() + " " + error.getType() + "\n");
            }
        }
    }

    public static void printTokens(List<Token> tokens) throws IOException {
        try (FileWriter fw = new FileWriter("lexer.txt")) {
            for (Token token : tokens) {
                fw.write(token.getLexType() + " " + token.getValue() + "\n");
            }
        }
    }

    public static void printSyntaxTree(Node root) throws IOException {
            Tree tree = new Tree(root);
            tree.postOrderPrint();
    }

    public static void printSymbols() throws IOException {
        try (FileWriter fw = new FileWriter("symbol.txt")) {
            SymbolManager.getInstance().sortSymbolTables();
            for (SymbolTable symbolTable : SymbolManager.getInstance().getSymbolTableList()) {
                for (Symbol symbol : symbolTable.getSymbols()) {
                    fw.write(symbol +  "\n");
                }
            }
        }
    }
}

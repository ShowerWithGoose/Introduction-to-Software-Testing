import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;

public class Compiler {
    public static void main(String[] args) {
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<ErrorToken> errors = new ArrayList<>();
        String inputFilePath = "testfile.txt";
        String lexerOutputPath = "lexer.txt";
        String errorOutputPath = "error.txt";
        String parserOutPath = "parser.txt";
        String symbolOutPath = "symbol.txt";

        try {
            Lexer lexer = new Lexer(inputFilePath);
            lexer.tokenize(tokens, errors);
            writeLexerOutput(lexerOutputPath, tokens);
            Parser parser = new Parser(tokens, errors);
            SyntaxNode syntaxTree = parser.parse();//树的根节点
            System.out.println(syntaxTree);
            syntaxTree.printTree(syntaxTree, 0);
            writeParserOutput(parserOutPath, syntaxTree);//后序遍历输出到对应文件夹当中
            //writeSymbolOutput(symbolOutPath);
            errors.sort(Comparator.comparingInt(t -> t.getLine()));
            writeErrorOutput(errorOutputPath, errors);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static void writeLexerOutput(String filePath, ArrayList<Token> tokens) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (Token token : tokens) {
                writer.write(token.getType() + " " + token.getName() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private static void writeParserOutput(String filePath, SyntaxNode syntaxTree) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
                writer.write(syntaxTree.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    /*private static void writeSymbolOutput(String filePath, ) {

    }*/
    private static void writeErrorOutput(String filePath, ArrayList<ErrorToken> errors) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (ErrorToken errorToken : errors) {
                writer.write(errorToken.getLine() + " " + errorToken.getType() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

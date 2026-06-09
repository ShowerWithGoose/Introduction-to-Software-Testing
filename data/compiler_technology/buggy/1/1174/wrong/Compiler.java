import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import lexer.Lexer;
import token.Token;
import parser.Parser;
import AST.ASTNode;
import error.Error;

public class Compiler {
    public static void main(String[] args) {
        String sourceCode;
        List<Token> tokens;
        ASTNode AST;
        List<Error> errors;
        PrintWriter writer_lexer;
        PrintWriter writer_parser;
        PrintWriter writer_error;
        
        try {
            sourceCode = new String(Files.readAllBytes(Paths.get("testfile.txt")));
            writer_lexer = new PrintWriter("lexer.txt");
            writer_parser = new PrintWriter("parser.txt");
            writer_error = new PrintWriter("error.txt");
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
        
        Lexer lexer = new Lexer(sourceCode);
        tokens = lexer.getTokens();
        printLexer(tokens, writer_lexer);
         
        Parser parser = new Parser(tokens);
        AST = parser.buildAST();
        printParser(AST, writer_parser);

        errors = Error.getErrorList();
        printError(errors, writer_error);

        writer_lexer.close();
        writer_parser.close();
        writer_error.close();

        System.out.println("Compile Finish!");
    }

    private static void printLexer(List<Token> tokens, PrintWriter writer_lexer) {
        for (Token token: tokens) {
            String Output = token.getType().name() + " " + token.getContent();
            writer_lexer.println(Output);
        }
        return;
    }

    private static void printParser(ASTNode node, PrintWriter writer_parser) {
        if (node == null) {
            return;
        }
        for (ASTNode child : node.getChildrens()) {
            printParser(child, writer_parser);
        }
        Token token = node.getTerminator();
        String type = node.getNonTerminator();
        if (node.getIsTerminator() == true) 
            writer_parser.println(token.getType().name() + " " + token.getContent());
        else if (!(type.equals("BlockItem") || type.equals("Decl") || type.equals("Btype"))) { 
            writer_parser.println("<" + type + ">");
        }
    }

    private static void printError(List<Error> errors, PrintWriter writer_error) {
        for (Error error : errors) {
            writer_error.println(error.getLineNum() + " " + error.getErrorType());
        }
    }
}

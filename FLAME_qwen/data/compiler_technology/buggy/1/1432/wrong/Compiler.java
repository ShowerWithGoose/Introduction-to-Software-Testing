import frontend.Error.ErrorLog;
import frontend.Lexer.Lexer;
import frontend.Lexer.Token;
import frontend.Lexer.TokenType;
import frontend.Parser.AST.AstNode;
import frontend.Parser.Parser;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Path path = Paths.get("testfile.txt");
        String str = Files.readString(path);
        Lexer lexer = new Lexer(str);
        //StringBuilder stringBuilder = new StringBuilder();
        ArrayList<Token> tokens = new ArrayList<>();
        Token token = lexer.getCurrentToken();
        do {
            //stringBuilder.append(token).append("\n");
            tokens.add(token);
            lexer.next();
            token = lexer.getCurrentToken();
        } while(token.getType() != TokenType.END && token.getType() != TokenType.UNKNOWN);
        //for (Token token1 : tokens) {
        //    System.err.println(token1);
        //}
        AstNode.print = 1;
        AstNode.tokens = tokens;
        Parser parser = new Parser();
        parser.parse();
        ErrorLog.getInstance().printErrors();
        //Path path1 = Paths.get("lexer.txt");
        //Files.writeString(path1, stringBuilder.toString());
    }
}
import logger.Logger;
import syntax.CompUnit;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) {
        String input;
        try {
            input = String.join("\n", Files.readAllLines(Paths.get("testfile.txt")));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Lexer lexer = new Lexer(input);
//        StringBuilder good = new StringBuilder();
//        StringBuilder bad = new StringBuilder();
//        while (lexer.next()) {
//            if (lexer.getLexType() == LexType.ERR_SINGLE_AND || lexer.getLexType() == LexType.ERR_SINGLE_OR) {
//                bad.append(lexer.getLineno()).append(" ").append("a").append("\n");
//            } else {
//                good.append(lexer.getLexType()).append(" ").append(lexer.getToken()).append("\n");
//            }
//        }
        Parser parser = new Parser(lexer);
        CompUnit compUnit = parser.parseCompUnit();
        String good = Logger.getGood();
        String bad = Logger.getBad();
        try {
            if (bad.isEmpty()) {
                Files.write(Paths.get("parser.txt"), good.getBytes());
            } else {
                Files.write(Paths.get("error.txt"), bad.getBytes());
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
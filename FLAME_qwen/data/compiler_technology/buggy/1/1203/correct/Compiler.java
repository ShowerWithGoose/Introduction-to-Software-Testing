import assist.*;
import frontend.*;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;

public class Compiler {
    public static void main(String[] args) throws IOException {
        boolean debug = false;

        String inputFile = "testfile.txt";
        String outputFile = "parser.txt";
        String errorFile = "error.txt";
        String lexerFile = "tokenlist.txt";
        List<String> lines = Files.readAllLines(Paths.get(inputFile),
                StandardCharsets.UTF_8);
        //读进来之后,每个字符串末尾都没有换行符
        List<String> inputs = new ArrayList<>();
        for (String line : lines) {
            StringBuilder tem = new StringBuilder(line);
            inputs.add(tem.append('\n').toString());
        }

        Lexer lexer = new Lexer((ArrayList<String>)inputs);
        ArrayList<Token> tokenList = lexer.resolve();

        if (debug) {
            for (Token token : tokenList) {
                Files.write(Paths.get(lexerFile), token.toString().getBytes(),
                        StandardOpenOption.APPEND, StandardOpenOption.CREATE);
            }
        }

        Parser parser = new Parser(tokenList);
        Node root = parser.parseCompUnit();

        if (parser.isHasError()) { //有错误
            /*Files.write(Paths.get(errorFile), parser.showErrorList(),
                    StandardOpenOption.APPEND, StandardOpenOption.CREATE);*/
            parser.printError(root, errorFile);
            if (debug) {
                parser.printNode(root, outputFile);
            }
        } else { //没错误
            parser.printNode(root, outputFile);
        }
    }
}

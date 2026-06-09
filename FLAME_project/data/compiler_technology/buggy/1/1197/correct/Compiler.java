import frontend.Lexer;
import frontend.Parser;
import config.Config;
import frontend.nodes.Node;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Compiler {

    public static void main(String[] args) throws FileNotFoundException {
        if (Config.DEBUG) {
            Config.OUT = new PrintStream("./parser.txt");
            Config.ERR = new PrintStream("./error.txt");
        }
        Scanner scanner = new Scanner(new File("./testfile.txt"));
        String source = "";
        while (scanner.hasNext()) {
            source += scanner.nextLine() + '\n';
        }
        Lexer.INSTANCE.init(source);
        Node node = Parser.INSTANCE.parse();
    }
}
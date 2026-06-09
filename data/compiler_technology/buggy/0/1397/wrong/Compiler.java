import lexical.Lexer;
import lexical.Read;
import lexical.Token;
import lexical.TokenList;

import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String path = "testfile.txt";
        File file = new File(path);
        Read read = new Read();
        read.readFile(file);
//        File fileError = new File("error.txt");
//        if (!fileError.exists()) {
//            fileError.createNewFile();
//        }
//        PrintStream psError = new PrintStream(fileError);
//        File fileLexer = new File("lexer.txt");
//        if (!fileLexer.exists()) {
//            fileLexer.createNewFile();
//        }
//        PrintStream psLexer = new PrintStream(fileLexer);
        BufferedWriter lexerWriter = new BufferedWriter(new FileWriter("lexer.txt"));
        BufferedWriter errorWriter = new BufferedWriter(new FileWriter("error.txt"));
        Lexer lexer = new Lexer(read);
        lexer.serErrorWriter(errorWriter);
        lexer.run();
        TokenList tokenList = lexer.getTokenlist();
        ArrayList<Token> tokens = tokenList.getList();
        for (Token token : tokens) {
            lexerWriter.write(token.getType() + " " + token.getRawString());
            lexerWriter.newLine();
        }
        lexerWriter.close();
        errorWriter.close();
    }
}

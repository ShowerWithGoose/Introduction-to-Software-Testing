import frontend.*;
import frontend.Error;
import frontend.syntaxTree.Node;
import frontend.type.GrammarType;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;

public class Compiler {
    public static void outputSyntaxTree(Node node, BufferedWriter bufferedWriter) throws IOException{
        if (node.getType() == null) return;
        if (node.getChildren() != null) {
            for (Node child: node.getChildren()) {
                outputSyntaxTree(child, bufferedWriter);
            }
        }
        if(node.getType() == GrammarType.BTYPE || node.getType() == GrammarType.BLOCKITEM ||
        node.getType() == GrammarType.DECL) {
            return;
        }
        bufferedWriter.write(node.toString());
        bufferedWriter.newLine();
    }
    public static void main(String[] args) throws IOException {
        String control = "Parser";
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<Error> errors = new ArrayList<>();
        Node tree;
        Lexer lexer;

        String inputFile = "testfile.txt";
        String outputFileCorrect = "parser.txt";
        String outputFileError = "error.txt";
        try {
            PushbackInputStream pis = new PushbackInputStream(new FileInputStream(inputFile));
            lexer = new Lexer(pis);
        } catch (IOException e) {
            System.out.println("File not found");
            throw new RuntimeException(e);
        }

        tokens = lexer.getTokenArrayList();

        TokenList tokenList = new TokenList(tokens);
        Parser parser = new Parser(tokenList);

        tree = parser.handleCompUnit();

        errors = ErrorList.getErrorList().getErrors();
        errors.sort(Comparator.comparingInt(Error::getLineNum));

        BufferedWriter bufferedWriterCorrect = null;
        BufferedWriter bufferedWriterError = null;
        try {
            bufferedWriterCorrect = new BufferedWriter(new FileWriter(outputFileCorrect));
            bufferedWriterError = new BufferedWriter(new FileWriter(outputFileError));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        if (errors.isEmpty()) {
            try {
                if (control.equals("Lexer")) {
                    for (Token token : tokens) {
                        bufferedWriterCorrect.write(token.getLexType().name()+" "+token.getTokenValue());
                        bufferedWriterCorrect.newLine();
                    }
                } else if (control.equals("Parser")) {
                    outputSyntaxTree(tree, bufferedWriterCorrect);
                }
                bufferedWriterCorrect.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } else {
            try {
                for (Error error : errors) {
                    bufferedWriterError.write(error.getLineNum()+" "+error.getError());
                    bufferedWriterError.newLine();
                }
                bufferedWriterCorrect.close();
                bufferedWriterError.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

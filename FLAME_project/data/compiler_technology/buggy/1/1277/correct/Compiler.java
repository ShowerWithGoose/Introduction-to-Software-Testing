import fronted.lexer.Lexer;
import fronted.parser.parse.CompileUnitParser;
import fronted.parser.parse.Parser;
import fronted.parser.syntax.ErrorSyntax;
import fronted.parser.syntax.SynNode;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.TreeMap;

public class Compiler {
    public static void main(String[] args) {
        String inFlie = "testfile.txt";
        String outFlie = "parser.txt";
        String errFlie = "error.txt";
        Lexer lexer = new Lexer(inFlie);
        Parser parser = new CompileUnitParser(lexer);
        SynNode root = parser.parse();
//        System.out.println(root);
        if (lexer.getError() != null || parser.getErrorList().size() > 0) {
            writeError(lexer, parser, errFlie);
        } else {
            writeParser(root, outFlie);
        }
    }

//    private static void writeError(Lexer lexer, String errFlie) {
//        try {
//            File file = new File(errFlie);
//            if (!file.exists()) {
//                file.createNewFile();
//            }
//            FileOutputStream fos = new FileOutputStream(file);
//            String out = lexer.getError().getLine() + " a";
//            fos.write(out.getBytes());
//            fos.close();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//    }

    private static void writeError(Lexer lexer, Parser parser, String errFlie) {
        try {
            File file = new File(errFlie);
            if (!file.exists()) {
                file.createNewFile();
            }
            TreeMap<Integer, String> errors = new TreeMap<>();
            FileOutputStream fos = new FileOutputStream(file);
            if (lexer.getError() != null) {
                String out = lexer.getError().getLine() + " a";
                errors.put(lexer.getError().getLine(), out);
            }
            if (parser.getErrorList().size() > 0) {
                ArrayList<ErrorSyntax> errorList = parser.getErrorList();
                for (ErrorSyntax error : errorList) {
                    errors.put(error.getLine(), error.getLine() + " " + error.getType().toString());
                }
            }
            String out = "";
            for (String val : errors.values()) {
                out += val + "\n";
            }

            fos.write(out.getBytes());
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

//    private static void writeLexer(Lexer lexer, String outFile) {
//        try {
//            File file = new File(outFile);
//            if (!file.exists()) {
//                file.createNewFile();
//            }
//            FileOutputStream fos = new FileOutputStream(file);
//            Token token;
//            while ((token = lexer.getAndNext()) != null) {
//                String out = token.getType() + " " + token.getValue() + '\n';
//                fos.write(out.getBytes());
//            }
//            fos.close();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//    }
    private static void writeParser(SynNode root, String outFile) {
        try {
            File file = new File(outFile);
            if (!file.exists()) {
                file.createNewFile();
            }
            FileOutputStream fos = new FileOutputStream(file);
            String out = root.toString();
            fos.write(out.getBytes());
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

import frontend.*;

import java.io.*;
import java.lang.Character;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;

public class Compiler {
    private static Lexer lexer;
    private static Parser parser;
    private static Semantic semantic = new Semantic();
    private static ArrayList<Integer> error_line = new ArrayList<>();
    private static ArrayList<Character> error_type = new ArrayList<>();
    private static HashMap<Integer, Character> error;

    public static void main(String[] args) {

        String testfilePath = "testfile.txt";
        String parserPath = "parser.txt";
        String symbolPath = "symbol.txt";
        String errorPath = "error.txt";
        StringBuilder sb = new StringBuilder();

        try (BufferedReader br = new BufferedReader(new FileReader(testfilePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                sb.append(line).append('\n');
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            FileOutputStream fileOutputStream = new FileOutputStream(parserPath);
            fileOutputStream.write(new byte[0]);
            fileOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        String fileContent = sb.toString();

        lexer = new Lexer(fileContent);
        parser = new Parser(lexer);

        lexer.getSymbol();

        CompUnit compUnit = parser.parseCompUnit();

        semantic.analyze(compUnit);

        //print(compUnit, parserPath);
        ArrayList<Symbol> symbols = semantic.getSymbols();

        SymbolSorter.sortSymbolsByScope(symbols);

        /*for (int i = 0; i < symbols.size(); i++) {
            System.out.println(symbols.get(i).getScope() + " " + symbols.get(i).getName() + " " + symbols.get(i).getType());
        }*/

        try {
            FileOutputStream fileOutputStream = new FileOutputStream(symbolPath);
            fileOutputStream.write(new byte[0]);
            fileOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (int i = 0; i < symbols.size(); i++) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(symbolPath, true))) {
                writer.write(symbols.get(i).getScope() + " " + symbols.get(i).getName() + " " + symbols.get(i).getType() + "\n");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        error = semantic.getError();

        error_line = parser.getError_line();
        error_type = parser.getError_type();

        try {
            FileOutputStream fileOutputStream = new FileOutputStream(errorPath);
            fileOutputStream.write(new byte[0]);
            fileOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (int i = 0; i < error_line.size(); i++) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorPath, true))) {
                writer.write(error_line.get(i) + " " + error_type.get(i) + "\n");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }

    public static void print(Token token, String parserPath) {
        if (token instanceof Terminal) {
            if (!Objects.equals(((Terminal) token).getToken(), "&") && !Objects.equals(((Terminal) token).getToken(), "|")) {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(parserPath, true))) {
                    writer.write(((Terminal) token).getType() + " " + ((Terminal) token).getToken() + "\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        } else {
            for (int i = 0; i < token.getSons().size(); i++) {
                print(token.getSons().get(i), parserPath);
            }
            if (!Objects.equals(token.toString1(), "<BlockItem>")
                    && !Objects.equals(token.toString1(), "<Decl>")
                    && !Objects.equals(token.toString1(), "<BType>")) {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(parserPath, true))) {
                    writer.write(token.toString1() + "\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

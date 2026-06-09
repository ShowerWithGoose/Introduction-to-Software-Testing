package Driver;

import Frontend.*;
import Utils.Pair;
import Utils.TokenList;

import java.io.*;
import java.util.ArrayList;

public class Driver {
    public static class ErrorRecord {
        private ArrayList<Pair<Integer, String>> errors = new ArrayList<>();

        public void addError(int line, String error) { errors.add(new Pair<>(line, error)); }

        public int size() { return errors.size(); }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (Pair<Integer, String> error : errors) {
                sb.append(error.first()).append(" ").append(error.second()).append("\n");
            } return sb.toString();
        }
    };

    public static ErrorRecord errorRecord = new ErrorRecord();

    public Driver(String[] args) {
        for (String arg : args) {
            switch (arg) {
                case "--tokens":
                case "-t":
                    Config.PRINT_TOKENS = true;
                    break;
                default:
                    System.err.println("Invalid argument: " + arg);
                    break;
            }
        }
    }

    public void run() {
        File inputFile = new File(Config.TEST_FILE);
        TokenList tokenList;
        try (Reader reader = new InputStreamReader(new FileInputStream(inputFile))) {
            Lexer lexer = new Lexer(reader);
            tokenList = lexer.lex();
            reader.close();
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + Config.TEST_FILE);
            return;
        } catch (IOException e) {
            System.err.println("Error reading file: " + Config.TEST_FILE);
            e.printStackTrace();
            return;
        } catch (Exception e) {
            System.err.println("Unknown Error: " + e.getMessage());
            e.printStackTrace();
            return;
        }
        if (Config.PRINT_TOKENS) {
            if (Config.LEXER_OUTPUT_FILE == null || Config.LEXER_OUTPUT_FILE.equals("")) {
                System.out.println(tokenList);
            } else {
                try (Writer writer = new OutputStreamWriter(new FileOutputStream(Config.LEXER_OUTPUT_FILE))) {
                    writer.write(tokenList.toString());
                    writer.close();
                } catch (IOException e) {
                    System.err.println("Error writing to file: " + Config.LEXER_OUTPUT_FILE);
                    e.printStackTrace();
                    return;
                }
            }
        } if (Config.STOP_AT == Config.Step.LEXICAL) return;
        AST ast = new AST(tokenList);
        if (Config.PRINT_AST) {
            if (Config.PARSER_OUTPUT_FILE == null || Config.PARSER_OUTPUT_FILE.equals("")) {
                System.out.println(ast);
            } else {
                try (Writer writer = new OutputStreamWriter(new FileOutputStream(Config.PARSER_OUTPUT_FILE))) {
                    writer.write(ast.toString());
                    writer.close();
                } catch (IOException e) {
                    System.err.println("Error writing to file: " + Config.PARSER_OUTPUT_FILE);
                    e.printStackTrace();
                    return;
                }
            }
        }
        return;
    }
}

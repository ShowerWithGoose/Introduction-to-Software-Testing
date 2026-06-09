package frontend;

import java.util.*;
import java.io.*;

public class Lexer {
    private static final Set<String> keywords = new HashSet<>(Arrays.asList(
            "else", "void", "main", "for", "const", "getint", "int", "getchar",
            "char", "printf", "break", "return", "continue", "if"
    ));

    private static final Map<String, String> categoryCodes = new HashMap<>();

    private List<Token> tokens = new ArrayList<>();
    private List<String> errors = new ArrayList<>();

    public Lexer() {
        // 初始化类别码
        categoryCodes.put("Ident", "IDENFR");
        categoryCodes.put("IntConst", "INTCON");
        categoryCodes.put("StringConst", "STRCON");
        categoryCodes.put("CharConst", "CHRCON");
        categoryCodes.put("main", "MAINTK");
        categoryCodes.put("const", "CONSTTK");
        categoryCodes.put("int", "INTTK");
        categoryCodes.put("char", "CHARTK");
        categoryCodes.put("break", "BREAKTK");
        categoryCodes.put("continue", "CONTINUETK");
        categoryCodes.put("if", "IFTK");
        categoryCodes.put("else", "ELSETK");
        categoryCodes.put("void", "VOIDTK");
        categoryCodes.put(";", "SEMICN");

        categoryCodes.put("!", "NOT");
        categoryCodes.put("*", "MULT");
        categoryCodes.put(",", "COMMA");

        categoryCodes.put("&&", "AND");
        categoryCodes.put("/", "DIV");
        categoryCodes.put("(", "LPARENT");

        categoryCodes.put("||", "OR");
        categoryCodes.put("%", "MOD");
        categoryCodes.put(")", "RPARENT");

        categoryCodes.put("for", "FORTK");
        categoryCodes.put("<", "LSS");
        categoryCodes.put("[", "LBRACK");

        categoryCodes.put("getint", "GETINTTK");
        categoryCodes.put("<=", "LEQ");
        categoryCodes.put("]", "RBRACK");

        categoryCodes.put("getchar", "GETCHARTK");
        categoryCodes.put(">", "GRE");
        categoryCodes.put("{", "LBRACE");

        categoryCodes.put("printf", "PRINTFTK");
        categoryCodes.put(">=", "GEQ");
        categoryCodes.put("}", "RBRACE");

        categoryCodes.put("return", "RETURNTK");
        categoryCodes.put("==", "EQL");

        categoryCodes.put("+", "PLUS");
        categoryCodes.put("!=", "NEQ");

        categoryCodes.put("-", "MINU");
        categoryCodes.put("=", "ASSIGN");
    }

    public void analyze(String sourceCode) {
        int length = sourceCode.length();
        int index = 0;
        int lineNumber = 1;  // Track the current line number

        while (index < length) {
            char currentChar = sourceCode.charAt(index);

            if (currentChar == '\n') {
                lineNumber++;  // Increase line number on each newline character
                index++;
                continue;
            }

            if (Character.isWhitespace(currentChar)) {
                index++;
            } else if (Character.isLetter(currentChar) || currentChar == '_') {
                int start = index;
                while (index < length && (Character.isLetterOrDigit(sourceCode.charAt(index)) || sourceCode.charAt(index) == '_')) {
                    index++;
                }
                String word = sourceCode.substring(start, index);
                if (keywords.contains(word)) {
                    tokens.add(new Token(categoryCodes.get(word), word, lineNumber));
                } else {
                    tokens.add(new Token("IDENFR", word, lineNumber));
                }
            } else if (Character.isDigit(currentChar)) {
                int start = index;
                while (index < length && Character.isDigit(sourceCode.charAt(index))) {
                    index++;
                }
                tokens.add(new Token("INTCON", sourceCode.substring(start, index), lineNumber));
            } else if (currentChar == '\"') {
                int start = index;
                index++;
                while (index < length && sourceCode.charAt(index) != '\"') {
                    if (sourceCode.charAt(index) == '\n') {
                        lineNumber++; // Handle new line inside the string
                    }
                    index++;
                }
                if (index < length) {
                    tokens.add(new Token("STRCON", sourceCode.substring(start, ++index), lineNumber));
                } else {
                    errors.add(lineNumber + " b");  // Output the line number and error category code 'b' for unterminated string
                }
            } else if (index + 1 < length && (
                    (currentChar == '>' && sourceCode.charAt(index + 1) == '=') ||
                            (currentChar == '<' && sourceCode.charAt(index + 1) == '=') ||
                            (currentChar == '=' && sourceCode.charAt(index + 1) == '=') ||
                            (currentChar == '!' && sourceCode.charAt(index + 1) == '='))) {
                // Double-character delimiters: >=, <=, ==, !=
                String doubleChar = "" + currentChar + sourceCode.charAt(index + 1);
                tokens.add(new Token(categoryCodes.get(doubleChar), doubleChar, lineNumber));
                index += 2;
            } else if (";!*%+-=<>".indexOf(currentChar) != -1) {
                // Single-character delimiters: ;, !, *, %, +, -, /, =, <, >
                tokens.add(new Token(categoryCodes.get(String.valueOf(currentChar)), String.valueOf(currentChar), lineNumber));
                index++;
            } else if (currentChar == '&' || currentChar == '|') {
                if (index + 1 < length && sourceCode.charAt(index + 1) == currentChar) {
                    // It's a valid '&&' or '||'
                    tokens.add(new Token(categoryCodes.get(String.valueOf(currentChar) + currentChar), String.valueOf(currentChar) + currentChar, lineNumber));
                    index += 2;
                } else {
                    errors.add(lineNumber + " a"); // Output the line number and error category code 'a'
                    index++;
                }
            } else if (currentChar == '/') {
                if (index + 1 < length && sourceCode.charAt(index + 1) == '/') {
                    // Single-line comment, skip to end of line
                    index += 2; // Skip the "//"
                    while (index < length && sourceCode.charAt(index) != '\n') {
                        index++;
                    }
                    if (index < length&& sourceCode.charAt(index)=='\n') {
                        index++; // Skip the newline character
                        lineNumber++; // Increment line number
                    }
                } else if (index + 1 < length && sourceCode.charAt(index + 1) == '*') {
                    // Multi-line comment
                    index += 2; // Skip the "/*"
                    while (index < length) {
                        if (sourceCode.charAt(index) == '*' && (index + 1 < length) && sourceCode.charAt(index + 1) == '/') {
                            index += 2; // Skip the "*/"
                            break; // End of multi-line comment
                        }
                        if (sourceCode.charAt(index) == '\n') {
                            lineNumber++; // Increment line number for new lines in the comment
                        }
                        index++;
                    }
                } else {
                    // It's a division operator
                    tokens.add(new Token(categoryCodes.get(String.valueOf(currentChar)), String.valueOf(currentChar), lineNumber));
                    index++;
                }
            }else if (categoryCodes.containsKey(String.valueOf(currentChar))) {
                tokens.add(new Token(categoryCodes.get(String.valueOf(currentChar)), String.valueOf(currentChar), lineNumber));
                index++;
            } else {
                errors.add(lineNumber + ": Unrecognized symbol " + currentChar);
                index++;
            }
        }
    }


    public void printTokens() {
        System.out.println("Tokens found:");
        for (Token token : tokens) {
            System.out.println(token);
        }
    }

    public void printErrors() {
        if (errors.isEmpty()) {
            //System.out.println("No lexical errors found.");
        } else {
            //System.out.println("Lexical errors found:");
            for (String error : errors) {
                System.out.println(error);
            }
        }
    }
    public void outputResults() {
        try (PrintWriter lexerWriter = new PrintWriter(new FileWriter("lexer.txt"));
             PrintWriter errorWriter = new PrintWriter(new FileWriter("error.txt"))) {

            // Output tokens to lexer.txt
            for (Token token : tokens) {
                lexerWriter.println(token.getType() + " " + token.getValue());
            }

            // Output errors to error.txt
            if (!errors.isEmpty()) {
                for (String error : errors) {
                    errorWriter.println(error);
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


}


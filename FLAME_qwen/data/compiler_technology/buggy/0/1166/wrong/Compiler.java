import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Compiler {
    private static final Map<String, String> keywords = new HashMap<>();
    private static final List<String> errors = new ArrayList<>();

    static {
        keywords.put("main", "MAINTK");
        keywords.put("const", "CONSTTK");
        keywords.put("int", "INTTK");
        keywords.put("char", "CHARTK");
        keywords.put("break", "BREAKTK");
        keywords.put("continue", "CONTINUETK");
        keywords.put("if", "IFTK");
        keywords.put("else", "ELSETK");
        keywords.put("getint", "GETINTTK");
        keywords.put("getchar", "GETCHARTK");
        keywords.put("printf", "PRINTFTK");
        keywords.put("return", "RETURNTK");
        keywords.put("void", "VOIDTK");
        keywords.put("for", "FORTK");
        keywords.put("&&", "AND");
        keywords.put("||", "OR");
        keywords.put("==", "EQL");
        keywords.put("!=", "NEQ");
        keywords.put("<", "LSS");
        keywords.put("<=", "LEQ");
        keywords.put(">", "GRE");
        keywords.put(">=", "GEQ");
        keywords.put("!", "NOT");
        keywords.put("+", "PLUS");
        keywords.put("-", "MINU");
        keywords.put("*", "MULT");
        keywords.put("/", "DIV");
        keywords.put("%", "MOD");
        keywords.put("=", "ASSIGN");
        keywords.put(";", "SEMICN");
        keywords.put(",", "COMMA");
        keywords.put("(", "LPARENT");
        keywords.put(")", "RPARENT");
        keywords.put("[", "LBRACK");
        keywords.put("]", "RBRACK");
        keywords.put("{", "LBRACE");
        keywords.put("}", "RBRACE");
    }

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"));
             PrintWriter lexerOut = new PrintWriter(new FileWriter("lexer.txt"));
             PrintWriter errorOut = new PrintWriter(new FileWriter("error.txt"))) {

            StringBuilder fileContent = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                fileContent.append(line).append(System.lineSeparator());
            }

            String contentWithoutComments = fileContent.toString().replaceAll("//.*|/\\*(.|\\R)*?\\*/", "");

            int lineNumber = 1;
            try (BufferedReader cleanedReader = new BufferedReader(new StringReader(contentWithoutComments))) {
                while ((line = cleanedReader.readLine()) != null) {
                    analyzeLine(line.trim(), lineNumber, lexerOut, errorOut);
                    lineNumber++;
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void analyzeLine(String line, int lineNumber, PrintWriter lexerOut, PrintWriter errorOut) {
        line = line.replaceAll("//.*", "");

        // Match single tokens with regex
        String regex = "\\s*(int\\b|char\\b|const\\b|break\\b|continue\\b|if\\b|else\\b|getint\\b|getchar\\b|printf\\b|return\\b|void\\b|main\\b|for\\b" +
                "|&&|\\|\\||==|!=|<=|>=" +
                "|[+\\-*\\/%;=<>,!()\\[\\]{}&|]" +
                "|\\d+|\"[^\"]*\"|'(\\\\'|\\\\0|[^'\\\\])'|[a-zA-Z_][a-zA-Z0-9_]*)\\s*";
        Matcher matcher = Pattern.compile(regex).matcher(line);

        while (matcher.find()) {
            String token = matcher.group(1);
            System.out.println("Found token: " + token); // Debug output

            if (keywords.containsKey(token)) {
                lexerOut.printf("%s %s%n", keywords.get(token), token);
            } else if (token.matches("\\d+")) {
                lexerOut.printf("INTCON %s%n", token);
            } else if (token.matches("\".*\"")) {
                lexerOut.printf("STRCON %s%n", token);
            }  else if (token.matches("'(\\\\'|\\\\0|\\\\t|\\\\n|\\\\b|\\\\r|\\\\f|\\\\a|\\\\v|\\\\\\\\|\\\\\"|[^'\\\\])'")) {
                // Handle character constants correctly
                String characterValue = token.substring(1, token.length() - 1); // Extract the character value

                switch (characterValue) {
                    case "0":
                        lexerOut.printf("CHRCON '\\0'%n"); // Handle null character
                        break;
                    case "t":
                        lexerOut.printf("CHRCON '\\t'%n"); // Handle tab character
                        break;
                    case "n":
                        lexerOut.printf("CHRCON '\\n'%n"); // Handle newline character
                        break;
                    case "b":
                        lexerOut.printf("CHRCON '\\b'%n"); // Handle backspace character
                        break;
                    case "r":
                        lexerOut.printf("CHRCON '\\r'%n"); // Handle carriage return character
                        break;
                    case "f":
                        lexerOut.printf("CHRCON '\\f'%n"); // Handle form feed character
                        break;
                    case "a":
                        lexerOut.printf("CHRCON '\\a'%n"); // Handle alert (bell) character
                        break;
                    case "v":
                        lexerOut.printf("CHRCON '\\v'%n"); // Handle vertical tab character
                        break;
                    case "\\":
                        lexerOut.printf("CHRCON '\\\\'%n"); // Handle backslash
                        break;
                    case "\"":
                        lexerOut.printf("CHRCON '\\\"'%n"); // Handle double quote
                        break;
                    case "'":
                        lexerOut.printf("CHRCON '\\'%n"); // Handle single quote
                        break;
                    default:
                        lexerOut.printf("CHRCON '%s'%n", characterValue); // Handle any other character
                        break;
                }
            } else if (isIdentifier(token)) {
                lexerOut.printf("IDENFR %s%n", token);
            } else if (token.equals("&") || token.equals("|")) {
                errorOut.println(lineNumber + " a");
            }
        }
    }


    private static boolean isIdentifier(String token) {
        return token.matches("[a-zA-Z_][a-zA-Z0-9_]*") && !keywords.containsKey(token);
    }
}
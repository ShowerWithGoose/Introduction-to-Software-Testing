import java.io.*;
import java.util.*;

public class Compiler {
    private int currow;
    
    private boolean duohang;
    private int numrow;
    private static BufferedReader reader;
    private static PrintWriter lexerWriter;
    private static PrintWriter errorWriter;
    
    public Compiler() {
        numrow = 1;
        duohang = false;
    }

    private void processLine(String line) {
        for (int i = 0; i < line.length(); ) {
            if (duohang) {
                int endCommentIndex = line.indexOf("*/", i);
                if (endCommentIndex != -1) {
                    duohang = false;
                    i = endCommentIndex + 2; // Skip "*/"
                } else {
                    return; // Skip the entire line
                }
            }
            
            if (i >= line.length()) {
                break;
            }
            char c = line.charAt(i);

            // Handle single-line comments
            if (i + 1 < line.length() && c == '/' && line.charAt(i + 1) == '/') {
                break;
            }

            // Handle multi-line comments
            if (i + 1 < line.length() && c == '/' && line.charAt(i + 1) == '*') {
                duohang = true;
                i += 2; // Skip "/*"
                continue;
            }

            // Skip whitespace
            if (Character.isWhitespace(c)) {
                i++;
                continue;
            }

            // Handle identifiers and keywords
            if (Character.isLetter(c) || c == '_') {
                int start = i;
                while (i < line.length() && (Character.isLetterOrDigit(line.charAt(i)) || line.charAt(i) == '_')) {
                    i++;
                }
                String token = line.substring(start, i);
                processIdentifierOrKeyword(token);
            }
            
            // Handle string constants
            else if (c == '"') {
                i = processStringConstant(line, i);
            }
            // Handle character constants
            else if (c == '\'') {
                i = processCharConstant(line, i);
            }
            // Handle numeric constants
            else if (Character.isDigit(c)) {
                int start = i;
                while (Character.isDigit(line.charAt(i)) && i < line.length()) {
                    i++;
                }
                String token = line.substring(start, i);
                lexerWriter.println("INTCON " + token);
            }
            // Handle operators and symbols
            else {
                i = processOperator(line, i);
            }
        }
    }

    private int processStringConstant(String line, int i) {
        i++; // Skip starting quote
        StringBuilder strConst = new StringBuilder();
        boolean validString = true;

        for (; i < line.length() && line.charAt(i) != '"'; i++) {
            char c = line.charAt(i);
            if (c == '\\' && i + 1 < line.length()) { // Handle escape characters
                char next = line.charAt(i + 1);
                strConst.append('\\').append(next);
                i++;
            } else {
                strConst.append(c);
            }
        }

        if (i < line.length() && line.charAt(i) == '"') {
            i++; // Skip ending quote
            if (validString) {
                lexerWriter.println("STRCON " + "\"" + strConst.toString() + "\"");
            }
        } else {
            errorWriter.println(numrow + " a"); // Unclosed string
        }
        return i;
    }

    private int processCharConstant(String line, int i) {
        i++; // Skip starting single quote
        StringBuilder charConst = new StringBuilder();

        if (i < line.length() && line.charAt(i) != '\'') {
            char c = line.charAt(i);
            if (c == '\\' && i + 1 < line.length()) { // Handle escape characters
                char next = line.charAt(i + 1);
                charConst.append('\\').append(next);
                i += 2;
            } else {
                charConst.append(c);
                i++;
            }
        }

        if (i < line.length() && line.charAt(i) == '\'') {
            i++; // Skip ending single quote
            lexerWriter.println("CHRCON '" + charConst.toString() + "'");
        } else {
            errorWriter.println(numrow + " a"); // Unclosed character constant
        }
        return i;
    }

    private int processOperator(String line, int i) {
        char c = line.charAt(i);
        if (c == '+') {
            lexerWriter.println("PLUS +");
            return i + 1;
        } else if (c == '-') {
            lexerWriter.println("MINU -");
            return i + 1;
        } else if (c == '*') {
            lexerWriter.println("MULT *");
            return i + 1;
        } else if (c == '|') {
            if (i + 1 < line.length() && line.charAt(i + 1) == '|') {
                lexerWriter.println("OR ||");
                return i + 2;
            } else {
                errorWriter.println(numrow + " a");
                return i + 1;
            }
        } else if (c == '<') {
            if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                lexerWriter.println("LEQ <=");
                return i + 2;
            } else {
                lexerWriter.println("LSS <");
                return i + 1;
            }
        } else if (c == '/') {
            if (i + 1 < line.length() && line.charAt(i + 1) == '/') {
                return line.length(); // Skip the rest of the line
            } else if (i + 1 < line.length() && line.charAt(i + 1) == '*') {
                duohang = true;
                return i + 2;
            } else {
                lexerWriter.println("DIV /");
                return i + 1;
            }
        } else if (c == '%') {
            lexerWriter.println("MOD %");
            return i + 1;
        } else if (c == '&') {
            if (i + 1 < line.length() && line.charAt(i + 1) == '&') {
                lexerWriter.println("AND &&");
                return i + 2;
            } else {
                errorWriter.println(numrow + " a");
                return i + 1;
            }
        } else if (c == '>') {
            if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                lexerWriter.println("GEQ >=");
                return i + 2;
            } else {
                lexerWriter.println("GRE >");
                return i + 1;
            }
        } else if (c == '=') {
            if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                lexerWriter.println("EQL =="); 
                return i + 2;
            } else {
                lexerWriter.println("ASSIGN =");
                return i + 1;
            }
        } else if (c == '!') {
            if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                lexerWriter.println("NEQ !=");
                return i + 2;
            } else {
                lexerWriter.println("NOT !");
                return i + 1;
            }
        } else if (c == '{') {
            lexerWriter.println("LBRACE {");
            return i + 1;
        } else if (c == '}') {
            lexerWriter.println("RBRACE }");
            return i + 1;
        } else if (c == ']') {
            lexerWriter.println("RBRACK ]");
            return i + 1;
        } else if (c == ';') {
            lexerWriter.println("SEMICN ;");
            return i + 1;
        } else if (c == ',') {
            lexerWriter.println("COMMA ,");
            return i + 1;
        } else if (c == '(') {
            lexerWriter.println("LPARENT (");
            return i + 1;
        } else if (c == ')') {
            lexerWriter.println("RPARENT )");
            return i + 1;
        } else if (c == '[') {
            lexerWriter.println("LBRACK [");
            return i + 1;
        } else {
            errorWriter.println(numrow + " a");
            return i + 1;
        }
    }

    public void analyze() throws IOException {
        String line;
        while ((line = reader.readLine()) != null) {
            currow++;
            processLine(line);
            numrow++;
        }
    }

    private void processIdentifierOrKeyword(String token) {
        if (keywords.contains(token)) {
            lexerWriter.println(token.toUpperCase() + "TK " + token);
        } else {
            lexerWriter.println("IDENFR " + token);
        }
    }

    private static final Set<String> keywords = new HashSet<>(Arrays.asList(
        "const", "int", "return", "printf", "scanf", "getint", "char", "void", "main", "if", "else", "for", "while", 
        "break", "getchar", "continue" 
    ));

    public static void main(String[] args) throws IOException {
        reader = new BufferedReader(new FileReader("testfile.txt"));
        lexerWriter = new PrintWriter(new FileWriter("lexer.txt"));
        errorWriter = new PrintWriter(new FileWriter("error.txt"));
        Compiler lexer = new Compiler();
        lexer.analyze();
        reader.close();
        lexerWriter.close();
        errorWriter.close();
    }
}
package frontEnd;
import java.io.*;
import java.util.*;
import java.util.regex.*;

public class CompileLexer {
    private static final Map<String, String> KEYWORDS = new HashMap<String, String>() {{
        put("else", "ELSETK");
        put("void", "VOIDTK");
        put("int", "INTTK");
        put("char", "CHARTK");
        put("main", "MAINTK");
        put("for", "FORTK");
        put("const", "CONSTTK");
        put("getint", "GETINTTK");
        put("getchar", "GETCHARTK");
        put("printf", "PRINTFTK");
        put("if", "IFTK");
        put("return", "RETURNTK");
        put("break", "BREAKTK");
        put("continue", "CONTINUETK");
    }};
    private static final Set<String> SYMBOLS = new HashSet<>(Arrays.asList(
            "<=","&&",">=" ,";", "*", ",", "/", "(", ")", "%","<", ">","||",
            "[", "]", "{", "}", "==", "!=", "+", "-", "=","!"));
    private static final Pattern TOKEN_PATTERN = Pattern.compile(
            "(\\belse\\b|\\bvoid\\b|\\bint\\b|\\bchar\\b|\\bmain\\b|\\bfor\\b|\\bconst\\b|\\bgetint\\b|\\bgetchar\\b|\\bprintf\\b|\\bif\\b|\\breturn\\b|\\bbreak\\b|\\bcontinue\\b|" +
                    "\\/\\*|"+"\\*\\/|"+
                    "\\<\\=|\\>\\=|\\;|\\!\\=|\\!|\\*|\\,|\\/|\\(|\\)|\\%|\\<|\\>|\\[|\\]|\\{|\\}|\\=\\=|\\+|\\-|\\=|" +
                    "\\b[a-zA-Z_][a-zA-Z0-9_]*\\b|" +
                    "'(\\\\[\\\\\"\'\\abfnrtv0]|[!-~])'|' '|" +
                    "\"[^\"]+\"|" +
                    "\\d+|" +
                    "\\|\\||&&)");
    private static final Pattern COMMENT_PATTERN = Pattern.compile("/\\*.*?\\*/", Pattern.DOTALL);
    public static void Lexer(String fileName) {
        File inputFile = new File(fileName);
        File lexerFile = new File("lexer.txt");
        File errorFile = new File("error.txt");
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
             BufferedWriter lexerWriter = new BufferedWriter(new FileWriter(lexerFile));
             BufferedWriter errorWriter = new BufferedWriter(new FileWriter(errorFile))) {
            int isComment=0;
            String line;
            int lineNo = 0;
            while ((line = reader.readLine()) != null) {
                lineNo++;
                // Remove single line comments
                line = line.replaceAll("//.*", "");
                Matcher matcher = TOKEN_PATTERN.matcher(line);
                int lastEnd = 0;
                while (matcher.find()) {
                    String matchedText = matcher.group();
                    if (lastEnd != matcher.start()) {
                        // There is some text which is not recognized as a token
                        String unrecognizedText = line.substring(lastEnd, matcher.start());
                        errorWriter.write(lineNo + " a " + "\n");
                    }
                    if(matchedText.equals("/*")&&isComment==0)
                        isComment=1;
                    if(isComment==0) {
                        if (KEYWORDS.containsKey(matchedText)) {
                            lexerWriter.write(KEYWORDS.get(matchedText) + " " + matchedText + "\n");
                        } else if (SYMBOLS.contains(matchedText)) {
                            // We will use a custom mapping for symbols
                            lexerWriter.write(getSymbolCode(matchedText) + " " + matchedText + "\n");
                        } else if (Character.isDigit(matchedText.charAt(0))) {
                            lexerWriter.write("INTCON " + matchedText + "\n");
                        } else if (matchedText.startsWith("\"")) {
                            lexerWriter.write("STRCON " + matchedText + "\n");
                        } else if (matchedText.startsWith("'")) {
                            lexerWriter.write("CHRCON " + matchedText + "\n");
                        } else {
                            lexerWriter.write("IDENFR " + matchedText + "\n");
                        }
                        lastEnd = matcher.end();
                    }
                    if(matchedText.equals("*/")&&isComment==1)
                        isComment=0;
                }
                if (lastEnd != line.length()) {
                    // There is some trailing text which is not recognized as a token
                    String trailingText = line.substring(lastEnd);
                    errorWriter.write(lineNo + " a " + "\n");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String getSymbolCode(String symbol) {
        switch (symbol) {
            case ";": return "SEMICN";
            case "*": return "MULT";
            case ",": return "COMMA";
            case "/": return "DIV";
            case "(": return "LPARENT";
            case ")": return "RPARENT";
            case "%": return "MOD";
            case "{": return "LBRACE";
            case "}": return "RBRACE";
            case "==": return "EQL";
            case "!=": return "NEQ";
            case "<=": return "LEQ";
            case ">=": return "GEQ";
            case "||": return "OR";
            case "&&": return "AND";
            case "+": return "PLUS";
            case "-": return "MINU";
            case "=": return "ASSIGN";
            case "!": return "NOT";
            case "<": return "LSS";
            case "[": return "LBRACK";
            case "]": return "RBRACK";
            case ">": return "GRE";
            default: return "UNKNOWN";
        }
    }
}
package frontend;

import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private String srccode;
    private int p = 0;
    private int line = 1;
    private boolean err = false;
    private ArrayList<Token> tokens = new ArrayList<>();
    private ArrayList<MyError> errors = new ArrayList<>();
    private HashMap<String, Type> keywords;
    private final String delimiters = "+-*/;,()[]{}%";
    private final String cmpDelimiters = "<>=!";

    private static Lexer instance;

    public static Lexer getInstance(String srccode, HashMap<String, Type> keywords) {
        if (instance == null) {
            instance = new Lexer(srccode, keywords);
        }
        return instance;
    }

    private Lexer(String srccode, HashMap<String, Type> keywords) {
        this.srccode = srccode;
        this.keywords = keywords;
        init();
        p = 0;
        line = 1;
    }

    private void init() {
        while (p < srccode.length()) {
            char c = srccode.charAt(p);
            if (c == ' ' || c == '\t') {
                p++;
                continue;
            }
            if (c == '\n' || c == '\r') {
                p++;
                line++;
                continue;
            }
            if (c == '/') {
                if (p + 1 < srccode.length() && srccode.charAt(p + 1) == '/') {
                    while (p < srccode.length() && srccode.charAt(p) != '\n') {
                        p++;
                    }
                    continue;
                } else if (p + 1 < srccode.length() && srccode.charAt(p + 1) == '*') {
                    while (p < srccode.length() && !(srccode.charAt(p) == '*' && srccode.charAt(p + 1) == '/')) {
                        if (srccode.charAt(p) == '\n') {
                            line++;
                        }
                        p++;
                    }
                    p += 2;
                    continue;
                }
            }
            String name = null;
            Type type = null;
            if (Character.isAlphabetic(c) || c == '_') {
                int start = p;
                while (p < srccode.length() && (Character.isAlphabetic(srccode.charAt(p)) || Character.isDigit(srccode.charAt(p)) || srccode.charAt(p) == '_')) {
                    p++;
                }
                name = srccode.substring(start, p);
                type = keywords.containsKey(name) ? keywords.get(name) : Type.IDENFR;
                tokens.add(new Token(name, type));

            } else if (Character.isDigit(c)) {
                int start = p;
                while (p < srccode.length() && Character.isDigit(srccode.charAt(p))) {
                    p++;
                }
                name = srccode.substring(start, p);
                type = Type.INTCON;
                tokens.add(new Token(name, type, Long.valueOf(name)));
            } else {
                if (delimiters.contains(String.valueOf(srccode.charAt(p)))) {
                    name = String.valueOf(srccode.charAt(p));
                    type = keywords.get(name);
                    tokens.add(new Token(name, type));
                    p++;
                } else if (cmpDelimiters.contains(String.valueOf(srccode.charAt(p)))) {
                    if (srccode.charAt(p + 1) == '=') {
                        name = srccode.substring(p, p + 2);
                        type = keywords.get(name);
                        tokens.add(new Token(name, type));
                        p += 2;
                    } else {
                        name = String.valueOf(srccode.charAt(p));
                        type = keywords.get(name);
                        tokens.add(new Token(name, type));
                        p++;
                    }

                } else if (srccode.charAt(p) == '"') {
                    int start = p;
                    p++;
                    while (p < srccode.length() && srccode.charAt(p) != '"'){
                        if(srccode.charAt(p) == '\\'){
                            p++;
                        }
                        p++;
                    }
                    name = srccode.substring(start, p + 1);
                    type = Type.STRCON;
                    tokens.add(new Token(name, type));
                    p++;
                } else if (srccode.charAt(p) == '\'') {
                    int start = p;
                    p++;
                    while (p < srccode.length() && srccode.charAt(p) != '\'') {
                        if (srccode.charAt(p) == '\\') {
                            p++;
                        }
                        p++;
                    }
                    name = srccode.substring(start, p + 1);
                    type = Type.CHRCON;
                    tokens.add(new Token(name, type));
                    p++;
                } else if (srccode.charAt(p) == '&') {
                    if (srccode.charAt(p + 1) == '&') {
                        name = srccode.substring(p, p + 2);
                        type = Type.AND;
                        tokens.add(new Token(name, type));
                        p += 2;
                    } else {
                        err = true;
                        name = String.valueOf(srccode.charAt(p));
                        type = Type.ERROR;
                        tokens.add(new Token(name, type));
                        errors.add(new MyError("a", line));
                        p++;
                    }


                } else if (srccode.charAt(p) == '|') {
                    if (srccode.charAt(p + 1) == '|') {
                        name = srccode.substring(p, p + 2);
                        type = Type.OR;
                        tokens.add(new Token(name, type));
                        p += 2;
                    } else {
                        name = String.valueOf(srccode.charAt(p));
                        type = Type.ERROR;
                        tokens.add(new Token(name, type));
                        errors.add(new MyError("a", line));
                        p++;
                    }

                } else {
                    name = String.valueOf(srccode.charAt(p));
                    type = Type.ERROR;
                    tokens.add(new Token(name, type));
                    errors.add(new MyError("Unkonwn Error", line));
                    p++;
                }

            }

        }

    }


    public void next() {
        p++;
    }

    public Token now() {
        return tokens.get(p);
    }

    public boolean notEnd() {
        return p < tokens.size();
    }

    public Token getToken(int idx) {
        return tokens.get(p + idx);
    }

    public boolean isError() {
        return err;
    }

    public ArrayList<MyError> getErrors() {
        return errors;
    }
}

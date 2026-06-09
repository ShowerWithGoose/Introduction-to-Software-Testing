package fronened.Lexer;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private final ArrayList<Token> tokens = new ArrayList<>();

    private final HashMap<String, Token.Type> keywords = new HashMap<>();

    private int line = 1;

    public TokenIterator iterator() {
        return new TokenIterator(tokens);
    }


    public void init_keyword() {
        this.keywords.put("main",Token.Type.MAINTK);
        this.keywords.put("const",Token.Type.CONSTTK);
        this.keywords.put("int",Token.Type.INTTK);
        this.keywords.put("char",Token.Type.CHARTK);
        this.keywords.put("break",Token.Type.BREAKTK);
        this.keywords.put("continue",Token.Type.CONTINUETK);
        this.keywords.put("if",Token.Type.IFTK);
        this.keywords.put("else",Token.Type.ELSETK);
        this.keywords.put("for",Token.Type.FORTK);
        this.keywords.put("getint",Token.Type.GETINTTK);
        this.keywords.put("getchar",Token.Type.GETCHARTK);
        this.keywords.put("printf",Token.Type.PRINTFTK);
        this.keywords.put("return",Token.Type.RETURNTK);
        this.keywords.put("void",Token.Type.VOIDTK);

    }

    public boolean analyze_keyword(String keyword) {
        if (this.keywords.containsKey(keyword)) {
            this.tokens.add(new Token(this.keywords.get(keyword),this.line,keyword));
            return true;
        }
        return false;
    }

    public void analyze_string(String keyword){
        String s = null;
        for (int i = 0; i < keyword.length(); i++) {
            char c = keyword.charAt(i);
            if (c == ' ') {
                analyze_const(s);
                s = null;
                continue;
            }
            if (c == '+') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.PLUS,line,String.valueOf(c)));
                continue;
            }
            if (c == '%') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.MOD,line,String.valueOf(c)));
                continue;
            }
            if (c == '-') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.MINU,line,String.valueOf(c)));
                continue;
            }
            if (c == '*') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.MULT,line,String.valueOf(c)));
                continue;
            }
            if (c == '/') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.DIV,line,String.valueOf(c)));
                continue;
            }
            if (c == '!') {
                analyze_const(s);
                s = null;
                if (i + 1 < keyword.length() && keyword.charAt(i + 1) == '=') {
                    i++;
                    tokens.add(new Token(Token.Type.NEQ,line,"!="));
                    continue;
                }
                tokens.add(new Token(Token.Type.NOT,line,String.valueOf(c)));
                continue;
            }
            if (c == '=') {
                analyze_const(s);
                s = null;
                if (i + 1 < keyword.length() && keyword.charAt(i + 1) == '=') {
                    i++;
                    tokens.add(new Token(Token.Type.EQL,line,"=="));
                    continue;
                }
                tokens.add(new Token(Token.Type.ASSIGN,line,String.valueOf(c)));
                continue;
            }
            if (c == '<') {
                analyze_const(s);
                s = null;
                if (i + 1 < keyword.length() && keyword.charAt(i + 1) == '=') {
                    i++;
                    tokens.add(new Token(Token.Type.LEQ,line,"<="));
                    continue;
                }
                tokens.add(new Token(Token.Type.LSS,line,String.valueOf(c)));
                continue;
            }
            if (c == '>') {
                analyze_const(s);
                s = null;
                if (i + 1 < keyword.length() && keyword.charAt(i + 1) == '=') {
                    i++;
                    tokens.add(new Token(Token.Type.GEQ,line,">="));
                    continue;
                }
                tokens.add(new Token(Token.Type.GRE,line,String.valueOf(c)));
                continue;
            }
            if (c == ';') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.SEMICN,line,String.valueOf(c)));
                continue;
            }
            if (c == ',') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.COMMA,line,String.valueOf(c)));
                continue;
            }
            if (c == '(') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.LPARENT,line,String.valueOf(c)));
                continue;
            }
            if (c == ')') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.RPARENT,line,String.valueOf(c)));
                continue;
            }

            if (c == '[') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.LBRACK,line,String.valueOf(c)));
                continue;
            }
            if (c == ']') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.RBRACK,line,String.valueOf(c)));
                continue;
            }
            if (c == '{') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.LBRACE,line,String.valueOf(c)));
                continue;
            }
            if (c == '}') {
                analyze_const(s);
                s = null;
                tokens.add(new Token(Token.Type.RBRACE,line,String.valueOf(c)));
                continue;
            }
            if (c == '|') {
                if (i + 1 < keyword.length() && keyword.charAt(i + 1) == '|') {
                    i++;
                    analyze_const(s);
                    s = null;
                    tokens.add(new Token(Token.Type.OR,line,"||"));
                    continue;
                }
                else {
                    analyze_const(s);
                    s = null;
                    tokens.add(new Token(Token.Type.OR,line,"|"));
                }
                Error error = new Error(this.line,'a');
                ErrorList.addError(error);
                continue;
            }
            if (c == '&') {
                if (i + 1 < keyword.length() && keyword.charAt(i + 1) == '&') {
                    i++;
                    analyze_const(s);
                    s = null;
                    tokens.add(new Token(Token.Type.AND,line,"&&"));
                    continue;
                }
                else {
                    analyze_const(s);
                    s = null;
                    tokens.add(new Token(Token.Type.AND,line,"&"));
                }
                Error error = new Error(this.line,'a');
                ErrorList.addError(error);
                continue;
            }
            if (c == '\'') {
                analyze_const(s);
                s = null;
                int start = i;
                int end = i;
                i++;
                for (;i < keyword.length(); i++) {
                    if (keyword.charAt(i) == '\'' && keyword.charAt(i-1) != '\\') {
                        break;
                    }
                }
                end = i + 1;
                String charConst = keyword.substring(start, end);
                tokens.add(new Token(Token.Type.CHRCON,line,charConst));
                continue;

            }
            if (c == '\"') {
                analyze_const(s);
                s = null;
                int start = i;
                int end = i;
                i++;
                for (;i < keyword.length(); i++) {
                    if (keyword.charAt(i) == '\"' && keyword.charAt(i-1) != '\\') {
                        break;
                    }
                }
                end = i + 1;
                String charConst = keyword.substring(start, end);
                tokens.add(new Token(Token.Type.STRCON,line,charConst));
                continue;

            }
            if (c == '\n') {
                analyze_const(s);
                s = null;
                this.line++;
                continue;
            }
            if (c == '\t' || c == '\f' || c == '\b') {
                analyze_const(s);
                s = null;
                continue;
            }
            if (s == null){
                s = String.valueOf(c);
            }
            else {
                s = s + String.valueOf(c);
            }

        }
        analyze_const(s);

    }

    public void analyze_const(String keyword) {
        if (keyword == null){
            return;
        }
        if (keyword.matches("\\d+")) {
            tokens.add(new Token(Token.Type.INTCON,line,keyword));
        }
        else {
            if (analyze_keyword(keyword)) {
                return;
            }
            tokens.add(new Token(Token.Type.IDENFR,line,keyword));
        }
    }

    public Lexer(String input) {
        init_keyword();
        analyze_string(input);
    }

    public void print() throws IOException {
        FileWriter writer = new FileWriter("lexer.txt");
        if (ErrorList.hasErrors()) {
            ErrorList.printErrors();
        }
        else {
            for (Token token : tokens) {
                writer.write(token.getType() + " " + token.getContent() + "\n");
            }
        }
        writer.close();
    }

}
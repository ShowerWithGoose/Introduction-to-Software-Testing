package frontend;

import java.io.*;
import java.util.ArrayList;

public class Lexer {
    public enum Type {
        IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK,
        IFTK, ELSETK, NOT, AND, OR, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS,
        MINU, VOIDTK, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, SEMICN, COMMA,
        LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE
    }
    
    private ArrayList<Type> types = new ArrayList<>();
    private ArrayList<String> contents = new ArrayList<>();
    private ArrayList<Integer> LexerLine = new ArrayList<>();
    private ArrayList<Integer> errorLine = new ArrayList<>();
    private ArrayList<Character> errorType = new ArrayList<>();
    private int lineNum;
    private boolean isError;
    private boolean ifJump2NextLine;
    private boolean ifLook4End;
    private int position = 0;
    
    public Lexer(BufferedReader bufferedReader) {
        isError = false;
        ifJump2NextLine = false;
        ifLook4End = false;
        lineNum = 0;
        String line;
        try {
            while (((line = bufferedReader.readLine()) != null)) {
                lineNum++;
//                if (!types.isEmpty()) {
//                    System.out.println(contents.get(contents.size() - 1) + " * " + lineNum); ///////////////////
//                }
                
                if (ifLook4End) {
                    if (line.contains("*/")) {
                        ifLook4End = false;
                    }
                    continue;
                }
                int pos;
                for (pos = 0; pos < line.length(); pos++) {
                    if (line.charAt(pos) == '_') {
                        pos = IdentLexer(pos, line);
                        LexerLine.add(lineNum);
                    } else if (line.charAt(pos) >= '0' && line.charAt(pos) <= '9') {
                        pos = IntConstLexer(pos, line);
                        LexerLine.add(lineNum);
                    } else if (line.charAt(pos) == '"') {
                        pos = StringConstLexer(pos, line);
                        LexerLine.add(lineNum);
                    } else if (line.charAt(pos) == '\'') {
                        pos = CharConstLexer(pos, line);
                        LexerLine.add(lineNum);
                    } else if (Character.isLetter(line.charAt(pos))) {
                        pos = LetterLexer(pos, line);
                        LexerLine.add(lineNum);
                    } else if (line.charAt(pos) == ' ' || line.charAt(pos) == '\t') {
                        continue;
                    } else {
                        pos = OtherLexer(pos, line);
                        if (ifJump2NextLine) {
                            ifJump2NextLine = false;
                            break;
                        } else if (ifLook4End) {
                            if (line.contains("*/")) {
                                ifLook4End = false;
                            }
                            break;
                        }
                        LexerLine.add(lineNum);
                    }
                }
                if (isError) {
                    errorLine.add(lineNum);
                    errorType.add('a');
                }
                isError = false;
            }
            
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    
    public int IdentLexer(int pos, String line) {
        StringBuilder sb = new StringBuilder();
        int i;
        for (i = pos; i < line.length() && (isNonDigit(line.charAt(i)) ||
                isDigital(line.charAt(i))); i++) {
            sb.append(line.charAt(i));
        }
        types.add(Type.IDENFR);
        contents.add(sb.toString());
        return i-1;
    }
    
    public int IntConstLexer(int pos, String line) {
        StringBuilder sb = new StringBuilder();
        if (line.charAt(pos) == '0') {
            sb.append('0');
            types.add(Type.INTCON);
            contents.add(sb.toString());
            return pos;
        } else {
            int i;
            for (i = pos; i < line.length() && line.charAt(i) >= '0' && line.charAt(i) <= '9'; i++) {
                sb.append(line.charAt(i));
            }
            types.add(Type.INTCON);
            contents.add(sb.toString());
            return i-1;
        }
    }
    
    public int StringConstLexer(int pos, String line) {
        StringBuilder sb = new StringBuilder();
        sb.append('"');
        int i;
        for (i = pos + 1; i < line.length() && line.charAt(i) != '"'; i++) {
            sb.append(line.charAt(i));
        }
        sb.append('"');
        types.add(Type.STRCON);
        contents.add(sb.toString());
        return i;
    }
    
    public int CharConstLexer(int pos, String line) {
        StringBuilder sb = new StringBuilder();
        sb.append('\'');
        int i;
        for (i = pos + 1; i < line.length() && line.charAt(i) != '\''; i++) {
            sb.append(line.charAt(i));
        }
        if (line.charAt(pos + 2) == '\'' && line.charAt(pos + 3) == '\'') {
            sb.append('\'');
            i++;
        }
        sb.append('\'');
        types.add(Type.CHRCON);
        contents.add(sb.toString());
        return i;
    }
    
    public int LetterLexer(int pos, String line) {
        StringBuilder sb = new StringBuilder();
        int i;
        for (i = pos; i < line.length() && (Character.isLetter(line.charAt(i))
                || Character.isDigit(line.charAt(i)) || line.charAt(i) == '_'); i++) {
            sb.append(line.charAt(i));
        }
        contents.add(sb.toString());
        switch (sb.toString()) {
            case "main":
                types.add(Type.MAINTK);
                break;
            case "const":
                types.add(Type.CONSTTK);
                break;
            case "int":
                types.add(Type.INTTK);
                break;
            case "char":
                types.add(Type.CHARTK);
                break;
            case "break":
                types.add(Type.BREAKTK);
                break;
            case "continue":
                types.add(Type.CONTINUETK);
                break;
            case "if":
                types.add(Type.IFTK);
                break;
            case "else":
                types.add(Type.ELSETK);
                break;
            case "for":
                types.add(Type.FORTK);
                break;
            case "getint":
                types.add(Type.GETINTTK);
                break;
            case "getchar":
                types.add(Type.GETCHARTK);
                break;
            case "printf":
                types.add(Type.PRINTFTK);
                break;
            case "return":
                types.add(Type.RETURNTK);
                break;
            case "void":
                types.add(Type.VOIDTK);
                break;
            default:
                types.add(Type.IDENFR);
                break;
        }
        return i-1;
    }
    
    public int OtherLexer(int pos, String line) {
        int i = pos;
        switch (line.charAt(pos)) {
            case '!':
                if (line.charAt(pos + 1) == '=') {
                    types.add(Type.NEQ);
                    contents.add("!=");
                    i++;
                } else {
                    types.add(Type.NOT);
                    contents.add("!");
                }
                break;
            case '&':
                if (line.charAt(pos + 1) == '&') {
                    types.add(Type.AND);
                    contents.add("&&");
                    i++;
                } else {
                    types.add(Type.AND);
                    contents.add("&&");
                    setError();
                }
                break;
            case '|':
                if (line.charAt(pos + 1) == '|') {
                    types.add(Type.OR);
                    contents.add("||");
                    i++;
                } else {
                    types.add(Type.OR);
                    contents.add("||");
                    setError();
                }
                break;
            case '+':
                types.add(Type.PLUS);
                contents.add("+");
                break;
            case '-':
                types.add(Type.MINU);
                contents.add("-");
                break;
            case '*':
                types.add(Type.MULT);
                contents.add("*");
                break;
            case '/':
                if (line.charAt(pos + 1) == '/') {
                    jump2NextLine();
                    i++;
                } else if (line.charAt(pos + 1) == '*') {
                    look4End();
                    i++;
                } else {
                    types.add(Type.DIV);
                    contents.add("/");
                }
                break;
            case '%':
                types.add(Type.MOD);
                contents.add("%");
                break;
            case '<':
                if (line.charAt(pos + 1) == '=') {
                    types.add(Type.LEQ);
                    contents.add("<=");
                    i++;
                } else {
                    types.add(Type.LSS);
                    contents.add("<");
                }
                break;
            case '>':
                if (line.charAt(pos + 1) == '=') {
                    types.add(Type.GEQ);
                    contents.add(">=");
                    i++;
                } else {
                    types.add(Type.GRE);
                    contents.add(">");
                }
                break;
            case '=':
                if (line.charAt(pos + 1) == '=') {
                    types.add(Type.EQL);
                    contents.add("==");
                    i++;
                } else {
                    types.add(Type.ASSIGN);
                    contents.add("=");
                }
                break;
            case ';':
                types.add(Type.SEMICN);
                contents.add(";");
                break;
            case ',':
                types.add(Type.COMMA);
                contents.add(",");
                break;
            case '(':
                types.add(Type.LPARENT);
                contents.add("(");
                break;
            case ')':
                types.add(Type.RPARENT);
                contents.add(")");
                break;
            case '[':
                types.add(Type.LBRACK);
                contents.add("[");
                break;
            case ']':
                types.add(Type.RBRACK);
                contents.add("]");
                break;
            case '{':
                types.add(Type.LBRACE);
                contents.add("{");
                break;
            case '}':
                types.add(Type.RBRACE);
                contents.add("}");
                break;
            default:
                break;
        }
        return i;
    }
    
    public boolean isNonDigit(char c) {
        return (c == '_') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    
    public boolean isDigital(char c) {
        return (c >= '0' && c <= '9');
    }
    
    public void setError() {
        isError = true;
    }
    
    private void jump2NextLine() {
        ifJump2NextLine = true;
    }
    
    public void look4End() {
        ifLook4End = true;
    }
    
    public void print() {
        try {
            System.out.println("当前工作目录：" + new File(".").getAbsolutePath());
            if (errorLine.isEmpty()) {
                FileWriter fileWriter = new FileWriter("./lexer.txt");
                BufferedWriter writer = new BufferedWriter(fileWriter);
                for (int i = 0; i < types.size(); i++) {
                    writer.write(types.get(i).name());
                    writer.write(" ");
                    writer.write(contents.get(i));
                    writer.write(" ");
                    writer.write(LexerLine.get(i).toString());
                    writer.newLine(); // 写入一个新行字符
                }
                writer.close();
            } else {
                FileWriter fileWriter = new FileWriter("./error.txt");
                BufferedWriter writer = new BufferedWriter(fileWriter);
                for (int i = 0; i < errorLine.size(); i++) {
                    writer.write(errorLine.get(i).toString());
                    writer.write(" ");
                    writer.write(errorType.get(i));
                    writer.newLine();
                }
                writer.close();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    
    public void move() {
        position++;
    }
    
    public void back() {
        position--;
    }
    
    public String getContent() {
        return contents.get(position);
    }
    
    public Type getType() {
        return types.get(position);
    }
    
    public Type getType(int i) {
        return types.get(position+i);
    }
    
    public Integer getLine() {
        return LexerLine.get(position);
    }
    
    public ArrayList<Character> getErrorType() {
        return errorType;
    }
    
    public ArrayList<Integer> getErrorLine() {
        return errorLine;
    }
    
    public int getPosition() {
        return position;
    }
    
    public void setPosition(int pos) {
        position = pos;
    }
}

package frontend.lexer;

import frontend.error.Error;
import frontend.error.ErrorProcess;
import frontend.lexer.Token;

import java.io.*;
import java.util.HashMap;

public class Lexer {
    private int cnt = 0;
    private int pos = 0;
    private String line;
    private int lineNum = 1;
    private boolean isError = false;
    private int errorNum;
    private ErrorProcess errorProcess;
    private HashMap<Integer, Token> hashMap = new HashMap<>();

    public HashMap<Integer, Token> getHashMap() {
        return hashMap;
    }

    public int getCnt() {
        return cnt;
    }

    public Lexer(ErrorProcess errorProcess) {
        this.errorProcess = errorProcess;
    }

    public void outputResult() {
        BufferedWriter bufferedWriter = null;
        if (!isError) {
            try {
                bufferedWriter = new BufferedWriter(new FileWriter("lexer.txt"));
                for(int i = 0; i < this.cnt; i++) {
                    bufferedWriter.write(hashMap.get(i).getLexType()+" "+hashMap.get(i).getValue());
                    bufferedWriter.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (bufferedWriter != null) {
                    try {
                        bufferedWriter.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        } else {
            try {
                bufferedWriter = new BufferedWriter(new FileWriter("error.txt"));
                bufferedWriter.write(errorNum+" a");
                bufferedWriter.newLine();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (bufferedWriter != null) {
                    try {
                        bufferedWriter.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    public void readFile() {
        String filePath = "./testfile.txt";
        StringBuilder stringBuilder = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String curLine;
            while ((curLine = br.readLine()) != null) {
                stringBuilder.append(curLine).append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        this.line = stringBuilder.toString();
    }
    public void extractToken() {
        while (this.pos < this.line.length()) {
            this.next(errorProcess);
        }
    }

    private Token next(ErrorProcess errorProcess) {
        Token token;
        while (this.pos < this.line.length()) {
            char c = this.line.charAt(this.pos);
            this.pos++;
            if (Character.isWhitespace(c)) {
                if (c == '\n') {
                    this.lineNum++;
                }
                continue;
            }

            if (Character.isDigit(c) && this.pos < this.line.length()) {
                int temp = this.pos - 1;
                c = this.line.charAt(this.pos);
                while (this.pos + 1 <= line.length() && Character.isDigit(c)) {
                    this.pos++;
                    c = this.line.charAt(this.pos);
                }
                String number = line.substring(temp, this.pos);
                token = new Token(LexType.INTCON, number, this.lineNum);
                this.hashMap.put(this.cnt++, token);
                return token;
            }

            switch (c) {
                case '+':
                    token = new Token(LexType.PLUS, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case '-':
                    token = new Token(LexType.MINU, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case '(':
                    token = new Token(LexType.LPARENT, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case ')':
                    token = new Token(LexType.RPARENT, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case '[':
                    token = new Token(LexType.LBRACK, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case ']':
                    token = new Token(LexType.RBRACK, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case '{':
                    token = new Token(LexType.LBRACE, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case '}':
                    token = new Token(LexType.RBRACE, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case ';':
                    token = new Token(LexType.SEMICN, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case ',':
                    token = new Token(LexType.COMMA, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case '%':
                    token = new Token(LexType.MOD, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                case '*':
                    token = new Token(LexType.MULT, Character.toString(c), this.lineNum);
                    this.hashMap.put(this.cnt++, token);
                    return token;
                default:
                    break;
            }

            if (this.pos < this.line.length() && c == '>' && this.line.charAt(this.pos) == '=') {
                token = new Token(LexType.GEQ, this.line.substring(this.pos - 1, this.pos + 1), this.lineNum);
                this.pos++;
                this.hashMap.put(this.cnt++, token);
                return token;
            } else if (c == '>') {
                token = new Token(LexType.GRE, Character.toString(c), this.lineNum);
                this.hashMap.put(this.cnt++, token);
                return token;
            }

            if (this.pos < this.line.length() && c == '<' && this.line.charAt(this.pos) == '=') {
                token = new Token(LexType.LEQ, this.line.substring(this.pos - 1, this.pos + 1), this.lineNum);
                this.pos++;
                this.hashMap.put(this.cnt++, token);
                return token;
            } else if (c == '<') {
                token = new Token(LexType.LSS, Character.toString(c), this.lineNum);
                this.hashMap.put(this.cnt++, token);
                return token;
            }

            if (this.pos < this.line.length() && c == '>' && this.line.charAt(this.pos) == '=') {
                token = new Token(LexType.GEQ, this.line.substring(this.pos - 1, this.pos + 1), this.lineNum);
                this.pos++;
                this.hashMap.put(this.cnt++, token);
                return token;
            } else if (c == '>') {
                token = new Token(LexType.GRE, Character.toString(c), this.lineNum);
                this.hashMap.put(this.cnt++, token);
                return token;
            }

            if (this.pos < this.line.length() && c == '=' && this.line.charAt(this.pos) == '=') {
                token = new Token(LexType.EQL, this.line.substring(this.pos - 1, this.pos + 1), this.lineNum);
                this.pos++;
                this.hashMap.put(this.cnt++, token);
                return token;
            } else if (c == '=') {
                token = new Token(LexType.ASSIGN, Character.toString(c), this.lineNum);
                this.hashMap.put(this.cnt++, token);
                return token;
            }

            if (this.pos < this.line.length() && c == '!' && this.line.charAt(this.pos) == '=') {
                token = new Token(LexType.NEQ, this.line.substring(this.pos - 1, this.pos + 1), this.lineNum);
                this.pos++;
                this.hashMap.put(this.cnt++, token);
                return token;
            } else if (c == '!') {
                token = new Token(LexType.NOT, Character.toString(c), this.lineNum);
                this.hashMap.put(this.cnt++, token);
                return token;
            }

            if (this.pos < this.line.length() && c == '&' && this.line.charAt(this.pos) == '&') {
                token = new Token(LexType.AND, this.line.substring(this.pos - 1, this.pos + 1), this.lineNum);
                this.pos++;
                this.hashMap.put(this.cnt++, token);
                return token;
            } else if (c == '&') {
                token = new Token(LexType.AND, Character.toString(c), this.lineNum);
                this.isError = true;
                this.errorNum = this.lineNum;
                Error error = new Error(this.lineNum, 'a');
                errorProcess.setError(error);
                this.hashMap.put(this.cnt++, token);
                return token;
            }

            if (this.pos < this.line.length() && c == '|' && this.line.charAt(this.pos) == '|') {
                token = new Token(LexType.OR, this.line.substring(this.pos - 1, this.pos + 1), this.lineNum);
                this.pos++;
                this.hashMap.put(this.cnt++, token);
                return token;
            } else if (c == '|') {
                token = new Token(LexType.OR, Character.toString(c), this.lineNum);
                this.isError = true;
                this.errorNum = this.lineNum;
                Error error = new Error(this.lineNum, 'a');
                errorProcess.setError(error);
                this.hashMap.put(this.cnt++, token);
                return token;
            }

            if (this.pos < this.line.length() && c == '/' && this.line.charAt(this.pos) == '/') {
                this.pos++;
                while (this.pos < this.line.length()) {
                    c = this.line.charAt(this.pos);
                    this.pos ++;
                    if (c == '\n') {
                        this.lineNum++;
                        break;
                    }
                }
            } else if (this.pos < this.line.length() && c == '/' && this.line.charAt(this.pos) == '*') {
                this.pos++;
                while (this.pos < this.line.length()) {
                    c = this.line.charAt(this.pos);
                    this.pos ++;
                    if (c == '\n') {
                        this.lineNum++;
                    }
                    if (c == '*' && this.line.charAt(this.pos) == '/') {
                        this.pos++;
                        break;
                    }
                }
            }  else if (c == '/') {
                token = new Token(LexType.DIV, Character.toString(c), this.lineNum);
                this.hashMap.put(this.cnt++, token);
                return token;
            }

            if (c == '\"') {
                int temp = this.pos - 1;
                while (this.pos < this.line.length()) {
                    if (c == '\\' && this.pos + 1 < this.line.length()) {
                        this.pos++;
                    }
                    c = this.line.charAt(this.pos);
                    this.pos++;
                    if (c == '\"') {
                        token = new Token(LexType.STRCON, this.line.substring(temp, this.pos), this.lineNum);
                        this.hashMap.put(this.cnt++, token);
                        return token;
                    }
                }
            }

            if (c == '\'') {
                int temp = this.pos - 1;
                while (this.pos < this.line.length()) {
                    if (c == '\\' && this.pos + 1 < this.line.length()) {
                        this.pos++;
                    }
                    c = this.line.charAt(this.pos);
                    this.pos++;
                    if (c == '\'') {
                        token = new Token(LexType.CHRCON, this.line.substring(temp, this.pos), this.lineNum);
                        this.hashMap.put(this.cnt++, token);
                        return token;
                    }
                }
            }

            if (Character.isLetter(c) || c == '_') {
                if (this.pos + 3 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 3).equals("main") && !this.judgeIdent(this.line.charAt(this.pos + 3))) {
                    token = new Token(LexType.MAINTK, "main", this.lineNum);
                    this.pos += 3;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 4 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 4).equals("const") && !this.judgeIdent(this.line.charAt(this.pos + 4))) {
                    token = new Token(LexType.CONSTTK, "const", this.lineNum);
                    this.pos += 4;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 2 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 2).equals("int") && !this.judgeIdent(this.line.charAt(this.pos + 2))) {
                    token = new Token(LexType.INTTK, "int", this.lineNum);
                    this.pos += 2;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 3 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 3).equals("char") && !this.judgeIdent(this.line.charAt(this.pos + 3))) {
                    token = new Token(LexType.CHARTK, "char", this.lineNum);
                    this.pos += 3;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 4 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 4).equals("break") && !this.judgeIdent(this.line.charAt(this.pos + 4))) {
                    token = new Token(LexType.BREAKTK, "break", this.lineNum);
                    this.pos += 4;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 7 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 7).equals("continue") && !this.judgeIdent(this.line.charAt(this.pos + 7))) {
                    token = new Token(LexType.CONTINUETK, "continue", this.lineNum);
                    this.pos += 7;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 1 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 1).equals("if") && !this.judgeIdent(this.line.charAt(this.pos + 1))) {
                    token = new Token(LexType.IFTK, "if", this.lineNum);
                    this.pos += 1;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 3 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 3).equals("else") && !this.judgeIdent(this.line.charAt(this.pos + 3))) {
                    token = new Token(LexType.ELSETK, "else", this.lineNum);
                    this.pos += 3;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 2 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 2).equals("for") && !this.judgeIdent(this.line.charAt(this.pos + 2))) {
                    token = new Token(LexType.FORTK, "for", this.lineNum);
                    this.pos += 2;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 5 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 5).equals("getint") && !this.judgeIdent(this.line.charAt(this.pos + 5))) {
                    token = new Token(LexType.GETINTTK, "getint", this.lineNum);
                    this.pos += 5;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 6 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 6).equals("getchar") && !this.judgeIdent(this.line.charAt(this.pos + 6))) {
                    token = new Token(LexType.GETCHARTK, "getchar", this.lineNum);
                    this.pos += 6;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 5 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 5).equals("printf") && !this.judgeIdent(this.line.charAt(this.pos + 5))) {
                    token = new Token(LexType.PRINTFTK, "printf", this.lineNum);
                    this.pos += 5;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 5 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 5).equals("return") && !this.judgeIdent(this.line.charAt(this.pos + 5))) {
                    token = new Token(LexType.RETURNTK, "return", this.lineNum);
                    this.pos += 5;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                } else if (this.pos + 3 <= this.line.length() && this.line.substring(this.pos - 1, this.pos + 3).equals("void") && !this.judgeIdent(this.line.charAt(this.pos + 3))) {
                    token = new Token(LexType.VOIDTK, "void", this.lineNum);
                    this.pos += 3;
                    this.hashMap.put(this.cnt++, token);
                    return token;
                }

                int temp = this.pos - 1;
                c = this.line.charAt(this.pos);
                while (this.judgeIdent(c) && this.pos + 1 < this.line.length()) {
                    this.pos++;
                    c = this.line.charAt(this.pos);
                }
                token = new Token(LexType.IDENFR, this.line.substring(temp, this.pos), this.lineNum);
                this.hashMap.put(this.cnt++, token);
                return token;
            }
        }
        return null;
    }

    private boolean judgeIdent(char c) {
        if (Character.isLetter(c) || Character.isDigit(c) || c == '_') {
            return true;
        }
        return false;
    }
}

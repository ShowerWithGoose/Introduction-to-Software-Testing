package frontend.Lexer;

import frontend.Error.ErrorManager;
import frontend.Error.ErrorToken;
import frontend.Error.ErrorType;
import frontend.IOManager;
import frontend.Utils;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.*;

public class Lexer
{
    //<editor-fold> desc="单例模式"
    private static final Lexer instance = new Lexer();

    private Lexer() {
    }

    public static Lexer GetLexer() {
        return instance;
    }
    //</editor-fold>

    //<editor-fold> desc="初始化Map"

    private void InitReservedWords() {
        reservedWords = new HashMap<>()
        {
            {
                put("main", TokenType.MainTk);
                put("const", TokenType.ConstTk);
                put("int", TokenType.IntTk);
                put("char", TokenType.CharTk);
                put("void", TokenType.VoidTk);
                put("break", TokenType.BreakTk);
                put("continue", TokenType.ContinueTk);
                put("if", TokenType.IfTk);
                put("else", TokenType.ElseTk);
                put("for", TokenType.ForTk);
                put("getint", TokenType.GetIntTk);
                put("getchar", TokenType.GetCharTk);
                put("printf", TokenType.PrintfTk);
                put("return", TokenType.ReturnTk);
            }
        };
    }

    private void InitCharWords() {
        charWords = new HashMap<>()
        {
            {
                put("+", TokenType.PlusTk);
                put("-", TokenType.MinusTk);
                put("*", TokenType.MulTk);
                put("%", TokenType.ModTk);
                put("/", TokenType.DivTk);
                put("<", TokenType.LessTk);
                put(">", TokenType.GreaterTk);
                put("<=", TokenType.LessEqTk);
                put(">=", TokenType.GreaterEqTk);
                put("==", TokenType.EqualTk);
                put("!=", TokenType.NotEqualTk);
                put("=", TokenType.AssignTk);
                put(";", TokenType.Semicolon);
                put(",", TokenType.Comma);
                put("(", TokenType.LParent);
                put(")", TokenType.RParent);
                put("[", TokenType.LBracket);
                put("]", TokenType.RBracket);
                put("{", TokenType.LBrace);
                put("}", TokenType.RBrace);
                put("!", TokenType.NotTk);
                put("&&", TokenType.AndTk);
                put("||", TokenType.OrTk);
            }
        };
    }

    //</editor-fold>

    //<editor-fold> desc="属性"
    private BufferedReader source;
    private String string;
    private int pos;
    private int lineNo;
    private Token token;
    private Map<String, TokenType> reservedWords;
    private Map<String, TokenType> charWords;
    private TokenType tokenType;
    private List<Token> tokens;

    //</editor-fold>

    public List<Token> getTokens() {return tokens;}

    public void Init() {
        this.source = IOManager.reader;
        pos = 0;
        lineNo = 0;
        tokens = new LinkedList<>();
        InitReservedWords();
        InitCharWords();
    }

    public int Next() throws IOException {
        pos++;
        if (string == null || pos >= string.length()) {
            ReadLine();
        }
        if (string == null) {
            //又读一行，为空，则已到文末
            return -1;
        }
        if (string.isEmpty()) {
            //空行，置为空，继续读
            while(string.isEmpty()){
                ReadLine();
                if(string == null){
                    break;
                }
            }
            pos--;
            return Next();
        }
        char c = string.charAt(pos);
        if (Utils.IsNonDigit(c)) {
            //是字母、下划线
            //标识符或关键字
            ProcessIdentOrReserved();
            return 0;
        }
        else if (Character.isDigit(c)) {
            //是数字
            ProcessInt();
            return 0;
        }
        else if (c == '\'') {
            //是单引号，单字符
            ProcessChar();
            return 0;
        }
        else if (c == '\"') {
            //是双引号，字符串
            ProcessString();
            return 0;
        }
        else if (c == '/') {
            // 处理注释/ 除号
            if (!ProcessNotesOrDiv()) {
                return 0;
            }
            else {
                return Next();
            }
        }
        else if (c == ' ' || c == '\t') {
            while(pos < string.length() && (string.charAt(pos) == ' ' || string.charAt(pos) == '\t')) {
                pos ++;
            }
            if(pos < string.length()){
                pos --;
            }
            return Next();
        }
        else {
            //处理符号
            ProcessCharacter();
            return 0;
        }
    }

    private void ProcessIdentOrReserved() {
        StringBuilder tempToken = new StringBuilder();
        char c = string.charAt(pos);
        tempToken.append(c);
        pos++;
        while (pos < string.length() &&
                (Utils.IsNonDigit(string.charAt(pos)) || Character.isDigit(string.charAt(pos)))) {
            //是数字、字母、下划线
            c = string.charAt(pos);
            tempToken.append(c);
            pos++;
        }
        if (pos < string.length()) {
            pos--;
        }
        String temp = tempToken.toString();
        tokenType = reservedWords.getOrDefault(temp, TokenType.Ident);
        token = new Token(tokenType, temp, lineNo);
    }

    private void ProcessInt() {
        StringBuilder tempToken = new StringBuilder();
        char c = string.charAt(pos);
        tempToken.append(c);
        pos++;
        while (pos < string.length() && Character.isDigit(string.charAt(pos))) {
            c = string.charAt(pos);
            tempToken.append(c);
            pos++;
        }
        if (pos < string.length()) {
            pos--;
        }
        String temp = tempToken.toString();
        tokenType = TokenType.IntConst;
        token = new Token(tokenType, temp, lineNo);
    }

    private void ProcessChar() {
        StringBuilder tempToken = new StringBuilder();
        char c = string.charAt(pos);
        tempToken.append(c);
        pos++;
        boolean alter = false;
        while (pos < string.length()) {
            c = string.charAt(pos);
            tempToken.append(c);
            if(alter){
                alter = false;
            }
            else{
                if(c == '\''){
                    break;
                }
                else if (c == '\\') {
                    alter = true;
                }
            }
            pos++;
        }
        tokenType = TokenType.CharConst;
        token = new Token(tokenType, tempToken.toString(), lineNo);
    }

    private void ProcessString() {
        StringBuilder tempToken = new StringBuilder();
        char c = string.charAt(pos);
        tempToken.append(c);
        pos++;
        while (pos < string.length()) {
            c = string.charAt(pos);
            tempToken.append(c);
            if (c == '\"') {
                break;
            }
            pos++;
        }
        tokenType = TokenType.StringConst;
        token = new Token(tokenType, tempToken.toString(), lineNo);
    }

    private boolean ProcessNotesOrDiv() throws IOException {
        pos++;
        if (pos < string.length() && string.charAt(pos) == '/') {
            //是单行注释
            string = null;
            return true;
        }
        else if (pos < string.length() && string.charAt(pos) == '*') {
            //是多行注释
            pos++;
            boolean flag = false;
            while (string != null) {
                if (pos < string.length()) {
                    char ch = string.charAt(pos);
                    if (ch == '*') {
                        flag = true;
                    }
                    else if (flag && ch == '/') {
                        return true;
                    }
                    else {
                        flag = false;
                    }
                    pos++;
                }
                else {
                    ReadLine();
                }
            }
            return true;
        }
        else {
            pos--;
            tokenType = TokenType.DivTk;
            token = new Token(tokenType, "/", lineNo);
            return false;
        }
    }

    private void ProcessCharacter() {
        StringBuilder tempToken = new StringBuilder();
        char c = string.charAt(pos);
        tempToken.append(c);
        if (c == '&' || c == '|') {
            char r = c;
            pos++;
            c = string.charAt(pos);
            if (c == r) {
                tempToken.append(r);
            }
            else {
                ErrorManager errorManager = ErrorManager.GetInstance();
                errorManager.setError(true);
                ErrorToken errorToken = new ErrorToken(tempToken.toString(), lineNo, ErrorType.IllegalCharacter);
                errorManager.addError(errorToken);
                pos--;
                tempToken.append(tempToken.charAt(0));
            }
        }
        else if (c == '>' || c == '<' || c == '=' || c == '!') {
            pos++;
            if(pos < string.length()){
                c = string.charAt(pos);
                if (c == '=') {
                    tempToken.append(c);
                }
                else {
                    pos--;
                }
            }

        }
        String temp = tempToken.toString();
        tokenType = charWords.getOrDefault(temp, TokenType.CharConst);
        token = new Token(tokenType, temp, lineNo);
    }

    private void ReadLine() throws IOException {
        string = source.readLine();
        pos = 0;
        lineNo++;
    }

    public void PutToken() {
        tokens.add(token);
    }

    public void PrintTokens(BufferedWriter bw) throws IOException {
        for (Token token : tokens) {
            bw.write(token.toString());
            bw.newLine();
//            System.out.println(token.toString());
        }
    }



}


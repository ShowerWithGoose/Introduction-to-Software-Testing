import java.io.*;
import java.util.*;

/**
 * Classname Lexer
 * Description TODO
 * Date 2024/10/2 22:32
 * Created ZHW
 */
public class Lexer {
    private static BufferedWriter right;
    private static BufferedWriter error;
    private Token token;
    private Map<String, TokenType> keymap;
    public List<Error> errors;
    public List<Token> tokens;

    static {
        try {
            right = new BufferedWriter(new FileWriter("lexer.txt"));
            error = new BufferedWriter(new FileWriter("error.txt"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Lexer(Token token) {
        this.token = token;
        this.tokens = new ArrayList<>();
        this.errors = new ArrayList<>();
        this.keymap = createKeywordMap();
    }

    public List<Token> getTokens() {
        return tokens;
    }

    public List<Error> getErrors() {
        return errors;
    }

    private Map<String, TokenType> createKeywordMap(){
        Map<String, TokenType> mymap = new HashMap<>();
        mymap.put("main", TokenType.MAINTK);
        mymap.put("const", TokenType.CONSTTK);
        mymap.put("int", TokenType.INTTK);
        mymap.put("char", TokenType.CHARTK);
        mymap.put("break", TokenType.BREAKTK);
        mymap.put("continue", TokenType.CONTINUETK);
        mymap.put("if", TokenType.IFTK);
        mymap.put("else", TokenType.ELSETK);
        mymap.put("!", TokenType.NOT);
        mymap.put("&&", TokenType.AND);
        mymap.put("||", TokenType.OR);
        mymap.put("for", TokenType.FORTK);
        mymap.put("getint", TokenType.GETINTTK);
        mymap.put("getchar", TokenType.GETCHARTK);
        mymap.put("printf", TokenType.PRINTFTK);
        mymap.put("return", TokenType.RETURNTK);
        mymap.put("+", TokenType.PLUS);
        mymap.put("-", TokenType.MINU);
        mymap.put("void", TokenType.VOIDTK);
        mymap.put("*", TokenType.MULT);
        mymap.put("/", TokenType.DIV);
        mymap.put("%", TokenType.MOD);
        mymap.put("<", TokenType.LSS);
        mymap.put("<=", TokenType.LEQ);
        mymap.put(">", TokenType.GRE);
        mymap.put(">=", TokenType.GEQ);
        mymap.put("==", TokenType.EQL);
        mymap.put("!=", TokenType.NEQ);
        mymap.put("=", TokenType.ASSIGN);
        mymap.put(";", TokenType.SEMICN);
        mymap.put(",", TokenType.COMMA);
        mymap.put("(", TokenType.LPARENT);
        mymap.put(")", TokenType.RPARENT);
        mymap.put("[", TokenType.LBRACK);
        mymap.put("]", TokenType.RBRACK);
        mymap.put("{", TokenType.LBRACE);
        mymap.put("}", TokenType.RBRACE);

        return mymap;
    }

    // 词法分析
    public void getAllTokens() {
        while (token.curPos < token.length) {
            getNextToken();
        }

        try {
            right.close();
            error.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //分析下一个单词
    public void getNextToken() {
        token.clearToken();
        char ch;

        // 跳过空白符
        while (token.curPos < token.length && Character.isWhitespace(ch = token.source.charAt(token.curPos))) {
            if (ch == '\n') {
                token.lineNum++;
            }
            token.curPos++;
        }

        if (token.curPos >= token.length) return; // 文件末尾

        ch = token.source.charAt(token.curPos);

        // 识别标识符
        if (Character.isLetter(ch) || ch == '_') {
            while (token.curPos < token.length && (Character.isLetterOrDigit(ch) || ch == '_')) {
                token.word += ch; // 构建当前单词
                token.curPos++;
                if (token.curPos < token.length) {
                    ch = token.source.charAt(token.curPos);
                }
            }
            token.type = keymap.getOrDefault(token.word, TokenType.IDENFR);
            Token onetoken = new Token(token.word, token.type, token.lineNum);
            tokens.add(onetoken);
        }

        // 识别数字
        else if (Character.isDigit(ch)) {
            while (token.curPos < token.length && Character.isDigit(ch)) {
                token.word += ch;
                token.curPos++;
                if (token.curPos < token.length) {
                    ch = token.source.charAt(token.curPos);
                }
            }
            token.type = TokenType.INTCON;
            Token onetoken = new Token(token.word, token.type, token.lineNum);
            tokens.add(onetoken);
        }

        //识别字符
        else if (ch == '\'') {
            token.curPos++;
            token.word += "'";
            while (token.curPos < token.length) {
                ch = token.source.charAt(token.curPos);
                if (ch == '\\') {
                    token.curPos++;
                    token.word += ch;
                    token.word += Character.toString(token.source.charAt(token.curPos));
                    token.curPos++;
                    continue;
                }
                if (ch == '\'') {
                    token.word += ch;
                    token.curPos++;
                    break;
                }
                token.curPos++;
                token.word += ch;
            }
            token.type = TokenType.CHRCON;
            Token onetoken = new Token(token.word, token.type, token.lineNum);
            tokens.add(onetoken);
        }

        //识别字符串
        else if (ch == '"') {
            token.curPos++;
            token.word += '"';
            while (token.curPos < token.length) {
                ch = token.source.charAt(token.curPos);
                if (ch == '"') {
                    token.word += ch;
                    token.curPos++;
                    break;
                }
                token.curPos++;
                token.word += ch;
            }
            token.type = TokenType.STRCON;
            Token onetoken = new Token(token.word, token.type, token.lineNum);
            tokens.add(onetoken);
        }

        //其他字符
        else{
            if (ch == '>' || ch == '<' || ch == '=' || ch == '!'){
                token.word += ch;
                token.curPos++;
                checkTheNextIsEqual();
                token.type = keymap.get(token.word);
                Token onetoken = new Token(token.word, token.type, token.lineNum);
                tokens.add(onetoken);
            }

            else if (ch == '&'){
                token.curPos++;
                if (token.curPos < token.length && token.source.charAt(token.curPos) == '&') {
                    token.type = TokenType.AND;
                    token.word += "&&";
                    token.curPos++;
                    Token onetoken = new Token(token.word, token.type, token.lineNum);
                    tokens.add(onetoken);
                } else {
                    addError(token.lineNum, "a");
                    tokens.add(new Token("&&", TokenType.AND, token.lineNum));
                }
            }

            else if (ch == '|'){
                token.curPos++;
                if (token.curPos < token.length && token.source.charAt(token.curPos) == '|') {
                    token.type = TokenType.OR;
                    token.word += "||";
                    token.curPos++;
                    Token onetoken = new Token(token.word, token.type, token.lineNum);
                    tokens.add(onetoken);
                } else {
                    addError(token.lineNum, "a");
                    tokens.add(new Token("||", TokenType.OR, token.lineNum));
                }
            }

            else if (ch == '/'){
                token.curPos++;
                if (token.curPos < token.length) {
                    char nextCh = token.source.charAt(token.curPos);
                    if (nextCh == '/') {
                        // 单行注释处理
                        while (token.curPos < token.length && token.source.charAt(token.curPos) != '\n') {
                            token.curPos++;
                        }
                    }
                    else if (nextCh == '*') {
                        // 多行注释处理
                        token.curPos++;
                        while (token.curPos < token.length) {
                            char currentCh = token.source.charAt(token.curPos);
                            if (currentCh == '*' && token.curPos + 1 < token.length && token.source.charAt(token.curPos + 1) == '/') {
                                token.curPos=token.curPos+2;
                                break;
                            }
                            token.curPos++;
                        }
                    }
                    else {
                        // 处理除号
                        token.type = TokenType.DIV;
                        token.word += "/";
                        Token onetoken = new Token(token.word, token.type, token.lineNum);
                        tokens.add(onetoken);
                    }
                }
            }

            else {
                token.curPos++;
                token.word += ch;
                token.type = keymap.get(token.word);
                Token onetoken = new Token(token.word, token.type, token.lineNum);
                tokens.add(onetoken);
            }
        }
    }

    private void checkTheNextIsEqual() {
        if (token.curPos < token.length && token.source.charAt(token.curPos) == '=') {
            token.word += '=';
            token.curPos++;
        }
    }

    private void addError(int line, String message) {
        errors.add(new Error(line, message));
    }
}

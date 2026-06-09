package frontend;

import frontend.tokens.*;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Lexer {
    /**
     * source code
     */
    private final String sourceCode;
    /**
     * 当前的行数
     */
    private int line;
    /**
     * 总的字符位置
     */
    private int pos;
    /**
     * 最终目标
     */
    private final ArrayList<Token> tokens;
    /**
     * errors
     */
    private final ArrayList<Error> errors;


    public Lexer(String sourceCode, ArrayList<Error> errors) {
        this.sourceCode = sourceCode;
        this.line = 1;
        this.pos = 0;
        this.tokens = new ArrayList<>();
        this.errors = errors;
    }

    /**
     * 跑Lexer
     */
    public ArrayList<Token> lex() {
        while (pos < sourceCode.length()) {
            Token token = getToken();
            if (token != null) {
                pos += token.getContent().length();
                line += (int) token.getContent().chars().boxed().filter(c -> c == '\n').count(); // 为什么之前写的居然都能过？因为正确的程序里不需要输出line！
                if (token.getType() != TokenType.BLANK &&
                        token.getType() != TokenType.LINECOMMENT &&
                        token.getType() != TokenType.BLOCKCOMMENT) {
                    tokens.add(token);
                }
            } else {  // 这儿关于出错的情况，我只考虑了“&”和“|”这两种（毕竟评测说了就这两种错误）
                pos++;
            }
        }
        return tokens;
    }

    /**
     * 获取下一个token getToken
     */
    private Token getToken() {
        String tmp;

        // 匹配到LineComment
        if (commonMatch("//") != null) {
            int end = Token.getLineComment(sourceCode, pos);
            return new Token(sourceCode.substring(pos, end), line, TokenType.LINECOMMENT);
        }
        // 匹配到BlockComment
        if (commonMatch("/\\*") != null) {
            int end = Token.getBlockComment(sourceCode, pos);
            return new Token(sourceCode.substring(pos, end), line, TokenType.BLOCKCOMMENT);
        }

        // 匹配keyword
        String keywordPattern = "(main|const|int|char|void|break|continue|if|else|for|return|getint|getchar|printf)(?![a-zA-Z0-9_])";
        if ((tmp = groupMatch(keywordPattern)) != null) {
            return new Token(tmp, line, getTokenType(tmp));
        }

        // 匹配ident
        if ((tmp = commonMatch("[a-zA-Z_][a-zA-Z0-9_]*")) != null) {
            return new Token(tmp, line, TokenType.IDENFR);
        }

        // 匹配字符串
        // todo （这里，字符串里面会不会再有双引号啥的）
        if (commonMatch("\"") != null) {
            int end = Token.getString(sourceCode, pos);
            return new Token(sourceCode.substring(pos, end), line, TokenType.STRCON);
        }

        // 匹配字符
        if (commonMatch("'") != null) {
            int end = Token.getChar(sourceCode, pos);
            return new Token(sourceCode.substring(pos, end), line, TokenType.CHRCON);
        }

        // 匹配数字
        if ((tmp = commonMatch("[0-9]+")) != null) {
            return new Token(tmp, line, TokenType.INTCON);
        }

        // 匹配space
        if ((tmp = commonMatch("\\s+")) != null) {
            return new Token(tmp, line, TokenType.BLANK);
        }

        // 匹配delimiters NOT, AND, OR, PLUS, MINU, MULT, DIV, MOD,
        //    ASSIGN, LSS, LEQ, GRE, GEQ, EQL, NEQ,
        //    SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
        String delimiterPattern = "(<=|>=|==|!=|;|,|\\(|\\)|\\[|\\]|\\{|\\}|!|&&|\\|\\||\\+|-|\\*|/|%|=|<|>)";
        if ((tmp = groupMatch(delimiterPattern)) != null) {
            return new Token(tmp, line, getTokenType(tmp));
        }

        // 匹配错误（仅有 & 和 | 两种）
        if (commonMatch("&") != null || commonMatch("\\|") != null) {
            errors.add(new Error(line, "a"));
        }

        return null;
    }

    private TokenType getTokenType(String tokenStr) {
        return switch (tokenStr) {
            case "main" -> TokenType.MAINTK;
            case "const" -> TokenType.CONSTTK;
            case "int" -> TokenType.INTTK;
            case "char" -> TokenType.CHARTK;
            case "void" -> TokenType.VOIDTK;
            case "break" -> TokenType.BREAKTK;
            case "continue" -> TokenType.CONTINUETK;
            case "if" -> TokenType.IFTK;
            case "else" -> TokenType.ELSETK;
            case "for" -> TokenType.FORTK;
            case "return" -> TokenType.RETURNTK;
            case "getint" -> TokenType.GETINTTK;
            case "getchar" -> TokenType.GETCHARTK;
            case "printf" -> TokenType.PRINTFTK;
            case "<=" -> TokenType.LEQ;
            case ">=" -> TokenType.GEQ;
            case "==" -> TokenType.EQL;
            case "!=" -> TokenType.NEQ;
            case ";" -> TokenType.SEMICN;
            case "," -> TokenType.COMMA;
            case "(" -> TokenType.LPARENT;
            case ")" -> TokenType.RPARENT;
            case "[" -> TokenType.LBRACK;
            case "]" -> TokenType.RBRACK;
            case "{" -> TokenType.LBRACE;
            case "}" -> TokenType.RBRACE;
            case "!" -> TokenType.NOT;
            case "&&" -> TokenType.AND;
            case "||" -> TokenType.OR;
            case "+" -> TokenType.PLUS;
            case "-" -> TokenType.MINU;
            case "*" -> TokenType.MULT;
            case "/" -> TokenType.DIV;
            case "%" -> TokenType.MOD;
            case "=" -> TokenType.ASSIGN;
            case "<" -> TokenType.LSS;
            case ">" -> TokenType.GRE;
            default -> throw new IllegalArgumentException("Unknown tokenStr: " + tokenStr);
        };
    }

    private String commonMatch(String regex) {
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(sourceCode);
        // 从 index 处开始匹配，然后检验是否匹配
        if (matcher.find(pos) && matcher.start() == pos) {
            return matcher.group();
        } else {
            return null;
        }
    }

    private String groupMatch(String regex) {
        Matcher matcher = Pattern.compile(regex).matcher(sourceCode); // inputString 是要匹配的字符串
        if (matcher.find(pos) && matcher.start() == pos) {
            return matcher.group(1); // 获取第一个捕获组的内容
        }
        return null;
    }

    public String showLexerResult() {
        StringBuilder stringBuilder = new StringBuilder();
        for (Token token : tokens) {
            stringBuilder.append(token).append("\n");
        }
        return stringBuilder.toString();
    }
}

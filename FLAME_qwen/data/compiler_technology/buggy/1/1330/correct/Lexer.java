
import java.util.*;

public class Lexer {
    private String source;
    private int curPos = 0;
    private int length;
    private int lineNum=1;
    private List<Token> tokenList;
    private List<Error>  errorList;


    public Lexer(String source) {
        this.source = source;
        this.length = source.length();
        this.tokenList = new ArrayList<>();
        this.errorList = new ArrayList<>();
    }

    // 词法分析
    public void lex() {
        while (curPos < length) {
            getNextToken();
        }
    }

    // 获取下一个单词
    public void getNextToken() {
        Token token=new Token();
        char ch;

        // 跳过空白符
        while (curPos < length && Character.isWhitespace(ch =source.charAt(curPos))) {
            if (ch == '\n') {
                lineNum++;
            }
           curPos++;
        }

        if (curPos >= length) return;
        ch = source.charAt(curPos);

        // 识别标识符
        if (Character.isLetter(ch) || ch == '_') {
            handleIdentifierOrKeyword(ch, token); // 修改此行
        }

        //识别数字
        else if (Character.isDigit(ch)) {
            handleNumber(ch,token);
        }

        //识别字符常量
        else if (ch == '\'') {
            handleCharacterConstant(ch,token);
        }

        //处理字符串常量
        else if (ch == '"') {
            handleStringConstant(ch,token);
        }

        // 处理其他字符
        else {
            Error error=new Error();
            handleOtherCharacters(ch,token,error);
        }
    }

    // 识别标识符
    private void handleIdentifierOrKeyword(char ch,Token token) {
        StringBuilder word = new StringBuilder();
        while (curPos < length && (Character.isLetterOrDigit(ch) || ch == '_')) {
            word.append(ch) ;
            curPos++;
            if (curPos < length) {
                ch = source.charAt(curPos);
            }
        }
        token.setWord(word.toString());
        token.setType(isReserveWord(token.getWord()) ? TokenType.valueOf(token.getWord().toUpperCase() + "TK") : TokenType.IDENFR);
        token.setLineNum(lineNum);
        tokenList.add(token);
    }

    //识别数字
    private void handleNumber(char ch,Token token) {
        StringBuilder word = new StringBuilder();
        while (curPos < length && Character.isDigit(ch)) {
            word.append(ch);
            curPos++;
            if (curPos < length) {
                ch = source.charAt(curPos);
            }
        }
        token.setWord(word.toString());
        token.setType( TokenType.INTCON);
        token.setLineNum(lineNum);
        tokenList.add(token);
    }

    //识别字符常量
    private void handleCharacterConstant(char ch,Token token) {
        StringBuilder word = new StringBuilder();
        curPos++;
        word.append("'");

        if (curPos < length) {
            ch = source.charAt(curPos);

            if (ch == '\\') {
                curPos++;
                if (curPos < length) {
                    String escapeSeq = handleEscapeCharacter(source.charAt(curPos));
                    if (escapeSeq != null) {
                        word.append(escapeSeq);
                    }
                }
            } else {
                word.append(ch);
            }
            curPos++;
            if (curPos < length && source.charAt(curPos) == '\'') {
                word.append("'");
                curPos++;
                token.setWord(word.toString());
                token.setType(TokenType.CHRCON);
                token.setLineNum(lineNum);
                tokenList.add(token);
            }
        }
    }

    //识别字符串常量
    private void handleStringConstant(char ch,Token token) {
        StringBuilder word = new StringBuilder();
        curPos++;
        word.append('"');

        while (curPos < length) {
            ch = source.charAt(curPos);
            if (ch == '"') {
                word.append('"');
                curPos++;
                token.setWord(word.toString());
                token.setType(TokenType.STRCON);;
                token.setLineNum(lineNum);
                tokenList.add(token);
                return;
            }
            if (ch == '\\') {
                curPos++;
                if (curPos < length) {
                    String escapeSeq = handleEscapeCharacter(source.charAt(curPos));
                    if (escapeSeq != null) {
                        word.append(escapeSeq);
                    }
                }
            } else {
                word.append(ch);
            }
            curPos++;
        }
    }

    //识别其它字符
    private void handleOtherCharacters(char ch,Token token,Error error) {
        switch (ch) {
            case '+': token. setType(TokenType.PLUS); token.setWord("+");curPos++;break;
            case '-': token. setType(TokenType.MINU) ;token.setWord("-"); curPos++;break;
            case '*': token. setType(TokenType.MULT);token.setWord("*"); curPos++;break;
            case '%': token. setType( TokenType.MOD); token.setWord("%") ;curPos++;break;
            case ';': token. setType(TokenType.SEMICN);token.setWord(";") ;curPos++;break;
            case ',': token. setType(TokenType.COMMA); token.setWord(",");curPos++;break;
            case '(': token. setType(TokenType.LPARENT);token.setWord("(") ;curPos++;break;
            case ')': token. setType(TokenType.RPARENT);token.setWord(")");curPos++;break;
            case '[': token. setType(TokenType.LBRACK);token.setWord("[") ; curPos++;break;
            case ']': token. setType(TokenType.RBRACK); token.setWord("]");curPos++;break;
            case '{': token. setType(TokenType.LBRACE);token.setWord("{"); curPos++;break;
            case '}': token. setType(TokenType.RBRACE); token.setWord("}") ;curPos++;break;
            case '/':
                curPos++;
                if (curPos < length) {
                    char nextCh = source.charAt(curPos);
                    if (nextCh == '/') {
                        // 单行注释处理
                        while (curPos <length && source.charAt(curPos) != '\n') {
                            curPos++;
                        }
                    }
                    else if (nextCh == '*') {
                        // 多行注释处理
                        curPos++;
                        while (curPos < length) {
                            char currentCh = source.charAt(curPos);
                            if (currentCh == '\n') {
                                lineNum++;
                            }
                            if (currentCh == '*' && curPos + 1 < length && source.charAt(curPos + 1) == '/') {
                                curPos=curPos+2;
                                break;
                            }
                            curPos++;
                        }
                    }
                    else {
                        // 处理除号
                        token.setType(TokenType.DIV);
                        token.setWord("/");
                    }
                }
                break;
            case '<':
                curPos++;
                if (curPos < length && source.charAt(curPos) == '=') {
                    token.setType(TokenType.LEQ);
                    token.setWord("<=");
                    curPos++;
                } else {
                    token.setType(TokenType.LSS);
                    token.setWord("<");
                }
                break;
            case '>':
                curPos++;
                if (curPos < length && source.charAt(curPos) == '=') {
                    token.setType(TokenType.GEQ);
                    token.setWord(">=");
                    curPos++;
                } else {
                    token.setType(TokenType.GRE);
                    token.setWord(">");
                }
                break;
            case '=':
                curPos++;
                if (curPos < length && source.charAt(curPos) == '=') {
                    token.setType(TokenType.EQL);
                    token.setWord("==");
                    curPos++;
                } else {
                    token.setType(TokenType.ASSIGN);
                    token.setWord("=");
                }
                break;
            case '!':
                curPos++;
                if (curPos < length &&source.charAt(curPos) == '=') {
                    token.setType(TokenType.NEQ);
                    token.setWord("!=");
                    curPos++;
                } else {
                    token.setType(TokenType.NOT);
                    token.setWord( "!");
                }
                break;
            case '&':
                curPos++;
                if (curPos < length && source.charAt(curPos) == '&') {
                    token.setType(TokenType.AND);
                    token.setWord("&&");
                    curPos++;
                } else {
                    token.setType(TokenType.AND);
                    token.setWord("&&");
                    error.setLineNum(lineNum);
                    error.setMessage("a");
                    errorList.add(error);
                }
                break;
            case '|':
                curPos++;
                if (curPos < length && source.charAt(curPos) == '|') {
                    token.setType(TokenType.OR);
                    token.setWord("||");
                    curPos++;
                } else {
                    token.setType(TokenType.OR);
                    token.setWord("||");
                    error.setLineNum(lineNum);
                    error.setMessage("a");
                    errorList.add(error);
                }
                break;
            default:
                break;
        }
        if(token.getType()!=null) {
            token.setLineNum(lineNum);
            tokenList.add(token);
        }
    }

    // 判断是否为关键字
    private static final Set<String> RESERVED_WORDS = new HashSet<>(Arrays.asList(
            "main", "const", "int", "char", "break", "continue", "if", "else", "for",
            "getint", "getchar", "printf", "return", "void"
    ));

    private boolean isReserveWord(String word) {
        return RESERVED_WORDS.contains(word);
    }

    //转义字符部分
    private String handleEscapeCharacter(char ch) {
        switch (ch) {
            case 'n': return "\\n";
            case 't': return "\\t";
            case 'b': return "\\b";
            case 'f': return "\\f";
            case 'r': return "\\r";
            case 'a': return "\\a";
            case 'v': return "\\v";
            case '\'': return "\\'";
            case '\"': return "\\\"";
            case '\\': return "\\\\";
            case '0': return "\\0";
            default: return null;
        }
    }

    public String getSource() {
        return source;
    }

    public void setSource(String source) {
        this.source = source;
    }

    public int getCurPos() {
        return curPos;
    }

    public void setCurPos(int curPos) {
        this.curPos = curPos;
    }

    public int getLength() {
        return length;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public int getLineNum() {
        return lineNum;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }

    public List<Token> getTokenList() {
        return tokenList;
    }

    public void setTokenList(List<Token> tokenList) {
        this.tokenList = tokenList;
    }

    public List<Error> getErrorList() {
        return errorList;
    }

    public void setErrorList(List<Error> errorList) {
        this.errorList = errorList;
    }
}

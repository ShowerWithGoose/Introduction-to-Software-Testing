package frontend;

import exceptions.FatalErrorException;
import common.Error;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.function.Supplier;

public class Lexer {
    enum LexerState {
        DEALING_SPACE,
        DEALING_ID,
        DEALING_CONST,
        DEALING_SEP,
        DEALING_COM,
        END
    }


    private final String rawFile;
    private final ArrayList<Token> tokens = new ArrayList<>();
    private int currentIndex = 0;
    private boolean nextIsEscape = false;
    private int currentLine = 1;
    private final ArrayList<Error> errorList;
    private LexerState currentState = LexerState.DEALING_SPACE;
    private FatalErrorException currentFatalException = null;
    private final HashMap<LexerState, Supplier<LexerState>> statFuncMap = new HashMap<>();
    private final HashMap<String, TokenType> keyWordMap = new HashMap<>();
    private final HashMap<String, TokenType> separatorMap = new HashMap<>();
    private final HashSet<Character> separatorCharSet = new HashSet<>();
    private Lexer(String rawFile, ArrayList<Error> handlerOfErrList) {
        this.rawFile = rawFile;

        //initializing function map
        statFuncMap.put(LexerState.DEALING_SPACE, this::dealSpace);
        statFuncMap.put(LexerState.DEALING_ID, this::dealId);
        statFuncMap.put(LexerState.DEALING_CONST, this::dealConst);
        statFuncMap.put(LexerState.DEALING_COM, this::dealCom);
        statFuncMap.put(LexerState.DEALING_SEP, this::dealSep);
        errorList = handlerOfErrList;

        registerWordMaps();
    }

    /**
     * move the index, update line, and mark whether the tmp character is an escape character,
     * i.e. the character at index before moving is '\'
     */
    private void moveIndex() {
        if (nextIsEscape) {
            nextIsEscape = false;
        } else {
            nextIsEscape = rawFile.charAt(currentIndex) == '\\';
        }
        if (rawFile.charAt(currentIndex) == '\n') {
            currentLine++;
        }
        currentIndex++;
    }

    private LexerState dealSpace() {
        while (currentIndex < rawFile.length()) {
            char tmpCh = rawFile.charAt(currentIndex);
            if (tmpCh == '/' &&
                    currentIndex + 1 < rawFile.length() &&
                    (rawFile.charAt(currentIndex + 1) == '/' || rawFile.charAt(currentIndex + 1) == '*' )
                    ) {
                //注释的优先级应该高于其他分隔符，否则可能判为除号
                return LexerState.DEALING_COM;
            }else if (Character.isLetter(tmpCh) || tmpCh == '_') {
                return LexerState.DEALING_ID;
            } else if (Character.isDigit(tmpCh) || tmpCh == '\'' || tmpCh == '\"') {
                return LexerState.DEALING_CONST;
            } else if (separatorCharSet.contains(tmpCh)) {
                return LexerState.DEALING_SEP;
            } else if (!Character.isWhitespace(tmpCh)) {
                currentFatalException = new FatalErrorException(currentLine, "Unknown char");
                return null;
            }
            moveIndex();
        }

        return LexerState.END;
    }

    private LexerState dealId() {
        StringBuilder sbOfValue = new StringBuilder();

        while (currentIndex < rawFile.length() &&
                String.valueOf(rawFile.charAt(currentIndex)).matches("\\w")) {

            char tmpCh = rawFile.charAt(currentIndex);
            if (tmpCh == '\n') {
                currentFatalException = new FatalErrorException(currentLine, "Unexpected end of line");
                return null;
            }
            sbOfValue.append(tmpCh);
            moveIndex();

        }
        String value = sbOfValue.toString();
        TokenType type = keyWordMap.get(value);
        if (type == null) {
            type = TokenType.IDENFR;
        }
        tokens.add(new Token(type, value, currentLine));
        return LexerState.DEALING_SPACE;
    }

    private LexerState dealConst() {
        StringBuilder sbOfValue = new StringBuilder();
        char firstCh = rawFile.charAt(currentIndex);
        sbOfValue.append(firstCh);
        moveIndex();    //指向第二个

        TokenType type = firstCh == '"' ? TokenType.STRCON :
                        firstCh == '\'' ? TokenType.CHRCON :
                                          TokenType.INTCON;

        while (currentIndex < rawFile.length()) {
            char tmpCh = rawFile.charAt(currentIndex);
            if (type == TokenType.STRCON && (tmpCh == '"' && !nextIsEscape) ||
                type == TokenType.CHRCON && (tmpCh == '\'' && !nextIsEscape)
                ) {
                sbOfValue.append(tmpCh);    //保留最后的'或"
                moveIndex();
                break;
            } else if (type == TokenType.INTCON && !Character.isDigit(tmpCh)) {
                break;                      //已经不是数字了
            }
            if (tmpCh == '\n') {
                currentFatalException = new FatalErrorException(currentLine, "Unexpected end of line");
                return null;
            }
            sbOfValue.append(tmpCh);
            moveIndex();
        }
        tokens.add(new Token(type, sbOfValue.toString(), currentLine));
        return LexerState.DEALING_SPACE;
    }

    private LexerState dealSep() {
        StringBuilder bufferBuilder = new StringBuilder();
        for (int cursor = currentIndex;
             cursor < rawFile.length() && separatorCharSet.contains(rawFile.charAt(cursor));
             cursor++) {
            bufferBuilder.append(rawFile.charAt(cursor));
        }
        String buffer = bufferBuilder.toString();
        TokenType type = null;
        String tmpStr;
        for (tmpStr = buffer;
             !tmpStr.isEmpty();
             tmpStr = tmpStr.substring(0, tmpStr.length() - 1)) {

            type = separatorMap.get(tmpStr);
            if (type != null) {
                break;
            }
        }
        if (type == null) {
            errorList.add(new Error(currentLine, Error.LEXICAL_ERROR));

            //为设计好的错误加特判
            if (rawFile.charAt(currentIndex) == '&') {
                tokens.add(new Token(TokenType.AND, "&&", currentLine));

            } else if (rawFile.charAt(currentIndex) == '|') {
                tokens.add(new Token(TokenType.OR, "||", currentLine));
            }


            currentIndex++; //掠过第一个错误的符号继续匹配。该行为不改变nextIsEscape和currentLine等状态
        } else {
            tokens.add(new Token(type, tmpStr, currentLine));
            currentIndex += tmpStr.length();
        }

        return LexerState.DEALING_SPACE;
    }
    
    private LexerState dealCom() {
        moveIndex();    // skip the first '/'
        char commentType = rawFile.charAt(currentIndex);
        moveIndex();    // skip the second '/' or '*', in case dealing '/*/' wrongly
        if (commentType == '/') {
            while (currentIndex < rawFile.length() &&
                    rawFile.charAt(currentIndex) != '\n') {
                moveIndex();
            }
        } else {
            while (true) {
                char lastCh = rawFile.charAt(currentIndex);
                moveIndex();
                if (currentIndex >= rawFile.length()) {
                    currentFatalException = new FatalErrorException(currentLine, "comment not closed");
                }
                char tmpCh = rawFile.charAt(currentIndex);
                if (lastCh == '*' && tmpCh == '/') {
                    break;
                }
            }
            moveIndex();    //skip the '/' of '*/'
        }

        return LexerState.DEALING_SPACE;
    }
    
    private void startLex() throws FatalErrorException {
        
        while (currentState != LexerState.END) {
            currentState = statFuncMap.get(currentState).get();
            if (currentFatalException != null) {
                throw currentFatalException;
            }
        }
    }

    private void registerWordMaps() {
        //为提高可维护性，以下代码应该由utils/中的脚本生成
        //for type separatorMap
        separatorMap.put(";", TokenType.SEMICN);
        separatorMap.put("!", TokenType.NOT);
        separatorMap.put("*", TokenType.MULT);
        separatorMap.put(",", TokenType.COMMA);
        separatorMap.put("&&", TokenType.AND);
        separatorMap.put("/", TokenType.DIV);
        separatorMap.put("(", TokenType.LPARENT);
        separatorMap.put("||", TokenType.OR);
        separatorMap.put("%", TokenType.MOD);
        separatorMap.put(")", TokenType.RPARENT);
        separatorMap.put("<", TokenType.LSS);
        separatorMap.put("[", TokenType.LBRACK);
        separatorMap.put("<=", TokenType.LEQ);
        separatorMap.put("]", TokenType.RBRACK);
        separatorMap.put(">", TokenType.GRE);
        separatorMap.put("{", TokenType.LBRACE);
        separatorMap.put(">=", TokenType.GEQ);
        separatorMap.put("}", TokenType.RBRACE);
        separatorMap.put("==", TokenType.EQL);
        separatorMap.put("+", TokenType.PLUS);
        separatorMap.put("!=", TokenType.NEQ);
        separatorMap.put("-", TokenType.MINU);
        separatorMap.put("=", TokenType.ASSIGN);
        //end of type separatorMap. total count: 23
        //for type keyWordMap
        keyWordMap.put("else", TokenType.ELSETK);
        keyWordMap.put("void", TokenType.VOIDTK);
        keyWordMap.put("main", TokenType.MAINTK);
        keyWordMap.put("for", TokenType.FORTK);
        keyWordMap.put("const", TokenType.CONSTTK);
        keyWordMap.put("getint", TokenType.GETINTTK);
        keyWordMap.put("int", TokenType.INTTK);
        keyWordMap.put("getchar", TokenType.GETCHARTK);
        keyWordMap.put("char", TokenType.CHARTK);
        keyWordMap.put("printf", TokenType.PRINTFTK);
        keyWordMap.put("break", TokenType.BREAKTK);
        keyWordMap.put("return", TokenType.RETURNTK);
        keyWordMap.put("continue", TokenType.CONTINUETK);
        keyWordMap.put("if", TokenType.IFTK);
        //end of type keyWordMap. total count: 14

        //所有分隔符的集合
        for (String s: separatorMap.keySet()) {
            for (char c: s.toCharArray()) {
                separatorCharSet.add(c);
            }
        }
    }

    //唯一由外部代码调用的方法

    /**
     *
     * @param rawFile: 读入的整个文件
     * @param handlerOfErrList: 传入的错误列表（作为句柄）
     * @return token序列（错误被追加在handlerOfErrList中）
     * @throws FatalErrorException: 未定义的错误
     */
    public static ArrayList<Token> lex(String rawFile, ArrayList<Error> handlerOfErrList)
            throws FatalErrorException {
        Lexer lexer = new Lexer(rawFile, handlerOfErrList);
        lexer.startLex();
        return lexer.tokens;
    }
}


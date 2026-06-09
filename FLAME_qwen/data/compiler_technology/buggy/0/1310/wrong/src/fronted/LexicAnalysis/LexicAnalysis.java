package src.fronted.LexicAnalysis;

import src.ErrorHandle.BaseError;
import src.ErrorHandle.Errortype;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class LexicAnalysis {
    private static LexicAnalysis instance;
    private ArrayList<String> CodeString;//代码全部按行读入
    private HashMap<String, WordType> ReservedWords;
    private ArrayList<Word> WordList;//词法分析就是要将CodeString转化为WordList
    private int curRow;
    private int curCol;
    private String curString;
    private char curChar;
    private BaseError error;
    private ArrayList<BaseError> ErrorList;

    private LexicAnalysis(ArrayList<String> CodeString) {
        this.CodeString = CodeString;
        this.WordList = new ArrayList<>();
        this.ErrorList = new ArrayList<>();
        this.curRow = 0;
        this.curCol = 0;
        if (!CodeString.isEmpty()) {
            this.curString = CodeString.get(0);
        } else {
            this.curString = "";
        }
        this.ReservedWords = new HashMap<>();
        this.ReservedWords.put("main", WordType.MAINTK);
        this.ReservedWords.put("const", WordType.CONSTTK);
        this.ReservedWords.put("int", WordType.INTTK);
        this.ReservedWords.put("char", WordType.CHARTK);
        this.ReservedWords.put("break", WordType.BREAKTK);
        this.ReservedWords.put("continue", WordType.CONTINUETK);
        this.ReservedWords.put("if", WordType.IFTK);
        this.ReservedWords.put("else", WordType.ELSETK);
        this.ReservedWords.put("for", WordType.FORTK);
        this.ReservedWords.put("getint", WordType.GETINTTK);
        this.ReservedWords.put("getchar", WordType.GETCHARTK);
        this.ReservedWords.put("printf", WordType.PRINTFTK);
        this.ReservedWords.put("return", WordType.RETURNTK);
        this.ReservedWords.put("void", WordType.VOIDTK);
        //之后判断是否为保留字
    }

    public static synchronized LexicAnalysis getInstance(ArrayList<String> CodeString) {
        if (instance == null) {
            instance = new LexicAnalysis(CodeString);
        }
        return instance;
    }

    public void excute() {
        while (curRow < CodeString.size()) {
            curString = CodeString.get(curRow);
            if (curCol < curString.length()) {
                curChar = curString.charAt(curCol);
                if (curChar == ' ' || curChar == '\r' || curChar == '\n' || curChar == '\t') {
                    Blank();
                } else if (Character.isLetter(curChar) || curChar == '_') {
                    ReservedWordsOrIdent();
                } else if (Character.isDigit(curChar)) {
                    IntConst();
                } else if (curChar == '\"') {
                    StringConst();
                } else if (curChar == '\'') {
                    CharConst();
                } else {
                    OperatorOrAnnotation();
                }
            } else {
                curCol = 0;
                curRow += 1;
            }
        }
    }

    private char nextChar(boolean get) {
        //get为真代表要取出这个字符，即对应列数加1。为假代表只是预读一下，实际不取出
        int tempCol = curCol + 1;
        if (get) {
            curCol++;
        }
        if (tempCol < curString.length()) {
            return curString.charAt(tempCol);
        } else {
            return 0;
        }
    }

    private void Blank() {
        curCol++;
        //使下次循环的curChar后移，超出列数则自动下一行。
    }

    private void AddtoWordList(String wordName, WordType wordType) {
        Word word = new Word(wordName, wordType, curRow+1, curCol+1);
        WordList.add(word);
        curChar = nextChar(true);
    }

    private void AddtoErrorList(Errortype e) {
        BaseError baseError = new BaseError(curRow+1, curCol+1, e);
        ErrorList.add(baseError);
        curChar = nextChar(true);
        //这里必须往后读一位
    }

    private void ReservedWordsOrIdent() {
        String wordname = "" + curChar;//进入这个函数只是判断了一下，但是没有保存
        //这里需要预读判断
        while (Character.isLetterOrDigit(nextChar(false)) || nextChar(false) == '_') {
            curChar = nextChar(true);
            wordname = wordname + curChar;
        }
        AddtoWordList(wordname, ReservedWords.getOrDefault(wordname, WordType.IDENFR));
    }

    private void IntConst() {
        String wordname = "" + curChar;
        while (Character.isDigit(nextChar(false))) {
            curChar = nextChar(true);
            wordname = wordname + curChar;
        }
        AddtoWordList(wordname, WordType.INTCON);
    }

    private void StringConst() {
        String wordname = "" + curChar;
        while (nextChar(false) != '\"' && nextChar(false) != 0) {
            curChar = nextChar(true);
            wordname = wordname + curChar;
        }
        if (nextChar(false) == '\"') {
            curChar = nextChar(true);
            wordname = wordname + curChar;
        }
        AddtoWordList(wordname, WordType.STRCON);
    }

    private void CharConst() {
//        curChar = nextChar(true);
        String wordname = "'" + curChar + "'";
        while (nextChar(false) != '\'' && nextChar(false) != 0) {
            curChar = nextChar(true);
            wordname = wordname + curChar;
        }
        if (nextChar(false) == '\'') {
            curChar = nextChar(true);
            wordname = wordname + curChar;
        }
        AddtoWordList(wordname, WordType.CHRCON);
    }

    private void nextRow() {
        curRow++;
        curCol = 0;
        if (curRow < CodeString.size()) {
            curString = CodeString.get(curRow);
            if (curCol < curString.length()) {
                curChar = curString.charAt(curCol);
            } else {
                curChar = 0;
            }
        } else {
            curString = "";
            curChar = 0;
        }
    }

    private void OperatorOrAnnotation() {
        String wordname = "" + curChar;
        if (curChar == '!') {
            if (nextChar(false) == '=') {
                curChar = nextChar(true);
                wordname = wordname + curChar;
                AddtoWordList(wordname, WordType.NEQ);
            } else {
                AddtoWordList(wordname, WordType.NOT);
            }
        } else if (curChar == '&') {
            if (nextChar(false) == '&') {
                curChar = nextChar(true);
                wordname = wordname + curChar;
                AddtoWordList(wordname, WordType.AND);
            } else {
                AddtoErrorList(Errortype.a);
            }
        } else if (curChar == '|') {
            if (nextChar(false) == '|') {
                curChar = nextChar(true);
                wordname = wordname + curChar;
                AddtoWordList(wordname, WordType.OR);
            } else {
                AddtoErrorList(Errortype.a);
            }
        } else if (curChar == '+') {
            AddtoWordList(wordname, WordType.PLUS);
        } else if (curChar == '-') {
            AddtoWordList(wordname, WordType.MINU);
        } else if (curChar == '*') {
            AddtoWordList(wordname, WordType.MULT);
        } else if (curChar == '/') {
            //处理注释
            if (nextChar(false) == '/') {
                nextRow();
            } else if (nextChar(false) == '*') {
                curChar = nextChar(true);
                //第一次读是读到了*，必须再读一次才能读下一个字符
                curChar = nextChar(true);
                while (true) {
                    if (curChar == '*') {
                        curChar = nextChar(true);
                        if (curChar == 0) {
                            //此行结束
                            nextRow();
                            continue;
                        }
                        if (curChar == '/') {
                            curChar = nextChar(true);
                            //这里要再往后读一位，否则会识别为除号
                            break;
                        }
                    } else {
                        curChar = nextChar(true);
                        if (curChar == 0) {
                            nextRow();
                        }
                    }
                }
            } else {
                AddtoWordList(wordname, WordType.DIV);
            }
        } else if (curChar == '%') {
            AddtoWordList(wordname, WordType.MOD);
        } else if (curChar == '<') {
            if (nextChar(false) == '=') {
                curChar = nextChar(true);
                wordname = wordname + curChar;
                AddtoWordList(wordname, WordType.LEQ);
            } else {
                AddtoWordList(wordname, WordType.LSS);
            }
        } else if (curChar == '>') {
            if (nextChar(false) == '=') {
                curChar = nextChar(true);
                wordname = wordname + curChar;
                AddtoWordList(wordname, WordType.GEQ);
            } else {
                AddtoWordList(wordname, WordType.GRE);
            }
        } else if (curChar == '=') {
            if (nextChar(false) == '=') {
                curChar = nextChar(true);
                wordname = wordname + curChar;
                AddtoWordList(wordname, WordType.EQL);
            } else {
                AddtoWordList(wordname, WordType.ASSIGN);
            }
        } else if (curChar == ';') {
            AddtoWordList(wordname, WordType.SEMICN);
        } else if (curChar == ',') {
            AddtoWordList(wordname, WordType.COMMA);
        } else if (curChar == '(') {
            AddtoWordList(wordname, WordType.LPARENT);
        } else if (curChar == ')') {
            AddtoWordList(wordname, WordType.RPARENT);
        } else if (curChar == '[') {
            AddtoWordList(wordname, WordType.LBRACK);
        } else if (curChar == ']') {
            AddtoWordList(wordname, WordType.RBRACK);
        } else if (curChar == '{') {
            AddtoWordList(wordname, WordType.LBRACE);
        } else if (curChar == '}') {
            AddtoWordList(wordname, WordType.RBRACE);
        }
    }

    public void output() throws IOException {
        if (!ErrorList.isEmpty()) {
            BufferedWriter errorWriter = new BufferedWriter(new FileWriter("error.txt"));
            for (BaseError baseError : ErrorList) {
                errorWriter.write(baseError.getRow() + " " + baseError.getErrortype());
                errorWriter.newLine();
            }
            errorWriter.flush();
            errorWriter.close();
        } else {
            BufferedWriter lexerWriter = new BufferedWriter(new FileWriter("lexer.txt"));
            for (Word word : WordList) {
                lexerWriter.write(word.getWordType() + " " + word.getWordName());
                lexerWriter.newLine();
            }
            lexerWriter.flush();
            lexerWriter.close();
        }
    }
}
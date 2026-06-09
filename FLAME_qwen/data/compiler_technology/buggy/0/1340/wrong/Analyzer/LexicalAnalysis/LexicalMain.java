package Analyzer.LexicalAnalysis;

import Analyzer.ERROR.Error;
import Analyzer.ERROR.ErrorType;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

import static java.lang.Character.isDigit;
import static java.lang.Character.isLetter;

public class LexicalMain {
    private HashMap<String,WordType> keywordMap;
    private HashMap<Character,WordType> singleSymbolMap;
    private HashMap<String,WordType> symbolWithEQMap;

    private ArrayList<String> stringInLine;
    private ArrayList<Word> wordList;
    private ArrayList<Error> errorList;

    public ArrayList<Error> getErrorList() {
        return errorList;
    }

    public ArrayList<Word> getWordList() {
        return wordList;
    }

    public LexicalMain(ArrayList<String> stringInLine){
        this.keywordMap = new HashMap<>();
        this.keywordMap.put("main", WordType.MAINTK);
        this.keywordMap.put("const", WordType.CONSTTK);
        this.keywordMap.put("int", WordType.INTTK);
        this.keywordMap.put("char", WordType.CHARTK);
        this.keywordMap.put("break", WordType.BREAKTK);
        this.keywordMap.put("continue", WordType.CONTINUETK);
        this.keywordMap.put("if", WordType.IFTK);
        this.keywordMap.put("else", WordType.ELSETK);
        this.keywordMap.put("for", WordType.FORTK);
        this.keywordMap.put("getint", WordType.GETINTTK);
        this.keywordMap.put("getchar", WordType.GETCHARTK);
        this.keywordMap.put("printf", WordType.PRINTFTK);
        this.keywordMap.put("return", WordType.RETURNTK);
        this.keywordMap.put("void", WordType.VOIDTK);

        this.singleSymbolMap = new HashMap<>();
        this.singleSymbolMap.put('+',WordType.PLUS);
        this.singleSymbolMap.put('-',WordType.MINU);
        this.singleSymbolMap.put('*',WordType.MULT);
        this.singleSymbolMap.put('/',WordType.DIV);
        this.singleSymbolMap.put('%',WordType.MOD);
        this.singleSymbolMap.put(';',WordType.SEMICN);
        this.singleSymbolMap.put(',',WordType.COMMA);
        this.singleSymbolMap.put('(',WordType.LPARENT);
        this.singleSymbolMap.put(')',WordType.RPARENT);
        this.singleSymbolMap.put('[',WordType.LBRACK);
        this.singleSymbolMap.put(']',WordType.RBRACK);
        this.singleSymbolMap.put('{',WordType.LBRACE);
        this.singleSymbolMap.put('}',WordType.RBRACE);

        this.symbolWithEQMap = new HashMap<>();
        this.symbolWithEQMap.put("!",WordType.NOT);
        this.symbolWithEQMap.put("<",WordType.LSS);
        this.symbolWithEQMap.put(">",WordType.GRE);
        this.symbolWithEQMap.put("=",WordType.ASSIGN);
        this.symbolWithEQMap.put("!=",WordType.NEQ);
        this.symbolWithEQMap.put("<=",WordType.LEQ);
        this.symbolWithEQMap.put(">=",WordType.GEQ);
        this.symbolWithEQMap.put("==",WordType.EQL);

        this.stringInLine = stringInLine;
        removeComments(this.stringInLine);

        this.wordList = new ArrayList<>();
        this.errorList = new ArrayList<>();

    }

    /**
     * 按行分析整个文件
     */
    public void runLexer(){
        String curLine;
        StringBuilder curStr = new StringBuilder();
        boolean isStringConst = false;
        boolean isCharConst = false;
        for(int curLineNum = 1;curLineNum<=stringInLine.size();curLineNum++){
            curLine = stringInLine.get(curLineNum - 1);
            int lengthOfLine = curLine.length();
            for(int i = 0;i<lengthOfLine;i++){
                char curChar = curLine.charAt(i);
                // 字符串常量
                if(curChar == '"'){
                    if(i > 0 && curLine.charAt(i-1) != '\\' && !isCharConst) {
                        if (!isStringConst) {
                            //字符串常量处理开始，处理此前的字符串
                            isStringConst = true;
                            handleOtherString(String.valueOf(curStr),curLineNum,i - curStr.length());
                            curStr.setLength(0);
                            curStr.append(curChar);
                        }
                        else{
                            //字符串常量处理结束，处理其中的字符串
                            curStr.append(curChar);
                            isStringConst = false;
                            handleStringConst(String.valueOf(curStr),curLineNum,i - curStr.length());
                            curStr.setLength(0);
                        }
                    }
                }
                // 字符常量。转义？
                else if(curChar =='\''){
                    if(i > 0 && curLine.charAt(i-1) != '\\' && !isStringConst) {
                        if (!isCharConst) {
                            isCharConst = true;
                            if(!curStr.isEmpty()){
                                handleOtherString(String.valueOf(curStr),curLineNum,i - curStr.length());
                                curStr.setLength(0);
                            }
                            curStr.append(curChar);
                        }
                        else{
                            curStr.append(curChar);
                            isCharConst = false;
                            handleCharConst(String.valueOf(curStr),curLineNum,i - curStr.length());
                            curStr.setLength(0);
                        }
                    }
                }
                //空字符
                else if( (curChar == ' '||curChar == '\n'||curChar == '\t') && !isCharConst && !isStringConst ){
                    //处理当前单词
                    handleOtherString(String.valueOf(curStr),curLineNum,i - curStr.length());
                    curStr.setLength(0);
                }
                //只会单独出现的符号
                else if(singleSymbolMap.containsKey(curChar)&&!isCharConst&&!isStringConst){
                    handleOtherString(String.valueOf(curStr),curLineNum,i - curStr.length());
                    curStr.setLength(0);
                    handleSingleSymbol(curChar,curLineNum,i);
                }
                else if(curChar == '|'&&!isCharConst&&!isStringConst){
                    handleOtherString(String.valueOf(curStr),curLineNum,i - curStr.length());
                    curStr.setLength(0);
                    if(i+1<lengthOfLine) {
                        char nextChar = curLine.charAt(i + 1);
                        if(nextChar == '|'){
                            handleOR(curLineNum,i);
                            i++;
                        }
                        else{
                            handleERR(curLineNum,ErrorType.a);
                        }
                    }
                    else{
                        handleERR(curLineNum,ErrorType.a);
                    }
                }
                else if(curChar == '&'&&!isCharConst&&!isStringConst){
                    handleOtherString(String.valueOf(curStr),curLineNum,i - curStr.length());
                    curStr.setLength(0);
                    if(i+1<lengthOfLine) {
                        char nextChar = curLine.charAt(i + 1);
                        if(nextChar == '&'){
                            handleAND(curLineNum,i);
                            i++;
                        }
                        else{
                            handleERR(curLineNum,ErrorType.a);
                        }
                    }
                    else{
                        handleERR(curLineNum,ErrorType.a);
                    }
                }
                else if(symbolWithEQMap.containsKey(""+curChar)&&!isCharConst&&!isStringConst){
                    handleOtherString(String.valueOf(curStr),curLineNum,i - curStr.length());
                    curStr.setLength(0);
                    if(i+1<lengthOfLine) {
                        char nextChar = curLine.charAt(i + 1);
                        if (nextChar == '=') {
                            handleSymbolWithEQ(curChar+"=",curLineNum, i);
                            i++;
                        }
                        else{
                            handleSymbolWithEQ(""+curChar,curLineNum, i);
                        }
                    }
                    else{
                        handleSymbolWithEQ(""+curChar,curLineNum, i);
                    }
                }
                else{
                    curStr.append(curChar);
                }
            }
        }
    }

    private void removeComments(ArrayList<String> stringInLine) {
        boolean inBlockComment = false;
        for (int i = 0; i < stringInLine.size(); i++) {
            String line = stringInLine.get(i);
            // 如果当前行在块注释中，则跳过处理
            if (inBlockComment) {
                int blockCommentEnd = line.indexOf("*/");
                if (blockCommentEnd != -1) {
                    // 找到结束标记，继续处理后面的内容
                    line = line.substring(blockCommentEnd + 2);
                    inBlockComment = false;
                }
                else {
                    // 仍在块注释中，清空行
                    line = "";
                }
            }

            // 去掉行内的单行注释
            int singleLineCommentIndex = line.indexOf("//");
            if (singleLineCommentIndex != -1) {
                line = line.substring(0, singleLineCommentIndex);
            }

            // 检查块注释的开始
            int blockCommentStart = line.indexOf("/*");
            if (blockCommentStart != -1) {
                inBlockComment = true;
                line = line.substring(0, blockCommentStart);
            }
            stringInLine.set(i, line.trim());
        }
    }
    /*
    不是字符串常量、字符常量、特殊符号；
    只可能是关键词、数字常量、变量名
     */
    private void handleOtherString(String str,int col,int row){
        if(!str.isEmpty()) {
            Word newWord;
            if (keywordMap.containsKey(str)) {
                newWord = new Word(str, keywordMap.get(str), col, row);
            }
            else if(isInteger(str)){
                newWord = new Word(str, WordType.INTCON, col, row);
            }
            else{
                newWord = new Word(str, WordType.IDENFR, col, row);
            }
            wordList.add(newWord);
        }
    }
    private void handleStringConst(String str,int col,int row){
        if(!str.isEmpty()) {
            Word newWord = new Word(str, WordType.STRCON, col, row);
            wordList.add(newWord);
        }
    }
    private void handleCharConst(String str,int col,int row){
        if(!str.isEmpty()) {
            Word newWord = new Word(str, WordType.CHRCON, col, row);
            wordList.add(newWord);
        }
    }
    private void handleSingleSymbol(char c,int col,int row){
        String s = ""+c;
        Word newWord = new Word(s,this.singleSymbolMap.get(c),col,row);
        wordList.add(newWord);
    }
    private void handleAND(int col,int row){
        Word newWord = new Word("&&",WordType.AND,col,row);
        wordList.add(newWord);
    }
    private void handleOR(int col,int row){
        Word newWord = new Word("||",WordType.OR,col,row);
        wordList.add(newWord);
    }
    private void handleSymbolWithEQ(String str,int col,int row){
        Word newWord = new Word(str,symbolWithEQMap.get(str),col,row);
        wordList.add(newWord);
    }
    private void handleERR(int col, ErrorType errType){
        errorList.add(new Error(errType,col));
    }

    public static boolean isInteger(String str) {
        if (str == null || str.isEmpty()) {
            return false;
        }
        return str.matches("\\d+");
    }

    public void writeWordsToFile(String filePath) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (Word word : wordList) {
                writer.write(word.getWordType() + " " + word.getWordName());
                writer.newLine(); // 换行
            }
            System.out.println("写入成功！");
        } catch (IOException e) {
            System.err.println("写入文件时出错: " + e.getMessage());
        }
    }
    public void writeErrorsToFile(String filePath) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (Error error : errorList) {
                writer.write(error.getCol() + " " + error.getErrorType());
                writer.newLine(); // 换行
            }
            System.out.println("写入成功！");
        } catch (IOException e) {
            System.err.println("写入文件时出错: " + e.getMessage());
        }
    }


}

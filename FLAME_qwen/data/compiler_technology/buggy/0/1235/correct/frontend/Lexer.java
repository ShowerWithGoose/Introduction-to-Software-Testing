package frontend;

import java.io.*;
import java.util.*;

public class Lexer {
    private final String inputPath;
    private final String outputPathTrue;
    private final String outputPathFalse;
    private BufferedReader bufferedReader;

    private final List<Token> tokens = new ArrayList<>();
    private final List<Error> errors = new ArrayList<>();
    private int lineNum = 1;

    // 获取文件路径
    public Lexer(String inputPath, String outputPathTrue, String outputPathFalse) throws IOException {
        this.inputPath = inputPath;
        this.outputPathTrue = outputPathTrue;
        this.outputPathFalse = outputPathFalse;
    }

    // 读入文件
    private void readInputFile() throws IOException {
        FileReader fileReader = new FileReader(inputPath);
        bufferedReader = new BufferedReader(fileReader);
    }

    // 结束文件读取
    private void closeInputFile() throws IOException {
        bufferedReader.close();
    }

    // 词法分析
    public void analysis() throws IOException {
        readInputFile();
        int character;
        StringBuilder currentToken = new StringBuilder();
        OperatorMap operatorMap = new OperatorMap();
        while((character = bufferedReader.read()) != -1){
            char ch = (char) character;
            String s = String.valueOf(ch);

            if(ch == '\n'){
                lineNum++;
            } else if(Character.isWhitespace(ch)) {
                continue;
            } else if(Character.isLetter(ch) || ch == '_'){
                currentToken.setLength(0);
                currentToken.append(ch);
                bufferedReader.mark(1);
                while((character = bufferedReader.read()) != -1){
                    ch = (char) character;
                    if(Character.isLetter(ch) || ch == '_' || Character.isDigit(ch)){
                        currentToken.append(ch);
                        bufferedReader.mark(1);
                    }else {
                        // 回退字符
                        bufferedReader.reset();
                        break;
                    }
                }
                String strToken = currentToken.toString();
                KeywordsMap keywordsMap = new KeywordsMap();
                if(keywordsMap.isKeyword(strToken)){
                    tokens.add(new Token(strToken, keywordsMap.getKeywordType(strToken), lineNum));
                }else {
                    tokens.add(new Token(strToken, "IDENFR", lineNum));
                }
            }else if(Character.isDigit(ch)){
                currentToken.setLength(0);
                currentToken.append(ch);
                bufferedReader.mark(1);
                while((character = bufferedReader.read()) != -1){
                    ch = (char) character;
                    if(Character.isDigit(ch)){
                        currentToken.append(ch);
                        bufferedReader.mark(1);
                    }else {
                        bufferedReader.reset();
                        break;
                    }
                }
                String digToken = currentToken.toString();
                tokens.add(new Token(digToken, "INTCON", lineNum));
            }else if(ch == '/'){
                currentToken.setLength(0);
                currentToken.append(ch);
                bufferedReader.mark(1);
                character = bufferedReader.read();
                char nextCh = (char) character;
                if(nextCh == '/'){
                    currentToken.append(nextCh);
                    while((character = bufferedReader.read()) != -1){
                        ch = (char) character;
                        if(ch == '\n'){
                            lineNum++;
                            break;
                        }
                        currentToken.append(ch);
                    }
//                    String noteToken = currentToken.toString();
//                    tokens.add(new Token(noteToken, "NOTE", lineNum));
                }else if(nextCh == '*'){
                    currentToken.append(nextCh);
                    while((character = bufferedReader.read()) != -1){
                        ch = (char) character;
                        if(ch == '\n'){
                            lineNum++;
                            currentToken.append(ch);
                        }else if(ch == '*'){
                            currentToken.append(ch);
                            bufferedReader.mark(1);
                            character = bufferedReader.read();
                            ch = (char) character;
                            if(ch == '/'){
                                currentToken.append("*/");
                                break;
                            }
                            bufferedReader.reset();
                        }
                    }
                }else {
                    String opString = currentToken.toString();
                    tokens.add(new Token(opString, operatorMap.getOperatorType(opString), lineNum));
                    bufferedReader.reset();
                }
            }else if(ch == '"'){
                currentToken.setLength(0);
                currentToken.append(ch);
                while((character = bufferedReader.read()) != -1){
                    ch = (char) character;
                    currentToken.append(ch);
                    if(ch == '\n'){
                        lineNum++;
                    }else if(ch == '"'){
                        break;
                    }
                }
                String quoteString = currentToken.toString();
                tokens.add(new Token(quoteString, "STRCON", lineNum));
            }else if(ch == '\''){
                currentToken.setLength(0);
                currentToken.append(ch);
                character = bufferedReader.read();
                char nextCh = (char) character;
                currentToken.append(nextCh);
                if(nextCh == '\\'){
                    character = bufferedReader.read();
                    nextCh = (char) character;
                    currentToken.append(nextCh);
                }
                character = bufferedReader.read();
                nextCh = (char) character;
                currentToken.append(nextCh);
                String quoteString = currentToken.toString();
                tokens.add(new Token(quoteString, "CHRCON", lineNum));
            }else if(ch == '&' || ch == '|'){
                character = bufferedReader.read();
                char nextCh = (char) character;
                currentToken.setLength(0);
                currentToken.append(ch);
                bufferedReader.mark(1);
                if((ch == '&' && nextCh == '&') || (ch == '|' && nextCh == '|')){
                    currentToken.append(nextCh);
                    String opToken = currentToken.toString();
                    tokens.add(new Token(opToken, operatorMap.getOperatorType(opToken), lineNum));
                }else {
                    String opToken = currentToken.toString();
                    errors.add(new Error(opToken, "a", lineNum));
                    bufferedReader.reset();
                }
            }else if(ch == '<' || ch == '>' || ch == '=' || ch == '!'){
                currentToken.setLength(0);
                currentToken.append(ch);
                bufferedReader.mark(1);
                character = bufferedReader.read();
                char nextCh = (char) character;
                if(nextCh == '='){
                    currentToken.append(nextCh);
                }else {
                    bufferedReader.reset();
                }
                String opToken = currentToken.toString();
                tokens.add(new Token(opToken, operatorMap.getOperatorType(opToken), lineNum));
            }else if(operatorMap.isOperator(s)){
                currentToken.setLength(0);
                currentToken.append(ch);
                String opToken = currentToken.toString();
                tokens.add(new Token(opToken, operatorMap.getOperatorType(opToken), lineNum));
            }
        }
        closeInputFile();
    }

    public List<Token> getTokens(){
        return tokens;
    }

    public void writeTokensToFile() throws IOException {
        BufferedWriter trueFile = new BufferedWriter(new FileWriter(outputPathTrue));
        for(Token token: tokens){
            trueFile.write(token.writeString());
            trueFile.newLine();
        }
        trueFile.flush();
        trueFile.close();
    }

    public void writeErrorsToFile() throws IOException {
        BufferedWriter falseFile = new BufferedWriter(new FileWriter(outputPathFalse));
        for(Error error: errors){
            falseFile.write(error.writeString());
            falseFile.newLine();
        }
        falseFile.flush();
        falseFile.close();
    }
}

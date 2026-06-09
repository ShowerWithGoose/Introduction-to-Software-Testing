package frontend;

import common.Error;
import common.Token;
import common.TokenType;

import java.util.ArrayList;

import static util.DetectCharTool.*;
import static util.Reserve.isReservedWord;

/**
 * The type Lexer.
 *
 * @author
 * @Description：词法分析
 * @date
 */
public class Lexer {
    private ArrayList<String> text;
    private int index;
    private int lineNum;
    private boolean isAnnotation;

    /**
     * 实例化一个新的词法分析器
     *
     * @param text 文本
     */
    public Lexer(ArrayList<String> text) {
        this.text = text;
        index = 0;
        isAnnotation  = false;
    }


    /**
     * 词法分析代码
     *
     * @return 数组列表
     */
    public ArrayList<Token> analyze(){
        ArrayList<Token> tokens = new ArrayList<Token>();
        for(int i = 0; i < text.size(); i++) {
            String line = text.get(i);
            lineNum = i+1;
            tokens.addAll(analyzeLine(line));

        }
        return tokens;
    }

    /**
     * 分析行
     *
     * @param line 行
     * @return  arraylist
     */
    public ArrayList<Token> analyzeLine(String line){
        ArrayList<Token> tokens = new ArrayList<>();
        index = 0;

        while(index<line.length()) {

            //处理多行注释
            if(isAnnotation){
                char c = line.charAt(index);
                index++;
                if(c!='*'){
                    continue;
                }
                else if(index == line.length()){
                    continue;
                }
                else if(line.charAt(index)=='/'){
                    isAnnotation = false;
                    index++;
                    continue;
                }
                index--;
            }
            else{
                char c = line.charAt(index);
                //标识符或保留字
                if(is_Alpha(c)){
                    StringBuilder tokenValue = new StringBuilder();
                    while (isIDENFR(c)) {
                        tokenValue.append(c);
                        if(index+1<line.length())
                        c = line.charAt(++index);
                        else
                            break;
                    }
                    if (!isIDENFR(c)) {
                        index--;
                    }
                    tokens.add(isReservedWord(tokenValue.toString(),lineNum));
                }
                //数字
                else if(isDigit(c)){
                    StringBuilder tokenValue = new StringBuilder();
                    while (isDigit(c)) {
                        tokenValue.append(c);
                        if(index+1<line.length())
                            c = line.charAt(++index);
                        else
                            break;
                    }
                    if (!isDigit(c)) {
                        index--;
                    }
                    tokens.add(new Token(tokenValue.toString(),TokenType.INTCON,lineNum));
                }
                //字符常量
                else if(isSingleQuote(c)){
                    StringBuilder tokenValue = new StringBuilder();
                    tokenValue.append(c);
                    if(index+1<line.length()) {
                        c = line.charAt(++index);
                        tokenValue.append(c);
                        if(isBackslashes(c)){
                            c = line.charAt(++index);
                            tokenValue.append(c);
                        }
                    }
                    c = line.charAt(++index);
                    tokenValue.append(c);

                    tokens.add(new Token(tokenValue.toString(), TokenType.CHRCON,lineNum));
                }
                //双分界符
                else if(isLss(c)){
                    // < <=
                    if(index+1==line.length()) {
                        tokens.add(new Token("<",TokenType.LSS,lineNum));
                        index++;
                        continue;
                    }
                    c = line.charAt(++index);
                    if(isEqual(c)){
                        tokens.add(new Token("<=",TokenType.LEQ,lineNum));
                    }
                    else{
                        index--;
                        tokens.add(new Token("<",TokenType.LSS,lineNum));
                    }

                }
                else if(isGre(c)){
                    //> >=
                    if(index+1==line.length()) {
                        tokens.add(new Token(">",TokenType.GRE,lineNum));
                        index++;
                        continue;
                    }
                    c = line.charAt(++index);
                    if(isEqual(c)){
                        tokens.add(new Token(">=",TokenType.GEQ,lineNum));
                    }
                    else{
                        index--;
                        tokens.add(new Token(">",TokenType.GRE,lineNum));
                    }
                }
                else if(isEqual(c)){
                    // = ==
                    if(index+1==line.length()) {
                        tokens.add(new Token("=",TokenType.ASSIGN,lineNum));
                        index++;
                        continue;
                    }
                    c = line.charAt(++index);
                    if(isEqual(c)){
                        tokens.add(new Token("==",TokenType.EQL,lineNum));
                    }
                    else{
                        index--;
                        tokens.add(new Token("=",TokenType.ASSIGN,lineNum));
                    }
                }
                else if(isExclamation(c)){
                    // ! !=
                    if(index+1==line.length()) {
                        tokens.add(new Token("=",TokenType.ASSIGN,lineNum));
                        index++;
                        continue;
                    }
                    c = line.charAt(++index);
                    if(isEqual(c)){
                        tokens.add(new Token("!=",TokenType.NEQ,lineNum));
                    }
                    else{
                        index--;
                        tokens.add(new Token("!",TokenType.NOT,lineNum));
                    }
                }
                else if(isAnd(c)){
                    // &&
                    if(index+1==line.length()){
                        tokens.add(new Token("&&",TokenType.AND,lineNum));
                        Error.Error_a(lineNum);
                        index++;
                        continue;
                    }
                    c = line.charAt(++index);
                    if(isAnd(c)){
                        tokens.add(new Token("&&",TokenType.AND,lineNum));
                    }
                    else {
                        index--;
                        tokens.add(new Token("&&",TokenType.AND,lineNum));
                        Error.Error_a(lineNum);
                    }
                }
                else if(isOr(c)){
                    // ||
                    if(index+1==line.length()){
                        tokens.add(new Token("||",TokenType.OR,lineNum));
                        Error.Error_a(lineNum);
                        index++;
                        continue;
                    }
                    c = line.charAt(++index);
                    if(isOr(c)){
                        tokens.add(new Token("||",TokenType.OR,lineNum));
                    }
                    else {
                        index--;
                        tokens.add(new Token("||",TokenType.OR,lineNum));
                        Error.Error_a(lineNum);
                    }
                }
                //除号 注释
                else if(isDiv(c)){
                    c = line.charAt(++index);
                    if (c == '/') {
                        break;
                    } else if (c == '*') {

                        isAnnotation = true;
                    } else {
                        tokens.add(new Token( "/", TokenType.DIV,lineNum));
                        index--;
                    }
                }
                //其他单分界符
                else if(isPlus(c)){
                    tokens.add(new Token("+", TokenType.PLUS,lineNum));
                }else if(isMinus(c)){
                    tokens.add(new Token("-",TokenType.MINU,lineNum));
                }else if(isMulti(c)){
                    tokens.add(new Token("*",TokenType.MULT,lineNum));
                }else if(isMod(c)){
                    tokens.add(new Token("%",TokenType.MOD,lineNum));
                }else if(isLeftBrace(c)){
                    tokens.add(new Token("{",TokenType.LBRACE,lineNum));
                }else if(isRightBrace(c)){
                    tokens.add(new Token("}",TokenType.RBRACE,lineNum));
                }else if(isLeftBracket(c)){
                    tokens.add(new Token("[",TokenType.LBRACK,lineNum));
                }else if(isRightBracket(c)){
                    tokens.add(new Token("]",TokenType.RBRACK,lineNum));
                }else if(isLeftParent(c)){
                    tokens.add(new Token("(",TokenType.LPARENT,lineNum));
                }else if(isRightParent(c)){
                    tokens.add(new Token(")",TokenType.RPARENT,lineNum));
                }else if(isComma(c)){
                    tokens.add(new Token(",",TokenType.COMMA,lineNum));
                }else if(isSemi(c)){
                    tokens.add(new Token(";",TokenType.SEMICN,lineNum));
                }
                // 字符串
                else if(isDoubleQuote(c)){

                    StringBuilder tokenValue = new StringBuilder();
                    tokenValue.append(c);
                    while(true){
                        c = line.charAt(++index);
                        if(isBackslashes(c)){
                            tokenValue.append(c);
                            c = line.charAt(++index);
                            tokenValue.append(c);
                            continue;
                        }
                        if(isDoubleQuote(c)){
                            tokenValue.append(c);
                            break;
                        }
                        tokenValue.append(c);
                    }
//                    do {
//                        tokenValue.append(c);
//
//                        c = line.charAt(++index);
//
//                    } while (c != '"'|| isBackslashes(line.charAt(index-1) ));
//                    tokenValue.append(c);
                    tokens.add(new Token(tokenValue.toString(), TokenType.STRCON,lineNum));
                }
            }
        index++;
        }

        return tokens;
    }



}

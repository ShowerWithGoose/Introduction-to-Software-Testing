package Lexer;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

import static java.lang.Character.*;

/**
 * <p>Project: Compiler - Lexer
 * <p>Powered by berry On 2024-09-20
 *
 * @author
 * @version 1.0
 */
public class Lexer {
    public String token;//累计存储当前的字符串
    public String line;
    public int lineNum=0;
    public boolean isEnd;//!isEnd还能取下一个
    public boolean isError;//文件中是否有错误
    public int errorLine;
    public int curPos;
    public List<Token> tokens = new ArrayList<>();//保存所有Token
    //其他属性
    public boolean isComment=false;//当前是否在注释内部
    //12个无其他情况的单个单词
    public final List<String> singleToken=new ArrayList<>(Arrays.asList("+","-","*","%",";",",","(",")","[","]","{","}"));
    //构造方法
    private static Lexer lexer=new Lexer();
    private Lexer(){
        System.out.println("单例模式");
    }
    public static Lexer getLexer(){
        return lexer;
    }
    //形如Ident的是否是保留字
    public static Token.Type isReserved(String value) {
        for (Token.Type type : Token.Type.values()) {
            if (type.getValue().equals(value)&&
                    !type.getValue().equals("Ident")&&
                    !type.getValue().equals("IntConst")&&
                    !type.getValue().equals("StringConst")&&
                    !type.getValue().equals("CharConst")) {
                return type;
            }
        }
        return Token.Type.NONE;
    }
    public static Token.Type getType(String value){
        for (Token.Type type : Token.Type.values()){
            if (type.getValue().equals(value)){
                return type;
            }
        }
        return Token.Type.NONE;
    }
    public void analyseLine(){
        System.out.println("analyseLine:"+lineNum+" "+line);
        if(line.length()==0) return;
        next();
        /*
        if(!isError) output();
        else{
            System.out.println(errorLine+" "+"a");
        }

        while (curPos < line.length()) {
            try {
                token = next();
                if (token.type==Token.Type.NONE)//没有获取到Token时返回NONE
                    continue;//考虑尾递归
                tokens.add(token);

            } catch (Exception e) {
                System.out.print("error");
            }
        }
         */
    }
    //词法分析函数
    public void next(){

        char ch='\0';
        token="";
        if(isEnd) return;
        if(!isEnd) ch=getChar();
        //是注释
        if(isComment){
            while(!isEnd){
                if(ch=='*'){
                    ch=getChar();
                    if(ch=='/'){
                        isComment=false;
                        next();
                    }
                }else{
                    ch=getChar();
                }
            }
            return;
            /*
            if(ch=='*'){
                ch=getChar();
                if(ch=='/'){
                    isComment=false;
                    next();
                }else{
                    ungetChar();
                    next();
                }
            }else{
                next();
            }
            */
        }
        //tokens.add(new Token(Token.Type.NONE,"abc",0));
        //是字母或下划线
        if(isNonDigit(ch)){
            while(!isEnd&&(isNonDigit(ch)||isDigit(ch))){
                token+=ch;
                ch=getChar();
            }
            if(isEnd&&(isNonDigit(ch)||isDigit(ch))){
                token+=ch;
            }else{
                ungetChar();
            }
            Token.Type t;
            if((t=isReserved(token))!=Token.Type.NONE){
                tokens.add(new Token(t,token,lineNum));
            }else{
                tokens.add(new Token(Token.Type.IDENFR,token,lineNum));
            }
            next();
        }
        //跳过空格
        else if(ch==' '){
            while(!isEnd&&ch==' '){
                ch=getChar();
            }
            ungetChar();
            next();
        }
        //是数字
        else if(isDigit(ch)){
            while(!isEnd&&isDigit(ch)){
                token+=ch;
                ch=getChar();
            }
            if(isEnd&&isDigit(ch)){
                token+=ch;
            }else{
                ungetChar();
            }
            Token t=new Token(Token.Type.INTCON,token,lineNum);
            t.digitnum=Long.parseLong(token);
            tokens.add(t);
            next();
        }
        //单个字符无其他判断的
        else if(singleToken.contains(new String(Character.toString(ch)))){
            String s=new String(Character.toString(ch));
            tokens.add(new Token(getType(s),s,lineNum));
            next();
        }
        //!和!=
        else if(ch=='!'){
            if(!isEnd) ch=getChar();
            else{
                tokens.add(new Token(Token.Type.NOT,"!",lineNum));
                return;
            }
            if(ch=='='){
                tokens.add(new Token(Token.Type.NEQ,"!=",lineNum));
            }else{
                ungetChar();
                tokens.add(new Token(Token.Type.NOT,"!",lineNum));
            }
            next();
        }
        //<和<=
        else if(ch=='<'){
            if(!isEnd) ch=getChar();
            else{
                tokens.add(new Token(Token.Type.LSS,"<",lineNum));
                return;
            }
            if(ch=='='){
                tokens.add(new Token(Token.Type.LEQ,"<=",lineNum));
            }else{
                ungetChar();
                tokens.add(new Token(Token.Type.LSS,"<",lineNum));
            }
            next();
        }
        //>和>=
        else if(ch=='>'){
            if(!isEnd) ch=getChar();
            else{
                tokens.add(new Token(Token.Type.GRE,">",lineNum));
                return;
            }
            if(ch=='='){
                tokens.add(new Token(Token.Type.GEQ,">=",lineNum));
            }else{
                ungetChar();
                tokens.add(new Token(Token.Type.GRE,">",lineNum));
            }
            next();
        }
        //=和==
        else if(ch=='='){
            if(!isEnd) ch=getChar();
            else{
                tokens.add(new Token(Token.Type.ASSIGN,"=",lineNum));
                return;
            }
            if(ch=='='){
                tokens.add(new Token(Token.Type.EQL,"==",lineNum));
            }else{
                ungetChar();
                tokens.add(new Token(Token.Type.ASSIGN,"=",lineNum));
            }
            next();
        }
        //'/'行内注释、多行注释、DIV
        else if(ch=='/'){
            if(!isEnd) ch=getChar();
            else{
                tokens.add(new Token(Token.Type.DIV,"/",lineNum));
                return;
            }
            if(ch=='*'){
                isComment=true;
                next();
            }else if(ch=='/'){
                return;
            }else{
                ungetChar();
                tokens.add(new Token(Token.Type.DIV,"/",lineNum));
                next();
            }
        }
        //单引号
        else if(ch=='\''){
            String ans=new String();
            ans+=ch;
            if(!isEnd) ch=getChar();
            else return;
            ans+=ch;
            if(ch=='\\'){
                if(!isEnd) ch=getChar();
                ans+=ch;
            }
            ans+="\'";
            //String ans=new String("\'"+ch+"\'");
            if(!isEnd) ch=getChar();
            tokens.add(new Token(Token.Type.CHRCON,ans,lineNum));
            next();
        }
        //双引号
        else if(ch=='\"'){
            token+="\"";
            if(!isEnd) ch=getChar();
            else return;
            while(!isEnd&&ch!='\"'){
                token+=ch;
                ch=getChar();
            }
            token+="\"";
            tokens.add(new Token(Token.Type.STRCON,token,lineNum));
            next();
        }
        //&和|
        else if(ch=='&'){
            if(!isEnd) ch=getChar();
            else{
                isError=true;
                errorLine=lineNum;
                return;
            }
            if(ch=='&'){
                tokens.add(new Token(Token.Type.AND,"&&",lineNum));
                next();
            }else{
                isError=true;
                errorLine=lineNum;
                return;
            }
        }
        else if(ch=='|'){
            if(!isEnd) ch=getChar();
            else{
                isError=true;
                errorLine=lineNum;
                return;
            }
            if(ch=='|'){
                tokens.add(new Token(Token.Type.OR,"||",lineNum));
                next();
            }else{
                isError=true;
                errorLine=lineNum;
                return;
            }
        }
        //其他情况
        else{
            next();
        }
        return;
    }
    //工具类
    public char getChar(){
        if(curPos==line.length()-1) isEnd=true;
        return line.charAt(curPos++);
    }
    public void ungetChar(){
        if(curPos==line.length()) isEnd=false;
        curPos--;
        return;
    }
    public void output(){
        String s;
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("./lexer.txt", false));
            for (int i = 0; i < tokens.size(); i++) {
                Token t = tokens.get(i);
                s=t.type+" "+t.content;
                writer.write(s);
                if(i!=tokens.size()-1)  writer.write("\n");
            }
            /*
            for(Token t:tokens) {
                s=t.type+" "+t.content+"\n";
                writer.write(s);
            }

             */
            writer.close();
        }catch (IOException e) {
            System.out.println(e);
        }
    }
    public boolean isNonDigit(char c) {
        return (Character.isLetter(c) || c == '_');
    }



    public static void main(String[] args){
        String str="{'3', '\\''}";
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            System.out.println(c);
        }

    }

}

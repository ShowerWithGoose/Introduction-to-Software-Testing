package frontend;

import check.T_type;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import utils.IO;
import utils.IO.*;
public class Lexer {
    private static Map<String, T_type> keywords = new HashMap<String, T_type>() {{
        put("main", T_type.MAINTK);
        put("const", T_type.CONSTTK);
        put("int", T_type.INTTK);
        put("char",T_type.CHARTK);
        put("break", T_type.BREAKTK);
        put("continue", T_type.CONTINUETK);
        put("if", T_type.IFTK);
        put("else", T_type.ELSETK);
        put("for", T_type.FORTK);
        put("getint", T_type.GETINTTK);
        put("getchar", T_type.GETCHARTK);
        put("printf", T_type.PRINTFTK);
        put("return", T_type.RETURNTK);
        put("void", T_type.VOIDTK);
    }};

    private static List<String> contents = new ArrayList<>();
    public static void Lexical_Analyse(String str){
        int judge = 0;//查看是否为错误程序
        int line_number = 1;//当前行号
        int length = str.length();//字符串总长度
        for (int i = 0; i < length; i++) {
            String content;
            String WrongContent;
            char now = str.charAt(i);
            char next;
            if (i==length-1) next = '\n';
            else next = str.charAt(i+1);
            if (now=='\n') line_number++;
            else if (Character.isLetter(now) || now=='_'){
                String value = "";
                for (int j = i; j < length; j++) {
                    char tmp = str.charAt(j);
                    if (Character.isLetter(tmp) || Character.isDigit(tmp) || tmp=='_'){
                        value = value + tmp;
                    }
                    else {
                        i = j - 1;
                        break;//当前第j个字符前的字符组成了一个标识符
                    }
                    if (j==length-1) i = j;
                }
//                System.out.println(keywords.getOrDefault(value,T_type.IDENFR)+" "+value);
                content = keywords.getOrDefault(value,T_type.IDENFR)+" "+value+"\n";
                contents.add(content);
            } else if (Character.isDigit(now)) {
                String value = "";
                for (int j = i; j < length; j++) {
                    char tmp = str.charAt(j);
                    if (Character.isDigit(tmp)){
                        value = value + tmp;
                    }
                    else {
                        i = j - 1;
                        break;//当前第j个字符前的字符组成了一个数字
                    }
                    if (j==length-1) i = j;
                }
//                System.out.println(T_type.INTCON+" "+value);
                content = T_type.INTCON+" "+value+"\n";
                contents.add(content);
            } else if (now == '"') {
                String value = "";
                for (int j = i; j < length; j++) {
                    char tmp = str.charAt(j);
                    value = value + tmp;
                    if (tmp == '"' && j != i){
                        i = j;
                        break;//当前第j个字符前的字符组成了一个字符串常量
                    }
                }
//                System.out.println(T_type.STRCON+" "+value);
                content = T_type.STRCON+" "+value+"\n";
                contents.add(content);
            } else if (now == '\'') {
                String value = "";
                for (int j = i; j < length; j++) {
                    char tmp = str.charAt(j);
                    value = value + tmp;
                    if (tmp == '\'' && j != i){
                        i = j;
                        break;//当前第j个字符前的字符组成了一个字符常量
                    }
                }
//                System.out.println(T_type.CHRCON+" "+value);
                content = T_type.CHRCON+" "+value+"\n";
                contents.add(content);
            } else if (now == '!') {
                if (next == '='){
//                    System.out.println(T_type.NEQ+" "+"!=");
                    content = T_type.NEQ+" "+"!="+"\n";
                    contents.add(content);
                    i++;
                }
                else {
//                    System.out.println(T_type.NOT+" "+"!");
                    content = T_type.NOT+" "+"!"+"\n";
                    contents.add(content);
                }
            } else if (now == '&' || now == '|') {
                if (now == next){
                    if (now == '&') {
//                        System.out.println(T_type.AND+" "+"&&");
                        content = T_type.AND+" "+"&&"+"\n";
                        contents.add(content);
                    }
                    else {
//                        System.out.println(T_type.OR+" "+"||");
                        content = T_type.OR+" "+"||"+"\n";
                        contents.add(content);
                    }
                    i++;
                }
                else {
//                    System.out.println(line_number+" "+"a");
                    WrongContent = line_number+" "+"a"+"\n";
                    IO.write(WrongContent,"error.txt");
                    judge = 1;
                }
            } else if (now == '+') {
//                System.out.println(T_type.PLUS+" " + "+");
                content = T_type.PLUS+" " + "+"+"\n";
                contents.add(content);
            } else if (now == '-') {
//                System.out.println(T_type.MINU+" "+"-");
                content = T_type.MINU+" "+"-"+"\n";
                contents.add(content);
            } else if (now == '*') {
//                System.out.println(T_type.MULT+" "+"*");
                content = T_type.MULT+" "+"*"+"\n";
                contents.add(content);
            } else if (now == '/') {
//                System.out.println(T_type.DIV+" "+"/");
                content = T_type.DIV+" "+"/"+"\n";
                contents.add(content);
            } else if (now == '%') {
//                System.out.println(T_type.MOD+" "+"%");
                content = T_type.MOD+" "+"%"+"\n";
                contents.add(content);
            } else if (now == '<') {
                if (next == '='){
//                    System.out.println(T_type.LEQ+" "+"<=");
                    content = T_type.LEQ+" "+"<="+"\n";
                    contents.add(content);
                    i++;
                }
                else {
//                    System.out.println(T_type.LSS+" "+"<");
                    content = T_type.LSS+" "+"<"+"\n";
                    contents.add(content);
                }
            } else if (now == '>') {
                if (next == '='){
//                    System.out.println(T_type.GEQ+" "+">=");
                    content = T_type.GEQ+" "+">="+"\n";
                    contents.add(content);
                    i++;
                }
                else {
//                    System.out.println(T_type.GRE+" "+">");
                    content = T_type.GRE+" "+">"+"\n";
                    contents.add(content);
                }
            } else if (now == '=') {
                if (next == '='){
//                    System.out.println(T_type.EQL+" "+"==");
                    content = T_type.EQL+" "+"=="+"\n";
                    contents.add(content);
                    i++;
                }
                else {
//                    System.out.println(T_type.ASSIGN+" "+"=");
                    content = T_type.ASSIGN+" "+"="+"\n";
                    contents.add(content);
                }
            } else if (now == ';') {
//                System.out.println(T_type.SEMICN+" "+";");
                content = T_type.SEMICN+" "+";"+"\n";
                contents.add(content);
            } else if (now == ',') {
//                System.out.println(T_type.COMMA+" "+",");
                content = T_type.COMMA+" "+","+"\n";
                contents.add(content);
            } else if (now == '(') {
//                System.out.println(T_type.LPARENT+" "+"(");
                content = T_type.LPARENT+" "+"("+"\n";
                contents.add(content);
            } else if (now == ')') {
//                System.out.println(T_type.RPARENT+" "+")");
                content = T_type.RPARENT+" "+")"+"\n";
                contents.add(content);
            } else if (now == '[') {
//                System.out.println(T_type.LBRACK+" "+"[");
                content = T_type.LBRACK+" "+"["+"\n";
                contents.add(content);
            } else if (now == ']') {
//                System.out.println(T_type.RBRACK+" "+"]");
                content = T_type.RBRACK+" "+"]"+"\n";
                contents.add(content);
            } else if (now == '{') {
//                System.out.println(T_type.LBRACE+" "+"{");
                content = T_type.LBRACE+" "+"{"+"\n";
                contents.add(content);
            } else if (now == '}') {
//                System.out.println(T_type.RBRACE+" "+"}");
                content = T_type.RBRACE+" "+"}"+"\n";
                contents.add(content);
            }
        }
        if (judge != 1){
            for (String content : contents) {
                IO.write(content,"lexer.txt");
            }
        }
    }
}

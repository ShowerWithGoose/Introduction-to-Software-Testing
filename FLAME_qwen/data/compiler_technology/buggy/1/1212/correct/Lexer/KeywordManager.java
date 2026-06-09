package Lexer;

import java.util.Arrays;
import java.util.List;

public class KeywordManager {
    private static class Keyword {
        String name, category;

        Keyword(String name, String category) {
            this.name = name;
            this.category = category;
        }
    }

    // 关键词列表
    private static final List<Keyword> keywords = Arrays.asList(
            new Keyword("if", "IFTK"),
            new Keyword("else", "ELSETK"),
            new Keyword("for", "FORTK"),
            new Keyword("const", "CONSTTK"),
            new Keyword("int", "INTTK"),
            new Keyword("char", "CHARTK"),
            new Keyword("void", "VOIDTK"),
            new Keyword("return", "RETURNTK"),
            new Keyword("main", "MAINTK"),
            new Keyword("=", "ASSIGN"),
            new Keyword("<", "LSS"),
            new Keyword("<=", "LEQ"),
            new Keyword(">", "GRE"),
            new Keyword(">=", "GEQ"),
            new Keyword("==", "EQL"),
            new Keyword("!=", "NEQ"),
            new Keyword("+", "PLUS"),
            new Keyword("-", "MINU"),
            new Keyword("*", "MULT"),
            new Keyword("/", "DIV"),
            new Keyword("%", "MOD"),
            new Keyword("printf", "PRINTFTK"),
            new Keyword(";", "SEMICN"),
            new Keyword(",", "COMMA"),
            new Keyword(",", "COMMA"),
            new Keyword("(", "LPARENT"),
            new Keyword(")", "RPARENT"),
            new Keyword("[", "LBRACK"),
            new Keyword("]", "RBRACK"),
            new Keyword("{", "LBRACE"),
            new Keyword("}", "RBRACE"),
            new Keyword("break", "BREAKTK"),
            new Keyword("continue", "CONTINUETK"),
            new Keyword("||", "OR"),
            new Keyword("&&", "AND"),
            new Keyword("!", "NOT"),
            new Keyword("getint", "GETINTTK"),
            new Keyword("getchar", "GETCHARTK")


    );

    // 获取单词的类别
    public String getKeywordCategory(String word) {
        for (Keyword keyword : keywords) {
            if (keyword.name.equals(word)) {
                return keyword.category;
            }
        }
        return null;
    }


    // 判断是否为单字符操作符
    public boolean isSingleCharOperator(char c) {
        return "+-*/%()[]{};,<>!=?&|".indexOf(c) != -1;
    }
}

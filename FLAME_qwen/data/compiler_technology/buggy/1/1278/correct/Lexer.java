import Tools.Token;
import Tools.myError;

import java.util.ArrayList;

public class Lexer {
    private static ArrayList<Token> tokens = new ArrayList<>();
    public static void tokenize(String input) {

        int length = input.length();
        int lineno = 1;
        boolean LineComments = false;
        boolean ParagraphComments = false;

        for (int i = 0; i < length; i++) {
            char currentChar = input.charAt(i);
            if (isLinkBreak(currentChar)) { //匹配换行符
                lineno++;
                LineComments = false;
            } else if (ParagraphComments && currentChar == '*') {
                if (input.charAt(i + 1) == '/') {
                    i++;
                    ParagraphComments = false;
                }
            } else if (Character.isWhitespace(currentChar) || LineComments || ParagraphComments) {
                continue;
            } else if (currentChar == '\'') { // 匹配字符常量
                char nextChar = input.charAt(i + 1);
                String ch = null;
                if (nextChar == '\\') {
                    char escapedChar = input.charAt(i + 2);
                    switch (escapedChar) {
                        case 'a': case 'b': case 't':
                        case 'n': case 'v': case 'f':
                        case '\"': case '\\': case '\'':
                        case '0':
                            ch = "'\\"  + escapedChar + "'";
                            break;
                        default:
                            System.out.println("error_escapedChar");
                    }
                    i += 3; // 跳过转义字符
                } else { // 非转义字符处理
                    ch = "'" + nextChar + "'";
                    i += 2;
                }
                tokens.add(new Token(Token.TokenType.CHRCON, ch, lineno));
            } else if (currentChar == '\"') { //匹配“”字符串
                StringBuilder str = new StringBuilder();
                str.append('\"');
                i++;
                while (input.charAt(i) != '\"') {
                    str.append(input.charAt(i));
                    i++;
                }
                str.append(input.charAt(i));
                tokens.add(new Token(Token.TokenType.STRCON, str.toString(), lineno));
            } else if (Character.isDigit(currentChar)) {
                StringBuilder number = new StringBuilder();
                while (i < length && Character.isDigit(input.charAt(i))) {
                    number.append(input.charAt(i));
                    i++;
                }
                i--; // 回退
                tokens.add(new Token(Token.TokenType.INTCON, number.toString(), lineno));

            } else if (Character.isLetter(currentChar) || currentChar == '_') {
                StringBuilder identifier = new StringBuilder();
                while (i < length && (Character.isLetterOrDigit(input.charAt(i)) || input.charAt(i) == '_')) {
                    identifier.append(input.charAt(i));
                    i++;
                }
                i--; // 回退
                String str = identifier.toString();
                Token.TokenType tk = Token.getMatchListLetter(str); // 匹配字符串
                tokens.add(new Token(tk, str, lineno));

            } else {
                StringBuilder str = new StringBuilder();
                str.append(currentChar);
                switch (currentChar) {
                    case '!': case '<': case '>':
                    case '=':
                        if (input.charAt(i + 1) == '=') {
                            i++;
                            str.append('=');
                        }
                        break;
                    case '&':
                        if (input.charAt(i + 1) == '&') {
                            i++;
                            str.append('&');
                        } else {
                            str.append('&');
                            myError.newError(myError.ErrorType.ERROR_A, lineno);
                        }
                        break;
                    case '|':
                        if (input.charAt(i + 1) == '|') {
                            i++;
                            str.append('|');
                        } else {
                            str.append('|');
                            myError.newError(myError.ErrorType.ERROR_A, lineno);
                        }
                        break;
                    case '/':
                        if(input.charAt(i + 1) == '/') {
                            i++;
                            LineComments = true;
                            continue;
                        } else if(input.charAt(i + 1) == '*'){
                            i++;
                            ParagraphComments = true;
                            continue;
                        }
                        break;
                    default:
                } // 匹配符号
                Token.TokenType tk = Token.getMatchListSign(str.toString());
                tokens.add(new Token(tk, str.toString(), lineno));
            }
        }
    }

    private static boolean isLinkBreak(char c) {
        return c == '\n';
    }

    public static ArrayList<Token> getTokens() {
        return tokens;
    }


}

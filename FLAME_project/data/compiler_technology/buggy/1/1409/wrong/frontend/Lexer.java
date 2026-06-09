package frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Map;

public class Lexer {

    private InputStreamReader inputStreamReader;

    private final static Map<String, LexType> reserveWords = Map.ofEntries(
            Map.entry("main", LexType.MAINTK),
            Map.entry("const", LexType.CONSTTK),
            Map.entry("int", LexType.INTTK),
            Map.entry("char", LexType.CHARTK),
            Map.entry("break", LexType.BREAKTK),
            Map.entry("continue", LexType.CONTINUETK),
            Map.entry("if", LexType.IFTK),
            Map.entry("else", LexType.ELSETK),
            Map.entry("for", LexType.FORTK),
            Map.entry("getint", LexType.GETINTTK),
            Map.entry("getchar", LexType.GETCHARTK),
            Map.entry("printf", LexType.PRINTFTK),
            Map.entry("return", LexType.RETURNTK),
            Map.entry("void", LexType.VOIDTK)
    );

    private String source = null;  //每次读取一行字符串
    private int curPos;  //指针在一行字符串中指向的位置
    private int lineNum = 0;  //行号
    private String token = null;  //单词指
    private LexType lexType = null;  //单词类型
    private int Number = 0;  //解析数值

    private BufferedReader br;

    private ErrorType errorType = null;


    public Lexer(InputStream stream) {
        inputStreamReader = new InputStreamReader(stream);
        br = new BufferedReader(inputStreamReader);
    }

    public boolean isNonDigit(char c) {
        return Character.isLetter(c) || c == '_';
    }

    public int readNewLine() throws IOException {
        while ((source = br.readLine()) != null) {
            lineNum++;
            if (source.length() > 0) {
                break;
            }
        }
        if(source == null)
        {
            return -1;
        }

        curPos = 0;
        return 0;  //标识已经正常读取新的line
    }

    public boolean isAscii(char ch, StringBuilder sb) {

        if(ch == '\\')
        {
            curPos = curPos + 1;
            sb.append('\\');
            if(curPos < source.length())
            {
                ch = source.charAt(curPos);
                if(ch == 'a' || ch == 'b' || ch == 't' || ch == 'n'
                        || ch == 'v' || ch == 'f' || ch == '\'' ||
                        ch == '\"' || ch == '\\' || ch == '0')
                {
                    sb.append(ch);
                    return true;
                }
                if(ch == 'r')
                {
                    return false;
                }
            }
        }
        else if((int)ch >=32 && (int)ch <= 126)
        {
            sb.append(ch);
            return true;
        }

        return false;
    }

    public LexType isReserve()
    {
        return reserveWords.get(token);
    }

    public int next() throws IOException{
        if(source == null || curPos >= source.length()) {
            int back = readNewLine();
            if(back == -1) {
                return -1;
            }
        }


        token = "";
        StringBuilder sb = new StringBuilder(token);
        char ch = source.charAt(curPos);
        if(isNonDigit(ch)) { // 标识符或保留字
            sb.append(ch);
            curPos = curPos + 1;
            while(curPos < source.length() &&
                    (isNonDigit(source.charAt(curPos)) || Character.isDigit(source.charAt(curPos)))) {
                // 下一个字符为数字或字母
                ch = source.charAt(curPos);
                sb.append(ch);
                curPos = curPos + 1;
            }
            token = sb.toString();
            if(isReserve() != null)
            {
                lexType = isReserve();
                return 1;
            }
            else {
                lexType = LexType.IDENFR;
                return 1;
            }
        }

        else if(Character.isDigit(ch))
        {
            sb.append(ch);
            curPos = curPos + 1;
            while(curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
                ch = source.charAt(curPos);
                curPos = curPos + 1;
                sb.append(ch);
            }
            lexType = LexType.INTCON;
            token = sb.toString();
            //Number = Integer.valueOf(token);
            return 1;
        }

        else if (ch == '/') {
            curPos = curPos + 1;
            if(curPos < source.length() && source.charAt(curPos) == '/') //单行注释
            {
                curPos = curPos + 1;
                while (curPos < source.length() && source.charAt(curPos) != '\n') {
                    curPos = curPos + 1;
                }
                //lineNum = lineNum + 1;  //注释结束算作一行
                return 0; //注释不输出
            }
            else if (curPos < source.length() && source.charAt(curPos) == '*') //多行注释
            {
                curPos = curPos + 1;
                int back = 0;
                if(curPos >= source.length())
                {
                    back = readNewLine();
                    if(back == -1)
                    {
                        return -1;
                    }
                }

                while(true)
                {
                    while (source.charAt(curPos) != '*') {
//                        if(source.charAt(curPos) == '\n')
//                        {
//
//                            lineNum = lineNum + 1;
//                        }
                        curPos = curPos + 1;
                        if(curPos >= source.length())
                        {
                            back = readNewLine();
                            if(back == -1)
                            {
                                return -1;
                            }
                        }
                    }
                    while (source.charAt(curPos) == '*') {
                        curPos = curPos + 1;
                        if(curPos >= source.length())
                        {
                            back = readNewLine();
                            if(back == -1)
                            {
                                return -1;
                            }
                        }
                    }
                    if(source.charAt(curPos) == '/')
                    {
                        curPos = curPos + 1;
                        break;
                    }
                }

                return 0;
            }

            else //除号的情况
            {
                token = "/";
                lexType = LexType.DIV;
                return 1;
            }
        }

        else if(ch == '\'')
        {
            curPos = curPos + 1;
            sb.append(ch);  // token = '
            if(curPos < source.length())
            {
                ch = source.charAt(curPos);
                if(isAscii(ch, sb)) //token = 'a   or   '\a
                {
                    curPos = curPos + 1;
                    if(curPos < source.length() && source.charAt(curPos) == '\'')
                    {
                        sb.append(source.charAt(curPos));
                        token = sb.toString();
                        lexType = LexType.CHRCON;
                        curPos = curPos + 1;
                        return 1;
                    }
                }

            }
        }

        else if(ch == '\"')
        {
            curPos = curPos + 1;
           // System.out.println("here");
            sb.append(ch);

            while(curPos < source.length() && source.charAt(curPos) != '\"')
            {
                sb.append(source.charAt(curPos));
                curPos = curPos + 1;
            }
            sb.append(source.charAt(curPos));
            curPos = curPos + 1;
            token = sb.toString();
            lexType = LexType.STRCON;
            return 1;
        }

        else if(ch == '!')
        {
            curPos = curPos + 1;
            if(curPos < source.length() && source.charAt(curPos) == '=')
            {
                token = "!=";
                lexType = LexType.NEQ;
                curPos = curPos + 1;
            }
            else {
                token = "!";
                lexType = LexType.NOT; //因为指针已经走到！下一个位置，所以不用再移动；
            }
            return 1;
        }

        else if(ch == '&')
        {
            curPos = curPos + 1;
            if(curPos < source.length() && source.charAt(curPos) == '&')
            {
                token = "&&";
                lexType = LexType.AND;
                curPos = curPos + 1;
                return 1;
            }
            else {
                //System.out.println("error");
                errorType = errorType.a;
                token = "&";
                lexType = LexType.AND;
                return -2;
                // *** &的a类error处理
            }
        }

        else if(ch == '|')
        {
            curPos = curPos + 1;
            if(curPos < source.length() && source.charAt(curPos) == '|')
            {
                token = "||";
                lexType = LexType.OR;
                curPos = curPos + 1;
                return 1;
            }
            else {
                errorType = errorType.a;
                token = "|";
                lexType = LexType.OR;
                return -2;
                // *** |的a类error处理
            }
        }

        else if(ch == '+')
        {
            token = "+";
            lexType = LexType.PLUS;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == '-')
        {
            token = "-";
            lexType = LexType.MINU;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == '*')
        {
            token = "*";
            lexType = LexType.MULT;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == '%')
        {
            token = "%";
            lexType = LexType.MOD;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == '<')
        {
            curPos = curPos + 1;
            if(curPos < source.length() && source.charAt(curPos) == '=')
            {
                token = "<=";
                lexType = LexType.LEQ;
                curPos = curPos + 1;
            }
            else {
                token = "<";
                lexType = LexType.LSS;
            }
            return 1;
        }

        else if(ch == '>')
        {
            curPos = curPos + 1;
            if(curPos < source.length() && source.charAt(curPos) == '=')
            {
                token = ">=";
                lexType = LexType.GEQ;
                curPos = curPos + 1;
            }
            else {
                token = ">";
                lexType = LexType.GRE;
            }
            return 1;
        }

        else if(ch == '=')
        {
            curPos = curPos + 1;
            if(curPos < source.length() && source.charAt(curPos) == '=')
            {
                token = "==";
                lexType = LexType.EQL;
                curPos = curPos + 1;
            }
            else {
                token = "=";
                lexType = LexType.ASSIGN;
            }
            return 1;
        }

        else if(ch == ';')
        {
            token = ";";
            lexType = LexType.SEMICN;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == ',')
        {
            token = ",";
            lexType = LexType.COMMA;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == '(')
        {
            token = "(";
            lexType = LexType.LPARENT;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == ')')
        {
            token = ")";
            lexType = LexType.RPARENT;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == '[')
        {
            token = "[";
            lexType = LexType.LBRACK;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == ']')
        {
            token = "]";
            lexType = LexType.RBRACK;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == '{')
        {
            token = "{";
            lexType = LexType.LBRACE;
            curPos = curPos + 1;
            return 1;
        }

        else if(ch == '}')
        {
            token = "}";
            lexType = LexType.RBRACE;
            curPos = curPos + 1;
            return 1;
        }

        else
        {
            curPos = curPos + 1;
        }

        return 0;
    }

    public String getValue()
    {
        return token;
    }

    public LexType getLexType()
    {
        return lexType;
    }

    public ErrorType getErrorType()
    {
        return errorType;
    }

    public int getLineNum()
    {
        return lineNum;
    }
}

import java.io.*;

public class MyFileReader {
    private String filePath;
    private StringBuffer token;
    private StringBuffer text;
    private int ptr;
    private int curLine;
    private char curChar;

    public MyFileReader(String filePath) {
        this.filePath = filePath;
        this.ptr = 0;
        this.curLine = 1;
        this.token = new StringBuffer();
        this.text = new StringBuffer();
        try {
            File file = new File(filePath);
            FileInputStream inputStream = new FileInputStream(file);
            InputStreamReader reader = new InputStreamReader(inputStream);
            while (reader.ready()) {
                text.append((char) reader.read());
            }
            // System.out.println(text.toString());
            reader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.text.append('\n');
        this.text.append((char)0);
    }

    /**
     * 将行号加一
     */
    public void pushLine() {
        this.curLine++;
    }

    /**
     * 将行号后退一
     */
    public void retractLine() {
        this.curLine--;
        if (this.curLine < 0) throw new RuntimeException("retract line unavailable");
    }

    /**
     * 返回当前指针所在行
     *
     * @return 行号，用Integer表示
     */
    public int getCurLine() {
        return curLine;
    }

    public void catToken() {
        this.token.append(this.text.charAt(ptr));
    }

    public void clearToken() {
        this.token = new StringBuffer();
    }

    public void getChar() {
        this.ptr++;
        this.curChar = this.text.charAt(this.ptr);
    }

    public void retract() {
        this.ptr--;
        if (this.ptr < 0) throw new RuntimeException("retract ptr unavailable");
    }

    public StringBuffer getToken() {
        return this.token;
    }

    public StringBuffer getText() {
        return this.text;
    }

    /**
     * 当前ptr字符是否是空格
     *
     * @return 是或否
     */
    public boolean isSpace() {
        int temp = (int) this.text.charAt(ptr);
        return (temp <= 15 && temp >= 11) || temp == 32;
    }

    /**
     * 当前ptr字符是否是换行符\n或\r
     *
     * @return 是或否
     */
    public boolean isNewlineN() {
        return this.text.charAt(ptr) == '\n';
    }

    /**
     * 当前ptr字符是否是换行符\r
     *
     * @return 是或否
     */
    public boolean isNewlineR() {
        return this.text.charAt(ptr) == '\r';
    }

    /**
     * 当前ptr字符是否是Tab
     *
     * @return 是或否
     */
    public boolean isTab() {
        return this.text.charAt(ptr) == '\t';
    }

    /**
     * 当前ptr字符是否是字母
     *
     * @return 是或否
     */
    public boolean isLetter() {
        return (this.text.charAt(ptr) >= 'a' && this.text.charAt(ptr) <= 'z')
                || (this.text.charAt(ptr) >= 'A' && (this.text.charAt(ptr) <= 'Z'))
                || this.text.charAt(ptr) == '_';
    }

    /**
     * 当前ptr字符是否是数字0~9
     *
     * @return 是或否
     */
    public boolean isDigit() {
        return this.text.charAt(ptr) >= '0' && this.text.charAt(ptr) <= '9';
    }

    /**
     * 当前ptr字符是否是非零数字
     *
     * @return 是或否
     */
    public boolean isNZeroDigit() {
        return this.text.charAt(ptr) >= '1' && this.text.charAt(ptr) <= '9';
    }

    /**
     * 当前ptr字符是否是逗号
     *
     * @return 是或否
     */
    public boolean isComma() {
        return this.text.charAt(ptr) == ',';
    }

    /**
     * 当前ptr字符是否是分号
     *
     * @return 是或否
     */
    public boolean isSemi() {
        return this.text.charAt(ptr) == ';';
    }

    /**
     * 当前ptr字符是否是等号
     *
     * @return 是或否
     */
    public boolean isEqu() {
        return this.text.charAt(ptr) == '=';
    }

    /**
     * 当前ptr字符是否是加号
     *
     * @return 是或否
     */
    public boolean isPlus() {
        return this.text.charAt(ptr) == '+';
    }

    /**
     * 当前ptr字符是否是减号
     *
     * @return 是或否
     */
    public boolean isMinus() {
        return this.text.charAt(ptr) == '-';
    }

    /**
     * 当前ptr字符是否是除号
     *
     * @return 是或否
     */
    public boolean isDiv() {
        return this.text.charAt(ptr) == '/';
    }

    /**
     * 当前ptr字符是否是乘号
     *
     * @return 是或否
     */
    public boolean isMulti() {
        return this.text.charAt(ptr) == '*';
    }

    /**
     * 当前ptr字符是否是求模符号
     *
     * @return 是或否
     */
    public boolean isMod() {
        return this.text.charAt(ptr) == '%';
    }

    /**
     * 当前ptr字符是否是&
     *
     * @return 是或否
     */
    public boolean isAnd() {
        return this.text.charAt(ptr) == '&';
    }

    /**
     * 当前ptr字符是否是|
     *
     * @return 是或否
     */
    public boolean isOr() {
        return this.text.charAt(ptr) == '|';
    }

    /**
     * 当前ptr字符是否是小于号
     *
     * @return 是或否
     */
    public boolean isLss() {
        return this.text.charAt(ptr) == '<';
    }

    /**
     * 当前ptr字符是否是大于号
     *
     * @return 是或否
     */
    public boolean isGre() {
        return this.text.charAt(ptr) == '>';
    }

    /**
     * 当前ptr字符是否是感叹号
     *
     * @return 是或否
     */
    public boolean isExclamation() {
        return this.text.charAt(ptr) == '!';
    }

    /**
     * 当前ptr字符是否是左括号
     *
     * @return 是或否
     */
    public boolean isLeftParent() {
        return this.text.charAt(ptr) == '(';
    }

    /**
     * 当前ptr字符是否是右括号
     *
     * @return 是或否
     */
    public boolean isRightParent() {
        return this.text.charAt(ptr) == ')';
    }

    /**
     * 当前ptr字符是否是左中括号
     *
     * @return 是或否
     */
    public boolean isLeftBracket() {
        return this.text.charAt(ptr) == '[';
    }

    /**
     * 当前ptr字符是否是右中括号
     *
     * @return 是或否
     */
    public boolean isRightBracket() {
        return this.text.charAt(ptr) == ']';
    }

    /**
     * 当前ptr字符是否是左大括号
     *
     * @return 是或否
     */
    public boolean isLeftBrace() {
        return this.text.charAt(ptr) == '{';
    }

    /**
     * 当前ptr字符是否是右大括号
     *
     * @return 是或否
     */
    public boolean isRightBrace() {
        return this.text.charAt(ptr) == '}';
    }

    /**
     * 当前ptr字符是否是反斜杠
     *
     * @return 是或否
     */
    public boolean isEscape() {
        return this.text.charAt(ptr) == '\\';
    }

    /**
     * 当前ptr字符是否是单引号
     *
     * @return 是或否
     */
    public boolean isSinQuotation() {
        return this.text.charAt(ptr) == '\'';
    }

    /**
     * 当前ptr字符是否是双引号
     *
     * @return 是或否
     */
    public boolean isDouQuotation() {
        return this.text.charAt(ptr) == '\"';
    }

    /**
     * 当前ptr字符是否是结束符号
     *
     * @return 是或否
     */
    public boolean isEOT() {
        return (int) this.text.charAt(ptr) == 0;
    }
}
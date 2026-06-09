package Frontend;

public class Lexer implements reserveWords{
    private int curPos;
    private int lineNum;
    private int number;
    private Character character;
    private LexType type;
    //private StringBuilder token;  还是不行，因为词法分析只有analyze是按照单词，得不到前一个单词
    private Token token;
    private final StringBuilder contents;
     //    reserveWords;用来记录是否是ident

    public Lexer(StringBuilder a) {
        curPos = 0;
        lineNum = 1;
        contents = a;
        //token = new StringBuilder();
        reserveWords.put("main","MAINTK");
        reserveWords.put("const","CONSTTK");
        reserveWords.put("int","INTTK");
        reserveWords.put("char","CHARTK");
        reserveWords.put("break","BREAKTK");
        reserveWords.put("continue","CONTINUETK");
        reserveWords.put("if","IFTK");
        reserveWords.put("else","ELSETK");
        reserveWords.put("for","FORTK");
        reserveWords.put("getint","GETINTTK");
        reserveWords.put("getchar","GETCHARTK");
        reserveWords.put("printf","PRINTFTK");
        reserveWords.put("return","RETURNTK");
        reserveWords.put("void","VOIDTK");
    }

    public boolean isEnd() {
        return curPos >= contents.length() - 1;
    }

    public void nextCharacter() {
        character = contents.charAt(curPos);
        curPos++;
    }

    public void outCharacter() {
        curPos--;
    }

    public Token getToken() {
        return token;
    }

    public LexType getLexType() {
        return type;
    }

    public int getlineNUM() {
        return lineNum;
    }
    public int getCurPos() {
        return curPos;
    }

    public void addToken() {
        token.addToken(character,lineNum);
    }

    public void tokenClear() {
        token = new Token();
    }

    public int analyze() {
        tokenClear();
        nextCharacter();
        // ' '，制表符，换行符直接跳过；
        while (character.equals(' ') || character.equals('\t') || character.equals('\n')) {
            if (character.equals('\n')) {
                lineNum++;
            }
            if (curPos == contents.length() - 1) {
                return -2;
            }
            nextCharacter();
        }
        // 识别标识符/保留字
        if (Character.isLetter(character) || character == '_') {
            while (Character.isLetter(character) || Character.isDigit(character) || character == '_') {
                addToken();
                nextCharacter();
            }
            outCharacter();     //退一个,让curPos指向下一个位置
            boolean isHave = reserveWords.containsKey(token.getToken().toString());
            if (isHave) {
                String e = reserveWords.get(token.getToken().toString());
                type = LexType.valueOf(e);
            }
            else {
                reserveWords.put(token.getToken().toString(),"IDENFR");
                type = LexType.IDENFR;
            }
        }
        // 数字
        else if (Character.isDigit(character)) {
            while (Character.isDigit(character)) {
                addToken();
                nextCharacter();
            }
            number = Integer.parseInt(token.getToken().toString());
            outCharacter();
            type = LexType.INTCON;
        }
        // STRCON
        else if (character == '\"') {
            do {
                addToken();
                nextCharacter();
            }
            while (character != '\"');
            addToken();
            type = LexType.STRCON;
        }
        // CHRCON
        else if (character == '\'') {
            do {
                addToken();
                nextCharacter();
            }
            while (character != '\'');
            addToken();
            nextCharacter();
            if (character == '\'') {
                addToken();
            }
            else {
                outCharacter();
            }
            type = LexType.CHRCON;
        }
        // NOT & NEQ
        else if (character == '!') {
            addToken();
            nextCharacter();
            if (character == '=') {
                addToken();
                type = LexType.NEQ;
            }
            else {
                outCharacter();
                type = LexType.NOT;
            }
        }
        // AND
        else if (character == '&') {
            addToken();
            nextCharacter();
            if (character == '&') {
                addToken();
                type = LexType.AND;
            }
            else {
                //token.append('&');
                token.addToken('&',lineNum);
                type = LexType.AND;
                token.setType(type);
                outCharacter();
                return -1;          // first error；
            }
        }
        // OR
        else if (character == '|') {
            addToken();
            nextCharacter();
            if (character == '|') {
                addToken();
                type = LexType.OR;
            }
            else {
                //token.append('|');
                token.addToken('|',lineNum);
                type = LexType.OR;
                token.setType(type);
                outCharacter();
                return -1;          // second error；
            }
        }
        // + - * % ; , ( ) [ ] { }
        else if (character == '+') {
            addToken();
            type = LexType.PLUS;
        }
        else if (character == '-') {
            addToken();
            type = LexType.MINU;
        }
        else if (character == '*') {
            addToken();
            type = LexType.MULT;
        }
        else if (character == '%') {
            addToken();
            type = LexType.MOD;
        }
        else if (character == ';') {
            addToken();
            type = LexType.SEMICN;
        }
        else if (character == ',') {
            addToken();
            type = LexType.COMMA;
        }
        else if (character == '(') {
            addToken();
            type = LexType.LPARENT;
        }
        else if (character == ')') {
            addToken();
            type = LexType.RPARENT;
        }
        else if (character == '[') {
            addToken();
            type = LexType.LBRACK;
        }
        else if (character == ']') {
            addToken();
            type = LexType.RBRACK;
        }
        else if (character == '{') {
            addToken();
            type = LexType.LBRACE;
        }
        else if (character == '}') {
            addToken();
            type = LexType.RBRACE;
        }
        // < <= > >= == =
        else if (character == '<') {
            addToken();
            nextCharacter();
            if (character == '=') {
                addToken();
                type = LexType.LEQ;
            }
            else {
                outCharacter();
                type = LexType.LSS;
            }
        }
        else if(character == '>') {
            addToken();
            nextCharacter();
            if (character == '=') {
                addToken();
                type = LexType.GEQ;
            }
            else {
                outCharacter();
                type = LexType.GRE;
            }
        }
        else if(character == '=') {
            addToken();
            nextCharacter();
            if (character == '=') {
                addToken();
                type = LexType.EQL;
            }
            else {
                outCharacter();
                type = LexType.ASSIGN;
            }
        }
        // 注释
        else if (character == '/') {
            addToken();
            nextCharacter();
            if (character != '/' && character != '*') {
                outCharacter();
                type = LexType.DIV;
            }
            else if (character == '/') {
                do {
                    addToken();
                    nextCharacter();
                } while (character != '\n');
                lineNum++;
                return -2;
            }
            else {
                while (curPos < contents.length()) {
                    do {
                        if (character == '\n') {
                            lineNum++;
                        }
                        addToken();
                        nextCharacter();
                    } while (character != '*');
                    addToken();
                    nextCharacter();
                    if (character == '\n') {
                        lineNum++;
                    }
                    if (character == '/') {
                        addToken();
                        return -2;
                    }
                }
                return -1;
            }
        }/*adadawd**da///wda*
        adwa*/
        token.setType(type);
        return 0;
    }

    public LexType preRead(int i) {
        int now = curPos;
        int nowLine = lineNum;
        for (int j = 0; j < i; j++) {
            analyze();
        }
        curPos = now;
        lineNum = nowLine;
        return type;
    }

    public void reStart(int i) {
        curPos = i;
    }

    public void setLineNum(int i) {
        lineNum = i;
    }
}

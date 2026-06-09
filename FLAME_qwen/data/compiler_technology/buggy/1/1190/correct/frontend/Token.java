package frontend;

public interface Token {
    String toString();

    String error();

    char getErrorCode();

    void setErrorCode(char errorCode);

    int getLine();

    frontend.Token.Type getType();

    enum Type {
        //Ident
        IDENFR,
        CONSTTK, INTTK, CHARTK, VOIDTK,
        IFTK, ELSETK, BREAKTK, CONTINUETK, FORTK, RETURNTK,
        MAINTK, GETINTTK, GETCHARTK, PRINTFTK,

        //Number
        INTCON,

        //Symbol
        STRCON, CHRCON, COMMA, SEMICN,
        LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
        NOT, OR, AND, EQL, NEQ, GRE, GEQ, LSS, LEQ,
        PLUS, MINU, MULT, DIV, MOD, ASSIGN,

        //Error
        ERROR
    }

    class IdentToken implements Token {

        private final Type type;
        private final String value;
        private final int ln;

        private char errorCode = 0;

        IdentToken(String value) {
            this.ln = Lexer.nowLine;
            this.value = value;
            switch (value) {
                case "int":
                    this.type = Type.INTTK;
                    break;
                case "char":
                    this.type = Type.CHARTK;
                    break;
                case "void":
                    this.type = Type.VOIDTK;
                    break;
                case "const":
                    this.type = Type.CONSTTK;
                    break;
                case "if":
                    this.type = Type.IFTK;
                    break;
                case "else":
                    this.type = Type.ELSETK;
                    break;
                case "break":
                    this.type = Type.BREAKTK;
                    break;
                case "continue":
                    this.type = Type.CONTINUETK;
                    break;
                case "for":
                    this.type = Type.FORTK;
                    break;
                case "return":
                    this.type = Type.RETURNTK;
                    break;
                case "main":
                    this.type = Type.MAINTK;
                    break;
                case "printf":
                    this.type = Type.PRINTFTK;
                    break;
                case "getint":
                    this.type = Type.GETINTTK;
                    break;
                case "getchar":
                    this.type = Type.GETCHARTK;
                    break;
                default:
                    this.type = Type.IDENFR;
                    break;
            }
        }

        @Override
        public String toString() {
            return String.format("%s %s\n", type, value);
        }

        @Override
        public String error() {
            if (errorCode == 0) {
                return "";
            }
            return String.format("%d %c\n", ln, errorCode);
        }

        @Override
        public char getErrorCode() {
            return this.errorCode;
        }

        @Override
        public void setErrorCode(char errorCode) {
            this.errorCode = errorCode;
        }

        @Override
        public int getLine() {
            return this.ln;
        }

        @Override
        public Type getType() {
            return this.type;
        }
    }

    class NumberToken implements Token {

        private final Type type;
        private final String value;
        private final int ln;
        private char errorCode = 0;

        NumberToken(String value) {
            this.ln = Lexer.nowLine;
            this.value = value;
            this.type = Type.INTCON;
        }

        @Override
        public String toString() {
            return String.format("%s %s\n", type, value);
        }

        @Override
        public String error() {
            if (errorCode == 0) {
                return "";
            }
            return String.format("%d %c\n", ln, errorCode);
        }

        @Override
        public char getErrorCode() {
            return this.errorCode;
        }

        @Override
        public void setErrorCode(char errorCode) {
            this.errorCode = errorCode;
        }

        @Override
        public int getLine() {
            return this.ln;
        }

        @Override
        public Type getType() {
            return this.type;
        }
    }

    class SymbolToken implements Token {

        private final Type type;
        private final String value;
        private final int ln;
        private char errorCode = 0;

        SymbolToken(String value) {
            this.ln = Lexer.nowLine;
            this.value = value;
            switch (value) {
                case ",":
                    this.type = Type.COMMA;
                    break;
                case ";":
                    this.type = Type.SEMICN;
                    break;
                case "(":
                    this.type = Type.LPARENT;
                    break;
                case ")":
                    this.type = Type.RPARENT;
                    break;
                case "[":
                    this.type = Type.LBRACK;
                    break;
                case "]":
                    this.type = Type.RBRACK;
                    break;
                case "{":
                    this.type = Type.LBRACE;
                    break;
                case "}":
                    this.type = Type.RBRACE;
                    break;
                case "!":
                    this.type = Type.NOT;
                    break;
                case "||":
                    this.type = Type.OR;
                    break;
                case "&&":
                    this.type = Type.AND;
                    break;
                case "==":
                    this.type = Type.EQL;
                    break;
                case "!=":
                    this.type = Type.NEQ;
                    break;
                case ">":
                    this.type = Type.GRE;
                    break;
                case ">=":
                    this.type = Type.GEQ;
                    break;
                case "<":
                    this.type = Type.LSS;
                    break;
                case "<=":
                    this.type = Type.LEQ;
                    break;
                case "+":
                    this.type = Type.PLUS;
                    break;
                case "-":
                    this.type = Type.MINU;
                    break;
                case "*":
                    this.type = Type.MULT;
                    break;
                case "/":
                    this.type = Type.DIV;
                    break;
                case "%":
                    this.type = Type.MOD;
                    break;
                case "=":
                    this.type = Type.ASSIGN;
                    break;
                case "|":
                    this.type = Type.OR;
                    this.errorCode = 'a';
                    break;
                case "&":
                    this.type = Type.AND;
                    this.errorCode = 'a';
                    break;
                default:
                    if (value.charAt(0) == '"' && value.charAt(value.length() - 1) == '"') {
                        //TODO: "he says, \"Hello!\".\n"
                        this.type = Type.STRCON;
                    } else if (value.charAt(0) == '\'' && value.charAt(value.length() - 1) == '\'') {
                        //TODO: 其他的CHAR_CONTENT的格式：'\'', '\n', '\32', '\126', ...
                        this.type = Type.CHRCON;
                    } else {
                        this.type = Type.ERROR;
                        this.errorCode = 'u'; // unknown
                    }
            }
        }

        @Override
        public String toString() {
            return String.format("%s %s\n", type, value);
        }

        @Override
        public String error() {
            if (errorCode == 0) {
                return "";
            }
            return String.format("%d %c\n", ln, errorCode);
        }

        @Override
        public char getErrorCode() {
            return this.errorCode;
        }

        @Override
        public void setErrorCode(char errorCode) {
            this.errorCode = errorCode;
        }

        @Override
        public int getLine() {
            return this.ln;
        }

        @Override
        public Type getType() {
            return this.type;
        }
    }
}

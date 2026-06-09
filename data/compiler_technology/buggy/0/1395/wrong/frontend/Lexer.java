package frontend;

import frontend.tokens.*;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Lexer {
    /**
     * source code
     */
    private final String sourceCode;
    /**
     * 当前的行数
     */
    private int line;
    /**
     * 总的字符位置
     */
    private int pos;
    /**
     * 最终目标
     */
    private final ArrayList<Token> tokens;
    /**
     * errors
     */
    private final ArrayList<Error> errors;


    public Lexer(String sourceCode, ArrayList<Error> errors) {
        this.sourceCode = sourceCode;
        this.line = 1;
        this.pos = 0;
        this.tokens = new ArrayList<>();
        this.errors = errors;
    }

    /**
     * 跑Lexer
     */
    public ArrayList<Token> lex() {
        while (pos < sourceCode.length()) {
            Token token = getToken();
            if (token != null) {
                pos += token.getContent().length();
                line += token.getContent().split("\n").length - 1;
                if (token.getType() != TokenType.BLANK &&
                        token.getType() != TokenType.LINECOMMENT &&
                        token.getType() != TokenType.BLOCKCOMMENT) {
                    tokens.add(token);
                }
            } else {  // 这儿关于出错的情况，我只考虑了“&”和“|”这两种（毕竟评测说了就这两种错误）
                pos++;
            }
        }
        return tokens;
    }

    /**
     * 获取下一个token getToken
     */
    private Token getToken() {
        String tmp;

        // 匹配到LineComment
        if (myMatch("//") != null) {
            int end = LineComment.getLineComment(sourceCode, pos);
            return new LineComment(sourceCode.substring(pos, end), line);
        }
        // 匹配到BlockComment
        if (myMatch("/\\*") != null) {
            int end = BlockComment.getBlockComment(sourceCode, pos);
            return new BlockComment(sourceCode.substring(pos, end), line);
        }

        boolean isKeyword = true;
        if (isKeyword) {
            if ((tmp = myMatch("main(?![a-zA-Z0-9_])")) != null) { // 匹配main
                return new MainTK(tmp, line);
            } else if ((tmp = myMatch("const(?![a-zA-Z0-9_])")) != null) { // 匹配const
                return new ConstTK(tmp, line);
            } else if ((tmp = myMatch("int(?![a-zA-Z0-9_])")) != null) { // 匹配int
                return new IntTK(tmp, line);
            } else if ((tmp = myMatch("char(?![a-zA-Z0-9_])")) != null) { // 匹配char
                return new CharTK(tmp, line);
            } else if ((tmp = myMatch("void(?![a-zA-Z0-9_])")) != null) { // 匹配void
                return new VoidTK(tmp, line);
            } else if ((tmp = myMatch("break(?![a-zA-Z0-9_])")) != null) { // 匹配break
                return new BreakTK(tmp, line);
            } else if ((tmp = myMatch("continue(?![a-zA-Z0-9_])")) != null) { // 匹配continue
                return new ContinueTK(tmp, line);
            } else if ((tmp = myMatch("if(?![a-zA-Z0-9_])")) != null) { // 匹配if
                return new IfTK(tmp, line);
            } else if ((tmp = myMatch("else(?![a-zA-Z0-9_])")) != null) { // 匹配else
                return new ElseTK(tmp, line);
            } else if ((tmp = myMatch("for(?![a-zA-Z0-9_])")) != null) { // 匹配for
                return new ForTK(tmp, line);
            } else if ((tmp = myMatch("return(?![a-zA-Z0-9_])")) != null) { // 匹配return
                return new ReturnTK(tmp, line);
            } else if ((tmp = myMatch("getint(?![a-zA-Z0-9_])")) != null) { // 匹配getint
                return new GetIntTK(tmp, line);
            } else if ((tmp = myMatch("getchar(?![a-zA-Z0-9_])")) != null) { // 匹配getchar
                return new GetCharTK(tmp, line);
            } else if ((tmp = myMatch("printf(?![a-zA-Z0-9_])")) != null) { // 匹配printf
                return new PrintfTK(tmp, line);
            }
        }

        // 匹配ident
        if ((tmp = myMatch("[a-zA-Z_][a-zA-Z0-9_]*")) != null) {
            return new Ident(tmp, line);
        }

        // 匹配字符串
        // todo （这里，字符串里面会不会再有双引号啥的）
        if (myMatch("\"") != null) {
            int end = StringCon.getString(sourceCode, pos);
            return new StringCon(sourceCode.substring(pos, end), line);
        }

        // 匹配字符
        if (myMatch("'") != null) {
            int end = CharCon.getChar(sourceCode, pos);
            return new CharCon(sourceCode.substring(pos, end), line);
        }

        // 匹配数字
        if ((tmp = myMatch("[0-9]+")) != null) {
            return new IntCon(tmp, line);
        }

        // 匹配space
        if ((tmp = myMatch("\\s+")) != null) {
            return new Blank(tmp, line);
        }

        // 匹配delimiters NOT, AND, OR, PLUS, MINU, MULT, DIV, MOD,
        //    ASSIGN, LSS, LEQ, GRE, GEQ, EQL, NEQ,
        //    SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
        boolean isDelimiter = true;
        if (isDelimiter) {
            if ((tmp = myMatch("<=")) != null) { // 匹配LEQ
                return new Leq(tmp, line);
            } else if ((tmp = myMatch(">=")) != null) { // 匹配GEQ
                return new Geq(tmp, line);
            } else if ((tmp = myMatch("==")) != null) { // 匹配EQL
                return new Eql(tmp, line);
            } else if ((tmp = myMatch("!=")) != null) { // 匹配NEQ
                return new Neq(tmp, line);
            } else if ((tmp = myMatch(";")) != null) { // 匹配SEMICN
                return new Semicn(tmp, line);
            } else if ((tmp = myMatch(",")) != null) { // 匹配COMMA
                return new Comma(tmp, line);
            } else if ((tmp = myMatch("\\(")) != null) { // 匹配LPARENT
                return new LParen(tmp, line);
            } else if ((tmp = myMatch("\\)")) != null) { // 匹配RPARENT
                return new RParen(tmp, line);
            } else if ((tmp = myMatch("\\[")) != null) { // 匹配LBRACK
                return new LBrack(tmp, line);
            } else if ((tmp = myMatch("\\]")) != null) { // 匹配RBRACK
                return new RBrack(tmp, line);
            } else if ((tmp = myMatch("\\{")) != null) { // 匹配LBRACE
                return new LBrace(tmp, line);
            } else if ((tmp = myMatch("\\}")) != null) { // 匹配RBRACE
                return new RBrace(tmp, line);
            } else if ((tmp = myMatch("!")) != null) { // 匹配NOT
                return new Not(tmp, line);
            } else if ((tmp = myMatch("&&")) != null) { // 匹配AND
                return new And(tmp, line);
            } else if ((tmp = myMatch("\\|\\|")) != null) { // 匹配OR
                return new Or(tmp, line);
            } else if ((tmp = myMatch("\\+")) != null) { // 匹配PLUS
                return new Plus(tmp, line);
            } else if ((tmp = myMatch("-")) != null) { // 匹配MINU
                return new Minu(tmp, line);
            } else if ((tmp = myMatch("\\*")) != null) { // 匹配MULT
                return new Mult(tmp, line);
            } else if ((tmp = myMatch("/")) != null) { // 匹配DIV
                return new Div(tmp, line);
            } else if ((tmp = myMatch("%")) != null) { // 匹配MOD
                return new Mod(tmp, line);
            } else if ((tmp = myMatch("=")) != null) { // 匹配ASSIGN
                return new Assign(tmp, line);
            } else if ((tmp = myMatch("<")) != null) { // 匹配LSS
                return new Lss(tmp, line);
            } else if ((tmp = myMatch(">")) != null) { // 匹配GRE
                return new Gre(tmp, line);
            } else if (myMatch("&") != null || myMatch("\\|") != null)  {
                errors.add(new Error(line, "a"));
            }
        }

        return null;
    }

    private String myMatch(String regex) {
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(sourceCode);
        // 从 index 处开始匹配，然后检验是否匹配
        if (matcher.find(pos) && matcher.start() == pos) {
            return matcher.group();
        } else {
            return null;
        }
    }

    public String showLexerResult() {
        StringBuilder stringBuilder = new StringBuilder();
        for (Token token : tokens) {
            stringBuilder.append(token).append("\n");
        }
        return stringBuilder.toString();
    }

}

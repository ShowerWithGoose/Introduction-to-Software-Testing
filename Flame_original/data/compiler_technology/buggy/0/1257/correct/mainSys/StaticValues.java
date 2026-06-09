package mainSys;

import java.util.*;

public class StaticValues {
    public static int line = 1;
    public static int pos = 0;

    public static List<Token> tokens = new ArrayList<>();
    public static List<Error> errors = new ArrayList<>();
    public static boolean errorFlag = false;

    public static String sourceCode ;




    public static final String errorOutPutFile = "error.txt";
    public static final String outputFile = "lexer.txt";
    public static final String IDENFR = "IDENFR";
    public static final String ELSETK = "ELSETK";
    public static final String VOIDTK = "VOIDTK";
    public static final String SEMICN = "SEMICN";
    public static final String INTCON = "INTCON";
    public static final String NOT = "NOT";
    public static final String MULT = "MULT";
    public static final String COMMA = "COMMA";
    public static final String STRCON = "STRCON";
    //StringConst	STRCON	&&	AND	/	DIV	(	LPARENT
    public static final String AND = "AND";
    public static final String DIV = "DIV";
    public static final String LPARENT = "LPARENT";
    //CharConst	CHRCON	||	OR	%	MOD	)	RPARENT
    public static final String CHRCON = "CHRCON";
    public static final String OR = "OR";
    public static final String MOD = "MOD";
    public static final String RPARENT = "RPARENT";
    //main	MAINTK	for	FORTK	<	LSS	[	LBRACK
    public static final String MAINTK = "MAINTK";
    public static final String FORTK = "FORTK";
    public static final String LSS = "LSS";
    public static final String LBRACK = "LBRACK";
    //const	CONSTTK	getint	GETINTTK	<=	LEQ	]	RBRACK
    public static final String CONSTTK = "CONSTTK";
    public static final String GETINTTK = "GETINTTK";
    public static final String LEQ = "LEQ";
    public static final String RBRACK = "RBRACK";

    public static final String INTTK = "INTTK";
    public static final String GETCHARTK = "GETCHARTK";
    public static final String GRE = "GRE";
    public static final String LBRACE = "LBRACE";

    public static final String CHARTK = "CHARTK";
    public static final String PRINTFTK = "PRINTFTK";
    public static final String GEQ = "GEQ";
    public static final String RBRACE = "RBRACE";
    //break	BREAKTK	return	RETURNTK	==	EQL
    //
    //continue	CONTINUETK	+	PLUS	!=	NEQ
    //
    //if	IFTK	-	MINU	=	ASSIGN
    public static final String BREAKTK = "BREAKTK";
    public static final String RETURNTK = "RETURNTK";
    public static final String EQL = "EQL";
    public static final String CONTINUETK = "CONTINUETK";
    public static final String PLUS = "PLUS";
    public static final String NEQ = "NEQ";

    public static final String IFTK = "IFTK";
    public static final String MINU = "MINU";
    public static final String ASSIGN = "ASSIGN";
    //TokenType是以上注释中大写的词，TokenType是词法分析器的关键字
    //存储在以上的静态变量中
    public static final Map<String, String> keywordMap = new HashMap<>();
    static{
        keywordMap.put("main",MAINTK);
        keywordMap.put("const",CONSTTK);
        keywordMap.put("int",INTTK);
        keywordMap.put("char",CHARTK);
        keywordMap.put("break",BREAKTK);
        keywordMap.put("continue",CONTINUETK);
        keywordMap.put("if",IFTK);
        keywordMap.put("else",ELSETK);
        keywordMap.put("void",VOIDTK);
        keywordMap.put("for",FORTK);
        keywordMap.put("return",RETURNTK);
        keywordMap.put("getint",GETINTTK);
        keywordMap.put("getchar",GETCHARTK);
        keywordMap.put("printf",PRINTFTK);
    }

}

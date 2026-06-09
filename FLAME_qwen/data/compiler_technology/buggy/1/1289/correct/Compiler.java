import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;

public class Compiler {
    static int linenum=1;
    static int character;
	static int Grammar_Pointer=0;
	static String filepath="parser.txt";
	static String filepath_error="error.txt";
    static StringBuilder token =new StringBuilder();
	static StringBuilder StringBuilder_Grammar = new StringBuilder();
	static ArrayList<String> Outputlist_Grammar= new ArrayList<>();
    static ArrayList<String> Wordslist= new ArrayList<>();
    static ArrayList<String> classification= new ArrayList<>();
    static ArrayList<Integer> Linelist= new ArrayList<>();
	static ArrayList<ERROR> Errorlist= new ArrayList<>();
    static int File_End =1;
	 public static void main(String[] args) {  
	        String filePath = "testfile.txt";  
	        FileReader fileReader = null;  
	        try {  
	            fileReader = new FileReader(filePath);  
	            File_End=(character = fileReader.read());
	            while (File_End != -1) {  
	                cifa_solve(fileReader);
	            }  
	            classify();
				Grammar_CompUnit();
	            Grammar_Print();
	        } catch (IOException e) {  
	            e.printStackTrace();  
	        } finally {  
	            if (fileReader != null) {  
	                try {  
	                    fileReader.close();  
	                } catch (IOException e) {  
	                    e.printStackTrace();  
	                }  
	            }  
	        }  
	    }  


public static void cifa_solve(FileReader fileReader) {
	String temp_add;
	 if((char)character=='\n') {
         linenum++;
         try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}

         }
	 else if((char)character ==' ') {
		 try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}

	 }
	 else if((char)character =='}'||(char)character =='{'||(char)character ==']'||(char)character =='['||(char)character ==')'||(char)character =='('||(char)character ==','||(char)character ==';'||(char)character =='*'||(char)character =='%'||(char)character =='-'||(char)character =='+')
	{
		temp_add = Character.toString((char)character);
		Wordslist.add(temp_add);
		Linelist.add(linenum);
		 try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	 else if((char)character =='|'||(char)character =='&') {
		char old_char;
		token.setLength(0);
		token.append((char)character);
		old_char =(char)character;
		try {
			 File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}
		if(old_char==(char)character)
		{
			token.append((char)character);
			Wordslist.add(token.toString());
			Linelist.add(linenum);
			token.setLength(0);
			try {
				 File_End=(character = fileReader.read());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		else
		{
			ERROR error = new ERROR("a",linenum);
			Errorlist.add(error);
			token.append(old_char);
			Wordslist.add(token.toString());
			Linelist.add(linenum);
			token.setLength(0);

		}
	}
	 else if((char)character =='<'||(char)character =='>'||(char)character =='='||(char)character =='!') {
		char old_char;
		token.setLength(0);
		old_char =(char)character;
		try {
			 File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}
		if(((old_char=='<')&&((char)character=='='))||((old_char=='>')&&((char)character=='='))||((old_char=='=')&&((char)character=='='))||((old_char=='!')&&((char)character=='='))) {
			token.setLength(0);
			token.append(old_char);
			token.append((char)character);
			Wordslist.add(token.toString());
			Linelist.add(linenum);
			token.setLength(0);
			try {
				 File_End=(character = fileReader.read());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		else {
			Wordslist.add(Character.toString(old_char));
			Linelist.add(linenum);
			token.setLength(0);
		}
		
	}
	 else if((char)character>='0'&&(char)character<='9') {
		token.setLength(0);
		try {
			while((char)character>='0'&&(char)character<='9')
			{
				token.append((char)character);
				File_End=(character = fileReader.read());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		Wordslist.add(token.toString());
		Linelist.add(linenum);
		token.setLength(0);
	}
	 else if((char)character=='"') {//""引用的
		token.setLength(0);
		token.append((char)character);
		try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			while((char)character!='"')
			{
				if((char)character=='\\')
				{
					token.append((char)character);
					File_End=(character = fileReader.read());
				}
				token.append((char)character);
				File_End=(character = fileReader.read());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		token.append((char)character);
		Wordslist.add(token.toString());
		Linelist.add(linenum);
		token.setLength(0);
		try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
	 else if((char)character=='\'') {//''引用的
		token.setLength(0);
		token.append((char)character);
		try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			while((char)character!='\'')
			{
				token.append((char)character);
				File_End=(character = fileReader.read());
			}
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		token.append((char)character);
		try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}
		if((char)character=='\'')
		{
			token.append((char)character);
			try {
				File_End=(character = fileReader.read());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		Wordslist.add(token.toString());
		Linelist.add(linenum);
		token.setLength(0);

	}
	 else if(((char)character>='a'&&(char)character<='z')||((char)character>='A'&&(char)character<='Z')||(char)character=='_')
	{
		token.setLength(0);
		try {
			while(((char)character>='a'&&(char)character<='z')||((char)character>='A'&&(char)character<='Z')||((char)character>='0'&&(char)character<='9')||(char)character=='_')
			{
				token.append((char)character);
				File_End=(character = fileReader.read());
			}
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		Wordslist.add(token.toString());
		Linelist.add(linenum);
		token.setLength(0);
	}
	 else if((char)character=='/') {
		 token.setLength(0);
		 token.append((char)character);
		 try {
				File_End=(character = fileReader.read());
			} catch (IOException e) {
				e.printStackTrace();
			}
		 if((char)character=='/')
		 {
			 token.setLength(0);
			 try {
					while((char)character!='\n'&&File_End!=-1)
					{
						File_End=(character = fileReader.read());
					}
				} catch (IOException e) {
					// TODO 自动生成的 catch 块
					e.printStackTrace();
				}

		 }
		 
		 else if((char)character=='*')
		 {
			 token.setLength(0);
			 try {
					while(true)
					{
						File_End=(character = fileReader.read());
						 if((char)character=='\n')  linenum++;
						while((char)character=='*')
						{
							try {
								File_End=(character = fileReader.read());
							} catch (IOException e) {
								e.printStackTrace();
							}
							if((char)character=='/')
							{
								 try {
										File_End=(character = fileReader.read());
									} catch (IOException e) {
										e.printStackTrace();
									}
								 return;
							}
						}
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
		 }
		 else {
			 Wordslist.add(token.toString());
				Linelist.add(linenum);
			token.setLength(0);
		 }
		 
	}
	
	else {
		 try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
	
}
public static void Grammar_Print(){
	int i=0;
	if(!Errorlist.isEmpty()) {
		Errorlist.sort(Comparator.comparingInt(ERROR -> ERROR.Error_Line));
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(filepath_error))) {
			for (i = 0; i < Errorlist.size(); i++) {
				writer.write(Errorlist.get(i).Error_Line + " " + Errorlist.get(i).Error_Name);
				writer.newLine();
			}
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	else {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(filepath))) {
			for(;i<Outputlist_Grammar.size();i++)
			{
				writer.write(Outputlist_Grammar.get(i));
				writer.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
public static void classify() {
	int i=0;
	for(;i<Wordslist.size();i++)
	{	
		if(Wordslist.get(i).equals("}")) classification.add("RBRACE");
		else if(Wordslist.get(i).equals("{")) classification.add("LBRACE");
		else if(Wordslist.get(i).equals("]")) classification.add("RBRACK");
		else if(Wordslist.get(i).equals("[")) classification.add("LBRACK");
		else if(Wordslist.get(i).equals(")")) classification.add("RPARENT");
		else if(Wordslist.get(i).equals("(")) classification.add("LPARENT");
		else if(Wordslist.get(i).equals(",")) classification.add("COMMA");
		else if(Wordslist.get(i).equals(";")) classification.add("SEMICN");
		else if(Wordslist.get(i).equals("=")) classification.add("ASSIGN");
		else if(Wordslist.get(i).equals("!=")) classification.add("NEQ");
		else if(Wordslist.get(i).equals("==")) classification.add("EQL");
		else if(Wordslist.get(i).equals(">=")) classification.add("GEQ");
		else if(Wordslist.get(i).equals(">")) classification.add("GRE");
		else if(Wordslist.get(i).equals("<=")) classification.add("LEQ");
		else if(Wordslist.get(i).equals("<")) classification.add("LSS");
		else if(Wordslist.get(i).equals("%")) classification.add("MOD");
		else if(Wordslist.get(i).equals("/")) classification.add("DIV");
		else if(Wordslist.get(i).equals("*")) classification.add("MULT");
		else if(Wordslist.get(i).equals("void")) classification.add("VOIDTK");
		else if(Wordslist.get(i).equals("-")) classification.add("MINU");
		else if(Wordslist.get(i).equals("+")) classification.add("PLUS");
		else if(Wordslist.get(i).equals("return")) classification.add("RETURNTK");
		else if(Wordslist.get(i).equals("printf")) classification.add("PRINTFTK");
		else if(Wordslist.get(i).equals("getchar")) classification.add("GETCHARTK");
		else if(Wordslist.get(i).equals("getint")) classification.add("GETINTTK");
		else if(Wordslist.get(i).equals("else")) classification.add("ELSETK");
		else if(Wordslist.get(i).equals("for")) classification.add("FORTK");
		else if(Wordslist.get(i).equals("||")) classification.add("OR");
		else if(Wordslist.get(i).equals("&&")) classification.add("AND");
		else if(Wordslist.get(i).equals("!")) classification.add("NOT");
		else if(Wordslist.get(i).equals("if")) classification.add("IFTK");
		else if(Wordslist.get(i).equals("continue")) classification.add("CONTINUETK");
		else if(Wordslist.get(i).equals("break")) classification.add("BREAKTK");
		else if(Wordslist.get(i).equals("char")) classification.add("CHARTK");
		else if(Wordslist.get(i).equals("int")) classification.add("INTTK");
		else if(Wordslist.get(i).equals("const")) classification.add("CONSTTK");
		else if(Wordslist.get(i).equals("main")) classification.add("MAINTK");
		else if(Wordslist.get(i).charAt(0)=='\''&&Wordslist.get(i).charAt(Wordslist.get(i).length()-1)=='\'') classification.add("CHRCON");
		else if(Wordslist.get(i).charAt(0)=='"'&&Wordslist.get(i).charAt(Wordslist.get(i).length()-1)=='"') classification.add("STRCON");
		else if(Wordslist.get(i).matches("^\\d+$")) classification.add("INTCON");
		else  classification.add("IDENFR");
	}
}

	public static void Grammar_CompUnit(){
		 if(Wordslist.get(Grammar_Pointer+1).equals("main")) {
			 Grammar_MainFuncDef();
			 Outputlist_Grammar.add("<CompUnit>");
			 return;
		 }
		while(!Wordslist.get(Grammar_Pointer+2).equals("("))
		{
			Grammar_Decl();
		}
		while(!Wordslist.get(Grammar_Pointer+1).equals("main"))
		{
			Grammar_FuncDef();
		}
		Grammar_MainFuncDef();
		Outputlist_Grammar.add("<CompUnit>");
	}
	public static void Grammar_Decl(){
		 if(Wordslist.get(Grammar_Pointer).equals("const"))
		 {
			 Grammar_ConstDecl();
		 }
		else{
			Grammar_VarDecl();
		 }
		//Outputlist_Grammar.add("<Decl>");
	}
	public static void Grammar_ConstDecl(){
		 Grammar_addtooutput();//const
		 Grammar_BType();
		 Grammar_ConstDef();
		 while(Wordslist.get(Grammar_Pointer).equals(","))
		 {
			 Grammar_addtooutput();//,
			 Grammar_ConstDef();
		 }
		 if(Wordslist.get(Grammar_Pointer).equals(";")){
			 Grammar_addtooutput();
		 }
		 else {
			 Grammar_ErrorSolve_i();
		 }
		Outputlist_Grammar.add("<ConstDecl>");
	}
	public static void Grammar_BType(){
		Grammar_addtooutput();
	}
	public static void Grammar_ConstDef(){
				Grammar_addtooutput();
				if(Wordslist.get(Grammar_Pointer).equals("["))
				{
					Grammar_addtooutput();//[
					Grammar_ConstExp();
					if(Wordslist.get(Grammar_Pointer).equals("]"))
						Grammar_addtooutput();
					else
					{
						Grammar_ErrorSolve_k();
					}
				}
				Grammar_addtooutput();// =
				Grammar_ConstInitVal();
		Outputlist_Grammar.add("<ConstDef>");
	}
	public static void Grammar_ConstInitVal(){
		if(classification.get(Grammar_Pointer).equals("STRCON")){
			Grammar_addtooutput();
		}
		else if(Wordslist.get(Grammar_Pointer).equals("{")){
			Grammar_addtooutput();
			if(Wordslist.get(Grammar_Pointer).equals("}"))
			{
				Grammar_addtooutput();//}
			}
			else
			{
				Grammar_ConstExp();
				while(Wordslist.get(Grammar_Pointer).equals(","))
				{
					Grammar_addtooutput();
					Grammar_ConstExp();
				}
				Grammar_addtooutput();//}
			}
		}
		else{
			Grammar_ConstExp();
		}
		Outputlist_Grammar.add("<ConstInitVal>");
	}
	public static void Grammar_VarDecl(){
		Grammar_BType();
		Grammar_VarDef();
		while(Wordslist.get(Grammar_Pointer).equals(","))
		{
			Grammar_addtooutput();
			Grammar_VarDef();
		}
		if(Wordslist.get(Grammar_Pointer).equals(";")){
			Grammar_addtooutput();
		}
		else {
			Grammar_ErrorSolve_i();
		}
		Outputlist_Grammar.add("<VarDecl>");
	}
	public static void Grammar_VarDef(){
		Grammar_addtooutput();//Ident
		if(Wordslist.get(Grammar_Pointer).equals("["))
		{
			Grammar_addtooutput();
			Grammar_ConstExp();
			if(Wordslist.get(Grammar_Pointer).equals("]"))
				Grammar_addtooutput();
			else {
				Grammar_ErrorSolve_k();
			}
		}
		if(Wordslist.get(Grammar_Pointer).equals("="))
		{
			Grammar_addtooutput();
			Grammar_InitVal();
		}
		Outputlist_Grammar.add("<VarDef>");
	}
	public static void Grammar_InitVal(){
		if(classification.get(Grammar_Pointer).equals("STRCON"))
		{
			Grammar_addtooutput();
		}
		else if(Wordslist.get(Grammar_Pointer).equals("{")){
			Grammar_addtooutput();// {
			if(Wordslist.get(Grammar_Pointer).equals("}"))
			{
				Grammar_addtooutput();//}
			}
			else
			{
				Grammar_Exp();
				while(Wordslist.get(Grammar_Pointer).equals(","))
				{
					Grammar_addtooutput();
					Grammar_Exp();
				}
				Grammar_addtooutput();//}
			}
		}
		else{
			Grammar_Exp();
		}
		Outputlist_Grammar.add("<InitVal>");
	}
	public static void Grammar_FuncDef(){
		Grammar_FuncType();
		Grammar_addtooutput();//Ident
		Grammar_addtooutput();//'(
		if(Wordslist.get(Grammar_Pointer).equals("int")||Wordslist.get(Grammar_Pointer).equals("char")){
			Grammar_FuncFParams();
		}
		if(Wordslist.get(Grammar_Pointer).equals(")")){
			Grammar_addtooutput();
		}
		else{
			Grammar_ErrorSolve_j();
		}
		Grammar_Block();
		Outputlist_Grammar.add("<FuncDef>");
	}
	public static void Grammar_MainFuncDef(){
		Grammar_addtooutput();//int
		Grammar_addtooutput();//main
		Grammar_addtooutput();// (
		if(Wordslist.get(Grammar_Pointer).equals(")"))
			Grammar_addtooutput();//)
		else {
			Grammar_ErrorSolve_j();
		}
		Grammar_Block();
		Outputlist_Grammar.add("<MainFuncDef>");
	}
	public static void Grammar_FuncType(){
		 Grammar_addtooutput();
		Outputlist_Grammar.add("<FuncType>");
	}
	public static void Grammar_FuncFParams(){
		 Grammar_FuncFParam();
		 while(Wordslist.get(Grammar_Pointer).equals(",")){
			 Grammar_addtooutput();//,
			 Grammar_FuncFParam();
		 }
		Outputlist_Grammar.add("<FuncFParams>");
	}
	public static void Grammar_FuncFParam(){
		Grammar_BType();
		Grammar_addtooutput();
		if(Wordslist.get(Grammar_Pointer).equals("["))
		{
			Grammar_addtooutput();
			if(Wordslist.get(Grammar_Pointer).equals("]"))
			{
				Grammar_addtooutput();
			}
			else{
				Grammar_ErrorSolve_k();
			}
		}
		Outputlist_Grammar.add("<FuncFParam>");
	}
	public static void Grammar_Block(){
		 Grammar_addtooutput();//{
		while(!Wordslist.get(Grammar_Pointer).equals("}"))
		{
			Grammar_BlockItem();
		}
		Grammar_addtooutput();//}
		Outputlist_Grammar.add("<Block>");
	}
	public static void Grammar_BlockItem(){
		if(Wordslist.get(Grammar_Pointer).equals("const")||Wordslist.get(Grammar_Pointer).equals("char")||Wordslist.get(Grammar_Pointer).equals("int"))
		{
			Grammar_Decl();
		}
		else {
			Grammar_Stmt();
		}
	 }
	public static void Grammar_Stmt(){
		if(Wordslist.get(Grammar_Pointer).equals("if"))
		{
			Grammar_addtooutput();//if
			Grammar_addtooutput();//'('
			Grammar_Cond();
			if(Wordslist.get(Grammar_Pointer).equals(")"))
				Grammar_addtooutput();//')'
			else {
				Grammar_ErrorSolve_j();
			}
			Grammar_Stmt();
			if(Wordslist.get(Grammar_Pointer).equals("else"))
			{
				Grammar_addtooutput();//else
				Grammar_Stmt();
			}
		}
		else if(Wordslist.get(Grammar_Pointer).equals("for"))
		{
			Grammar_addtooutput();//for
			Grammar_addtooutput();//(
			if(!Wordslist.get(Grammar_Pointer).equals(";"))
				Grammar_ForStmt();
			Grammar_addtooutput();// ;
			if(!Wordslist.get(Grammar_Pointer).equals(";"))
				Grammar_Cond();
			Grammar_addtooutput();// ;
			if(!Wordslist.get(Grammar_Pointer).equals(")"))
				Grammar_ForStmt();
			Grammar_addtooutput();// )
			Grammar_Stmt();
		}
		else if(Wordslist.get(Grammar_Pointer).equals("break"))
		{
			Grammar_addtooutput();
			if(Wordslist.get(Grammar_Pointer).equals(";"))
				Grammar_addtooutput();
			else{
				Grammar_ErrorSolve_i();
			}
		}
		else if(Wordslist.get(Grammar_Pointer).equals("continue"))
		{
			Grammar_addtooutput();
			if(Wordslist.get(Grammar_Pointer).equals(";"))
				Grammar_addtooutput();
			else{
				Grammar_ErrorSolve_i();
			}
		}
		else if(Wordslist.get(Grammar_Pointer).equals("return"))
		{
			Grammar_addtooutput();//return
			if(Wordslist.get(Grammar_Pointer).equals(";"))
				Grammar_addtooutput();
			else if(Linelist.get(Grammar_Pointer-1)<Linelist.get(Grammar_Pointer))
			{
					Grammar_ErrorSolve_i();
			}
			else
			{
				Grammar_Exp();
				if(Wordslist.get(Grammar_Pointer).equals(";"))
					Grammar_addtooutput();
				else
				{
					Grammar_ErrorSolve_i();
				}
			}
		//////////////////////////////////////////////////有bug的.现在似乎没了
		}
		else if(Wordslist.get(Grammar_Pointer).equals("printf"))
		{
			Grammar_addtooutput();//printf
			Grammar_addtooutput();//(
			Grammar_addtooutput();//StringConst
			while(Wordslist.get(Grammar_Pointer).equals(","))
			{
				Grammar_addtooutput();//,
				Grammar_Exp();
			}
			if(Wordslist.get(Grammar_Pointer).equals(")"))
				Grammar_addtooutput();//)
			else{
				Grammar_ErrorSolve_j();
			}
			if(Wordslist.get(Grammar_Pointer).equals(";"))
				Grammar_addtooutput();
			else{
				Grammar_ErrorSolve_i();
			}
		}
		else if(Wordslist.get(Grammar_Pointer).equals("{"))
		{
			Grammar_Block();
		}
		else if(Grammar_Find_equal())
		{
			Grammar_LVal();
			Grammar_addtooutput();// =
			if(Wordslist.get(Grammar_Pointer).equals("getint"))
			{
				Grammar_addtooutput();//getint
				Grammar_addtooutput();//(
				if(Wordslist.get(Grammar_Pointer).equals(")"))
				{
					Grammar_addtooutput();//)
				}
				else
				{
					Grammar_ErrorSolve_j();
				}
				if(Wordslist.get(Grammar_Pointer).equals(";"))
				{
					Grammar_addtooutput();//)
				}
				else
				{
					Grammar_ErrorSolve_i();
				}
			}
			else if(Wordslist.get(Grammar_Pointer).equals("getchar"))
			{
				Grammar_addtooutput();//getchar
				Grammar_addtooutput();//(
				if(Wordslist.get(Grammar_Pointer).equals(")"))
				{
					Grammar_addtooutput();//)
				}
				else
				{
					Grammar_ErrorSolve_j();
				}
				if(Wordslist.get(Grammar_Pointer).equals(";"))
				{
					Grammar_addtooutput();//)
				}
				else
				{
					Grammar_ErrorSolve_i();
				}
			}
			else
			{
				Grammar_Exp();
				if(Wordslist.get(Grammar_Pointer).equals(";"))
				{
					Grammar_addtooutput();//)
				}
				else
				{
					Grammar_ErrorSolve_i();
				}

			}
		}
		else{
			if(Wordslist.get(Grammar_Pointer).equals(";"))
			{
				Grammar_addtooutput();
			}
			else {
				Grammar_Exp();
				if (Wordslist.get(Grammar_Pointer).equals(";")) {
					Grammar_addtooutput();
				} else {
					Grammar_ErrorSolve_i();
				}
			}
		}
		Outputlist_Grammar.add("<Stmt>");
	}
	public static void Grammar_ForStmt(){
		 Grammar_LVal();
		 Grammar_addtooutput();//=
		Grammar_Exp();
		Outputlist_Grammar.add("<ForStmt>");
	}
	public static void Grammar_Exp(){
		 Grammar_AddExp();
		Outputlist_Grammar.add("<Exp>");
	}
	public static void Grammar_Cond(){
		 Grammar_LOrExp();
		Outputlist_Grammar.add("<Cond>");
	}
	public static void Grammar_LVal(){
		 Grammar_addtooutput();
		 if(Wordslist.get(Grammar_Pointer).equals("["))
		 {
			 Grammar_addtooutput();//[
			 Grammar_Exp();
			 if (Wordslist.get(Grammar_Pointer).equals("]"))
				 Grammar_addtooutput();
			 else {
				 Grammar_ErrorSolve_k();
			 }
		 }
		Outputlist_Grammar.add("<LVal>");
	}
	public static void Grammar_PrimaryExp (){
		if(Wordslist.get(Grammar_Pointer).equals("(")){
			Grammar_addtooutput();
			Grammar_Exp();
			if(Wordslist.get(Grammar_Pointer).equals(")"))
			{
				Grammar_addtooutput();
			}
			else {
				Grammar_ErrorSolve_j();
			}
		}
		else if(classification.get(Grammar_Pointer).equals("INTCON")){
			Grammar_Number();
		}
		else if(classification.get(Grammar_Pointer).equals("CHRCON")){
			Grammar_Character();
		}
		else{
			Grammar_LVal();
		}
		Outputlist_Grammar.add("<PrimaryExp>");
	}
	public static void Grammar_Number(){
		 Grammar_addtooutput();//int
		Outputlist_Grammar.add("<Number>");
	}
	public static void  Grammar_Character(){
		Grammar_addtooutput();//char
		Outputlist_Grammar.add("<Character>");
	}
	public static void Grammar_UnaryExp(){
		if(Wordslist.get(Grammar_Pointer).equals("+")||Wordslist.get(Grammar_Pointer).equals("-")||Wordslist.get(Grammar_Pointer).equals("!"))
		{
			Grammar_UnaryOp();
			Grammar_UnaryExp();
		}
		else if(classification.get(Grammar_Pointer).equals("IDENFR")&&Wordslist.get(Grammar_Pointer+1).equals("("))
		{
			Grammar_addtooutput();//名字
			Grammar_addtooutput();//“("
			if(Wordslist.get(Grammar_Pointer).equals(")"))
			{
				Grammar_addtooutput();
			}
			else if(Wordslist.get(Grammar_Pointer).equals(";"))
			{
				Grammar_ErrorSolve_j();
			}
			else{
				Grammar_FuncRParams();
				if(Wordslist.get(Grammar_Pointer).equals(")"))
				{
					Grammar_addtooutput();
				}
				else
				{
					Grammar_ErrorSolve_j();
				}
			}
		}
		else{
			Grammar_PrimaryExp();
		}
		Outputlist_Grammar.add("<UnaryExp>");
	}
	public static void Grammar_UnaryOp(){
		 Grammar_addtooutput();// + - /
		Outputlist_Grammar.add("<UnaryOp>");
	}
	public static void Grammar_FuncRParams(){
		 Grammar_Exp();
		while(Wordslist.get(Grammar_Pointer).equals(",")){
			Grammar_addtooutput();
			Grammar_Exp();
		}
		Outputlist_Grammar.add("<FuncRParams>");
	}
	public static void Grammar_MulExp(){
		Grammar_UnaryExp();
		while(Wordslist.get(Grammar_Pointer).equals("*")||Wordslist.get(Grammar_Pointer).equals("/")||Wordslist.get(Grammar_Pointer).equals("%"))
		{
			Outputlist_Grammar.add("<MulExp>");
			Grammar_addtooutput();
			Grammar_UnaryExp();
		}
		Outputlist_Grammar.add("<MulExp>");
	}
	public static void Grammar_AddExp(){
		Grammar_MulExp();
		while(Wordslist.get(Grammar_Pointer).equals("+")||Wordslist.get(Grammar_Pointer).equals("-"))
		{
			Outputlist_Grammar.add("<AddExp>");
			Grammar_addtooutput();
		 	Grammar_MulExp();
		}
		Outputlist_Grammar.add("<AddExp>");
	}
	public static void Grammar_RelExp(){
		 Grammar_AddExp();
		while(Wordslist.get(Grammar_Pointer).equals(">=")||Wordslist.get(Grammar_Pointer).equals("<=")||Wordslist.get(Grammar_Pointer).equals(">")||Wordslist.get(Grammar_Pointer).equals("<"))
		{
			Outputlist_Grammar.add("<RelExp>");
			Grammar_addtooutput();// <|>|<=|>=
			Grammar_AddExp();
		}
		Outputlist_Grammar.add("<RelExp>");
	}
	public static void  Grammar_EqExp(){
		 Grammar_RelExp();
		while(Wordslist.get(Grammar_Pointer).equals("==")||Wordslist.get(Grammar_Pointer).equals("!="))
		{
			Outputlist_Grammar.add("<EqExp>");
			Grammar_addtooutput();//  ==/!=
			Grammar_RelExp();
		}
		Outputlist_Grammar.add("<EqExp>");
	}
	public static void  Grammar_LAndExp(){
		 Grammar_EqExp();
		while(Wordslist.get(Grammar_Pointer).equals("&&"))
		{
			Outputlist_Grammar.add("<LAndExp>");
			Grammar_addtooutput();//  &&
			Grammar_EqExp();
		}
		Outputlist_Grammar.add("<LAndExp>");
	}
	public static void   Grammar_LOrExp(){
		 Grammar_LAndExp();
		 while(Wordslist.get(Grammar_Pointer).equals("||"))
		 {
			 Outputlist_Grammar.add("<LOrExp>");
			 Grammar_addtooutput();//  ||
			 Grammar_LAndExp();
		 }
		Outputlist_Grammar.add("<LOrExp>");
	}
	public static void  Grammar_ConstExp(){
		Grammar_AddExp();
		Outputlist_Grammar.add("<ConstExp>");
	}
	public static void Grammar_ErrorSolve_i(){
		 ERROR error=new ERROR("i",Linelist.get(Grammar_Pointer-1));
		 Errorlist.add(error);
		 Wordslist.add(Grammar_Pointer,";");
		 classification.add(Grammar_Pointer,"SEMICN");
		 Linelist.add(Grammar_Pointer,Linelist.get(Grammar_Pointer-1));
		 Grammar_Pointer++;
	}
	public static void Grammar_ErrorSolve_j(){
		ERROR error=new ERROR("j",Linelist.get(Grammar_Pointer-1));
		Errorlist.add(error);
		Wordslist.add(Grammar_Pointer,")");
		classification.add(Grammar_Pointer,"RPARENT");
		Linelist.add(Grammar_Pointer,Linelist.get(Grammar_Pointer-1));
		Grammar_Pointer++;
	 }
	public static void Grammar_ErrorSolve_k(){
		ERROR error=new ERROR("k",Linelist.get(Grammar_Pointer-1));
		Errorlist.add(error);
		Wordslist.add(Grammar_Pointer,"]");
		classification.add(Grammar_Pointer,"RBRACK");
		Linelist.add(Grammar_Pointer,Linelist.get(Grammar_Pointer-1));
		Grammar_Pointer++;
	 }

public static void Grammar_addtooutput(){
	StringBuilder_Grammar.setLength(0);
	StringBuilder_Grammar.append(classification.get(Grammar_Pointer));
	StringBuilder_Grammar.append(" ");
	StringBuilder_Grammar.append(Wordslist.get(Grammar_Pointer));
	Outputlist_Grammar.add(StringBuilder_Grammar.toString());
	StringBuilder_Grammar.setLength(0);
	Grammar_Pointer++;
}

public static Boolean Grammar_Find_equal(){
		 int i=0;
		 while(Linelist.get(Grammar_Pointer).equals(Linelist.get(Grammar_Pointer+i)))
		 {
			 if(Wordslist.get(Grammar_Pointer+i).equals("="))
				 return true;
			 i=i+1;
		 }
		 return false;
}
}
class ERROR{
	String Error_Name;
	int Error_Line;
	ERROR(String a,int b){
		this.Error_Name=a;
		this.Error_Line=b;
	}
}


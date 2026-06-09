import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    static int linenum=1;
    static int character; 
    static StringBuilder token =new StringBuilder();
    static ArrayList<String> Wordslist= new ArrayList<>();
    static ArrayList<String> classification= new ArrayList<>();
    static ArrayList<Integer> Linelist= new ArrayList<>();
    static boolean ERROR = false;
    static int ERROR_LINE = 0;
    static int File_End =1;
	 public static void main(String[] args) {  
	        String filePath = "testfile.txt";  
	        FileReader fileReader = null;  
	        try {  
	            fileReader = new FileReader(filePath);  
	            File_End=(character = fileReader.read());
	            while (File_End != -1) {  
	                solve(fileReader);
	            }  
	            classify();
	            Print();
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


public static void solve(FileReader fileReader) {
	String temp_add;
	 if((char)character=='\n') {
         linenum++;
         try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}
         return;
         }
	 else if((char)character ==' ') {
		 try {
			File_End=(character = fileReader.read());
		} catch (IOException e) {
			e.printStackTrace();
		}
		return;
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
		return;
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
			return;
		}
		else
		{
			ERROR = true;
			ERROR_LINE=linenum;
			Wordslist.add(token.toString());
			Linelist.add(linenum);
			token.setLength(0);
			return;
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
			return;
		}
		else {
			Wordslist.add(Character.toString(old_char));
			Linelist.add(linenum);
			token.setLength(0);
			return;
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
		return;
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
				token.append((char)character);
				File_End=(character = fileReader.read());
			}
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
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
		return;
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
		return;
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
		return;
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
			// token.append((char)character);
			 //Wordslist.add(token.toString());
			 token.setLength(0);
			 try {
					while((char)character!='\n')
					{
						File_End=(character = fileReader.read());
					}
				} catch (IOException e) {
					// TODO 自动生成的 catch 块
					e.printStackTrace();
				}
			 return;
		 }
		 
		 else if((char)character=='*')
		 {
			// token.append((char)character);
			// Wordslist.add(token.toString());
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
			 return;
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
public static void Print() {
	int i=0;
	String filepath="lexer.txt";
	String filepath_error="error.txt";
	if(ERROR) {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(filepath_error))) {   
	            writer.write(ERROR_LINE+" a");  
	    		}
	     catch (IOException e) {  
	        e.printStackTrace();  
	    }  
	}
	else {
	try (BufferedWriter writer = new BufferedWriter(new FileWriter(filepath))) {   
    		for(;i<Wordslist.size();i++)
    		{	
    	        writer.write(classification.get(i)+" " +Wordslist.get(i));  
    	        writer.newLine();  
    		}

    } catch (IOException e) {  
        e.printStackTrace();  
    }  
	}
	return;
	
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
	return;
}
}



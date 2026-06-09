import Lexer.Lexer;
import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.CompUnit;
import Parser.CompUnitParser;
import Parser.ErrorP;
import Parser.ErrorPList;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * @Description:
 * @date 2024/9/24
 */
public class Compiler {
    public static void main(String[] args) {
        String sourceFile="testfile.txt";
        String writeFile="parser.txt";
        String errorFile="error.txt";
        Lexer lexer=new Lexer(sourceFile);
        ArrayList<Token> tokens = lexer.tokenize();
        CompUnitParser compUnitParser = new CompUnitParser(tokens);
        CompUnit compUnit=compUnitParser.compUnitParse();
        //List<Token> errors =new ArrayList<>();
        int flagError=0;
        ErrorPList errorPList=ErrorPList.getInstance();
        if(errorPList.getErrors().isEmpty()){
            flagError=0;
        }else {
            flagError=1;
            Collections.sort(errorPList.getErrors(),new Comparator<ErrorP>(){
                @Override
                public int compare(ErrorP e1,ErrorP e2){
                    return Integer.compare(e1.getErrorLine(), e2.getErrorLine());
                }
            });
        }

//        try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorFile))) {
//            for (Token token : tokens) {
//                if (token.getType().equals("ERROR")) {
//                    flagError = 1;
//                    //errors.add(token);
//                    writer.write(token.getLine()+" "+"a");
//                    //writer.newLine();
//                }
//            }
//        }catch (IOException e) {
//            e.printStackTrace();
//        }
        /*for (Token token : tokens) {
            System.out.println(token.getType()+" "+token.getValue());
        }*/
        if(flagError==0){
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(writeFile))) {
                writer.write(compUnit.print_tree());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }else {

            try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorFile))) {
                for (ErrorP errorP:errorPList.getErrors()){
                    writer.write(errorP.getErrorLine()+" "+errorP.getErrorType()+"\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        /*for (SyntaxTreeNode child : node.children) {
            printSyntaxTree(child, level + 1);
        }*/
    }
}
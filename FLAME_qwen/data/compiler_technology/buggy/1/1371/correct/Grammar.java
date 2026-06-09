import java.util.ArrayList;

public class Grammar {
    private int cur = 0;  //记录数组位置

    private ArrayList<Token>tokens;
    private ArrayList<Error>errors;
    private ArrayList<Token>list;

    private int sign ;
    public Grammar(ArrayList<Token> tokens,ArrayList<Token>list,int sign,ArrayList<Error>errors) {
       this.tokens = tokens;
       this.list = list;
       this.sign = sign;
       this.errors = errors;
       this.parserCompUnit();
    }

    public void parserCompUnit() {
        int sign_1 = 0;
        int sign_2 = 0;
        while (returnContent().equals("int")||returnContent().equals("char")
                ||returnContent().equals("const")||returnContent().equals(",")) {
            if(returnContent().equals("const")) {
                parserDecl();
                continue;
            }
            int line = this.now().getLine();
            this.move();
            this.move();
            sign_1 = 1;
            if(returnContent().equals("[")||returnContent().equals("=")||
                    returnContent().equals(";")||returnContent().equals(",")||this.now().getLine()>line) {
                this.up();
                this.up();
                parserDecl();
                sign_1 = 0;
            }
        }
        if (sign_1 == 1) {
            this.up();
            this.up();
        }
        while(returnContent().equals("int")||returnContent().equals("char")||returnContent().equals("void")) {
            if(returnContent().equals("void")) {
                parserFuncDef();
                continue;
            }
            this.move();
            if(returnContent().equals("main")) {
                this.up();
                break;
            }
            this.move();
            sign_2=1;
            if(returnContent().equals("(")) {
                this.up();
                this.up();
                parserFuncDef();
                sign_2 = 0;
            } }
        if(sign_2 == 1) {
            this.up();
            this.up();
        }
        parserMainFuncDef();
        addToList(new Token(Token.Type.NAME,"<CompUnit>",0));
    }

    public void parserDecl(){
      if (this.now().getContent().equals("const")) {
          addToList(new Token(Token.Type.KEYWORD,"const",this.now().getLine()));
          match_BType();
         //跳过BType
         parserConstDef();
         while(returnContent().equals(",")) {
             addToList(new Token(Token.Type.COMMA,",",this.now().getLine()));
             parserConstDef();
         }
         match_semicn();
         addToList(new Token(Token.Type.NAME,"<ConstDecl>",0));
      } //ConstDecl;
      else {
          this.move();
          if(returnContent().equals("main")) {
              this.up();
              return;
          }
          this.up();
          match_BType();
          parserVarDef();
          while(returnContent().equals(",")) {
              addToList(new Token(Token.Type.COMMA,",",this.now().getLine()));
              parserVarDef();
          }
          match_semicn();
          addToList(new Token(Token.Type.NAME,"<VarDecl>",0));
      } //VarDecl
    }
    public void parserVarDef(){
        match_Ident();
        if(returnContent().equals("[")) {
            addToList(new Token(Token.Type.LBRACK,"[",this.now().getLine()));
            parserConstExp();
            match_rbrack();
        }
        if(returnContent().equals("=")) {
            addToList(new Token(Token.Type.ASSIGN,"=",this.now().getLine()));
            parserInitVal();
        }
        addToList(new Token(Token.Type.NAME,"<VarDef>",0));
    }

    public void parserInitVal() {
         if(this.now().getType() == Token.Type.STRCON) {
             addToList(new Token(Token.Type.STRCON,returnContent(),this.now().getLine()));
         }
         else if(returnContent().equals("{")){
             addToList(new Token(Token.Type.LBRACE,"{",this.now().getLine()));
             parserExp();  //多个Exp
             while(returnContent().equals(",")) {
                 addToList(new Token(Token.Type.COMMA,",",this.now().getLine()));
                 parserExp();
             }
             match_rbrace();
         }
         else{
             parserExp();
         }
         addToList(new Token(Token.Type.NAME,"<InitVal>",0));

    }

    public void parserFuncDef() {
        this.move();
        if(returnContent().equals("main")) {
            this.up();
            return;
        }
        this.up();
        match_funcType();
        addToList(new Token(Token.Type.NAME,"<FuncType>",0));
        match_Ident();
        match_lparent();
        parserFuncParams();
        match_rparent();
        parserBlock();
        addToList(new Token(Token.Type.NAME,"<FuncDef>",0));
    }

    public void parserFuncParams() {
      if(returnContent().equals(")")||returnContent().equals("{")) {
          return;
      }
      else {
          parserFuncParam();
          while(returnContent().equals(",")) {
              addToList(new Token(Token.Type.COMMA,",",this.now().getLine()));
              parserFuncParam();
          }
          addToList(new Token(Token.Type.NAME,"<FuncFParams>",0));
      }
    }

    public void parserFuncParam() {
        match_BType();
        match_Ident();
        if(returnContent().equals("[")) {
            addToList(new Token(Token.Type.LBRACK,"[",this.now().getLine()));
            match_rbrack();
        }
        addToList(new Token(Token.Type.NAME,"<FuncFParam>",0));
    }

    public void parserMainFuncDef() {
       match_BType();
       addToList(new Token(Token.Type.KEYWORD,"main",this.now().getLine()));
       match_lparent();
       match_rparent();
       parserBlock();
       addToList(new Token(Token.Type.NAME,"<MainFuncDef>",0));
    }

    public void parserConstDef() {
        match_Ident();
        if(this.now().getContent().equals("[")) {
            addToList(new Token(Token.Type.LBRACK,"[",this.now().getLine()));
            parserConstExp();
            match_rbrack();
        }
        match_assign();
        parserConstInitVal();
        addToList(new Token(Token.Type.NAME,"<ConstDef>",0));
    }


    public void parserBlock() {
      if (this.now().getType()==Token.Type.LBRACE) {
          addToList(new Token(Token.Type.LBRACE,"{",this.now().getLine()));
          parserBlockItem();
          while (!returnContent().equals("}")) {
           parserBlockItem();
          }
          match_rbrace();
      }
      addToList(new Token(Token.Type.NAME,"<Block>",0));
    }

    public void parserBlockItem() {
      if (returnContent().equals("const")||returnContent().equals("int")
      ||returnContent().equals("char")) {
          parserDecl();
      } else if(returnContent().equals("}")) {
          return;
      }
      else {
          parserStmt();
      }
    }

    public void parserStmt() {
        int sign_assign = 0;
         if(returnContent().equals("if")) {
             addToList(new Token(Token.Type.KEYWORD,"if",this.now().getLine()));
             match_lparent();
             parserCond();
             match_rparent();
             parserStmt();
             if(returnContent().equals("else")) {
                 addToList(new Token(Token.Type.KEYWORD,"else",this.now().getLine()));
                 parserStmt();
             }
         } else if(returnContent().equals("for")) {
             addToList(new Token(Token.Type.KEYWORD,"for",this.now().getLine()));
             match_lparent();
             parserForStmt();
             match_semicn();
             parserCond();
             match_semicn();
             parserForStmt();
             match_rparent();
             parserStmt();
             //三种情况
         } else if(returnContent().equals("break")) {
             addToList(new Token(Token.Type.KEYWORD,"break",this.now().getLine()));
             match_semicn();
         } else if(returnContent().equals("continue")) {
             addToList(new Token(Token.Type.KEYWORD,"continue",this.now().getLine()));
             match_semicn();
         }else if(returnContent().equals("{")) {
             parserBlock();
         } else if(returnContent().equals("return")) {
             int line = this.now().getLine();
             addToList(new Token(Token.Type.KEYWORD,"return",this.now().getLine()));
             if (this.now().getLine()==line) {
                 parserExp();
                 match_semicn();
             }
             else {
                 this.up();
                 errors.add(new Error(Error.Type.ERROR_I,now().getLine(),"i"));
                 this.move();
                 sign = 1;
             }
         } else if(returnContent().equals("printf")) {
             addToList(new Token(Token.Type.KEYWORD,"printf",this.now().getLine()));
             addToList(new Token(Token.Type.LPARENT,"(",this.now().getLine()));
             addToList(new Token(Token.Type.STRCON,returnContent(),this.now().getLine()));
             while(returnContent().equals(",")) {
                 addToList(new Token(Token.Type.COMMA,",",this.now().getLine()));
                 parserExp();
             }
             match_rparent();
             match_semicn();
         } else if(this.now().getType() == Token.Type.IDENFR) {
            this.move();
            if(returnContent().equals("=")) {
                /*if (returnContent().equals("[")) {
                   while(!returnContent().equals(";"))  {
                       this.move();
                       if (returnContent().equals("=")) {
                          sign_assign = 1;
                          break;
                       }
                   }
                while(!returnContent().equals("[")) {
                    this.up();
                }
                }*/
                this.up();
                parserLval();
                addToList(new Token(Token.Type.ASSIGN,"=",this.now().getLine()));
                if(this.now().getType()== Token.Type.KEYWORD) {
                    addToList(new Token(Token.Type.KEYWORD,returnContent(),this.now().getLine()));
                    addToList(new Token(Token.Type.LPARENT,"(",this.now().getLine()));
                    match_rparent();
                    match_semicn();
                }
                else {
                    parserExp();
                    match_semicn();
                }
            } else if (returnContent().equals("[")) {
                int count = 0;
                while (!returnContent().equals(";")) {
                  this.move();
                  count++;
                  if(returnContent().equals("=")) {
                      sign_assign = 1;
                      break;
                  }
              }
                for(int j = count; j>0 ; j--) {
                    this.up();
                }

                if(sign_assign == 1) {
                    this.up();
                    parserLval();
                    addToList(new Token(Token.Type.ASSIGN,"=",this.now().getLine()));
                    if(this.now().getType()== Token.Type.KEYWORD) {
                        addToList(new Token(Token.Type.KEYWORD,returnContent(),this.now().getLine()));
                        addToList(new Token(Token.Type.LPARENT,"(",this.now().getLine()));
                        match_rparent();
                        match_semicn();
                    }
                    else {
                        parserExp();
                        match_semicn();
                    }
                }
                else {
                    this.up();
                    parserExp();
                    match_semicn();
                }

            }
            else {
                this.up();
                parserExp();
                match_semicn();
            }
         } else  {
             parserExp();
             match_semicn();
         }
         addToList(new Token(Token.Type.NAME,"<Stmt>",0));


    }

    public void parserForStmt() {
        if(returnContent().equals(";")||returnContent().equals(")")) {
            return;
        }
        parserLval();
        match_assign();
        parserExp();
        addToList(new Token(Token.Type.NAME,"<ForStmt>",0));
    }

    public void parserCond() {
        if(returnContent().equals(";")) {
            return ;
        }
        parserLOrExp();
        this.addToList(new Token(Token.Type.NAME,"<Cond>",0));
    }

    public void parserMulExp() {
        parserUnaryExp();
        while(returnContent().equals("*")||returnContent().equals("%")
        ||returnContent().equals("/")) {
            addToList(new Token(Token.Type.NAME,"<MulExp>",0));
            addToList(new Token(this.now().getType(), returnContent(),this.now().getLine()));
            parserUnaryExp();
        }
        addToList(new Token(Token.Type.NAME,"<MulExp>",0));
    }

    public void parserLOrExp() {
       parserLAndExp();
       while(returnContent().equals("||")) {
           addToList(new Token(Token.Type.NAME,"<LOrExp>",0));
           addToList(new Token(this.now().getType(),returnContent(),this.now().getLine()));
           parserLAndExp();
       }
       addToList(new Token(Token.Type.NAME,"<LOrExp>",0));
    }

    public void parserLAndExp() {
        parserEqExp();
        while(returnContent().equals("&&")) {
            addToList(new Token(Token.Type.NAME,"<LAndExp>",0));
            addToList(new Token(this.now().getType(),returnContent(),this.now().getLine()));
            parserEqExp();
        }
        addToList(new Token(Token.Type.NAME,"<LAndExp>",0));
    }

    public void parserConstExp(){
        if(returnContent().equals("}")) {
            return;
        }
        parserAddExp();
        addToList(new Token(Token.Type.NAME,"<ConstExp>",0));
    }

    public void  parserConstInitVal(){
        if (this.now().getType()== Token.Type.STRCON) {
           addToList(new Token(Token.Type.STRCON,returnContent(),this.now().getLine()));

        } else if (returnContent().equals("{")) {
            addToList(new Token(Token.Type.LBRACE,"{",this.now().getLine()));
            parserConstExp();
            while(returnContent().equals(",")) {
                addToList(new Token(Token.Type.COMMA,",",this.now().getLine()));
                parserConstExp();
            }
            match_rbrace();
        } else  {
            parserConstExp();
        }

        addToList(new Token(Token.Type.NAME,"<ConstInitVal>",0));

    }

    public void parserAddExp(){
        parserMulExp();
        while (returnContent().equals("+")||returnContent().equals("-")) {
            addToList(new Token(Token.Type.NAME,"<AddExp>",0));
            addToList(new Token(this.now().getType(),returnContent(),this.now().getLine()));
            parserMulExp();
        }
        addToList(new Token(Token.Type.NAME,"<AddExp>",0));
    }

    public void parserRelExp() {
        parserAddExp();
        while(returnContent().equals("<")||returnContent().equals(">")||
        returnContent().equals(">=")||returnContent().equals("<=")) {
            addToList(new Token(Token.Type.NAME,"<RelExp>",0));
            addToList(new Token(this.now().getType(),returnContent(),this.now().getLine()));
        parserAddExp();
        }
        addToList(new Token(Token.Type.NAME,"<RelExp>",0));
    }

    public void parserEqExp() {
        parserRelExp();
        while(returnContent().equals("==")||returnContent().equals("!=")) {
            addToList(new Token(Token.Type.NAME,"<EqExp>",0));
            addToList(new Token(this.now().getType(),returnContent(),this.now().getLine()));
            parserRelExp();
        }
        addToList(new Token(Token.Type.NAME,"<EqExp>",0));
    }


    public void parserUnaryOp() {
       addToList(new Token(this.now().getType(), returnContent(),this.now().getLine()));
       addToList(new Token(Token.Type.NAME,"<UnaryOp>",0));
    }

    public void parserUnaryExp() {
         if(returnContent().equals("(")) {
             parserPrimaryExp();
         } else if(this.now().getType() == Token.Type.INTCON) {
             parserPrimaryExp();
         } else if(returnContent().equals("+") ||
                 returnContent().equals("-") ||
         returnContent().equals("!")) {
             parserUnaryOp();
             parserUnaryExp();
         } else if (this.now().getType() == Token.Type.IDENFR) {
            this.move();
            if(returnContent().equals("(")){
                this.up();
                addToList(new Token(Token.Type.IDENFR,returnContent(),this.now().getLine()));
                addToList(new Token(Token.Type.LPARENT,"(",this.now().getLine()));
                parserFuncRParams();
                match_rparent();
            } else {
                this.up();
                parserPrimaryExp();
            }
         } else {
            parserPrimaryExp();
         }

         addToList(new Token(Token.Type.NAME,"<UnaryExp>",0));
    }

    public void parserFuncRParams() {
        if(returnContent().equals(")")||returnContent().equals("{")) {
            return;
        }
        parserExp();
        while(returnContent().equals(",")) {
            addToList(new Token(Token.Type.COMMA,",",this.now().getLine()));
            parserExp();
        }
        this.addToList(new Token(Token.Type.NAME,"<FuncRParams>",0));
    }


    public void parserPrimaryExp(){
        if(this.now().getContent().equals("(")){
            addToList(new Token(Token.Type.LPARENT,"(",this.now().getLine()));
            parserExp();
            match_rparent();
        }
        else if (this.now().getType() == Token.Type.INTCON) {
             addToList(new Token(Token.Type.INTCON,returnContent(),this.now().getLine()));
             addToList(new Token(Token.Type.NAME,"<Number>",0));
        }
        else if (this.now().getType() == Token.Type.CHRCON) {
            addToList(new Token(Token.Type.CHRCON,returnContent(),this.now().getLine()));
            addToList(new Token(Token.Type.NAME,"<Character>",0));
        }else {
            parserLval();
        }
        addToList(new Token(Token.Type.NAME,"<PrimaryExp>",0));
    }

    public void parserLval() {
        match_Ident();
        if(this.now().getContent().equals("[")) {
            addToList(new Token(Token.Type.LBRACK,"[",this.now().getLine()));
            parserExp();
           match_rbrack();
        }
        addToList(new Token(Token.Type.NAME,"<LVal>",0));
    }

    public void parserExp(){
        this.up();
        int line = this.now().getLine();
        this.move();
        if (returnContent().equals(";")||returnContent().equals("}")) {
            return;
        }
        parserAddExp();
        addToList(new Token(Token.Type.NAME,"<Exp>",0));
    }


    public Token now() {
        if(cur< tokens.size())
            return tokens.get(cur);
        else
            return null;
    }

    public void move() {
        this.cur++;
    }

    public void up() {
        this.cur--;
    }

    public boolean match_assign(){
        if(this.now().getType() == Token.Type.ASSIGN) {
           addToList(new Token(Token.Type.ASSIGN,returnContent(),this.now().getLine()));
            return true;
        }
        this.move();
        return false;
    }

    public boolean match_Ident(){
        if(this.now().getType() == Token.Type.IDENFR){
            addToList(new Token(Token.Type.IDENFR,returnContent(),this.now().getLine()));
            return true;
        }
        this.move();
        return false;
    }

    public void addToList(Token token){
        this.list.add(token);
        if(token.getType()!= Token.Type.NAME)
            this.move();
    }

    public String returnContent() {
        if(cur < tokens.size())
            return this.now().getContent();
        else {
            return "end";
        }
    }

    public boolean match_BType(){
       if(returnContent().equals("int") || returnContent().equals("char") ){
           addToList(new Token(Token.Type.KEYWORD,returnContent(),this.now().getLine()));
           return true;
       }
       this.move();
       return false;
    }

    public boolean match_rbrack() {
        if(returnContent().equals("]")) {
            addToList(new Token(Token.Type.RBRACK,"]",this.now().getLine()));
            return true;
        }
        this.up();
        errors.add(new Error(Error.Type.ERROR_K,this.now().getLine(),"k"));
        this.move();
        sign = 1;
        return false;
    }

    public boolean  match_rbrace(){
        if(returnContent().equals("}")) {
            addToList(new Token(Token.Type.RBRACE,"}",this.now().getLine()));
            return true;
        }
        this.move();
        return false;
    }

    public boolean match_funcType(){
        if(returnContent().equals("void")
                ||returnContent().equals("int")
                ||returnContent().equals("char")) {
            addToList(new Token(Token.Type.KEYWORD,returnContent(),this.now().getLine()));
            return true;
        }
        this.move();
        return false;
    }

    public boolean match_lparent() {
        if(returnContent().equals("(")) {
            addToList(new Token(Token.Type.LPARENT,returnContent(),this.now().getLine()));
            return true;
        }
        this.move();
        return false;
    }

    public boolean match_rparent() {
        if(returnContent().equals(")")) {
            addToList(new Token(Token.Type.RPARENT,returnContent(),this.now().getLine()));
            return true;
        }
        this.up();
        errors.add(new Error(Error.Type.ERROR_J, now().getLine(),"j"));
        this.move();
        sign = 1;
        return false;
    }

    public boolean match_semicn() {
        if(returnContent().equals(";")) {
            addToList(new Token(Token.Type.SEMICN,";",this.now().getLine()));
            return true;
        }
        this.up();
        errors.add(new Error(Error.Type.ERROR_I,now().getLine(),"i"));
        this.move();
        sign = 1;
        return false;
    }
}
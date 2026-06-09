package frontend;

import frontend.grammatical_item.*;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Parser {
     ArrayList<Sym> symList = Lexer.symList;
     ArrayList<Error> errorList = Lexer.errorList;
     FileWriter lw = new FileWriter("parser.txt");
     FileWriter ew = new FileWriter("error.txt");
     int i = 0;
     Sym now;
     public void nextSym() {
          now = symList.get(i);
          i++;
     };

     public void lastSym() {
          i--;
          now = symList.get(i - 1);
     };
     public boolean IsBType(String s) {
          return (s.equals("int") || s.equals("char"));
     }

     public boolean IsFuncType(String s) {
          return (s.equals("void") || s.equals("int") || s.equals("char"));
     }

     public boolean IsUnaryOp(String s) {
          return (s.equals("+") || s.equals("-") || s.equals("!"));
     }

     public boolean IsMulOp(String s) {
          return (s.equals("*") || s.equals("/") || s.equals("%"));
     }

     public boolean IsAddOp(String s) {
          return (s.equals("+") || s.equals("-"));
     }

     public boolean IsRelOp(String s) {
          return (s.equals("<") || s.equals(">") || s.equals("<=") || s.equals(">="));
     }

     public boolean IsEqOp(String s) {
          return (s.equals("==") || s.equals("!="));
     }

     public boolean IsLAndOp(String s) {
          return s.equals("&&");
     }

     public boolean IsLOrOp(String s) {
          return s.equals("||");
     }

     public CompUnit CompUnit_func() {
          CompUnit compUnit = new CompUnit();
          nextSym();
          while(i <= symList.size()) {
               if(now.token.equals("const")) {
                    compUnit.decls.add(Decl_func());
                    nextSym();
               }
               if(now.token.equals("void")) {
                    compUnit.funcDefs.add(FuncDef_func());
                    nextSym();
               }
               if(now.token.equals("char")) {
                    if(symList.get(i).type.equals("IDENFR")){
                         if(symList.get(i + 1).token.equals("(")) {
                              compUnit.funcDefs.add(FuncDef_func());
                              nextSym();
                         }
                         else {
                              compUnit.decls.add(Decl_func());
                              nextSym();
                         }
                    }
               }
               if(now.token.equals("int")){
                     if(symList.get(i).token.equals("main")){
                         compUnit.mainFuncDef = MainFuncDef_func();
                         if(compUnit.mainFuncDef != null)
                              break;
                    }
                    if(symList.get(i).type.equals("IDENFR")){
                         if(symList.get(i + 1).token.equals("(")) {
                                   compUnit.funcDefs.add(FuncDef_func());
                                   nextSym();
                         }
                         else {
                              compUnit.decls.add(Decl_func());
                              nextSym();
                         }
                    }
               }
          }
          return compUnit;
     }

     public Decl Decl_func() {
          Decl decl = new Decl();
          if(now.token.equals("const")) {
               decl.constDecl = ConstDecl_func();
               if(decl.constDecl == null)
                    return null;
          }
          else {
               decl.varDecl = VarDecl_func();
               if(decl.varDecl == null)
                    return null;
          }
          return decl;
     }

     public FuncDef FuncDef_func() {
          FuncDef funcDef = new FuncDef();
          if(IsFuncType(now.token)) {
               funcDef.funcType = now.token;
               nextSym();
               if(now.type.equals("IDENFR")) {
                    funcDef.ident = now.token;
                    nextSym();
                    if(now.token.equals("(")) {
                         funcDef.LPARENT = "(";
                         nextSym();
                         if(IsBType(now.token)) {
                              funcDef.funcFParams.add(FuncFParam_func());
                              nextSym();
                              while(now.token.equals(",")) {
                                   nextSym();
                                   funcDef.funcFParams.add(FuncFParam_func());
                                   nextSym();
                              }
                         }
                         if(now.token.equals(")")) {
                              funcDef.RPARENT = ")";
                              nextSym();
                              funcDef.block = Block_func();
                         }
                         else {
                              //j型错误输出
                              Error error = new Error(symList.get(i - 2).line, "j");
                              errorList.add(error);
                              funcDef.block = Block_func();
                         }
                    }
                    else {
                         lastSym();
                         lastSym();
                         return null;
                    }
               }
               else {
                    lastSym();
                    return null;
               }
          }
          else {
               return null;
          }
          return funcDef;
     }

     public MainFuncDef MainFuncDef_func() {
          MainFuncDef mainFuncDef = new MainFuncDef();
          if(now.token.equals("int")) {
               mainFuncDef.INTTK = "int";
               nextSym();
               if(now.token.equals("main")) {
                    mainFuncDef.MAINTK = "main";
                    nextSym();
                    if(now.token.equals("(")) {
                         mainFuncDef.LPARENT = "(";
                         nextSym();
                         if(now.token.equals(")")) {
                              mainFuncDef.RPARENT = ")";
                              nextSym();
                              mainFuncDef.block = Block_func();
                              if(mainFuncDef.block == null){
                                   lastSym();
                                   lastSym();
                                   lastSym();
                                   lastSym();
                                   return null;
                              }
                         }
                         else {
                              // j型错误输出
                              Error error = new Error(symList.get(i - 2).line, "j");
                              errorList.add(error);

                              mainFuncDef.block = Block_func();
                              if(mainFuncDef.block == null){
                                   lastSym();
                                   lastSym();
                                   lastSym();
                                   return null;
                              }
                         }
                    }
                    else {
                         lastSym();
                         lastSym();
                         return null;
                    }
               }
               else {
                    lastSym();
                    return null;
               }
          }
          else {
               return null;
          }
          return mainFuncDef;
     }

     public ConstDecl ConstDecl_func() {
          ConstDecl constDecl = new ConstDecl();
          if(now.token.equals("const")) {
               constDecl.CONSTTK = "const";
               nextSym();
               if(IsBType(now.token)) {
                    constDecl.BType = now.token;
                    nextSym();
                    constDecl.constDefs.add(ConstDef_func());
                    nextSym();
                    while(now.token.equals(",")) {
                         nextSym();
                         constDecl.constDefs.add(ConstDef_func());
                         nextSym();
                    }
                    if(!now.token.equals(";")) {
                         //i型错误输出
                         Error error = new Error(symList.get(i - 2).line, "i");
                         errorList.add(error);
                         lastSym();
                    }
               }
               else {
                    lastSym();
                    return null;
               }
          }
          else {
               return null;
          }
          return constDecl;
     }

     public VarDecl VarDecl_func() {
          VarDecl varDecl = new VarDecl();
          if(IsBType(now.token)) {
               varDecl.BType = now.token;
               nextSym();
               varDecl.varDefs.add(VarDef_func());
               nextSym();
               while(now.token.equals(",")) {
                    nextSym();
                    varDecl.varDefs.add(VarDef_func());
                    nextSym();
               }
               if(!now.token.equals(";")) {
                    //i型错误输出
                    Error error = new Error(symList.get(i - 2).line, "i");
                    errorList.add(error);
                    lastSym();
               }
               else {
                    varDecl.SEMICN = ";";
               }
          }
          else {
               return null;
          }
          return varDecl;
     }

     public ConstDef ConstDef_func() {
          ConstDef constDef = new ConstDef();
          if(now.type.equals("IDENFR")) {
               constDef.Ident = now.token;
               nextSym();
               if(now.token.equals("[")) {
                    constDef.LBRACK = "[";
                    nextSym();
                    constDef.constExp = ConstExp_func();
                    nextSym();
                    if(now.token.equals("]")) {
                         constDef.RBRACK = "]";
                         nextSym();
                    }
                    else {
                         // k型错误输出
                         Error error = new Error(symList.get(i - 2).line, "k");
                         errorList.add(error);
                    }
               }
               if(now.token.equals("=")) {
                    constDef.ASSIGN = "=";
                    nextSym();
                    constDef.constInitVal = ConstInitVal_func();
               }
          }
          else {
               return null;
          }
          return constDef;
     }

     public ConstExp ConstExp_func() {
          ConstExp constExp = new ConstExp();
          constExp.addExp = AddExp_func();
          return constExp;
     }

     public ConstInitVal ConstInitVal_func() {
          ConstInitVal constInitVal = new ConstInitVal();
          if(now.token.equals("{")) {
               constInitVal.LBRACE = "{";
               nextSym();
               if(now.token.equals("}")) {
                    constInitVal.RBRACE = "}";
               }
               else {
                    constInitVal.constExps.add(ConstExp_func());
                    nextSym();
                    while(now.token.equals(",")) {
                         nextSym();
                         constInitVal.constExps.add(ConstExp_func());
                         nextSym();
                    }
                    if(now.token.equals("}")) {
                         constInitVal.RBRACE = "}";
                    }
               }
          }
          else if(now.type.equals("STRCON")) {
               constInitVal.StringConst = now.token;
          }
          else {
               constInitVal.constExp = ConstExp_func();
          }
          return constInitVal;
     }

     public VarDef VarDef_func() {
          VarDef varDef = new VarDef();
          if(now.type.equals("IDENFR")) {
               varDef.Ident = now.token;
               nextSym();
               if(now.token.equals("[")) {
                    varDef.LBRACK = "[";
                    nextSym();
                    varDef.constExp = ConstExp_func();
                    nextSym();
                    if(now.token.equals("]")) {
                         varDef.RBRACK = "]";
                         nextSym();
                    }
                    else {
                         // k型错误输出
                         Error error = new Error(symList.get(i - 2).line, "k");
                         errorList.add(error);
                    }
               }
               if(now.token.equals("=")) {
                    varDef.ASSIGN = "=";
                    nextSym();
                    varDef.initVal = InitVal_func();
               }
               else {
                    lastSym();
               }
          }
          else {
               return null;
          }
          return varDef;
     }
     public InitVal InitVal_func() {
          InitVal initVal = new InitVal();
          if(now.token.equals("{")) {
               initVal.LBRACE = "{";
               nextSym();
               if(now.token.equals("}")) {
                    initVal.RBRACE = "}";
               }
               else {
                    initVal.exps.add(Exp_func());
                    nextSym();
                    while(now.token.equals(",")) {
                         nextSym();
                         initVal.exps.add(Exp_func());
                         nextSym();
                    }
                    if(now.token.equals("}")) {
                         initVal.RBRACE = "}";
                    }
               }
          }
          else if(now.type.equals("STRCON")) {
               initVal.StringConst = now.token;
          }
          else {
               initVal.exp = Exp_func();
          }
          return initVal;
     }

     public Exp Exp_func() {
          Exp exp = new Exp();
          exp.addExp = AddExp_func();
          if(exp.addExp == null)
               return null;
          return exp;
     }

     public FuncFParam FuncFParam_func() {
          FuncFParam funcFParam = new FuncFParam();
          if(IsBType(now.token)) {
               funcFParam.BType = now.token;
               nextSym();
               if(now.type.equals("IDENFR")) {
                    funcFParam.Ident = now.token;
                    nextSym();
                    if(now.token.equals("[")) {
                         funcFParam.LBRACK = "[";
                         nextSym();
                         if(now.token.equals("]")) {
                              funcFParam.RBRACK = "]";
                         }
                         else {
                              //k型错误输出
                              Error error = new Error(symList.get(i - 2).line, "k");
                              errorList.add(error);
                              lastSym();
                         }
                    }
                    else {
                         lastSym();
                    }
               }
               else {
                    lastSym();
                    return null;
               }
          }
          else {
               return null;
          }
          return funcFParam;
     }

     public Block Block_func() {
          Block block = new Block();
          if(now.token.equals("{")) {
               block.LBRACE = "{";
               nextSym();
               if(now.token.equals("}")) {
                    block.RBRACE = "}";
               }
               else {
                    while(!now.token.equals("}")) {
                         block.blockItems.add(BlockItem_func());
                         nextSym();
                    }
                    block.RBRACE = "}";
               }
          }
          else {
               return null;
          }
          return block;
     }

     public BlockItem BlockItem_func() {
          BlockItem blockItem = new BlockItem();
          if(now.token.equals("int") || now.token.equals("char") || now.token.equals("const")) {
               blockItem.decl = Decl_func();
          }
          else {
               blockItem.stmt = Stmt_func();
          }
          return blockItem;
     }

     public Stmt Stmt_func() {
         Stmt stmt = new Stmt();
         switch (now.token) {
             case "if" -> {
                 stmt.IFTK = "if";
                 nextSym();
                 if (now.token.equals("(")) {
                     stmt.LPARENT = "(";
                     nextSym();
                     stmt.cond = Cond_func();
                     if (stmt.cond == null)
                         return null;
                     nextSym();
                     if (now.token.equals(")")) {
                         stmt.RPARENT = ")";
                         nextSym();
                     } else {
                         // j型错误输出
                          Error error = new Error(symList.get(i - 2).line, "j");
                          errorList.add(error);
                     }
                     stmt.stmt = Stmt_func();
                     if (stmt.stmt == null)
                         return null;
                     nextSym();
                     if (now.token.equals("else")) {
                         stmt.ELSETK = "else";
                         nextSym();
                         stmt.else_stmt = Stmt_func();
                         if (stmt.else_stmt == null)
                             return null;
                     } else {
                         lastSym();
                     }
                 } else {
                     return null;
                 }
             }
             case "for" -> {
                  stmt.FORTK = "for";
                  nextSym();
                  if(now.token.equals("(")) {
                       stmt.LPARENT = "(";
                       nextSym();
                       Sym j = now;
                       int k = i;
                       stmt.First_forStmt = ForStmt_func();
                       if(stmt.First_forStmt == null) {
                            now = j;
                            i = k;
                       }
                       else {
                            nextSym();
                       }
                       if(now.token.equals(";")) {
                            stmt.First_for_SEMICN = ";";
                            nextSym();
                       }
                       else {
                            //i型错误输出
                            Error error = new Error(symList.get(i - 2).line, "i");
                            errorList.add(error);
                       }
                       j = now;
                       k = i;
                       stmt.cond = Cond_func();
                       if(stmt.cond == null) {
                            now = j;
                            i = k;
                       }
                       else {
                            nextSym();
                       }
                       if(now.token.equals(";")) {
                            stmt.Second_for_SEMICN = ";";
                            nextSym();
                       }
                       else {
                            //i型错误输出
                            Error error = new Error(symList.get(i - 2).line, "i");
                            errorList.add(error);
                       }
                       j = now;
                       k = i;
                       stmt.Second_forStmt = ForStmt_func();
                       if(stmt.Second_forStmt == null) {
                            now = j;
                            i = k;
                       }
                       else {
                            nextSym();
                       }
                       if(now.token.equals(")")) {
                            stmt.RPARENT = ")";
                            nextSym();
                       }
                       else {
                            //j型错误输出
                            Error error = new Error(symList.get(i - 2).line, "j");
                            errorList.add(error);
                       }
                       stmt.stmt = Stmt_func();
                       if(stmt.stmt == null) {
                            return null;
                       }
                  }
                  else {
                       return null;
                  }
             }
             case "break" -> {
                  stmt.BREAKTK = "break";
                  nextSym();
                  if(now.token.equals(";")) {
                       stmt.SEMICN = ";";
                  }
                  else {
                       //i型错误输出
                       Error error = new Error(symList.get(i - 2).line, "i");
                       errorList.add(error);
                       lastSym();
                  }
             }
             case "continue" -> {
                  stmt.CONTINUETK = "continue";
                  nextSym();
                  if(now.token.equals(";")) {
                       stmt.SEMICN = ";";
                  }
                  else {
                       //i型错误输出
                       Error error = new Error(symList.get(i - 2).line, "i");
                       errorList.add(error);
                       lastSym();
                  }
             }
             case "return" -> {
                  stmt.RETURNTK = "return";
                  nextSym();
                  Sym j = now;
                  int k = i;
                  stmt.exp = Exp_func();
                  if(stmt.exp == null) {
                       now = j;
                       i = k;
                       if(now.token.equals(";")) {
                            stmt.SEMICN = ";";
                       }
                       else {
                            //i型错误输出
                            Error error = new Error(symList.get(i - 2).line, "i");
                            errorList.add(error);
                            lastSym();
                       }
                  }
                  else {
                       nextSym();
                       if(now.token.equals(";")) {
                            stmt.SEMICN = ";";
                       }
                       else {
                            //i型错误输出
                            Error error = new Error(symList.get(i - 2).line, "i");
                            errorList.add(error);
                            lastSym();
                       }
                  }
             }
             case "printf" -> {
                  stmt.PRINTFTK = "printf";
                  nextSym();
                  if(now.token.equals("(")) {
                       stmt.LPARENT = "(";
                       nextSym();
                       if(now.type.equals("STRCON")) {
                            stmt.StringConst = now.token;
                            nextSym();
                            while (now.token.equals(",")) {
                                 nextSym();
                                 stmt.exps.add(Exp_func());
                                 nextSym();
                            }
                            if(now.token.equals(")")) {
                                 stmt.RPARENT = ")";
                                 nextSym();
                            }
                            else {
                                 //j型错误输出
                                 Error error = new Error(symList.get(i - 2).line, "j");
                                 errorList.add(error);
                            }
                            if(now.token.equals(";")) {
                                 stmt.SEMICN = ";";
                            }
                            else {
                                 //i型错误输出
                                 Error error = new Error(symList.get(i - 2).line, "i");
                                 errorList.add(error);
                                 lastSym();
                            }
                       }
                       else {
                            return null;
                       }
                  }
                  else {
                       return null;
                  }
             }
             case ";" -> stmt.SEMICN = ";";
             case "{" -> {
                  stmt.block = Block_func();
                  if(stmt.block == null)
                       return null;
             }
             default -> {
                 Sym j = now;
                 int k = i;
                 stmt.lVal = LVal_func();
                 if(stmt.lVal == null) {
                      now = j;
                      i = k;
                      stmt.exp = Exp_func();
                      if (stmt.exp == null) {
                           now = j;
                           i = k;
                           return null;
                      }
                      nextSym();
                      if(now.token.equals(";")) {
                           stmt.SEMICN = ";";
                      }
                      else {
                           //i型错误输出
                           Error error = new Error(symList.get(i - 2).line, "i");
                           errorList.add(error);
                           lastSym();
                      }
                 }
                 else {
                      nextSym();
                      if (now.token.equals("=")) {
                           stmt.ASSIGN = "=";
                           nextSym();
                           if (now.token.equals("getint")) {
                                stmt.GETINTTK = "getint";
                                nextSym();
                                if(now.token.equals("(")) {
                                     stmt.LPARENT = "(";
                                     nextSym();
                                     if(now.token.equals(")")) {
                                          stmt.RPARENT = ")";
                                          nextSym();
                                     }
                                     else {
                                          //j型错误输出
                                          Error error = new Error(symList.get(i - 2).line, "j");
                                          errorList.add(error);
                                     }
                                     if(now.token.equals(";")) {
                                          stmt.SEMICN = ";";
                                     }
                                     else {
                                          //i型错误输出
                                          Error error = new Error(symList.get(i - 2).line, "i");
                                          errorList.add(error);
                                          lastSym();
                                     }
                                }
                                else {
                                     return null;
                                }
                           }
                           else if (now.token.equals("getchar")) {
                                stmt.GETCHARTK = "getchar";
                                nextSym();
                                if(now.token.equals("(")) {
                                     stmt.LPARENT = "(";
                                     nextSym();
                                     if(now.token.equals(")")) {
                                          stmt.RPARENT = ")";
                                          nextSym();
                                     }
                                     else {
                                          //j型错误输出
                                          Error error = new Error(symList.get(i - 2).line, "j");
                                          errorList.add(error);
                                     }
                                     if(now.token.equals(";")) {
                                          stmt.SEMICN = ";";
                                     }
                                     else {
                                          //i型错误输出
                                          Error error = new Error(symList.get(i - 2).line, "i");
                                          errorList.add(error);
                                          lastSym();
                                     }
                                }
                                else {
                                     return null;
                                }
                           }
                           else {
                                stmt.exp = Exp_func();
                                if(stmt.exp == null)
                                     return null;
                                nextSym();
                                if(now.token.equals(";")) {
                                     stmt.SEMICN = ";";
                                }
                                else {
                                     //i型错误输出
                                     Error error = new Error(symList.get(i - 2).line, "i");
                                     errorList.add(error);
                                     lastSym();
                                }
                           }
                      } else {
                           now = j;
                           i = k;
                           stmt.lVal = null;
                           stmt.exp = Exp_func();
                           if (stmt.exp == null) {
                                now = j;
                                i = k;
                                return null;
                           }
                           nextSym();
                           if(now.token.equals(";")) {
                                stmt.SEMICN = ";";
                           }
                           else {
                                //i型错误输出
                                Error error = new Error(symList.get(i - 2).line, "i");
                                errorList.add(error);
                                lastSym();
                           }
                      }
                 }
             }
         }
          return stmt;
     }

     public LVal LVal_func() {
          LVal lVal = new LVal();
          if(now.type.equals("IDENFR")) {
               lVal.Ident = now.token;
               nextSym();
               if(now.token.equals("[")) {
                    lVal.LBRACK = "[";
                    nextSym();
                    Sym j = now;
                    int k = i;
                    lVal.exp = Exp_func();
                    if(lVal.exp == null) {
                         now = j;
                         i = k;
                         lastSym();
                         lastSym();
                         return null;
                    }
                    nextSym();
                    if(now.token.equals("]")) {
                         lVal.RBRACK = "]";
                    }
                    else {
                         // k型错误输出
                         Error error = new Error(symList.get(i - 2).line, "k");
                         errorList.add(error);
                         lastSym();
                    }
               }
               else {
                    lastSym();
               }
          }
          else {
               return null;
          }
          return lVal;
     }

     public Cond Cond_func() {
          Cond cond = new Cond();
          cond.lOrExp = LOrExp_func();
          if(cond.lOrExp == null)
               return null;
          return cond;
     }

     public ForStmt ForStmt_func() {
          ForStmt forStmt = new ForStmt();
          forStmt.lVal = LVal_func();
          if(forStmt.lVal == null) {
               return null;
          }
          else {
               nextSym();
               if(now.token.equals("=")) {
                    forStmt.ASSIGN = "=";
                    nextSym();
                    forStmt.exp = Exp_func();
                    if(forStmt.exp == null) {
                         return null;
                    }
               }
               else {
                    return null;
               }
          }
          return forStmt;
     }

     public LOrExp LOrExp_func() {
          LOrExp lOrExp = new LOrExp();
          lOrExp.lAndExps.add(LAndExp_func());
          if(lOrExp.lAndExps.isEmpty() ||  lOrExp.lAndExps.get(0) == null) {
               lOrExp.lAndExps.clear();
               return null;
          }
          else {
               nextSym();
               while (IsLOrOp(now.token)) {
                    lOrExp.LOrOps.add(now.token);
                    nextSym();
                    LAndExp lAndExp = LAndExp_func();
                    if(lAndExp != null) {
                         lOrExp.lAndExps.add(lAndExp);
                    }
                    else {
                         return null;
                    }
                    nextSym();
               }
               lastSym();
          }
          return lOrExp;
     }

     public LAndExp LAndExp_func() {
          LAndExp lAndExp = new LAndExp();
          lAndExp.eqExps.add(EqExp_func());
          if(lAndExp.eqExps.isEmpty() || lAndExp.eqExps.get(0) == null) {
               lAndExp.eqExps.clear();
               return null;
          }
          else {
               nextSym();
               while (IsLAndOp(now.token)) {
                    lAndExp.LAndOps.add(now.token);
                    nextSym();
                    EqExp eqExp = EqExp_func();
                    if(eqExp != null) {
                         lAndExp.eqExps.add(eqExp);
                    }
                    else {
                         return null;
                    }
                    nextSym();
               }
               lastSym();
          }
          return lAndExp;
     }

     public EqExp EqExp_func() {
          EqExp eqExp = new EqExp();
          eqExp.relExps.add(RelExp_func());
          if(eqExp.relExps.isEmpty() || eqExp.relExps.get(0) == null) {
               eqExp.relExps.clear();
               return null;
          }
          else {
               nextSym();
               while (IsEqOp(now.token)) {
                    eqExp.EqOps.add(now.token);
                    nextSym();
                    RelExp relExp = RelExp_func();
                    if(relExp != null) {
                         eqExp.relExps.add(relExp);
                    }
                    else {
                         return null;
                    }
                    nextSym();
               }
               lastSym();
          }
          return eqExp;
     }

     public RelExp RelExp_func() {
          RelExp relExp = new RelExp();
          relExp.addExps.add(AddExp_func());
          if(relExp.addExps.isEmpty() || relExp.addExps.get(0) == null) {
               relExp.addExps.clear();
               return null;
          }
          else {
               nextSym();
               while (IsRelOp(now.token)) {
                    relExp.RelOps.add(now.token);
                    nextSym();
                    AddExp addExp = AddExp_func();
                    if(addExp != null) {
                         relExp.addExps.add(addExp);
                    }
                    else {
                         return null;
                    }
                    nextSym();
               }
               lastSym();
          }
          return relExp;
     }

     public AddExp AddExp_func() {
          AddExp addExp = new AddExp();
          addExp.mulExps.add(MulExp_func());
          if(addExp.mulExps.isEmpty() || addExp.mulExps.get(0) == null) {
               addExp.mulExps.clear();
               return null;
          }
          else {
               nextSym();
               while (IsAddOp(now.token)) {
                    addExp.AddOps.add(now.token);
                    nextSym();
                    MulExp mulExp = MulExp_func();
                    if(mulExp != null) {
                         addExp.mulExps.add(mulExp);
                    }
                    else {
                         return null;
                    }
                    nextSym();
               }
               lastSym();
          }
          return addExp;
     }

     public MulExp MulExp_func() {
          MulExp mulExp = new MulExp();
          mulExp.unaryExps.add(UnaryExp_func());
          if(mulExp.unaryExps.isEmpty() || mulExp.unaryExps.get(0) == null) {
               mulExp.unaryExps.clear();
               return null;
          }
          else {
               nextSym();
               while (IsMulOp(now.token)) {
                    mulExp.MulOps.add(now.token);
                    nextSym();
                    UnaryExp unaryExp = UnaryExp_func();
                    if(unaryExp != null) {
                         mulExp.unaryExps.add(unaryExp);
                    }
                    else {
                         return null;
                    }
                    nextSym();
               }
               lastSym();
          }
          return mulExp;
     }

     public UnaryExp UnaryExp_func() {
          UnaryExp unaryExp = new UnaryExp();
          if(now.type.equals("IDENFR")) {
               if(symList.get(i).token.equals("(")) {
                    unaryExp.Ident = now.token;
                    nextSym();
                    unaryExp.LPARENT = "(";
                    nextSym();
                    Sym j = now;
                    int k = i;
                    unaryExp.exps.add(Exp_func());
                    if(unaryExp.exps.isEmpty() || unaryExp.exps.get(0) == null) {
                         unaryExp.exps.clear();
                         now = j;
                         i = k;
                    }
                    else {
                         nextSym();
                         while (now.token.equals(",")) {
                              nextSym();
                              unaryExp.exps.add(Exp_func());
                              nextSym();
                         }
                    }
                    if(now.token.equals(")")) {
                         unaryExp.RPARENT = ")";
                    }
                    else {
                         //j型错误输出
                         Error error = new Error(symList.get(i - 2).line, "j");
                         errorList.add(error);
                         lastSym();
                    }
               }
               else {
                    Sym j = now;
                    int k = i;
                    unaryExp.primaryExp = PrimaryExp_func();
                    if(unaryExp.primaryExp == null) {
                         now = j;
                         i = k;
                         return null;
                    }
               }
          }
          else if(IsUnaryOp(now.token)) {
               unaryExp.unaryOp = now.token;
               nextSym();
               unaryExp.unaryExp = UnaryExp_func();
               if(unaryExp.unaryExp == null)
                    return null;
          }
          else {
               Sym j = now;
               int k = i;
               unaryExp.primaryExp = PrimaryExp_func();
               if(unaryExp.primaryExp == null) {
                    now = j;
                    i = k;
                    return null;
               }
          }
          return unaryExp;
     }

     public PrimaryExp PrimaryExp_func() {
          PrimaryExp primaryExp = new PrimaryExp();
          Sym j = now;
          int k = i;
          primaryExp.lVal = LVal_func();
          if(primaryExp.lVal == null) {
               now = j;
               i = k;
               if(now.token.equals("(")) {
                    primaryExp.LPARENT = "(";
                    nextSym();
                    j = now;
                    k = i;
                    primaryExp.exp = Exp_func();
                    if(primaryExp.exp == null) {
                         now = j;
                         i = k;
                         return null;
                    }
                    else {
                         nextSym();
                         if(now.token.equals(")")) {
                              primaryExp.RPARENT = ")";
                         }
                         else {
                              //j型错误输出
                              Error error = new Error(symList.get(i - 2).line, "j");
                              errorList.add(error);
                              lastSym();
                         }
                    }
               }
               else if(now.type.equals("INTCON")) {
                    primaryExp.Number = now.token;
               }
               else if(now.type.equals("CHRCON")) {
                    primaryExp.Character = now.token;
               }
               else {
                    return null;
               }
          }
          return primaryExp;
     }

     public Parser() throws IOException {
          CompUnit compUnit = CompUnit_func();
          if(errorList.isEmpty())
               compUnit.print(lw);
          else {
               //按行号排序
               Collections.sort(errorList);
               for (Error error : errorList) {
                    ew.write(error.line + " " + error.type + "\n");
               }
          }
          lw.close();
          ew.close();
     }

}

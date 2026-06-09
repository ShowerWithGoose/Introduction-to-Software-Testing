package frontend;

import javax.swing.tree.TreeNode;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;


public class Parser {
    public static int i = 0;
    public static int cnt = 0;
    public static Lexer_out now;
    public final static ArrayList<WrongExample> w = new ArrayList<>();
    public static final Node root = new Node("kaishiyufafenxi");

    public static void HouXu(Node root, FileWriter f, FileWriter p) {


        try {
            if (root == null) {
                return;
            }
            for (Node child : root.children) {
                HouXu(child, f, p);
            }
            if (root.name.equals("kaishiyufafenxi") || root.name.equals("<BlockItem>") || root.name.equals("<Decl>") || root.name.equals("<BType>")) {
                ;
            } else {
                p.write(root.name + "\n");
                p.flush();
                //System.out.println(root.name);
            }
        } catch (IOException e) {
            //System.out.println("wrong!!!");
            e.printStackTrace();
        }
    }

    public static void run() {
        /*for(int i = 0; i < Lexer.outs.size(); i++) {
            System.out.println(Lexer.outs.get(i).getType() + " " + Lexer.outs.get(i).getName() + " " + Lexer.outs.get(i).getLine_num());
        }*/

        /*while (i <= Lexer.outs.size() - 1) {
            now = Lexer.outs.get(i);
            System.out.println(now.getType() + " " + now.getName() + " " + now.getLine_num());
            i++;
        }*/
        i = 0;
        now = Lexer.outs.get(i);

        root.addChild(CompUnit());
        FileWriter f = null;

        try {
            FileWriter p = new FileWriter("parser.txt");
            HouXu(root, f, p);
        } catch (IOException e) {
            //System.out.println("wrong!!!");
            e.printStackTrace();
        }
    }

    public static Node getRoot() {
        return root;
    }
    public static Node CompUnit() {
        Node node = new Node("<CompUnit>");
        while (!Lexer.outs.get(i + 2).getName().equals("(")) {
            node.addChild(Decl());
        }
        while (!Lexer.outs.get(i + 1).getName().equals("main")) {
            node.addChild(FuncDef());
        }
        node.addChild(MainFuncDef());
        return node;
    }

    public static Node Decl() {
        Node node = new Node("<Decl>");
        if (now.getName().equals("const")) {
            node.addChild(ConstDecl());
        } else {
            node.addChild(VarDecl());
        }
        return node;
    }

    public static Node ConstDecl() {
        Node node = new Node("<ConstDecl>");
        if (now.getName().equals("const")) {
            node.addChild(new Node(/*"const"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(BType());
            node.addChild(ConstDef());
            while (now.getName().equals(",")) {
                node.addChild(new Node(/*","*/now.getType() + " " +now.getName()));
                now = Lexer.outs.get(++i);
                node.addChild(ConstDef());
            }
            if (now.getName().equals(";")) {
                node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                //错误处理
                w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
                cnt++;
                //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
            }
            //now = Lexer.outs.get(++i);
        }
        return node;
    }

    public static Node BType() {
        Node node = new Node("<BType>");
        if (now.getName().equals("int")) {
            node.addChild(new Node(/*"int"*/now.getType() + " " + now.getName()));
        } else {
            node.addChild(new Node(/*"char"*/now.getType() + " " + now.getName()));
        }
        now = Lexer.outs.get(++i);
        return node;
    }

    public static Node ConstDef() {
        Node node = new Node("<ConstDef>");
        node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
        now = Lexer.outs.get(++i);
        if (now.getName().equals("[")) {
            node.addChild(new Node(/*[*/now.getType() + " "+now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(ConstExp());
            if (now.getName().equals("]")) {
                node.addChild(new Node(/*"]"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                if (now.getName().equals("=")) {
                    node.addChild(new Node(/*"="*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    node.addChild(ConstInitVal());
                }
            } else {
                //错误处理
                w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "k"));
                cnt++;
                //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "k");
                node.addChild(new Node(/*"="*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                node.addChild(ConstInitVal());
            }

        } else {
            node.addChild(new Node(/*"="*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(ConstInitVal());
        }
        return node;
    }

    public static Node ConstInitVal() {
        Node node = new Node("<ConstInitVal>");
        if (now.getName().equals("{")) {
            node.addChild(new Node(/*"{"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            if (now.getName().equals("}")) {
                node.addChild(new Node(/*"}"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                node.addChild(ConstExp());
                while (now.getName().equals(",")) {
                    node.addChild(new Node(/*","*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    node.addChild(ConstExp());
                }
                if (now.getName().equals("}")) {
                    node.addChild(new Node(/*"}"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                }
            }
        } else if (now.getType().equals("STRCON")) {
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        } else {
            node.addChild(ConstExp());
        }
        return node;
    }

    public static Node VarDecl() {
        Node node = new Node("<VarDecl>");
        node.addChild(BType());
        node.addChild(VarDef());
        while (now.getName().equals(",")) {
            node.addChild(new Node(/*","*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(VarDef());
        }
        if (now.getName().equals(";")) {
            node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
            if (i < Lexer.outs.size() - 1) {
                now = Lexer.outs.get(++i);
            }
        } else {
            //错误处理
            w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
            cnt++;
            //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
        }
        return node;
    }

    public static Node VarDef() {
        Node node = new Node("<VarDef>");
        if (now.getType().equals("IDENFR")) {
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            if (now.getName().equals("[")) {
                node.addChild(new Node(/*"["*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                node.addChild(ConstExp());
                if (now.getName().equals("]")) {
                    node.addChild(new Node(/*"]"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    if (now.getName().equals("=")) {
                        node.addChild(new Node(/*"="*/now.getType() + " " + now.getName()));
                        now = Lexer.outs.get(++i);
                        node.addChild(InitVal());
                    }
                } else {
                    //错误处理
                    w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "k"));
                    cnt++;
                    if (now.getName().equals("=")) {
                        node.addChild(new Node(/*"="*/now.getType() + " " + now.getName()));
                        now = Lexer.outs.get(++i);
                        node.addChild(InitVal());
                    }
                    //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "k");
                }
            } else if (now.name.equals("=")) {
                node.addChild(new Node(/*"="*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                node.addChild(InitVal());
            }
        }
        return node;
    }

    public static Node InitVal() {
        Node node = new Node("<InitVal>");
        if (now.getType().equals("STRCON")) {
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        } else if (now.getName().equals("{")) {
            node.addChild(new Node(/*"{"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            if (now.getName().equals("}")) {
                node.addChild(new Node(/*"}"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                node.addChild(Exp());
                while (now.getName().equals(",")) {
                    node.addChild(new Node(/*","*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    node.addChild(Exp());
                }
                node.addChild(new Node(/*"}"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            }
        } else {
            node.addChild(Exp());
        }
        return node;
    }

    public static Node FuncDef() {
        Node node = new Node("<FuncDef>");
        node.addChild(FuncType());
        if (now.getType().equals("IDENFR")) {
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            if (now.getName().equals("(")) {
                node.addChild(new Node(/*"("*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                if (now.getName().equals(")")) {
                    node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    node.addChild(Block());
                } else if (now.getName().equals("{")) {
                    //错误处理
                    w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "j"));
                    cnt++;
                    node.addChild(Block());
                    //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "j");
                } else {
                    node.addChild(FuncFParams());
                    if (now.getName().equals(")")) {
                        node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                        now = Lexer.outs.get(++i);
                        node.addChild(Block());
                    } else {
                        //错误处理
                        w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "j"));
                        cnt++;
                        node.addChild(Block());
                        //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "j");
                    }
                }
            }
        }
        return node;
    }

    public static Node MainFuncDef() {
        Node node = new Node("<MainFuncDef>");
        if (now.getName().equals("int")) {
            node.addChild(new Node(/*"int"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            if (now.getName().equals("main")) {
                node.addChild(new Node(/*"main"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                if (now.getName().equals("(")) {
                    node.addChild(new Node(/*"("*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    if (now.getName().equals(")")) {
                        node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                        now = Lexer.outs.get(++i);
                        node.addChild(Block());
                    } else {
                        //错误处理
                        w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "j"));
                        cnt++;
                        node.addChild(Block());
                        //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "j");
                    }
                }
            }
        }
        return node;
    }

    public static Node FuncType() {
        Node node = new Node("<FuncType>");
        if (now.getName().equals("void")) {
            node.addChild(new Node(/*"void"*/now.getType() + " " + now.getName()));
        } else if (now.getName().equals("int")) {
            node.addChild(new Node(/*"int"*/now.getType() + " " + now.getName()));
        } else {
            node.addChild(new Node(/*"char"*/now.getType() + " " + now.getName()));
        }
        now = Lexer.outs.get(++i);
        return node;
    }

    public static Node FuncFParams() {
        Node node = new Node("<FuncFParams>");
        node.addChild(FuncFParam());
        while (now.getName().equals(",")) {
            node.addChild(new Node(/*","*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(FuncFParam());
        }
        return node;
    }

    public static Node FuncFParam() {
        Node node = new Node("<FuncFParam>");
        node.addChild(BType());
        if (now.getType().equals("IDENFR")) {
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            if (now.getName().equals("[")) {
                node.addChild(new Node(/*"["*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                if (now.getName().equals("]")) {
                    node.addChild(new Node(/*"]"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                } else {
                    //错误处理
                    w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "k"));
                    cnt++;
                    //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "k");
                }
            }
        }
        return node;
    }

    public static Node Block() {
        Node node = new Node("<Block>");
        if (now.getName().equals("{")) {
            node.addChild(new Node(/*"{"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            while (!now.getName().equals("}")) {
                node.addChild(BlockItem());
            }
            node.addChild(new Node(/*"}"*/now.getType() + " " + now.getName()));
            if (i < Lexer.outs.size() - 1) {
                now = Lexer.outs.get(++i);
            }
        }
        return node;
    }

    public static Node BlockItem() {
        Node node = new Node("<BlockItem>");
        if (now.getName().equals("char") || now.getName().equals("int") || now.getName().equals("const")) {
            node.addChild(Decl());
        } else {
            node.addChild(Stmt());
        }
        return node;
    }

    public static Node Stmt() {
        Node node = new Node("<Stmt>");
        //System.out.println("now = " + now.getName() + " " + now.getType());
        if (now.getName().equals("{")) {
            node.addChild(Block());
        } else if (now.getName().equals("if")) {
            node.addChild(new Node(/*"if"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(new Node(/*"("*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(Cond());
            if (now.getName().equals(")")) {
                node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                node.addChild(Stmt());
                if (now.getName().equals("else")) {
                    node.addChild(new Node(/*"else"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    node.addChild(Stmt());
                }
            } else {
                //错误处理
                w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "j"));
                cnt++;
                //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "j");
                node.addChild(Stmt());
                if (now.getName().equals("else")) {
                    node.addChild(new Node(/*"else"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    node.addChild(Stmt());
                }
            }
        } else if (now.getName().equals("for")) {
            node.addChild(new Node(/*"for"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(new Node(/*"("*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            if (now.getName().equals(";")) {
                node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                node.addChild(ForStmt());
                node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            }
            if (now.getName().equals(";")) {
                node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                node.addChild(Cond());
                node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            }
            if (now.getName().equals(")")) {
                node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                node.addChild(ForStmt());
                node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            }
            node.addChild(Stmt());
        } else if (now.getName().equals("break") || now.getName().equals("continue")) {
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            if (now.getName().equals(";")) {
                node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                //错误处理
                w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
                cnt++;
                //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
            }
        } else if (now.getName().equals("return")) {
            node.addChild(new Node(/*"return"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            if (now.getName().equals(";")) {
                node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                /////////////////////////////
                node.addChild(Exp());
                if (now.getName().equals(";")) {
                    node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                } else {
                    //错误处理
                    w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
                    cnt++;
                    //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
                }
            }
        } else if (now.getName().equals("printf")) {
            node.addChild(new Node(/*"printf"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(new Node(/*"("*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            while (now.getName().equals(",")) {
                node.addChild(new Node(/*","*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                node.addChild(Exp());
            }
            if (now.getName().equals(")")) {
                node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                if (now.getName().equals(";")) {
                    node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                } else {
                    //错误处理
                    w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
                    cnt++;
                    //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
                }
            } else {
                //错误处理
                w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "j"));
                cnt++;
                //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "j");
                if (now.getName().equals(";")) {
                    node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                } else {
                    //错误处理
                    w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
                    cnt++;
                    //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
                }
            }
        } else if (now.getName().equals(";")) {
            node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        } else {
            int tmp = i;
            Node tmpnode = new Node("tmp");
            //System.out.println(now.getName());
            tmpnode.addChild(Exp());
            if (Lexer.outs.get(i).getName().equals("=")) {
                //System.out.println(now.getName());
                i = tmp;
                now = Lexer.outs.get(i);
                int error = w.size();
                node.addChild(LVal());
                while (w.size() > error) {
                    w.remove(w.size() - 1);
                    cnt--;
                }
                node.addChild(new Node(/*"="*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                if (now.getName().equals("getint") || now.getName().equals("getchar")) {
                    node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    node.addChild(new Node(/*"("*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    if (now.getName().equals(")")) {
                        node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                        now = Lexer.outs.get(++i);
                        if (now.getName().equals(";")) {
                            node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                            now = Lexer.outs.get(++i);
                        } else {
                            //错误处理
                            w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
                            cnt++;
                            //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
                        }
                    } else {
                        //错误处理
                        w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "j"));
                        cnt++;
                        //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "j");
                        if (now.getName().equals(";")) {
                            node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                            now = Lexer.outs.get(++i);
                        } else {
                            //错误处理
                            w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
                            cnt++;
                            //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
                        }
                    }
                } else {
                    node.addChild(Exp());
                    if (now.getName().equals(";")) {
                        node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                        now = Lexer.outs.get(++i);
                    } else {
                        //错误处理
                        w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
                        cnt++;
                        //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
                    }
                }
            } else {

                i = tmp;
                now = Lexer.outs.get(i);
                int error = w.size();
                node.addChild(Exp());
                while (w.size() > error) {
                    w.remove(w.size() - 1);
                    cnt--;
                }
                if (now.getName().equals(";")) {
                    node.addChild(new Node(/*";"*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                } else {
                    //错误处理
                    w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "i"));
                    cnt++;
                    //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "i");
                }
            }
        }
        return node;
    }

    public static Node ForStmt() {
        Node node = new Node("<ForStmt>");
        node.addChild(LVal());
        if (now.getName().equals("=")) {
            node.addChild(new Node(/*"="*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        }
        node.addChild(Exp());
        return node;
    }

    public static Node Exp() {
        Node node = new Node("<Exp>");
        node.addChild(AddExp());
        return node;
    }

    public static Node Cond() {
        Node node = new Node("<Cond>");
        node.addChild(LOrExp());
        return node;
    }

    public static Node LVal() {
        Node node = new Node("<LVal>");
        node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
        now = Lexer.outs.get(++i);
        if (now.getName().equals("[")) {
            node.addChild(new Node(/*"["*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(Exp());
            if (now.getName().equals("]")) {
                node.addChild(new Node(/*"]"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                //错误处理
                w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "k"));
                cnt++;
            }
        }
        return node;
    }

    public static Node PrimaryExp() {
        Node node = new Node("<PrimaryExp>");
        if (now.getName().equals("(")) {
            node.addChild(new Node(/*"("*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(Exp());
            if (now.getName().equals(")")) {
                node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
            } else {
                //错误处理
                w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "j"));
                cnt++;
            }
        } else if (now.getType().equals("INTCON")) {
            node.addChild(Number());
        } else if (now.getType().equals("CHRCON")) {
            node.addChild(Character());
        } else if (now.getType().equals("IDENFR")) {
            node.addChild(LVal());
        }
        return node;
    }

    public static Node Number() {
        Node node = new Node("<Number>");
        node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
        now = Lexer.outs.get(++i);
        return node;
    }

    public static Node Character() {
        Node node = new Node("<Character>");
        node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
        now = Lexer.outs.get(++i);
        return node;
    }

    public static Node UnaryExp() {
        Node node = new Node("<UnaryExp>");
        if (now.getName().equals("+") || now.getName().equals("-") || now.getName().equals("!")) {
            node.addChild(UnaryOp());
            node.addChild(UnaryExp());
        } else if (now.getType().equals("IDENFR") && Lexer.outs.get(i + 1).getName().equals("(")) {
            if (Lexer.outs.get(i + 1).getName().equals("(")) {
                node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
                now = Lexer.outs.get(++i);
                if (now.getName().equals("(")) {
                    node.addChild(new Node(/*"("*/now.getType() + " " + now.getName()));
                    now = Lexer.outs.get(++i);
                    if (now.getName().equals(")")) {
                        node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                        now = Lexer.outs.get(++i);
                    } else if (now.getName().equals("+") || now.getName().equals("-") || now.getName().equals("!") ||
                            now.getName().equals("(") || now.getType().equals("IDENFR")
                            || now.getType().equals("INTCON") || now.getType().equals("CHRCON")) {
                        node.addChild(FuncRParams());
                        if (now.getName().equals(")")) {
                            node.addChild(new Node(/*")"*/now.getType() + " " + now.getName()));
                            now = Lexer.outs.get(++i);
                        } else {
                            w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "j"));
                            cnt++;
                        }
                    } else {
                        //错误处理
                        w.add(cnt, new WrongExample(Lexer.outs.get(i - 1).getLine_num(), "j"));
                        cnt++;
                        //System.out.println(Lexer.outs.get(i - 1).getLine_num() + " " + "j");
                    }
                }
            }
        } else {
            node.addChild(PrimaryExp());
        }
        return node;
    }

    public static Node UnaryOp() {
        Node node = new Node("<UnaryOp>");
        switch (now.getName()) {
            case "+" -> node.addChild(new Node(/*"+"*/now.getType() + " " + now.getName()));
            case "-" -> node.addChild(new Node(/*"-"*/now.getType() + " " + now.getName()));
            case "!" -> node.addChild(new Node(/*"!"*/now.getType() + " " + now.getName()));
        }
        now = Lexer.outs.get(++i);
        return node;
    }

    public static Node FuncRParams() {
        Node node = new Node("<FuncRParams>");
        node.addChild(Exp());
        while (now.getName().equals(",")) {
            node.addChild(new Node(/*","*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
            node.addChild(Exp());
        }
        return node;
    }

    public static Node MulExp(Node in) {
        Node node = new Node("<MulExp>");
        if (in != null) {
            node.addChild(in);
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        }
        node.addChild(UnaryExp());
        if (now.getName().equals("*") || now.getName().equals("/") || now.getName().equals("%")) {
            return MulExp(node);
        }
        return node;
    }

    public static Node MulExp() {
        return MulExp(null);
    }

    public static Node AddExp(Node in) {
        Node node = new Node("<AddExp>");
        if (in != null) {
            node.addChild(in);
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        }
        node.addChild(MulExp());
        if (now.getName().equals("+") || now.getName().equals("-")) {
            return AddExp(node);
        }
        return node;
    }

    public static Node AddExp() {
        return AddExp(null);
    }

    public static Node RelExp(Node in) {
        Node node = new Node("<RelExp>");
        if (in != null) {
            node.addChild(in);
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        }
        node.addChild(AddExp());
        if (now.getName().equals("<=") || now.getName().equals(">=") || now.getName().equals(">") || now.getName().equals("<")) {
            return RelExp(node);
        }
        return node;
    }

    public static Node RelExp() {
        return RelExp(null);
    }

    public static Node EqExp(Node in) {
        Node node = new Node("<EqExp>");
        if (in != null) {
            node.addChild(in);
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        }
        node.addChild(RelExp());
        if (now.getName().equals("==") || now.getName().equals("!=")) {
            return EqExp(node);
        }
        return node;
    }

    public static Node EqExp() {
        return EqExp(null);
    }

    public static Node LAndExp(Node in) {
        Node node = new Node("<LAndExp>");
        if (in != null) {
            node.addChild(in);
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        }
        node.addChild(EqExp());
        if (now.getType().equals("AND")) {
            return LAndExp(node);
        }
        return node;
    }

    public static Node LAndExp() {
        return LAndExp(null);
    }

    public static Node LOrExp(Node in) {
        Node node = new Node("<LOrExp>");
        if (in != null) {
            node.addChild(in);
            node.addChild(new Node(/*now.getName()*/now.getType() + " " + now.getName()));
            now = Lexer.outs.get(++i);
        }
        node.addChild(LAndExp());
        if (now.getType().equals("OR")) {
            return LOrExp(node);
        }

        return node;
    }

    public static Node LOrExp() {
        return LOrExp(null);
    }

//    public static Node LOrExp() {
//        Node node = new Node("<LOrExp>");
//        /*if(Lexer.outs.get(i+1).getType().equals("OR")) {
//            node.addChild(LOrExp());
//            node.addChild(new Node(now.getName()));
//            now = Lexer.outs.get(++i);
//            node.addChild(LAndExp());
//        } else {
//            node.addChild(LAndExp());
//        }
//        return node;*/
//        node.addChild(LAndExp());
//        while(now.getType().equals("OR")) {
//            node.addChild(new Node(now.getName()));
//            now = Lexer.outs.get(++i);
//            node.addChild(LAndExp());
//        }
//        return node;
//    }

    public static Node ConstExp() {
        Node node = new Node("<ConstExp>");
        node.addChild(AddExp());
        return node;
    }

    public static ArrayList<WrongExample> getW() {
        return w;
    }
}

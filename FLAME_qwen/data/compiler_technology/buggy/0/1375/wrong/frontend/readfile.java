package frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class readfile {
    public InputStream in;
    public ArrayList<String> contents;
    public int now_line_num;
    public int now_column_num;
    public readfile(InputStream ifs) {
        this.in= ifs;
        this.contents= new ArrayList<>();
        this.now_line_num=0;
        this.now_column_num=0;
        readlines();
    }
    // 将文件的内容都读进contents里面去，一行作为一个字符串，每个字符串都不包括换行符，但是文件内部的每行字符是有换行符的
    public void readlines(){
       BufferedReader br = new BufferedReader(new InputStreamReader(this.in));
       String lineNow=null;
       try {
           String linenow=null;
           while(true)
           {
               linenow=br.readLine();
               if(linenow==null)
               {
                   break;
               }
               if(linenow.length()!=0) {
                   this.contents.add(linenow);
               }
           }
       } catch (IOException e) {
           throw new RuntimeException(e);
       }
    }

    //判断是到达了行末尾还是文件末尾，注意，我们的行数从0开始算，而Arraylist的索引也是从0开始算的，但是题目要求从1开始算
    public int if_end() {
        //如果已经到达文件末尾，返回1
        if(this.now_line_num >= this.contents.size())
        {
            return 1;
        }
        //如果到达了行末尾，返回2
        else if (this.now_column_num >= this.contents.get(this.now_line_num).length())
        {
            return 2;
        }
        //什么也没到，返回0
        return 0;
    }

    public String get_now_line()
    {
        if(if_end()==1)
        {
            return "";
        }
        return this.contents.get(this.now_line_num);
    }
    public char get_now_char()
    {
        //如果到了文件末尾，那么返回0，是违法的
        if(if_end()==1)
        {
            return 0;
        }
        //如果没到文件末尾但是到了行末尾，那么返回换行符
        else if(if_end()==2)
        {
            return '\n';
        }
        else
        {
            return get_now_line().charAt(this.now_column_num);
        }
    }
    public String get_now_len_str(int len)
    {
        if(if_end()==1)
        {
            return "";
        }
        else if(this.now_column_num+len >= get_now_line().length())
        {
            return get_now_line().substring(this.now_column_num);
        }
        else
        {
            return get_now_line().substring(this.now_column_num, this.now_column_num+len);
        }
    }
    public void skipspace()
    {
        while(if_end()!=1 && Character.isWhitespace(get_now_char()))
        {
                movehead(1);
        }
    }
    public void movehead(int steps)
    {
        int cnt=steps;
        while(if_end()!=1 && cnt>0)
        {
            int now_line_len=get_now_line().length();
            if(this.now_column_num+cnt >= now_line_len)
            {
                //System.out.println("现在是第"+now_line_num+"行");
                this.now_line_num++;
                cnt -= (now_line_len-this.now_column_num);
                this.now_column_num=0;
            }
            else
            {
                this.now_column_num+=cnt;
                cnt=0;
            }
        }
    }
    public void nextline()
    {
        if(if_end()!=1)
        {
            this.now_line_num++;
            this.now_column_num=0;
        }
    }

    public String getleftline()
    {
        if(if_end()==1 || if_end()==2)
        {
            return "";
        }
        else
        {
            return  get_now_line().substring(this.now_column_num);
        }
    }



}

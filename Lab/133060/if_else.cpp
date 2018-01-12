#include<bits/stdc++.h>
using namespace std;

vector<string>if_state;
vector<string>for_loop;
string buffer,str,tmp,if_string;
int j,k,l;
char ch;


int is_correct(string str)
{

     int sem_num=0,rr_num=0;

    if (!(str[0]=='f'&&str[1]=='o'&&str[2]=='r'))
    return 0;



    if(str[3]=='(')
    {
        for(int i=4;i<str.length();i++)
        {
            if(str[i]==';')
            {
                sem_num++;

            }

            if(str[i]==')')
                rr_num++;
        }
    }

    if(sem_num==2 && rr_num==1)
        return 1;
}


int is_correct_if(string str)
{

  int if_bra=0,else_cnt=0;
  if(str[0]=='i' && str[1]=='f' && str[2]=='(')
  {
      for(int i=3;i<str.length();i++)
      {
          if(str[i]==')')
          if_bra=1;


      if(str[i]=='e')
      {
          if(str[i+1]=='l'&&str[i+2]=='s'&&str[i+3]=='e')
          {
               else_cnt=4;
               break;
          }

      }
      }
  }

  if(if_bra==1 && (else_cnt==0 ||else_cnt==4))
    return 1;
  else
    return 0;

}

int main()
{
    int aaa=0;
    if(aaa>1);
    else;

    ifstream f1;
    f1.open("for_loop.txt");

    while(! f1.eof())
     {
         f1>>buffer;
         for_loop.push_back(buffer);
     }

     for(int i=0;i<for_loop.size();i++)
     cout<<for_loop.at(i)<<"\n";


     buffer.clear();
    ifstream f2;
    f2.open("if_else.txt");

    while(! f2.eof())
     {
         f2>>buffer;
         if_state.push_back(buffer);
     }

     for(int i=0;i<if_state.size();i++)
     cout<<if_state.at(i)<<"\n";
     cout<<"Checking for statement : "<<endl;
     for(int i=0;i<for_loop.size();i++)
     {
         tmp=for_loop.at(i);
         if(is_correct(tmp)==1)
            cout<<" "<<for_loop.at(i)<<" is corect " <<endl;
         else
         cout<<" "<<for_loop.at(i)<<" is not corect " <<endl;

         tmp.clear();

     }

     cout<<"\n\nChecking if statement : "<<endl;

     for(int i=0;i<if_state.size();i++)
     {
         str=if_state.at(i);
       if(is_correct_if(str)==1)
        cout<<" "<<if_state.at(i)<<" is correct "<<endl;
       else
       cout<<" "<<if_state.at(i)<<" is incorrect "<<endl;
        str.clear();

     }





}

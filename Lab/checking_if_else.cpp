#include<bits/stdc++.h>//lab 4
using namespace std;

int correct_if(string str)
{
    int i,s1,s2,s,ss1,ss2,ss3,ss4,len,b1=0,b2=0,bb1=0,bb2=0;
    s1=s2=s=ss1=ss2=ss3=ss4=-2;
    bool iff=false,el=false;

    s1=str.find(" if ");
    s2=str.find(" if(");

    ss1=str.find(" else ");
    ss2=str.find(";else ");
    ss3=str.find(" else{");
    ss4=str.find(";else{");

    if(s1!=-1 && s2==-1){s=s1;}
    if(s2!=-1 && s1==-1){s=s2;}
    len=str.size();

    if(s>=0)
    {
        for(i=s+3;i<len;i++)
        {
            //cout<<str[i]<<b1<<b2<<iff<<el<<"\n";
            if(str[i]=='('){b1++;}
            if(str[i]==')'){b2++;}

            if(str[i]=='{'){bb1++;}
            if(str[i]=='}'){bb2++;}

            if(iff==false && str[i]==';')
            {
                if(b1==b2){iff=true;}
            }
            if(iff==true && (ss1==-1 && ss2==-1 && ss3==-1 && ss4==-1))
            {
                return 1;
            }
            if(iff==true && (ss1>=0 || ss2>=0 || ss3>=0 || ss4>=0))
            {
                if(str[i]==';'){el=true;}
            }
            if(el==true && bb1==bb2)
            {
                return 1;
            }
        }
    }
    return 0;
}
int correct_loop(string str)
{
    int i,len,b1,b2,s1,s2,s,cntc,saveb,savec;
    b1=0,b2=0,cntc=0;s1=0,s2=0,s=-2,saveb=0,savec=0;
    len=str.size();

    s1=str.find(" while ");
    s2=str.find(" while(");

    if(s1!=-1 && s2==-1){s=s1;}
    if(s2!=-1 && s1==-1){s=s2;}

    if(s>=0)
    {
        for(i=s+5;i<len;i++)
        {
            if(str[i]=='('){b1++;}
            if(str[i]==')'){b2++;}
            if(b1==b2 && str[i]==';')
            {
                return 1;
            }
        }
    }

    b1=0,b2=0,cntc=0;s1=0,s2=0,s=-2,saveb=0,savec=0;
    s1=str.find(" for ");
    s2=str.find(" for(");

    if(s1!=-1 && s2==-1){s=s1;}
    if(s2!=-1 && s1==-1){s=s2;}

    if(s>=0)
    {
        for(i=s+3;i<len;i++)
        {
            if(str[i]=='('){b1++;}
            if(str[i]==')'){b2++;saveb=i;}
            if(str[i]==';')
            {
                cntc++;
                if(cntc==2){savec=i;}
            }
            //cout<<str[i]<<b1<<b2<<cntc<<saveb<<savec<<"\n";
            if(b1==b2 && cntc==3 && savec<saveb)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int i=0,s;
    vector<string>if_condition,loop;
    string line,str;
    ifstream f1,f2;

    f1.open("if_else.txt");
    cout<<"sample if_else c code: \n\n";

    while(!f1.eof())
    {
        getline(f1,line);
        if_condition.push_back(line);
        cout<<if_condition[i++]<<"\n";
    }

    s=if_condition.size();
    cout<<"\n\nChecking if else statement : "<<"\n\n";

    for(i=0;i<s;i++)
    {
        str=if_condition[i];
        str=" "+str;
        if(correct_if(str)==1)
        {
            cout<<if_condition[i]<<" --correct--\n";
        }
        else
        {
            cout<<if_condition[i]<<" --not correct--\n";
        }
    }

    i=0;
    f2.open("for_while.txt");
    cout<<"\n\nsample for_while c code: \n\n";

    while(!f2.eof())
    {
        getline(f2,line);
        loop.push_back(line);
        cout<<loop[i++]<<"\n";
    }

    s=loop.size();
    cout<<"\n\nChecking for while statement : "<<"\n\n";

    for(i=0;i<s;i++)
    {
        str=loop[i];
        str=" "+str;
        if(correct_loop(str)==1)
        {
            cout<<loop[i]<<" --correct--\n";
        }
        else
        {
            cout<<loop[i]<<" --not correct--\n";
        }
    }
    return 0;
}

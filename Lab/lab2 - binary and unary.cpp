#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len,i,j,k,l,m,n,o,a,b,c,cntd=0,ascii[10001],ascii2[10001];a=b=c=o=-1;
    string word[10001],variables[101],str=" ";
    string op1[29]={"+","-","*","/","%","^","|","||","&","&&",
    "+=","-=","*=","/=","%=","^=","|=","&&","!=",",", "<","<=","<<","<<=",">",">=",">>",">>=","="};
    string op2[3]={"--","++","~"};
    vector<string>eqn,bin,un,no;
    bool fnd;
    ifstream ifs("mycode.txt");
    string content( (istreambuf_iterator<char>(ifs) ),
                    (istreambuf_iterator<char>() )
                   );
    cout<<content<<endl;
    str+=content;len=str.length();str+="@";
    ascii[0]=32;ascii2[0]=32;

    for(i=1,j=0,k=0,m=0;i<len;i++)
    {
        ascii[i]=(int)str[i];ascii2[i]=ascii[i];
        //separating word
        if(str[i]=='#' || str[i]=='<' || str[i]=='>' || str[i]==',' || str[i]==';' || str[i]=='(' || str[i]==')'
         || str[i]=='{' || str[i]=='}' || str[i]=='[' || str[i]==']' || str[i]=='"' || str[i]=='\'')
            {
                ascii2[i]=32;
                if(str[i]=='"'){cntd++;}
            }
        //finding word
        if(ascii2[i]!=10 && ascii2[i]!=32 && ascii2[i]!=9)
        {
            if(ascii2[i-1]==10 || ascii2[i-1]==32 || ascii2[i-1]==9){j++;}
            string s(1,str[i]);word[j]+=s;
        }
    }

    cout<<"#Printing equations: \n\n";
    for(i=1,l=-1;i<=j;i++)
    {
        int siz=word[i].size();
        for(k=0;k<siz;k++)
        {
            if(word[i][k]=='+' || word[i][k]=='-' || word[i][k]=='*' ||word[i][k]=='/' ||word[i][k]=='=' ||
            word[i][k]=='%' ||word[i][k]=='^' ||word[i][k]=='|' || word[i][k]=='&' || word[i][k]=='!' ||
            word[i][k]=='<' || word[i][k]=='>' || word[i][k]=='~' )
            {
                if(word[i]!="%d"){
                eqn.push_back(word[i]);
                l++;}
            }
        }
        fnd=false;
        if(l>=0 && n!=l)
        {
        n=l;
        for(m=0;m<3;m++)
        {
            if(eqn[l].find(op2[m]) != string::npos)
            {
                cout<<"unary "<<eqn[l]<<endl;
                un.push_back(eqn[l]);
                fnd=true;
                break;
            }
        }
        if(!fnd)
        {
            cout<<"binary "<<eqn[l]<<endl;
            bin.push_back(eqn[l]);
        }
        }
    }
    printf("\n");

    cout<<"\nvalid binary : \n\n";
    for(i=0;i<bin.size();i++)
    {
        int siz=bin[i].size();
        a=b=c=o=-1;
        for(k=0;k<siz;k++)
        {
            if(a==-1 && b==-1 && ( isalpha(bin[i][k]) || isdigit(bin[i][k]) ) ) {a=k;continue;}
            if(b==-1 && (bin[i][k]=='+' || bin[i][k]=='-' || bin[i][k]=='*' ||bin[i][k]=='/' ||bin[i][k]=='=' ||
            bin[i][k]=='%' ||bin[i][k]=='^' ||bin[i][k]=='|' || bin[i][k]=='&' || bin[i][k]=='!' || bin[i][k]=='<'
            || bin[i][k]=='>' || bin[i][k]=='~' ) ) {b=k;continue;}
            if(c==-1 && ( isalpha(bin[i][k]) || isdigit(bin[i][k]) ) ){c=k;break;}
        }
        if(a!=-1 && a<b && b<c){cout<<bin[i]<<endl;}
        else{no.push_back(bin[i]);}
    }

    cout<<"\nvalid unary : \n\n";
    for(i=0;i<un.size();i++)
    {
        int siz=un[i].size();
        a=b=c=o=-1;
        for(k=0;k<siz;k++)
        {
            if(a==-1 && b==-1 && ( isalpha(un[i][k]) || isdigit(un[i][k]) ) ) {a=k;continue;}
            if(b==-1 && ( un[i][k]=='+' || un[i][k]=='-' || un[i][k]=='~' ) ){b=k;continue;}
            if(c==-1 && ( isalpha(un[i][k]) || isdigit(un[i][k]) ) ){c=k;break;}
        }
        if(a==-1 && b<c){cout<<un[i]<<endl;}
        else{no.push_back(un[i]);}
    }
    cout<<"\nnot accurate : \n\n";
    for(i=0;i<no.size();i++)
    {
        cout<<no[i]<<endl;
    }
    return 0;
}

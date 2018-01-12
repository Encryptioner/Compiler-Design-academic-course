#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len,i,j,k,l,m,n,o,number,cntd=0,ascii[10001],ascii2[10001];
    string word[10001],comment[101],identifiers[101],operators[101],library[101],keywords[101],constants[101],str=" ",nocmnt,nocmnt2;
    string op1[28]={"+","-","*","/","%","^","|","||","&","&&", "+=","-=","*=","/=","%=","^=","|=","&&","!=",",", "<","<=","<<","<<=",">",">=",">>",">>="};
    string op2[4]={"--","++","!","~"};
    vector<string>eqn,bin,un,no;

    ifstream ifs("mycode.txt");

    string content( (istreambuf_iterator<char>(ifs) ),
                    (istreambuf_iterator<char>() )
                   );
    str+=content;len=str.length();
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


    cout<<"\n#Printing equations: \n\n";
    for(i=1;i<=j;i++)
    {
        int siz=word[i].size();
        for(k=0;k<siz;k++)
        {
            if(word[i][k]=='+' || word[i][k]=='-' || word[i][k]=='*' ||word[i][k]=='/' ||word[i][k]=='=' ||word[i][k]=='%' ||word[i][k]=='^' ||
             word[i][k]=='|' || word[i][k]=='&' || word[i][k]=='!' || word[i][k]=='<' || word[i][k]=='>' || word[i][k]=='~' )
            {
                eqn.push_back(word[i]);
                break;
            }
        }
    }
    printf("\n");


    //finding
    int siz=eqn.size();
    for(i=0;i<siz;i++)
    {
        int siz2=eqn[i].size();
        cout<<eqn[i]<<" "<<siz2<<endl;
        for(k=0;k<siz2;k++)
        {
            if(eqn[i][k]=='+' || eqn[i][k]=='-' || eqn[i][k]=='*' ||eqn[i][k]=='/' ||eqn[i][k]=='=' ||eqn[i][k]=='%' ||eqn[i][k]=='^' )
            {
                if(k!=siz-1 && k!=0)//binary possible
                {
                    //cout<<"p "<<k<<
                    if(k+1!=siz-1 || k-1!=0){
                    if( (isdigit(eqn[i][k-1]) || isalpha(eqn[i][k-1])) && (isdigit(eqn[i][k+1]) || isalpha(eqn[i][k+1])) )
                    {
                        bin.push_back(eqn[i]);
                    }}
                    if(k+1==siz-1)
                    {
                        cout<<eqn[i]<<endl;
                        if(isalpha(eqn[i][k-1]) && eqn[i][k]=='+' && eqn[i][k+1]=='+'){un.push_back(eqn[i]);}
                        else if(isalpha(eqn[i][k-1]) && eqn[i][k]=='-' && eqn[i][k+1]=='-'){un.push_back(eqn[i]);}
                        else{no.push_back(eqn[i]);}
                    }

                }
                else
                {

                }
            }
        }

    }
    cout<<"\nvalid binary : \n";
    for(i=0;i<bin.size();i++)
    {
        cout<<"b "<<bin[i]<<endl;
    }
    cout<<"\nvalid unary : \n";
    for(i=0;i<un.size();i++)
    {
        cout<<"u "<<un[i]<<endl;
    }
    cout<<"\nnot accurate : \n";
    for(i=0;i<no.size();i++)
    {
        cout<<"n "<<no[i]<<endl;
    }

    return 0;
}

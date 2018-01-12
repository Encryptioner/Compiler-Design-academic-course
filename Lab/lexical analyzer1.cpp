#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len,i,j,k,l,m,number;
    int ascii[10001],ascii2[10001],constants[1001];
    string word[10001],comment[1001],variables[1001],operators[1001],str=" ";
    bool cmnt=false;

    ifstream ifs("mycode.txt");
    string content( (istreambuf_iterator<char>(ifs) ),
                    (istreambuf_iterator<char>() )
                   );
    cout<<content<<"\n";
    str+=content;
    len=str.length();
    ascii[0]=32;
    ascii2[0]=32;

    for(i=1,j=0;i<len;i++)
    {
        ascii[i]=(int)str[i];
        //cout<<str[i]<<" "<<ascii[i]<<"\n";
    }
    //Let's Find
    i=0,j=0,k=0,m=0,l=0,number=0;
    for(i=1;i<len;i++)
    {
        if(isdigit(str[i]))
        {
            while(isdigit(str[i]))
            {
                number=10*number+ascii[i]-'0';
                i++;
            }
            j++;
            constants[j]=number;
            number=0;
        }
        if(isalpha(str[i]))
        {
            m++;
            while(isalpha(str[i]) || isdigit(str[i] || str[i]=='_'))
            {
                string s(1,str[i]);
                variables[m]+=s;
                i++;
            }
        }
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='=' || str[i]=='^')
        {
            l++;
            operators[l]=str[i];
        }
    }
    cout<<"\n\nPrinting constants: \n\n";
    for(i=1;i<=j;i++)
    {
        cout<<constants[i]<<" ";
    }
    cout<<"\n\nPrinting variables: \n\n";
    for(i=1;i<=m;i++)
    {
        cout<<variables[i]<<" ";
    }
    cout<<"\n\nPrinting operators: \n\n";
    for(i=1;i<=l;i++)
    {
        cout<<operators[i]<<" ";
    }
    return 0;
}

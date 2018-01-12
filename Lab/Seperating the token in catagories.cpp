#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len,i,j,k,l,m,n,o,number,cntd=0,ascii[10001],ascii2[10001];
    string word[10001],comment[101],identifiers[101],operators[101],library[101],keywords[101],constants[101],str=" ",nocmnt,nocmnt2;
    string key[32]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    bool cmnt=false,def=false;

    ifstream ifs("mycode2.txt");
    string content( (istreambuf_iterator<char>(ifs) ),
                    (istreambuf_iterator<char>() )
                   );
    str+=content;len=str.length();
    ascii[0]=32;ascii2[0]=32;

    for(i=1,j=0,k=0,m=0;i<len;i++)
    {
        ascii[i]=(int)str[i];ascii2[i]=ascii[i];
        // finding comment
        if(cmnt==true && str[i]!=10)
        {
            string s(1,str[i]);comment[k]+=s;
            continue;
        }
        else{cmnt=false;}
        if(str[i]=='/' && str[i-1]=='/')
        {
            cmnt=true;
            k++;word[j]="";j--;m--;
            nocmnt=nocmnt2;
            continue;
        }
        string s(1,str[i]);nocmnt+=s;
        if(s!="/"){nocmnt2=nocmnt;}
        //separating word
        if(str[i]=='#' || str[i]=='<' || str[i]=='>' || str[i]==',' || str[i]==';' || str[i]=='(' || str[i]==')'
         || str[i]=='{' || str[i]=='}' || str[i]=='[' || str[i]==']' || str[i]=='"' || str[i]=='\'')
            {
                ascii2[i]=32;
                if(str[i]=='"'){cntd++;}
            }
        // finding operator
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^' || str[i]=='=')
        {
            operators[++m]=str[i];
            ascii2[i]=32;
        }
        if(cntd%2==0 && str[i]=='%'){operators[m++]=str[i];ascii2[i]=32;}
        //finding word
        if(ascii2[i]!=10 && ascii2[i]!=32 && ascii2[i]!=9)
        {
            if(ascii2[i-1]==10 || ascii2[i-1]==32 || ascii2[i-1]==9){j++;}
            string s(1,str[i]);word[j]+=s;
        }
    }
    cout<<"#Printing code after comment elimination: \n\n";
    cout<<nocmnt<<endl;

    cout<<"\n#Printing comments: \n\n";
    for(i=1;i<=k;i++){cout<<comment[i]<<"\n";}
    cout<<"\n#Printing identifiers: \n\n";
    for(i=1,l=0,n=0,o=0;i<=j;i++)
    {
        int siz=word[i].size();
        if(word[i][siz-1]=='h' && word[i][siz-2]=='.')
        {library[++l]=word[i];def=true;}

        else if(isdigit(word[i][0]) && isdigit(word[i][siz-1]))
        {constants[++o]=word[i];def=true;}

        for(k=0;k<32;k++){
            if(word[i]==key[k]){keywords[++n]=word[i];def=true;break;}}
        if(!def && word[i][0]!='%')
        {
             cout<<word[i]<<" ";
        }
        def=false;
    }
    printf("\n");

    cout<<"\n#Printing operators: \n\n";
    for(i=1;i<=m;i++){cout<<operators[i]<<" ";}printf("\n");
    cout<<"\n#Printing keywords: \n\n";
    for(i=1;i<=n;i++){cout<<keywords[i]<<" ";}printf("\n");
    cout<<"\n#Printing constants: \n\n";
    for(i=1;i<=o;i++){cout<<constants[i]<<" ";}printf("\n");

    return 0;
}

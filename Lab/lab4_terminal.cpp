#include<bits/stdc++.h>

using namespace std;

int main()
{
   string str;
   vector<char>ter,n_ter,tmp;
   int i=0;

   while(1){
   cout<<"Enter Input: ";
   cin>>str;
   if(str=="0"){break;}
   i=str.find(">");
   n_ter.push_back(str[i-2]);
   for(i=i+1;i<str.size();i++)
   {
      if(str[i]>='a' && str[i]<='z')
      {
         ter.push_back(str[i]);
      }
      else if(str[i]=='\'')
	  {
	  	n_ter.pop_back();
	  	tmp.push_back(str[i-1]);
	  }
      else
      {
         n_ter.push_back(str[i]);
      }
   }
   cout<<"\nTerminal Symbol: \n\n";
   for(i=0;i<ter.size();i++)
   {
		cout<<ter[i]<<" ";
   }
   printf("\n");
   cout<<"\nNon-Terminal Symbol: \n\n";
   for(i=0;i<n_ter.size();i++)
   {
		cout<<n_ter[i]<<" ";
   }
   for(i=0;i<tmp.size();i++)
   {
		cout<<tmp[i]<<"\' ";
   }
   ter.clear();n_ter.clear();tmp.clear();
   printf("\n\n");
   }
   printf("\n");
   return 0;
}

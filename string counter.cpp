#include<iostream>
#include<string>

using namespace std;

int main()
{
    string st;
    int capital[26];
    int small[26];
    
    for(int i=0;i<26;i++)
    {
            capital[i]=0;
            small[i]=0;
            }
    
    getline(cin,st);
    cout<<st<<endl;
    
    
    for(int i=0;i<st.length();i++)
    {
     if(st[i]<65 || st[i]>90)//capital letters
     {
                 if(st[i]<97 || st[i]>122)//small letters
                 {
                  if(st[i]!=32)//space        
                  {
                                              cout<<"Error: Your Entered String Consists of Numbers and Special Characters"<<endl;    
                                              cout<<"<Program will Terminate>"<<endl;
                                              system("pause");
                                              return 0;
                                              }
                            }
                }
    }
    
    
    for(int i=0;i<st.length();i++)
    {
            if(st[i]>64 || st[i]<91)//capital letters
            capital[st[i]-65]=capital[st[i]-65]+1;
            }
    
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
    for(int i=0;i<26;i++)
    cout<<capital[i]<<" ";
    cout<<endl;
    
    for(int i=0;i<st.length();i++)
    {
            if(st[i]>96 || st[i]<123)//small letters
            small[st[i]-97]=small[st[i]-97]+1;
            }
    
    cout<<"a b c d e f g h i j k l m n o p q r s t u v w x y z"<<endl;
    for(int i=0;i<26;i++)
    cout<<small[i]<<" ";
    cout<<endl;
    
    system("pause");
    return 0;
    
    }

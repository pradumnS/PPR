#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class String
{
 
public:
    String();
    ~String();
    String(const char *str);
    String(const String &s);
    String& operator = (const String &s);
    String( String &&s);
    String& operator = (String &&s);
    int size();
    void insert(int,const char* str);
    String& operator + (const char *str);
    void Strcpy(char* des, const char *src);
    void Strcat(char* des, const char *src);
    int len(const char *ptr);
private:
    int sz=0,length; char *buffer;
    
};
int String::len(const char *ptr)
{
    length=0;
    while(*ptr++ != '\0')
        length++;
    return length;
}
String::String()
{
    
}
String::~String()
{
    
}
String::String(const char *str)
{
    int i=0;
    while(str[i++] != '\0')
        sz++;
    buffer = new char[sz];
    for(i=0; i<sz; i++)
        buffer[i] = *str++;
    buffer[i]='\0';
}
void String::Strcpy(char* des, const char *src)
{
    des = new char[len(src)]; int i=0;
    while(*src != '\0')
        des[i++] = *src++;
    des[i] = '\0';
    
    std::cout << des << std::endl;
    
}
void String::Strcat(char* des, const char *src)
{
    int pos = len(des);
    char *p = new char[pos]; int i=0,n=len(src);
    
    for(i=0; i<pos; i++){
        p[i] = *des++;}
    p[i] = '\0';
    
    des = new char[pos+len(src)];
    
    for(i=0; i<pos; i++){
        des[i] = *p++;}
        
        
    for(i=pos; i<n+pos; i++){
        des[i] = *src++;}

    des[i] = '\0';

    std::cout << des << std::endl;
}
void String::insert(int pos,const char* str)
{
    char *p = new char[sz]; int i=0; int n = strlen(str);
    for(i=0; i<sz; i++){
        p[i] = *buffer++;}
    p[i] = '\0';
    
    buffer = new char[sz+n+1];
    
    for(i=0; i<pos; i++){
        buffer[i] = *p++;}
        
        
    for(i=pos; i<n+pos; i++){
        buffer[i] = *str++;}
        
    for(i=pos+n; i<n+sz; i++){
        buffer[i] = *p++;}
    buffer[i] = '\0';
    
    sz=sz+n;
    std::cout << buffer << std::endl;
}
int String::size()
{
    return sz;
}
String::String(const String& s)
{
    
}
String &String::operator = (const String &s)
{
    
}
String::String(String&&s)
{
    
}
String &String::operator = (String&&s)
{
    
}
int main()
{
   char st[] = "I am ram";
   char des[] = ""; char des1[] = "new";
   String s(st);
   s.insert(4," shri ");
   s.Strcpy(des,"source");
   s.Strcat(des1," old ");
   std::cout << s.size() << std::endl;
   return 0;
}

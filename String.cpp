#include "String.h"
#include<stdio.h>
String::String() :String(10)
{

}
String::String(String& s) : String(s.length + 1) //복사생성자
{
    for (int i = 0; i < s.length; i++)
        buffer[i] = s.buffer[i];
    buffer[s.length] = '\0';
    length = s.length;
    //복사생성자 안에서 메모리 할당을 해줘야 문제가 발생하지 않는다. 
//printf("-A--(%p)---\n", this); //현재 객체의 주소를 출력
}
String::~String()
{
    //printf("-B--(%p)---\n", this);
    delete[] buffer;
}
String::String(int m)
{
    size = m;
    buffer = new char[m];
    length = 0;
    //printf("-C--(%p)---\n", this);
}
String::String(char* init, int m) :String(m + 1)
{
    String(m + 1);// 널문자 넣는 것까지 생각해서 +1
    for (int i = 0; i < m; i++)
        buffer[i] = init[i];
    buffer[m] = '\0';
    length = m;
}
String String::Concat(String t)
{
    String result(length + t.length + 1);

    for (int i = 0; i < length; i++)
        result.buffer[i] = buffer[i];
    for (int i = 0; i < t.length; i++)
        result.buffer[length + i] = t.buffer[i];

    result.buffer[length + t.length] = '\0';
    result.length = length + t.length;

    return result;
}
String& String::operator=(const String& s)
{
    delete[] buffer;
    buffer = new char[s.length + 1];
    for (int i = 0; i < s.length; i++)
        buffer[i] = s.buffer[i];
    buffer[s.length] = '\0';
    length = s.length;

    return *this;
}
bool String::operator==(String t)//동일한지 비교
{
    int eqcount = 0;
    if ((length == t.length) || (size == t.size))
    {
        for (int i = 0; i < length; i++) {
            if (buffer[i] == t.buffer[i]) {
                eqcount++;
            }
        }
        if (eqcount == length)
            return true;
        else
            return false;
    }
    else {
        return false;
        //0이면 false 0이 아니면 true
    }
}
bool String:: operator!()//공백이면 true 아니면 false
{
    if ((length == 0) || (buffer[0] == '\0'))//length==0 또는 size==1로 코드 작성
        return true;
    else
        return false;
}
int String::Length()//문자수를 반환
{
    return length;
}

String String::Substr(int i, int j)
{
    String answer(j - i + 1);
    for (int a = 0; a < j - i; a++)
    {
        answer.buffer[a] = buffer[a + i];
    }
    buffer[j - i] = '\0';
    answer.size = j - i + 1;
    answer.length = j - i - 1;
    return answer;
}
int String::Find(String pat)
{
    int i,j;
    int answer = -1;
    if (pat.length == 0)
        answer= -1;
    for (i = 0; i <= length - pat.length; i++) {
        for (j = 0; j < pat.length; j++) {
            if (buffer[i + j] == pat.buffer[j]) {
                answer = i;
                continue;
            }
            if (buffer[i + j] != pat.buffer[j]) {
            answer = -1;
            break;
        }
        }
        if (j == pat.length)
            answer= i;
    }
    return answer;
}
void String::print()//스트링을 출력
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", buffer[i]);
    }
    printf(" ");
}

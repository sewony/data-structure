#pragma once
class String
{
private:
	char* buffer;
	int length;
	int size;

	String(int m);
public:
	String();
	String(String&);
	String(char* init, int m);
	~String();
	String Concat(String t);
	String& operator=(const String&); //기존에 있던 버퍼를 삭제하고 파라미터로 넘어온 String의 사이즈만큼 재할당하여 복사
	bool operator==(String t);//동일한지 비교
	bool operator!();//공백이면 true 아니면 false
	int Length();//문자수를 반환
	String Substr(int i, int j);//i~j 사이의 스트링을 반환
	int Find(String pat);
	void print();//스트링을 출력
};

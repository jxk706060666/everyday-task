//https://www.nowcoder.com/pat/6/problem/4059
#include<bits/stdc++.h>
using namespace std;

string s1,s2;
map<char,int> mm;

int main()
{
	cin>>s1;
	cin>>s2;
	int len1=s1.length();
	int len2=s2.length();  //函数1 string.length() 获取字符串的长度 
	for(int i=0;i<len1;i++)
	{
		if(s1[i]=='+'&&(!mm.count('A')))  //函数2 map.count(x) 获取map中有无该关键字 
		{
			for(int j=0;j<26;j++) mm[(char) ('A'+j)]=1;
		}
		else
		{
			if(isupper(s1[i])) mm[(char)s1[i]]=mm[(char)(s1[i]-'A'+'a')]=1;  //函数3 isupper(char) 检查该字符是否是大写 同理的还有 islower(char) 检查是否小写 isdigit(char) 检查是否为数字 
			else mm[s1[i]]=1;
		}
	}
	map<char,int>::iterator it; //建立map的迭代器it 以便遍历map 
	for(it=mm.begin();it!=mm.end();it++) s2.erase(remove(s2.begin(),s2.end(),it->first),s2.end()); //函数remove(begin,end,c) 将字符串中值为 c 的 字符全部扔到末尾并返回更新后的尾指针，函数erase(begin,end)将末尾这些c全部删掉 
	cout<<s2<<endl;
} 

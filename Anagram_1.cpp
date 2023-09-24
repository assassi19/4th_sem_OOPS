#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string a = "LISTEN";
    string b = "SILEBT";
  int len = a.length();
  int val_a = 0, val_b=0;
  for(int i=0; i<len; i++){
    	val_a += int(a[i]);
  }
  for(int i=0; i<len; i++){
    	val_b += int(b[i]);
  }
  if(val_a = val_b){
  cout<<"string a & b are anagrams";}
  else{ cout<<"string a & b are NOT anagrams";}
  return 0;
}
#include <iostream>
using namespace std;

int main(){
    string N;
    int B;
    cin >> N >> B;
    
    int len = N.length();
    int result = 0;
    int tmp = 1;
	
	for(int i = len-1; i >= 0; i--){
		int num;
		
		if(N[i] >= '0' && N[i] <= '9'){
			num = N[i] - '0';
		}else{
			num = N[i] - 'A' + 10;
		}
		
		num *= tmp;
		result += num;
		tmp *= B;		
	}
    cout << result;
	return 0;
}
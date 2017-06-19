#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


#define BOOL bool

const size_t MAX_NAME_LEN = 60;
enum ErrorStatus {
  E_ToShortName, E_ToShortPass, E_BigName, E_OK
};

void PrintNormalizedName(const char *raw_name)
{
  char name[MAX_NAME_LEN + 1];
  strcpy(name, raw_name);

  for (size_t i = 0; name[i] != '\0'; ++i)
    name[i] = tolower(name[i]);
  name[0] = toupper(name[0]);

  printf(name);
}

ErrorStatus IsCorrectPassword(char* argv2,char* argv,
  const char *universalPassword,
  BOOL &retIsOkPass)
{
lable1:
  string name, password=string(argv2);
  name = string(argv);
  //printf("Name: "); cin >> name;
  //printf("Password: "); cin >> password;
  if (name.length() < 1) return E_ToShortName;
  if (name.length() > MAX_NAME_LEN) return E_BigName;
  if (password.length() < 1) return E_ToShortPass;

  retIsOkPass = 
    universalPassword != NULL &&
    strcmp(password.c_str(), universalPassword) == 0;
  if (!retIsOkPass)
    retIsOkPass = name[0] == password[0];
lable2:
  printf("Hello, ");
  PrintNormalizedName(name.c_str());
  void *one=&&lable1;
  void *two=&&lable2;
  two-=(int&)one;
  // int two=&&lable2;
  cout << endl;
  cout << "float() "<< sizeof(float) <<" "<<(int&)two << " " << (&&lable2)<<endl;

  char *mqq=(char *)0x401784;
  	 cout << mqq << "++++++++++++++++++"<<endl;
  	 // cout << "             " <<(int*) mqq  << endl;
  	 

  for(int i=0x450; i < (int&)two+0x410; i++){
	char *u=(char *)(one+i);
	//cout << std::hex <<(((char)*u)&0xFF) << " ";
	// cout << std::hex <<(((char)*u)&0xFF) << " ";
	cout << (((char)*u)) ;
	if((i%20)==0){
		cout << "             " <<(int*) u  << endl;
	}
  }

  return E_OK;
}


int main(int argc, char* argv[]){

	// _set_printf_count_output(1);
	bool isOkPassword=false;
	ErrorStatus status = IsCorrectPassword(argv[1],argv[2],"secretpassword",isOkPassword);


	if (status == E_OK && isOkPassword)
		printf("\nPassword: OK\n");
	else
		printf("\nPassword: ERROR\n");

	//char hello[5];

	// strcpy( hello, argv[2] );

	// cout << "Введите число: ";
	// cin >> hello;
	// cout << hello <<endl;
 	return 0;
}



// михаил Фирстов
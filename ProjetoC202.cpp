#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct estados{
	char sigla[2];
	double km;	
};

void LerArquivo(struct estados uf[]){
	int i = 0;
	ifstream arq;
	//Abrindo o arquvio para leitura 
	arq.open("estados.txt", ifstream::in);
	for (i = 0; i < 26; i++){
		arq >> uf[i].sigla;
		arq >> uf[i].km; 		
	}
	//Fechando o arquivo 
	arq.close();
}



int main (){
	struct estados uf[26];
	int i = 0;
	
	
	LerArquivo(uf);
	for (i = 0; i < 26; i++){
		cout << uf[i].sigla << endl;
		cout << uf[i].km << endl; 		
	}
	
	
	
	return 0;	
}
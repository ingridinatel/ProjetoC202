#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct estados{
	char sigla[2];
	float km;
	char nomeEstado[50];
	char capital[100];
	float valorFixo;	
};

void LerArquivo(struct estados uf[]){
	int i = 0;
	ifstream arq;
	//Abrindo o arquvio para leitura 
	arq.open("estados.txt", ifstream::in);
	for (i = 0; i < 26; i++){
		//Armazenando a sigla
		arq >> uf[i].sigla;
		//Armazenando o km
		arq >> uf[i].km; 
		//Armazenando o nome
		arq >> uf[i].nomeEstado;
		//Armazenando o capital
		arq >> uf[i].capital;
		//Armazenando o valor fixo
		arq >> uf[i].valorFixo;		
	}
	//Fechando o arquivo 
	arq.close();
}



int main (){
	struct estados uf[26];
	
	LerArquivo(uf);
	
	
	
	return 0;	
}
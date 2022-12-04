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

 float calctemp(float distancia){
	 float tempo;
   
	 tempo = (distancia)/80.88;
	 
	 return tempo;
 }
 
int localizaposicao (char capital[26], estados uf[26]){
	int posicao;
  
	for (int i = 0; i < 3; i ++){
		if (strcmp(capital, uf[i].capital)==0	){
      posicao = i;	
		}
	}

	return posicao;
} 

float calcub(float A, float L, float C){

	float FC = 300;	
	float cubagem;
	
	cubagem = A * L * C *FC;

	return cubagem;
}

float VCG(float KM){
  float Result_VCG;
  
  Result_VCG = KM * 0.1;
  
  return Result_VCG;
}

float logica_custo(float resultado, float KM){

	float valor_fixo = 5;
	float frete;

	frete = (resultado * valor_fixo) + (resultado * VCG(KM));

	return frete;
}

int main(){
	float altura;
	float largura;
	float comprimento;
	float resultado_cubagem;
	float resultado_frete;
	float distancia;
  struct estados uf[26];
	int posicao;
	char capital[50];
	cin.getline(capital,50);
	float horas;
  LerArquivo(uf);
	
	cin >> altura >> largura >> comprimento;
	cin >> distancia;
  
  posicao = localizaposicao(capital, uf);
	horas = calctemp(uf[posicao].km);

	resultado_cubagem = calcub(altura, largura, comprimento);
	resultado_frete = logica_custo(resultado_cubagem, uf[posicao].km);

	cout << "Cugabem: "<< resultado << endl;
	cout <<"Frete: "<< resultado_frete << endl;	
	
	cout << posicao << endl;
	cout << horas;
	return 0;	
}

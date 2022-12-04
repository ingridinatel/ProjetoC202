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
	for (i = 0; i < 27; i++){
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

 void calctemp(float distancia){
	 float tempo;
   
	 tempo = (distancia)/80.88;
	 
	 cout << "Tempo de entrega: " << horas << "h" << endl;
 }
 
int localizaposicao (char capital[100], struct estados uf[]){
	int posicao;
  	int i;
	for (i = 0; i < 27; i ++){
		if (strcmp(capital, uf[i].capital) == 0){
			posicao = i;	
		}
	}
	cout << "Test: " << posicao << endl;
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
    struct estados uf[26];
	float altura;
	float largura;
	float comprimento;
	float resultado_cubagem;
	float resultado_frete;
	int posicao;
	char capital[100];
	float horas;	
	
    LerArquivo(uf);
	
	cout << "Digite a capital de destino: " ;
	cin.getline(capital,100);
	
	cout << "Digite a altura: ";
	cin >> altura; 
	cout << "Digite a largura: ";
	cin >> largura;
	cout << "Digite o comprimento: ";
	cin >> comprimento;
	
    posicao = localizaposicao(capital, uf);
    
	
	resultado_cubagem = calcub(altura, largura, comprimento);
	resultado_frete = logica_custo(resultado_cubagem, uf[posicao].km);
	
	cout << fixed << setprecision(2);
	cout << "Sua compra foi concluida, veja abaixo as informacoes do seu pedido: " << endl;
	cout << "Destino da entrega: " << uf[posicao].capital << " - " << uf[posicao].sigla << endl;
	calctemp(uf[posicao].km);
	cout << "Valor do frete: " << resultado_frete << endl;
	cout << "Agradecemos a preferencia" << endl;
	
	return 0;	
}

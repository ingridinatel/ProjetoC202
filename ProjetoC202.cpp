#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


 float calctemp(float distancia)
 {
	 float tempo; 
	 tempo = (distancia)/80.88;
	 
	 return tempo;
 }
 
int localizaposicao (char capital[26], estados uf[26])
{
	int posicao;
	for (int i = 0; i < 3; i ++)
	{
		if (strcmp(capital, uf[i].capital)==0	)
		{
		posicao = i;	
		}
	}

	return posicao;
} 
 





int main (){

	int posicao;
	char capital[50];
	cin.getline(capital,50);
	float horas;
	  
	posicao = localizaposicao(capital, uf);
	horas = calctemp(uf[posicao].km);
	
	cout << posicao << endl;
	cout << horas;
	return 0;	
}

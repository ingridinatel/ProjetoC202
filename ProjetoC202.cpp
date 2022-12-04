#include <iostream>

using namespace std;

float calcub(float A, float L, float C)
{

	float FC = 300;
	
	float cubagem;
	
	cubagem = A * L * C *FC;

	return cubagem;
}

float logica_custo(float resultado, float KM)
{

	float valor_fixo = 5;
	float VCG;
	float frete;
	
	VCG = KM * 0.1;

	frete = (resultado * valor_fixo) + (resultado * VCG);

	return frete;
}

int main()
{

	float altura;
	float largura;
	float comprimento;
	float resultado;
	float resultado_frete;
	float distancia;
	
	cin >> altura >> largura >> comprimento;
	cin >> distancia;

	resultado = calcub(altura, largura, comprimento);
	resultado_frete = logica_custo(resultado, distancia);

	cout << "Cugabem: "<< resultado << endl;
	cout <<"Frete: "<< resultado_frete << endl;

	return 0;
}





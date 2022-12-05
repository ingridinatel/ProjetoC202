#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

struct estados
{
	char sigla[2];
	float km;
	char nomeEstado[50];
	char capital[100];
	float valorFixo;
};

void LerArquivo(struct estados uf[])
{
	int i = 0;
	ifstream arq;
	//Abrindo o arquvio para leitura
	arq.open("estados.txt", ifstream::in);
	for (i = 0; i < 27; i++)
	{
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

void calctemp(float distancia, int dias)
{
	int tempo;
	float horas;
	int dias_aux;
	tempo = (distancia) / 80.88;

	dias_aux = dias + (int)tempo / 8;
	horas = tempo - (dias_aux - dias) * 8;

	cout << "Tempo de entrega: " << dias_aux << " dia(s) " <<  horas << " hora(s)" << endl;
}

int localizaposicao (char estado_uf[100], struct estados uf[], int contador)
{
	int posicao;
	int i;
	for (i = 0; i < 27; i ++)
	{
		if (strcmp(estado_uf, uf[i].nomeEstado) == 0)
		{
			posicao = i;
			break;
		}
	}
	return posicao;
}

float calcub(float A, float L, float C)
{
	float FC = 300;
	float cubagem;

	cubagem = A * L * C * FC;

	return cubagem;
}

float VCG(float KM)
{
	float Result_VCG;

	Result_VCG = KM * 0.1;

	return Result_VCG;
}

float logica_custo(float resultado, float KM)
{

	float valor_fixo = 5;
	float frete;

	frete = (resultado * valor_fixo) + (resultado * VCG(KM));

	return frete;
}

float custofixo (int posicao, struct estados uf[])
{
	float valorfixo;
	valorfixo = uf[posicao].valorFixo;

	return valorfixo;
}

int ajustanome(char estado_uf[], struct estados uf[])
{
	char aux_estado[100];
	int contador = 0;
	int posicao;
	for (int i = 0; i < strlen(estado_uf); i ++)
	{
		if (estado_uf[i] != ' ')
		{
			aux_estado[contador] = estado_uf[i];
			contador = contador + 1;

		}
	}
	aux_estado[contador] = '\0';
	posicao = localizaposicao(aux_estado, uf, contador);
	return posicao;
}

int main()
{
	struct estados uf[27];
	float altura;
	float largura;
	float comprimento;
	float resultado_cubagem;
	float resultado_frete = 0;
	int posicao;
	char estado_uf[100];
	int dias = 1;
	char retirada;
	char endereco[250];
	int opcao;
	

	LerArquivo(uf);
	cout << "///////////////////////////////////////////// SEJA BEM VINDO A MOVING BOX /////////////////////////////////////////////" << endl;
	cout << endl;
	do
	{
		cout << "Entre com as dimensoes do pacote (em metros)." << endl;
		cout << "Digite a altura: ";
		cin >> altura;
		cout << "Digite a largura: ";
		cin >> largura;
		cout << "Digite o comprimento: ";
		cin >> comprimento;
		cout << "Deseja retirar o produto no Centro de Distribuicao (capital do Estado)?" << endl;
		do
		{
			cout << "Digite S para SIM ou N para NAO: ";
			cin >> retirada;
		}
		while(retirada != 'S' && retirada != 'N');
		if (retirada == 'S')
		{
			cout << "Digite o estado o qual deseja retirar: ";
			cin.ignore();
			cin.getline(estado_uf, 100);
			posicao = ajustanome(estado_uf, uf);
		}
		else
		{
			dias += 2; //para chegar ate as cidades dentro do estado
			cout << "Digite o endereco com rua, numero, bairro, cidade." << endl;
			cin.ignore();
			cin.getline(endereco, 200);
			cout << "Entre com o estado: ";
			cin.getline(estado_uf, 100);
			posicao = ajustanome(estado_uf, uf);
			resultado_frete = custofixo(posicao, uf);
		}



		resultado_cubagem = calcub(altura, largura, comprimento);
		resultado_frete += logica_custo(resultado_cubagem, uf[posicao].km);

		cout << fixed << setprecision(2);
		cout << endl;
		cout << "///////////////////////////////////////////////////// MOVING BOX ///////////////////////////////////////////////////////" << endl;
		cout << "Sua compra foi concluida com sucesso, veja abaixo as informacoes do seu pedido: " << endl;
		if (retirada == 'S')
		{
			cout << "Destino da entrega: " << uf[posicao].capital << " - " << uf[posicao].sigla << endl;
		}
		else
		{
			cout << "Destino da entrega: " << endereco << " - " << estado_uf << " - " << uf[posicao].sigla << endl;
		}
		calctemp(uf[posicao].km, dias);
		cout << "Valor do frete: R$  " << resultado_frete << endl;
		cout << "Agradecemos a preferencia!" << endl;
		cout << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "Gostaria de realizar novo pedido?" << endl;
		do
		{
			cout << "Digite\n 1 para sair\n 2 para realizar novo pedido\nOpcao: ";
			cin >> opcao;
		}
		while(opcao != 1 && opcao != 2);
		resultado_frete = 0;
	}
	while (opcao != 1);
	return 0;
}

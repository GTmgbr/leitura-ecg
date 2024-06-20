#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;

int main()
{
	//Declarando as variáveis
	
	int i = 0;//Contador inicialmente vale zero
	float diferenca;//Diferença entre um pico e outro
	float pico1;//Primeiro pico do batimento
	float pico2;//Segundo pico do batimento
    char* vet[5000];//Vetor para guardar todos os números do arquivo
    char linha[5000];//Vetor para guardar as linhas do arquivo
	
	string info;//Informação contida no arquivo
	
	ifstream arqin("ecg.txt");//Ler arquivo 
	
	if(arqin.is_open())//Se o arquivo estiver aberto
	{
		while(!arqin.eof())//Enquanto o arquivo estiver rodando
		{
			//Adiciona cada palavra no vetor
			vet[i] = strdup(linha);
			i++;
			string info;
			getline(arqin,info);
		}
	}
	
	for(i=2001; i>0; i--)//Para o contador igual a 2001 amostras, maior que 1 e decrescendo 
	{
		if(i==2001)//Se o contador for igual a 2001
		{
			pico2 = 1009;//O segundo pico se dará em torno da posição 1009
			pico1 = 258;//O primeiro pico se dará em torno da posição 258
		}
		
		diferenca = (pico2 - pico1);//A diferença de posição entre os picos
	}
	
	//Calculando a frequencia cardíaca
	
	int fs = 1000;//Frequência de amostragem dada em Hertz
	float variacao = diferenca/fs;//A variação é a diferença entre os picos dividida por fs
	float minutos = variacao/60;//O tempo em minutos é convertido através da variação dividida por 60 segundos
	float bpm = 1/minutos;//Batimentos por minuto
	
	cout << "Frequencia cardiaca = " << fixed << setprecision(1) << bpm << " bpm" << endl;
	
	return 0;
}
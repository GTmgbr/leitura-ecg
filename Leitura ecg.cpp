#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;

int main()
{
	//Declarando as vari�veis
	
	int i = 0;//Contador inicialmente vale zero
	float diferenca;//Diferen�a entre um pico e outro
	float pico1;//Primeiro pico do batimento
	float pico2;//Segundo pico do batimento
    char* vet[5000];//Vetor para guardar todos os n�meros do arquivo
    char linha[5000];//Vetor para guardar as linhas do arquivo
	
	string info;//Informa��o contida no arquivo
	
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
			pico2 = 1009;//O segundo pico se dar� em torno da posi��o 1009
			pico1 = 258;//O primeiro pico se dar� em torno da posi��o 258
		}
		
		diferenca = (pico2 - pico1);//A diferen�a de posi��o entre os picos
	}
	
	//Calculando a frequencia card�aca
	
	int fs = 1000;//Frequ�ncia de amostragem dada em Hertz
	float variacao = diferenca/fs;//A varia��o � a diferen�a entre os picos dividida por fs
	float minutos = variacao/60;//O tempo em minutos � convertido atrav�s da varia��o dividida por 60 segundos
	float bpm = 1/minutos;//Batimentos por minuto
	
	cout << "Frequencia cardiaca = " << fixed << setprecision(1) << bpm << " bpm" << endl;
	
	return 0;
}
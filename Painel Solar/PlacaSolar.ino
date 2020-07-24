// Primeiro incluimos a biblioteca para uso do servo
#include <Servo.h>

// Criamos o objeto Servo e o chamamos de meuServo
Servo meuServo;

// Declaramos constantes com as portas que usaremos
const int  LDRE = A0;
const int  LDRD = A1;
const int  painel = A2;

// Definimos algumas constantes para o funcionamento do codigo
int  leituraPainel =0;
int  leituraD = 0;
int  leituraE = 0;
int  pos = 90;
int  margem = 10;


void setup(){
	Serial.begin(9600);
	// Declaramos que o servo esta conectado a porta numero 5 e, em seguida, mandamos ele para a posicao inicial
	meuServo.attach(5);
	meuServo.write(pos);
}

void loop(){
	// Efetuamos a leitura das portas analogicas e salvamos nas respectivas variaveis
	leituraPainel = analogRead(painel);
	leituraD = analogRead(LDRD);
	leituraE = analogRead(LDRE);
	// Enviamos a leitura do painel para o monitor serial
	Serial.println(leituraPainel);
	// Essa parte comentada pode ser usada para testar as leituras dos LDRs
	/*Serial.print("Direita: ");
	Serial.println(leituraD);
	Serial.print("Esquerda: ");
	Serial.println(leituraE);
	delay(800);*/
	// Com base nas leituras feitas anteriormente e feito o posicionamento do painel
	if( leituraD > (leituraE+margem)){
		pos++;
		meuServo.write(pos);
		delay(150);
	}else if( leituraE >( leituraD+margem)){
		pos--;
		meuServo.write(pos);
		delay(150);
	}	
}

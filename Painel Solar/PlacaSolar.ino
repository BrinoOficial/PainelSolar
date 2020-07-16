#include <Servo.h>

Servo meuServo;

const int  LDRE = A0;
const int  LDRD = A1;
const int  painel = A2;

int  leituraPainel =0;
int  leituraD = 0;
int  leituraE = 0;
int  pos = 90;
int  margem = 10;


void setup(){
	Serial.begin(9600);
	meuServo.attach(5);
	meuServo.write(pos);
}

void loop(){
	leituraPainel = analogRead(painel);
	leituraD = analogRead(LDRD);
	leituraE = analogRead(LDRE);
	Serial.println(leituraPainel);
	/*Serial.print("Direita: ");
	Serial.println(leituraD);
	Serial.print("Esquerda: ");
	Serial.println(leituraE);
	delay(800);*/
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
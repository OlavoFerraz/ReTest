 #include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
 
//Definicao de cores
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF
#define ORANGE          0xFBE0
 
//CS, CD, WR, RD, RESET
Adafruit_TFTLCD tft(A3, A2, A1, A0, A4);

int y = 0;
int x = 1;
String listaR [3][6] = {
  {"", " Controle      >", "<Luz           >", "<Projetor      >", "<Cadeira       >", "<Ar-condicionado"}, //Valores da lista 
  {"","Faltando","Quebrado","Sem Bateria","",""},
  {"","Faltando","Quebrado","Sem Bateria","",""}
};
int botao1;
int botao2;
int bt;
String texto;

void terceiratela(void)
{ 
  texto = listaR [y][x];
  tft.fillScreen(BLACK);
  tft.fillRoundRect(5, 15, 312, 100, 5, ORANGE);
  tft.drawRoundRect(5, 15, 312, 100, 5, WHITE);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(18, 31);
  tft.println("Especifique seu ");
  tft.setCursor(18, 71);
  tft.println("    Report");
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(19, 32);
  tft.println("Especifique seu ");
  tft.setCursor(19, 72);
  tft.println("    Report");
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.setCursor(20, 30);
  tft.println("Especifique seu ");
  tft.setCursor(20, 70);
  tft.println("    Report");
  tft.fillRoundRect(5, 150, 312, 50, 5, ORANGE);
  tft.drawRoundRect(5, 150, 312, 50, 5, WHITE);
  tft.setCursor(16,163);
  tft.setTextColor(BLACK);
  tft.println(texto);
  tft.setTextColor(BLACK);
  tft.setCursor(17,164);
  tft.println(texto);
  tft.setTextColor(WHITE);
  tft.setCursor(18,165);
  tft.println(texto);  
  }



void mudancaTela(void)
{
  texto = listaR[y][x];
  tft.fillRoundRect(5, 150, 312, 50, 5, ORANGE);
  tft.drawRoundRect(5, 150, 312, 50, 5, WHITE);
  tft.setCursor(16,163);
  tft.setTextColor(BLACK);
  tft.println(texto);
  tft.setTextColor(BLACK);
  tft.setCursor(17,164);
  tft.println(texto);
  tft.setTextColor(WHITE);
  tft.setCursor(18,165);
  tft.println(texto);
}
void segundaTela(void)
{
  texto = listaR[y][x];
  tft.fillScreen(BLACK);
  tft.fillRoundRect(5, 15, 312, 100, 5, ORANGE);
  tft.drawRoundRect(5, 15, 312, 100, 5, WHITE);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(18, 31);
  tft.println(" Selecione seu ");
  tft.setCursor(18, 71);
  tft.println("    Report");
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(19, 32);
  tft.println(" Selecione seu ");
  tft.setCursor(19, 72);
  tft.println("    Report");
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.setCursor(20, 30);
  tft.println(" Selecione seu ");
  tft.setCursor(20, 70);
  tft.println("    Report");
  tft.fillRoundRect(5, 150, 312, 50, 5, ORANGE);
  tft.drawRoundRect(5, 150, 312, 50, 5, WHITE);
  tft.setCursor(16,163);
  tft.setTextColor(BLACK);
  tft.println(texto);
  tft.setTextColor(BLACK);
  tft.setCursor(17,164);
  tft.println(texto);
  tft.setTextColor(WHITE);
  tft.setCursor(18,165);
  tft.println(texto);

}

void verificaBotoes(void)
{
 bt = digitalRead(24); //Select
 botao1 = digitalRead(22); //Cima
 botao2 = digitalRead(23); //Baixo
  if (botao1 == HIGH){  
    delay(100);
    if (x < 5){
      x = x + 1 ; 
      mudancaTela();
    } 
  }  
  if (botao2 == HIGH){
    delay(100);
    if (x > 1) {
      x = x - 1 ;
      mudancaTela();   
      }
   } 
   if (bt == HIGH){
    delay(100);
    y = x;
    x = 1;
    terceiratela();
    
    
   }
  Serial.print("x=>");
  Serial.println(x);
  Serial.print("y=>");
  Serial.println(y);
  Serial.println(texto);
}

 
void setup(void) 
{
  pinMode(24,INPUT); // Botão "Selecionar"
  pinMode(22,INPUT); // Botão "Cima"
  pinMode(23,INPUT); // Botão "Baixo"
  Serial.begin(9600);
  tft.reset();
  tft.begin(0x9325);
  tft.setRotation(3);
  segundaTela();
}
void loop()
{
  verificaBotoes();
  
  
}

void tela_inicial(uint16_t color)
{
  tft.fillScreen(BLACK);
  tft.fillRoundRect(5, 15, 312, 100, 5, ORANGE);
  tft.drawRoundRect(5, 15, 312, 100, 5, WHITE);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(13, 31);
  tft.println("  Aproxime seu ");
  tft.setCursor(13, 71);
  tft.println("cartao do leitor");
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(14, 32);
  tft.println("  Aproxime seu ");
  tft.setCursor(14, 72);
  tft.println("cartao do leitor");
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.setCursor(15, 30);
  tft.println("  Aproxime seu ");
  tft.setCursor(15, 70);
  tft.println("cartao do leitor");
  delay(30000);
}

void tela_reporte(uint16_t color)
{
 botao1 = digitalRead(22); //Cima
 botao2 = digitalRead(23); //Baixo
 bt = digitalRead(24); // Botão select
 Serial.println(botao1);
    
}

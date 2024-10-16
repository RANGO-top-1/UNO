int led_RANGO_1_red = 2;
int led_RANGO_2_yellow = 3;
int led_RANGO_3_green = 4;

void setup()
{
  pinMode(led_RANGO_1_red , OUTPUT);
  pinMode(led_RANGO_2_yellow , OUTPUT);
  pinMode(led_RANGO_3_green , OUTPUT);
}
void loop()
{
  digitalWrite(led_RANGO_1_red , HIGH);
  delay(16000);
  digitalWrite(led_RANGO_2_yellow , HIGH);
  delay(700);
  digitalWrite(led_RANGO_1_red , LOW);
  digitalWrite(led_RANGO_2_yellow , LOW);
  digitalWrite(led_RANGO_3_green , HIGH);
  delay(2000);
  digitalWrite(led_RANGO_3_green , LOW);
  digitalWrite(led_RANGO_2_yellow , HIGH);
  delay(700);
  digitalWrite(led_RANGO_2_yellow , LOW);
}

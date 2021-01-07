float Temp;
float Temp2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}

void loop() {
  Temp = analogRead(A0);
  Temp = (Temp/1024*5)/0.01;
  Serial.print("Read Value = ");
  Serial.print(analogRead(A0));
  Serial.print(" Temp = ");
  Serial.print(Temp);

  Temp2 = analogRead(A1);
  Temp2 = (Temp2/1024*5)/0.01;
  Serial.print("Read Value2 = ");
  Serial.print(analogRead(A1));
  Serial.print(" Temp2 = ");
  Serial.println(Temp);
  delay(1000);
}
/*
  *我們從A0讀取到的值並不是溫度也不是電壓的實際值，必須透過百分比與單位換算才能得到我們想要的溫度值。
  *Arduino UNO的 analog輸入(A0~A5)所能讀到的範圍是 0~1024，而Arduino電壓範圍為 0~5V，所以我們可以透過下面的公式得到轉換後的電壓：
  *轉換的電壓 ＝ ( A0的值 / 1024 ) x 5
  *求得 A0 轉換後的電壓值後，透過從 Datasheet知道的，每上升1度C 電壓增加 10mV，我們將轉換後的電壓值再除以 10mV，就可以得出溫度值：
  *溫度 ＝ 轉換的電壓 / 10mV
  * https://makerpro.cc/2018/09/temperature-sensor-lm35/
*/

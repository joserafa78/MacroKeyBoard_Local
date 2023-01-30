#include <Arduino.h>
#line 1 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
#include <HID-Project.h> // ibrería estánda
#include <OneButton.h> // OneButton by Matthias Hertel, mathertel@hotmail.com
//Este codigo ha sido Mejorado y Adaptado a las nececidades de Negocio del Local.



// Teclas || El número representa el PIN donde está conectada la tecla.
const int b_key = 2;
const int a_key = 3;
const int d_key = 4;
const int c_key = 5;
const int e_key = 6;
const int f_key = 7;
const int g_key = 8;
const int h_key = 9;
//---------------Instancias de boton----------
OneButton a_btn = OneButton(a_key, true, true);
OneButton b_btn = OneButton(b_key, true, true);
OneButton c_btn = OneButton(c_key, true, true);
OneButton d_btn = OneButton(d_key, true, true);


// Encoder || El número representa los pines usados para conectar el encoder.
#define OUTPUT_B 15
#define OUTPUT_A A0
#define BUTTON A1
#define PIN_5V A2
#define PIN_GND A3

// Variables de control
bool aState;
bool aLastState;
bool lastButtonState = 0;
String programa = "windows";

#line 36 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void setup();
#line 84 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void loop();
#line 474 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void a_key_evento_clic();
#line 479 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void a_key_evento_doble_clic();
#line 506 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void b_key_evento_clic();
#line 511 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void b_key_evento_doble_clic();
#line 538 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void c_key_evento_clic();
#line 543 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void c_key_evento_doble_clic();
#line 547 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void d_key_evento_clic();
#line 552 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void d_key_evento_doble_clic();
#line 559 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void abreConsola();
#line 573 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void minimizaVentana();
#line 36 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
void setup()
{
    Serial.begin(9600);

    a_btn.attachClick(a_key_evento_clic);             // Hacer Clic
    a_btn.attachDoubleClick(a_key_evento_doble_clic); // Hacer Doble Clic
    digitalWrite(a_key, HIGH);

    b_btn.attachClick(b_key_evento_clic);             // Hacer Clic
    b_btn.attachDoubleClick(b_key_evento_doble_clic); // Hacer Doble Clic
    digitalWrite(b_key, HIGH);

    c_btn.attachClick(c_key_evento_clic);             // Hacer Clic
    c_btn.attachDoubleClick(c_key_evento_doble_clic); // Hacer Doble Clic
    digitalWrite(c_key, HIGH);

    d_btn.attachClick(d_key_evento_clic);             // Hacer Clic
    d_btn.attachDoubleClick(d_key_evento_doble_clic); // Hacer Doble Clic
    digitalWrite(d_key, HIGH);

    pinMode(e_key, INPUT_PULLUP);
    digitalWrite(e_key, HIGH);

    pinMode(f_key, INPUT_PULLUP);
    digitalWrite(f_key, HIGH);

    pinMode(g_key, INPUT_PULLUP);
    digitalWrite(g_key, HIGH);

    pinMode(h_key, INPUT_PULLUP);
    digitalWrite(h_key, HIGH);

    // ENCODER || NO MODIFICAR
    pinMode(OUTPUT_A, INPUT);
    pinMode(OUTPUT_B, INPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    pinMode(PIN_5V, OUTPUT);
    digitalWrite(PIN_5V, HIGH);
    pinMode(PIN_GND, OUTPUT);
    digitalWrite(PIN_GND, LOW);
    aLastState = digitalRead(OUTPUT_A);

    Consumer.begin();
    Keyboard.begin();
}

long lastClickTime = 0;

void loop()
{

    a_btn.tick(); // Funcio necesari.Chekea el Objeto.
    b_btn.tick(); // Funcio necesari.Chekea el Objeto.
    c_btn.tick(); // Funcio necesari.Chekea el Objeto.
    d_btn.tick(); // Funcio necesari.Chekea el Objeto.

        // FUNCIONAMIENTO DE LAS TECLAS DE ATAJO Y EL ENCODER SI HEMOS SELECCIONADO WINDOWS ( D )
    if (programa == "windows")
    {

        // ABRIMOS EL BLOC DE NOTAS
        if (digitalRead(e_key) == LOW)
        {
            Keyboard.press(KEY_LEFT_GUI); // Tecla Win
            Keyboard.press('r');          // Ventana EJECUTA.
            Keyboard.releaseAll();
            delay(200);
            Keyboard.print("notepad"); // Abre Ejecutar
            Keyboard.press(KEY_RETURN);
            Keyboard.releaseAll();
            delay(1000);
            //----
            Keyboard.print("Archivo Abierto desde MacroKeyBoard");
            Keyboard.press(KEY_RETURN);
            Keyboard.releaseAll();
            delay(300);
        }

        // ABRIMOS LA CALCULADORA
        if (digitalRead(f_key) == LOW)
        {
            Keyboard.press(KEY_LEFT_GUI); // Tecla Win
            Keyboard.press('r');          // Ventana EJECUTA.
            Keyboard.releaseAll();
            delay(200);
            Keyboard.print("calc"); // Abre Ejecutar
            Keyboard.press(KEY_RETURN);
            Keyboard.releaseAll();
            delay(300);
        }

        // ABRIMOS PAINT
        if (digitalRead(g_key) == LOW)
        {
            Keyboard.press(KEY_LEFT_GUI); // Tecla Win
            Keyboard.press('r');          // Ventana EJECUTA.
            Keyboard.releaseAll();
            delay(200);
            Keyboard.print("mspaint"); // Abre Ejecutar
            Keyboard.press(KEY_RETURN);
            Keyboard.releaseAll();
            delay(2000);
        }

        // ABRIMOS EXCEL
        if (digitalRead(h_key) == LOW)
        {
            Keyboard.press(KEY_LEFT_GUI); // Tecla Win
            Keyboard.press('r');          // Ventana EJECUTA.
            Keyboard.releaseAll();
            delay(200);
            Keyboard.print("excel /safe"); // Abre Ejecutar
            Keyboard.press(KEY_RETURN);
            Keyboard.releaseAll();
            delay(50000);
        }

        // ENCODER
        if (millis() - lastClickTime > 1000)
        {
            aState = digitalRead(OUTPUT_A);

            if (aState != aLastState)
            {
                if (digitalRead(OUTPUT_B) != aState)
                {
                    // IZQUIERDA || BAJAMOS EL VOLUMEN
                    Consumer.write(MEDIA_VOL_DOWN);
                }
                else
                {
                    // DERECHA || SUBIMOS EL VOLUMEN
                    Consumer.write(MEDIA_VOL_UP);
                }
                // Keyboard.releaseAll();
                aLastState = aState;
            }

            if (digitalRead(BUTTON) == LOW)
            {
                if (lastButtonState == HIGH)
                {
                    // BOTÓN || MUTEAMOS/DESMUTEAMOS EL SONIDO
                    Consumer.write(MEDIA_VOLUME_MUTE);
                    lastClickTime = millis();
                }
                lastButtonState = LOW;
            }
            else
            {
                lastButtonState = HIGH;
            }
        }
        // FIN DEL ENCODER
    }

    // FUNCIONAMIENTO DE LAS TECLAS DE ATAJO Y EL ENCODER SI HEMOS SELECCIONADO ( A )
    if (programa == "SGTaller 3")
    {
        // TECLAS
        // EQUIPOS EN EL TALLER
        if (digitalRead(e_key) == LOW)
        {
            Keyboard.press(KEY_F6);
            delay(100);
            Keyboard.releaseAll();
            delay(1000);
            Keyboard.press(KEY_UP_ARROW );
            delay(100);
            Keyboard.releaseAll();
        }

        // NUEVA ORDEN
        if (digitalRead(f_key) == LOW)
        {
            Keyboard.press(KEY_F9);
            delay(100);
            Keyboard.releaseAll();
            delay(1000);
        }

        // BUSCA ORDEN DE REPARACION
        if (digitalRead(g_key) == LOW)
        {
            Keyboard.press(KEY_F3);
            delay(100);
            Keyboard.releaseAll();
            delay(1000);
        }

        // BUSCA POR CLIENTE
        if (digitalRead(h_key) == LOW)
        {
            Keyboard.press(KEY_F5);
            delay(100);
            Keyboard.releaseAll();
            delay(1000);
        }

        // ENCODER
        if (millis() - lastClickTime > 1000)
        {
            aState = digitalRead(OUTPUT_A);

            if (aState != aLastState)
            {
                if (digitalRead(OUTPUT_B) != aState)
                {
                    // IZQUIERDA || ZOOM OUT
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press(47);
                    delay(10);
                }
                else
                {
                    // DERECHA || ZOOm IN
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press(93);
                    delay(10);
                }
                Keyboard.releaseAll();
                aLastState = aState;
            }

            if (digitalRead(BUTTON) == LOW)
            {
                if (lastButtonState == HIGH)
                {
                    // BOTÓN || GUARDAMOS EL DOCUMENTO ACTUAL (CTRL+S)
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press('s');
                    delay(100);
                    Keyboard.releaseAll();

                    lastClickTime = millis();
                }
                lastButtonState = LOW;
            }
            else
            {
                lastButtonState = HIGH;
            }
        }
        // FIN DEL ENCODER
    }

    // FUNCIONAMIENTO DE LAS TECLAS DE ATAJO Y EL ENCODER SI HEMOS SELECCIONADO ( B )
    if (programa == "Computacion Plus")
    {
        // TECLAS
        // Busquedas de Articulos por Detalles.
        if (digitalRead(e_key) == LOW)
        {
            Keyboard.press(KEY_F1);
            delay(100);
            Keyboard.releaseAll();
            Keyboard.press(KEY_F2);
            delay(100);
            Keyboard.releaseAll();
        }

        // Abre Formulario Para comienzar una Nueva venta
        if (digitalRead(f_key) == LOW)
        {
            Keyboard.press(KEY_F4);
            delay(100);
            Keyboard.releaseAll();
        }

        // Genera una Nueva venta se Soporte tecnico.
        if (digitalRead(g_key) == LOW)
        {
            Keyboard.press(KEY_F4);
            delay(100);
            Keyboard.releaseAll();
            Keyboard.print("302"); // Cod para Soporte Tecnico
            Keyboard.press(KEY_RETURN);
            delay(100);
            Keyboard.releaseAll();
            Keyboard.press(HID_KEYBOARD_LEFT_ALT);
            Keyboard.press('A');
            Keyboard.releaseAll();
            delay(100);
        }

        // Reporte de ventas del dia
        if (digitalRead(h_key) == LOW)
        {
            Keyboard.press(HID_KEYBOARD_LEFT_ALT);
            delay(100);
            Keyboard.press('r');
            Keyboard.release('r');
            delay(100);
            Keyboard.press('v');
            Keyboard.release('v');
            delay(100);
            Keyboard.press('v');
            Keyboard.release('v');
            delay(100);
            Keyboard.releaseAll();
            delay(100);
        }

        // ENCODER
        if (millis() - lastClickTime > 1000)
        {
            aState = digitalRead(OUTPUT_A);

            if (aState != aLastState)
            {
                if (digitalRead(OUTPUT_B) != aState)
                {
                    // IZQUIERDA || RETROCEDER FOTOGRAMA
                    Keyboard.press(KEY_LEFT_ARROW);
                    delay(10);
                }
                else
                {
                    // DERECHA || AVANZAR FOTOGRAMA
                    Keyboard.press(KEY_RIGHT_ARROW);
                    delay(10);
                }
                Keyboard.releaseAll();
                aLastState = aState;
            }

            if (digitalRead(BUTTON) == LOW)
            {
                if (lastButtonState == HIGH)
                {
                    // BOTÓN || ACTIVAMOS LA REPRODUCCIÓN
                    Keyboard.press(' ');
                    delay(100);
                    Keyboard.releaseAll();

                    lastClickTime = millis();
                }
                lastButtonState = LOW;
            }
            else
            {
                lastButtonState = HIGH;
            }
        }
        // FIN DEL ENCODER
    }

    // FUNCIONAMIENTO DE LAS TECLAS DE ATAJO Y EL ENCODER SI HEMOS SELECCIONADO OBS ( C )
    if (programa == "obs"){
            //TECLAS    
    //ATAJO 1
    if(digitalRead(e_key)==LOW){      
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('1');      
      delay(100);
      Keyboard.releaseAll();          
    }

    //ATAJO 2
    if(digitalRead(f_key)==LOW){      
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('2');      
      delay(100);
      Keyboard.releaseAll();      
    }

    //ATAJO 3
    if(digitalRead(g_key)==LOW){      
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('3');      
      delay(100);
      Keyboard.releaseAll();      
    }

    //ATAJO 4
    if(digitalRead(h_key)==LOW){
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('4');      
      delay(100);
      Keyboard.releaseAll();      
    }
    
    //ENCODER
    if (millis() - lastClickTime > 1000){
      aState = digitalRead(OUTPUT_A);
          
      if (aState != aLastState){
        if (digitalRead(OUTPUT_B) != aState){
          //IZQUIERDA || ATAJO 5
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('5');                
          delay(10);
        }else{
          //DERECHA || ATAJO 6
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('6');
          delay(10);
        }
        Keyboard.releaseAll();
        aLastState = aState;
      }
      
      if (digitalRead(BUTTON) == LOW){      
        if (lastButtonState == HIGH){
          //BOTÓN || ATAJO 7
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('7');
          delay(10);
          Keyboard.releaseAll();         
          
          lastClickTime = millis();
        }      
        lastButtonState = LOW;
      } else {      
        lastButtonState = HIGH;
      }
    }
    //FIN DEL ENCODER  
    }


  
}
//******************************FUNCIONES PARA CADA EVENTO**********************************
void a_key_evento_clic()
{
    programa = "SGTaller 3";
        Serial.println("SGTaller 3");
}
void a_key_evento_doble_clic()
{
    programa = "SGTaller 3";
    Keyboard.press(KEY_LEFT_GUI); // Tecla Win
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(200);
    Keyboard.print("cmd"); // Abre Ejecutar
    Keyboard.write(KEY_RETURN);
    delay(1300);
    Keyboard.print("cd");       // Escribe Comando en Consola
    Keyboard.write(38);         // Escribe Simbolo "/" ascii.
    Keyboard.write(KEY_RETURN); // Carga Archivo Raiz
    delay(100);
    Keyboard.print("cd SGTaller 3");
    Keyboard.write(KEY_RETURN);
    delay(100);
    Keyboard.print("Service.exe");
    Keyboard.write(KEY_RETURN);
    delay(500);
    // cerrarVentana();
    delay(8000);
    Keyboard.print("ventas");
    Keyboard.write(KEY_RETURN);
    Keyboard.print("ventas");
    Keyboard.write(KEY_RETURN);
}
void b_key_evento_clic()
{
    programa = "Computacion Plus";
    Serial.println("Computacion Plus");
}
void b_key_evento_doble_clic()
{
    programa = "Computacion Plus";
    Keyboard.press(KEY_LEFT_GUI); // Tecla Win
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(200);
    Keyboard.print("cmd"); // Abre Ejecutar
    Keyboard.write(KEY_RETURN);
    delay(1300);
    Keyboard.print("cd");       // Escribe Comando en Consola
    Keyboard.write(38);         // Escribe Simbolo "/" ascii.
    Keyboard.write(KEY_RETURN); // Carga Archivo Raiz
    delay(100);
    Keyboard.print("cd Computacion Plus");
    Keyboard.write(KEY_RETURN);
    delay(100);
    Keyboard.print("Computacion.exe");
    Keyboard.write(KEY_RETURN);
    delay(500);
    // cerrarVentana();
    delay(8000);
    Keyboard.print("0");
    Keyboard.write(KEY_RETURN);
    Keyboard.print("admin");
    Keyboard.write(KEY_RETURN);
}
void c_key_evento_clic()
{
    programa = "obs";
    Serial.println("obs");
}
void c_key_evento_doble_clic()
{
    programa = "obs";
}
void d_key_evento_clic()
{
    programa = "windows";
    Serial.println("windows");
}
void d_key_evento_doble_clic()
{
    programa = "windows";
    minimizaVentana();
}


void abreConsola()
{
    Keyboard.press(KEY_LEFT_GUI); // Tecla Win
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(200);
    Keyboard.print("cmd"); // Abre Ejecutar
    Keyboard.write(KEY_RETURN);
    delay(1300);
    Keyboard.print("cd");       // Escribe Comando en Consola
    Keyboard.write(38);         // Escribe Simbolo "/" ascii.
    Keyboard.write(KEY_RETURN); // Carga en Archivo Raiz
    delay(100);
}
void minimizaVentana()
{

    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('d');
    Keyboard.releaseAll();
}


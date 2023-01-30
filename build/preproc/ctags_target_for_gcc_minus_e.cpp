# 1 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino"
# 2 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino" 2
# 3 "c:\\Users\\Servcio Tecnico\\Desktop\\MacroKeyBoardLocal\\MacroKeyPad.ino" 2
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






// Variables de control
bool aState;
bool aLastState;
bool lastButtonState = 0;
String programa = "windows";

void setup()
{
    Serial.begin(9600);

    a_btn.attachClick(a_key_evento_clic); // Hacer Clic
    a_btn.attachDoubleClick(a_key_evento_doble_clic); // Hacer Doble Clic
    digitalWrite(a_key, 0x1);

    b_btn.attachClick(b_key_evento_clic); // Hacer Clic
    b_btn.attachDoubleClick(b_key_evento_doble_clic); // Hacer Doble Clic
    digitalWrite(b_key, 0x1);

    c_btn.attachClick(c_key_evento_clic); // Hacer Clic
    c_btn.attachDoubleClick(c_key_evento_doble_clic); // Hacer Doble Clic
    digitalWrite(c_key, 0x1);

    d_btn.attachClick(d_key_evento_clic); // Hacer Clic
    d_btn.attachDoubleClick(d_key_evento_doble_clic); // Hacer Doble Clic
    digitalWrite(d_key, 0x1);

    pinMode(e_key, 0x2);
    digitalWrite(e_key, 0x1);

    pinMode(f_key, 0x2);
    digitalWrite(f_key, 0x1);

    pinMode(g_key, 0x2);
    digitalWrite(g_key, 0x1);

    pinMode(h_key, 0x2);
    digitalWrite(h_key, 0x1);

    // ENCODER || NO MODIFICAR
    pinMode(A0, 0x0);
    pinMode(15, 0x0);
    pinMode(A1, 0x2);
    pinMode(A2, 0x1);
    digitalWrite(A2, 0x1);
    pinMode(A3, 0x1);
    digitalWrite(A3, 0x0);
    aLastState = digitalRead(A0);

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
        if (digitalRead(e_key) == 0x0)
        {
            Keyboard.press(KEY_LEFT_GUI); // Tecla Win
            Keyboard.press('r'); // Ventana EJECUTA.
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
        if (digitalRead(f_key) == 0x0)
        {
            Keyboard.press(KEY_LEFT_GUI); // Tecla Win
            Keyboard.press('r'); // Ventana EJECUTA.
            Keyboard.releaseAll();
            delay(200);
            Keyboard.print("calc"); // Abre Ejecutar
            Keyboard.press(KEY_RETURN);
            Keyboard.releaseAll();
            delay(300);
        }

        // ABRIMOS PAINT
        if (digitalRead(g_key) == 0x0)
        {
            Keyboard.press(KEY_LEFT_GUI); // Tecla Win
            Keyboard.press('r'); // Ventana EJECUTA.
            Keyboard.releaseAll();
            delay(200);
            Keyboard.print("mspaint"); // Abre Ejecutar
            Keyboard.press(KEY_RETURN);
            Keyboard.releaseAll();
            delay(2000);
        }

        // ABRIMOS EXCEL
        if (digitalRead(h_key) == 0x0)
        {
            Keyboard.press(KEY_LEFT_GUI); // Tecla Win
            Keyboard.press('r'); // Ventana EJECUTA.
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
            aState = digitalRead(A0);

            if (aState != aLastState)
            {
                if (digitalRead(15) != aState)
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

            if (digitalRead(A1) == 0x0)
            {
                if (lastButtonState == 0x1)
                {
                    // BOTÓN || MUTEAMOS/DESMUTEAMOS EL SONIDO
                    Consumer.write(MEDIA_VOLUME_MUTE);
                    lastClickTime = millis();
                }
                lastButtonState = 0x0;
            }
            else
            {
                lastButtonState = 0x1;
            }
        }
        // FIN DEL ENCODER
    }

    // FUNCIONAMIENTO DE LAS TECLAS DE ATAJO Y EL ENCODER SI HEMOS SELECCIONADO ( A )
    if (programa == "SGTaller 3")
    {
        // TECLAS
        // GUARDAR PARA WEB
        if (digitalRead(e_key) == 0x0)
        {
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press('s');
            delay(100);
            Keyboard.releaseAll();
        }

        // DESHACER
        if (digitalRead(f_key) == 0x0)
        {
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press('z');
            delay(150);
            Keyboard.releaseAll();
        }

        // PASO ATRÁS
        if (digitalRead(g_key) == 0x0)
        {
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press('z');
            delay(150);
            Keyboard.releaseAll();
        }

        // PASO ADELANTE
        if (digitalRead(h_key) == 0x0)
        {
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press('z');
            delay(150);
            Keyboard.releaseAll();
        }

        // ENCODER
        if (millis() - lastClickTime > 1000)
        {
            aState = digitalRead(A0);

            if (aState != aLastState)
            {
                if (digitalRead(15) != aState)
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

            if (digitalRead(A1) == 0x0)
            {
                if (lastButtonState == 0x1)
                {
                    // BOTÓN || GUARDAMOS EL DOCUMENTO ACTUAL (CTRL+S)
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press('s');
                    delay(100);
                    Keyboard.releaseAll();

                    lastClickTime = millis();
                }
                lastButtonState = 0x0;
            }
            else
            {
                lastButtonState = 0x1;
            }
        }
        // FIN DEL ENCODER
    }

    // FUNCIONAMIENTO DE LAS TECLAS DE ATAJO Y EL ENCODER SI HEMOS SELECCIONADO ( B )
    if (programa == "Computacion Plus")
    {
        // TECLAS
        // Busquedas de Articulos por Detalles.
        if (digitalRead(e_key) == 0x0)
        {
            Keyboard.press(KEY_F1);
            delay(100);
            Keyboard.releaseAll();
            Keyboard.press(KEY_F2);
            delay(100);
            Keyboard.releaseAll();
        }

        // Abre Formulario Para comienzar una Nueva venta
        if (digitalRead(f_key) == 0x0)
        {
            Keyboard.press(KEY_F4);
            delay(100);
            Keyboard.releaseAll();
        }

        // Genera una Nueva venta se Soporte tecnico.
        if (digitalRead(g_key) == 0x0)
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
        if (digitalRead(h_key) == 0x0)
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
            aState = digitalRead(A0);

            if (aState != aLastState)
            {
                if (digitalRead(15) != aState)
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

            if (digitalRead(A1) == 0x0)
            {
                if (lastButtonState == 0x1)
                {
                    // BOTÓN || ACTIVAMOS LA REPRODUCCIÓN
                    Keyboard.press(' ');
                    delay(100);
                    Keyboard.releaseAll();

                    lastClickTime = millis();
                }
                lastButtonState = 0x0;
            }
            else
            {
                lastButtonState = 0x1;
            }
        }
        // FIN DEL ENCODER
    }

    // FUNCIONAMIENTO DE LAS TECLAS DE ATAJO Y EL ENCODER SI HEMOS SELECCIONADO OBS ( C )
    if (programa == "obs"){
            //TECLAS    
    //ATAJO 1
    if(digitalRead(e_key)==0x0){
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('1');
      delay(100);
      Keyboard.releaseAll();
    }

    //ATAJO 2
    if(digitalRead(f_key)==0x0){
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('2');
      delay(100);
      Keyboard.releaseAll();
    }

    //ATAJO 3
    if(digitalRead(g_key)==0x0){
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('3');
      delay(100);
      Keyboard.releaseAll();
    }

    //ATAJO 4
    if(digitalRead(h_key)==0x0){
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('4');
      delay(100);
      Keyboard.releaseAll();
    }

    //ENCODER
    if (millis() - lastClickTime > 1000){
      aState = digitalRead(A0);

      if (aState != aLastState){
        if (digitalRead(15) != aState){
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

      if (digitalRead(A1) == 0x0){
        if (lastButtonState == 0x1){
          //BOTÓN || ATAJO 7
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('7');
          delay(10);
          Keyboard.releaseAll();

          lastClickTime = millis();
        }
        lastButtonState = 0x0;
      } else {
        lastButtonState = 0x1;
      }
    }
    //FIN DEL ENCODER  
    }



}
//******************************FUNCIONES PARA CADA EVENTO**********************************
void a_key_evento_clic()
{
    programa = "SGTaller 3";
}
void a_key_evento_doble_clic()
{
    programa = "SGTaller 3";
}
void b_key_evento_clic()
{
    programa = "Computacion Plus";
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
    Keyboard.print("cd"); // Escribe Comando en Consola
    Keyboard.write(38); // Escribe Simbolo "/" ascii.
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
}
void c_key_evento_doble_clic()
{
    programa = "obs";
}
void d_key_evento_clic()
{
    programa = "windows";
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
    Keyboard.print("cd"); // Escribe Comando en Consola
    Keyboard.write(38); // Escribe Simbolo "/" ascii.
    Keyboard.write(KEY_RETURN); // Carga en Archivo Raiz
    delay(100);
}
void minimizaVentana()
{

    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('d');
    Keyboard.releaseAll();
}

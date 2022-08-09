#ifdef __MSDOS__
    #include <iostream.h>
    #include <stdlib.h>
#else
    #include <iostream>
    #include <cstdlib>
    using namespace std;
#endif

int main (void)
{
    float IMC, altura_en_m, peso_en_kg;
    cout << "Ingresa el valor de altura en m: ";
    cin >> altura_en_m;
    cin.get();
    cout << "Ingresa el valor de peso en kg: ";
    cin >> peso_en_kg;
    cin.get();
    IMC=peso_en_kg/altura_en_m/altura_en_m;
    if(IMC<16)
        cout << "Criterio de ingreso en hospital." << endl;
    if(IMC>=16&&IMC<17)
        cout << "Infrapeso." << endl;
    if(IMC>=17&&IMC<18)
        cout << "Bajo peso." << endl;
    if(IMC>=18&&IMC<25)
        cout << "Peso normal (saludable)." << endl;
    if(IMC>=5&&IMC<30)
        cout << "Sobrepeso (obesidad de grado I)." << endl;
    if(IMC>=30&&IMC<35)
        cout << "Sobrepeso cr\242nico (obesidad de grado II)." << endl;
    if(IMC>=35&&IMC<40)
        cout << "Obesidad prem\242rbida (obesidad de grado III)." << endl;
    if(IMC>=40)
        cout << "Obesidad m\242rbida (obesidad de grado IV)." << endl;
    cout << "Valor de IMC: " << IMC << endl;
    cout << endl;
    system ("pause");
    return EXIT_SUCCESS;
}

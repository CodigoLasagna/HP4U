#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	float peso{0.0}; float altura{0.0}; float edad{0.0}; float factor_actividad{0.0}; float masa_muscular{0.0};
	float agua{0.0}; float IMC{0.0}; string imcres; float RMR{0.0};
	int genero{0}; float GET{0.0};
	
	cout << "Introduzca su peso en kilogramos: \n>";
	cin >> peso;
	cout << "Introduzca su altura en centimetros\n> ";
	cin >> altura;
	cout << "Introduzca su edad\n>";
	cin >> edad;
	cout << "Introduzca su factor de actividad" << endl;
	cout << "Factores de actividad \n1.2[sedentario] \n1.375[ej 1-3] \n1.55[ej 3-5] \n1.725[ej 6-7]" << endl;
	cout << "[ej] <- dias a la semana\n>";
	cin >> factor_actividad;
	cout << "Introduzca su genero H[0] M[1]\n>";
	cin >> genero;

	altura /= 100;
	
	masa_muscular = (0.000975482 * pow(altura, 2)) + (0.166477 * peso) - 0.05704 * edad - 10.663;
	if (genero) // calcula para hombre
	{
		RMR = 66+(13.6*peso) + (5.0 * altura*100) - (6.8*edad);
	}
	else // calcula para mujer
	{
		RMR = 655+(9.6*peso) + (1.85 * altura*100) - (4.7*edad);
	}
	GET = RMR * factor_actividad;
	IMC = (peso + masa_muscular) / pow(altura, 2);
	
	if (IMC < 18.5)
	{
		imcres = "bajo";
	}
	else if (IMC >= 18.5)
	{
		imcres = "adecuado";
	}
	else if (IMC >= 25)
	{
		imcres = "sobrepeso";
	}
	else if (IMC >= 30)
	{
		imcres = "obesidad grado 1";
	}
	else if (IMC >= 35)
	{
		imcres = "obesidad grado 2";
	}
	else if (IMC >= 40)
	{
		imcres = "obesidad grado cronico";
	}
	
	agua = (35*peso)/1000;
	
	cout << "IMC: " << IMC << ": Peso " << imcres << endl;
	cout << "Agua a consumir: " << agua << "L" << endl;
	cout << "Calorias para mantener el peso en reposo(RMR):" << RMR << endl;
	cout << "calorias a consumir para ganar peso en reposo(RMR) + 500 calorias: " << RMR+500 << endl;
	cout << "calorias necesarias para cumplir las actividades con un factor de " << factor_actividad << " (GET): " << GET << endl;
	cout << "calorias necesarias para subir de peso con un factor de " << factor_actividad << " (GET): " << GET+500 << endl;
	cout << "Las calorias son para asumir el ganar 0.5kg a la semana, consumiendo diariamente" << endl;
	return 0;
}

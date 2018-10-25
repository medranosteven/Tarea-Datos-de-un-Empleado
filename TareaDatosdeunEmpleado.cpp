//Programa hecho por: Jesús Steven Medrano Carballo
//carnet: MC18055

 /*El siguente programa es para mostrar el inventario de los datos de un empleado y
calcular los descuentos de su salario*/

 #include <iostream> //libreria estandar de entrada y salida
#include <iomanip> //Libreria iomanip para utilizar sus funciones
#include <stdlib.h> //Libreria stdlib para utilizar sus funciones
#include <windows.h> //Libreria windows.h para utilizar sus funciones
#include <cstdio> //Libreria cstdio para utilizar sus funciones

 using namespace std; //espacio de nombre a usar std esto nos permite abreviar el codigo
 void cargar(); //Declaracion, funcion que permite dar un tiempo de carga
void errordato(); //Declaracion funcion que evita que se ingrese datos incorrectos

 //structura empleado
struct Empleado{
	
	//Declaracion de variables
	char cod[5];
	char nombre[50];
	int edad;
	float salbase;
	float isss;
	float afp;
	float salliquido;
	float renta;
	float totalprestamo;
	char departamento[60];
	char puesto[60] ;
 };
 
 //estructura sucusal
struct Sucursal{
     ///Declaracion de variables
	int numsucursal;
	char nombresucursal[60];
 };
 float calisss(float sal) //funcion que calcula isss
{   
    //declaracion de variable
	float isss = 0.00;
	
	//se evalua la condicion en caso de que se cumpla se ingresa aqui
	if (sal >= 600.00) 
	{
	    //variable isss almacena el valor de 30.00
        isss = 30.00;
    
        //retorna la variable isss
        return isss;
	
    }
	//si no se cumple ninguna condicion anterior se ingresa aqui
	else {
        
        //variable isss realizara una operacion para obtener el isss
        isss = sal * 0.03;
		
        //retorna la variable isss
        return isss;
    }
	
}
 //crear las funciones para calcular el afp y renta del empleadp
 float calafp (float sal)//funcion que calcula la afp
{
    //declaracion de variable
	float afp = 0.00;
	
	//variable afp realiza una operacion para obtener el afp
	afp = sal * 0.0725;
	
	//retorna la variable afp
	return afp;
}
 float calsl(float sal, float isss, float afp) //funcion que calcula el salario liquido
{
	//declaracion de variable
	float sl = 0.00;
	
	//variable sl realizara una operacion para obtener el salario liquido
	sl = sal - (isss + afp);
	
	//retorna la variable sl
	return sl;
}
 float calrenta(float salliqui) //funcion que calcula la renta
{
    //declaracion de variables
    float renta;
    float sldescuento = 0.00;
    
    //se evalua la condicion en caso de que se cumpla se ingresa aqui
    //Tramo 1
    if(salliqui >= 0.01 && salliqui <= 472.00) {
        
        //retorna la variable salliqui
        return salliqui;
        
    }
    //se evalua la condicion en caso de que se cumpla se ingresa aqui
    //Tramo 2
    else if(salliqui > 472.00 && salliqui <= 895.24) {
        
        //variable sldescuento realizara una operacion necesaria para realizar la operacion renta
        sldescuento = salliqui - 472.00;
        
        //variable renta realizara una operacion para obtener la renta
        renta = (sldescuento * 0.10) + 17.67;
        
        //retorna variable renta
        return renta;
        
    }
    //se evalua la condicion en caso de que se cumpla se ingresa aqui
    //Tramo 3
    else if(salliqui > 895.24 && salliqui <= 2038.10) {
        
        //variable sldescuento realizara una operacion necesaria para realizar la operacion renta
        sldescuento = salliqui - 895.24;
        
        //variable renta realizara una operacion para obtener la renta
        renta = (sldescuento * 0.20) + 60.00;
        
        //retorna variable renta
        return renta;
        
    }
    //si no se cumple ninguna condicion anterio se ingresa aqui
    //Tramo 4
    else {
        
        //variable sldescuento realizara una operacion necesaria para realizar la operacion renta
        sldescuento = salliqui - 2038.10;
        
        //variable renta realizara una operacion para obtener la renta
        renta = (sldescuento * 0.30) + 288.57;
        
        //retorna variable renta
        return renta;
        
    }
    	
}
 //funcion que calcula el prestamo total del empleado
float totalprestamo(float salbase, float m)
{
    //declaracion de variable
    float prestamo;
    
    //operacion para determinar el %20 del prestamo del salario
    prestamo = salbase * 0.20;
    
    //se evaluara la condicion en caso de que se cumpla se ingresa aqui
    if(m <= prestamo)
    {
        //retorna variable m
        return m;
    }
    //si no se cumple ninguna condicion anterio se ingresa aqui
    else
    {
        cout << "El monto ingresado excede el limite establecido" << endl;
        m = 0.00;
        //retorna variable m
        return m;
    }
        
}
 //cuerpo principal
int main()
{ 
    //declaracion de variables
	int n;
	Sucursal s;
	float monto;
	
	//funcion que le dara un color al fondo y letra de la consola
	system("color 5B");
	
	//ciclo do-while para evitar el 0 o numeros negativos
	do {
        
        system("cls"); // funcion system("cls") limpia la pantalla
        
        cout << "\n\t\t\t\t**********************************\n";
        cout << "\t\t\t\t* Inventario de los empleados/as *\n";
        cout << "\t\t\t\t**********************************\n\n";
        
        cout << "\n\t\t\t\t\tADVERTENCIA\n";
        cout << "\t\t\t\tEn caso de ingresar un dato\n";
        cout << "\t\t\t\terroneo se volveran a pedir \n";
        cout << "\t\t\t\tnuevamente los datos\n\n";
        
        //funcion que limpia el bueffer
        fflush(stdin);
        cout << "\n\t\t\t\tIngrese el nombre de la sucursal: "; //se ingresa el numero de empleados
        cin.getline(s.nombresucursal, 60);
		errordato(); //Funcion que se utiliza para evitar errores de datos
        
        fflush(stdin);
        cout << "\n\t\t\t\tIngrese el numero de la sucursal: "; //se ingresa el numero de empleados
        cin >> s.numsucursal;
		errordato(); //Funcion que se utiliza para evitar errores de datos
        
        //funcion que limpia el bueffer
        fflush(stdin);
        cout << "\n\t\t\t\tIngrese el numero de empleados: "; //se ingresa el numero de empleados
        cin >> n;
		errordato(); //Funcion que se utiliza para evitar errores de datos
    
    } while(n <= 0 || s.numsucursal <= 0);
	
	//varaible diminsional e de tipo struct
	Empleado e[n];
	
	//ciclo for en el que se ingresara los datos del empleado
    for (int i = 0; i < n; i++)
	{
        //ciclo do-while para evitar el 0 o numeros negativos
        do {
            
            system("cls"); // funcion system("cls") limpia la pantalla
            
            cout << "Empleado " << i + 1 << "\n\n";
            
            //funcion que limpia el bueffer
		    fflush(stdin);
            
    		cout << "Codigo: ";
    		cin >> e[i].cod;//se ingresa el codigo del empleado
    		errordato(); //Funcion que se utiliza para evitar errores de datos
    		
    		//funcion que limpia el bueffer
	       	fflush(stdin);
    		
    		cout << "Nombre: ";
    		cin.getline(e[i].nombre, 50); //se ingresa el nombre del empleado    		
    		errordato(); //Funcion que se utiliza para evitar errores de datos
    		
    		//funcion que limpia el bueffer
		    fflush(stdin);
    		
    		cout << "Edad: ";
    		cin >> e[i].edad; //se ingresa la edad del empleado
    		errordato(); //Funcion que se utiliza para evitar errores de datos
		      
		    //funcion que limpia el bueffer
		    fflush(stdin);
		      
            cout << "Salario base: $";
    		cin >> e[i].salbase;//se ingresa el salario base del empleado
			errordato(); //Funcion que se utiliza para evitar errores de datos
            
            //funcion que limpia el bueffer
    	    fflush(stdin);
    	   
        	cout << "Departamento: ";
        	cin.getline(e[i].departamento,60); //se ingresa el departamento del empleado
        	//Funcion que se utiliza para evitar errores de datos
        	errordato();
        	   
        	//funcion que limpia el bueffer
        	fflush(stdin);
        	   
        	cout << "Puesto: ";
        	cin.getline(e[i].puesto, 60); //se ingresa el puesto del empleado
        	//Funcion que se utiliza para evitar errores de datos
        	errordato();
        	
        	//funcion que limpia el bueffer
    	    fflush(stdin);
                
    		cout << "Monto para el prestamo: $";
    		cin >> monto;
    		//Funcion que se utiliza para evitar errores de datos
    		errordato();
    	   
        } while(e[i].salbase <= 0 || e[i].edad <= 0);
		
		//funcion que calcula el isss
		e[i].isss = calisss(e[i].salbase);
         //funcion que calcula el afp
		e[i].afp = calafp(e[i].salbase);
		
		//funcion que calcula el salario liquido
		e[i].salliquido = calsl(e[i].salbase, e[i].isss, e[i].afp);
		
		//funcion que calcula la renta
		e[i].renta = calrenta(e[i].salliquido);
		
		//funcion que calcula el prestamo total
		e[i].totalprestamo = totalprestamo(e[i].salbase, monto);
        
        cout << "\n\n";
        
        //system("pause detendra el programa hasta que el usuario presione una tecla")
        system("pause");	
	   
	}
	
	system("cls"); // funcion system("cls") limpia la pantalla
	
	//ciclo for que mostrara los resultados
	for(int i=0; i<n;i++)
	{
        
        //Funcion cargar para dar un tiempo de carga antes de continuar 
        cargar();
            
        //El caracter'\a' nos permite generar un sonido de campanilla
		cout << '\a';   
        
        cout << "\n\n\tSucursal " << s.nombresucursal << " #" << s.numsucursal << "\n\n";
        
        //Se imprime el resultado
        //la funcion fixed y setprecision son utilizadas para redondear los decimales a 2
        
        cout << "\tEmpleado " << i + 1 << "\n\n";
        
        cout << "\t\tCodigo: " << e[i].cod << endl;
        cout << "\t\tNombre: " << e[i].nombre << endl;
        cout << "\t\tEdad: " << e[i].edad << endl;
        cout << "\t\tDepartamento: " << e[i].departamento << endl;
        cout << "\t\tPuesto: " << e[i].puesto << endl;
        cout << "\t\tSalario base: $" << fixed << setprecision(2) << e[i].salbase << endl;
        cout << "\t\tIsss: $" << fixed << setprecision(2) << e[i].isss << endl;
        cout << "\t\tAfp: $" << fixed << setprecision(2) << e[i].afp << endl;
        cout << "\t\tSalario liquido: $" << fixed << setprecision(2) << e[i].salliquido << endl;
        cout << "\t\tRenta: $" << fixed << setprecision(2) << e[i].renta << endl;
        cout << "\t\tPrestamo total: $" << fixed << setprecision(2) << e[i].totalprestamo << endl;
        
		cout << endl; 
		
	}
	
	//system("pause detendra el programa hasta que el usuario presione una tecla")
	system("Pause");
	//No retorna ningun valor
	return 0;
}
 //funcion que permite dar un tiempo de carga
void cargar()
{
	
	//Variable cargar servira como contador
	int carga = 1;
	
	cout << "\nEl programa esta cargando" << endl;
	
	//ciclo while para generar un tiempo de carga
	do {
		//Funcion Sleep para permite generar un tiempo de carga
		Sleep(1400);
	
		cout << "....";  
		
		//Variable carga se utiliza como contador
		carga++;
	
	} while (carga < 4);
}
 //funcion que evita que se ingrese datos incorrectos
void errordato()
{
		//Ciclo while para evitar datos incorrectos
		while(cin.fail()){
		
		//Limpia el buffer de los datos ingresados
		cin.clear();
		
		//Ignora los primeros 1000 caracteres o en este caso los numeros
		cin.ignore(1000,'\n');
		
		}
}

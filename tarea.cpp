#include <iostream> //Habilita funciones de entrada y salida
#include <fstream> //Habilita la opcion de abrir, leer y escribir archivos
#include <string> //Permite declarar y manipular variables de tipo string
#include <vector> //Permite el uso de vectores (estructuras)
#include <limits> // Proporciona informacion sobre limites de los tipos de datos

using namespace std;  

// Estructura del registro
struct Producto {
    string nombre;
    string codigo; 
    double precio; //Para un dato tipo real puede utilizarse: float, double o long double
    string proveedor;
    int existencia;
    char estado;
    double descuento;  
};

// Función para agregar un producto
void agregarProducto(vector<Producto>& productos) {
    Producto producto;
    cout << "Ingrese nombre del producto: ";
    cin.ignore();   //Limpia bufer de entrada 
    getline(cin, producto.nombre);
    cout << "Ingrese codigo del producto: ";
    getline(cin, producto.codigo);

    for (const Producto& p : productos) {
        if (p.codigo == producto.codigo) {
            cout << "Codigo ya existente." << endl;
            return;
        }
    }

    cout << "Ingrese precio del producto: ";
    cin >> producto.precio;
    cout << "Ingrese proveedor del producto: ";
    cin.ignore();
    getline(cin, producto.proveedor);
    cout << "Ingrese la cantidad de existencias del producto: ";
    cin >> producto.existencia;
    cout << "Seleccione el estado del producto (A = Aprobado, R = Reprobado): ";
    cin >> producto.estado;
    cout << "Descuento del producto: ";
    cin >> producto.descuento;
    productos.push_back(producto);  //Agrega el producto ingresado al vector *producto
    cout << "                            " << endl;
    cout << "Producto agregado!." << endl;
    cout << "                     " << endl;
}

// Función para busqueda de producto
void buscarProducto(const vector<Producto>& productos, const string& criterio) { //realiza la busqueda en el vector producto
    bool encontrado = false;  //Inicializa una variable booleana
    for (const Producto& producto : productos) {
        if (producto.codigo == criterio || producto.nombre.find(criterio) != string::npos) { //verifica
        //si el codigo o el nombre del producto coincide con el criterio de busqueda
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Codigo: " << producto.codigo << endl;
            cout << "Precio: " << producto.precio << endl;
            cout << "Proveedor: " << producto.proveedor << endl;
            cout << "Existencia: " << producto.existencia << endl;
            cout << "Estado: " << producto.estado << endl;
            cout << "Descuento: " << producto.descuento << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {  //Verifica si la variable *encontrado sigue seindo falsa 
        cout << "Producto no encontrado." << endl;
    }
}

// Función para modificar datos de un producto
void modificarProducto(vector<Producto>& productos, const string& codigo) { //Activa la funcion de modificar producto
//segun los argumentos: producto y codigo
    for (Producto& producto : productos) {  //Inicia un buble for, el bucle utiliza una referencia "&" que permite modificar los productos
    //directamente del vector
        if (producto.codigo == codigo) {
            cout << " Ingrese el nuevo nombre: ";
            cin.ignore();
            getline(cin, producto.nombre);
            cout << "Ingrese el nuevo precio: ";
            cin >> producto.precio;
            cout << "Ingrese el nuevo proveedor: ";
            cin.ignore();
            getline(cin, producto.proveedor);
            cout << "Ingrese la nueva existencia: ";
            cin >> producto.existencia;
            cout << "Valide el estado (A = Aprobado, R = Reprobado): ";
            cin >> producto.estado;
            cout << "Valide el nuevo descuento: ";
            cin >> producto.descuento;
            cout << "Datos modificados correctamente." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

// Función para guardar los productos 
void guardarProductos(const vector<Producto>& productos) {
    ofstream archivo("productosc.txt"); //Abre un archivo llamado "productos" en modo escritura
    if (archivo.is_open()) { //comprueba si el archivo se ha abierto correctamente
        for (const Producto& producto : productos) {
            archivo << producto.nombre << '\n' << producto.codigo << '\n' << producto.precio << '\n'
                    << producto.proveedor << '\n' << producto.existencia << '\n' << producto.estado << '\n'
                    << producto.descuento << '\n';
                    archivo << '\n';
        }
        archivo.close(); //cierra el archivo "productos" despues de haber terminado de escribir todos los datos
    } else {
        cout << "No se pudo abrir el archivo!!" << endl;
    }
}

// Función para cargar los productos desde un archivo
void cargarProductos(vector<Producto>& productos) {
    ifstream archivo("productosc.txt");
    if (archivo.is_open()) {
        Producto producto;
        while (getline(archivo, producto.nombre) && getline(archivo, producto.codigo) &&
               archivo >> producto.precio >> ws &&
               getline(archivo, producto.proveedor) && archivo >> producto.existencia >> ws &&
               archivo.get(producto.estado) && archivo >> producto.descuento >> ws) {
            productos.push_back(producto);
        }
        archivo.close();
    }
}

int main() {
    vector<Producto> productos;
    cargarProductos(productos);

int opcion = 0;
    while (opcion != 4) {

        cout << "\nMenu:" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Buscar producto" << endl;
        cout << "3. Modificar datos de un producto" << endl;
        cout << "4. Salir" << endl;
        cout << "        " << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cout << "    " << endl;

        //Validacion del dato de entrada (valida que sea un numero)
        if (cin.fail()) { 
        cin.clear();                 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
        cout << "Error, ingrese un valor valido." << endl;
        continue;  // Vuelve al principio del bucle
        }
        
         else if (opcion == 1) {
            agregarProducto(productos);

        } else if (opcion == 2) {
            cin.ignore();
            cout << "Ingresa el codigo o nombre que desea buscar: " << endl;
            string criterio;
            getline(cin, criterio);
            buscarProducto(productos, criterio);

            cout << " " << endl;

        
        } else if (opcion == 3) {
            cin.ignore();
            cout << "Ingresa el codigo del producto que desea modificar: ";
            string codigo;
            getline(cin, codigo);
            modificarProducto(productos, codigo);
        
        } else if (opcion == 4) {
            guardarProductos(productos);
            cout << "Guardando cambios. Cerrando programa" << endl;
        
        } else {
            cout << "Error. Seleccione una opcion valida." << endl;
        }
    }

    return 0;

    
}

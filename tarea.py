class Producto:
    def __init__(self):
        self.nombre = ""
        self.codigo = ""
        self.precio = 0.0
        self.proveedor = ""
        self.existencia = 0
        self.estado = ""
        self.descuento = 0.0

def agregarProducto(productos):
    producto = Producto()
    print("Ingrese nombre del producto: ")
    producto.nombre = input()
    print("Ingrese codigo del producto: ")
    producto.codigo = input()

    for p in productos:
        if p.codigo == producto.codigo:
            print("Codigo ya existente.")
            return

    print("Ingrese precio del producto: ")
    producto.precio = float(input())
    print("Ingrese proveedor del producto: ")
    producto.proveedor = input()
    print("Ingrese la cantidad de existencias del producto: ")
    producto.existencia = int(input())
    print("Seleccione el estado del producto (A = Aprobado, R = Reprobado): ")
    producto.estado = input()
    print("Descuento del producto: ")
    producto.descuento = float(input())
    productos.append(producto)
    print("Producto agregado!")

def buscarProducto(productos, criterio):
    encontrado = False
    for producto in productos:
        if producto.codigo == criterio or criterio in producto.nombre:
            print("Nombre:", producto.nombre)
            print("Codigo:", producto.codigo)
            print("Precio:", producto.precio)
            print("Proveedor:", producto.proveedor)
            print("Existencia:", producto.existencia)
            print("Estado:", producto.estado)
            print("Descuento:", producto.descuento)
            encontrado = True
    if not encontrado:
        print("Producto no encontrado.")

def modificarProducto(productos, codigo):
    for producto in productos:
        if producto.codigo == codigo:
            print("Ingrese el nuevo nombre: ")
            producto.nombre = input()
            print("Ingrese el nuevo precio: ")
            producto.precio = float(input())
            print("Ingrese el nuevo proveedor: ")
            producto.proveedor = input()
            print("Ingrese la nueva existencia: ")
            producto.existencia = int(input())
            print("Valide el estado (A = Aprobado, R = Reprobado): ")
            producto.estado = input()
            print("Valide el nuevo descuento: ")
            producto.descuento = float(input())
            print("Datos modificados correctamente.")
            return
    print("Producto no encontrado.")

def guardarProductos(productos):
    with open("productospy.txt", "w") as archivo:
        for producto in productos:
            archivo.write(f"{producto.nombre}\n{producto.codigo}\n{producto.precio}\n"
                          f"{producto.proveedor}\n{producto.existencia}\n{producto.estado}\n"
                          f"{producto.descuento}\n\n")

def cargarProductos(productos):
    try:
        with open("productospy.txt", "r") as archivo:
            lines = archivo.read().splitlines()
            for i in range(0, len(lines), 8):
                producto = Producto()
                producto.nombre = lines[i]
                producto.codigo = lines[i + 1]
                producto.precio = float(lines[i + 2])
                producto.proveedor = lines[i + 3]
                producto.existencia = int(lines[i + 4])
                producto.estado = lines[i + 5]
                producto.descuento = float(lines[i + 6])
                productos.append(producto)
    except FileNotFoundError:
        pass

def main():
    productos = []
    cargarProductos(productos)

    opcion = 0
    while opcion != 4:
        print("\nMenu:")
        print("1. Agregar producto")
        print("2. Buscar producto")
        print("3. Modificar datos de un producto")
        print("4. Salir")
        print("  ")
        opcion = int(input("Selecciona una opcion: "))
        print("  ")
        
        if opcion == 1:
            agregarProducto(productos)
        elif opcion == 2:
            print("Ingresa el codigo o nombre que deseas buscar: ")
            criterio = input()
            buscarProducto(productos, criterio)
        elif opcion == 3:
            print("Ingresa el codigo del producto que deseas modificar: ")
            codigo = input()
            modificarProducto(productos, codigo)
        elif opcion == 4:
            guardarProductos(productos)
            print("Guardando cambios. Cerrando programa")
        else:
            print("Error. Seleccione una opcion valida.")

if __name__ == "__main__":
    main()
#include <iostream>
#include <cstring>

// Definición de la estructura Alumno
struct Alumno {
    char nombre[100];
    int creditosAprobados;
    int semestreEquivalente;
};

struct Nodo {
    Alumno alumno;
    Nodo* siguiente;
};

Alumno crearAlumno(const char* nombre, int creditos, int semestre) {
    Alumno alumno;
    strcpy(alumno.nombre, nombre);
    alumno.creditosAprobados = creditos;
    alumno.semestreEquivalente = semestre;
    return alumno;
}

// Función para imprimir los datos de un alumno
void imprimirAlumno(const Alumno& alumno) {
    std::cout << "Nombre: " << alumno.nombre << std::endl;
    std::cout << "Creditos Aprobados: " << alumno.creditosAprobados << std::endl;
    std::cout << "Semestre Equivalente: " << alumno.semestreEquivalente << std::endl;
}

Nodo* crearNodo(const Alumno& alumno) {
    Nodo* nodo = new Nodo;
    nodo->alumno = alumno;
    nodo->siguiente = nullptr;
    return nodo;
}

int insertarNodoOrdenadoCredito(Nodo** cabeza, Nodo* nuevoNodo) {
    if (*cabeza == nullptr || (*cabeza)->alumno.creditosAprobados <= nuevoNodo->alumno.creditosAprobados) {
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
        return 0;
    }
    Nodo* actual = *cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->alumno.creditosAprobados > nuevoNodo->alumno.creditosAprobados) {
        actual = actual->siguiente;
    }
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    return 0;
}

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        imprimirAlumno(actual->alumno);
        std::cout << "-------------------------" << std::endl;
        actual = actual->siguiente;
    }
}

int main() {
    // Crear 5 calificaciones de la estructura Alumno
    Alumno alumno1 = crearAlumno("Eduardo Gonzalez", 120, 5);
    Alumno alumno2 = crearAlumno("Luis Gonzalez", 90, 4);
    Alumno alumno3 = crearAlumno("Ricardo Cervera", 150, 6);
    Alumno alumno4 = crearAlumno("Pedro Rios", 80, 3);
    Alumno alumno5 = crearAlumno("Franco Cen", 110, 5);

    Nodo* lista = nullptr;
    insertarNodoOrdenadoCredito(&lista, crearNodo(alumno1));
    insertarNodoOrdenadoCredito(&lista, crearNodo(alumno2));
    insertarNodoOrdenadoCredito(&lista, crearNodo(alumno3));
    insertarNodoOrdenadoCredito(&lista, crearNodo(alumno4));
    insertarNodoOrdenadoCredito(&lista, crearNodo(alumno5));

    imprimirLista(lista);

    return 0;
}

#include "foo.h"

Matriz2D::Matriz2D(): filas(3), columnas(3){
// Crear matriz dinamica (ptr) de n fila
    
        ptr = new float*[filas];

        // Crear cada fila de la matriz dinamica (ptr) de m columnas
        for(int i = 0; i < filas; i++){
            ptr[i] = new float[columnas];
        }

        // Inicializar la matriz dinamica (ptr) con numeros aleatorios entre 0 y 1
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                float random = round((float)(rand()/(float)RAND_MAX)*100)/100;

                ptr[i][j] = random;
            }
        }    
}

Matriz2D::Matriz2D(int n): filas(n),columnas(n){
    // Constructor con un parametro
    ptr = new float*[n];
    for(int i = 0; i < n; i++){
        ptr[i] = new float[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            float random = round((float)(rand()/(float)RAND_MAX)*100)/100; // random con 2 decimales

            ptr[i][j] = random;
        }
}
    }

Matriz2D::Matriz2D(int n, int m): filas(n),columnas(m){
    ptr = new float*[n];

    // Crear cada fila de la matriz dinamica (ptr) de m columnas
    for(int i = 0; i < n; i++){
        ptr[i] = new float[m];
    }

    // Inicializar la matriz dinamica (ptr) con numeros aleatorios entre 0 y 1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            float random = round((float)(rand()/(float)RAND_MAX)*100)/100;

            ptr[i][j] = random;
        }
    }   
}

Matriz2D::Matriz2D(const Matriz2D& m): filas(m.filas),columnas(m.columnas){
    // Constructor de copia
    ptr = new float*[filas];
    for (int i = 0; i < filas; i++){
            ptr[i] = new float[columnas];
    }
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            ptr[i][j] = m.ptr[i][j];
        }
    }

}

Matriz2D::Matriz2D(Matriz2D&& m): filas(m.filas), columnas(m.columnas), ptr(m.ptr){
    m.filas = 0;
    m.columnas = 0;
    m.ptr = nullptr;
    
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D tr(m.getFilas(),m.getColumnas());
    for(int i = 0; i<tr.getFilas();i++){
        for(int j = 0; j<tr.getColumnas();j++){
            tr.ptr[i][j] = m.ptr[j][i];
        }

    }
    return tr;

}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            os << m.ptr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    if(m1.filas != m2.filas || m1.columnas != m2.columnas){
        cout<<"no se puede sumar la matriz"<<endl;

    }
        Matriz2D resultado(m1.filas,m1.columnas);
        for (int i = 0; i < m1.filas; i++) {
            for (int j = 0; j < m1.columnas; j++) {
                resultado.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
            }
        }
    return resultado;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    if(m1.filas != m2.filas || m1.columnas != m2.columnas){
        cout<<"no se puede restar la matriz"<<endl;

    }
    Matriz2D resultado(m1.filas,m1.columnas);
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m1.columnas; j++) {
            resultado.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
        }
    }
    return resultado;

}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    if(m1.columnas != m2.filas){
        cout<<"No se pueden multiplicar las matrices";
    }
    Matriz2D resultado(m1.filas,m2.columnas);
    for(int i = 0; i<m1.filas;i++){
        for(int j = 0; j<m2.columnas;j++){
            float prod = 0;
            for(int k = 0; k<m1.columnas;k++){
                prod += m1.ptr[i][k] * m2.ptr[k][j];
            }
            resultado.ptr[i][j] = prod;
        }
    }
    return resultado;
}

Matriz2D operator+(const Matriz2D& m, float n) {
    Matriz2D resultado(m.filas, m.columnas);

    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            resultado.ptr[i][j] = m.ptr[i][j] + n;
        }
    }

    return resultado;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D resultado(m.filas, m.columnas);

    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            resultado.ptr[i][j] = m.ptr[i][j] - n;
        }
    }

    return resultado;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D resultado(m.filas, m.columnas);

    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            resultado.ptr[i][j] = m.ptr[i][j] - n;
        }
    }

    return resultado;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    // Sobrecarga del operador -
    Matriz2D resultado(m.filas, m.columnas);

    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            resultado.ptr[i][j] = m.ptr[i][j] / n;
        }
    }

    return resultado;
}

Matriz2D& Matriz2D::operator=(const Matriz2D& m) {
    if (this == &m) {
        return *this;  // Check for self-assignment
    }

    // Deallocate current memory
    for (int i = 0; i < filas; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;

    // Allocate new memory for the copy
    filas = m.filas;
    columnas = m.columnas;
    ptr = new float*[filas];
    for (int i = 0; i < filas; i++) {
        ptr[i] = new float[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            ptr[i][j] = m.ptr[i][j];
        }
    }

    return *this;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}





#include <iostream>

extern "C" int calcularProbabilidad(int unidadDeTiempo,int probabilidad,int correccion,int desecho);

int main(){
    int prob = calcularProbabilidad(2,40,5,3);

    switch(prob){
        case 0:
            std::cout << "No hay error" << std::endl;
            break;
        case 1:
            std::cout << "Correccion" << std::endl;
            break;
        case 2:
            std::cout << "Desecho" << std::endl;
            break;
        default:
            break;
    }

    return 0;
}
#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

extern "C" int calcularProbabilidad(int unidadDeTiempo,int probabilidad,int correccion,int desecho);

int etapa(int unidadDeTiempo,int probabilidad,int correccion,int desecho){
    int p = calcularProbabilidad(unidadDeTiempo,probabilidad,correccion,desecho);
    return p;
}

void cadena(int n){
    for(int i=0;i<5;i++){
        auto t1 = Clock::now();

        int etapaStat = etapa(1,80,4,2);
        
        std::string head = "Cadena: " + std::to_string(n) + " | Etapa: " + std::to_string(i) + "\n";
        switch(etapaStat){
            case 0:
                std::cout << head+"No hay error" << std::endl;
                break;
            case 1:
                std::cout << head+"Correccion" << std::endl;
                break;
            case 2:
                std::cout << head+"Desecho" << std::endl;
                break;
        }
        auto t2 = Clock::now();
        std::cout << "Tiempo: "  << (int)(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1e+9) << std::endl;
        std::cout << std::endl;
    }
}

int main(){
    for(int i=0;i<3;i++){
        std::thread t(cadena,i);
        t.detach();
    }
    
    std::cin.get();
    return 0;
}
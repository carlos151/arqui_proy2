 #include <gtkmm.h>
 #include <iostream>
 #include <thread>
 #include <chrono>
#include <fstream>

typedef std::chrono::high_resolution_clock Clock;

 extern "C" int calcularProbabilidad(int unidadDeTiempo,int probabilidad,int correccion,int desecho);

class App : public Gtk::Window
{
    public:
        App() : startProgram("Comenzar")
        {
            label1.set_text("Unidad de tiempo (segundos)");
            correccionLabel.set_text("Tiempo de corrección (segundos)");
            desechoLabel.set_text("Tiempo de desecho (segundos)");
            etapa1.set_text("Coccion");
            etapa2.set_text("Limpieza");
            etapa3.set_text("Enaltado");
            etapa4.set_text("Esterilizacion");
            etapa5.set_text("Empaque");
            porcentajes.set_text("Porcentajes de error por etapa");

            set_default_size(1000, 800);
            set_title("Fabrica de atun");
            set_position(Gtk::WIN_POS_CENTER);
            set_border_width(10);

            //Ajustes de labels
            correccionLabel.set_margin_left(12);
            desechoLabel.set_margin_left(12);

            porcentajes.set_margin_top(30);

            etapa1.set_margin_top(30);
            etapa2.set_margin_top(30);
            etapa3.set_margin_top(30);
            etapa4.set_margin_top(30);
            etapa5.set_margin_top(30);

            //Ajustes de entries
            entry1.set_margin_left(12);
            correccionEntry.set_margin_left(12);
            desechoEntry.set_margin_left(12);

            error1.set_margin_top(30);
            error2.set_margin_top(30);
            error3.set_margin_top(30);
            error4.set_margin_top(30);
            error5.set_margin_top(30);

            error2.set_margin_left(12);
            error3.set_margin_left(12);
            error4.set_margin_left(12);
            error5.set_margin_left(12);

            //Ajustes de buttons
            startProgram.set_margin_top(30);
            startProgram.set_margin_left(12);

            startProgram.signal_clicked().connect(
                sigc::mem_fun(*this,&App::onClick)
            );

            etapa1_1.set_margin_top(50);
            etapa1_2.set_margin_top(50);
            etapa1_3.set_margin_top(50);
            etapa2_1.set_margin_top(50);
            etapa2_2.set_margin_top(50);
            etapa2_3.set_margin_top(50);
            etapa3_1.set_margin_top(50);
            etapa3_2.set_margin_top(50);
            etapa3_3.set_margin_top(50);
            etapa4_1.set_margin_top(50);
            etapa4_2.set_margin_top(50);
            etapa4_3.set_margin_top(50);
            etapa5_1.set_margin_top(50);
            etapa5_2.set_margin_top(50);
            etapa5_3.set_margin_top(50);

            etapa2_1.set_margin_left(12);
            etapa2_2.set_margin_left(12);
            etapa2_3.set_margin_left(12);
            etapa3_1.set_margin_left(12);
            etapa3_2.set_margin_left(12);
            etapa3_3.set_margin_left(12);
            etapa4_1.set_margin_left(12);
            etapa4_2.set_margin_left(12);
            etapa4_3.set_margin_left(12);
            etapa5_1.set_margin_left(12);
            etapa5_2.set_margin_left(12);
            etapa5_3.set_margin_left(12);

            
            
            //Poner widgets en el grid

            //Row 1
            grid.attach(label1,0,0,1,1);
            grid.attach(entry1,1,0,1,1);
            grid.attach(correccionLabel,2,0,1,1);
            grid.attach(correccionEntry,3,0,1,1);
            grid.attach(desechoLabel,4,0,1,1);
            grid.attach(desechoEntry,5,0,1,1);

            //Row 2
            grid.attach(porcentajes,2,1,1,1);
            grid.attach(startProgram,3,1,1,1);

            //Row 3
            grid.attach(error1,0,2,1,1);
            grid.attach(error2,1,2,1,1);
            grid.attach(error3,2,2,2,1);
            grid.attach(error4,4,2,1,1);
            grid.attach(error5,5,2,1,1);

            //Row 4
            grid.attach(etapa1,0,3,1,1);
            grid.attach(etapa2,1,3,1,1);
            grid.attach(etapa3,2,3,2,1);
            grid.attach(etapa4,4,3,1,1);
            grid.attach(etapa5,5,3,1,1);

            //Row 5
            grid.attach(etapa1_1,0,4,1,2);
            grid.attach(etapa2_1,1,4,1,2);
            grid.attach(etapa3_1,2,4,2,2);
            grid.attach(etapa4_1,4,4,1,2);
            grid.attach(etapa5_1,5,4,1,2);


            //Row 7
            grid.attach(etapa1_2,0,6,1,2);
            grid.attach(etapa2_2,1,6,1,2);
            grid.attach(etapa3_2,2,6,2,2);
            grid.attach(etapa4_2,4,6,1,2);
            grid.attach(etapa5_2,5,6,1,2);

            //Row 9
            grid.attach(etapa1_3,0,8,1,2);
            grid.attach(etapa2_3,1,8,1,2);
            grid.attach(etapa3_3,2,8,2,2);
            grid.attach(etapa4_3,4,8,1,2);
            grid.attach(etapa5_3,5,8,1,2);

            add(grid);

            show_all_children();

        }

    //private:
        void onClick(){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::thread t(startProgramOnClick,this);
            t.detach();
        }

        void static startProgramOnClick(App *window){
            int unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho;
            try{
                unidad = std::stoi(window->entry1.get_text());
                porcentaje1 = std::stoi(window->error1.get_text());
                porcentaje2 = std::stoi(window->error2.get_text());
                porcentaje3 = std::stoi(window->error3.get_text());
                porcentaje4 = std::stoi(window->error4.get_text());
                porcentaje5 = std::stoi(window->error5.get_text());
                correccion = std::stoi(window->correccionEntry.get_text());
                desecho = std::stoi(window->desechoEntry.get_text());
            }catch(std::exception e){
                std::cout << "ENTRADA INVALIDA" << std::endl;
                return;
            }
            window->start(unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho);
        }

        int prob(int unidad,int porcentaje,int correccion,int desecho){
            return calcularProbabilidad(unidad,porcentaje,correccion,desecho);
        }

        void etapa5Run(int unidad,int porcentaje1,int porcentaje2,int porcentaje3,int porcentaje4,int porcentaje5,int correccion,int desecho){
            int error=0;
            auto t1 = Clock::now();
            switch(cola5){
                case 0:
                    cola5++;
                    etapa5_1.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje5,correccion,desecho);
                    etapa5_1.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola5--;
                    break;
                case 1:
                    cola5++;
                    etapa5_2.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje5,correccion,desecho);
                    etapa5_2.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola5--;
                    break;
                case 2:
                    cola5++;
                    etapa5_3.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje5,correccion,desecho);
                    etapa5_3.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola5--;
                    break;
            }
            switch(error){
                        case 0:
                            histograma << "Etapa 5:No hay error" << std::endl;
                            break;
                        case 1:
                            histograma << "Etapa 5:Correccion" << std::endl;
                            break;
                        case 2:
                            histograma << "Etapa 5:Desecho" << std::endl;
                            break;
                    }
                    auto t2 = Clock::now();
            histograma << "Tiempo: " << (int)(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1e+9) << std::endl;
        }

        void etapa4Run(int unidad,int porcentaje1,int porcentaje2,int porcentaje3,int porcentaje4,int porcentaje5,int correccion,int desecho){
            int error=0;
            auto t1 = Clock::now();
            switch(cola4){
                case 0:
                    cola4++;
                    etapa4_1.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje4,correccion,desecho);
                    etapa4_1.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola4--;
                    break;
                case 1:
                    cola4++;
                    etapa4_2.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje4,correccion,desecho);
                    etapa4_2.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola4--;
                    break;
                case 2:
                    cola4++;
                    etapa4_3.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje4,correccion,desecho);
                    etapa4_3.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola4--;
                    break;
            }
            switch(error){
                        case 0:
                            histograma << "Etapa 4:No hay error" << std::endl;
                            break;
                        case 1:
                            histograma << "Etapa 4:Correccion" << std::endl;
                            break;
                        case 2:
                            histograma << "Etapa 4:Desecho" << std::endl;
                            break;
                    }
                    auto t2 = Clock::now();
            histograma << "Tiempo: " << (int)(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1e+9) << std::endl;
            etapa5Run(unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho);
        }

        void etapa3Run(int unidad,int porcentaje1,int porcentaje2,int porcentaje3,int porcentaje4,int porcentaje5,int correccion,int desecho){
            int error=0;
            auto t1 = Clock::now();
            switch(cola3){
                case 0:
                    cola3++;
                    etapa3_1.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje3,correccion,desecho);
                    etapa3_1.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola3--;
                    break;
                case 1:
                    cola3++;
                    etapa3_2.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje3,correccion,desecho);
                    etapa3_2.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola3--;
                    break;
                case 2:
                    cola3++;
                    etapa3_3.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje3,correccion,desecho);
                    etapa3_3.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola3--;
                    break;
            }
            switch(error){
                        case 0:
                            histograma << "Etapa 3:No hay error" << std::endl;
                            break;
                        case 1:
                            histograma << "Etapa 3:Correccion" << std::endl;
                            break;
                        case 2:
                            histograma << "Etapa 3:Desecho" << std::endl;
                            break;
                    }
                    auto t2 = Clock::now();
            histograma << "Tiempo: " << (int)(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1e+9) << std::endl;
            etapa4Run(unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho);
        }

        void etapa2Run(int unidad,int porcentaje1,int porcentaje2,int porcentaje3,int porcentaje4,int porcentaje5,int correccion,int desecho){
            int error=0;
            auto t1 = Clock::now();
            switch(cola2){
                case 0:
                    cola2++;
                    etapa2_1.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje2,correccion,desecho);
                    etapa2_1.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola2--;
                    break;
                case 1:
                    cola2++;
                    etapa2_2.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje2,correccion,desecho);
                    etapa2_2.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola2--;
                    break;
                case 2:
                    cola2++;
                    etapa2_3.override_background_color(Gdk::RGBA("red"));
                    show_all_children();
                    error = prob(unidad,porcentaje2,correccion,desecho);
                    etapa2_3.override_background_color(Gdk::RGBA("white"));
                    show_all_children();
                    cola2--;
                    break;
            }
            switch(error){
                        case 0:
                            histograma << "Etapa 2:No hay error" << std::endl;
                            break;
                        case 1:
                            histograma << "Etapa 2:Correccion" << std::endl;
                            break;
                        case 2:
                            histograma << "Etapa 2:Desecho" << std::endl;
                            break;
                    }
                    auto t2 = Clock::now();
            histograma << "Tiempo: " << (int)(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1e+9) << std::endl;
            etapa3Run(unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho);
        }

        void static etapa1Run(App *window,int unidad,int porcentaje1,int porcentaje2,int porcentaje3,int porcentaje4,int porcentaje5,int correccion,int desecho){
            int error=0;
            auto t1 = Clock::now();
            switch(window->cola1){
                case 0:
                    window->cola1++;
                    window->etapa1_1.override_background_color(Gdk::RGBA("red"));
                    window->show_all_children();
                    error = window->prob(unidad,porcentaje1,correccion,desecho);
                    window->etapa1_1.override_background_color(Gdk::RGBA("white"));
                    window->show_all_children();
                    window->cola1--;
                    break;
                case 1:
                    window->cola1++;
                    window->etapa1_2.override_background_color(Gdk::RGBA("red"));
                    window->show_all_children();
                    error = window->prob(unidad,porcentaje1,correccion,desecho);
                    window->etapa1_2.override_background_color(Gdk::RGBA("white"));
                    window->show_all_children();
                    window->cola1--;
                    break;
                case 2:
                    window->cola1++;
                    window->etapa1_3.override_background_color(Gdk::RGBA("red"));
                    window->show_all_children();
                    error = window->prob(unidad,porcentaje1,correccion,desecho);
                    window->etapa1_3.override_background_color(Gdk::RGBA("white"));
                    window->show_all_children();
                    window->cola1--;
                    break;
            }
            switch(error){
                        case 0:
                            window->histograma << "Etapa 1:No hay error" << std::endl;
                            break;
                        case 1:
                            window->histograma << "Etapa 1:Correccion" << std::endl;
                            break;
                        case 2:
                            window->histograma << "Etapa 1:Desecho" << std::endl;
                            break;
                    }
                    auto t2 = Clock::now();
            window->histograma << "Tiempo: " << (int)(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1e+9) << std::endl;
            window->etapa2Run(unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho);
        }

        void start(int unidad,int porcentaje1,int porcentaje2,int porcentaje3,int porcentaje4,int porcentaje5,int correccion,int desecho){
            histograma.open("histograma.txt",std::ios::app);
            while(true){
                if(cola1 <= 2){
                    std::thread start(etapa1Run,this,unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho);
                    start.detach();
                    std::cout << cola1 << "," << cola2 << "," << cola3 << std::endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            histograma.close();
        }


        // Elementos de la ventana

        std::ofstream histograma;

        Gtk::Grid grid;

        // Colas
        int cola1 = 0;
        int cola2 = 0;
        int cola3 = 0;
        int cola4 = 0;
        int cola5 = 0;

        //Labels
        Gtk::Label label1;
        Gtk::Label correccionLabel;
        Gtk::Label desechoLabel;
        Gtk::Label etapa1;
        Gtk::Label etapa2;
        Gtk::Label etapa3;
        Gtk::Label etapa4;
        Gtk::Label etapa5;
        Gtk::Label porcentajes;

        //Entries
        Gtk::Entry entry1;
        Gtk::Entry correccionEntry;
        Gtk::Entry desechoEntry;
        Gtk::Entry error1;
        Gtk::Entry error2;
        Gtk::Entry error3;
        Gtk::Entry error4;
        Gtk::Entry error5;
        
        //Buttons
        Gtk::Button startProgram;

        Gtk::Button etapa1_1;
        Gtk::Button etapa1_2;
        Gtk::Button etapa1_3;

        Gtk::Button etapa2_1;
        Gtk::Button etapa2_2;
        Gtk::Button etapa2_3;

        Gtk::Button etapa3_1;
        Gtk::Button etapa3_2;
        Gtk::Button etapa3_3;

        Gtk::Button etapa4_1;
        Gtk::Button etapa4_2;
        Gtk::Button etapa4_3;

        Gtk::Button etapa5_1;
        Gtk::Button etapa5_2;
        Gtk::Button etapa5_3;
        
};

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc,argv,"org.gtkmm.example");

  App main;

  return app->run(main);
}
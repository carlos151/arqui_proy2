 #include <gtkmm.h>
 #include <iostream>
 #include <thread>

 extern "C" int calcularProbabilidad(int unidadDeTiempo,int probabilidad,int correccion,int desecho);

class App : public Gtk::Window
{
    public:
        App() : startProgram("Comenzar")
        {
            label1.set_text("Unidad de tiempo (segundos)");
            correccionLabel.set_text("Tiempo de corrección (segundos)");
            desechoLabel.set_text("Tiempo de desecho (segundos)");
            etapa1.set_text("Etapa 1");
            etapa2.set_text("Etapa 2");
            etapa3.set_text("Etapa 3");
            etapa4.set_text("Etapa 4");
            etapa5.set_text("Etapa 5");
            porcentajes.set_text("Porcentajes de error por etapa");

            set_default_size(1000, 800);
            set_title("Pipeline");
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
                sigc::mem_fun(*this,&App::startProgramOnClick)
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

    private:

        void startProgramOnClick(){
            int unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho;
            //startProgram.override_background_color(Gdk::RGBA("red"));
            show_all_children();
            try{
                unidad = std::stoi(entry1.get_text());
                porcentaje1 = std::stoi(error1.get_text());
                porcentaje2 = std::stoi(error2.get_text());
                porcentaje3 = std::stoi(error3.get_text());
                porcentaje4 = std::stoi(error4.get_text());
                porcentaje5 = std::stoi(error5.get_text());
                correccion = std::stoi(correccionEntry.get_text());
                desecho = std::stoi(desechoEntry.get_text());
            }catch(std::exception e){
                return;
            }
            startLine(unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho);
            std::cout << unidad << ","  << correccion << "," << desecho << "," << porcentaje1 << "," << porcentaje2 << "," << porcentaje3 << "," << porcentaje4 << "," << porcentaje5 << std::endl;
        }

        void startLine(int unidad,int porcentaje1,int porcentaje2,int porcentaje3,int porcentaje4,int porcentaje5,int correccion,int desecho){
            while(true){
                for(int i=0;i<5;i++){
                    int errorState = 0;
                    switch(i){
                        case 0:
                            etapa1_1.override_background_color(Gdk::RGBA("red"));
                            etapa2_1.override_background_color(Gdk::RGBA("white"));
                            etapa3_1.override_background_color(Gdk::RGBA("white"));
                            etapa4_1.override_background_color(Gdk::RGBA("white"));
                            etapa5_1.override_background_color(Gdk::RGBA("white"));
                            errorState = calcularProbabilidad(unidad,porcentaje1,correccion,desecho);
                            break;
                        case 1:
                            etapa1_1.override_background_color(Gdk::RGBA("white"));
                            etapa2_1.override_background_color(Gdk::RGBA("red"));
                            etapa3_1.override_background_color(Gdk::RGBA("white"));
                            etapa4_1.override_background_color(Gdk::RGBA("white"));
                            etapa5_1.override_background_color(Gdk::RGBA("white"));
                            errorState = calcularProbabilidad(unidad,porcentaje2,correccion,desecho);
                            break;
                        case 2:
                            etapa1_1.override_background_color(Gdk::RGBA("white"));
                            etapa2_1.override_background_color(Gdk::RGBA("white"));
                            etapa3_1.override_background_color(Gdk::RGBA("red"));
                            etapa4_1.override_background_color(Gdk::RGBA("white"));
                            etapa5_1.override_background_color(Gdk::RGBA("white"));
                            errorState = calcularProbabilidad(unidad,porcentaje3,correccion,desecho);
                            break;
                        case 3:
                            etapa1_1.override_background_color(Gdk::RGBA("white"));
                            etapa2_1.override_background_color(Gdk::RGBA("white"));
                            etapa3_1.override_background_color(Gdk::RGBA("white"));
                            etapa4_1.override_background_color(Gdk::RGBA("red"));
                            etapa5_1.override_background_color(Gdk::RGBA("white"));
                            errorState = calcularProbabilidad(unidad,porcentaje4,correccion,desecho);
                            break;
                        case 4:
                            etapa1_1.override_background_color(Gdk::RGBA("white"));
                            etapa2_1.override_background_color(Gdk::RGBA("white"));
                            etapa3_1.override_background_color(Gdk::RGBA("white"));
                            etapa4_1.override_background_color(Gdk::RGBA("white"));
                            etapa5_1.override_background_color(Gdk::RGBA("red"));
                            errorState = calcularProbabilidad(unidad,porcentaje5,correccion,desecho);
                            break;
                    }
                    show_all_children();
                }
            }
        }


        // Elementos de la ventana

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
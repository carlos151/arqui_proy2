 #include <gtkmm.h>
 #include <iostream>

class App : public Gtk::Window
{
    public:
        App() : startProgram("Comenzar")
        {
            label1.set_text("Unidad de tiempo (segundos)");
            correccionLabel.set_text("Tiempo de corrección (segundos)");
            desechoLabel.set_text("Tiempo de desecho (segundos)");
            etapa1.set_text("Etapa 1");
            etapa2.set_text("Etapa 1");
            etapa3.set_text("Etapa 1");
            etapa4.set_text("Etapa 1");
            etapa5.set_text("Etapa 1");
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

            add(grid);

            show_all_children();

        }

    private:
        void startProgramOnClick(){
            int unidad,porcentaje1,porcentaje2,porcentaje3,porcentaje4,porcentaje5,correccion,desecho;
            unidad = std::stoi(entry1.get_text());
            porcentaje1 = std::stoi(error1.get_text());
            porcentaje2 = std::stoi(error2.get_text());
            porcentaje3 = std::stoi(error3.get_text());
            porcentaje4 = std::stoi(error4.get_text());
            porcentaje5 = std::stoi(error5.get_text());
            correccion = std::stoi(correccionEntry.get_text());
            desecho = std::stoi(desechoEntry.get_text());

            std::cout << unidad << ","  << correccion << "," << desecho << "," << porcentaje1 << "," << porcentaje2 << "," << porcentaje3 << "," << porcentaje4 << "," << porcentaje5 << std::endl;
        }

        Gtk::Grid grid;

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
};

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc,argv,"org.gtkmm.example");

  App main;

  return app->run(main);
}
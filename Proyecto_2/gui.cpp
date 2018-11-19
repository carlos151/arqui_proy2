 #include <gtkmm.h>
 #include <iostream>

void onClick(){
    std::cout << "CLICK!" << std::endl;
}

int main(int argc, char *argv[])
{
 
  Gtk::Main kit(argc, argv);
  Gtk::Window window;
  window.set_default_size(1000, 600);
  window.set_title("Pipeline");
  window.set_position(Gtk::WIN_POS_CENTER);

  Gtk::Button button("Click");
  button.signal_clicked().connect(
      sigc::ptr_fun(&onClick)
  );
  button.show();
  window.add(button);

  Gtk::Main::run(window);

  return 0;
}
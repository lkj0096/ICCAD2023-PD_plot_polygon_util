#include <vector>
#include <iostream>
#include <thread>
#include <iomanip>


void gnup_th(std::vector<std::pair<int,int>> vecccc){
    int width = 40;
    int height = 40;
    std::cout << "Opening gnuplot... \n";
    FILE* pipe = popen(true ? "gnuplot -persist" : "gnuplot", "w");
    if (!pipe){
        std::cout << "failed!" << std::endl;
    } else{
        std::cout << "succeded." << std::endl;
    }
//    fputs("set title \"A!!\"\n", pipe);
    fputs(("set xrange [0:" + std::to_string(width) + "]\n").c_str(), pipe);
    fputs(("set yrange [0:" + std::to_string(height) + "]\n").c_str(), pipe);

    std::string str = "";
    std::stringstream stream;
    for(int m = 0; m < 1; m++){
        str = "set object " + std::to_string(m + 1) + " polygon from ";
        for(int i = 0; i < vecccc.size(); i++){
            str += std::to_string(vecccc[i].first);
            str += ",";
            str += std::to_string(vecccc[i].second);
            str += " to ";
        }
        str += std::to_string(vecccc[0].first);
        str += ",";
        str += std::to_string(vecccc[0].second);
        str += " \n";
        fputs(str.c_str(), pipe);

        uint32_t rgb = rand() % 0x1000000;
        stream.str("");
        stream << "0x"
               << std::setfill ('0') << std::setw(6)
               << std::hex << rgb;

        str = "set object 1 fc rgb " + stream.str() + " fillstyle transparent solid 0.3\n";
        fputs(str.c_str(), pipe);
    }

    fputs("plot 0\n", pipe);
    if(pipe != nullptr) { pclose(pipe); }

}

void join(std::vector<std::pair<int,int>> vecccc){
    std::thread th(gnup_th, vecccc);
    th.detach();
    return;
}

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(340, 180);
    Fl_Box *box = new Fl_Box(20, 40, 300, 100, "Hello, World!");
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD + FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);
    window->end();
    window->show(argc, argv);
    return Fl::run();
}